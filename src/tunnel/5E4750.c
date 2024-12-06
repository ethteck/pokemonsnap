#include "tunnel.h"

extern AnimCmd* D_80112F20[];
extern AnimCmd* D_80113740[];
extern AnimCmd* D_8010E190[];
extern AnimCmd* D_801092F0[];
extern AnimCmd* D_8010D410[];
extern AnimCmd* D_801161D0[];
extern AnimCmd* D_80111AA0[];
extern AnimCmd* D_8010CE10[];
extern AnimCmd* D_8010C370[];
extern AnimCmd* D_801189D0[];
extern AnimCmd* D_80109C10[];
extern AnimCmd* D_80117C40[];
extern AnimCmd* D_80114610[];

extern AnimCmd** D_8011A2B0[];
extern AnimCmd** D_8011A370[];
extern AnimCmd** D_80119A00[];
extern AnimCmd** D_801196C0[];
extern AnimCmd** D_80119960[];
extern AnimCmd** D_8011ADE0[];
extern AnimCmd** D_8011A1B0[];
extern AnimCmd** D_801198B0[];
extern AnimCmd** D_80119800[];
extern AnimCmd** D_8011AF80[];
extern AnimCmd** D_80119760[];
extern AnimCmd** D_8011AEE0[];
extern AnimCmd** D_8011A440[];

extern UnkEC64Arg3 D_8034DD30[];
extern Texture** D_803476A0[];

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
void func_802E8330_5E5400(GObj*);
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
void func_802E8EAC_5E5F7C(GObj*);
void func_802E8D84_5E5E54(GObj*);
void func_802E8D38_5E5E08(GObj*);
void func_802E8B1C_5E5BEC(GObj*);
void func_802E8C94_5E5D64(GObj*);
void func_802E8868_5E5938(GObj*);
void func_802E8AA4_5E5B74(GObj*);
void func_802E8990_5E5A60(GObj*);
void func_802E88EC_5E59BC(GObj*);
void func_802E86C4_5E5794(GObj*);
void func_802E85BC_5E568C(GObj*);
void func_802E8754_5E5824(GObj*);
void func_802E8398_5E5468(GObj*);
void func_802E80CC_5E519C(GObj*);
void func_802E8058_5E5128(GObj*);
void func_802E7CA4_5E4D74(GObj*);
void func_802E7C1C_5E4CEC(GObj*);
void func_802E7D04_5E4DD4(GObj*);
void func_802E7AC8_5E4B98(GObj*);

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
    D_80112F20,
    D_8011A2B0,
    NULL
};

AnimationHeader D_802EEDD0_5EBEA0 = {
    0.5,
    80,
    D_80113740,
    D_8011A370,
    D_802EED80_5EBE50
};

AnimationHeader D_802EEDE4_5EBEB4 = {
    0.3,
    63,
    D_8010E190,
    D_80119A00,
    D_802EED84_5EBE54
};

AnimationHeader D_802EEDF8_5EBEC8 = {
    0.35,
    12,
    D_801092F0,
    D_801196C0,
    NULL
};

AnimationHeader D_802EEE0C_5EBEDC = {
    0.6,
    16,
    D_8010D410,
    D_80119960,
    NULL
};

AnimationHeader D_802EEE20_5EBEF0 = {
    0.6,
    120,
    D_801161D0,
    D_8011ADE0,
    D_802EED90_5EBE60
};

AnimationHeader D_802EEE34_5EBF04 = {
    0.3,
    36,
    D_80111AA0,
    D_8011A1B0,
    D_802EED94_5EBE64
};

AnimationHeader D_802EEE48_5EBF18 = {
    0.4,
    5,
    D_8010CE10,
    D_801198B0,
    NULL
};

AnimationHeader D_802EEE5C_5EBF2C = {
    0.4,
    35,
    D_8010C370,
    D_80119800,
    NULL
};

AnimationHeader D_802EEE70_5EBF40 = {
    0.4,
    75,
    D_801189D0,
    D_8011AF80,
    D_802EED9C_5EBE6C
};

AnimationHeader D_802EEE84_5EBF54 = {
    0.6,
    64,
    D_80109C10,
    D_80119760,
    D_802EEDA4_5EBE74
};

AnimationHeader D_802EEE98_5EBF68 = {
    0.6,
    16,
    D_80117C40,
    D_8011AEE0,
    D_802EEDA8_5EBE78
};

