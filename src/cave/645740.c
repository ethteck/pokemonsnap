#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802C33E4_645894(GObj*);

extern PokemonInitData D_802C77FC_649CAC;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3290_645740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3348_6457F8.s")

GObj* func_802C3388_645838(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C77FC_649CAC);
}

void func_802C33C0_645870(GObj* arg0) {
    Pokemon_SetState(arg0, func_802C33E4_645894);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C33E4_645894.s")

void func_802C3494_645944(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C34E0_645990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3580_645A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3658_645B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C36F0_645BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3784_645C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3840_645CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3874_645D24.s")
