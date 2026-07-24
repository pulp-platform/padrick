# Copyright 2026 ETH Zurich.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
# Author: Kai Berszin, ETH Zurich

"""Characterization tests pinning currently-untested user-facing features."""
import textwrap
from pathlib import Path

from conftest import REPO_ROOT, run_padrick

CONFIGS_DIR = Path(__file__).parent / "configs"
SAMPLE_PADFRAME = REPO_ROOT / "examples" / "sample_padframe.yaml"
USER_ATTR_CONFIG = CONFIGS_DIR / "user_attr_padframe.yml"


def test_fusesoc_gen_produces_core_and_rtl(tmp_path: Path):
    """`fusesoc-gen` writes a .core file plus RTL sources into the cwd."""
    vlnv = "myvendor:mylib:mypadframe:0.1.0"
    gen_input = tmp_path / "gen_input.yml"
    gen_input.write_text(textwrap.dedent(f"""\
        files_root: {REPO_ROOT / "examples"}
        gapi: '1.0'
        vlnv: {vlnv}
        parameters:
          padframe_manifest: sample_padframe.yaml
          generate_steps:
            - kind: rtl
        """))

    # generate_core writes into the current working directory, so run in tmp_path.
    result = run_padrick(["fusesoc-gen", str(gen_input)], cwd=tmp_path)
    assert result.returncode == 0, result.stderr

    core_file = tmp_path / "low_power_padframe.core"
    assert core_file.exists()
    assert vlnv in core_file.read_text()
    # A representative RTL source and the Bender manifest are emitted alongside.
    assert (tmp_path / "src" / "low_power_padframe.sv").exists()
    assert (tmp_path / "Bender.yml").exists()


def test_user_attr_expansion_in_config_output(tmp_path: Path):
    """user_attr keys/values (templated, int, nested) are expanded per instance."""
    result = run_padrick(["config", str(USER_ATTR_CONFIG)])
    assert result.returncode == 0, result.stderr
    out = result.stdout
    # Templated key and value expanded with the instance index {i}.
    assert '"loc_index_0": "gpio number 0"' in out
    assert '"loc_index_1": "gpio number 1"' in out
    # Non-templated string and integer attributes are preserved verbatim.
    assert '"bank": "north"' in out
    assert '"count": 4' in out
    # Nested user_attr blocks are expanded recursively.
    assert '"inner_0": "value 0"' in out
    assert '"inner_1": "value 1"' in out


def test_generator_settings_override_customizes_template(tmp_path: Path):
    """A customized exported template is used when passed via `generate -s`."""
    export_dir = tmp_path / "customization"
    result = run_padrick(["generate", "template-customization", "-o", str(export_dir)])
    assert result.returncode == 0, result.stderr

    settings_file = export_dir / "padrick_generator_settings.yml"
    assert settings_file.exists()
    # The exported settings reference the template copies by absolute path, so
    # editing the copy in place is enough to influence generation.
    bender_template = export_dir / "rtl_templates" / "Bender.yml.mako"
    marker = "PADRICK_CUSTOM_TEMPLATE_MARKER"
    bender_template.write_text(bender_template.read_text() + "\n# " + marker + "\n")

    out_dir = tmp_path / "rtl"
    result = run_padrick([
        "generate", "-s", str(settings_file),
        "rtl", "--no-version-string", "-o", str(out_dir), str(SAMPLE_PADFRAME),
    ])
    assert result.returncode == 0, result.stderr
    assert marker in (out_dir / "Bender.yml").read_text()


def test_generate_custom_renders_template(tmp_path: Path):
    """`generate custom` renders a user Mako template against the padframe."""
    template = tmp_path / "template.mako"
    template.write_text(textwrap.dedent("""\
        padframe=${padframe.name}
        % for pad_domain in padframe.pad_domains:
        domain=${pad_domain.name}
        % endfor
        """))
    out_file = tmp_path / "out.txt"

    result = run_padrick([
        "generate", "custom", str(SAMPLE_PADFRAME), str(template), str(out_file),
    ])
    assert result.returncode == 0, result.stderr
    rendered = out_file.read_text()
    assert "padframe=low_power_padframe" in rendered
    assert "domain=always_on_pads" in rendered


def test_generate_rtl_header_option_inserts_header(tmp_path: Path):
    """`generate rtl --header` inserts the header file content into outputs."""
    header_file = tmp_path / "header.txt"
    header_text = "ACME Corp Copyright"
    header_file.write_text(header_text + "\n")

    out_dir = tmp_path / "rtl"
    result = run_padrick([
        "generate", "rtl", "--no-version-string",
        "--header", str(header_file), "-o", str(out_dir), str(SAMPLE_PADFRAME),
    ])
    assert result.returncode == 0, result.stderr
    assert header_text in (out_dir / "Bender.yml").read_text()


def test_include_glob_expands_to_list(tmp_path: Path) -> None:
    """A wildcard !include yields the list of all matched documents."""
    import ruamel.yaml
    from padrick.YamlInclude import YamlIncludeConstructor

    (tmp_path / "part_a.yml").write_text("- alpha\n")
    (tmp_path / "part_b.yml").write_text("- beta\n")
    yaml = ruamel.yaml.YAML(typ="rt")
    yaml.register_class(YamlIncludeConstructor(base_dir=str(tmp_path)))
    data = yaml.load("parts: !include part_*.yml\n")
    assert list(map(list, data["parts"])) == [["alpha"], ["beta"]]


def test_schema_command_emits_json_schema(tmp_path: Path) -> None:
    """`padrick schema` prints the JSON Schema of the config file format."""
    import json
    result = run_padrick(["schema"])
    assert result.returncode == 0, result.stderr
    schema = json.loads(result.stdout)
    assert schema["title"] == "Padframe Config"
    assert "pad_domains" in schema["properties"]


def test_validate_json_format(tmp_path: Path) -> None:
    """`validate --format json` reports a machine-readable verdict and exit code."""
    import json
    ok = run_padrick(["validate", "--format", "json", str(SAMPLE_PADFRAME)])
    assert ok.returncode == 0
    assert json.loads(ok.stdout) == {"valid": True, "errors": []}

    bad = run_padrick(["validate", "--format", "json", "tests/rtl_tests/testpadframe.yaml"])
    assert bad.returncode == 1
    verdict = json.loads(bad.stdout)
    assert verdict["valid"] is False
    assert verdict["errors"], "expected at least one structured error"
    assert {"type", "msg", "loc", "line", "column"} <= set(verdict["errors"][0])


def test_committed_schema_is_current() -> None:
    """padrick_schema.json at the repo root matches the generated schema."""
    result = run_padrick(["schema"])
    committed = (REPO_ROOT / "padrick_schema.json").read_text()
    assert result.stdout.strip() == committed.strip(), (
        "padrick_schema.json is stale; regenerate with: padrick schema -o padrick_schema.json"
    )
