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

extern u8 D_80116CF0_4C90C0[];
extern u8 D_80116EF0_4C92C0[];
extern u8 D_80117210_4C95E0[];
extern u8 D_80117260_4C9630[];
extern u8 D_80117310_4C96E0[];
extern u8 D_80117360_4C9730[];
extern u8 D_80117410_4C97E0[];
extern u8 D_80117480_4C9850[];
extern u8 D_80117570_4C9940[];
extern u8 D_801175E0_4C99B0[];
extern u8 D_801176D0_4C9AA0[];
extern u8 D_80117730_4C9B00[];
extern u8 D_80117840_4C9C10[];
extern u8 D_801178A0_4C9C70[];
extern u8 D_80117980_4C9D50[];
extern u8 D_801179C0_4C9D90[];
extern u8 D_80117A50_4C9E20[];
extern u8 D_80117A90_4C9E60[];
extern u8 D_80117B20_4C9EF0[];
extern u8 D_80117B60_4C9F30[];
extern u8 D_80117C70_4CA040[];
extern u8 D_80117CB0_4CA080[];
extern u8 D_80117DC0_4CA190[];
extern u8 D_80117DF0_4CA1C0[];
extern u8 D_80117F10_4CA2E0[];
extern u8 D_80117F40_4CA310[];
extern u8 D_8034B080_82A7F0[];
extern u8 D_8034B088_82A7F8[];
void func_80349180_8288F0(GObj*);
void func_8034935C_828ACC(GObj*);
void func_80349480_828BF0(GObj*);
void func_80349514_828C84(GObj*);
void func_8034956C_828CDC(GObj*);
void func_803495FC_828D6C(GObj*);
void func_80349654_828DC4(GObj*);
void func_803496BC_828E2C(GObj*);
void func_8034977C_828EEC(GObj*);
void func_803498A0_829010(GObj*);
void func_80349934_8290A4(GObj*);
void func_8034998C_8290FC(GObj*);
void func_80349A1C_82918C(GObj*);
void func_80349A74_8291E4(GObj*);
void func_80349ADC_82924C(GObj*);
void func_80349B98_829308(GObj*);
void func_80349DB0_829520(GObj*);
void func_80349DE8_829558(GObj*);
extern u32 D_8034B090_82A800[];
extern PokemonAnimationSetup D_8034B540_82ACB0;

// .data
u32 D_8034B090_82A800[] = {
    0x00000000, 0x0000009A,
};

AnimationHeader D_8034B098_82A808 = { 0.5f, 10.0f, (AnimCmd**) &D_80117980_4C9D50, (AnimCmd***) &D_801179C0_4C9D90, NULL };
AnimationHeader D_8034B0AC_82A81C = { 0.6f, 110.0f, (AnimCmd**) &D_80117B20_4C9EF0, (AnimCmd***) &D_80117B60_4C9F30, (s32*) &D_8034B088_82A7F8 };
AnimationHeader D_8034B0C0_82A830 = { 0.8f, 140.0f, (AnimCmd**) &D_80117DC0_4CA190, (AnimCmd***) &D_80117DF0_4CA1C0, NULL };

u32 D_8034B0D4_82A844[] = {
    0x3F000000, 0x42200000, (u32) &D_801176D0_4C9AA0, (u32) &D_80117730_4C9B00,
    0x00000000,
};

AnimationHeader D_8034B0E8_82A858 = { 0.6f, 25.0f, (AnimCmd**) &D_80117410_4C97E0, (AnimCmd***) &D_80117480_4C9850, (s32*) &D_8034B080_82A7F0 };
AnimationHeader D_8034B0FC_82A86C = { 0.5f, 10.0f, (AnimCmd**) &D_80117210_4C95E0, (AnimCmd***) &D_80117260_4C9630, (s32*) &D_8034B090_82A800 };
AnimationHeader D_8034B110_82A880 = { 0.5f, 10.0f, (AnimCmd**) &D_80117A50_4C9E20, (AnimCmd***) &D_80117A90_4C9E60, NULL };
AnimationHeader D_8034B124_82A894 = { 0.6f, 110.0f, (AnimCmd**) &D_80117C70_4CA040, (AnimCmd***) &D_80117CB0_4CA080, (s32*) &D_8034B088_82A7F8 };
AnimationHeader D_8034B138_82A8A8 = { 0.8f, 140.0f, (AnimCmd**) &D_80117F10_4CA2E0, (AnimCmd***) &D_80117F40_4CA310, NULL };

u32 D_8034B14C_82A8BC[] = {
    0x3F000000, 0x42200000, (u32) &D_80117840_4C9C10, (u32) &D_801178A0_4C9C70,
    0x00000000,
};

AnimationHeader D_8034B160_82A8D0 = { 0.6f, 25.0f, (AnimCmd**) &D_80117570_4C9940, (AnimCmd***) &D_801175E0_4C99B0, (s32*) &D_8034B080_82A7F0 };
AnimationHeader D_8034B174_82A8E4 = { 0.5f, 10.0f, (AnimCmd**) &D_80117310_4C96E0, (AnimCmd***) &D_80117360_4C9730, (s32*) &D_8034B090_82A800 };

