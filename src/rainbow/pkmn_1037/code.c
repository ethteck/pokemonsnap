#include "../rainbow.h"
#include "app_render/effect.h"

void func_80349E28_829598(GObj*);
void func_803491D4_828944(GObj*);
void func_8034930C_828A7C(GObj*);
void func_803493F4_828B64(GObj*);
void func_80349714_828E84(GObj*);
void func_80349814_828F84(GObj*);
void func_80349B34_8292A4(GObj*);
void func_80349D40_8294B0(GObj*);
void func_80349C18_829388(GObj*);

extern s32 D_8034AE48_82A5B8;
extern s32 D_8034AE4C_82A5BC;
extern f32 D_8034B700_82AE70;

extern s32 D_80350190_82F900;

extern UnkEC64Arg3 D_80116EF0_4C92C0[];
extern Texture** D_80116CF0_4C90C0[];

extern AnimCmd* D_80117210_4C95E0[];
extern AnimCmd* D_80117310_4C96E0[];
extern AnimCmd* D_80117410_4C97E0[];
extern AnimCmd* D_80117570_4C9940[];
extern AnimCmd* D_801176D0_4C9AA0[];
extern AnimCmd* D_80117840_4C9C10[];
extern AnimCmd* D_80117980_4C9D50[];
extern AnimCmd* D_80117A50_4C9E20[];
extern AnimCmd* D_80117B20_4C9EF0[];
extern AnimCmd* D_80117C70_4CA040[];
extern AnimCmd* D_80117DC0_4CA190[];
extern AnimCmd* D_80117F10_4CA2E0[];

extern AnimCmd** D_80117260_4C9630[];
extern AnimCmd** D_80117360_4C9730[];
extern AnimCmd** D_80117480_4C9850[];
extern AnimCmd** D_801175E0_4C99B0[];
extern AnimCmd** D_80117730_4C9B00[];
extern AnimCmd** D_801178A0_4C9C70[];
extern AnimCmd** D_801179C0_4C9D90[];
extern AnimCmd** D_80117A90_4C9E60[];
extern AnimCmd** D_80117B60_4C9F30[];
extern AnimCmd** D_80117CB0_4CA080[];
extern AnimCmd** D_80117DF0_4CA1C0[];
extern AnimCmd** D_80117F40_4CA310[];

extern AnimCmd* D_8012C9E0_4DEDB0[];
extern AnimCmd* D_8012D700_4DFAD0[];
extern AnimCmd* D_8012EFF0_4E13C0[];
extern AnimCmd* D_8012FB60_4E1F30[];
extern AnimCmd* D_80131D30_4E4100[];
extern AnimCmd* D_80133040_4E5410[];
extern AnimCmd* D_801358A0_4E7C70[];
extern AnimCmd* D_801368F0_4E8CC0[];
extern AnimCmd** D_801394D0_4EB8A0[];
extern AnimCmd** D_801395A0_4EB970[];
extern AnimCmd** D_80139690_4EBA60[];
extern AnimCmd** D_80139770_4EBB40[];
extern AnimCmd** D_80139840_4EBC10[];
extern AnimCmd** D_80139900_4EBCD0[];
extern AnimCmd** D_80139A00_4EBDD0[];
extern AnimCmd** D_80139B00_4EBED0[];

// copy of the mew animations
s32 D_8034AFC0_82A730[] = { SOUND_ID_349 };
s32 D_8034AFC4_82A734[] = { SOUND_ID_351 };
s32 D_8034AFC8_82A738[] = { SOUND_ID_350, SOUND_ID_147 };
s32 D_8034AFD0_82A740[] = { SOUND_ID_349 };
s32 D_8034AFD4_82A744[] = { SOUND_ID_351 };
s32 D_8034AFD8_82A748[] = { SOUND_ID_352, SOUND_ID_145 };

AnimationHeader D_8034AFE0_82A750 = {
    0.5f,
    70.0f,
    D_8012EFF0_4E13C0,
    D_80139690_4EBA60,
    NULL
};

AnimationHeader D_8034AFF4_82A764 = {
    0.65f,
    135.0f,
    D_801368F0_4E8CC0,
    D_80139B00_4EBED0,
    D_8034AFC0_82A730
};

AnimationHeader D_8034B008_82A778 = {
    0.8f,
    140.0f,
    D_801358A0_4E7C70,
    D_80139A00_4EBDD0,
    D_8034AFC4_82A734
};

AnimationHeader D_8034B01C_82A78C = {
    0.6f,
    110.0f,
    D_80133040_4E5410,
    D_80139900_4EBCD0,
    D_8034AFC8_82A738
};