AnimationHeader D_802EEEAC_5EBF7C = {
    0.3,
    63,
    D_80114610,
    D_8011A440,
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

    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    Pokemon_StartPathProc(obj, func_802E7AC8_5E4B98);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802E77B0_5E4880);
    }

    Pokemon_SetAnimation(obj, &D_802EEE70_5EBF40);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 17, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802E782C_5E48FC);
    }

    Pokemon_EatApple(obj);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E782C_5E48FC);
}

POKEMON_FUNC(func_802E7AC8_5E4B98)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E7B3C_5E4C0C)
    Pokemon_StartPathProc(obj, NULL);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    Pokemon_StartAuxProc(obj, func_802E7CA4_5E4D74);
    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_2000) {
        Pokemon_SetState(obj, func_802E7C1C_5E4CEC);
    }

    if (D_802EFF28_5ECFF8 != NULL && Pokemon_GetDistance(obj, D_802EFF28_5ECFF8) < 600.0f) {
        Pokemon_SetState(obj, func_802E7D04_5E4DD4);
    }

    Pokemon_SetState(obj, func_802E7C1C_5E4CEC);
}

POKEMON_FUNC(func_802E7C1C_5E4CEC)
    Pokemon_ForceAnimation(obj, &D_802EEDE4_5EBEB4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_1000);
    
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_ANIMATION_ENDED) {
        Pokemon_SetState(obj, func_802E7C1C_5E4CEC);
    }

    pokemon->apple = NULL;
    Pokemon_SetState(obj, func_802E782C_5E48FC);
}

POKEMON_FUNC(func_802E7CA4_5E4D74)
    while (Items_GetPokeFluteCmd() != 0) {
        ohWait(1);
    }
    
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E7D04_5E4DD4)
    Pokemon_StartPathProc(obj, func_802E7DDC_5E4EAC);
    Pokemon_ForceAnimation(obj, &D_802EEEAC_5EBF7C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED | POKEMON_PROCESS_FLAG_1000);
    
    if (!(pokemon->processFlags & POKEMON_PROCESS_WAIT_ENDED)) {
        Pokemon_SetState(obj, func_802E782C_5E48FC);
    }

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_41, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_ForceAnimation(obj, &D_802EEEAC_5EBF7C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_42, obj);
    Pokemon_SetState(obj, func_802E7E94_5E4F64);
}

POKEMON_FUNC(func_802E7DDC_5E4EAC)
    while (true) {
        if (D_802EFBA4_5ECC74 != NULL) {
            pokemon->interactionTarget = D_802EFBA4_5ECC74;
            Pokemon_TurnToTarget(obj, 0.1f, 0);
        }
        ohWait(1);
    }
}

POKEMON_FUNC(func_802E7E5C_5E4F2C)
    Pokemon_StartPathProc(obj, func_802E7DDC_5E4EAC);
    Pokemon_SetState(obj, func_802E7E94_5E4F64);
}

POKEMON_FUNC(func_802E7E94_5E4F64)
    InteractionHandler saved[] = {
        { POKEMON_CMD_9, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_13, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_10, func_802E789C_5E496C, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2000;
    Pokemon_ForceAnimation(obj, &D_802EEE34_5EBF04);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (!(pokemon->processFlags &POKEMON_PROCESS_FLAG_1000)) {
        Pokemon_SetState(obj, func_802E7E94_5E4F64);
    }

    Pokemon_SetState(obj, func_802E7E94_5E4F64);
}

POKEMON_FUNC(func_802E7F64_5E5034)
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.6f) {
            break;
        }
        ohWait(1);
    }

    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E8008_5E50D8)
    Pokemon_StartAuxProc(obj, func_802E7F64_5E5034);
    D_802EEEC0_5EBF90 = obj;
    pokemon->miscVars[0].field1 = 0;
    Pokemon_SetState(obj, func_802E8058_5E5128);
}

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

POKEMON_FUNC(func_802E8058_5E5128)
    Pokemon_ForceAnimation(obj, &D_802EEDD0_5EBEA0);
    Pokemon_StartPathProc(obj, func_802E80CC_5E519C);
    pokemon->transitionGraph = D_802EF0A0_5EC170;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E8058_5E5128);
}

