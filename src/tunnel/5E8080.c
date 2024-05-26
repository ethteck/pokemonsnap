#include "common.h"

#include "world/world.h"

extern PokemonInitData D_802EFAFC_5ECBCC;
extern GObj* D_802EFBA4_5ECC74;
extern PokemonInitData D_802EFC0C_5ECCDC;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EAFB0_5E8080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB014_5E80E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB0CC_5E819C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB28C_5E835C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB35C_5E842C.s")

GObj* func_802EB3A8_5E8478(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802EFAFC_5ECBCC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB3E0_5E84B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB430_5E8500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB548_5E8618.s")

void func_802EB664_5E8734(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.1f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB6D0_5E87A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB750_5E8820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB7AC_5E887C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8080/func_802EB7E4_5E88B4.s")

GObj* func_802EB818_5E88E8(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EFBA4_5ECC74 = spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_802EFC0C_5ECCDC);

    return D_802EFBA4_5ECC74;
}