InteractionHandler D_8034B188_82A8F8[2] = {
    { 30, (GObjFunc) func_8034935C_828ACC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B1A8_82A918[6] = {
    { 9, NULL, 0.0f, (GObjFunc) func_80349DB0_829520 },
    { 13, NULL, 0.0f, (GObjFunc) func_80349DE8_829558 },
    { 28, (GObjFunc) func_80349480_828BF0, 0.0f, NULL },
    { 29, (GObjFunc) func_8034956C_828CDC, 0.0f, NULL },
    { 32, (GObjFunc) func_803496BC_828E2C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B208_82A978[3] = {
    { 31, (GObjFunc) func_8034930C_828A7C, 0.0f, NULL },
    { 32, (GObjFunc) func_80349514_828C84, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B238_82A9A8[3] = {
    { 31, (GObjFunc) func_8034930C_828A7C, 0.0f, NULL },
    { 33, (GObjFunc) func_80349480_828BF0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B268_82A9D8[3] = {
    { 31, (GObjFunc) func_80349654_828DC4, 0.0f, NULL },
    { 32, (GObjFunc) func_803495FC_828D6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B298_82AA08[3] = {
    { 31, (GObjFunc) func_80349654_828DC4, 0.0f, NULL },
    { 33, (GObjFunc) func_8034956C_828CDC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B2C8_82AA38[6] = {
    { 9, NULL, 0.0f, (GObjFunc) func_80349DB0_829520 },
    { 13, NULL, 0.0f, (GObjFunc) func_80349DE8_829558 },
    { 28, (GObjFunc) func_80349480_828BF0, 0.0f, NULL },
    { 29, (GObjFunc) func_8034956C_828CDC, 0.0f, NULL },
    { 33, (GObjFunc) func_803493F4_828B64, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B328_82AA98[2] = {
    { 30, (GObjFunc) func_8034977C_828EEC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B348_82AAB8[7] = {
    { 9, NULL, 0.0f, (GObjFunc) func_80349DB0_829520 },
    { 13, NULL, 0.0f, (GObjFunc) func_80349DE8_829558 },
    { 31, (GObjFunc) func_80349714_828E84, 0.0f, NULL },
    { 28, (GObjFunc) func_803498A0_829010, 0.0f, NULL },
    { 29, (GObjFunc) func_8034998C_8290FC, 0.0f, NULL },
    { 32, (GObjFunc) func_80349ADC_82924C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B3B8_82AB28[3] = {
    { 31, (GObjFunc) func_80349714_828E84, 0.0f, NULL },
    { 32, (GObjFunc) func_80349934_8290A4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B3E8_82AB58[3] = {
    { 31, (GObjFunc) func_80349714_828E84, 0.0f, NULL },
    { 33, (GObjFunc) func_803498A0_829010, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B418_82AB88[3] = {
    { 31, (GObjFunc) func_80349A74_8291E4, 0.0f, NULL },
    { 32, (GObjFunc) func_80349A1C_82918C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B448_82ABB8[3] = {
    { 31, (GObjFunc) func_80349A74_8291E4, 0.0f, NULL },
    { 33, (GObjFunc) func_8034998C_8290FC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B478_82ABE8[7] = {
    { 9, NULL, 0.0f, (GObjFunc) func_80349DB0_829520 },
    { 13, NULL, 0.0f, (GObjFunc) func_80349DE8_829558 },
    { 31, (GObjFunc) func_80349714_828E84, 0.0f, NULL },
    { 28, (GObjFunc) func_803498A0_829010, 0.0f, NULL },
    { 29, (GObjFunc) func_8034998C_8290FC, 0.0f, NULL },
    { 33, (GObjFunc) func_80349814_828F84, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_8034B4E8_82AC58[4] = {
    { 30, (GObjFunc) func_80349B98_829308, 0.0f, NULL },
    { 31, (GObjFunc) func_80349B34_8292A4, 0.0f, NULL },
    { 34, (GObjFunc) func_80349714_828E84, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

Vec3f D_8034B528_82AC98 = { 0.0f, 0.0f, 0.0f };
Vec3f D_8034B534_82ACA4 = { 0.0f, 0.0f, 0.0f };
PokemonAnimationSetup D_8034B540_82ACB0 = { (AnimationHeader*) &D_8034B098_82A808, (GObjFunc) func_80349180_8288F0, 0, "", NULL, NULL };
PokemonInitData D_8034B554_82ACC4 = { (UnkEC64Arg3*) &D_80116EF0_4C92C0, (Texture***) &D_80116CF0_4C90C0, (GObjFunc) renderModelTypeDFogged, (PokemonAnimationSetup*) &D_8034B540_82ACB0, { 2.0f, 2.0f, 2.0f }, { 0.0f, 0.0f, 0.0f }, 36.0f, 0, 0, 0, 0, "" };

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
