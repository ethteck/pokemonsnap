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
        self._bit_cursor = 0  # bits written into last byte (0..7); 0 means new byte needed

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




def _build_tree_from_bit_widths(
    widths_in_order: Sequence[int],
) -> Vpk0Tree:
    """Construct a right-skewed tree: leaf L0 at the top, then L1, L2 ...

    Given widths [w0, w1, ..., wk-1] produces the tree

        entries = [
            Leaf(w0), Leaf(w1), ..., Leaf(w_{k-1}),
            Node(k-2, k-1),            # combines last two leaves
            Node(k-3, k),              # combines w_{k-3} with previous node
            ...
            Node(0, 2k-3),             # combines w_0 with everything below
        ]

    so that the code for w_i has length i+1 for i < k-1 and length k-1
    for i == k-1. w_0 is the shortest (1-bit code).

    This matches the shape we observed in the ROM for 3+ leaves. A single
    leaf is a degenerate zero-depth tree.
    """

    if len(widths_in_order) == 0:
        raise Vpk0CompressionError("Cannot build tree with no leaves")

    entries: List[TreeEntry] = [_Leaf(w) for w in widths_in_order]
    if len(widths_in_order) == 1:
        return Vpk0Tree(entries)

    # Combine from the bottom up. First combine leaves[-2] and leaves[-1].
    prev_index = len(entries)
    entries.append(_Node(len(widths_in_order) - 2, len(widths_in_order) - 1))
    for i in range(len(widths_in_order) - 3, -1, -1):
        new_index = len(entries)
        entries.append(_Node(i, prev_index))
        prev_index = new_index
    return Vpk0Tree(entries)


def _choose_bit_widths(values: Sequence[int]) -> List[int]:
    """Choose a set of bit-widths to cover ``values`` with reasonable cost.

    This is a first-cut heuristic: take the histogram of ceil(log2(v+1))
    and emit the set of widths that actually occur, sorted ascending.
    Not a matching algorithm.
    """

    if not values:
        return [1]  # any width that the decoder can parse

    required: set[int] = set()
    for v in values:
        if v < 0:
            raise Vpk0CompressionError(f"Negative value {v}")
        if v == 0:
            required.add(1)
        else:
            required.add(max(1, v.bit_length()))
    widths = sorted(required)
    return widths


# ---------------------------------------------------------------------------
# Tree derivation (the remaining research problem)
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


def _splay_items(items: Sequence[Tuple[int, int]]) -> List[TreeEntry]:
    """Build tree entries for ``items = [(width, freq), ...]`` assumed
    sorted by width ascending.

    Rule (reverse-engineered from all four non-trivial ROM trees):

    * ``len == 1``: single leaf.
    * ``len == 2``: balanced pair; leaves emitted in width-ascending
      order so they become LEFT and RIGHT children.
    * Else if the most frequent bucket has ``> total_freq / 2``
      occurrences, that bucket alone becomes one child and the
      remainder recurses on the other side.
    * Else split the item list in half by **count** (not frequency):
      ``floor(n/2)`` items on the left, the rest on the right, and
      recurse.

    The side placement preserves the "smaller min_width goes LEFT"
    convention observed in the ROM, so the post-order linearisation
    has ascending-width leaves when possible.
    """

    if len(items) == 1:
        return [_Leaf(items[0][0])]

    if len(items) == 2:
        entries: List[TreeEntry] = [_Leaf(items[0][0]), _Leaf(items[1][0])]
        entries.append(_Node(0, 1))
        return entries

    total = sum(f for _, f in items)
    max_idx = 0
    for i, (_, f) in enumerate(items):
        if f > items[max_idx][1]:
            max_idx = i
    max_item = items[max_idx]

    if max_item[1] * 2 > total:
        # "Dominant" case. The most-frequent bucket becomes a standalone
        # leaf on one side; everything else (in original width order)
        # forms the opposite subtree.
        others = list(items[:max_idx]) + list(items[max_idx + 1:])
        lone_min_w = max_item[0]
        others_min_w = min(w for w, _ in others) if others else lone_min_w
        if lone_min_w <= others_min_w:
            left = [_Leaf(lone_min_w)]
            right = _splay_items(others)
        else:
            left = _splay_items(others)
            right = [_Leaf(lone_min_w)]
    else:
        # "Canonical" case. Split by item-count.
        mid = len(items) // 2
        left = _splay_items(items[:mid])
        right = _splay_items(items[mid:])

    combined: List[TreeEntry] = list(left)
    r_offset = len(combined)
    left_root_idx = r_offset - 1
    for e in right:
        if isinstance(e, _Node):
            combined.append(_Node(e.left + r_offset, e.right + r_offset))
        else:
            combined.append(_Leaf(e.bit_size))
    right_root_idx = len(combined) - 1
    combined.append(_Node(left_root_idx, right_root_idx))
    return combined


