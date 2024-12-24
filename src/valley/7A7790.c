#include "valley.h"

void func_802CE224_7A77B4(GObj*);
void func_802CE7D8_7A7D68(GObj*);

extern PokemonInitData D_802D3F38_7AD4C8;

void func_802CE200_7A7790(GObj* arg0) {
    Pokemon_SetState(arg0, func_802CE224_7A77B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE224_7A77B4.s")

void func_802CE2DC_7A786C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE328_7A78B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE37C_7A790C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE3CC_7A795C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE440_7A79D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE4B0_7A7A40.s")

void func_802CE554_7A7AE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE5B0_7A7B40.s")

void func_802CE654_7A7BE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE6B0_7A7C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE768_7A7CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE7D8_7A7D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE870_7A7E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE8F4_7A7E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE978_7A7F08.s")

void func_802CEA34_7A7FC4(GObj* arg0) {
    Pokemon_SetState(arg0, func_802CE7D8_7A7D68);
}

GObj* func_802CEA58_7A7FE8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D3F38_7AD4C8);
}
