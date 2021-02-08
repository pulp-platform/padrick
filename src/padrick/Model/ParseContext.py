from typing import Set, Mapping, Union, List


class ParseContext:
    _current_pad_domain: 'PadDomain'
    _pad_types: Mapping[str, 'PadType'] = {}

    def set_context(self, ctx: 'PadDomain'):
        self._current_pad_domain = ctx

    def register_pad_type(self, pad_type: 'PadType'):
        self._pad_types[pad_type.name] = pad_type

    def find_pad_type(self, name: str) -> Union['PadType', None]:
        return self._pad_types.get(name, None)

    def find_pad_signal_instances(self, name: str) -> List[Union['Signal']]:
        pad_signal_references = []
        for pad_type in self._pad_types.values():
            for pad_signal in pad_type.pad_signals:
                if pad_signal.name == name:
                    pad_signal_references.append(pad_signal)
        return pad_signal_references

PARSE_CONTEXT = ParseContext()