def _huffman_tree_from_items(items: Sequence[Tuple[int, int]]) -> Vpk0Tree:
    """Build a VPK0 tree from ``items = [(bit_width, frequency), ...]``."""
    return Vpk0Tree(_splay_items(items))


def _cost_from_items(tree: Vpk0Tree, items: Sequence[Tuple[int, int]]) -> int:
    """Total bits for ``tree`` header + stream, given per-bucket frequencies.

    This is the fast version of ``_cost_of_tree`` — instead of iterating
    every value, it takes precomputed (width, freq) pairs.
    """
    code_table = tree.code_table()
    width_to_code_len: dict[int, int] = {}
    for i, e in enumerate(tree.entries):
        if isinstance(e, _Leaf):
            _, length = code_table[i]
            if e.bit_size not in width_to_code_len or length < width_to_code_len[e.bit_size]:
                width_to_code_len[e.bit_size] = length

    stream_bits = 0
    for w, f in items:
        stream_bits += f * (width_to_code_len[w] + w)
    header_bits = 10 * len(items)
    return header_bits + stream_bits


def _tree_for_subset(
    subset: Sequence[int], cum: Sequence[int]
) -> Tuple[Vpk0Tree, int, List[Tuple[int, int]]]:
    """Build the VPK0 tree for a bucket-width subset and return
    (tree, cost, items)."""
    items: List[Tuple[int, int]] = []
    prev = 0
    for w in subset:
        items.append((w, cum[w] - cum[prev]))
        prev = w
    tree = _huffman_tree_from_items(items)
    return tree, _cost_from_items(tree, items), items


def derive_tree(values: Sequence[int]) -> Vpk0Tree:
    """Derive a VPK0 tree (bucket set + tree shape) from the raw values
    that will be encoded through it.

    Strategy (the remaining research problem, partially solved):

    * Bucket-set selection: greedy add. Start with just ``{max_w}``;
      repeatedly add the single bucket width that lowers the total
      bit-count the most; stop when no addition helps.
    * Tree shape for a fixed bucket set: see ``_splay_items``.

    This reproduces the ROM trees for the tiny and mid segments and
    the large-OFFSETS tree. The large-LENGTHS tree still disagrees on
    one bucket — the ROM stops at ``{3, 5, 6, 8}`` but greedy-add
    keeps going and picks ``{3, 4, 5, 6, 8}``. Investigating.
    """

    if not values:
        return Vpk0Tree([_Leaf(1)])

    from collections import Counter

    required = _required_widths(values)
    max_w = max(required)
    hist = Counter(required)

    cum = [0] * (max_w + 2)
    for w in range(1, max_w + 1):
        cum[w] = cum[w - 1] + hist.get(w, 0)

    current: set[int] = {max_w}
    current_tree, current_cost, _ = _tree_for_subset(sorted(current), cum)

    while True:
        best_w: Optional[int] = None
        best_cost = current_cost
        best_tree: Optional[Vpk0Tree] = None

        for w in range(1, max_w):
            if w in current:
                continue
            trial = sorted(current | {w})
            tree, cost, _ = _tree_for_subset(trial, cum)
            if cost < best_cost:
                best_cost = cost
                best_w = w
                best_tree = tree

        if best_w is None or best_tree is None:
            return current_tree

        current.add(best_w)
        current_tree = best_tree
        current_cost = best_cost


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
        off_widths = _choose_bit_widths(offset_values)
        len_widths = _choose_bit_widths(length_values)
        offsets_tree = _build_tree_from_bit_widths(off_widths)
        lengths_tree = _build_tree_from_bit_widths(len_widths)

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
                raise Vpk0CompressionError(
                    f"length tree has no bucket for value {L}"
                )

    payload = writer.to_bytes()
    header = b"vpk0" + len(raw).to_bytes(4, "big") + bytes([method])
    return header + payload
