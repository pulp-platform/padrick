from typing import Iterable, List

from natsort import natsorted

def sort_signals(seq: Iterable['Signal']):
    return natsorted(seq, key=lambda x: x.name)

def sort_ports(seq: Iterable['Port']):
    return natsorted(seq, key=lambda x: x.name)

def sort_pads(seq: Iterable['PadInstance']):
    return natsorted(seq, key=lambda x: x.name)