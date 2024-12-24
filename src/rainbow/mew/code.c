#include "../rainbow.h"

void func_803467A4_825F14(GObj*);
void func_80347188_8268F8(GObj*);
void func_803471D4_826944(GObj*);
void func_80347334_826AA4(GObj*);
void func_80347398_826B08(GObj*);
void func_80347724_826E94(GObj*);
void func_80347900_827070(GObj*);
void func_80347940_8270B0(GObj*);
void func_8034799C_82710C(GObj*);
void func_80347CC8_827438(GObj*);
void func_80347E0C_82757C(GObj*);
void func_80347E44_8275B4(GObj*);
void func_8034800C_82777C(GObj*);
void func_803480C0_827830(GObj*);
void func_803482EC_827A5C(GObj*);
void func_80348540_827CB0(GObj*);
void func_803487CC_827F3C(GObj*);
void func_80348850_827FC0(GObj*);
void func_803475D0_826D40(GObj*);
void func_8034877C_827EEC(GObj*);
void func_80347B88_8272F8(GObj*);
void func_80348208_827978(GObj*);
void func_80347574_826CE4(GObj*);
void func_80349084_8287F4(GObj*);

extern AnimCmd* D_8012C9E0[];
extern AnimCmd* D_8012D700[];
extern AnimCmd* D_8012EFF0[];
extern AnimCmd* D_8012FB60[];
extern AnimCmd* D_80131D30[];
extern AnimCmd* D_80133040[];
extern AnimCmd* D_801358A0[];
extern AnimCmd* D_801368F0[];

extern AnimCmd** D_801394D0[];
extern AnimCmd** D_801395A0[];
extern AnimCmd** D_80139690[];
extern AnimCmd** D_80139770[];
extern AnimCmd** D_80139840[];
extern AnimCmd** D_80139900[];
extern AnimCmd** D_80139A00[];
extern AnimCmd** D_80139B00[];

extern UnkEC64Arg3 D_8034FB98[];
extern Texture** D_8034B740[];

s32 D_8034AC90_82A400[] = { SOUND_ID_349 };
s32 D_8034AC94_82A404[] = { SOUND_ID_351 };
s32 D_8034AC98_82A408[] = { SOUND_ID_350, SOUND_ID_147 };
s32 D_8034ACA0_82A410[] = { SOUND_ID_349 };
s32 D_8034ACA4_82A414[] = { SOUND_ID_351 };
s32 D_8034ACA8_82A418[] = { SOUND_ID_352, SOUND_ID_145 };

AnimationHeader D_8034ACB0_82A420 = {
    0.5,
    70,
    D_8012EFF0,
    D_80139690,
    NULL
};

AnimationHeader D_8034ACC4_82A434 = {
    0.65,
    135,
    D_801368F0,
    D_80139B00,
    D_8034AC90_82A400
};

AnimationHeader D_8034ACD8_82A448 = {
    0.8,
    140,
    D_801358A0,
    D_80139A00,
    D_8034AC94_82A404
};

AnimationHeader D_8034ACEC_82A45C = {
    0.6,
    110,
    D_80133040,
    D_80139900,
    D_8034AC98_82A408
};

AnimationHeader D_8034AD00_82A470 = {
    0.5,
    40,
    D_8012C9E0,
    D_801394D0,
    NULL
};

AnimationHeader D_8034AD14_82A484 = {
    0.5,
    80,
    D_8012D700,
    D_801395A0,
    D_8034ACA0_82A410
};

AnimationHeader D_8034AD28_82A498 = {
    0.5,
    90,
    D_80131D30,
    D_80139840,
    D_8034ACA4_82A414
};

AnimationHeader D_8034AD3C_82A4AC = {
    0.75,
    200,
    D_8012FB60,
    D_80139770,
    D_8034ACA8_82A418
};

