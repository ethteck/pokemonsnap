# pokemonsnap

[![US Bytes]](https://decomp.dev/ethteck/pokemonsnap/us)
[![US Functions]](https://decomp.dev/ethteck/pokemonsnap/us)

[US Bytes]: https://decomp.dev/ethteck/pokemonsnap/us.svg?mode=shield&label=US+Bytes&measure=matched_code_percent
[US Functions]: https://decomp.dev/ethteck/pokemonsnap/us.svg?mode=shield&label=US+Functions&measure=matched_functions_percent

A WIP decomp of Pokemon Snap.

Note: To use this repository, you must already have a rom for the game.

For Python dependencies:
`uv sync`

## Setup

1. Place the US Pokemon Snap rom (sha1: `edc7c49cc568c045fe48be0d18011c30f393cbaf`) into the root of the repository as "pokemonsnap.z64".
2. (one-time) Set up tools: `uv run configure.py --setup`
3. Run extraction and disassembly: `uv run configure.py`
4. Rebuild the rom: `ninja`

## Audio banks and wave tables

Extraction generates the complete SDK bank graphs in `assets/audio/bank1.json`
and `bank2.json`, table layouts in `table1.json` and `table2.json`, and
self-contained Nintendo AIFCs under `assets/audio/waves/bank1/` and `bank2/`.
These ROM-derived sources, generated C/binaries, and authored overrides are
ignored; never commit or distribute game assets. Keep the extracted JSON and
AIFCs as the stock baseline. Rebuilding uses those sources, not the ROM.

Configuration rescans segments rather than reusing Splat's segment cache, so
generated undefined linker symbols remain complete on repeated runs. Authored
overrides are outside the extraction outputs and are retained.

To replace an existing sample, copy an AIFC to the matching stable sample ID:

```sh
mkdir -p src/audio/instruments/bank1
# Substitute an actual sample_<table offset>_<wavetable offset> ID from table1.json.
cp /path/to/replacement.aifc src/audio/instruments/bank1/<sample_id>.aifc
ninja audio-mod
```

Use `bank2/` for IDs from `table2.json`. Only existing IDs with the `.aifc`
extension are accepted; unknown names fail instead of silently doing nothing.
Creation, edits and removal are discovered on plain Ninja invocations, including
when the override directory did not exist at configuration time. The always-run
inventory uses Ninja [restat](https://ninja-build.org/manual.html#ref_rule), so an
unchanged inventory/content does not rewrite generated data or recompile it.
No manual JSON/table placement edits, clean, or reconfiguration are needed.

Inputs must be mono Nintendo VADPCM (`VAPC`, with `VADPCMCODES` and optional
`VADPCMLOOPS`) or big-endian PCM16 (`NONE`) AIFC at the existing bank sample rate.
PCM16 sustain loops may use standard `MARK`/`INST` chunks; forward loops are
supported, while ping-pong and separate release loops are rejected. Active
native loops must have positive length.
There is no WAV importer, ADPCM encoder, retuning, or new sound-ID allocation.
Different encoded lengths and codebook/loop geometry are supported; shared
metadata is retained when equal and isolated when an override diverges.
Non-overridden sound/envelope/keymap fields and flags are preserved. Native
partial-frame zero tails remain represented for stock samples; AIFC sample
counts do not reconstruct unknown precompression trim.

The generator emits an actual typed C aggregate with SDK records, exact-count
wrappers, inline alignment padding, compile-time layout assertions and
`offsetof` disk pointers. Configured IDO 7.1 compiles it directly into
`build/assets/audio/bankN.bin.o`'s `.data`; this is not a C byte dump or a
Python bank binary wrapped as an object. Table payloads are rebuilt from AIFCs,
with 8-byte sample/book alignment. Existing linker object identities and runtime
ROM-label loading are retained; no game audio runtime changes are required.

`ninja audio-mod` writes `build/pokemonsnap.mod.z64`, a 16 MiB ROM with corrected
CIC-6103 header checksums and a trimmed/extended `0xFF` tail. Oversized ROMs fail.
The normal `ninja`/`build/pokemonsnap.ok` matching checksum gate is unchanged and
intentionally rejects modified audio. Existing runtime audio memory remains
fixed (heap `0x4B000`); substantially larger bank graphs need a capacity review,
not an assumption that any ROM-fitting payload is runtime-safe.

Remove overrides to restore the exact stock output, without re-extraction:

```sh
rm src/audio/instruments/bank1/<sample_id>.aifc
ninja build/pokemonsnap.ok
```

For isolated generation (the bank output is C, not a bank `.bin`):

```sh
uv run tools/build/audio_banks.py generate assets/audio/bank1.json assets/audio/table1.json src/audio/instruments/bank1 build/assets/audio/bank1.bin.c build/assets/audio/table1.bin
uv run python -m unittest discover -s tests -p 'test_audio_banks.py'
```

`tools/audio_bank.py` remains the lossless extraction/fixed-layout codec for
diagnostics. Production bank generation uses `tools/build/audio_banks.py`; the
Ninja compile edge uses the same configured IDO toolchain as the project.
