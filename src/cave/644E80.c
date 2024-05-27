#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802C7728_649BD8;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C29D0_644E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2AC4_644F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2B0C_644FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2B54_645004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2B9C_64504C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2BDC_64508C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2C90_645140.s")

void func_802C2D00_6451B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2D6C_64521C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2D98_645248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2E24_6452D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2EBC_64536C.s")

void func_802C2F48_6453F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2FB4_645464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C2FF4_6454A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C30B8_645568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/644E80/func_802C31D0_645680.s")

GObj* func_802C3250_645700(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C7728_649BD8);
}
