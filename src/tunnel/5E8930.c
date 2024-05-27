#include "common.h"
#include "world/world.h"

void func_802EBC04_5E8CD4(GObj*);
void func_802EBABC_5E8B8C(GObj*);

extern PokemonInitData D_802EFD10_5ECDE0;
extern PokemonInitData D_802EFD90_5ECE60;
extern PokemonInitData D_802EFE7C_5ECF4C;
extern AnimationHeader D_802EFC48_5ECD18;
extern idFuncStruct D_802EFCCC_5ECD9C;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EB860_5E8930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EB908_5E89D8.s")

void func_802EB98C_5E8A5C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.13333334f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

extern idFuncStruct D_802EFCAC_5ECD7C;

void func_802EB9F8_5E8AC8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 3;
    pokemon->transitionGraph = &D_802EFCAC_5ECD7C;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_802EBA48_5E8B18(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, func_802EBABC_5E8B8C);
    setPokemonAnimation(obj, &D_802EFC48_5ECD18);
    pokemon->transitionGraph = &D_802EFCCC_5ECD9C;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802EBA48_5E8B18);
}

void func_802EBABC_5E8B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.13333334f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBB28_5E8BF8.s")

GObj* func_802EBBA8_5E8C78(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802EFD10_5ECDE0);
}

void func_802EBBE0_5E8CB0(GObj* arg0) {
    updatePokemonState(arg0, func_802EBC04_5E8CD4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBC04_5E8CD4.s")

void func_802EBC78_5E8D48(GObj *obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj,0, 0,0.1f, 0.0f, 2);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}


GObj* func_802EBCE8_5E8DB8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802EFD90_5ECE60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBD20_5E8DF0.s")

extern idFuncStruct D_802EFE48_5ECF18;

void func_802EBD6C_5E8E3C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 3;
    pokemon->transitionGraph = &D_802EFE48_5ECF18;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBDBC_5E8E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBE0C_5E8EDC.s")

void func_802EBEC4_5E8F94(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

GObj* func_802EBF04_5E8FD4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802EFE7C_5ECF4C);
}
