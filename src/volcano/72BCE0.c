#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802DB0B8_72C2B8(GObj*);
void func_802DB2F8_72C4F8(GObj*);

extern AnimationHeader D_802E23A4_7335A4;
extern AnimationHeader D_802E23B8_7335B8;
extern AnimationHeader D_802E23F4_7335F4;
extern InteractionHandler D_802E2444_733644[];
extern InteractionHandler D_802E25F4_7337F4[];
extern RandomState D_802E26D4_7338D4[];
extern PokemonInitData D_802E2710_733910;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DAAE0_72BCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DAB90_72BD90.s")

void func_802DAC38_72BE38(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E23A4_7335A4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2444_733644;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E26D4_7338D4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DACA8_72BEA8.s")

void func_802DAD4C_72BF4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DADA8_72BFA8.s")

void func_802DAE4C_72C04C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DAEA8_72C0A8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E23B8_7335B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2444_733644;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E26D4_7338D4);
}
void func_802DAF18_72C118(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E23F4_7335F4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E25F4_7337F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DB2F8_72C4F8);
}

void func_802DAF88_72C188(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E23F4_7335F4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E25F4_7337F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DB2F8_72C4F8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DAFF8_72C1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB06C_72C26C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB0B8_72C2B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB140_72C340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB1C4_72C3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB274_72C474.s")

void func_802DB2D4_72C4D4(GObj* arg0) {
    Pokemon_SetState(arg0, func_802DB0B8_72C2B8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB2F8_72C4F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB358_72C558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB3CC_72C5CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB418_72C618.s")

void func_802DB48C_72C68C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72BCE0/func_802DB4E8_72C6E8.s")

GObj* func_802DB558_72C758(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2710_733910);
}
