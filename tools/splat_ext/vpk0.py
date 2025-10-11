from __future__ import annotations

from typing import List, Union

from splat.segtypes.n64.decompressor import CommonSegDecompressor
from splat.util import log


class Vpk0DecompressionError(Exception):
    """Raised when VPK0 data cannot be decompressed."""


class BitReader:
    def __init__(self, data: bytes):
        self._data = data
        self._bitpos = 0
        self._bitlen = len(data) * 8

    def read_bit(self) -> int:
        if self._bitpos >= self._bitlen:
            raise Vpk0DecompressionError("Unexpected end of VPK0 bitstream")

        byte_index = self._bitpos // 8
        bit_index = 7 - (self._bitpos % 8)
        self._bitpos += 1
        return (self._data[byte_index] >> bit_index) & 1

    def read_bits(self, count: int) -> int:
        if count == 0:
            return 0

        value = 0
        for _ in range(count):
            value = (value << 1) | self.read_bit()
        return value

    def bytes_consumed(self) -> int:
        return (self._bitpos + 7) // 8


class _Node:
    __slots__ = ("left", "right")

    def __init__(self, left: int, right: int):
        self.left = left
        self.right = right


class _Leaf:
    __slots__ = ("bit_size",)

    def __init__(self, bit_size: int):
        self.bit_size = bit_size


TreeEntry = Union[_Node, _Leaf]


class Vpk0Tree:
    def __init__(self, entries: List[TreeEntry]):
        self.entries = entries

    @classmethod
    def from_reader(cls, reader: BitReader) -> "Vpk0Tree":
        entries: List[TreeEntry] = []
        stack: List[int] = []

        while True:
            idx = len(entries)
            bit = reader.read_bit()
            if bit == 1:
                if len(stack) < 2:
                    break
                right = stack.pop()
                left = stack.pop()
                entries.append(_Node(left, right))
            else:
                entries.append(_Leaf(reader.read_bits(8)))

            stack.append(idx)

        return cls(entries)

    def read_value(self, reader: BitReader) -> int:
        if not self.entries:
            return 0

        idx = len(self.entries) - 1
        while isinstance(self.entries[idx], _Node):
            node = self.entries[idx]
            idx = node.right if reader.read_bit() else node.left

        leaf = self.entries[idx]
        assert isinstance(leaf, _Leaf)
        return reader.read_bits(leaf.bit_size)


def _decompress_vpk0(data: bytes) -> tuple[bytes, int]:
    if len(data) < 9:
        raise Vpk0DecompressionError("VPK0 stream is too short for header")

    if data[:4] != b"vpk0":
        raise Vpk0DecompressionError("Invalid VPK0 magic")

    decompressed_size = int.from_bytes(data[4:8], "big")
    method = data[8]
    if method not in (0, 1):
        raise Vpk0DecompressionError(
            f"VPK0 method {method} is invalid and not supported"
        )

    reader = BitReader(data[9:])
    offsets = Vpk0Tree.from_reader(reader)
    lengths = Vpk0Tree.from_reader(reader)

    output = bytearray()
    while len(output) < decompressed_size:
        encoded = reader.read_bit()

        if encoded:
            initial_move = offsets.read_value(reader)
            if method == 1:
                if initial_move < 3:
                    l = initial_move + 1
                    u = offsets.read_value(reader)
                    move_back = (l + (u << 2)) - 8
                else:
                    move_back = (initial_move << 2) - 8
            else:
                move_back = initial_move

            if move_back == 0 or move_back > len(output):
                raise Vpk0DecompressionError(
                    f"Bad input: tried to move back {move_back} bytes with only {len(output)} bytes output"
                )

            start = len(output) - move_back
            copy_len = lengths.read_value(reader)

            for i in range(copy_len):
                try:
                    output.append(output[start + i])
                except IndexError as err:
                    raise Vpk0DecompressionError(
                        "Bad input: copy length extends past decoded output"
                    ) from err
        else:
            output.append(reader.read_bits(8))

    consumed = 9 + reader.bytes_consumed()

    return bytes(output), consumed


class N64SegVpk0(CommonSegDecompressor):
    compression_error_hint = "(hint: add a 'bin' segment after it)"

    @property
    def compression_type(self) -> str:
        return "Vpk0"

    def decompress(self, compressed_bytes: bytes) -> bytes:
        try:
            decompressed, consumed = _decompress_vpk0(compressed_bytes)
        except Vpk0DecompressionError as err:
            log.error(f"Error decompressing {self.name}: {err}")

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        expected_end = self.rom_start + consumed
        actual_end = self.rom_end

        if expected_end != actual_end:
            log.error(
                f"Error: {self.name} should end at 0x{expected_end:X}, but it ends at 0x{actual_end:X}\n{self.compression_error_hint}"
            )

        return decompressed
