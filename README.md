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

## Idle replays

Extraction writes the beach and tunnel idle recordings to
`assets/idle_script_beach.json` and `assets/idle_script_tunnel.json`. Edit the
header and controller `inputs` in these ignored files, then run `ninja` to
regenerate the native recordings and rebuild the ROM. Running extraction again
overwrites these edits, so save any recordings you want to keep elsewhere.
Configuration rescans ROM segments to regenerate complete undefined linker
symbols; cached scans can omit symbols needed when edited data triggers a relink.

The JSON preserves the header's `dataSize` independently of the physical input
count, the reserved header word, and the tunnel recording's incomplete final
input (`partialInput`). Do not complete that prefix or add padding when
rebuilding an unchanged recording.

For standalone conversion:

```sh
python tools/idle_script.py extract input.bin output.json
python tools/idle_script.py build input.json output.bin
```