POKEMON_FUNC(func_802E80CC_5E519C)
    if (D_802EEEC4_5EBF94 != NULL) {
        Pokemon_TurnToModelNode(obj, D_802EEEC4_5EBF94->data.dobj->firstChild->next->next->next->next->next->next,
                                0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED);
    } else if (D_802EEEC8_5EBF98 != NULL) {
        Pokemon_TurnToModelNode(obj, D_802EEEC8_5EBF98->data.dobj->firstChild->next->next->next->next->next,
                                0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E818C_5E525C)
    if (D_802EEEC4_5EBF94 != NULL) {
        if (Pokemon_GetDistance(obj, D_802EEEC4_5EBF94) < 200.0f) {
            Pokemon_SetAnimation(obj, &D_802EEE5C_5EBF2C);
        }
    } else if (D_802EEEC8_5EBF98 != NULL) {
        if (Pokemon_GetDistance(obj, D_802EEEC8_5EBF98) < 200.0f) {
            Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
        }
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E823C_5E530C)
    Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E8058_5E5128);
}

POKEMON_FUNC(func_802E8290_5E5360)
    if (!(D_802EEED0_5EBFA0 & D_802EEED4_5EBFA4)) {
        Pokemon_SetState(obj, func_802E8058_5E5128);
    }

    D_802EEED4_5EBFA4 *= 2;
    if (pokemon->miscVars[0].field1 < 3) {
        pokemon->miscVars[1].field1 = pokemon->miscVars[0].field1 + 1;
    } else {
        pokemon->miscVars[1].field1 = pokemon->miscVars[0].field1 + 2;
    }

    Pokemon_StartPathProc(obj, func_802E8398_5E5468);
    Pokemon_SetState(obj, func_802E8330_5E5400);
}

InteractionHandler D_802EF150_5EC220[] = {
    { POKEMON_CMD_9, func_802E8428_5E54F8, 0, NULL },
    { POKEMON_CMD_13, func_802E8428_5E54F8, 0, NULL },
    { POKEMON_CMD_10, func_802E8428_5E54F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(func_802E8330_5E5400)
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    pokemon->transitionGraph = D_802EF150_5EC220;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->miscVars[0].field1 = pokemon->miscVars[1].field1;
    Pokemon_SetState(obj, func_802E8058_5E5128);
}

POKEMON_FUNC(func_802E8398_5E5468)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, pokemon->path->paramPoints[pokemon->miscVars[0].field1],
                            pokemon->path->paramPoints[pokemon->miscVars[1].field1],
                            0.1f, 0.0f, MOVEMENT_FLAG_ON_GROUND | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E8428_5E54F8)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802E8330_5E5400);
}

POKEMON_FUNC(func_802E849C_5E556C)
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex >= 2 || blockIndex == 1 && blockPart >= 0.0f) {
            break;
        }
        ohWait(1);
    }

    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E853C_5E560C)
    while (D_802EE8AC_5EB97C == NULL) {
        ohWait(1);
    }

    D_802EEECC_5EBF9C = obj;
    Pokemon_StartAuxProc(obj, func_802E849C_5E556C);
    pokemon->miscVars[0].field1 = 0;
    Pokemon_SetState(obj, func_802E85BC_5E568C);
}

InteractionHandler D_802EF190_5EC260[] = {
    { POKEMON_CMD_24, func_802E867C_5E574C, 0, NULL },
    { POKEMON_CMD_10, func_802E8628_5E56F8, 0, NULL },
    { POKEMON_CMD_9, func_802E8628_5E56F8, 0, NULL },
    { POKEMON_CMD_13, func_802E8628_5E56F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(func_802E85BC_5E568C)
    Pokemon_SetAnimation(obj, &D_802EEDBC_5EBE8C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EF190_5EC260;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E8628_5E56F8)
    Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E85BC_5E568C);
}

POKEMON_FUNC(func_802E867C_5E574C)
    pokemon->miscVars[1].field1 = pokemon->miscVars[0].field1 + 1;
    Pokemon_StartPathProc(obj, func_802E8754_5E5824);
    Pokemon_SetState(obj, func_802E86C4_5E5794);
}

InteractionHandler D_802EF1E0_5EC2B0[] = {
    { POKEMON_CMD_10, func_802E87F4_5E58C4, 0, NULL },
    { POKEMON_CMD_9, func_802E87F4_5E58C4, 0, NULL },
    { POKEMON_CMD_13, func_802E87F4_5E58C4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(func_802E86C4_5E5794)
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    pokemon->transitionGraph = D_802EF1E0_5EC2B0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->miscVars[1].field1 + 2 == pokemon->path->numPoints) {
        Pokemon_SetState(obj, func_802E8868_5E5938);
    }

    pokemon->miscVars[0].field1 = pokemon->miscVars[1].field1;
    Pokemon_SetState(obj, func_802E85BC_5E568C);
}

