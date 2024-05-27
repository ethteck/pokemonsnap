#include "common.h"
#include "world/world.h"

void func_802E53DC_5E24AC(GObj*);
void func_802E5668_5E2738(GObj*);
void func_802E583C_5E290C(GObj*);

extern PokemonInitData D_802EE95C_5EBA2C;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E50F0_5E21C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E5134_5E2204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E5160_5E2230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E5244_5E2314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E529C_5E236C.s")

void func_802E53B8_5E2488(GObj* arg0) {
    updatePokemonState(arg0, func_802E53DC_5E24AC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E53DC_5E24AC.s")

void func_802E5448_5E2518(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E54B4_5E2584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E54F0_5E25C0.s")

void func_802E556C_5E263C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.043333337f, 0.0f, 3U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E55D8_5E26A8.s")

void func_802E5644_5E2714(GObj* arg0) {
    updatePokemonState(arg0, func_802E5668_5E2738);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E5668_5E2738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E56D8_5E27A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E5748_5E2818.s")

void func_802E5818_5E28E8(GObj* arg0) {
    updatePokemonState(arg0, func_802E583C_5E290C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E583C_5E290C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E58B0_5E2980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E21C0/func_802E5968_5E2A38.s")

GObj* func_802E5C74_5E2D44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802EE95C_5EBA2C);
}
