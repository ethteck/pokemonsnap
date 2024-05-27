#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E31B0_7343B0;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F100/func_802DDF00_72F100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F100/func_802DDF7C_72F17C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F100/func_802DE0DC_72F2DC.s")

void func_802DE144_72F344(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.13333334f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F100/func_802DE1B0_72F3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F100/func_802DE1F0_72F3F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F100/func_802DE26C_72F46C.s")

GObj* func_802DE34C_72F54C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E31B0_7343B0);
}