AnimationHeader D_8034B030_82A7A0 = {
    0.5f,
    40.0f,
    D_8012C9E0_4DEDB0,
    D_801394D0_4EB8A0,
    NULL
};

AnimationHeader D_8034B044_82A7B4 = {
    0.5f,
    80.0f,
    D_8012D700_4DFAD0,
    D_801395A0_4EB970,
    D_8034AFD0_82A740
};

AnimationHeader D_8034B058_82A7C8 = {
    0.5f,
    90.0f,
    D_80131D30_4E4100,
    D_80139840_4EBC10,
    D_8034AFD4_82A744
};

AnimationHeader D_8034B06C_82A7DC = {
    0.75f,
    200.0f,
    D_8012FB60_4E1F30,
    D_80139770_4EBB40,
    D_8034AFD8_82A748
};

s32 D_8034B080_82A7F0[] = { 0, SOUND_ID_148 };
s32 D_8034B088_82A7F8[] = { 0, SOUND_ID_155 };
s32 D_8034B090_82A800[] = { 0, SOUND_ID_154 };

AnimationHeader D_8034B098_82A808 = {
    0.5f,
    10.0f,
    D_80117980_4C9D50,
    D_801179C0_4C9D90,
    NULL
};

AnimationHeader D_8034B0AC_82A81C = {
    0.6f,
    110.0f,
    D_80117B20_4C9EF0,
    D_80117B60_4C9F30,
    D_8034B088_82A7F8
};

AnimationHeader D_8034B0C0_82A830 = {
    0.8f,
    140.0f,
    D_80117DC0_4CA190,
    D_80117DF0_4CA1C0,
    NULL
};

AnimationHeader D_8034B0D4_82A844 = {
    0.5f,
    40.0f,
    D_801176D0_4C9AA0,
    D_80117730_4C9B00,
    NULL
};

AnimationHeader D_8034B0E8_82A858 = {
    0.6f,
    25.0f,
    D_80117410_4C97E0,
    D_80117480_4C9850,
    D_8034B080_82A7F0
};

AnimationHeader D_8034B0FC_82A86C = {
    0.5f,
    10.0f,
    D_80117210_4C95E0,
    D_80117260_4C9630,
    D_8034B090_82A800
};

AnimationHeader D_8034B110_82A880 = {
    0.5f,
    10.0f,
    D_80117A50_4C9E20,
    D_80117A90_4C9E60,
    NULL
};

AnimationHeader D_8034B124_82A894 = {
    0.6f,
    110.0f,
    D_80117C70_4CA040,
    D_80117CB0_4CA080,
    D_8034B088_82A7F8
};

AnimationHeader D_8034B138_82A8A8 = {
    0.8f,
    140.0f,
    D_80117F10_4CA2E0,
    D_80117F40_4CA310,
    NULL
};

AnimationHeader D_8034B14C_82A8BC = {
    0.5f,
    40.0f,
    D_80117840_4C9C10,
    D_801178A0_4C9C70,
    NULL
};

AnimationHeader D_8034B160_82A8D0 = {
    0.6f,
    25.0f,
    D_80117570_4C9940,
    D_801175E0_4C99B0,
    D_8034B080_82A7F0
};

AnimationHeader D_8034B174_82A8E4 = {
    0.5f,
    10.0f,
    D_80117310_4C96E0,
    D_80117360_4C9730,
    D_8034B090_82A800
};

