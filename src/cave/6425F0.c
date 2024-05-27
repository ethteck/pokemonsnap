#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802C6F14_6493C4;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0140_6425F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0220_6426D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C027C_64272C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C02BC_64276C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0330_6427E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C03E4_642894.s")

void func_802C04A4_642954(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0510_6429C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C05D8_642A88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0630_642AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C06BC_642B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6425F0/func_802C0748_642BF8.s")

GObj* func_802C07D4_642C84(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C6F14_6493C4);
}