POKEMON_FUNC(func_802E8754_5E5824)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, pokemon->path->paramPoints[pokemon->miscVars[0].field1],
                            pokemon->path->paramPoints[pokemon->miscVars[1].field1],
                            0.1f, 0.0f, MOVEMENT_FLAG_ON_GROUND | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E87F4_5E58C4)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802E86C4_5E5794);
}

InteractionHandler D_802EF220_5EC2F0[] = {
    { POKEMON_CMD_10, func_802E8A24_5E5AF4, 0, NULL },
    { POKEMON_CMD_9, func_802E8A24_5E5AF4, 0, NULL },
    { POKEMON_CMD_13, func_802E8A24_5E5AF4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(func_802E8868_5E5938)
    Pokemon_SetAnimation(obj, &D_802EEDBC_5EBE8C);
    Pokemon_StartPathProc(obj, func_802E88EC_5E59BC);
    Pokemon_StartAuxProc(obj, func_802E8990_5E5A60);
    pokemon->transitionGraph = D_802EF220_5EC2F0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E8AA4_5E5B74);
}

POKEMON_FUNC(func_802E88EC_5E59BC)
    while (Pokemon_GetDistance(obj, D_802EE8AC_5EB97C) > 200.0f) {
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E8990_5E5A60)
    while (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        pokemon->interactionTarget = D_802EE8AC_5EB97C;
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E8A24_5E5AF4)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_SetAnimation(obj, &D_802EEE20_5EBEF0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->flags &= ~POKEMON_FLAG_800;
    Pokemon_SetState(obj, func_802E8868_5E5938);
}

InteractionHandler D_802EF260_5EC330[] = {
    { TUNNEL_CMD_40, func_802E8E34_5E5F04, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EF280_5EC350[] = {
    { TUNNEL_CMD_37, func_802E91A8_5E6278, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

f32 D_802EF2A0_5EC370[] =  { 0 };

POKEMON_FUNC(func_802E8AA4_5E5B74)
    pokemon->forbiddenGround = D_802EF2A0_5EC370;
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    Pokemon_StartPathProc(obj, func_802E8B1C_5E5BEC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E8C94_5E5D64);
}

POKEMON_FUNC(func_802E8B1C_5E5BEC)
    Mtx3Float* anotherPos = &GET_TRANSFORM(D_802EE8AC_5EB97C->data.dobj)->pos;
    f32 f0;

    do {
        ohWait(1);
        f0 = anotherPos->v.y + 150.0f - position->v.y;
        if (ABS(f0) < 30.0f) {
            position->v.y = anotherPos->v.y + 150.0f;
        } else if (f0 > 0) {
            position->v.y += 30.0f;
        } else {
            position->v.y -= 30.0f;
        }
        pokemon->hSpeed = 320.0f;
        Pokemon_SetTargetPos(obj, anotherPos->v.x, anotherPos->v.z);
    } while (Pokemon_StepToTargetPos(obj, 0.1f, 0) == 0);
    
    position->v.x = anotherPos->v.x;
    position->v.z = anotherPos->v.z;
    position->v.y = anotherPos->v.y + 150.0f; 

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E8C94_5E5D64)
    EnvSound_PlaySound(obj, 0, SOUND_ID_265);
    pokemon->specialPoseID = 2;
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4000;
    Pokemon_StartAuxProc(obj, func_802E8D84_5E5E54);
    Pokemon_StartPathProc(obj, func_802E8D38_5E5E08);
    pokemon->transitionGraph = D_802EF260_5EC330;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E8D38_5E5E08)
    Pokemon_TurnToTarget(obj, 0.2f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E8D84_5E5E54)
    Mtx3Float* anotherPos = &GET_TRANSFORM(D_802EE8AC_5EB97C->data.dobj)->pos;

    while (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_4000)) {
        position->v.x = anotherPos->v.x;
        position->v.z = anotherPos->v.z;
        position->v.y = anotherPos->v.y + 150.0f;        
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E8E34_5E5F04)
    Pokemon_SetAnimation(obj, &D_802EEE5C_5EBF2C);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_4000;
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E8EAC_5E5F7C);
}

POKEMON_FUNC(func_802E8EAC_5E5F7C)
    pokemon->specialPoseID = 0;
    Pokemon_SetAnimation(obj, &D_802EEE0C_5EBEDC);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_4000;
    Pokemon_StartPathProc(obj, func_802E8F44_5E6014);
    Pokemon_StartAuxProc(obj, func_802E9098_5E6168);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);

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
    D_8034DD30,
    D_803476A0,
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
