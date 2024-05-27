#include "common.h"

#include "world/world.h"

extern GObj* D_802C7B4C_649FFC;
extern PokemonInitData D_802C7B9C_64A04C;

extern idFuncStruct D_802C7B50_64A000;

void func_802C46A0_646B50(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 3;
    pokemon->transitionGraph = &D_802C7B50_64A000;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C46F0_646BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C4820_646CD0.s")

void func_802C493C_646DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.075f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

GObj* func_802C49A8_646E58(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802C7B4C_649FFC = spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_802C7B9C_64A04C);

    return D_802C7B4C_649FFC;
}
