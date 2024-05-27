#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802DBB78_72CD78(GObj*);
void func_802DBDB8_72CFB8(GObj*);

extern AnimationHeader D_802E2764_733964;
extern AnimationHeader D_802E2778_733978;
extern AnimationHeader D_802E27B4_7339B4;
extern InteractionHandler D_802E2804_733A04[];
extern InteractionHandler D_802E2984_733B84[];
extern RandomState D_802E2A64_733C64[];
extern PokemonInitData D_802E2AA8_733CA8;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DB5A0_72C7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DB660_72C860.s")

void func_802DB6F8_72C8F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2764_733964);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2804_733A04;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DB768_72C968.s")

void func_802DB80C_72CA0C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DB868_72CA68.s")

void func_802DB90C_72CB0C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DB968_72CB68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E2778_733978);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2804_733A04;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

void func_802DB9D8_72CBD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E27B4_7339B4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2984_733B84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DBDB8_72CFB8);
}

void func_802DBA48_72CC48(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E27B4_7339B4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2984_733B84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DBDB8_72CFB8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBAB8_72CCB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBB2C_72CD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBB78_72CD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBC00_72CE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBC84_72CE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBD34_72CF34.s")

void func_802DBD94_72CF94(GObj* arg0) {
    Pokemon_SetState(arg0, func_802DBB78_72CD78);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBDB8_72CFB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBE18_72D018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBE8C_72D08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBED8_72D0D8.s")

void func_802DBF4C_72D14C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBFA8_72D1A8.s")

GObj* func_802DC018_72D218(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2AA8_733CA8);
}
