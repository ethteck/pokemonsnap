"""
Exact reimplementation of the N64 SDK `rgb2c` RGBA16 conversion, plus its
inverse.

rgb2c (as run by the SDK's mksprite scripts with `-F -S 2`) converts each tile
row as follows:
  - readtex() widens the row to a multiple of 4 texels by repeating the last
    8-bit source pixel;
  - printdata() quantises to RGBA5551 with a per-row carry dither: the low 3
    bits of each channel's accumulator carry over into the next texel, and the
    accumulator resets to 4 whenever a channel value repeats;
  - odd rows are emitted in `x ^ shuffle` order (TMEM interleaving).

`decode_rgba16_row` finds 8-bit pixels, as close as possible to the plain 5->8
bit expansion, that `encode_rgba16_row` turns back into the given texels.
"""

Pixel = tuple[int, int, int, int]


def expand5(c: int) -> int:
    return (c << 3) | (c >> 2)


def encode_rgba16_row(pixels: list[Pixel], padded_w: int, shuffle: int) -> list[int]:
    """Convert one row of 8-bit RGBA pixels into RGBA5551 texels, exactly like
    rgb2c's readtex() + printdata()."""
    row = list(pixels) + [pixels[-1]] * (padded_w - len(pixels))
    out = []
    r_prev = g_prev = b_prev = 0
    r_acc = g_acc = b_acc = 4
    for x in range(padded_w):
        r, g, b, a = row[shuffle ^ x]
        if r == r_prev:
            r_acc = 4
        if g == g_prev:
            g_acc = 4
        if b == b_prev:
            b_acc = 4
        r_acc = min((r_acc & 7) + r, 0xFF)
        g_acc = min((g_acc & 7) + g, 0xFF)
        b_acc = min((b_acc & 7) + b, 0xFF)
        r_prev, g_prev, b_prev = r, g, b
        out.append(
            ((r_acc >> 3) << 11) | ((g_acc >> 3) << 6) | ((b_acc >> 3) << 1) | (a >> 7)
        )
    return out


def _step(prev: int, carry: int, v: int) -> tuple[int, int]:
    """One channel of the dither: returns (5-bit output, new carry)."""
    acc = 4 if v == prev else carry
    acc = min((acc & 7) + v, 0xFF)
    return acc >> 3, acc & 7


def _nearest_valid(c: int, prev: int, carry: int) -> int | None:
    """8-bit value closest to the plain expansion of `c` that dithers to `c`."""
    want = expand5(c)
    best = None
    # v != prev: the accumulator is carry + v, so v must lie in [lo, hi]
    lo = max(0, 8 * c - carry)
    hi = 0xFF if c == 31 else min(0xFF, 8 * c + 7 - carry)
    if lo <= hi:
        v = min(max(want, lo), hi)
        if v != prev:
            best = v
        else:
            for alt in sorted((v - 1, v + 1), key=lambda a: abs(a - want)):
                if lo <= alt <= hi:
                    best = alt
                    break
    # v == prev: the accumulator resets to 4 + v
    if min(4 + prev, 0xFF) >> 3 == c and (best is None or abs(prev - want) < abs(best - want)):
        best = prev
    return best


# Pixels before the padding region whose values are searched rather than picked
# greedily. One free pixel can steer the carry to any value, except when its
# output is clamped at 0 or 31, so leave some slack.
_WINDOW = 8


def _greedy_channel(target: list[int], w: int, shuffle: int) -> list[int] | None:
    """Pick, in emission order, the valid value nearest the plain expansion.
    When the shuffle emits padding before the last pixel, try each value the
    last pixel could take."""
    order = [shuffle ^ x for x in range(len(target))]
    last_x = order.index(w - 1)
    early_pad = any(s >= w for s in order[:last_x])
    if not early_pad:
        return _greedy_pass(target, w, order, None)
    c_last = target[last_x]
    want = [0] * w
    for x, s in enumerate(order):
        if s < w:
            want[s] = expand5(target[x])
    best = None
    for v_last in range(max(0, 8 * c_last - 7), min(0xFF, 8 * c_last + 7) + 1):
        vals = _greedy_pass(target, w, order, v_last)
        if vals is not None:
            cost = sum(abs(v - e) for v, e in zip(vals, want))
            if best is None or cost < best[0]:
                best = (cost, vals)
    return best[1] if best else None


