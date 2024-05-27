#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802C6F14_6493C4;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0140_6425F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0220_6426D0.s")

extern idFuncStruct D_802C6D90_649240;

void func_802C027C_64272C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802C6D90_649240;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C02BC_64276C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0330_6427E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C03E4_642894.s")

void func_802C04A4_642954(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.05f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0510_6429C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C05D8_642A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0630_642AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C06BC_642B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0748_642BF8.s")

GObj* func_802C07D4_642C84(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802C6F14_6493C4);
}
