#include "tunnel.h"

void func_802E796C_5E4A3C(GObj*);
void func_802E7DDC_5E4EAC(GObj*);
void func_802E7E94_5E4F64(GObj*);
void func_802E7718_5E47E8(GObj*);
void func_802E8008_5E50D8(GObj*);
void func_802E853C_5E560C(GObj*);
void func_802E789C_5E496C(GObj*);
void func_802E7B3C_5E4C0C(GObj*);
void func_802E8290_5E5360(GObj*);
void func_802E818C_5E525C(GObj*);
void func_802E823C_5E530C(GObj*);
void func_802E8428_5E54F8(GObj*);
void func_802E867C_5E574C(GObj*);
void func_802E8628_5E56F8(GObj*);
void func_802E87F4_5E58C4(GObj*);
void func_802E8A24_5E5AF4(GObj*);
void func_802E8E34_5E5F04(GObj*);
void func_802E91A8_5E6278(GObj*);
void func_802E7680_5E4750(GObj*);
void func_802E77B0_5E4880(GObj*);
void func_802E782C_5E48FC(GObj*);
void func_802E7948_5E4A18(GObj*);
void func_802E7E5C_5E4F2C(GObj*);
void func_802E9288_5E6358(GObj*);
void func_802E91FC_5E62CC(GObj*);
void func_802E9150_5E6220(GObj*);
void func_802E8F44_5E6014(GObj*);
void func_802E90DC_5E61AC(GObj*);
void func_802E9098_5E6168(GObj*);

s32 D_802EED80_5EBE50[] = { SOUND_ID_266 };
s32 D_802EED84_5EBE54[] = { SOUND_ID_264, SOUND_ID_127, SOUND_ID_360 };
s32 D_802EED90_5EBE60[] = { SOUND_ID_263 };
s32 D_802EED94_5EBE64[] = { SOUND_ID_265, SOUND_ID_371 };
s32 D_802EED9C_5EBE6C[] = { SOUND_ID_267, SOUND_ID_268 };
s32 D_802EEDA4_5EBE74[] = { SOUND_ID_354 };
s32 D_802EEDA8_5EBE78[] = { 0, SOUND_ID_138 };
s32 D_802EEDB0_5EBE80[] = { SOUND_ID_264, SOUND_ID_127, SOUND_ID_360 };

AnimationHeader D_802EEDBC_5EBE8C = {
    0.43,
    40,
    0x80112F20,
    0x8011A2B0,
    NULL
};

AnimationHeader D_802EEDD0_5EBEA0 = {
    0.5,
    80,
    0x80113740,
    0x8011A370,
    D_802EED80_5EBE50
};

AnimationHeader D_802EEDE4_5EBEB4 = {
    0.3,
    63,
    0x8010E190,
    0x80119A00,
    D_802EED84_5EBE54
};

AnimationHeader D_802EEDF8_5EBEC8 = {
    0.35,
    12,
    0x801092F0,
    0x801196C0,
    NULL
};

AnimationHeader D_802EEE0C_5EBEDC = {
    0.6,
    16,
    0x8010D410,
    0x80119960,
    NULL
};

AnimationHeader D_802EEE20_5EBEF0 = {
    0.6,
    120,
    0x801161D0,
    0x8011ADE0,
    D_802EED90_5EBE60
};

AnimationHeader D_802EEE34_5EBF04 = {
    0.3,
    36,
    0x80111AA0,
    0x8011A1B0,
    D_802EED94_5EBE64
};

AnimationHeader D_802EEE48_5EBF18 = {
    0.4,
    5,
    0x8010CE10,
    0x801198B0,
    NULL
};

AnimationHeader D_802EEE5C_5EBF2C = {
    0.4,
    35,
    0x8010C370,
    0x80119800,
    NULL
};

AnimationHeader D_802EEE70_5EBF40 = {
    0.4,
    75,
    0x801189D0,
    0x8011AF80,
    D_802EED9C_5EBE6C
};

AnimationHeader D_802EEE84_5EBF54 = {
    0.6,
    64,
    0x80109C10,
    0x80119760,
    D_802EEDA4_5EBE74
};

AnimationHeader D_802EEE98_5EBF68 = {
    0.6,
    16,
    0x80117C40,
    0x8011AEE0,
    D_802EEDA8_5EBE78
};

AnimationHeader D_802EEEAC_5EBF7C = {
    0.3,
    63,
    0x80114610,
    0x8011A440,
    D_802EEDB0_5EBE80
};

GObj* D_802EEEC0_5EBF90 = NULL;
GObj* D_802EEEC4_5EBF94 = NULL;
GObj* D_802EEEC8_5EBF98 = NULL;
GObj* D_802EEECC_5EBF9C = NULL;
s32 D_802EEED0_5EBFA0 = 0;
s32 D_802EEED4_5EBFA4 = 1;