InteractionHandler D_8034AD50_82A4C0[] = {
    { POKEMON_CMD_9, func_803475D0_826D40, 0, NULL },
    { POKEMON_CMD_13, func_803475D0_826D40, 0, NULL },
    { RAINBOW_CMD_35, func_8034877C_827EEC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_8034AD90_82A500[] = {
    { POKEMON_CMD_9, func_80347B88_8272F8, 0, NULL },
    { POKEMON_CMD_13, func_80347B88_8272F8, 0, NULL },
    { RAINBOW_CMD_35, func_8034877C_827EEC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_8034ADD0_82A540[] = {
    { POKEMON_CMD_9, func_80348208_827978, 0, NULL },
    { POKEMON_CMD_13, func_80348208_827978, 0, NULL },
    { RAINBOW_CMD_35, func_8034877C_827EEC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_8034AE10_82A580[] = {
    { RAINBOW_CMD_35, func_8034877C_827EEC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_8034AE30_82A5A0[] = {
    { 1, func_80347334_826AA4 },
    { 1, func_80347574_826CE4 },
    { 0, NULL }
};

s32 D_8034AE48_82A5B8 = 3;
s32 D_8034AE4C_82A5BC = 3;
f32 D_8034AE50_82A5C0 = 0;
f32 D_8034AE54_82A5C4 = 0;
f32 D_8034AE58_82A5C8 = 0;
s32 D_8034AE5C_82A5CC = 0;

// .bss
extern f32 D_80350188_82F8F8;
extern f32 D_8035018C_82F8FC;
extern bool D_80350190_82F900;
extern s32 D_80350194_82F904;
extern s32 D_80350198_82F908;

POKEMON_FUNC(func_80346FA0_826710)
    s32 sp40[] = { 7200, 1800 };
    s32 i;
    s32 var_s0;

    for (i = 0; i < (u32) ARRAY_COUNT(sp40); i++) {
        var_s0 = sp40[i];
        while (var_s0--) {
            ohWait(1);
        }
        D_8034AB9C_82A30C = 0x6D37F;
    }

    D_8034AB9C_82A30C = 0x65B7F;
    omCreateProcess(obj, func_80349084_8287F4, 1, 1);
    while (D_8034AE5C_82A5CC == 0) {
        if (D_8034AF38_82A6A8 != 0) {
            cmdSendCommand(obj, RAINBOW_CMD_35, obj);
        }
        ohWait(1);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_803470CC_82683C)
    Pokemon_StartAuxProc(obj, func_80346FA0_826710);
    Pokemon_StartPathProc(obj, func_80347188_8268F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    omCreateProcess(obj, func_803467A4_825F14, 1, 1);
    D_80350188_82F8F8 = position->v.y;
    D_8035018C_82F8FC = position->v.z;
    pokemon->specialPoseID = 0;
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetState(obj, func_803471D4_826944);
}

POKEMON_FUNC(func_80347188_8268F8)
    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_803471D4_826944)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    D_8034AE50_82A5C0 = randRange(360) * TAU / 360.0f;
    D_8034AE58_82A5C8 = randRange(180) * PI / 180.0f;

    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_30, obj);
    Pokemon_StartPathProc(obj, func_80347398_826B08);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_8034ACD8_82A448);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80347334_826AA4);
}

POKEMON_FUNC(func_80347334_826AA4)
    D_80350190_82F900 = false;
    Pokemon_SetAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_8034AE30_82A5A0);
}

POKEMON_FUNC(func_80347398_826B08)
    f32 var_f20 = 1.0f;

    while (true) {
        var_f20 += randFloat() - 0.5;
        if (var_f20 < 1.0f) {
            var_f20 = 1.0f;
        } else if (var_f20 > 4.0f) {
            var_f20 = 4.0f;
        }

        position->v.x = sinf(D_8034AE50_82A5C0) * 200.0f;
        D_8034AE50_82A5C0 += var_f20 * PI / 180.0f;
        D_8034AE50_82A5C0 -= (s32) (D_8034AE50_82A5C0 / TAU) * TAU;

        position->v.z = sinf(D_8034AE58_82A5C8) * 150.0f + D_8035018C_82F8FC;
        D_8034AE58_82A5C8 += (PI / 225.0); // 0.8 deg
        D_8034AE58_82A5C8 -= (s32) (D_8034AE58_82A5C8 / TAU) * TAU;

        ohWait(1);
    }
}

POKEMON_FUNC(func_80347574_826CE4)
    Pokemon_SetAnimation(obj, &D_8034ACC4_82A434);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_8034AE30_82A5A0);
}

