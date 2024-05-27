#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"

extern GObj* D_802C7B4C_649FFC;
extern PokemonInitData D_802C7B9C_64A04C;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C46A0_646B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C46F0_646BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C4820_646CD0.s")

void func_802C493C_646DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.075f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C49A8_646E58(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802C7B4C_649FFC = Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802C7B9C_64A04C);

    return D_802C7B4C_649FFC;
}
