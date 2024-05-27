#include "common.h"
#include "world/world.h"

void func_802C1B54_644004(GObj*);
void func_802C1C48_6440F8(GObj*);
void func_802C1A20_643ED0(GObj*);

extern PokemonInitData D_802C7590_649A40;
extern AnimationHeader D_802C7274_649724;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1440_6438F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C14C4_643974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C157C_643A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1660_643B10.s")

void func_802C1728_643BD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.05f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1794_643C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1818_643CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C189C_643D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1920_643DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C19BC_643E6C.s")

void func_802C1B1C_643FCC(GObj*);
extern AnimationHeader D_802C7288_649738;
extern idFuncStruct D_802C73E0_649890;

void func_802C1A20_643ED0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802C7288_649738);
    pokemon->transitionGraph = &D_802C73E0_649890;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802C1B1C_643FCC);
}

void func_802C1A7C_643F2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802C1AC8_643F78(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802C7274_649724);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802C1A20_643ED0);
}

void func_802C1B1C_643FCC(GObj* arg0) {
    runPathProcess(arg0, func_802C1C48_6440F8);
    updatePokemonState(arg0, func_802C1B54_644004);
}
#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1B54_644004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1C48_6440F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1E4C_6442FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1EB0_644360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1F08_6443B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1F74_644424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2058_644508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2308_6447B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2504_6449B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C257C_644A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C25D8_644A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2650_644B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C26AC_644B5C.s")

void func_802C2758_644C08(GObj *);
void func_802C27E4_644C94(GObj *);

void func_802C2710_644BC0(GObj *obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 1;
    obj->flags = 0;
    runPathProcess(obj, func_802C27E4_644C94);
    updatePokemonState(obj, func_802C2758_644C08);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2758_644C08.s")

void func_802C27E4_644C94(GObj *obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj,0, 0,0.05f, 0.0f, 2);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2854_644D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C28D0_644D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C294C_644DFC.s")

GObj* func_802C2994_644E44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802C7590_649A40);
}
