#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern UnkEC64Arg3 D_80346B30[];
extern Texture** D_80341BD0[];

extern AnimCmd* D_80191B20[];
extern AnimCmd* D_80190AC0[];
extern AnimCmd* D_80191260[];
extern AnimCmd* D_801935B0[];
extern AnimCmd* D_80193CD0[];
extern AnimCmd* D_80191F40[];
extern AnimCmd* D_80192340[];
extern AnimCmd* D_801950B0[];

extern AnimCmd** D_801965B0[];
extern AnimCmd** D_80196830[];
extern AnimCmd** D_801968D0[];
extern AnimCmd** D_801966D0[];
extern AnimCmd** D_80196770[];
extern AnimCmd** D_80196960[];

void func_802DA3A0_72B5A0(GObj*);
void func_802D9F24_72B124(GObj*);
void func_802DA97C_72BB7C(GObj*);
void func_802DAA34_72BC34(GObj*);
void func_802DA000_72B200(GObj*);
void func_802DA100_72B300(GObj*);
void func_802DA200_72B400(GObj*);
void func_802DA2C8_72B4C8(GObj*);
void func_802DA7A4_72B9A4(GObj*);
void func_802DA5B4_72B7B4(GObj*);
void func_802DA68C_72B88C(GObj*);
void func_802DA330_72B530(GObj*);
void func_802D9F90_72B190(GObj*);

s32 D_802E1FF0_7331F0[] = { 0x123 };
s32 D_802E1FF4_7331F4[] = { 0x124 };

AnimationHeader D_802E1FF8_7331F8 = {
    0.4,
    40,
    D_80191B20,
    D_801965B0,
    NULL
};

AnimationHeader D_802E200C_73320C = {
    0.8,
    40,
    D_80190AC0,
    NULL,
    NULL
};

AnimationHeader D_802E2020_733220 = {
    1.2,
    37,
    D_80191260,
    NULL,
    NULL
};

AnimationHeader D_802E2034_733234 = {
    0.5,
    15,
    D_801935B0,
    D_80196830,
    NULL
};

AnimationHeader D_802E2048_733248 = {
    0.7,
    52,
    D_80193CD0,
    D_801968D0,
    D_802E1FF0_7331F0
};

AnimationHeader D_802E205C_73325C = {
    0.5,
    10,
    D_80191F40,
    D_801966D0,
    NULL
};

AnimationHeader D_802E2070_733270 = {
    0.35,
    45,
    D_80192340,
    D_80196770,
    NULL
};

AnimationHeader D_802E2084_733284 = {
    0.5,
    54,
    D_801950B0,
    D_80196960,
    D_802E1FF4_7331F4
};

InteractionHandler D_802E2098_733298[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { POKEMON_CMD_15, func_802DA5B4_72B7B4, 0, NULL },
    { POKEMON_CMD_16, func_802DA68C_72B88C, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_44, func_802DA7A4_72B9A4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2118_733318[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { POKEMON_CMD_44, func_802DA7A4_72B9A4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2178_733378[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { POKEMON_CMD_16, func_802DA68C_72B88C, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E21D8_7333D8[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2208_733408[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2238_733438[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_15, func_802DA5B4_72B7B4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2278_733478[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { POKEMON_CMD_44, func_802DA7A4_72B9A4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E22D8_7334D8[] = {
    { 100, func_802D9F90_72B190 },
    { 100, func_802DA000_72B200 },
    { 100, func_802DA100_72B300 },
    { 0, NULL },
};

Vec3f D_802E22F8_7334F8 = { 0, 0, 0 };

InteractionHandler D_802E2304_733504[] = {
    { POKEMON_CMD_9, func_802DA97C_72BB7C, 0, NULL },
    { POKEMON_CMD_13, func_802DAA34_72BC34, 0, NULL },
    { POKEMON_CMD_10, func_802DAA34_72BC34, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E2344_733544 = {
    &D_802E1FF8_7331F8,
    func_802D9F24_72B124,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2358_733558 = {
    D_80346B30,
    D_80341BD0,
    renderPokemonModelTypeIFogged,
    &D_802E2344_733544,
    { 1.7, 1.7, 1.7 },
    { 0, 60, 0 },
    30,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9D00_72AF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9DFC_72AFFC.s")

void func_802D9E7C_72B07C(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (true) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 4 || (sp34 == 4 && sp30 >= 0.1)) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(arg0);
    Pokemon_StopAuxProc(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9F24_72B124.s")

void func_802D9F90_72B190(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1FF8_7331F8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2098_733298;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E22D8_7334D8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA000_72B200.s")

void func_802DA0A4_72B2A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA100_72B300.s")

void func_802DA1A4_72B3A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA200_72B400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA2C8_72B4C8.s")

void func_802DA330_72B530(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2034_733234);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E21D8_7333D8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D9F90_72B190);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA3A0_72B5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA428_72B628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA4AC_72B6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA55C_72B75C.s")

void func_802DA5B4_72B7B4(GObj* arg0) {
    Pokemon_SetState(arg0, func_802DA3A0_72B5A0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA5D8_72B7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA640_72B840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA68C_72B88C.s")

void func_802DA748_72B948(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA7A4_72B9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA848_72BA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA8A4_72BAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA930_72BB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA97C_72BB7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DAA34_72BC34.s")

GObj* func_802DAA9C_72BC9C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2358_733558);
}
