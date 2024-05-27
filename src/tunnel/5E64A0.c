#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802E9C3C_5E6D0C(GObj*);
void func_802E9C60_5E6D30(GObj*);
void func_802E9C98_5E6D68(GObj*);
void func_802E9D04_5E6DD4(GObj*);

extern PokemonInitData D_802EF714_5EC7E4;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E93D0_5E64A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E944C_5E651C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9538_5E6608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E95E8_5E66B8.s")

void func_802E968C_5E675C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E96E8_5E67B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E97EC_5E68BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9854_5E6924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E98F4_5E69C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9A48_5E6B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9A94_5E6B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9AF8_5E6BC8.s")

void func_802E9B90_5E6C60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 100.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 3);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9BEC_5E6CBC.s")

void func_802E9C18_5E6CE8(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E9C3C_5E6D0C);
}

void func_802E9C3C_5E6D0C(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E9C60_5E6D30);
}

void func_802E9C60_5E6D30(GObj* arg0) {
    Pokemon_StartPathProc(arg0, func_802E9C98_5E6D68);
    Pokemon_SetState(arg0, func_802E9D04_5E6DD4);
}

void func_802E9C98_5E6D68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9D04_5E6DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9D70_5E6E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9DD8_5E6EA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9E54_5E6F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9F20_5E6FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802E9F80_5E7050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA030_5E7100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA098_5E7168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA108_5E71D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA1B4_5E7284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA21C_5E72EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA344_5E7414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA3A0_5E7470.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA3EC_5E74BC.s")

GObj* func_802EA424_5E74F4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EF714_5EC7E4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E64A0/func_802EA45C_5E752C.s")