InteractionHandler D_802EEED8_5EBFA8[] = {
    { POKEMON_CMD_15, func_802E7948_5E4A18, 0, NULL },
    { POKEMON_CMD_14, func_802E796C_5E4A3C, 0, NULL },
    { POKEMON_CMD_9, func_802E789C_5E496C, 0, NULL },
    { POKEMON_CMD_13, func_802E789C_5E496C, 0, NULL },
    { POKEMON_CMD_10, func_802E789C_5E496C, 0, NULL },
    { POKEMON_CMD_5, func_802E7B3C_5E4C0C, 0, NULL },
    { POKEMON_CMD_6, func_802E7B3C_5E4C0C, 0, NULL },
    { POKEMON_CMD_7, func_802E7B3C_5E4C0C, 0, NULL },
    { TUNNEL_CMD_42, func_802E7E5C_5E4F2C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802EEF78_5EC048[] = {
    { 1, func_802E77B0_5E4880 },
    { 1, func_802E782C_5E48FC },
    { 0, NULL },
};

POKEMON_FUNC(func_802E7680_5E4750)
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_802E7718_5E47E8);
    }
    if (pokemon->behavior == 6) {
        Pokemon_SetState(obj, func_802E8008_5E50D8);
    }
    if (pokemon->behavior == 7) {
        Pokemon_SetState(obj, func_802E853C_5E560C);
    }
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E7718_5E47E8)
    InteractionHandler saved[] = {
        { TUNNEL_CMD_50, func_802E77B0_5E4880, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, func_802E77B0_5E4880);
}

POKEMON_FUNC(func_802E789C_5E496C)
    InteractionHandler saved[] = {
        { POKEMON_CMD_9, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_13, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    Pokemon_ForceAnimation(obj, &D_802EEE20_5EBEF0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->apple = NULL;
    Pokemon_SetState(obj, func_802E782C_5E48FC);
}

POKEMON_FUNC(func_802E77B0_5E4880)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_802EEDBC_5EBE8C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EEED8_5EBFA8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802EEF78_5EC048);
}

POKEMON_FUNC(func_802E782C_5E48FC)
    Pokemon_ForceAnimation(obj, &D_802EEDD0_5EBEA0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EEED8_5EBFA8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802EEF78_5EC048);
}

POKEMON_FUNC(func_802E7948_5E4A18)
    Pokemon_SetState(obj, func_802E796C_5E4A3C);
}

