#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802E4B64_5E1C34(GObj*);
void func_802E4DA4_5E1E74(GObj*);

extern AnimationHeader D_802EE6A4_5EB774;
extern InteractionHandler D_802EE6B8_5EB788[];
extern RandomState D_802EE6F8_5EB7C8[];
extern PokemonInitData D_802EE79C_5EB86C;

void func_802E4B40_5E1C10(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E4B64_5E1C34);
}

void func_802E4B64_5E1C34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802EE6A4_5EB774);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EE6B8_5EB788;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802EE6F8_5EB7C8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4BD4_5E1CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4C6C_5E1D3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4CBC_5E1D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4D54_5E1E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4DA4_5E1E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4E2C_5E1EFC.s")

void func_802E4EA4_5E1F74(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E4DA4_5E1E74);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4EC8_5E1F98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E4F4C_5E201C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E5008_5E20D8.s")

GObj* func_802E505C_5E212C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EE79C_5EB86C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E1C10/func_802E5094_5E2164.s")
