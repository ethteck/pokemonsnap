"""Pure-Python VPK0 codec (decompress + compress).

VPK0 is the compression format used by Vanpool/HAL-authored N64 titles
including Pokemon Snap. A stream consists of:

    offset 0   : magic "vpk0"
    offset 4   : decompressed size (u32 big-endian)
    offset 8   : method byte (0 = one-sample, 1 = two-sample)
    offset 9.. : bitstream containing
                    - offsets tree
                    - lengths tree
                    - LZSS token stream

Each tree encodes "bucket" leaves whose value is a raw bit-width. Reading
a value from a tree reads a Huffman code to pick a bucket, then reads
that many bits to obtain the value.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import List, Optional, Sequence, Tuple, Union


class Vpk0DecompressionError(Exception):
    """Raised when VPK0 data cannot be decompressed."""


class Vpk0CompressionError(Exception):
    """Raised when VPK0 data cannot be compressed."""


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

    @property
    def bitpos(self) -> int:
        return self._bitpos

    def bytes_consumed(self) -> int:
        return (self._bitpos + 7) // 8


class BitWriter:
    def __init__(self) -> None:
        self._buf = bytearray()
        self._bit_cursor = (
            0  # bits written into last byte (0..7); 0 means new byte needed
        )

    def write_bit(self, bit: int) -> None:
        if self._bit_cursor == 0:
            self._buf.append(0)
        if bit & 1:
            self._buf[-1] |= 1 << (7 - self._bit_cursor)
        self._bit_cursor = (self._bit_cursor + 1) % 8

    def write_bits(self, value: int, count: int) -> None:
        if count == 0:
            return
        for i in range(count - 1, -1, -1):
            self.write_bit((value >> i) & 1)

    @property
    def bitpos(self) -> int:
        if self._bit_cursor == 0:
            return len(self._buf) * 8
        return (len(self._buf) - 1) * 8 + self._bit_cursor

    def to_bytes(self) -> bytes:
        return bytes(self._buf)


# ---------------------------------------------------------------------------
# Tree representation
# ---------------------------------------------------------------------------


@dataclass
class _Node:
    left: int
    right: int


@dataclass
class _Leaf:
    bit_size: int


TreeEntry = Union[_Node, _Leaf]


class Vpk0Tree:
    """Post-order tree of bucket leaves.

    Serialization: bit 0 means "leaf, followed by 8-bit bit_size"; bit 1
    means "internal node, pops two previous entries from the stack and
    combines them". A final lone '1' with fewer than 2 items on the stack
    terminates the tree.
    """

    def __init__(self, entries: Sequence[TreeEntry]):
        self.entries: List[TreeEntry] = list(entries)

    # -- decode -------------------------------------------------------------
    @classmethod
    def read(cls, reader: BitReader) -> "Vpk0Tree":
        entries: List[TreeEntry] = []
        stack: List[int] = []
        while True:
            if reader.read_bit() == 1:
                if len(stack) < 2:
                    break
                right = stack.pop()
                left = stack.pop()
                entries.append(_Node(left, right))
            else:
                entries.append(_Leaf(reader.read_bits(8)))
            stack.append(len(entries) - 1)
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

    # -- encode -------------------------------------------------------------
    def write(self, writer: BitWriter) -> None:
        for entry in self.entries:
            if isinstance(entry, _Leaf):
                writer.write_bit(0)
                writer.write_bits(entry.bit_size, 8)
            else:
                writer.write_bit(1)
        writer.write_bit(1)  # terminator

    def code_table(self) -> dict[int, Tuple[int, int]]:
        """Map from leaf_index -> (code_bits, code_length).

        Note: leaves are keyed by entry index, not bit_size, because the
        same bit_size can legally appear in multiple leaves (though in
        practice the ROM streams we care about never do this).
        """
        table: dict[int, Tuple[int, int]] = {}
        if not self.entries:
            return table

        def walk(idx: int, code: int, length: int) -> None:
            entry = self.entries[idx]
            if isinstance(entry, _Leaf):
                table[idx] = (code, length)
            else:
                walk(entry.left, code << 1, length + 1)
                walk(entry.right, (code << 1) | 1, length + 1)

        walk(len(self.entries) - 1, 0, 0)
        return table

    def leaves_with_codes(self) -> List[Tuple[int, int, int]]:
        """Return list of (bit_size, code_bits, code_len) for each leaf,
        in the order their indices appear in ``entries``."""
        codes = self.code_table()
        result = []
        for idx, entry in enumerate(self.entries):
            if isinstance(entry, _Leaf):
                code, length = codes[idx]
                result.append((entry.bit_size, code, length))
        return result


# ---------------------------------------------------------------------------
# Decompression
# ---------------------------------------------------------------------------


@dataclass
class Vpk0Metadata:
    """Information recovered from a reference compressed stream.

    Exposing this lets callers (e.g. build tooling) ask the encoder to
    reuse the exact trees/method the original ROM used, which is the
    fundamental strategy for producing byte-identical output.
    """

    method: int
    offsets_tree: Vpk0Tree
    lengths_tree: Vpk0Tree
    decompressed_size: int

    @classmethod
    def from_compressed(cls, data: bytes) -> "Vpk0Metadata":
        if len(data) < 9 or data[:4] != b"vpk0":
            raise Vpk0DecompressionError("Invalid VPK0 header")
        decompressed_size = int.from_bytes(data[4:8], "big")
        method = data[8]
        reader = BitReader(data[9:])
        offsets = Vpk0Tree.read(reader)
        lengths = Vpk0Tree.read(reader)
        return cls(
            method=method,
            offsets_tree=offsets,
            lengths_tree=lengths,
            decompressed_size=decompressed_size,
        )


def _decompress_internal(
    data: bytes,
) -> Tuple[bytes, int, List["LzToken"]]:
    if len(data) < 9:
        raise Vpk0DecompressionError("VPK0 stream is too short for header")
    if data[:4] != b"vpk0":
        raise Vpk0DecompressionError("Invalid VPK0 magic")

    decompressed_size = int.from_bytes(data[4:8], "big")
    method = data[8]
    if method not in (0, 1):
        raise Vpk0DecompressionError(f"VPK0 method {method} is not supported")

    reader = BitReader(data[9:])
    offsets = Vpk0Tree.read(reader)
    lengths = Vpk0Tree.read(reader)

    output = bytearray()
    tokens: List[LzToken] = []
    while len(output) < decompressed_size:
        if reader.read_bit():
            initial = offsets.read_value(reader)
            if method == 1:
                if initial < 3:
                    u = offsets.read_value(reader)
                    move_back = (initial + 1 + (u << 2)) - 8
                else:
                    move_back = (initial << 2) - 8
            else:
                move_back = initial

            if move_back <= 0 or move_back > len(output):
                raise Vpk0DecompressionError(
                    f"Bad input: move_back={move_back} out of range"
                )

            copy_len = lengths.read_value(reader)
            start = len(output) - move_back
            for i in range(copy_len):
                output.append(output[start + i])
            tokens.append(LzToken(False, move_back=move_back, length=copy_len))
        else:
            b = reader.read_bits(8)
            output.append(b)
            tokens.append(LzToken(True, literal=b))

    consumed = 9 + reader.bytes_consumed()
    return bytes(output), consumed, tokens


def decompress_vpk0(data: bytes) -> Tuple[bytes, int]:
    """Return (decompressed_bytes, bytes_consumed_from_input)."""
    out, consumed, _ = _decompress_internal(data)
    return out, consumed


def decompress_vpk0_with_tokens(data: bytes) -> Tuple[bytes, List["LzToken"]]:
    """Decompress and also return the original tool's LZSS token sequence.

    Useful for studying the encoder's match-selection heuristic: every
    token corresponds to exactly one output byte (literal) or a run of
    output bytes (backref), so ``tokens`` is the exact sequence of
    decisions the original compressor made.
    """
    out, _, tokens = _decompress_internal(data)
    return out, tokens


# ---------------------------------------------------------------------------
# Compression
# ---------------------------------------------------------------------------


@dataclass
class LzToken:
    """A single LZSS decision — either a literal byte or a back-reference."""

    is_literal: bool
    literal: int = 0
    move_back: int = 0
    length: int = 0


def _encode_offset_fields(move_back: int) -> List[int]:
    """Return the sequence of tree-values that encodes this move_back
    for method 1.

    Method-1 offsets are one of:
      * direct: tree_value = (move_back + 8) >> 2, requires
                (move_back + 8) % 4 == 0 and tree_value >= 3.
      * escaped: two tree-values. Decoder rule:
                   move_back = (tv0 + 1) + (tv1 << 2) - 8
                 with tv0 ∈ {0, 1, 2}.
    """

    # Prefer the direct encoding when valid: fewer tree reads.
    if (move_back + 8) % 4 == 0:
        tv0 = (move_back + 8) >> 2
        if tv0 >= 3:
            return [tv0]

    # Escape encoding: pick tv0 in {0,1,2} such that (move_back + 8) - (tv0 + 1)
    # is divisible by 4 and non-negative.
    for tv0 in (0, 1, 2):
        remainder = move_back + 8 - (tv0 + 1)
        if remainder < 0:
            continue
        if remainder % 4 != 0:
            continue
        tv1 = remainder >> 2
        return [tv0, tv1]

    raise Vpk0CompressionError(f"Cannot encode move_back={move_back} in method 1")


MIN_MATCH = 3
DEFAULT_MAX_MATCH = 255
DEFAULT_MAX_WINDOW = 1 << 16


def _lzss_lazy(
    data: bytes,
    *,
    max_window: int = DEFAULT_MAX_WINDOW,
    max_match: int = DEFAULT_MAX_MATCH,
) -> List[LzToken]:
    """Lazy-match LZSS via a rolling 3-byte hash chain.

    The lazy rule: if the best match at ``pos+1`` is strictly longer than
    the best match at ``pos``, emit a literal at ``pos`` and advance by
    1. This is the classic gzip heuristic and matches the pattern we
    observe in the Pokemon Snap VPK0 blobs.
    """

    N = len(data)
    if N == 0:
        return []

    HASH_SIZE = 1 << 16
    HASH_MASK = HASH_SIZE - 1
    head: list[int] = [-1] * HASH_SIZE
    prev: list[int] = [-1] * N

    def h3(pos: int) -> int:
        b0 = data[pos]
        b1 = data[pos + 1]
        b2 = data[pos + 2]
        return ((b0 * 2654435761) ^ (b1 << 8) ^ b2) & HASH_MASK

    def best_match_at(pos: int) -> Tuple[int, int]:
        """Return (move_back, length). length < MIN_MATCH means "no match"."""
        if pos + MIN_MATCH > N:
            return 0, 0
        best_len = 0
        best_off = 0
        key = h3(pos)
        window_start = max(0, pos - max_window)
        j = head[key]
        limit = min(max_match, N - pos)
        while j != -1 and j >= window_start:
            if data[j + best_len] == data[pos + best_len]:
                k = 0
                while k < limit and data[j + k] == data[pos + k]:
                    k += 1
                if k > best_len:
                    best_len = k
                    best_off = pos - j
                    if k == limit:
                        break
            j = prev[j]
        return best_off, best_len

    def insert(pos: int) -> None:
        if pos + MIN_MATCH > N:
            return
        key = h3(pos)
        prev[pos] = head[key]
        head[key] = pos

    tokens: List[LzToken] = []
    i = 0
    while i < N:
        off_i, len_i = best_match_at(i)
        insert(i)

        if len_i >= MIN_MATCH:
            # Lazy check: peek one position ahead.
            if i + 1 < N:
                _off_next, len_next = best_match_at(i + 1)
                if len_next > len_i:
                    # Prefer a literal here so the longer match at i+1
                    # can be taken on the next iteration.
                    tokens.append(LzToken(True, literal=data[i]))
                    i += 1
                    continue

            tokens.append(LzToken(False, move_back=off_i, length=len_i))
            # Insert every byte inside the match so the chain stays dense.
            for p in range(i + 1, i + len_i):
                insert(p)
            i += len_i
        else:
            tokens.append(LzToken(True, literal=data[i]))
            i += 1
    return tokens


# ---------------------------------------------------------------------------
# Tree derivation
# ---------------------------------------------------------------------------


def tokens_to_tree_values(tokens: Sequence[LzToken]) -> Tuple[List[int], List[int]]:
    """Split a token stream into the raw integer value sequences that the
    offsets tree and lengths tree need to encode, respectively.

    For method 1 the offset stream interleaves direct values and escape
    pairs; both go through the same tree, so we just concatenate them.
    """
    offset_values: List[int] = []
    length_values: List[int] = []
    for tok in tokens:
        if tok.is_literal:
            continue
        for v in _encode_offset_fields(tok.move_back):
            offset_values.append(v)
        length_values.append(tok.length)
    return offset_values, length_values


def _required_widths(values: Sequence[int]) -> List[int]:
    return [max(1, v.bit_length()) if v > 0 else 1 for v in values]


def derive_tree(values: Sequence[int]) -> Vpk0Tree:
    """Derive a VPK0 tree (bucket set + tree shape) from the raw values
    that will be encoded through it.

    The algorithm is a **top-down greedy splitter** over contiguous
    width ranges. Each node covers an interval ``[lo..hi]``; if not
    split, it becomes a leaf with ``bit_size = hi``. A split at
    position ``k`` is accepted when the local gain is positive::

        gain(lo, hi, k) = (hi - k) * freq(lo..k) - freq(lo..hi) - 10

    The first term is the raw-bit savings (values in ``[lo..k]`` now
    use ``k`` bits instead of ``hi``). The second is the extra code bit
    every value in ``[lo..hi]`` pays. The ``-10`` is the tree-overhead
    cost of one additional leaf.

    This simultaneously determines the bucket set AND the tree shape.
    The recursion produces entries in post-order (left subtree, right
    subtree, combining node), which is exactly VPK0's serialisation
    order. Verified to reproduce all six ROM trees byte-for-byte.
    """

    if not values:
        return Vpk0Tree([_Leaf(1)])

    from collections import Counter

    required = _required_widths(values)
    max_w = max(required)
    min_w = min(required)
    hist = Counter(required)

    cum = [0] * (max_w + 2)
    for w in range(1, max_w + 1):
        cum[w] = cum[w - 1] + hist.get(w, 0)

    def freq(lo: int, hi: int) -> int:
        return cum[hi] - cum[lo - 1]

    def build(lo: int, hi: int) -> List[TreeEntry]:
        if lo == hi:
            return [_Leaf(hi)]

        total = freq(lo, hi)
        best_gain = 0
        best_k: Optional[int] = None

        for k in range(lo, hi):
            gain = (hi - k) * freq(lo, k) - total - 10
            if gain > best_gain:
                best_gain = gain
                best_k = k

        if best_k is None:
            return [_Leaf(hi)]

        left = build(lo, best_k)
        right = build(best_k + 1, hi)

        combined: List[TreeEntry] = list(left)
        r_offset = len(combined)
        left_root = r_offset - 1
        for e in right:
            if isinstance(e, _Node):
                combined.append(_Node(e.left + r_offset, e.right + r_offset))
            else:
                combined.append(_Leaf(e.bit_size))
        right_root = len(combined) - 1
        combined.append(_Node(left_root, right_root))
        return combined

    return Vpk0Tree(build(min_w, max_w))


def derive_trees_from_tokens(
    tokens: Sequence[LzToken],
) -> Tuple[Vpk0Tree, Vpk0Tree]:
    """Given an LZSS token stream, derive (offsets_tree, lengths_tree).

    Used by tests to separate tree-derivation quality from LZSS-matching
    quality: feed the original ROM's own token sequence in, and any
    mismatch against the ROM's trees is purely a tree-derivation bug.
    """
    offset_values, length_values = tokens_to_tree_values(tokens)
    return derive_tree(offset_values), derive_tree(length_values)


def compress_vpk0(
    raw: bytes,
    method: int = 1,
    *,
    metadata: Optional[Vpk0Metadata] = None,
) -> bytes:
    """Compress raw data into a VPK0 stream.

    If ``metadata`` is provided, the encoder will reuse the given
    trees/method verbatim. This is the reliable path to byte-identical
    output on the three ROM segments while a matching heuristic is still
    being developed.
    """

    if method != 1:
        raise Vpk0CompressionError(
            f"method {method} is not supported by this encoder "
            "(Pokemon Snap only uses method 1)"
        )

    # When metadata is provided, derive limits from the biggest bucket the
    # target trees can reach — otherwise the LZSS pass can emit a match
    # that the tree cannot encode (e.g. a 16-bit offset field into a tree
    # whose largest leaf is bit_size=14).
    if metadata is not None:
        off_max_bits = max(
            (e.bit_size for e in metadata.offsets_tree.entries if isinstance(e, _Leaf)),
            default=1,
        )
        len_max_bits = max(
            (e.bit_size for e in metadata.lengths_tree.entries if isinstance(e, _Leaf)),
            default=1,
        )
        # For direct-encoded offsets, move_back = (tv << 2) - 8. So the
        # maximum tv value that fits is (1 << off_max_bits) - 1, giving
        # move_back <= (((1 << off_max_bits) - 1) << 2) - 8. The escape
        # encoding reaches a similar upper bound.
        max_tv = (1 << off_max_bits) - 1
        lzss_max_window = max(1, (max_tv << 2) - 8)
        lzss_max_match = min(DEFAULT_MAX_MATCH, (1 << len_max_bits) - 1)
    else:
        lzss_max_window = DEFAULT_MAX_WINDOW
        lzss_max_match = DEFAULT_MAX_MATCH

    tokens = _lzss_lazy(raw, max_window=lzss_max_window, max_match=lzss_max_match)

    # Collect values we'll need to encode.
    offset_values: List[int] = []
    length_values: List[int] = []
    for tok in tokens:
        if tok.is_literal:
            continue
        for v in _encode_offset_fields(tok.move_back):
            offset_values.append(v)
        length_values.append(tok.length)

    if metadata is not None:
        if metadata.method != method:
            raise Vpk0CompressionError(
                f"Metadata method {metadata.method} does not match requested method {method}"
            )
        offsets_tree = metadata.offsets_tree
        lengths_tree = metadata.lengths_tree
    else:
        offsets_tree = derive_tree(offset_values)
        lengths_tree = derive_tree(length_values)

    # Build lookup: bit_width -> (leaf_index, code_bits, code_len)
    def tree_lookup(tree: Vpk0Tree) -> dict[int, Tuple[int, int]]:
        codes = tree.code_table()
        out: dict[int, Tuple[int, int]] = {}
        for idx, entry in enumerate(tree.entries):
            if isinstance(entry, _Leaf):
                # If the same bit_size appears multiple times, prefer the
                # earliest occurrence (shortest code).
                code, length = codes[idx]
                existing = out.get(entry.bit_size)
                if existing is None or length < existing[1]:
                    out[entry.bit_size] = (code, length)
        return out

    off_codes = tree_lookup(offsets_tree)
    len_codes = tree_lookup(lengths_tree)
    off_widths_sorted = sorted(off_codes.keys())
    len_widths_sorted = sorted(len_codes.keys())

    writer = BitWriter()
    # Header is handled outside the bit stream.
    offsets_tree.write(writer)
    lengths_tree.write(writer)

    for tok in tokens:
        if tok.is_literal:
            writer.write_bit(0)
            writer.write_bits(tok.literal, 8)
        else:
            writer.write_bit(1)
            tvs = _encode_offset_fields(tok.move_back)
            for tv in tvs:
                # Pick the smallest bit-width bucket that can hold this tv.
                for w in off_widths_sorted:
                    if tv < (1 << w):
                        code, clen = off_codes[w]
                        writer.write_bits(code, clen)
                        writer.write_bits(tv, w)
                        break
                else:
                    raise Vpk0CompressionError(
                        f"offset tree has no bucket for value {tv}"
                    )
            L = tok.length
            for w in len_widths_sorted:
                if L < (1 << w):
                    code, clen = len_codes[w]
                    writer.write_bits(code, clen)
                    writer.write_bits(L, w)
                    break
            else:
                raise Vpk0CompressionError(f"length tree has no bucket for value {L}")

    payload = writer.to_bytes()
    header = b"vpk0" + len(raw).to_bytes(4, "big") + bytes([method])
    return header + payload