POKEMON_FUNC(func_803475D0_826D40)
    if (--D_8034AE48_82A5B8 != 0) {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_28, obj);
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);

        pokemon->tangible = false;
        obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    } else {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_29, obj);
        D_80350190_82F900 = true;
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
        pokemon->tangible = false;
        obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
        Pokemon_SetState(obj, func_80347724_826E94);
    }
    Pokemon_SetState(obj, func_803471D4_826944);
}

POKEMON_FUNC(func_80347724_826E94)
    D_80350190_82F900 = false;
    pokemon->specialPoseID = 0;
    pokemon->flags |= POKEMON_FLAG_8;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    pokemon->counter = 150, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    D_8034AE50_82A5C0 = randRange(360) * TAU / 360.0f;
    D_8034AE54_82A5C4 = randRange(360) * PI / 360.0f;

    position->v.z = (randRange(50) + 80) * 10.0f + 200.0f;
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_30, obj);
    Pokemon_StartPathProc(obj, func_8034799C_82710C);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_8034ACD8_82A448);
    pokemon->transitionGraph = D_8034AD90_82A500;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80347900_827070);
    }
    Pokemon_SetState(obj, func_80347940_8270B0);
}

POKEMON_FUNC(func_80347900_827070)
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
    Pokemon_SetState(obj, func_80347724_826E94);
}

POKEMON_FUNC(func_80347940_8270B0)
    Pokemon_SetAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = D_8034AD90_82A500;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_80347900_827070);
}

POKEMON_FUNC(func_8034799C_82710C)
    s32 counter = 120;

    while (position->v.z > 200.0f && counter--) {
        position->v.x = sinf(D_8034AE50_82A5C0) * 300.0f;
        D_8034AE50_82A5C0 += PI / 180.0f;
        D_8034AE50_82A5C0 -= (s32) (D_8034AE50_82A5C0 / TAU) * TAU;

        position->v.z -= 10.0f;

        position->v.y = sinf(D_8034AE54_82A5C4) * 20.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 45.0; // 4 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80347B88_8272F8)
    if (--D_8034AE4C_82A5BC != 0) {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_28, obj);
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
    } else {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_29, obj);
        D_80350190_82F900 = true;
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
        Pokemon_SetState(obj, func_80347E0C_82757C);
    }
    Pokemon_SetState(obj, func_80347724_826E94);
}

POKEMON_FUNC(func_80347CC8_827438)
    while (true) {
        if (!(position->v.z < 2200.0f)) {
            break;
        }
        position->v.z += 10.0f;
        position->v.y = sinf(D_8034AE54_82A5C4) * 50.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 30.0; // 6 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80347E0C_82757C)
    Pokemon_StartAuxProc(obj, func_80348540_827CB0);
    Pokemon_SetState(obj, func_80347E44_8275B4);
}

POKEMON_FUNC(func_80347E44_8275B4)
    D_80350194_82F904 = 4;
    pokemon->flags &= ~POKEMON_FLAG_8;
    pokemon->specialPoseID = 10;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    position->v.y = 100.0f;
    position->v.z = 200.0f;
    position->v.x = randRange(2) != 0 ? ((D_80350194_82F904 * 60.0f) + 100.0f) : -((D_80350194_82F904 * 60.0f) + 100.0f);

    D_8034AE54_82A5C4 = 0.0f;
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_30, obj);
    Pokemon_StartPathProc(obj, func_803480C0_827830);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_8034AD28_82A498);
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_8034800C_82777C);
}

POKEMON_FUNC(func_8034800C_82777C)
    if (randRange(2) != 0) {
        Pokemon_SetAnimation(obj, &D_8034AD00_82A470);
    } else {
        Pokemon_SetAnimation(obj, &D_8034AD14_82A484);
    }
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_34, obj);
    D_8034AE4C_82A5BC = 1;
    D_80350198_82F908 = 0;
    Pokemon_SetState(obj, func_80347724_826E94);
}

POKEMON_FUNC(func_803480C0_827830)
    while (position->v.z < 2000.0f) {
        position->v.z += 5.0f;
        position->v.y = sinf(D_8034AE54_82A5C4) * 50.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 60.0; // 3 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80348208_827978)
    D_80350198_82F908 = 2;
    pokemon->poseID = 152;
    Pokemon_StartPathProc(obj, func_803482EC_827A5C);
    Pokemon_ForceAnimation(obj, &D_8034AD3C_82A4AC);
    pokemon->counter = 192, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->poseID = 153;
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (D_80350194_82F904 != 0) {
        D_80350194_82F904--;
    }
    pokemon->poseID = 0;
    D_80350198_82F908 = 1;
    Pokemon_SetState(obj, func_80347E44_8275B4);
}

