#include "common.h"
#include "world/world.h"

void func_802DED0C_6C6AEC(GObj*);
void func_802DEF28_6C6D08(GObj*);
void func_802DF560_6C7340(GObj*);
void func_802DF5B8_6C7398(GObj*);

extern AnimationHeader D_802E3F08_6CBCE8;
extern idFuncStruct D_802E403C_6CBE1C;
extern AnimationHeader D_802E3F30_6CBD10;
extern idFuncStruct D_802E406C_6CBE4C;
extern AnimationHeader D_802E3F1C_6CBCFC;
extern idFuncStruct D_802E400C_6CBDEC;
extern AnimationHeader D_802E3E18_6CBBF8;
extern idFuncStruct D_802E3E40_6CBC20;
extern PokemonInitData D_802E3EA4_6CBC84;
extern PokemonInitData D_802E40B0_6CBE90;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEC90_6C6A70.s")

extern AnimationHeader D_802E3E04_6CBBE4;
extern idFuncStruct D_802E3E40_6CBC20;

void func_802DED0C_6C6AEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3E04_6CBBE4);
    pokemon->transitionGraph = &D_802E3E40_6CBC20;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DED0C_6C6AEC);
}

void func_802DEEA0_6C6C80(GObj*);
void func_802DEDD4_6C6BB4(GObj*);
extern AnimationHeader D_802E3E18_6CBBF8;

void func_802DED68_6C6B48(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3E18_6CBBF8);
    runPathProcess(obj, func_802DEEA0_6C6C80);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DEDD4_6C6BB4);
}

extern AnimationHeader D_802E3E2C_6CBC0C;
extern idFuncStruct D_802E3E70_6CBC50;

void func_802DEDD4_6C6BB4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3E2C_6CBC0C);
    pokemon->transitionGraph = &D_802E3E70_6CBC50;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_802DEE2C_6C6C0C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3E18_6CBBF8);
    runPathProcess(obj, func_802DEF28_6C6D08);
    pokemon->transitionGraph = &D_802E3E40_6CBC20;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DED0C_6C6AEC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEEA0_6C6C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEF28_6C6D08.s")

GObj* func_802DEF88_6C6D68(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802E3EA4_6CBC84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEFC0_6C6DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF078_6C6E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF0B8_6C6E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF104_6C6EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF154_6C6F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF1F0_6C6FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF360_6C7140.s")

void func_802DF404_6C71E4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3F08_6CBCE8);
    runPathProcess(obj, func_802DF560_6C7340);
    pokemon->transitionGraph = &D_802E403C_6CBE1C;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DF5B8_6C7398);
}

void func_802DF478_6C7258(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3F1C_6CBCFC);
    runPathProcess(obj, func_802DF560_6C7340);
    pokemon->transitionGraph = &D_802E400C_6CBDEC;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DF5B8_6C7398);
}

void func_802DF4EC_6C72CC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3F30_6CBD10);
    runPathProcess(obj, func_802DF560_6C7340);
    pokemon->transitionGraph = &D_802E406C_6CBE4C;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DF5B8_6C7398);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF560_6C7340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF5B8_6C7398.s")

GObj* func_802DF634_6C7414(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E40B0_6CBE90);
}
