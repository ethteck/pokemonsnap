#include "common.h"

#include "world/world.h"

extern AnimationHeader D_802D315C_7AC6EC;
extern AnimationHeader D_802D3170_7AC700;
extern AnimationHeader D_802D3184_7AC714;
extern AnimationHeader D_802D3198_7AC728;
extern AnimationHeader D_802D31AC_7AC73C;
extern AnimationHeader D_802D31C0_7AC750;
extern AnimationHeader D_802D31D4_7AC764;
extern AnimationHeader D_802D31E8_7AC778;
extern AnimationHeader D_802D31FC_7AC78C;
extern AnimationHeader D_802D3210_7AC7A0;
extern idFuncStruct D_802D3224_7AC7B4;
extern randomTransition D_802D3274_7AC804;
extern idFuncStruct D_802D32B4_7AC844;
extern idFuncStruct D_802D32D4_7AC864;
extern idFuncStruct D_802D3304_7AC894;
extern idFuncStruct D_802D3334_7AC8C4;
extern idFuncStruct D_802D3374_7AC904;
extern PokemonInitData D_802D33F8_7AC988;

void func_802CA7A0_7A3D30(GObj*);
void func_802CA8F8_7A3E88(GObj*);
void func_802CA9BC_7A3F4C(GObj*);
void func_802CAAD0_7A4060(GObj*);
void func_802CABD0_7A4160(GObj*);
void func_802CADEC_7A437C(GObj*);
void func_802CAE70_7A4400(GObj*);
void func_802CAF04_7A4494(GObj*);

void func_802CA6C0_7A3C50(GObj* obj) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (TRUE) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 2 || (sp34 == 2 && sp30 >= 0.1)) {
            break;
        }
        ohWait(1);
    }
    runPokemonCleanup(obj);
    func_8035EDC8_4FF1D8(obj);
}

void func_802CA768_7A3CF8(GObj* obj) {
    func_8035ED90_4FF1A0(obj, func_802CA6C0_7A3C50);
    updatePokemonState(obj, func_802CA7A0_7A3D30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA7A0_7A3D30.s")

void func_802CA858_7A3DE8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 42);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802CA8A4_7A3E34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3210_7AC7A0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802CA8F8_7A3E88);
}

void func_802CA8F8_7A3E88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 0x2 | 0x1;
    pokemon->transitionGraph = &D_802D32B4_7AC844;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_802CA948_7A3ED8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    pokemon->flags |= 0x800;
    pokemon->tangible = 1;
    obj->flags = 0;
    setPokemonAnimation(obj, &D_802D31FC_7AC78C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802CA9BC_7A3F4C);
}

void func_802CA9BC_7A3F4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_802D315C_7AC6EC);
    pokemon->transitionGraph = &D_802D3224_7AC7B4;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802D3274_7AC804);
}

void func_802CAA2C_7A3FBC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3170_7AC700);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802CAAD0_7A4060);
    pokemon->transitionGraph = &D_802D3224_7AC7B4;
    runInteractionsAndWaitForFlags(obj, 0x2 | 0x1);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802CA9BC_7A3F4C);
    }
    weightedRandomStaightTransition(obj, &D_802D3274_7AC804);
}

void func_802CAAD0_7A4060(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 0x2;
    omEndProcess(NULL);
}

void func_802CAB2C_7A40BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3184_7AC714);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802CABD0_7A4160);
    pokemon->transitionGraph = &D_802D3224_7AC7B4;
    runInteractionsAndWaitForFlags(obj, 0x2 | 0x1);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802CA9BC_7A3F4C);
    }
    weightedRandomStaightTransition(obj, &D_802D3274_7AC804);
}

void func_802CABD0_7A4160(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 0x2;
    omEndProcess(NULL);
}

void func_802CAC2C_7A41BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_802D31AC_7AC73C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_802D31C0_7AC750);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_802D31D4_7AC764);
    pokemon->transitionGraph = &D_802D32D4_7AC864;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802CA9BC_7A3F4C);
}

void func_802CACE4_7A4274(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_802D3198_7AC728);
    pokemon->transitionGraph = &D_802D3304_7AC894;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802CA9BC_7A3F4C);
}

void func_802CAD54_7A42E4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3170_7AC700);
    runPathProcess(obj, func_802CADEC_7A437C);
    pokemon->transitionGraph = &D_802D3334_7AC8C4;
    runInteractionsAndWaitForFlags(obj, 2);
    if (!(pokemon->processFlags & 0x10)) {
        updatePokemonState(obj, func_802CA9BC_7A3F4C);
    }
    updatePokemonState(obj, func_802CAE70_7A4400);
}

void func_802CADEC_7A437C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0);
    setPokemonAnimation(obj, &D_802D3184_7AC714);
    pokemon->hSpeed = 80.0f;
    func_80361748_501B58(obj, 50.0f, 0.1f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 0x2;
    omEndProcess(NULL);
}

void func_802CAE70_7A4400(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D31E8_7AC778);
    runPathProcess(obj, func_802CAF04_7A4494);
    pokemon->transitionGraph = &D_802D3374_7AC904;
    runInteractionsAndWaitForFlags(obj, 1);
    if (pokemon->interactionTarget != NULL) {
        updatePokemonState(obj, func_802CAE70_7A4400);
    }
    weightedRandomStaightTransition(obj, &D_802D3274_7AC804);
}

void func_802CAF04_7A4494(GObj* obj) {
    while (TRUE) {
        func_8036148C_50189C(obj, 0.1f, 0);
        ohWait(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAF54_7A44E4.s")

void func_802CB008_7A4598(GObj* obj) {
    updatePokemonState(obj, func_802CAD54_7A42E4);
}

void func_802CB02C_7A45BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_802D33F8_7AC988);
}