POKEMON_FUNC(func_802E796C_5E4A3C)
    InteractionHandler saved[] = {
        { POKEMON_CMD_14, func_802E796C_5E4A3C, 0, NULL },
        { POKEMON_CMD_9, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_13, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_10, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_5, func_802E7B3C_5E4C0C, 0, NULL },
        { POKEMON_CMD_6, func_802E7B3C_5E4C0C, 0, NULL },
        { POKEMON_CMD_7, func_802E7B3C_5E4C0C, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    Pokemon_ForceAnimation(obj, &D_802EEDD0_5EBEA0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802EEF78_5EC048);
}

InteractionHandler D_802EF060_5EC130[] = {
    { POKEMON_CMD_9, func_802E789C_5E496C, 0, NULL },
    { POKEMON_CMD_13, func_802E789C_5E496C, 0, NULL },
    { POKEMON_CMD_10, func_802E789C_5E496C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF0A0_5EC170[] = {
    { TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, func_802E8290_5E5360, 0, NULL },
    { TUNNEL_CMD_SECOND_DIGLETT_SHOW_UP, func_802E8290_5E5360, 0, NULL },
    { TUNNEL_CMD_THIRD_DIGLETT_SHOW_UP, func_802E8290_5E5360, 0, NULL },
    { TUNNEL_CMD_FIRST_DUGTRIO_SHOW_UP, func_802E8290_5E5360, 0, NULL },
    { TUNNEL_CMD_SECOND_DUGTRIO_SHOW_UP, func_802E8290_5E5360, 0, NULL },
    { TUNNEL_CMD_THIRD_DUGTRIO_SHOW_UP, func_802E8290_5E5360, 0, NULL },
    { TUNNEL_CMD_43, NULL, 0, func_802E818C_5E525C },
    { POKEMON_CMD_9, func_802E823C_5E530C, 0, NULL },
    { POKEMON_CMD_13, func_802E823C_5E530C, 0, NULL },
    { POKEMON_CMD_10, func_802E823C_5E530C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF150_5EC220[] = {
    { POKEMON_CMD_9, func_802E8428_5E54F8, 0, NULL },
    { POKEMON_CMD_13, func_802E8428_5E54F8, 0, NULL },
    { POKEMON_CMD_10, func_802E8428_5E54F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF190_5EC260[] = {
    { POKEMON_CMD_24, func_802E867C_5E574C, 0, NULL },
    { POKEMON_CMD_10, func_802E8628_5E56F8, 0, NULL },
    { POKEMON_CMD_9, func_802E8628_5E56F8, 0, NULL },
    { POKEMON_CMD_13, func_802E8628_5E56F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF1E0_5EC2B0[] = {
    { POKEMON_CMD_10, func_802E87F4_5E58C4, 0, NULL },
    { POKEMON_CMD_9, func_802E87F4_5E58C4, 0, NULL },
    { POKEMON_CMD_13, func_802E87F4_5E58C4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF220_5EC2F0[] = {
    { POKEMON_CMD_10, func_802E8A24_5E5AF4, 0, NULL },
    { POKEMON_CMD_9, func_802E8A24_5E5AF4, 0, NULL },
    { POKEMON_CMD_13, func_802E8A24_5E5AF4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF260_5EC330[] = {
    { TUNNEL_CMD_40, func_802E8E34_5E5F04, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF280_5EC350[] = {
    { TUNNEL_CMD_37, func_802E91A8_5E6278, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

s32 D_802EF2A0_5EC370 = 0;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7AC8_5E4B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7B3C_5E4C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7C1C_5E4CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7CA4_5E4D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7D04_5E4DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7DDC_5E4EAC.s")

void func_802E7E5C_5E4F2C(GObj* arg0) {
    Pokemon_StartPathProc(arg0, func_802E7DDC_5E4EAC);
    Pokemon_SetState(arg0, func_802E7E94_5E4F64);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7E94_5E4F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7F64_5E5034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8008_5E50D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8058_5E5128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E80CC_5E519C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E818C_5E525C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E823C_5E530C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8290_5E5360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8330_5E5400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8398_5E5468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8428_5E54F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E849C_5E556C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E853C_5E560C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E85BC_5E568C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8628_5E56F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E867C_5E574C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E86C4_5E5794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8754_5E5824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E87F4_5E58C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8868_5E5938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E88EC_5E59BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8990_5E5A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8A24_5E5AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8AA4_5E5B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8B1C_5E5BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8C94_5E5D64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8D38_5E5E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8D84_5E5E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8E34_5E5F04.s")

POKEMON_FUNC(func_802E8EAC_5E5F7C)
    pokemon->specialPoseID = 0;
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
    Pokemon_StartPathProc(obj, func_802E8F44_5E6014);
    Pokemon_StartAuxProc(obj, func_802E9098_5E6168);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEDBC_5EBE8C);

    Pokemon_SetState(obj, func_802E90DC_5E61AC);
}

POKEMON_FUNC(func_802E8F44_5E6014)
    Vec3f endPos = { 0, 0, 0 };
    f32 x,z;
    WorldBlock* block;

    block = getCurrentWorldBlock();
    x  = - (block->descriptor->worldPos.x * 100.0f);
    z  = - (block->descriptor->worldPos.z * 100.0f);
    GetInterpolatedPosition(&endPos, pokemon->path, 0.99999f);
    x += endPos.x * 100.0f;
    z += endPos.z * 100.0f;
    pokemon->hSpeed = 320.0f;
    Pokemon_SetTargetPos(obj, x, z);
    while (Pokemon_StepToTargetPos(obj, 6.2831855f, 0) == 0) {
        ohWait(1);
    }

    position->v.x = x;
    position->v.z = z;

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E9098_5E6168)
    pokemon->jumpVel = 10.0f;
    Pokemon_FallDownOnGround(obj, -9.8f, 0);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E90DC_5E61AC)
    Pokemon_ForceAnimation(obj, &D_802EEDD0_5EBEA0);
    Pokemon_StartPathProc(obj, func_802E9150_5E6220);
    pokemon->transitionGraph = D_802EF280_5EC350;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E90DC_5E61AC);
}

POKEMON_FUNC(func_802E9150_5E6220)
    pokemon->interactionTarget = D_802EE8AC_5EB97C;
    Pokemon_TurnToTarget(obj, 0.1f, 0);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E91A8_5E6278)
    Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E91FC_5E62CC);
}

POKEMON_FUNC(func_802E91FC_5E62CC)
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    Pokemon_StartPathProc(obj, func_802E9288_5E6358);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEDBC_5EBE8C);
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E9288_5E6358)
    Vec3f endPos = { 0, 0, 0 };
    GroundResult sp38;
    Vec3f sp2C;
    WorldBlock* block;

    block = getCurrentWorldBlock();
    sp2C.x  = - (block->descriptor->worldPos.x * 100.0f);
    sp2C.z  = - (block->descriptor->worldPos.z * 100.0f);
    GetInterpolatedPosition(&endPos, pokemon->path, 0);
    sp2C.x += endPos.x * 100.0f;
    sp2C.z += endPos.z * 100.0f;
    getGroundAt(sp2C.x, sp2C.z, &sp38);
    Pokemon_SetTargetPos(obj, sp2C.x, sp2C.z);
    Pokemon_RunToTargetPos(obj, 0.2f);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

PokemonAnimationSetup D_802EF2BC_5EC38C = {
    &D_802EEDBC_5EBE8C,
    func_802E7680_5E4750,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802EF2D0_5EC3A0 = {
    0x8034DD30,
    0x803476A0,
    renderPokemonModelTypeJFogged,
    &D_802EF2BC_5EC38C,
    { 2, 2, 2 },
    { 0, 76, 0 },
    22,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

GObj* func_802E9390_5E6460(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EF2D0_5EC3A0);
}