def _greedy_pass(
    target: list[int], w: int, order: list[int], v_last: int | None
) -> list[int] | None:
    vals = [0] * w
    prev, carry = 0, 4
    for x, s in enumerate(order):
        c = target[x]
        if s >= w - 1 and v_last is not None:
            v = v_last
        elif s < w:
            # clamp the plain expansion into the range that dithers to c
            want = (c << 3) | (c >> 2)
            lo = 8 * c - carry
            hi = 0xFF if c == 31 else 8 * c + 7 - carry
            v = lo if want < lo else hi if want > hi else want
            if v < 0 or v > 0xFF or v == prev:
                v = _nearest_valid(c, prev, carry)
                if v is None:
                    return None
            if s == w - 1:
                v_last = v
        else:
            return None
        acc = 4 if v == prev else carry
        acc = min((acc & 7) + v, 0xFF)
        if acc >> 3 != c:
            return None
        carry = acc & 7
        prev = v
        if s < w:
            vals[s] = v
    return vals


def _solve_channel(target: list[int], w: int, shuffle: int) -> list[int] | None:
    """Find 8-bit values v[0..w-1] for one channel such that the dithered,
    padded (v[w..] = v[w-1]) and shuffled row equals `target` (5-bit outputs
    in emission order)."""
    padded_w = len(target)
    greedy = _greedy_channel(target, w, shuffle)
    if greedy is not None:
        return greedy
    order = [shuffle ^ x for x in range(padded_w)]
    first = min(x for x, s in enumerate(order) if s >= w - 1)
    start = max(0, first - _WINDOW)

    vals: dict[int, int] = {}
    prev, carry = 0, 4
    for x in range(start):
        v = _nearest_valid(target[x], prev, carry)
        if v is None:
            return None
        vals[order[x]] = v
        _, carry = _step(prev, carry, v)
        prev = v

    c_last = target[order.index(w - 1)]
    best: tuple[int, dict[int, int]] | None = None
    for v_last in range(max(0, 8 * c_last - 7), min(0xFF, 8 * c_last + 7) + 1):
        # state (prev value, carry) -> (cost, previous state, chosen value)
        layer: dict = {(prev, carry): (0, None, None)}
        layers = []
        for x in range(start, padded_w):
            s, c = order[x], target[x]
            fixed = s >= w - 1
            cost_v = s < w
            want = expand5(c)
            nxt: dict = {}
            for (kpv, kc), (cost, _, _) in layer.items():
                if fixed:
                    cands = (v_last,)
                else:
                    lo = max(0, 8 * c - kc)
                    hi = 0xFF if c == 31 else min(0xFF, 8 * c + 7 - kc)
                    cands = range(lo, hi + 1)
                for v in cands:
                    acc = 4 if v == kpv else kc
                    acc = min((acc & 7) + v, 0xFF)
                    if acc >> 3 != c:
                        continue
                    ncost = cost + (abs(v - want) if cost_v else 0)
                    nkey = (v, acc & 7)
                    if nkey not in nxt or nxt[nkey][0] > ncost:
                        nxt[nkey] = (ncost, (kpv, kc), v)
                if not fixed and min(4 + kpv, 0xFF) >> 3 == c:
                    # repeating the previous value resets the carry to 4
                    v = kpv
                    nkey = (v, min(4 + v, 0xFF) & 7)
                    ncost = cost + (abs(v - want) if cost_v else 0)
                    if nkey not in nxt or nxt[nkey][0] > ncost:
                        nxt[nkey] = (ncost, (kpv, kc), v)
            layers.append(nxt)
            layer = nxt
            if not layer:
                break
        if not layer:
            continue
        key = min(layer, key=lambda k: layer[k][0])
        cost = layer[key][0]
        if best is not None and cost >= best[0]:
            continue
        chosen = {}
        for x in range(padded_w - 1, start - 1, -1):
            _, prev_key, v = layers[x - start][key]
            if order[x] < w:
                chosen[order[x]] = v
            key = prev_key
        best = (cost, chosen)

    if best is None:
        return None
    vals.update(best[1])
    return [vals[i] for i in range(w)]


def decode_rgba16_row(texels: list[int], w: int, shuffle: int) -> list[Pixel]:
    """Inverse of encode_rgba16_row: given the emitted texels of one row
    (including padding), return `w` 8-bit RGBA pixels that encode back to
    exactly those texels."""
    padded_w = len(texels)
    order = [shuffle ^ x for x in range(padded_w)]
    plain = [0] * padded_w
    for x, s in enumerate(order):
        plain[s] = texels[x]

    alpha = [0xFF if t & 1 else 0 for t in plain[:w]]
    if any((plain[s] & 1) != (plain[w - 1] & 1) for s in range(w, padded_w)):
        raise ValueError("padding alpha differs from last pixel")

    channels = []
    for shift in (11, 6, 1):
        target = [(t >> shift) & 31 for t in texels]
        vals = _solve_channel(target, w, shuffle)
        if vals is None:
            raise ValueError("no 8-bit source row reproduces these texels")
        channels.append(vals)
    pixels = list(zip(channels[0], channels[1], channels[2], alpha))
    if encode_rgba16_row(pixels, padded_w, shuffle) != texels:
        raise ValueError("decoded row does not round-trip")
    return pixels
