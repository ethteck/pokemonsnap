#include "valley.h"

void func_802C9840_7A2DD0(GObj*);
void func_802C9990_7A2F20(GObj*);

extern PokemonInitData D_802D2F2C_7AC4BC;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9840_7A2DD0.s")

void func_802C9958_7A2EE8(GObj* arg0) {
    Pokemon_StartAuxProc(arg0, func_802C9840_7A2DD0);
    Pokemon_SetState(arg0, func_802C9990_7A2F20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9990_7A2F20.s")

void func_802C9A48_7A2FD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9A94_7A3024.s")

void func_802C9B0C_7A309C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9B78_7A3108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9BD0_7A3160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9C84_7A3214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9D00_7A3290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9DC4_7A3354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9E60_7A33F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9EC8_7A3458.s")

void func_802C9F34_7A34C4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C9F90_7A3520(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D2F2C_7AC4BC);
}