InteractionHandler D_8034B188_82A8F8[] = {
    { RAINBOW_CMD_30, func_8034935C_828ACC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B1A8_82A918[] = {
    { POKEMON_CMD_9, NULL, 0.0f, func_80349DB0_829520 },
    { POKEMON_CMD_13, NULL, 0.0f, func_80349DE8_829558 },
    { RAINBOW_CMD_28, func_80349480_828BF0, 0.0f, NULL },
    { RAINBOW_CMD_29, func_8034956C_828CDC, 0.0f, NULL },
    { RAINBOW_CMD_32, func_803496BC_828E2C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B208_82A978[] = {
    { RAINBOW_CMD_31, func_8034930C_828A7C, 0.0f, NULL },
    { RAINBOW_CMD_32, func_80349514_828C84, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B238_82A9A8[] = {
    { RAINBOW_CMD_31, func_8034930C_828A7C, 0.0f, NULL },
    { RAINBOW_CMD_33, func_80349480_828BF0, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B268_82A9D8[] = {
    { RAINBOW_CMD_31, func_80349654_828DC4, 0.0f, NULL },
    { RAINBOW_CMD_32, func_803495FC_828D6C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B298_82AA08[] = {
    { RAINBOW_CMD_31, func_80349654_828DC4, 0.0f, NULL },
    { RAINBOW_CMD_33, func_8034956C_828CDC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B2C8_82AA38[] = {
    { POKEMON_CMD_9, NULL, 0.0f, func_80349DB0_829520 },
    { POKEMON_CMD_13, NULL, 0.0f, func_80349DE8_829558 },
    { RAINBOW_CMD_28, func_80349480_828BF0, 0.0f, NULL },
    { RAINBOW_CMD_29, func_8034956C_828CDC, 0.0f, NULL },
    { RAINBOW_CMD_33, func_803493F4_828B64, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B328_82AA98[] = {
    { RAINBOW_CMD_30, func_8034977C_828EEC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B348_82AAB8[] = {
    { POKEMON_CMD_9, NULL, 0.0f, func_80349DB0_829520 },
    { POKEMON_CMD_13, NULL, 0.0f, func_80349DE8_829558 },
    { RAINBOW_CMD_31, func_80349714_828E84, 0.0f, NULL },
    { RAINBOW_CMD_28, func_803498A0_829010, 0.0f, NULL },
    { RAINBOW_CMD_29, func_8034998C_8290FC, 0.0f, NULL },
    { RAINBOW_CMD_32, func_80349ADC_82924C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B3B8_82AB28[] = {
    { RAINBOW_CMD_31, func_80349714_828E84, 0.0f, NULL },
    { RAINBOW_CMD_32, func_80349934_8290A4, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B3E8_82AB58[] = {
    { RAINBOW_CMD_31, func_80349714_828E84, 0.0f, NULL },
    { RAINBOW_CMD_33, func_803498A0_829010, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B418_82AB88[] = {
    { RAINBOW_CMD_31, func_80349A74_8291E4, 0.0f, NULL },
    { RAINBOW_CMD_32, func_80349A1C_82918C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B448_82ABB8[] = {
    { RAINBOW_CMD_31, func_80349A74_8291E4, 0.0f, NULL },
    { RAINBOW_CMD_33, func_8034998C_8290FC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B478_82ABE8[] = {
    { POKEMON_CMD_9, NULL, 0.0f, func_80349DB0_829520 },
    { POKEMON_CMD_13, NULL, 0.0f, func_80349DE8_829558 },
    { RAINBOW_CMD_31, func_80349714_828E84, 0.0f, NULL },
    { RAINBOW_CMD_28, func_803498A0_829010, 0.0f, NULL },
    { RAINBOW_CMD_29, func_8034998C_8290FC, 0.0f, NULL },
    { RAINBOW_CMD_33, func_80349814_828F84, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B4E8_82AC58[] = {
    { RAINBOW_CMD_30, func_80349B98_829308, 0.0f, NULL },
    { RAINBOW_CMD_31, func_80349B34_8292A4, 0.0f, NULL },
    { RAINBOW_CMD_34, func_80349714_828E84, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

Vec3f D_8034B528_82AC98 = { 0.0f, 0.0f, 0.0f };
Vec3f D_8034B534_82ACA4 = { 0.0f, 0.0f, 0.0f };

PokemonAnimationSetup D_8034B540_82ACB0 = {
    &D_8034B098_82A808,
    func_80349180_8288F0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_8034B554_82ACC4 = {
    D_80116EF0_4C92C0,
    D_80116CF0_4C90C0,
    renderModelTypeDFogged,
    &D_8034B540_82ACB0,
    { 2.0f, 2.0f, 2.0f },
    { 0.0f, 0.0f, 0.0f },
    36.0f,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_80349180_8288F0)
    pokemon->miscVars[0].field0 = pokemon->collisionRadius;
    Pokemon_StartAuxProc(obj, func_80349E28_829598);
    Pokemon_StartPathProc(obj, func_803491D4_828944);
    Pokemon_SetState(obj, func_8034930C_828A7C);
}

POKEMON_FUNC(func_803491D4_828944)
    DObj* node;
    Vec3f pos;
    Vec3f vel = D_8034B528_82AC98;

    node = D_8034AB94_82A304->data.dobj->firstChild->firstChild;
    while (true) {
        fx_getPosVelDObj(&pos, &vel, node);
        position->v.x = pos.x;
        position->v.y = pos.y;
        if (D_80350190_82F900 == 0 || position->v.z < 2000.0f) {
            position->v.z = pos.z;
        }
        rotation->v.y = atan2f(pos.x, pos.z) + PI;
        ohWait(1);
    }
}

POKEMON_FUNC(func_8034930C_828A7C)
    HIDE_POKEMON();
    pokemon->transitionGraph = D_8034B188_82A8F8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034935C_828ACC)
    SHOW_POKEMON();

    if (gDirectionIndex < 0) {
        Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    } else {
        Pokemon_SetAnimation(obj, &D_8034B0C0_82A830);
    }
    pokemon->transitionGraph = D_8034B1A8_82A918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_803493F4_828B64);
}

POKEMON_FUNC(func_803493F4_828B64)
    if (D_8034AE48_82A5B8 != 1) {
        Pokemon_ForceAnimation(obj, &D_8034B098_82A808);
    } else {
        Pokemon_ForceAnimation(obj, &D_8034B0AC_82A81C);
    }
    pokemon->transitionGraph = D_8034B1A8_82A918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_803493F4_828B64);
}

POKEMON_FUNC(func_80349480_828BF0)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B208_82A978;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_ForceAnimation(obj, &D_8034B0AC_82A81C);
    pokemon->transitionGraph = D_8034B208_82A978;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80349480_828BF0);
}

POKEMON_FUNC(func_80349514_828C84)
    Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = D_8034B238_82A9A8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034956C_828CDC)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B268_82A9D8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_8034B0AC_82A81C);
    pokemon->transitionGraph = D_8034B268_82A9D8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_803495FC_828D6C)
    Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = D_8034B298_82AA08;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349654_828DC4)
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_8034B0E8_82A858);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_SetState(obj, func_80349714_828E84);
}

POKEMON_FUNC(func_803496BC_828E2C)
    Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = D_8034B2C8_82AA38;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349714_828E84)
    HIDE_POKEMON();
    Pokemon_StartPathProc(obj, func_803491D4_828944);
    pokemon->transitionGraph = D_8034B328_82AA98;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034977C_828EEC)
    SHOW_POKEMON();
    if (gDirectionIndex < 0) {
        Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    } else {
        Pokemon_SetAnimation(obj, &D_8034B138_82A8A8);
    }
    pokemon->transitionGraph = D_8034B348_82AAB8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80349814_828F84);
}

POKEMON_FUNC(func_80349814_828F84)
    if (D_8034AE4C_82A5BC != 1) {
        Pokemon_ForceAnimation(obj, &D_8034B110_82A880);
    } else {
        Pokemon_ForceAnimation(obj, &D_8034B124_82A894);
    }
    pokemon->transitionGraph = D_8034B348_82AAB8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80349814_828F84);
}

POKEMON_FUNC(func_803498A0_829010)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B3B8_82AB28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_ForceAnimation(obj, &D_8034B124_82A894);
    pokemon->transitionGraph = D_8034B3B8_82AB28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_803498A0_829010);
}

POKEMON_FUNC(func_80349934_8290A4)
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = D_8034B3E8_82AB58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034998C_8290FC)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B418_82AB88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_8034B124_82A894);
    pokemon->transitionGraph = D_8034B418_82AB88;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349A1C_82918C)
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = D_8034B448_82ABB8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349A74_8291E4)
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_8034B160_82A8D0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_SetState(obj, func_80349B34_8292A4);
}

POKEMON_FUNC(func_80349ADC_82924C)
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = D_8034B478_82ABE8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349B34_8292A4)
    HIDE_POKEMON();
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_8034B4E8_82AC58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349B98_829308)
    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    Pokemon_StartPathProc(obj, func_80349C18_829388);
    pokemon->transitionGraph = D_8034B4E8_82AC58;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_80349D40_8294B0);
}