POKEMON_FUNC(func_803482EC_827A5C)
    f32 f20 = position->v.x;
    s32 counter1 = 101;
    s32 counter2 = 96;
    bool cond;

    D_8034AE50_82A5C0 = 0.0f;
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);

    while (true) {
        if (counter2 == 0) {
            if (position->v.z > 200.0f) {
                position->v.z -= 2.0f;
            } else {
                break;
            }
        } else {
            counter2--;
        }

        position->v.y = sinf(D_8034AE54_82A5C4) * 10.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 90.0; // 2 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;

        if (counter1-- > 0) {
            if (ABS(f20) > 1.0f) {
                if (f20 > 0) {
                    f20 -= 1.0f;
                } else {
                    f20 += 1.0f;
                }
            } else {
                f20 = 0.0f;
            }
        }
        position->v.x = f20;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

void func_803484F0_827C60(s32 arg0, s32* arg1) {
    if (ABS(arg0 - *arg1) < 6) {
        *arg1 = arg0;
    } else if (*arg1 < arg0) {
        *arg1 += 6;
    } else {
        *arg1 -= 6;
    }
}

POKEMON_FUNC(func_80348540_827CB0)
    u8 sp50[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 13, 14, 15 };
    u8 sp4C[] = { 9, 10, 11 };
    s32 unused[2];
    s32 sp40 = 127;
    s32 i;
    s32 sp38 = 0;

    auPlaySong(BGM_PLAYER_AUX, SONG_ID_28);
    D_80350198_82F908 = 1;

    while (D_80350198_82F908 != 0) {
        if (Items_GetPokeFluteCmd() != 0) {
            auSetBGMVolume(BGM_PLAYER_MAIN, 0x7F00);
            func_803484F0_827C60(127, &sp40);
            for (i = 0; i < (u32)ARRAY_COUNT(sp50); i++) {
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, sp50[i], sp40);
            }
        } else {
            func_803484F0_827C60(D_80350198_82F908 == 1 ? 63 : 0, &sp40);
            for (i = 0; i < (u32)ARRAY_COUNT(sp50); i++) {
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, sp50[i], sp40);
            }
            for (i = 0; i < (u32)ARRAY_COUNT(sp4C); i++) {
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, sp4C[i], 0);
            }
        }
        ohWait(1);
    }

    while (sp40 != 127 || sp38 != 127) {
        func_803484F0_827C60(127, &sp40);
        func_803484F0_827C60(127, &sp38);
        for (i = 0; i < (u32)ARRAY_COUNT(sp50); i++) {
            auSetBGMChannelVolume(BGM_PLAYER_MAIN, sp50[i], sp40);
        }
        for (i = 0; i < (u32)ARRAY_COUNT(sp4C); i++) {
            auSetBGMChannelVolume(BGM_PLAYER_MAIN, sp4C[i], sp38);
        }
        ohWait(1);
    }

    auStopSong(BGM_PLAYER_AUX);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_8034877C_827EEC)
    D_8034AE5C_82A5CC = 1;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_80348850_827FC0);
    Pokemon_SetState(obj, func_803487CC_827F3C);
}

POKEMON_FUNC(func_803487CC_827F3C)
    Pokemon_ForceAnimation(obj, &D_8034AD3C_82A4AC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_803487CC_827F3C);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80348850_827FC0)
    f32 f22;

    position->v.y = 100.0f;
    position->v.z = 660.0f;

    f22 = position->v.y + 500.0f;
    while (position->v.y < f22) {
        position->v.y += 5.0f / 3.0f;
        rotation->v.y += PI / 18.0f;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

PokemonAnimationSetup D_8034AE7C_82A5EC = {
    &D_8034ACB0_82A420,
    func_803470CC_82683C,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_8034AE90_82A600 = {
    D_8034FB98,
    D_8034B740,
    renderPokemonModelTypeIFogged,
    &D_8034AE7C_82A5EC,
    { 2, 2, 2 },
    { 0, 117, 0 },
    24,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_2 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

GObj* func_80348938_8280A8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_8034AE90_82A600);
}
