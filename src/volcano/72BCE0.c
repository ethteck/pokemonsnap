#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern UnkEC64Arg3 D_80336188[];
extern Texture** D_80330A10[];

extern AnimCmd* D_80168F70[];
extern AnimCmd* D_8016A970[];
extern AnimCmd* D_801645E0[];
extern AnimCmd* D_80168280[];
extern AnimCmd* D_8016BCD0[];
extern AnimCmd* D_8016E950[];
extern AnimCmd* D_80164F50[];
extern AnimCmd* D_8016DCF0[];

extern AnimCmd** D_80171980[];
extern AnimCmd** D_80171A20[];
extern AnimCmd** D_801717A0[];
extern AnimCmd** D_80171BD0[];
extern AnimCmd** D_801718F0[];
extern AnimCmd** D_80171A90[];
extern AnimCmd** D_80171830[];
extern AnimCmd** D_80171B30[];

void func_802DB0B8_72C2B8(GObj*);
void func_802DB2F8_72C4F8(GObj*);
void func_802DAAE0_72BCE0(GObj*);
void func_802DACA8_72BEA8(GObj*);
void func_802DADA8_72BFA8(GObj*);
void func_802DAFF8_72C1F8(GObj*);
void func_802DB2D4_72C4D4(GObj*);
void func_802DB358_72C558(GObj*);
void func_802DAF18_72C118(GObj*);
void func_802DAF88_72C188(GObj*);
void func_802DAC38_72BE38(GObj*);
void func_802DAEA8_72C0A8(GObj*);
void func_802DB418_72C618(GObj*);
void func_802DB4E8_72C6E8(GObj*);

s32 D_802E2390_733590[] = { 0x113 };
s32 D_802E2394_733594[] = { 0x114 };
s32 D_802E2398_733598[] = { 0x112 };
s32 D_802E239C_73359C[] = { 0x115, 0x75 };

AnimationHeader D_802E23A4_7335A4 = {
    0.6,
    140,
    D_80168F70,
    D_80171980,
    NULL
};

AnimationHeader D_802E23B8_7335B8 = {
    0.5,
    36,
    D_8016A970,
    D_80171A20,
    D_802E2390_733590
};

AnimationHeader D_802E23CC_7335CC = {
    0.5,
    24,
    D_801645E0,
    D_801717A0,
    NULL
};

AnimationHeader D_802E23E0_7335E0 = {
    1.0,
    40,
    D_80168280,
    D_801718F0,
    NULL
};

AnimationHeader D_802E23F4_7335F4 = {
    0.4,
    90,
    D_8016BCD0,
    D_80171A90,
    D_802E2394_733594
};

AnimationHeader D_802E2408_733608 = {
    0.5,
    120,
    D_8016E950,
    D_80171BD0,
    D_802E2398_733598
};

AnimationHeader D_802E241C_73361C = {
    0.7,
    90,
    D_80164F50,
    D_80171830,
    NULL
};

AnimationHeader D_802E2430_733630 = {
    0.7,
    55,
    D_8016DCF0,
    D_80171B30,
    D_802E239C_73359C
};

InteractionHandler D_802E2444_733644[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_10, func_802DAFF8_72C1F8, 0, NULL },
    { POKEMON_CMD_14, func_802DB0B8_72C2B8, 0, NULL },
    { POKEMON_CMD_15, func_802DB2D4_72C4D4, 0, NULL },
    { POKEMON_CMD_5, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_6, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_7, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_16, func_802DB418_72C618, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_23, func_802DB4E8_72C6E8, 60, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E24F4_7336F4[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_10, func_802DAFF8_72C1F8, 0, NULL },
    { POKEMON_CMD_14, func_802DB0B8_72C2B8, 0, NULL },
    { POKEMON_CMD_5, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_6, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_7, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2574_733774[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_10, func_802DAFF8_72C1F8, 0, NULL },
    { POKEMON_CMD_14, func_802DB0B8_72C2B8, 0, NULL },
    { POKEMON_CMD_5, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_6, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_7, func_802DB358_72C558, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E25F4_7337F4[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2624_733824[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2654_733854[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_15, func_802DB2D4_72C4D4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2694_733894[] = {
    { POKEMON_CMD_9, func_802DAF18_72C118, 0, NULL },
    { POKEMON_CMD_13, func_802DAF88_72C188, 0, NULL },
    { POKEMON_CMD_10, func_802DAFF8_72C1F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E26D4_7338D4[] = {
    { 100, func_802DAC38_72BE38 },
    { 100, func_802DACA8_72BEA8 },
    { 100, func_802DADA8_72BFA8 },
    { 100, func_802DAEA8_72C0A8 },
    { 0, NULL },
};

PokemonAnimationSetup D_802E26FC_7338FC = {
    &D_802E23A4_7335A4,
    func_802DAAE0_72BCE0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2710_733910 = {
    D_80336188,
    D_80330A10,
    renderPokemonModelTypeIFogged,
    &D_802E26FC_7338FC,
    { 2.2, 2.2, 2.2 },
    { 0, 127, 4 },
    37,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

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

GObj* func_802DB558_72C758(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2710_733910);
}
