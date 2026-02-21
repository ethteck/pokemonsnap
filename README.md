# pokemonsnap

![US Bytes](https://img.shields.io/endpoint?label=US%20Bytes&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpokemonsnap%2Fus%2Fall%2F%3Fmode%3Dshield%26measure%3Dbytes)
![US Functions](https://img.shields.io/endpoint?label=US%20Functions&url=https%3A%2F%2Fprogress.deco.mp%2Fdata%2Fpokemonsnap%2Fus%2Fall%2F%3Fmode%3Dshield%26measure%3Dfuncs)

A WIP decomp of Pokemon Snap.

Note: To use this repository, you must already have a rom for the game.

For Python dependencies:
```
uv sync
source .venv/bin/activate
```

## Setup

1. Place the US Pokemon Snap rom (sha1: `edc7c49cc568c045fe48be0d18011c30f393cbaf`) into the root of the repository as "pokemonsnap.z64".
2. (one-time) Set up tools: `./configure.py --setup`
3. Run extraction and disassembly: `./configure.py`
4. Rebuild the rom: `ninja`