POKEMON_FUNC(func_80349C18_829388)
    DObj* node;
    Vec3f sp48;
    Vec3f sp3C = D_8034B534_82ACA4;

    node = D_8034AB94_82A304->data.dobj->firstChild->firstChild;
    fx_getPosVelDObj(&sp48, &sp3C, node);
    position->v.z = sp48.z;
    while (true) {
        fx_getPosVelDObj(&sp48, &sp3C, node);
        position->v.x = sp48.x;
        position->v.y = sp48.y;
        position->v.z += 15.0f;

        if (position->v.z > 2000.0f) {
            break;
        }

        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80349D40_8294B0)
    Pokemon_StartPathProc(obj, func_803491D4_828944);
    Pokemon_SetAnimation(obj, &D_8034B110_82A880);
    pokemon->transitionGraph = D_8034B4E8_82AC58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349DB0_829520)
    cmdSendCommand(D_8034AB94_82A304, POKEMON_CMD_9, obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_80349DE8_829558)
    cmdSendCommand(D_8034AB94_82A304, POKEMON_CMD_13, obj);
    Pokemon_StopAuxProc(obj);
}

static void nullsub(void) {
}

POKEMON_FUNC(func_80349E28_829598)
    while (true) {
        if (gDirectionIndex < 0) {
            cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_32, obj);
        } else {
            cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_33, obj);
        }
        ohWait(1);
    }
}

GObj* func_80349EB8_829628(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034B554_82ACC4);
}
