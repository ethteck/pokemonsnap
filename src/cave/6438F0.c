#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802C1B54_644004(GObj*);
void func_802C1C48_6440F8(GObj*);

extern PokemonInitData D_802C7590_649A40;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1440_6438F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C14C4_643974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C157C_643A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1660_643B10.s")

void func_802C1728_643BD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1794_643C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1818_643CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C189C_643D4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1920_643DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C19BC_643E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1A20_643ED0.s")

void func_802C1A7C_643F2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1AC8_643F78.s")

void func_802C1B1C_643FCC(GObj* arg0) {
    Pokemon_StartPathProc(arg0, func_802C1C48_6440F8);
    Pokemon_SetState(arg0, func_802C1B54_644004);
}
#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1B54_644004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1C48_6440F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1E4C_6442FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1EB0_644360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1F08_6443B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C1F74_644424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2058_644508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2308_6447B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2504_6449B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C257C_644A2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C25D8_644A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2650_644B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C26AC_644B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2710_644BC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2758_644C08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C27E4_644C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C2854_644D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C28D0_644D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6438F0/func_802C294C_644DFC.s")

GObj* func_802C2994_644E44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C7590_649A40);
}
