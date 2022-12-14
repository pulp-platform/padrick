import os
from contextlib import contextmanager

@contextmanager
def working_dir(path):
    "A context manager to temporarily chang the working directory"
    prev_cwd = os.getcwd()
    os.chdir(path)
    try:
        yield
    finally:
        os.chdir(prev_cwd)