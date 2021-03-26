from typing import Iterable, List

from natsort import natsorted

from padrick.Model.PadSignal import Signal


def sort_signals(seq: Iterable[Signal]):
    return natsorted(seq, key=lambda x: x.name)
