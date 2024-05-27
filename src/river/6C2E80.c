#include "common.h"
#include "world/world.h"

void func_802DB1C4_6C2FA4(GObj*);

extern AnimationHeader D_802E319C_6CAF7C;
extern AnimationHeader D_802E31B0_6CAF90;
extern AnimationHeader D_802E31C4_6CAFA4;
extern PokemonInitData D_802E3328_6CB108;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB0A0_6C2E80.s")

void func_802DB11C_6C2EFC(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802E319C_6CAF7C);
    updatePokemonState(arg0, func_802DB1C4_6C2FA4);
}

void func_802DB154_6C2F34(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802E31B0_6CAF90);
    updatePokemonState(arg0, func_802DB1C4_6C2FA4);
}

void func_802DB18C_6C2F6C(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802E31C4_6CAFA4);
    updatePokemonState(arg0, func_802DB1C4_6C2FA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB1C4_6C2FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB270_6C3050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB388_6C3168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB41C_6C31FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB468_6C3248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB4A8_6C3288.s")

void func_802DB554_6C3334(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.05f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB5C0_6C33A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB630_6C3410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB71C_6C34FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB78C_6C356C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB85C_6C363C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB8EC_6C36CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB93C_6C371C.s")

GObj* func_802DBB54_6C3934(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E3328_6CB108);
}
