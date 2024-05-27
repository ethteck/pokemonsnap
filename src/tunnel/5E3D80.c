#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802EED40_5EBE10;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E6CB0_5E3D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E6D90_5E3E60.s")

void func_802E6F48_5E4018(GObj*);
extern AnimationHeader D_802EEC08_5EBCD8;
extern idFuncStruct D_802EEC1C_5EBCEC;

void func_802E6E0C_5E3EDC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802EEC08_5EBCD8);
    runPathProcess(obj, func_802E6F48_5E4018);
    pokemon->transitionGraph = &D_802EEC1C_5EBCEC;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_802E6D90_5E3E60(GObj*);
void func_802E6EE8_5E3FB8(GObj*);
extern AnimationHeader D_802EEC08_5EBCD8;

void func_802E6E7C_5E3F4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802EEC08_5EBCD8);
    runPathProcess(obj, func_802E6EE8_5E3FB8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802E6D90_5E3E60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E6EE8_5E3FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E6F48_5E4018.s")

void func_802E6D90_5E3E60(GObj*);
void func_802E7014_5E40E4(GObj*);
extern AnimationHeader D_802EEC08_5EBCD8;

void func_802E6FA8_5E4078(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802EEC08_5EBCD8);
    runPathProcess(obj, func_802E7014_5E40E4);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802E6D90_5E3E60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E7014_5E40E4.s")

extern idFuncStruct D_802EEC6C_5EBD3C;

void func_802E70BC_5E418C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802EEC6C_5EBD3C;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E70FC_5E41CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E71D4_5E42A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E729C_5E436C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E7324_5E43F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E73D0_5E44A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E74A4_5E4574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E7504_5E45D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E7594_5E4664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E3D80/func_802E75F4_5E46C4.s")

GObj* func_802E7620_5E46F0(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802EED40_5EBE10);
}
