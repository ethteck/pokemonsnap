#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

void func_802E0094_6C7E74(GObj*);

extern PokemonInitData D_802E44B4_6CC294;

void func_802E0070_6C7E50(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E0094_6C7E74);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E0094_6C7E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E00EC_6C7ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E01C8_6C7FA8.s")

void func_802E01F4_6C7FD4(GObj* obj) {
    f32 fader;
    s32 i;
    u32 vol;

    f32 steps = 240;
    fader = 1.0f;

    for (i = 239; i > 0; i--) {
        fader += -1.0f / steps;
        vol = 32512.0f * fader;
        auSetBGMVolume(0, vol);
        auSetBGMVolume(1, vol);
        ohWait(1);
    }

    auSetBGMVolume(0, 0);
    auSetBGMVolume(1, 0);
    Pokemon_StopAuxProc(obj);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E0334_6C8114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E03C0_6C81A0.s")

GObj* func_802E0584_6C8364(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E44B4_6CC294);
}
