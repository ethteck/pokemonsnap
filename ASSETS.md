# Assets

## Audio banks and wave tables

Extraction generates the complete SDK bank graphs in `assets/audio/bank1.yaml`
and `bank2.yaml`, table layouts in `table1.yaml` and `table2.yaml`, and
self-contained Nintendo AIFCs under `assets/audio/waves/bank1/` and `bank2/`.
These ROM-derived sources, generated C/binaries, and authored overrides are
ignored; never commit or distribute game assets. Keep the extracted YAML and
AIFCs as the stock baseline. Rebuilding uses those sources, not the ROM.
Run the commands below from the repository root.

Configuration rescans segments rather than reusing Splat's segment cache, so
generated undefined linker symbols remain complete on repeated runs. Authored
overrides are outside the extraction outputs and are retained.

To replace an existing sample, copy an AIFC to the matching stable sample ID:

```sh
mkdir -p src/audio/instruments/bank1
# Substitute an actual sample_<table offset>_<wavetable offset> ID from table1.yaml.
cp /path/to/replacement.aifc src/audio/instruments/bank1/<sample_id>.aifc
ninja audio-mod
```

Use `bank2/` for IDs from `table2.yaml`. Only existing IDs with the `.aifc`
extension are accepted; unknown names fail instead of silently doing nothing.
Creation, edits and removal are discovered on plain Ninja invocations, including
when the override directory did not exist at configuration time. The always-run
inventory uses Ninja [restat](https://ninja-build.org/manual.html#ref_rule), so an
unchanged inventory/content does not rewrite generated data or recompile it.
No manual YAML/table placement edits, clean, or reconfiguration are needed.
The generated `.inventory.json` file is a machine-only override cache, not an
editable source.

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
uv run tools/build/audio_banks.py generate assets/audio/bank1.yaml assets/audio/table1.yaml src/audio/instruments/bank1 build/assets/audio/bank1.bin.c build/assets/audio/table1.bin
uv run python -m unittest discover -s tests -p 'test_audio_banks.py'
```

`tools/audio_bank.py` remains the lossless extraction/fixed-layout codec for
diagnostics. Production bank generation uses `tools/build/audio_banks.py`; the
Ninja compile edge uses the same configured IDO toolchain as the project.

### Editable source layout and fixed-layout diagnostics

The YAML retains the `snap-sdk-bank-v1` and `snap-sdk-table-v1` format tags.
Bank records are offset-addressed and reference stable IDs, preserving physical
order, shared records, flags and explicit padding. Table samples name their
AIFC `asset`, placement and native length; explicit fill runs account for the
remaining bytes. Books and loops name a `sourceSample` AIFC so its metadata
remains authoritative. YAML serialization does not change these dictionary or
native binary semantics. Keep each bank/table pair in the same directory so
relative AIFC paths resolve consistently.

To rebuild fixed-layout native images without production relocation or C generation:

```sh
uv run tools/audio_bank.py build assets/audio/bank1.yaml assets/audio/table1.yaml /tmp/bank1.bin /tmp/table1.bin
```
