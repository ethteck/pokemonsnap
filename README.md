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

## Game data

Game data is rebuilt from typed C tables, descriptors, and animation commands.
Textures, palettes, vertices, display lists, fonts, replay/effect scripts, photo
scenes, and audio payloads are extracted from the user-supplied ROM into ignored
`assets/` and `build/` directories; do not commit these generated files.

The three VPK0 payloads are compiled and linked from native source before
compression. Their extraction and linker layouts are in `tools/native_layouts/`.
Audio banks and compact sequences have editable JSON representations; waveform
samples use self-contained AIFC files. The build encodes these extracted assets
back into their original formats.

Run `uv run configure.py` after changing extraction layouts or symbol mappings,
then run `ninja`. The build checks the original ROM checksum. Use
`cmp pokemonsnap.z64 build/pokemonsnap.z64` for a complete byte comparison.

The unreferenced 32×32 texture `D_801428D8_438D18` is interpreted as I4.
No reachable consumer distinguishes I4 from IA4; its original bytes round-trip
exactly.
