#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern AnimationHeader D_802E29FC_6CA7DC;
extern InteractionHandler D_802E2AC4_6CA8A4[];
extern RandomState D_802E2B24_6CA904[];
extern PokemonInitData D_802E2BDC_6CA9BC;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9520_6C1300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9664_6C1444.s")

void func_802D96FC_6C14DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E29FC_6CA7DC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2AC4_6CA8A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2B24_6CA904);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D976C_6C154C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9808_6C15E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D990C_6C16EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9990_6C1770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9A0C_6C17EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9A58_6C1838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9AC4_6C18A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9C8C_6C1A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9D7C_6C1B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9DD8_6C1BB8.s")

GObj* func_802D9F44_6C1D24(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2BDC_6CA9BC);
}
