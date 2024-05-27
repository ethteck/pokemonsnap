#include "common.h"
#include "world/world.h"

void func_802C1178_643628(GObj*);

extern PokemonDef D_802C6FC4_649474;
extern PokemonInitData D_802C7040_6494F0;
extern PokemonInitData D_802C714C_6495FC;
extern PokemonInitData D_802C7194_649644;
extern AnimationHeader D_802C70DC_64958C;

/*
void evolveIntoMuk(GObj* obj) {
    GObj* muk;
    PokemonDef def = D_802C6FC4_649474;

    muk = addPokemonAtGeo(obj, PokemonID_MUK, &def);
    muk->userData.rootNode->xform->euler.y = obj->userData.rootNode->xform->euler.y;
    omEndProcess(NULL);
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/evolveIntoMuk.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0888_642D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0960_642E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C09C4_642E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0A28_642ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0A8C_642F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0AF0_642FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0BB0_643060.s")

void func_802C0CD8_643188(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0D34_6431E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0E28_6432D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0E80_643330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C0F30_6433E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C1018_6434C8.s")

GObj* func_802C10C8_643578(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C7040_6494F0);
}

void func_802C1100_6435B0(GObj* arg0) {
    updatePokemonState(arg0, func_802C1178_643628);
}

void func_802C1124_6435D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802C70DC_64958C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802C1178_643628);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C1178_643628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C11E8_643698.s")

void func_802C1288_643738(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.01f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C12E4_643794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642CC0/func_802C134C_6437FC.s")

GObj* func_802C13B4_643864(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C714C_6495FC);
}

GObj* func_802C13EC_64389C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C7194_649644);
}
