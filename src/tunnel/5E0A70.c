#include "common.h"
#include "../world/world.h"
#include "app_level/app_level.h"

void func_802E3B8C_5E0C5C(GObj*);
void func_802E3CC8_5E0D98(GObj*);

extern PokemonInitData D_802EE660_5EB730;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E39A0_5E0A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3A14_5E0AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3AC8_5E0B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3B8C_5E0C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3C18_5E0CE8.s")

void func_802E3CA4_5E0D74(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E3B8C_5E0C5C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3CC8_5E0D98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3D80_5E0E50.s")

void func_802E3E20_5E0EF0(GObj* arg0) {
    Pokemon_SetState(arg0, func_802E3CC8_5E0D98);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3E44_5E0F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3EE4_5E0FB4.s")

void func_802E3F8C_5E105C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E3FD8_5E10A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E40D4_5E11A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4124_5E11F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4234_5E1304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E43B0_5E1480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4434_5E1504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E44DC_5E15AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E45B4_5E1684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4668_5E1738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4710_5E17E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E480C_5E18DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4844_5E1914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E487C_5E194C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4964_5E1A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E49A4_5E1A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E0A70/func_802E4A84_5E1B54.s")

GObj* func_802E4AFC_5E1BCC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EE660_5EB730);
}
