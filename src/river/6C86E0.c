#include "common.h"
#include "world/world.h"

void func_802E142C_6C920C(GObj*);
void func_802E1488_6C9268(GObj*);
void func_802E1594_6C9374(GObj*);
void func_802E1110_6C8EF0(GObj*);
void func_802E0E20_6C8C00(GObj*);
void func_802E0C3C_6C8A1C(GObj*);

extern AnimationHeader D_802E4720_6CC500;
extern idFuncStruct D_802E4938_6CC718;
extern idFuncStruct D_802E4908_6CC6E8;
extern AnimationHeader D_802E470C_6CC4EC;
extern AnimationHeader D_802E46D0_6CC4B0;
extern AnimationHeader D_802E46E4_6CC4C4;
extern AnimationHeader D_802E46F8_6CC4D8;
extern idFuncStruct D_802E4838_6CC618;
extern randomTransition D_802E4978_6CC758;
extern PokemonInitData D_802E4AA8_6CC888;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E0900_6C86E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E09A8_6C8788.s")

void func_802E0A48_6C8828(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E46D0_6CC4B0);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E4838_6CC618;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E4978_6CC758);
}

void func_802E0AB8_6C8898(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E46E4_6CC4C4);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E4838_6CC618;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E4978_6CC758);
}

void func_802E0B28_6C8908(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E46F8_6CC4D8);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E4838_6CC618;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E4978_6CC758);
}

void func_802E0B98_6C8978(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E470C_6CC4EC);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802E0C3C_6C8A1C);
    pokemon->transitionGraph = &D_802E4838_6CC618;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802E0A48_6C8828);
    }
    weightedRandomStaightTransition(obj, &D_802E4978_6CC758);
}

void func_802E0C3C_6C8A1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E0C98_6C8A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E0D44_6C8B24.s")

void func_802E0DAC_6C8B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E4720_6CC500);
    runPathProcess(obj, func_802E0E20_6C8C00);
    pokemon->transitionGraph = &D_802E4938_6CC718;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802E0A48_6C8828);
}

void func_802E0E20_6C8C00(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E0E7C_6C8C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E0F04_6C8CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E0F9C_6C8D7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E1030_6C8E10.s")

void func_802E1094_6C8E74(void) {
}

void func_802E109C_6C8E7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E470C_6CC4EC);
    runPathProcess(obj, func_802E1110_6C8EF0);
    pokemon->transitionGraph = &D_802E4908_6CC6E8;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802E0A48_6C8828);
}

void func_802E1110_6C8EF0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2E);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E115C_6C8F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E1194_6C8F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E11D4_6C8FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E12D8_6C90B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E1374_6C9154.s")

void func_802E13F4_6C91D4(GObj* arg0) {
    runPathProcess(arg0, func_802E1488_6C9268);
    updatePokemonState(arg0, func_802E142C_6C920C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E142C_6C920C.s")

void func_802E1488_6C9268(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.05f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E14F4_6C92D4.s")

void func_802E1570_6C9350(GObj* arg0) {
    updatePokemonState(arg0, func_802E1594_6C9374);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E1594_6C9374.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E1604_6C93E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E1678_6C9458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E171C_6C94FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E17D4_6C95B4.s")

GObj* func_802E1864_6C9644(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E4AA8_6CC888);
}
