# pokemonsnap
A WIP decomp of Pokemon Snap. 

Note: To use this repository, you must already have a rom for the game.

# To use
1. Place the US Pokemon Snap rom into the root of the repository as "baserom.z64".
2. Run `git submodule update --init --recursive` to set up submodules
3. Build sm64tools: `cd sm64tools && make && cd ..`
4. Split the rom: `./splitrom.sh`
5. Re-assemble the rom: `cd pokemonsnap && make`
