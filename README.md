# pokemonsnap

A WIP decomp of Pokemon Snap. 

Note: To use this repository, you must already have a rom for the game.

For Python dependencies:
`pip3 install -r requirements.txt`

## To use

1. Place the US Pokemon Snap rom (retail, not kiosk demo) into the root of the repository as "baserom.z64".
2. (one-time) Set up tools: `./configure.py --setup`
3. Run extraction and disassembly: `./configure.py`
4. Rebuild the rom: `ninja`
