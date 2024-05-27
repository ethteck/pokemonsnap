#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802EBC04_5E8CD4(GObj*);

extern PokemonInitData D_802EFD10_5ECDE0;
extern PokemonInitData D_802EFD90_5ECE60;
extern PokemonInitData D_802EFE7C_5ECF4C;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EB860_5E8930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EB908_5E89D8.s")

void func_802EB98C_5E8A5C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EB9F8_5E8AC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBA48_5E8B18.s")

void func_802EBABC_5E8B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBB28_5E8BF8.s")

GObj* func_802EBBA8_5E8C78(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802EFD10_5ECDE0);
}

void func_802EBBE0_5E8CB0(GObj* arg0) {
    Pokemon_SetState(arg0, func_802EBC04_5E8CD4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBC04_5E8CD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBC78_5E8D48.s")

GObj* func_802EBCE8_5E8DB8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EFD90_5ECE60);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBD20_5E8DF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBD6C_5E8E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBDBC_5E8E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBE0C_5E8EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E8930/func_802EBEC4_5E8F94.s")

GObj* func_802EBF04_5E8FD4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EFE7C_5ECF4C);
}
