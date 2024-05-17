#include "common.h"
#include "world/world.h"
#include "app_level.h"

void func_80351534_4F1944(GObj*);
void func_80350224_4F0634(GObj*);
void func_80350AE8_4F0EF8(GObj*);
void func_803512FC_4F170C(GObj*);
void func_80350950_4F0D60(GObj*);

// TODO make sprite assets

/*
s32 D_80366BA0_506FB0 = 10;
UnkGoldViper D_80366BA4_506FB4 = {
    0.0f,
    0.5f,
    NULL,
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
}
*/

extern s32 D_80366BA0_506FB0;
extern UnkGoldViper D_80366BA4_506FB4;
extern Sprite D_80366DF0_507200; // 506FE8 small reticle
extern Sprite D_80367580_507990; // 507248 reticle 2
extern Sprite D_80367D10_508120; // 5079D8 reticle 3
extern Sprite D_80367DC0_5081D0; // 508168 red dot
extern Sprite D_80368038_508448; // 508218 white dot
extern Sprite D_803706E0_510AF0; // 508490
extern Sprite D_80378D88_519198; // 510B38
extern Sprite D_80378ED8_5192E8; // 5191E0 white square
extern Sprite D_8037A9A0_51ADB0; // 519330 Pause
extern Sprite D_8037C468_51C878; // 51ADF8 Pause Pressed
extern Sprite D_8037D2A0_51D6B0; // 51C8C0 Quit Course
extern Sprite D_8037E0D8_51E4E8; // 51D6F8 Quit Course Pressed
extern Sprite D_8037EF10_51F320; // 51E530 Continue
extern Sprite D_8037FD48_520158; // 51F368 Continue Pressed
extern Sprite D_80380B80_520F90; // 5201A0 Retry
extern Sprite D_803819B8_521DC8; // 520FD8 Retry Pressed
extern Sprite D_80381B58_521F68; // 521E10 END

// we have to make this small array because of alignment
u32 D_80382BF0_523000[] = {
    0x803AE160,
    0x00000000,
    0x00000000
};

s32 D_80382BFC_52300C = 2;
GObj* D_80382C00_523010 = NULL;
DObj* D_80382C04_523014 = NULL;
s32 D_80382C08_523018_unused = 0;
f32 D_80382C0C_52301C = 0.0f;
f32 D_80382C10_523020_unused = 0.0f;
s32 D_80382C14_523024 = 0;
s32 D_80382C18_523028 = 0;
f32 D_80382C1C_52302C = 0.0f;
f32 D_80382C20_523030 = 0.0f;
f32 D_80382C24_523034 = -500.0f;
f32 D_80382C28_523038 = 0.0f;
f32 D_80382C2C_52303C = 0.0f;
OMCamera* D_80382C30_523040 = NULL;
s32 D_80382C34_523044_unused = 0;
GObj* D_80382C38_523048 = NULL;
s32 D_80382C3C_52304C = 0;
GObj* D_80382C40_523050 = NULL;
f32 D_80382C44_523054 = 0.0005;
f32 D_80382C48_523058 = 0.0f;
s32 D_80382C4C_52305C = 0;
f32 D_80382C50_523060 = 0.0f;
f32 D_80382C54_523064_unused = 0.0f;
f32 D_80382C58_523068 = 0.0f;
f32 D_80382C5C_52306C = 20.0f;
f32 D_80382C60_523070 = 3.0f;
s32 D_80382C64_523074 = 0;
f32 D_80382C68_523078 = 1.0f;
GObj* D_80382C6C_52307C = NULL;
SObj* D_80382C70_523080 = NULL;
SObj* D_80382C74_523084 = NULL;
SObj* D_80382C78_523088 = NULL;
SObj* D_80382C7C_52308C = NULL;
SObj* D_80382C80_523090 = NULL;
SObj* D_80382C84_523094 = NULL;
SObj* D_80382C88_523098 = NULL;
SObj* D_80382C8C_52309C = NULL;
SObj* D_80382C90_5230A0 = NULL;
Vec3f D_80382C94_5230A4 = { 0.0f, 0.0f, 0.0f };
Vec3f D_80382CA0_5230B0 = { 0.0f, 0.0f, 0.0f };
s32 D_80382CAC_5230BC_unused[2] = { 0, 0 };
s32 D_80382CB4_5230C4 = 3;
s32 D_80382CB8_5230C8 = 3;
s32 D_80382CBC_5230CC = 3;
f32 D_80382CC0_5230D0 = 0.0f;
f32 D_80382CC4_5230D4 = 0.0f;
f32 D_80382CC8_5230D8 = 0.0f;
f32 D_80382CCC_5230DC = 0.0f;
f32 D_80382CD0_5230E0 = 0.0f;
f32 D_80382CD4_5230E4 = 0.0f;
f32 D_80382CD8_5230E8[5] = {
    -3.141592741f,
    -1.570796371f,
    0.0f,
    1.570796371f,
    3.141592741f,
};
f32 D_80382CEC_5230FC = -0.3926990926f;
f32 D_80382CF0_523100 = 0.7853981853f;
s32 D_80382CF4_523104 = 0;
s32 D_80382CF8_523108 = 0;
s32 D_80382CFC_52310C = 0;
s8 D_80382D00_523110 = 2;
s8 D_80382D04_523114 = 0;
s32 D_80382D08_523118 = 0;
s32 D_80382D0C_52311C = 0;
GObj* D_80382D10_523120 = NULL;
GObj* D_80382D14_523124 = NULL;
void (*D_80382D18_523128)(s32) = NULL;
void (*D_80382D1C_52312C)(s32) = NULL;
u8 D_80382D20_523130 = 0;
u8 D_80382D24_523134 = 0;
s32 D_80382D28_523138 = 153;
u8 D_80382D2C_52313C = 0;
u8 D_80382D30_523140 = 0;
u8 D_80382D34_523144 = 0;
s32 D_80382D38_523148 = 360;
f32 D_80382D3C_52314C = 1.0f;
u8 D_80382D40_523150 = 0;
u8 D_80382D44_523154 = 0;
s32 D_80382D48_523158 = -1;

extern s32 D_80382DC0_5231D0;
extern Sprite D_80388E00_529210;

// bss
extern s32 D_803AE408_54E818;
extern Vec3f D_803AE410_54E820;
extern Vec3f D_803AE420_54E830;
extern Vec3f D_803AE430_54E840;
extern SObj* D_803AE440_54E850[4];
extern SObj* D_803AE458_54E868[6];
extern s32 D_803AE470_54E880;
extern s32 D_803AE474_54E884;
extern f32 D_803AE478_54E888;
extern f32 D_803AE47C_54E88C;
extern struct DObjDynamicStore D_803AE4A0_54E8B0; // size 0x38
extern Vec3f D_803AE4D8_54E8E8;
extern Vec3f D_803AE4E8_54E8F8;
extern Vec3f D_803AE4F8_54E908;
extern Vec3f D_803AE508_54E918;
extern s8 D_803AE514_54E924;
extern s8 D_803AE515_54E925;
extern s8 D_803AE516_54E926;
extern UnkCelesteWolverine* D_803AE518_54E928;
extern u32 D_803AE51C_54E92C;
extern s8 D_803AE520_54E930;
extern s8 D_803AE521_54E931;
extern s8 D_803AE522_54E932;
extern s32 D_803AE530_54E940[4]; // Rect?
extern s32 D_803AE540_54E950;
extern s32 D_803AE544_54E954;
extern s32 D_803AE548_54E958;
extern s32 D_803AE54C_54E95C;
extern s32 D_803AE768_54EB78;
extern GObj* D_803AE76C_54EB7C;
extern s32 D_803AE770_54EB80;
extern u16 D_803AE774_54EB84;

extern s32 D_803AEF30_54F340;
extern u16 D_803AEF38_54F348;

void func_803573BC_4F77CC(void);
void func_80350950_4F0D60(GObj*);
void func_80350AE8_4F0EF8(GObj*);
void func_803512FC_4F170C(GObj*);
void func_80351768_4F1B78(GObj*);
void func_80351FF0_4F2400(GObj*);
void func_8035275C_4F2B6C(GObj*);
void func_80353180_4F3590(GObj*);
void func_803549A4_4F4DB4(GObj*);
void func_80357120_4F7530(GObj*);
void func_803579C8_4F7DD8(f32*, f32*, f32*);
void func_803588D4_4F8CE4(void);
void func_8035E37C_4FE78C(void);
void func_80365B24_505F34(void);
void func_80365BB0_505FC0(char*, s32, s32, u8, u8, u8, u8, s32, u8);
s32 func_80365E70_506280(void);
UnkCelesteWolverine* func_8009A8CC(void);
void func_800A7918(s32, f32);
void func_800A7F40(f32, f32, s32, f32);
void func_80357D18_4F8128(s32, s32, s32, s32);
void func_80365E34_506244(void);
void func_80358994_4F8DA4(s32);
void func_80355614_4F5A24(GObj*);
void func_80357170_4F7580(void);
void func_80359064_4F9474(void);
void func_80355F18_4F6328(GObj* arg0);
s32 func_8009BBF4(void);
void func_8035E4D0_4FE8E0(void);
void func_8035E764_4FEB74(void);
void func_8035E754_4FEB64(void);
void func_80359034_4F9444(void);
void func_800A1E6C(Vec3f* arg0);
void func_80356074_4F6484(GObj* arg0);
void func_80355860_4F5C70(GObj*);
s32 func_8035E508_4FE918(void);
s32 func_8009C9E8(GObj* gobj);
s32 func_8035E52C_4FE93C(void);

s32 func_80350200_4F0610(s32 arg0) {
    return func_800BF3D4_5C274(arg0) == 0;
}

void func_80350224_4F0634(GObj* arg0) {
    func_800E3D04_614B4(&D_80366BA4_506FB4);
}

void func_8035024C_4F065C(f32 arg0, f32 arg1, f32 arg2) {
    D_80382C94_5230A4.x += arg0;
    D_80382C94_5230A4.y += arg1;
    D_80382C94_5230A4.z += arg2;

    D_80382C30_523040->viewMtx.lookAt.eye.x += arg0;
    D_80382C30_523040->viewMtx.lookAt.eye.y += arg1;
    D_80382C30_523040->viewMtx.lookAt.eye.z += arg2;

    D_80382C30_523040->viewMtx.lookAt.at.x += arg0;
    D_80382C30_523040->viewMtx.lookAt.at.y += arg1;
    D_80382C30_523040->viewMtx.lookAt.at.z += arg2;

    D_803AE410_54E820.x += arg0; D_803AE410_54E820.y += arg1; D_803AE410_54E820.z += arg2;
    D_803AE420_54E830.x += arg0; D_803AE420_54E830.y += arg1; D_803AE420_54E830.z += arg2;
    D_80382C1C_52302C += arg0; D_80382C20_523030 += arg1; D_80382C24_523034 += arg2;
}

void func_8035038C_4F079C(void) {
    ohPauseProcessByFunction(D_80382C00_523010, func_80351FF0_4F2400);
    ohPauseProcessByFunction(D_80382C00_523010, func_8035275C_4F2B6C);
    ohPauseProcessByFunction(D_80382C00_523010, func_80353180_4F3590);
    ohPauseProcessByFunction(D_80382C00_523010, func_80351534_4F1944);
    ohPauseProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
    ohPauseProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
    ohPauseProcessByFunction(D_80382C00_523010, func_803512FC_4F170C);
    ohPauseProcessByFunction(D_80382C00_523010, func_80350950_4F0D60);
    ohPauseProcessByFunction(D_80382C00_523010, func_80351768_4F1B78);
    ohPauseProcessByFunction(D_80382C6C_52307C, func_803549A4_4F4DB4);
}

void func_80350458_4F0868(s32 arg0, s32 arg1) {
    scRemovePostProcessFunc();
    func_800A7F68(arg0, arg1);
}

void func_80350488_4F0898(GObj* obj) {
    f32 var_f20;
    s32 i;
    f32 duration = 120.0f;
    UnkCelesteWolverineSub* sub = D_803AE518_54E928->unk_10;

    for (i = D_803AE518_54E928->unk_00 / sizeof(UnkCelesteWolverineSub); i > 0; i--, sub++) {
        gContInputCurrentButtons = sub->unk_00;
        gContInputPressedButtons = sub->unk_02;
        gContInputHeldButtons = sub->unk_04;
        gContInputReleasedButtons = sub->unk_06;
        gContInputStickX = sub->unk_08;
        gContInputStickY = sub->unk_09;
        ohWait(1);
        if (D_800BF051 == 0 && (gContInputPressedButtons & (A_BUTTON | START_BUTTON))) {
            func_8035038C_4F079C();
            func_80350458_4F0868(10, 1);
            func_800A7470(0, 0, 0);
            func_800A7918(0, 0.5f);
            ohWait(1);
            while (func_800A7460() == 1) {
                ohWait(1);
            }
            D_80382D18_523128(8);
            omEndProcess(NULL);
            return;
        }
    }

    func_8035038C_4F079C();
    var_f20 = 1.0f;
    func_80350458_4F0868(10, 1);
    func_800A7F40(0.0f, 0.0f, 0, 2.0f);
    auSetBGMVolumeSmooth(1, 0, 120);
    ohWait(1);
    while (func_800A7460() == 1) {
        var_f20 += -(1.0f / duration);
        auSetSoundGlobalVolume(127.0f * var_f20);
        ohWait(1);
    }
    auSetSoundGlobalVolume(0);
    D_80382D18_523128(7);
    omEndProcess(NULL);
}

void func_80350788_4F0B98(GObj* obj) {
    UnkCelesteWolverine* unk = D_803AE518_54E928;
    setRandSeed(unk->unk_08);
    D_803AE51C_54E92C = unk->unk_0C;
    omCreateProcess(obj, &func_80350488_4F0898, 0, 10);
}

void func_803507E0_4F0BF0(s32 arg0) {
    D_80382D48_523158 = arg0;
}

void func_803507EC_4F0BFC(GObj* obj) {
    s32 s0 = 2;

    while (TRUE) {
        if (Items_GetPokeFluteState() == 0) {
            if (--s0 < 0) {
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                s0 = 2;
                auStopSong(BGM_PLAYER_MAIN);
                if (D_803AE518_54E928 == NULL) {
                    auPlaySong(BGM_PLAYER_MAIN, D_80382D48_523158);
                }
            }
        } else {
            s0 = 2;
        }
        ohWait(1);
    }
}

void func_80350898_4F0CA8(GObj* obj) {
    f32 f20;
    s32 i;

    for (f20 = 0.0f, i = 59; i > 0; i--) {
        D_80382C48_523058 = cosf(f20) * 15.0f;
        f20 += 0.3f;
        if (f20 > 6.2831855f) {
            f20 -= 6.2831855f;
        }
        ohWait(1);
    }
    D_80382C48_523058 = 0.0f;
    omEndProcess(NULL);
}

void func_80350950_4F0D60(GObj* obj) {
    if (!D_80382D0C_52311C) {
        if ((gContInputPressedButtons & D_CBUTTONS) && Icons_NumItemsAvailable >= 3 && D_80382CB8_5230C8 == 0) {
            D_80382CF4_523104 = ITEM_ID_POKEFLUTE;
            D_80382CB8_5230C8 = 45;
            Icons_ProcessButtonPress(ITEM_ID_POKEFLUTE);
            Items_PlayPokeFlute();
        } else if (D_80382CB4_5230C4 == 0) {
            if ((gContInputPressedButtons & B_BUTTON) && Icons_NumItemsAvailable >= 2) {
                D_80382CF4_523104 = ITEM_ID_PESTER_BALL;
                D_80382CB4_5230C4 = 45;
                Items_SpawnPesterBall(&D_80382C30_523040->viewMtx.lookAt.eye, &D_80382CA0_5230B0);
                Icons_ProcessButtonPress(ITEM_ID_PESTER_BALL);
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                D_80382CB8_5230C8 = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) && Icons_NumItemsAvailable >= 1) {
                D_80382CF4_523104 = ITEM_ID_APPLE;
                D_80382CB4_5230C4 = 45;
                Items_SpawnApple(&D_80382C30_523040->viewMtx.lookAt.eye, &D_80382CA0_5230B0);
                Icons_ProcessButtonPress(ITEM_ID_APPLE);
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                D_80382CB8_5230C8 = 0;
            }
        }
    }
    if (D_80382CB4_5230C4 > 0) {
        D_80382CB4_5230C4--;
    }
    if (D_80382CB8_5230C8 > 0) {
        D_80382CB8_5230C8--;
    }
}

void func_80350AE8_4F0EF8(GObj* obj) {
    DObj* model = obj->data.dobj;

    if (ABS(gContInputStickX) >= 6 && !D_80382D0C_52311C) {
        D_80382CC0_5230D0 = (f32)gContInputStickX / 80.0;
        D_80382C28_523038 += 0.014f * D_80382CC0_5230D0;
        if (D_80382C28_523038 > 1.0f) {
            D_80382C28_523038 = 1.0f;
        } else if (D_80382C28_523038 < -1.0f) {
            D_80382C28_523038 = -1.0f;
        }
    } else {
        D_80382CC0_5230D0 = 0.0f;
        if (D_80382C28_523038 > 0.8) {
            D_80382C28_523038 -= 0.03;
        } else if (D_80382C28_523038 < -0.8) {
            D_80382C28_523038 += 0.03;
        }
    }

    if (ABS(gContInputStickY) >= 6 && !D_80382D0C_52311C) {
        D_80382CC4_5230D4 = (f32)gContInputStickY / 80.0;
        if (D_803AE521_54E931 == TRUE) {
            D_80382CC4_5230D4 = -D_80382CC4_5230D4;
        }

        if (D_80382CC4_5230D4 < 0.0f && D_80382C0C_52301C <= D_80382CF0_523100 + 0.017453292f ||
            D_80382CC4_5230D4 > 0.0f && D_80382C0C_52301C >= D_80382CEC_5230FC - 0.017453292f)
        {
            D_80382C2C_52303C += 0.02f * D_80382CC4_5230D4;
        }

        if (D_80382C2C_52303C > 0.2f) {
            D_80382C2C_52303C = 0.2f;
        } else if (D_80382C2C_52303C < -0.9f) {
            D_80382C2C_52303C = -0.9f;
        }

        if (D_80382CC4_5230D4 < 0.0f && D_80382C0C_52301C <= D_80382CF0_523100 ||
            D_80382CC4_5230D4 > 0.0f && D_80382C0C_52301C > D_80382CEC_5230FC)
        {
            D_80382C0C_52301C -= 0.015f * D_80382CC4_5230D4;
        }
    } else {
        if (D_80382C2C_52303C > 0.0) {
            D_80382C2C_52303C -= 0.03;
        } else if (D_80382C2C_52303C < -0.7) {
            D_80382C2C_52303C += 0.03;
        }
    }

    if (!(D_80382BFC_52300C < 0 || (D_80382BFC_52300C & 1))) {
    } else {
        if (ABS(D_80382CD4_5230E4) > 0.1f) {
            D_80382CD4_5230E4 -= SIGN(D_80382CD4_5230E4) * 0.1f;
        } else {
            D_80382CD4_5230E4 = 0.0f;
        }
    }

    if (!D_80382C64_523074) {
        D_80366BA4_506FB4.unk_04 += D_803AE47C_54E88C * 0.005f;
        if (D_80366BA4_506FB4.unk_04 > 1.0f) {
            D_80366BA4_506FB4.unk_04 = 1.0f;
        } else if (D_80366BA4_506FB4.unk_04 < 0.0f) {
            D_80366BA4_506FB4.unk_04 = 0.0f;
        }
        D_80366BA4_506FB4.unk_28 = D_80382C44_523054;
    } else {
        D_80366BA4_506FB4.unk_28 = 0.0f;
    }

    GET_TRANSFORM(model)->pos.v.x = D_80366BA4_506FB4.unk_0C.x;
    GET_TRANSFORM(model)->pos.v.y = D_80366BA4_506FB4.unk_0C.y;
    GET_TRANSFORM(model)->pos.v.z = D_80366BA4_506FB4.unk_0C.z;
    GET_TRANSFORM(model)->rot.f[1] = D_80366BA4_506FB4.unk_18.x;
    GET_TRANSFORM(model)->rot.f[2] = D_80366BA4_506FB4.unk_18.y + D_80382CD4_5230E4;
    GET_TRANSFORM(model)->rot.f[3] = D_80366BA4_506FB4.unk_18.z;

    Vec3fDiff(&D_80382CA0_5230B0, &GET_TRANSFORM(model)->pos.v, &D_80382C94_5230A4);

    D_80382C94_5230A4 = GET_TRANSFORM(model)->pos.v;

    if (D_80382D04_523114 == 1) {
        if (D_803AE520_54E930 == 1 && (gContInputPressedButtons & Z_TRIG) && D_80382BFC_52300C >= 0 ||
            D_803AE520_54E930 == 0 && (gContInputCurrentButtons & Z_TRIG) && D_80382BFC_52300C >= 0)
        {
            D_80382C3C_52304C = 0;
            auPlaySound(SOUND_ID_5);
            D_80382BFC_52300C = -2;
            omCreateProcess(obj, func_80351FF0_4F2400, 0, 9);
            ohPauseProcessByFunction(obj, func_803512FC_4F170C);
            ohPauseProcessByFunction(obj, func_80350950_4F0D60);
            ohPauseProcessByFunction(obj, func_80351768_4F1B78);
        }
    }
}

void func_80351114_4F1524(GObj* obj) {
    if (D_80382C44_523054 > 0.0f) {
        D_80382C44_523054 -= 0.0000025000002f;
    } else {
        D_80382C44_523054 = 0.0f;
    }
}

void func_80351158_4F1568(s32 arg0) {
    static s32 D_80382D4C_52315C = -1;
    if (arg0 == TRUE) {
        if (D_80382D4C_52315C == -1) {
            D_80382D4C_52315C = auPlaySound(SOUND_ID_14);
        }
    } else {
        if (D_80382D4C_52315C == -1) {
            return;
        }
        auStopSound(D_80382D4C_52315C);
        auPlaySound(SOUND_ID_15);
        D_80382D4C_52315C = -1;
        D_80382CBC_5230CC = 10;
    }
}

s32 D_80382D50_523160 = 0;
s32 D_80382D54_523164 = 100;

void func_803511DC_4F15EC(void) {
    D_80382C68_523078 = 1.0f;
    if (D_80382D0C_52311C == 0 && D_803AE522_54E932 == 1) {
        if ((gContInputCurrentButtons & R_TRIG) && D_803AE514_54E924 == 0) {
            D_80382C68_523078 *= 3.0f;
            Icons_SetDashEngineEnabled(TRUE);
            if (D_80382CBC_5230CC == 0) {
                func_80351158_4F1568(TRUE);
            }
        } else {
            func_80351158_4F1568(FALSE);
            D_80382D50_523160 = 0;
            Icons_SetDashEngineEnabled(FALSE);
        }
    }
    if (D_80382CBC_5230CC > 0) {
        D_80382CBC_5230CC--;
    }
    D_80382C44_523054 = D_80382C68_523078 * 0.0005f * (1.0f + D_803AE478_54E888 * 0.25f);
}

void func_803512FC_4F170C(GObj* obj) {
    s32 a1 = FALSE;

    if (D_80382BFC_52300C < 0) {
        return;
    }

    if (D_80382D0C_52311C == 0) {
        if (gContInputPressedButtons & U_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            if (D_80382BFC_52300C == 0) {
                D_80382CCC_5230DC = 0.2f;
            } else if (D_80382BFC_52300C == 1) {
                D_80382CCC_5230DC = 0.1f;
            } else {
                D_80382CCC_5230DC = -0.1f;
            }
            D_80382BFC_52300C = 2;
            a1 = TRUE;
            D_80382C14_523024 = 0;
        } else if (gContInputPressedButtons & R_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            D_80382BFC_52300C++;
            if (D_80382BFC_52300C >= 4) {
                D_80382BFC_52300C -= 4;
            }
            a1 = TRUE;
            D_80382CCC_5230DC = 0.1f;
            D_80382C14_523024 = 0;
        } else if (gContInputPressedButtons & L_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            D_80382BFC_52300C--;
            if (D_80382BFC_52300C < 0) {
                D_80382BFC_52300C += 4;
            }
            a1 = TRUE;
            D_80382CCC_5230DC = -0.1f;
            D_80382C14_523024 = 0;
        }
    }

    func_803511DC_4F15EC();
    if (a1) {
        D_80382C28_523038 = 0.0f;
        D_80382CC8_5230D8 = 0.0f;
        ohResumeProcessByFunction(obj, func_80351534_4F1944);
        ohPauseProcessByFunction(obj, func_80350224_4F0634);
        ohPauseProcessByFunction(obj, func_80350AE8_4F0EF8);
        ohPauseProcessByFunction(obj, func_803512FC_4F170C);
        return;
    }

    if (ABS(D_80382C14_523024) > 50) {
        D_80382CC8_5230D8 += D_80382CC0_5230D0 * 0.03 * 0.8;
    }
}

void func_80351534_4F1944(GObj* obj) {
    f32 sp1C;
    f32 f18;
    s32 v0 = 0;

    if (D_80382D20_523130 != 0) {
        return;
    }

    f18 = D_80382CD8_5230E8[D_80382BFC_52300C];
    sp1C = D_80382CD0_5230E0;

    while (f18 < 0.0f) {
        f18 += 6.2831855f;
    }
    while (f18 >= 6.2831855f) {
        f18 -= 6.2831855f;
    }

    while (sp1C < 0.0f) {
        sp1C += 6.2831855f;
    }
    while (sp1C >= 6.2831855f) {
        sp1C -= 6.2831855f;
    }

    if (ABS(f18 - sp1C) > ABS(D_80382CCC_5230DC)) {
        D_80382CD0_5230E0 += D_80382CCC_5230DC;
    } else {
        D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        v0++;
    }
    f18 = 0.04712389f; // need var reuse for matching
    if (ABS(D_80382C0C_52301C) > f18) {
        if (D_80382C0C_52301C > 0.0f) {
            D_80382C0C_52301C -= f18;
        } else {
            D_80382C0C_52301C += f18;
        }
    } else {
        D_80382C0C_52301C = 0.0f;
        v0++;
    }

    if (v0 >= 2) {
        D_80382CCC_5230DC = 0.0f;
        ohResumeProcessByFunction(obj, func_80350224_4F0634);
        ohResumeProcessByFunction(obj, func_80350AE8_4F0EF8);
        ohResumeProcessByFunction(obj, func_803512FC_4F170C);
        ohPauseProcessByFunction(obj, func_80351534_4F1944);
    }
}

static void nullsub(void) {

}

void func_80351768_4F1B78(GObj* obj) {
    f32 sp94;
    f32 unused1[6];
    Vec3f sp70;
    Vec3f sp64;
    f32 unused2[11];
    f32 dx, dz;
    f32 delta1;
    f32 oneHundred = 100.0f;

    static f32 D_80382D58_523168 = 0.0f;
    static f32 D_80382D5C_52316C = 50.0f;
    static f32 D_80382D60_523170 = 0.0f;
    static f32 D_80382D64_523174 = 50.0f;

    if (D_80382BFC_52300C == 0) {
        if (D_80382CC8_5230D8 > 0.9424779f) {
            D_80382BFC_52300C = 1;
            D_80382CC8_5230D8 = -0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        } else if (D_80382CC8_5230D8 < -0.9424779f) {
            D_80382BFC_52300C = 3;
            D_80382CC8_5230D8 = 0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        }
    } else if (D_80382BFC_52300C == 1) {
        if (D_80382CC8_5230D8 > 0.9424779f) {
            D_80382BFC_52300C = 2;
            D_80382CC8_5230D8 = -0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        } else if (D_80382CC8_5230D8 < -0.9424779f) {
            D_80382BFC_52300C = 0;
            D_80382CC8_5230D8 = 0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        }
    } else if (D_80382BFC_52300C == 2) {
        if (D_80382CC8_5230D8 > 0.9424779f) {
            D_80382BFC_52300C = 3;
            D_80382CC8_5230D8 = -0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        } else if (D_80382CC8_5230D8 < -0.9424779f) {
            D_80382BFC_52300C = 1;
            D_80382CC8_5230D8 = 0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        }
    } else if (D_80382BFC_52300C == 3) {
        if (D_80382CC8_5230D8 > 0.9424779f) {
            D_80382BFC_52300C = 0;
            D_80382CC8_5230D8 = -0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        } else if (D_80382CC8_5230D8 < -0.9424779f) {
            D_80382BFC_52300C = 2;
            D_80382CC8_5230D8 = 0.62831855f;
            D_80382CD0_5230E0 = D_80382CD8_5230E8[D_80382BFC_52300C];
        }
    }

    if (D_80382BFC_52300C == 0) {
        D_80382CC0_5230D0 *= -1.0f;
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    } else if (D_80382BFC_52300C == 1) {
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    } else if (D_80382BFC_52300C == 2) {
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    } else if (D_80382BFC_52300C == 3) {
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    }

    sp94 = D_80382CD0_5230E0 + D_80382CC8_5230D8;
    D_803AE478_54E888 = cosf(sp94);
    D_803AE47C_54E88C = sinf(sp94);

    if (D_80382C64_523074 == 0) {
        D_80382C44_523054 = D_80382C68_523078 * 0.0005f * (1.0f + D_803AE478_54E888 * 0.25f);
    }

    if (ABS(D_80382D60_523170 - D_80382D58_523168) > 0.2f) {
        D_80382D58_523168 += SIGN(D_80382D60_523170 - D_80382D58_523168) * 0.2f;
    } else {
        D_80382D58_523168 = D_80382D60_523170;
    }

    if (ABS(D_80382D64_523174 - D_80382D5C_52316C) > 0.2f) {
        D_80382D5C_52316C += SIGN(D_80382D64_523174 - D_80382D5C_52316C) * 0.2f;
        D_80382D64_523174 = D_80382D64_523174;
    } else {
        D_80382D5C_52316C = D_80382D64_523174;
        D_80382D64_523174 = D_80382D64_523174;
    }

    sinf(D_80366BA4_506FB4.unk_18.y);
    cosf(D_80366BA4_506FB4.unk_18.y);

    sp70.x = D_803AE410_54E820.x = D_80366BA4_506FB4.unk_0C.x;
    sp70.y = D_803AE410_54E820.y = D_80366BA4_506FB4.unk_0C.y + oneHundred + D_80382C48_523058 + D_80382C58_523068;
    sp70.z = D_803AE410_54E820.z = D_80366BA4_506FB4.unk_0C.z;

    sp64.x = -20.0f * cosf(D_80382C0C_52301C) * sinf(sp94);
    sp64.y = 20.0f * sinf(D_80382C0C_52301C);
    sp64.z = 20.0f * cosf(D_80382C0C_52301C) * cosf(sp94);

    Vec3fGetEulerRotation(&sp64, AXIS_X, D_80366BA4_506FB4.unk_18.x);
    Vec3fGetEulerRotation(&sp64, AXIS_Y, D_80366BA4_506FB4.unk_18.y);
    Vec3fGetEulerRotation(&sp64, AXIS_Z, D_80366BA4_506FB4.unk_18.z);

    D_803AE420_54E830.x = sp64.x + sp70.x;
    D_803AE420_54E830.y = sp64.y + sp70.y;
    D_803AE420_54E830.z = sp64.z + sp70.z;

    dx = D_803AE420_54E830.x - D_803AE410_54E820.x;
    dz = D_803AE420_54E830.z - D_803AE410_54E820.z;
    if (SQ(dx) + SQ(dz) < 0.1f) {
        D_803AE420_54E830.x = D_803AE410_54E820.x + D_803AE430_54E840.x;
        D_803AE420_54E830.z = D_803AE410_54E820.z + D_803AE430_54E840.z;
    } else {
        D_803AE430_54E840.x = dx;
        D_803AE430_54E840.z = dz;
    }

    D_80382C30_523040->viewMtx.lookAt.eye.x = D_803AE410_54E820.x;
    D_80382C30_523040->viewMtx.lookAt.eye.y = D_803AE410_54E820.y;
    D_80382C30_523040->viewMtx.lookAt.eye.z = D_803AE410_54E820.z;
    D_80382C30_523040->viewMtx.lookAt.at.x = D_803AE420_54E830.x;
    D_80382C30_523040->viewMtx.lookAt.at.y = D_803AE420_54E830.y;
    D_80382C30_523040->viewMtx.lookAt.at.z = D_803AE420_54E830.z;
}

char D_80382D68_523178[] = "\\#S0\\[\\]\\#S1";
s32 D_80382D78_523188 = 0;


void func_80351E8C_4F229C(Vec3f* arg0) {
    f32 sin;
    f32 cos;
    f32 x;
    f32 y;
    f32 z;

    x = arg0->x - D_80366BA4_506FB4.unk_0C.x;
    y = arg0->y - D_80366BA4_506FB4.unk_0C.y;
    z = arg0->z - D_80366BA4_506FB4.unk_0C.z;
    sin = sinf(-D_80366BA4_506FB4.unk_18.y);
    cos = cosf(-D_80366BA4_506FB4.unk_18.y);
    arg0->x = (x * cos) + (z * sin);
    arg0->y = y;
    arg0->z = (z * cos) - (x * sin);
}

void func_80351F44_4F2354(Vec3f* arg0) {
    f32 sp2C, sp28;
    f32 x, y, z;

    x = arg0->x;
    y = arg0->y;
    z = arg0->z;
    sp2C = sinf(D_80366BA4_506FB4.unk_18.y);
    sp28 = cosf(D_80366BA4_506FB4.unk_18.y);

    arg0->x = x * sp28 + z * sp2C + D_80366BA4_506FB4.unk_0C.x;
    arg0->y = y + D_80366BA4_506FB4.unk_0C.y;
    arg0->z = z * sp28 - x * sp2C + D_80366BA4_506FB4.unk_0C.z;
}

void func_80351FF0_4F2400(GObj* obj) {
    s32 unused1;
    s32 i;
    f32 sp114;
    f32 sp110;
    s32 unused2[6];
    Vec3f spEC;
    Vec3f spE0;
    Vec3f spD4;
    f32 f28;
    s32 y1, y2;
    s32 x1, x2;
    s32 unused3;
    f32 dx, dy, dz;
    s32 y3, y4;
    s32 x3, x4;
    f32 sinAngle, cosAngle;
    s32 unused4[4];
    f32 dx2, dz2;

    i = 0;

    Icons_ProcessZoom(TRUE);

    y1 = 0;
    y2 = SCREEN_HEIGHT;
    x1 = 0;
    x2 = SCREEN_WIDTH;
    y3 = 0;
    y4 = SCREEN_HEIGHT;
    x3 = 0;
    x4 = SCREEN_WIDTH;

    D_803AE4F8_54E908.x = 0.0f;
    D_803AE4F8_54E908.y = 100.0f;
    D_803AE4F8_54E908.z = 0.0f;
    func_80351F44_4F2354(&D_803AE4F8_54E908);

    dx = D_80382C1C_52302C - D_803AE4F8_54E908.x;
    dy = D_80382C20_523030 - D_803AE4F8_54E908.y;
    dz = D_80382C24_523034 - D_803AE4F8_54E908.z;
    f28 = sqrtf(SQ(dx) + SQ(dz));
    sinAngle = sinf(-D_80366BA4_506FB4.unk_18.y);
    cosAngle = cosf(-D_80366BA4_506FB4.unk_18.y);

    spD4.x = dx * cosAngle + dz * sinAngle;
    spD4.y = dy;
    spD4.z = dz * cosAngle - dx * sinAngle;

    D_80382CC8_5230D8 = atanf(spD4.x / spD4.z);
    D_80382C0C_52301C = atanf(spD4.y / f28);
    if (spD4.z > 0.0f) {
        D_80382CC8_5230D8 = 6.2831855f - D_80382CC8_5230D8;
    } else {
        D_80382CC8_5230D8 = 3.1415927f - D_80382CC8_5230D8;
    }
    if (D_80382CC8_5230D8 > 6.2831855f) {
        D_80382CC8_5230D8 -= 6.2831855f;
    } else if (D_80382CC8_5230D8 < 0.0f) {
        D_80382CC8_5230D8 += 6.2831855f;
    }

    D_803AE4F8_54E908.x = 0.0f;
    D_803AE4F8_54E908.y = 100.0f;
    D_803AE4F8_54E908.z = 0.0f;

    spD4.x = D_80382C1C_52302C;
    spD4.y = D_80382C20_523030;
    spD4.z = D_80382C24_523034;
    func_80351E8C_4F229C(&spD4);
    spD4.x -= D_803AE4F8_54E908.x;
    spD4.y -= D_803AE4F8_54E908.y;
    spD4.z -= D_803AE4F8_54E908.z;
    Vec3fNormalize(&spD4);

    D_803AE508_54E918.x = 20.0f * spD4.x + D_803AE4F8_54E908.x;
    D_803AE508_54E918.y = 20.0f * spD4.y + D_803AE4F8_54E908.y;
    D_803AE508_54E918.z = 20.0f * spD4.z + D_803AE4F8_54E908.z;
    D_803AE4D8_54E8E8.x = D_803AE410_54E820.x;
    D_803AE4D8_54E8E8.y = D_803AE410_54E820.y;
    D_803AE4D8_54E8E8.z = D_803AE410_54E820.z;
    D_803AE4E8_54E8F8.x = D_803AE420_54E830.x;
    D_803AE4E8_54E8F8.y = D_803AE420_54E830.y;
    D_803AE4E8_54E8F8.z = D_803AE420_54E830.z;
    func_80351E8C_4F229C(&D_803AE4D8_54E8E8);
    func_80351E8C_4F229C(&D_803AE4E8_54E8F8);

    spEC.x = D_803AE4F8_54E908.x - D_803AE4D8_54E8E8.x;
    spEC.y = D_803AE4F8_54E908.y - D_803AE4D8_54E8E8.y;
    spEC.z = D_803AE4F8_54E908.z - D_803AE4D8_54E8E8.z;
    sp114 = Vec3fNormalize(&spEC) / 10.0f;
    spE0.x = D_803AE508_54E918.x - D_803AE4E8_54E8F8.x;
    spE0.y = D_803AE508_54E918.y - D_803AE4E8_54E8F8.y;
    spE0.z = D_803AE508_54E918.z - D_803AE4E8_54E8F8.z;
    sp110 = Vec3fNormalize(&spE0) / 10.0f;

    while (TRUE) {
        if (D_803AE520_54E930 == 0 && (gContInputReleasedButtons & Z_TRIG)) {
            break;
        }

        sinAngle = sinf(D_80366BA4_506FB4.unk_18.y);
        cosAngle = cosf(D_80366BA4_506FB4.unk_18.y);

        D_803AE4D8_54E8E8.x += sp114 * spEC.x;
        D_803AE4D8_54E8E8.y += sp114 * spEC.y;
        D_803AE4D8_54E8E8.z += sp114 * spEC.z;

        D_803AE410_54E820.x = D_80366BA4_506FB4.unk_0C.x + D_803AE4D8_54E8E8.x * cosAngle + D_803AE4D8_54E8E8.z * sinAngle;
        D_803AE410_54E820.y = D_80366BA4_506FB4.unk_0C.y + D_803AE4D8_54E8E8.y;
        D_803AE410_54E820.z = D_80366BA4_506FB4.unk_0C.z - D_803AE4D8_54E8E8.x * sinAngle + D_803AE4D8_54E8E8.z * cosAngle;

        D_803AE4E8_54E8F8.x += sp110 * spE0.x;
        D_803AE4E8_54E8F8.y += sp110 * spE0.y;
        D_803AE4E8_54E8F8.z += sp110 * spE0.z;

        D_803AE420_54E830.x = D_80366BA4_506FB4.unk_0C.x + D_803AE4E8_54E8F8.x * cosAngle + D_803AE4E8_54E8F8.z * sinAngle;
        D_803AE420_54E830.y = D_80366BA4_506FB4.unk_0C.y + D_803AE4E8_54E8F8.y;
        D_803AE420_54E830.z = D_80366BA4_506FB4.unk_0C.z - D_803AE4E8_54E8F8.x * sinAngle + D_803AE4E8_54E8F8.z * cosAngle;

        dx2 = D_803AE420_54E830.x - D_803AE410_54E820.x;
        dz2 = D_803AE420_54E830.z - D_803AE410_54E820.z;
        if ((SQ(dx2) + SQ(dz2)) < 0.1f) {
            D_803AE420_54E830.x = D_803AE410_54E820.x + D_803AE430_54E840.x;
            D_803AE420_54E830.z = D_803AE410_54E820.z + D_803AE430_54E840.z;
        } else {
            D_803AE430_54E840.x = dx2;
            D_803AE430_54E840.z = dz2;
        }

        x1 -= 2;
        y1 -= 2;
        x2 += 2;
        y2 += 2;

        D_80382C30_523040->viewMtx.lookAt.eye.x = D_803AE410_54E820.x;
        D_80382C30_523040->viewMtx.lookAt.eye.y = D_803AE410_54E820.y + D_80382C58_523068;
        D_80382C30_523040->viewMtx.lookAt.eye.z = D_803AE410_54E820.z;
        D_80382C30_523040->viewMtx.lookAt.at.x = D_803AE420_54E830.x;
        D_80382C30_523040->viewMtx.lookAt.at.y = D_803AE420_54E830.y + D_80382C58_523068;
        D_80382C30_523040->viewMtx.lookAt.at.z = D_803AE420_54E830.z;

        func_80007C20(&D_80382C30_523040->vp, x1, y1, x2, y2);

        x3 += 3;
        y3 += 2;
        x4 -= 3;
        y4 -= 2;

        D_80382C30_523040->perspMtx.persp.aspect = (f32)(x2 - x1) / (f32)(y2 - y1);
        D_80382C30_523040->perspMtx.persp.fovy = 55.0f - i * 1.5f;

        func_80357D18_4F8128(x3, y3, x4, y4);
        i++;
        ohWait(1);
        if (D_803AE520_54E930 == 1 && (gContInputPressedButtons & Z_TRIG)) {
            break;
        }

        func_803511DC_4F15EC();
        if (i >= 10) {
            break;
        }
    }

    D_80382BFC_52300C = -1;
    D_80382C4C_52305C = 0;
    omCreateProcess(obj, func_80353180_4F3590, 1, 9);
    omEndProcess(NULL);
}

void func_8035275C_4F2B6C(GObj* arg0) {
    f32 unused3;
    f32 angle1;
    s32 x2, y2, x1, y1;
    s32 var_s1;
    Vec3f spE8;
    s32 unused[13];
    s32 y3, y4, x3, x4;
    f32 temp_f14;
    f32 temp_f18;
    f32 temp_f20;
    f32 dx;
    f32 dz;
    s32 unused2[2];
    s32 i = 0;

    auPlaySound(6);
    D_80382CF8_523108 = 0;
    D_80382CFC_52310C = 0;
    D_80382C28_523038 = 0.0f;

    y1 = -25;
    y2 = 265;
    x1 = -25;
    x2 = 345;

    y3 = 22;
    y4 = 216;
    x3 = 30;
    x4 = 289;
    D_80382C2C_52303C = 0.0f;
    
    while (i++ < 10) {
        if (D_803AE520_54E930 == 0 && (gContInputPressedButtons & 0x2000)) { break; }

        temp_f14 = D_80366BA4_506FB4.unk_0C.x - D_803AE410_54E820.x;
        temp_f18 = D_80366BA4_506FB4.unk_0C.y + 100.0f + D_80382C48_523058 - D_803AE410_54E820.y;
        temp_f20 = D_80366BA4_506FB4.unk_0C.z - D_803AE410_54E820.z;

        D_803AE410_54E820.x = D_80366BA4_506FB4.unk_0C.x;        
        D_803AE410_54E820.y = D_80366BA4_506FB4.unk_0C.y + 100.0f + D_80382C48_523058;
        D_803AE410_54E820.z = D_80366BA4_506FB4.unk_0C.z;

        D_803AE420_54E830.x += temp_f14;
        D_803AE420_54E830.y += temp_f18;
        D_803AE420_54E830.z += temp_f20;

        dx = D_803AE420_54E830.x - D_803AE410_54E820.x;
        dz = D_803AE420_54E830.z - D_803AE410_54E820.z;
        if (SQ(dx) + SQ(dz) < 0.1f) {
            D_803AE420_54E830.x = D_803AE410_54E820.x + D_803AE430_54E840.x;
            D_803AE420_54E830.z = D_803AE410_54E820.z + D_803AE430_54E840.z;
        } else {
            D_803AE430_54E840.x = dx;
            D_803AE430_54E840.z = dz;
        }

        D_80382C30_523040->viewMtx.lookAt.eye.x = D_803AE410_54E820.x;
        D_80382C30_523040->viewMtx.lookAt.eye.y = D_803AE410_54E820.y;        
        D_80382C30_523040->viewMtx.lookAt.eye.z = D_803AE410_54E820.z;
        D_80382C30_523040->viewMtx.lookAt.at.x = D_803AE420_54E830.x;
        D_80382C30_523040->viewMtx.lookAt.at.y = D_803AE420_54E830.y;
        D_80382C30_523040->viewMtx.lookAt.at.z = D_803AE420_54E830.z;
        D_80382C30_523040->viewMtx.lookAt.eye.y += D_80382C58_523068;
        D_80382C30_523040->viewMtx.lookAt.at.y += D_80382C58_523068;

        x1 += 2;
        y1 += 2;
        x2 -= 2;
        y2 -= 2;
        func_80007C20(&D_80382C30_523040->vp, x1, y1, x2, y2);

        D_80382C30_523040->perspMtx.persp.aspect = (f32) (x2 - x1) / (f32) (y2 - y1);
        D_80382C30_523040->perspMtx.persp.fovy = 55.0f - (10.0f - i) * 1.5f;

        y4 += 2;
        x4 += 3;
        y3 -= 2;
        x3 -= 3;
        func_80357D18_4F8128(x3, y3, x4, y4);
        ohWait(1);
        if (D_803AE520_54E930 == 1 && (gContInputPressedButtons & 0x2000)) {
            break;
        }
        func_803511DC_4F15EC();
    }

    func_803573BC_4F77CC();
    spE8.x = D_803AE420_54E830.x - D_803AE410_54E820.x;
    spE8.y = D_803AE420_54E830.y - D_803AE410_54E820.y;
    spE8.z = D_803AE420_54E830.z - D_803AE410_54E820.z;
    Vec3fNormalize(&spE8);
    Vec3fGetEulerRotation(&spE8, 4, -D_80366BA4_506FB4.unk_18.z);
    Vec3fGetEulerRotation(&spE8, 2, -D_80366BA4_506FB4.unk_18.y);
    Vec3fGetEulerRotation(&spE8, 1, -D_80366BA4_506FB4.unk_18.x);
    D_80382C0C_52301C = asinf(spE8.y);
    angle1 = acosf(spE8.z / cosf(D_80382C0C_52301C));
    if (spE8.x > 0.0f) {
        angle1 = 6.2831855f - angle1;
    }
    
    if (angle1 < 0.7853982f) {
        var_s1 = 2;
    } else if (angle1 < 2.3561945f) {
        var_s1 = 3;
    } else if (angle1 < 3.926991f) {
        var_s1 = 0;
    } else if (angle1 < 5.4977875f) {
        var_s1 = 1;
    } else {
        var_s1 = 2;
    }

    D_80382CD0_5230E0 = D_80382CD8_5230E8[var_s1];
    if (D_80382CD0_5230E0 < 0.0f) {
        D_80382CD0_5230E0 += 6.2831855f;
    }
    if (var_s1 == 2) {
        if (angle1 > 3.1415927f) {
            D_80382CC8_5230D8 = angle1 - 6.2831855f;
        } else {
            D_80382CC8_5230D8 = angle1;
        }
        D_80382CD0_5230E0 = D_80382CD8_5230E8[var_s1];
    } else {
        D_80382CC8_5230D8 = angle1 - D_80382CD0_5230E0;
        D_80382CD0_5230E0 = D_80382CD8_5230E8[var_s1];
    }
    D_80382C30_523040->viewMtx.lookAt.eye.x = D_803AE410_54E820.x;
    D_80382C30_523040->viewMtx.lookAt.eye.y = D_803AE410_54E820.y + D_80382C58_523068;
    D_80382C30_523040->viewMtx.lookAt.eye.z = D_803AE410_54E820.z;
    D_80382C30_523040->viewMtx.lookAt.at.x = D_803AE420_54E830.x;
    D_80382C30_523040->viewMtx.lookAt.at.y = D_803AE420_54E830.y + D_80382C58_523068;
    D_80382C30_523040->viewMtx.lookAt.at.z = D_803AE420_54E830.z;
    Icons_ProcessZoom(FALSE);
    D_80382C14_523024 = 0;
    D_80382BFC_52300C = var_s1;
    ohResumeProcessByFunction(arg0, func_803512FC_4F170C);
    ohResumeProcessByFunction(arg0, func_80350950_4F0D60);
    ohResumeProcessByFunction(arg0, func_80351768_4F1B78);
    omEndProcess(0);
}

s32 func_80352DC8_4F31D8(u8* arg0, u8* arg1) {
    if (arg0 == NULL || arg1 == NULL) {
        return 0;
    }

    while (TRUE) {
        s32 diff = *arg0 - *arg1;
        if (diff != 0) {
            return diff;
        }
        if (*arg0 == 0 || *arg1 == 0) {
            break;
        }
        arg0++;
        arg1++;
    }
    return 0;
}

void func_80352E24_4F3234(s32 pokemonID, s32 arg1, s32* arg2) {
    char sp40[32];
    char* pokemonName;

    if (D_803AE516_54E926 != 0) {
        return;
    }

    if (arg1 == 0) {
        if (*arg2 == 0) {
            *arg2 = 1;
            func_80365E34_506244();
        }
    } else if (*arg2 != 0) {
        *arg2 = 0;
        pokemonName = getPokemonName(pokemonID);
        if (pokemonName != NULL) {
            if (func_80350200_4F0610(pokemonID) && func_80352DC8_4F31D8(pokemonName, "？")) {
                sprintf(sp40, "%s%s", pokemonName, D_80382D68_523178);
                pokemonName = sp40;
            }
        } else {
            pokemonName = "？";
        }
        func_80365BB0_505FC0(pokemonName, 160, 200, 255, 255, 255, 255, 0, 2);
    }
}

void func_80352F20_4F3330(GObj* arg0) {
    s32 i;
    s32 pokemonID;
    s32 sp3C;

    pokemonID = D_803AE408_54E818;
    sp3C = 0;

    if (pokemonID != 0) {
        if (func_80350200_4F0610(pokemonID)) {
            auPlaySound(SOUND_ID_2);
        }

        for (i = 48; i > 0; i--) {
            if (D_803AE408_54E818 != pokemonID ||
               D_803AE520_54E930 == 0 && !(gContInputCurrentButtons & Z_TRIG) ||
               D_803AE520_54E930 == 1 && (gContInputPressedButtons & Z_TRIG))
            {
                goto END;
            }
            func_80352E24_4F3234(pokemonID, i & 0xC, &sp3C);
            ohWait(1);
        }

        func_80352E24_4F3234(pokemonID, 1, &sp3C);

        for (i = 60; i > 0; i--) {
            if (D_803AE408_54E818 != pokemonID ||
               D_803AE520_54E930 == 0 && !(gContInputCurrentButtons & Z_TRIG) ||
               D_803AE520_54E930 == 1 && (gContInputPressedButtons & Z_TRIG))
            {
                goto END;
            }
            ohWait(1);
        }
    }
END:
    if (D_803AE516_54E926 == 0) {
        if (&sp3C) {
        } // required to match
        func_80365E34_506244();
    }
    omEndProcess(NULL);
}

void func_803530B4_4F34C4(GObj* obj, GObjFunc func) {
    GObjProcess* proc;
    GObjProcess* next;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        next = proc->next;
        if (func == proc->function) {
            omEndProcess(proc);
        }
        proc = next;
    }
}

void func_80353118_4F3528(GObj* obj) {
    if (D_80382D20_523130 == 0 && D_80382D44_523154 == 0 && D_80382D78_523188 != gtlDrawnFrameCounter) {
        spSetAttribute(&D_80382C6C_52307C->data.sobj->sprite, SP_HIDDEN);
    }
}

void func_80353180_4F3590(GObj* arg0) {
    s32 unused[2];
    f32 sp64, sp60;
    Vec3f unused2;
    Vec3f sp48;
    f32 temp_f2;
    f32 sp40;
    f32 sp3C;
    s32 sp38;
    GObj* temp_v0;
    f32 temp_f16;    
    f32 var_f14;

    static s32 D_80382D7C_52318C = -1;

    if (D_80382D08_523118 == 0) {
        if (D_80382C4C_52305C == 1) {
            D_80382CC8_5230D8 += 0.1f;
            if (D_80382C50_523060 < D_80382CC8_5230D8) {
                D_80382C4C_52305C = 0;
                D_80382CC8_5230D8 = D_80382C50_523060;
            }
        } else if (D_80382C4C_52305C == 2) {
            D_80382CC8_5230D8 -= 0.1f;
            if (D_80382CC8_5230D8 < D_80382C50_523060) {
                D_80382C4C_52305C = 0;
                D_80382CC8_5230D8 = D_80382C50_523060;
            }
        } else {
            D_80382CC8_5230D8 = D_80382CC8_5230D8 + D_80382CC0_5230D0 * 0.025;
            if (D_80382CC8_5230D8 > 6.2831855f) {
                D_80382CC8_5230D8 -= 6.2831855f;
            } else if (D_80382CC8_5230D8 < 0.0f) {
                D_80382CC8_5230D8 += 6.2831855f;
            }
        }
        sp64 = sinf(D_80366BA4_506FB4.unk_18.y);
        sp60 = cosf(D_80366BA4_506FB4.unk_18.y);
        
        sp48.x = D_803AE410_54E820.x = D_80366BA4_506FB4.unk_0C.x;
        sp48.y = D_803AE410_54E820.y = D_80366BA4_506FB4.unk_0C.y + 100.0f + D_80382C58_523068;
        sp48.z = D_803AE410_54E820.z = D_80366BA4_506FB4.unk_0C.z;

        sp3C = -20.0f * cosf(D_80382C0C_52301C) * sinf(D_80382CC8_5230D8);
        sp40 = 20.0f * sinf(D_80382C0C_52301C);
        temp_f2 = 20.0f * cosf(D_80382C0C_52301C) * cosf(D_80382CC8_5230D8);

        D_803AE420_54E830.x = sp3C * sp60 + temp_f2 * sp64 + sp48.x;
        D_803AE420_54E830.y = sp40 + sp48.y;
        D_803AE420_54E830.z = temp_f2 * sp60 - sp3C * sp64 + sp48.z;

        var_f14 = D_803AE420_54E830.x - D_803AE410_54E820.x;        
        temp_f16 = D_803AE420_54E830.z - D_803AE410_54E820.z;
        if (SQ(var_f14) + SQ(temp_f16) < 0.1f) {
            D_803AE420_54E830.x = D_803AE410_54E820.x + D_803AE430_54E840.x;
            D_803AE420_54E830.z = D_803AE410_54E820.z + D_803AE430_54E840.z;
        } else {
            D_803AE430_54E840.x = var_f14;
            D_803AE430_54E840.z = temp_f16;
        }

        D_80382C30_523040->viewMtx.lookAt.eye.x = D_803AE410_54E820.x;
        D_80382C30_523040->viewMtx.lookAt.eye.y = D_803AE410_54E820.y;        
        D_80382C30_523040->viewMtx.lookAt.eye.z = D_803AE410_54E820.z;
        D_80382C30_523040->viewMtx.lookAt.at.x = D_803AE420_54E830.x;
        D_80382C30_523040->viewMtx.lookAt.at.y = D_803AE420_54E830.y;
        D_80382C30_523040->viewMtx.lookAt.at.z = D_803AE420_54E830.z;
    }
    if (D_803AE520_54E930 == 1 || (gContInputCurrentButtons & 0x2000)) {
        if (D_803AE768_54EB78 == 1 && D_803AE76C_54EB7C != NULL && GET_POKEMON(D_803AE76C_54EB7C) == NULL) {
            D_803AE768_54EB78 = 0;
        }
        if (D_803AE768_54EB78 == 1 && (D_803AE774_54EB84 & 4)) {
            if (D_80382C40_523050 == D_803AE76C_54EB7C) {
                D_80382CF8_523108++;
            } else {
                D_80382CF8_523108 = 0;
                D_80382C3C_52304C = 0;
            }
            D_80382CFC_52310C = 2;
            if ((D_80382C3C_52304C == 0 || D_803AE474_54E884 != (D_803AE774_54EB84 & 8)) && D_80382BFC_52300C == -1) {
                omCreateProcess(D_80382C38_523048, func_80356074_4F6484, 0, 9);
                auPlaySound(1);
                D_80382C3C_52304C = 1;
                D_80382C40_523050 = D_803AE76C_54EB7C;
                D_803AE470_54E880 = D_803AE770_54EB80;
                D_803AE474_54E884 = D_803AE774_54EB84 & 8;
            }
        } else if (D_80382CFC_52310C != 0) {
            D_80382CFC_52310C--;
        } else {
            D_80382CF8_523108 = 0;
            D_80382C3C_52304C = 0;
        }
        if (D_80382D7C_52318C < 0) {
            if (D_80382C4C_52305C == 0 && (gContInputPressedButtons & 0x8000)) {
                temp_v0 = ohFindByLinkAndId(0, 1);
                if (temp_v0 != NULL) {
                    if (D_80382D00_523110 == 2) {
                        spColor(&D_80382C6C_52307C->data.sobj->sprite, 0, 0, 0, D_80382D54_523164);
                        spClearAttribute(&D_80382C6C_52307C->data.sobj->sprite, SP_HIDDEN);
                        D_80382D78_523188 = gtlDrawnFrameCounter;
                    } else if (D_80382D00_523110 == 1) {
                        cmdSendCommand(temp_v0, 1, 0);
                    }
                }
                if (func_8035E508_4FE918() > 0) {
                    if (func_8035E508_4FE918() > 10) {
                        auPlaySound(0);
                    } else {
                        auPlaySound(0x10);
                    }
                    cmdSendCommandToLink(3, 18, arg0);
                    if (D_803AE768_54EB78 != 0 && D_803AE76C_54EB7C != NULL) {
                        cmdSendCommand(D_803AE76C_54EB7C, 24, arg0);
                    }
                    D_803AEF30_54F340 = D_803AEF38_54F348;
                    if (D_803AE768_54EB78 != 0 && (D_803AE774_54EB84 & 4)) {
                        func_8009C9E8(D_803AE76C_54EB7C);
                        sp38 = D_803AE770_54EB80;
                        if (D_803AE774_54EB84 & 8) {
                            sp38 = 500;
                        }
                    } else {
                        func_8009C9E8(NULL);
                        sp38 = 0;
                    }

                    func_803530B4_4F34C4(arg0, func_80352F20_4F3330);
                    D_803AE408_54E818 = sp38;
                    omCreateProcess(arg0, func_80352F20_4F3330, 0, 9);
                    if (D_803AE768_54EB78 != 0 && D_803AE76C_54EB7C != NULL) {
                        GET_POKEMON(D_803AE76C_54EB7C)->flags |= 0x80;
                    }
                    if (func_8035E52C_4FE93C() == 0) {
                        omCreateProcess(arg0, func_80355860_4F5C70, 0, 9);
                        omEndProcess(0);
                    }
                    Icons_ProcessTakePhotoPressed();
                }
                D_80382D7C_52318C = D_80366BA0_506FB0;
            }
        } else {
            D_80382D7C_52318C--;
        }
        if (D_80382D0C_52311C == 0) {
            func_803511DC_4F15EC();
            if (gContInputPressedButtons & 8) {
                auPlaySound(4);
                if (D_80382CC8_5230D8 > 3.1415927f) {
                    D_80382C4C_52305C = 1;
                    D_80382C50_523060 = 6.2831855f;
                } else {
                    D_80382C4C_52305C = 2;
                    D_80382C50_523060 = 0.0f;
                }
            } else if (gContInputPressedButtons & 1) {
                auPlaySound(4);
                D_80382C4C_52305C = 1;
                if (D_80382CC8_5230D8 > 6.282185482025146) {
                    D_80382CC8_5230D8 -= 6.2831855f;
                    D_80382C50_523060 = 1.5707964f;
                } else if (D_80382CC8_5230D8 > 4.7023889923095705) {
                    D_80382C50_523060 = 6.2831855f;
                } else if (D_80382CC8_5230D8 > 3.1315927410125735) {
                    D_80382C50_523060 = 4.712389f;
                } else if (D_80382CC8_5230D8 > 1.5607963705062866) {
                    D_80382C50_523060 = 3.1415927f;
                } else {
                    D_80382C50_523060 = 1.5707964f;
                }
            } else if (gContInputPressedButtons & 2) {
                auPlaySound(4);
                D_80382C4C_52305C = 2;
                if (D_80382CC8_5230D8 < 0.001f) {
                    D_80382CC8_5230D8 += 6.2831855f;
                    D_80382C50_523060 = 4.712389f;
                } else if (D_80382CC8_5230D8 < 1.5717964f) {
                    D_80382C50_523060 = 0.0f;
                } else if (D_80382CC8_5230D8 < 3.1425927f) {
                    D_80382C50_523060 = 1.5707964f;
                } else if (D_80382CC8_5230D8 < 4.713389f) {
                    D_80382C50_523060 = 3.1415927f;
                } else {
                    D_80382C50_523060 = 4.712389f;
                }
            }
        }
        if (D_803AE520_54E930 != 1 || !(gContInputPressedButtons & 0x2000)) {
            return;
        }
    }

    D_80382BFC_52300C = -2;
    D_80382D7C_52318C = -1;
    omCreateProcess(arg0, func_8035275C_4F2B6C, 0, 9);
    omEndProcess(NULL);
}

s32 D_80382D80_523190 = 0;
GObjFunc D_80382D84_523194[] = {
    func_80351534_4F1944,
    func_80350224_4F0634,
    func_80350AE8_4F0EF8,
    func_803512FC_4F170C,
    func_80350950_4F0D60,
    NULL,
};
s32 D_80382D9C_5231AC = 0;
s32 D_80382DA0_5231B0 = 0;
s32 D_80382DA4_5231B4 = 0;
s32 D_80382DA8_5231B8 = 0;
s32 D_80382DAC_5231BC = 0;
s32 D_80382DB0_5231C0 = 0;

void func_80353BCC_4F3FDC(GObj* obj) {
    f32 f20 = 0.0f;
    f32 sp58;
    s32 sp54;
    s32 levelID = getLevelId();

    if (levelID == SCENE_BEACH) {
        while (TRUE) {
            func_80357384_4F7794(&sp54, &sp58);
            if (sp54 + sp58 >= 4.15f) {
                break;
            }
            ohWait(1);
        }
    }

    while (TRUE) {
        D_80382C58_523068 = sinf(f20) * D_80382C5C_52306C;
        f20 += D_80382C60_523070 * 3.1415927f / 180.0f;
        if (levelID == SCENE_BEACH) {
            func_80357384_4F7794(&sp54, &sp58);
            if (sp54 + sp58 >= 4.45f) {
                break;
            }
        }
        ohWait(1);
    }

    D_80382C58_523068 = 0.0f;
    omEndProcess(NULL);
}

void func_80353D50_4F4160(void (*arg0)(s32)) {
    D_80382D18_523128 = arg0;
}

void func_80353D5C_4F416C(void (*arg0)(s32)) {
    D_80382D1C_52312C = arg0;
}

// `int` is required to match
int func_80353D68_4F4178(void) {
    return D_80382D20_523130 == 0 && D_80382D44_523154 == 0;
}

void func_80353D90_4F41A0(GObj* obj) {
    if (D_80382D40_523150 > 0) {
        D_80382D80_523190 = FALSE;
    } else if (ABS(gContInputStickY) > 20 && D_80382D80_523190) {
        D_80382D80_523190 = FALSE;
        if (gContInputStickY > 0) {
            if (D_80382D24_523134 > 0) {
                D_80382D24_523134--;
                auPlaySound(SOUND_ID_65);
            }
        } else {
            if (D_80382D24_523134 < 2) {
                D_80382D24_523134++;
                auPlaySound(SOUND_ID_65);
            }
        }

        switch (D_80382D24_523134) {
            case 0:
                spSetAttribute(&D_80382C7C_52308C->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C80_523090->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C84_523094->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C88_523098->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C8C_52309C->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C90_5230A0->sprite, SP_HIDDEN);
                break;
            case 1:
                spClearAttribute(&D_80382C7C_52308C->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C80_523090->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C84_523094->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C88_523098->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C8C_52309C->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C90_5230A0->sprite, SP_HIDDEN);
                break;
            case 2:
                spSetAttribute(&D_80382C7C_52308C->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C80_523090->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C84_523094->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C88_523098->sprite, SP_HIDDEN);
                spClearAttribute(&D_80382C8C_52309C->sprite, SP_HIDDEN);
                spSetAttribute(&D_80382C90_5230A0->sprite, SP_HIDDEN);
                break;
        }
        D_80382D80_523190 += 0; // required to match
    } else if (ABS(gContInputStickY) < 5) {
        D_80382D80_523190 = TRUE;
    }
    if (D_80382D20_523130 == 0) {
        omEndProcess(NULL);
    }
}

void func_8035403C_4F444C(GObj* obj) {
    SObj* sobj = obj->data.sobj;
    Sprite* sprite = &sobj->sprite;

    D_80382D28_523138 = 0;
    spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 0);
    spClearAttribute(sprite, SP_HIDDEN);

    while (TRUE) {
        if (D_80382D28_523138 > 153) {
            D_80382D28_523138 = 153;
            spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 153);
            break;
        }
        spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, D_80382D28_523138);
        D_80382D28_523138 += 15;
        ohWait(1);
    }

    omEndProcess(NULL);
}

void func_80354140_4F4550(GObj* obj) {
    SObj* sobj = obj->data.sobj;
    Sprite* sprite = &sobj->sprite;

    D_80382D28_523138 = 0;
    spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 0);
    spClearAttribute(sprite, SP_HIDDEN);
    spMove(&D_80382C78_523088->sprite, 360, 94);
    spClearAttribute(&D_80382C78_523088->sprite, SP_HIDDEN);
    D_80382D38_523148 = 360;

    while (TRUE) {
        if (D_80382D28_523138 > 153) {
            D_80382D28_523138 = 153;
            spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 153);
            spMove(&D_80382C74_523084->sprite, 111, 94);
            spClearAttribute(&D_80382C74_523084->sprite, SP_HIDDEN);
            spSetAttribute(&D_80382C78_523088->sprite, SP_HIDDEN);
            spSetAttribute(&D_80382C7C_52308C->sprite, SP_HIDDEN);
            spClearAttribute(&D_80382C80_523090->sprite, SP_HIDDEN);
            spClearAttribute(&D_80382C84_523094->sprite, SP_HIDDEN);
            spSetAttribute(&D_80382C88_523098->sprite, SP_HIDDEN);
            spSetAttribute(&D_80382C8C_52309C->sprite, SP_HIDDEN);
            spClearAttribute(&D_80382C90_5230A0->sprite, SP_HIDDEN);
            omCreateProcess(obj, func_80353D90_4F41A0, 1, 9);
            omEndProcess(NULL);
        } else {
            spMove(&D_80382C78_523088->sprite, D_80382D38_523148, 94);
            spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, D_80382D28_523138);
            D_80382D28_523138 += 15;
            D_80382D38_523148 -= 24;
        }
        if (D_80382D20_523130 == 0) {
            omEndProcess(NULL);
        }
        ohWait(1);
    }
}

void func_803543B0_4F47C0(GObj* obj) {
    SObj* sobj = obj->data.sobj;

    spSetAttribute(&D_80382C74_523084->sprite, SP_HIDDEN);
    spMove(&D_80382C78_523088->sprite, D_80382D38_523148, 94);
    spClearAttribute(&D_80382C78_523088->sprite, SP_HIDDEN);
    spSetAttribute(&D_80382C7C_52308C->sprite, SP_HIDDEN);
    spSetAttribute(&D_80382C80_523090->sprite, SP_HIDDEN);
    spSetAttribute(&D_80382C84_523094->sprite, SP_HIDDEN);
    spSetAttribute(&D_80382C88_523098->sprite, SP_HIDDEN);
    spSetAttribute(&D_80382C8C_52309C->sprite, SP_HIDDEN);
    spSetAttribute(&D_80382C90_5230A0->sprite, SP_HIDDEN);

    while (TRUE) {
        if (D_80382D38_523148 < -103) {
            spSetAttribute(&sobj->sprite, SP_HIDDEN);
            spSetAttribute(&D_80382C78_523088->sprite, SP_HIDDEN);
            omEndProcess(NULL);
        } else {
            spMove(&D_80382C78_523088->sprite, D_80382D38_523148, 94);
            sobj->sprite.alpha = D_80382D28_523138;
            D_80382D28_523138 -= 15;
            if (D_80382D28_523138 < 0) {
                sobj->sprite.alpha = 0;
            }
            D_80382D38_523148 -= 24;
        }
        ohWait(1);
    }
}

void func_8035453C_4F494C(void) {
    func_80365E34_506244();
    func_80358994_4F8DA4(1);
    func_8035038C_4F079C();
    func_80355614_4F5A24(NULL);
    func_80350458_4F0868(10, 1);
    func_800A7470(0, 0, 0);
    func_800A7918(0, 0.5f);
    ohWait(1);
    while (func_800A7460() == 1) {
        ohWait(1);
    }
}

void func_803545D4_4F49E4(GObj* arg0) {
    func_8035453C_4F494C();
    D_80382D18_523128(1);
    omEndProcess(NULL);
}

void func_80354610_4F4A20(GObj* arg0) {
    func_8035453C_4F494C();
    D_80382D18_523128(6);
    omEndProcess(NULL);
}

void func_8035464C_4F4A5C(GObj* arg0) {
    f32 var_f20, var_f22, var_f24;
    s32 i;
    s32 duration = 20;

    if (D_80382D3C_52314C < 1.0f) {
        var_f20 = 1.0f;
        var_f22 = 0.5f;
        var_f24 = -0.5f / duration;
    } else {
        var_f20 = 0.5f;
        var_f22 = 1.0f;
        var_f24 = 0.5f / duration;
    }
    for (i = duration; i > 0; i--) {
        var_f20 += var_f24;
        var_f22 += var_f24;
        auSetBGMVolume(BGM_PLAYER_MAIN, 32512.0f * var_f20);
        auSetBGMVolume(BGM_PLAYER_AUX, 32512.0f * var_f20);
        auSetCurrentSoundsGlobalVolume(127.0f * var_f20);
        ohWait(1);
    }
    omEndProcess(NULL);
}

void func_80354860_4F4C70(GObj* arg0) {
    ohWait(21);
    D_80382D20_523130 = 1 - D_80382D20_523130;
    func_80357170_4F7580();
    Icons_UnFreeze();
    D_80382D1C_52312C(0);
    func_80359064_4F9474();
    ohResumeProcessByFunction(D_80382C00_523010, func_80352F20_4F3330);
    if (D_80382BFC_52300C < 0) {
        ohResumeProcessByFunction(D_80382C00_523010, func_80351FF0_4F2400);
        ohResumeProcessByFunction(D_80382C00_523010, func_8035275C_4F2B6C);
        ohResumeProcessByFunction(D_80382C00_523010, func_80353180_4F3590);
        ohResumeProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
        ohResumeProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
    } else {
        ohResumeProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
        ohResumeProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
        ohResumeProcessByFunction(D_80382C00_523010, func_803512FC_4F170C);
        ohResumeProcessByFunction(D_80382C00_523010, func_80350950_4F0D60);
    }
    ohResumeProcessByFunction(D_80382C00_523010, func_80353BCC_4F3FDC);
    omEndProcess(NULL);
}

void func_803549A4_4F4DB4(GObj* arg0) {
    if (D_80382D0C_52311C != 1) {
        if (D_80382D40_523150 > 0) {
            D_80382D40_523150 -= 1;
            return;
        }
        if (D_80382D20_523130 != 0) {
            if (gContInputPressedButtons & B_BUTTON) {
                omCreateProcess(arg0, func_803543B0_4F47C0, 0, 9);
                D_80382D40_523150 = 30;
                D_80382D3C_52314C = 1.0f;
                omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
                omCreateProcess(arg0, func_80354860_4F4C70, 0, 9);
                gContInputPressedButtons = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) || (gContInputPressedButtons & CONT_START)) {
                if (D_80382D24_523134 == 0) {
                    omCreateProcess(arg0, func_803543B0_4F47C0, 0, 9);
                    D_80382D40_523150 = 30;
                    D_80382D3C_52314C = 1.0f;
                    omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
                    omCreateProcess(arg0, func_80354860_4F4C70, 0, 9);
                } else if (D_80382D24_523134 == 1) {
                    auPlaySound(SOUND_ID_66);
                    omCreateProcess(arg0, func_803545D4_4F49E4, 0, 9);
                    D_80382D20_523130 = 0;
                    D_80382D44_523154 = 1;
                    omEndProcess(NULL);
                } else {
                    auPlaySound(SOUND_ID_66);
                    omCreateProcess(arg0, func_80354610_4F4A20, 0, 9);
                    D_80382D20_523130 = 0;
                    D_80382D44_523154 = 1;
                    omEndProcess(NULL);
                }
                gContInputPressedButtons = 0;
            }
        } else if (gContInputPressedButtons & CONT_START) {
            D_80382D20_523130 = 1 - D_80382D20_523130;
            D_80382D24_523134 = 0;
            func_80357120_4F7530(arg0);
            Icons_Freeze();
            D_80382D1C_52312C(1);
            func_80359074_4F9484();
            ohPauseProcessByFunction(D_80382C00_523010, func_80352F20_4F3330);
            func_80365E34_506244();
            if (D_80382BFC_52300C < 0) {
                ohPauseProcessByFunction(D_80382C00_523010, func_80351FF0_4F2400);
                ohPauseProcessByFunction(D_80382C00_523010, func_8035275C_4F2B6C);
                ohPauseProcessByFunction(D_80382C00_523010, func_80353180_4F3590);
                ohPauseProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
                ohPauseProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
            } else {
                ohPauseProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
                ohPauseProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
                ohPauseProcessByFunction(D_80382C00_523010, func_803512FC_4F170C);
                ohPauseProcessByFunction(D_80382C00_523010, func_80350950_4F0D60);
            }
            ohPauseProcessByFunction(D_80382C00_523010, func_80353BCC_4F3FDC);
            omCreateProcess(arg0, func_80354140_4F4550, 0, 9);
            auPlaySound(SOUND_ID_11);
            D_80382D40_523150 = 30;
            D_80382D3C_52314C = 0.5f;
            omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
        }
    }
}

void func_80354D38_4F5148(s32* arg0) {
    GObjProcess* proc;
    s32 i;

    for (proc = D_80382C00_523010->processListHead; proc != NULL; proc = proc->next) {
        if (!proc->paused) {
            for (i = 0; D_80382D84_523194[i] != NULL; i++) {
                if (proc->function == D_80382D84_523194[i]) {
                    ohPauseProcessByFunction(D_80382C00_523010, D_80382D84_523194[i]);
                    *arg0 |= 1 << i;
                    break;
                }
            }
        }
    }
}

void func_80354E04_4F5214(s32 arg0) {
    s32 i = 0;

    while (arg0) {
        if (arg0 & 1) {
            ohResumeProcessByFunction(D_80382C00_523010, D_80382D84_523194[i]);
        }
        arg0 >>= 1;
        i++;
    }
}

void func_80354E7C_4F528C(s32* arg0, GObjFunc arg1) {
    s32 i;

    for (i = 0; D_80382D84_523194[i] != NULL; i++) {
        if (arg1 == D_80382D84_523194[i]) {
            *arg0 &= ~(1 << i);
            break;
        }
    }
}

void func_80354EDC_4F52EC(s32 arg0) {
    char* message = NULL;

    if (D_803AE516_54E926 == 1) {
        return;
    }
    if (arg0 != 0) {
        switch (arg0) {
            case 1:
                message = "Press \\z to aim.";
                break;
            case 2:
                message = "Press \\a to shoot.";
                break;
            case 3:
                message = "Try to take a lot of Pokεmon pictures!";
                break;
            case 4:
                message = "Please use the Control Stick.";
                break;
        }

        if (message != NULL) {
            func_80365BB0_505FC0(message, 160, 150, 255, 255, 255, 255, 0, 2);
        }
    } else {
        func_80365E34_506244();
    }
}

s32 func_80354FB8_4F53C8(s32 arg0) {
    s32 s1 = FALSE;

    while (arg0 > 0) {
        if (ABS(gContInputStickX) >= 6 || ABS(gContInputStickY) >= 6) {
            s1 = TRUE;
        }
        if (D_80382D20_523130 == 0) {
            arg0--;
        }
        ohWait(1);
    }
    return s1;
}

void func_80355080_4F5490(GObj* arg0, s32* arg1) {
    *arg1 = 0;
    func_80357120_4F7530(arg0);
    func_80354D38_4F5148(arg1);
    ohPauseProcessByFunction(D_80382C00_523010, func_80351FF0_4F2400);
    ohPauseProcessByFunction(D_80382C00_523010, func_8035275C_4F2B6C);
    ohPauseProcessByFunction(D_80382C00_523010, func_80353180_4F3590);
    ohPauseProcessByFunction(D_80382C6C_52307C, func_803549A4_4F4DB4);
    ohPauseProcessByFunction(D_80382C38_523048, func_80355F18_4F6328);
}

void func_80355110_4F5520(GObj* arg0, s32* arg1) {
    func_80357170_4F7580();
    func_80354E04_4F5214(*arg1);
    ohResumeProcessByFunction(D_80382C00_523010, func_80351FF0_4F2400);
    ohResumeProcessByFunction(D_80382C00_523010, func_8035275C_4F2B6C);
    ohResumeProcessByFunction(D_80382C00_523010, func_80353180_4F3590);
    ohResumeProcessByFunction(D_80382C6C_52307C, func_803549A4_4F4DB4);
    ohResumeProcessByFunction(D_80382C38_523048, func_80355F18_4F6328);
}

void func_803551A4_4F55B4(s32 arg0) {
    s32 i;

    for (i = 0xF0; i > 0; i--) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            break;
        }
        if (!(i & 0x70)) {
            func_80354EDC_4F52EC(0);
        } else {
            func_80354EDC_4F52EC(arg0);
        }
        ohWait(1);
    }
}

void func_80355228_4F5638(GObj* arg0) {
    s32 sp1C;

    func_80354FB8_4F53C8(90);
    func_80355080_4F5490(arg0, &sp1C);
    func_803551A4_4F55B4(3);
    func_80354EDC_4F52EC(0);
    func_80355110_4F5520(arg0, &sp1C);
    if (func_80354FB8_4F53C8(600) == 0) {
        func_80355080_4F5490(arg0, &sp1C);
        func_803551A4_4F55B4(4);
        func_80354EDC_4F52EC(0);
        func_80355110_4F5520(arg0, &sp1C);
    }
    omEndProcess(NULL);
}

void func_803552B0_4F56C0(GObj* obj) {
    s32 i;
    s32 sp30;

    sp30 = 0;
    func_80357120_4F7530(obj);
    func_80354D38_4F5148(&sp30);

    for (i = 120;; i--) {
        if (D_803AE768_54EB78 == 0) {
            break;
        }

        if (D_803AE520_54E930 == 0) {
            if (D_80382BFC_52300C < 0) {
                if (!(gContInputCurrentButtons & Z_TRIG)) {
                    break;
                }
            } else {
                if (gContInputPressedButtons & Z_TRIG) {
                    break;
                }
            }
        } else {
            if (gContInputPressedButtons & Z_TRIG) {
                break;
            }
        }

        if (D_803AE770_54EB80 <= 0 || D_803AE770_54EB80 >= 152 || (GET_POKEMON(D_803AE76C_54EB7C)->flags & 0x80)) {
            break;
        }

        if (!(i & 0x70)) {
            func_80354EDC_4F52EC(0);
        } else if (D_80382BFC_52300C < 0) {
            func_80354EDC_4F52EC(2);
        } else {
            func_80354EDC_4F52EC(1);
        }

        ohWait(1);
    }

    func_80365E34_506244();
    D_80382D08_523118 = 0;
    if (D_80382D04_523114 == 1) {
        if (D_803AE520_54E930 == 0 && (gContInputPressedButtons & Z_TRIG) ||
            D_803AE520_54E930 == 1 && (gContInputPressedButtons & Z_TRIG) && D_80382BFC_52300C >= 0)
        {
            D_80382C3C_52304C = 0;
            auPlaySound(SOUND_ID_5);
            D_80382BFC_52300C = -2;
            omCreateProcess(D_80382C00_523010, func_80351FF0_4F2400, 0, 9);
            func_80354E7C_4F528C(&sp30, func_803512FC_4F170C);
            func_80354E7C_4F528C(&sp30, func_80350950_4F0D60);
            ohPauseProcessByFunction(D_80382C00_523010, func_80351768_4F1B78);
        }
    }
    ohWait(1);
    func_80354E04_4F5214(sp30);
    if (D_80382D08_523118 == 0) {
        func_80357170_4F7580();
    }
    omEndProcess(NULL);
}

void func_803554EC_4F58FC(GObj* arg0) {
    if (func_8009BBF4() >= 3) {
        D_80382D0C_52311C = 0;
        omCreateProcess(arg0, func_80355228_4F5638, 0, 9);
        omEndProcess(NULL);
    } else if (D_803AE768_54EB78 == 1 &&
               D_80382D08_523118 == 0 &&
               D_803AE770_54EB80 > 0 &&
               D_803AE770_54EB80 < 152 &&
               !(GET_POKEMON(D_803AE76C_54EB7C)->flags & 0x80))
    {
        D_80382D08_523118 = 1;
        omCreateProcess(arg0, func_803552B0_4F56C0, 0, 9);
    }
}

void func_803555B0_4F59C0(u8 arg0, u8 arg1, u8 arg2) {
    D_80382D2C_52313C = arg0;
    D_80382D30_523140 = arg1;
    D_80382D34_523144 = arg2;
    omCreateProcess(D_80382C6C_52307C, func_8035403C_4F444C, 0, 9);
}

void func_80355614_4F5A24(GObj* arg0) {
    GObj* pokemonObj;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        if (pokemonObj != arg0) {
            ohPauseObjectProcesses(pokemonObj);
        }
    }
}

void func_80355664_4F5A74(GObj* arg0, s32 arg1, AnimCmd* arg2, f32 arg3) {
    Icons_Hide();
    func_8035E4D0_4FE8E0();
    if (D_80382C38_523048 != NULL) {
        omDeleteGObj(D_80382C38_523048);
        D_80382C38_523048 = NULL;
    }
    func_80365E34_506244();
    func_80358994_4F8DA4(arg1);
    scRemovePostProcessFunc();
    func_8035038C_4F079C();
    ohPauseProcessByFunction(D_80382C00_523010, func_80352F20_4F3330);
    func_80355614_4F5A24(arg0);
    func_800E1A78_5F228(0);
    if (arg2 != NULL) {
        animSetCameraAnimation(D_80382C30_523040, arg2, arg3);
        animUpdateCameraAnimation(D_80382C30_523040->obj);
    } else {
        Vec3f sp34;
        Vec3f sp28;

        sp34.x = 0;
        sp34.y = 0;
        sp34.z = 1.0f;
        sp28.x = 0;
        sp28.y = 0.5f;
        sp28.z = 0;
        Vec3fGetEulerRotation(&sp34, AXIS_Y, D_80366BA4_506FB4.unk_18.y);
        Vec3fAdd(&sp34, &sp28);
        Vec3fNormalize(&sp28);
        Vec3f_func_8001A8B8(&sp34, &sp28, -30.0f);
        D_80382C30_523040->viewMtx.lookAt.at.x = D_80366BA4_506FB4.unk_0C.x;
        D_80382C30_523040->viewMtx.lookAt.at.y = D_80366BA4_506FB4.unk_0C.y;
        D_80382C30_523040->viewMtx.lookAt.at.z = D_80366BA4_506FB4.unk_0C.z;
        D_80382C30_523040->viewMtx.lookAt.eye.x = D_80366BA4_506FB4.unk_0C.x + sp34.x * 80.0f;
        D_80382C30_523040->viewMtx.lookAt.eye.y = D_80366BA4_506FB4.unk_0C.y + sp34.y * 80.0f;
        D_80382C30_523040->viewMtx.lookAt.eye.z = D_80366BA4_506FB4.unk_0C.z + sp34.z * 80.0f;
    }
    D_80382C30_523040->perspMtx.persp.aspect = 4.0f / 3.0f;
    func_80007C20(&D_80382C30_523040->vp, 0.0f, 0.0f, 320.0f, 240.0f);
}

#ifdef NON_MATCHING
// stack diff
void func_80355860_4F5C70(GObj* arg0) {
    s32 var_s2;
    SObj* sobj1;
    s32 i;
    SObj* sobj2;

    var_s2 = 0;
    D_80382D44_523154 = 1;
    D_803AE516_54E926 = 1;
    func_8035038C_4F079C();
    ohPauseProcessByFunction(D_80382C00_523010, func_80355228_4F5638);
    func_80357120_4F7530(NULL);
    func_803555B0_4F59C0(0, 0, 255);
    scRemovePostProcessFunc();
    func_80351158_4F1568(0);
    Icons_SetDashEngineEnabled(0);
    sobj1 = omGObjAddSprite(D_80382C6C_52307C, &D_80388E00_529210);
    spMove(&sobj1->sprite, 125, 97);
    spColor(&sobj1->sprite, 255, 255, 255, 0);
    sobj2 = omGObjAddSprite(D_80382C6C_52307C, &D_80381B58_521F68);
    spMove(&sobj2->sprite, 149, 103);
    spColor(&sobj2->sprite, 255, 255, 255, 0);

    for (i = 59; i != 0; i--) {
        var_s2 += 10;
        if (var_s2 > 255) {
            var_s2 = 255;
        }
        spColor(&sobj1->sprite, 255, 255, 255, var_s2);
        spColor(&sobj2->sprite, 255, 255, 255, var_s2);
        ohWait(1);
    }
    func_80365BB0_505FC0("You're out of film!", 160, 130, 255, 255, 255, 255, 5, 2);
    auStopBGM();
    auStopAllSounds();
    for (i = 0; i < 16; i++) {
        auSetBGMChannelVolume(0, i, 127);
    }
    auPlaySong(0, 17);
    while (func_80365E70_506280() == 0) {
        ohWait(1);
    }
    for (i = 180; i != 0; i--) {
        if (gContInputPressedButtons & A_BUTTON) {
            break;
        }
        ohWait(1);
    }
    func_80350458_4F0868(0xA, 1);
    func_800A7F40(0.0f, 0.0f, 0, 2.0f);
    ohWait(1);
    while (func_800A7460() == 1) {
        ohWait(1);
    }
    D_80382D18_523128(4);
    omEndProcess(NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355860_4F5C70.s")
void func_80355860_4F5C70(GObj* arg0);
#endif

void func_80355B24_4F5F34(GObj* arg0) {
    s32 i;

    auPlaySound(SOUND_ID_20);
    D_80382C64_523074 = TRUE;
    for (i = 0; i < 180; i++) {
        if (D_80382DC0_5231D0 == -1) {
            i = 0;
        }
        ohWait(1);
    }
    D_80382C64_523074 = FALSE;
    cmdSendCommand(D_80382C00_523010, 5, arg0);
    omEndProcess(NULL);
}

void func_80355BC4_4F5FD4(GObj* arg0) {
    f32 volume = 1.0f;
    f32 duration = 120.0f;

    func_80350458_4F0868(10, 1);
    func_800A7470(255, 255, 255);
    func_800A7918(0, 2.0f);
    auSetBGMVolumeSmooth(BGM_PLAYER_MAIN, 0, 120);
    auSetBGMVolumeSmooth(BGM_PLAYER_AUX, 0, 120);
    ohWait(1);
    while (func_800A7460() == 1) {
        volume += -(1.0f / duration);
        auSetSoundGlobalVolume(127.0f * volume);
        ohWait(1);
    }
    auSetSoundGlobalVolume(0);
    D_80382D18_523128(2);
    omEndProcess(NULL);
}

void func_80355D54_4F6164(GObj* obj) {
    D_80382D18_523128(3);
    omEndProcess(NULL);
}

void func_80355D88_4F6198(GObjCmdData cmdData) {
    switch (cmdData.cmd) {
        case 3:
            omCreateProcess(omCurrentObject, func_80350898_4F0CA8, 0, 9);
            break;
        case 4:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, func_80355B24_4F5F34, 0, 9);
                D_80382D9C_5231AC = 1;
            }
            break;
        case 5:
            D_80382D9C_5231AC = 0;
            break;
        case 6:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, func_80355BC4_4F5FD4, 0, 9);
                D_80382D9C_5231AC = 1;
            }
            break;
        case 7:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, func_80355D54_4F6164, 1, 9);
                D_80382D9C_5231AC = 1;
            }
            break;
        case 8:
            func_80355664_4F5A74(cmdData.source, 1, NULL, 0.0f);
            break;
        case 9:
            D_803AE514_54E924 = 1;
            func_80351158_4F1568(0);
            break;
        case 10:
            D_803AE514_54E924 = 1;
            func_80351158_4F1568(0);
            break;
    }
}

void func_80355EF0_4F6300(GObj* arg0) {
    cmdProcessCommands(func_80355D88_4F6198);
}

void func_80355F18_4F6328(GObj* arg0) {
    if (D_80382D20_523130 == 0 && D_80382D0C_52311C != TRUE) {
        if (ABS(D_80382CC0_5230D0) > 0.0005f) {
            if (D_80382BFC_52300C > 0) {
                D_80382C14_523024 += (s32) (5.0f * D_80382CC0_5230D0);
            } else {
                D_80382C14_523024 -= (s32) (5.0f * D_80382CC0_5230D0);
            }
            if (D_80382C14_523024 > 60) {
                D_80382C14_523024 = 60;
            } else if (D_80382C14_523024 < -60) {
                D_80382C14_523024 = -60;
            }
        } else if (D_80382C14_523024 > 50) {
            D_80382C14_523024 -= 3;
        } else if (D_80382C14_523024 < -50) {
            D_80382C14_523024 += 3;
        }
        D_80382C18_523028 = D_80382C2C_52303C * 100.0;
    }
}

void func_80356074_4F6484(GObj* arg0) {
    s32 i = 0;

    while (TRUE) {
        spSetAttribute(&D_803AE440_54E850[i + 1]->sprite, SP_HIDDEN);
        spClearAttribute(&D_803AE440_54E850[1 - (i - 1)]->sprite, SP_HIDDEN);
        i++;
        if (i >= 2) {
            omEndProcess(NULL);
        }
        ohWait(2);
    }
}

void func_80356118_4F6528(GObjCmdData cmdData) {

}

void func_80356124_4F6534(GObj* arg0) {
    SObj* sobj = arg0->data.sobj;

    if (D_80382BFC_52300C >= 0) {
        D_80382C1C_52302C = (f32)D_80382C14_523024 / 160.0f;
        D_80382C20_523030 = -(f32)D_80382C18_523028 / 120.0f;
        D_80382C24_523034 = 0.99f;
        func_803579C8_4F7DD8(&D_80382C1C_52302C, &D_80382C20_523030, &D_80382C24_523034);
        spMove(&sobj->sprite, D_80382C14_523024 + 152, D_80382C18_523028 + 112);
        spClearAttribute(&D_803AE440_54E850[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE440_54E850[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE440_54E850[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE440_54E850[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[4]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[5]->sprite, SP_HIDDEN);
    } else if (D_80382BFC_52300C == -1) {
        spX2Move(&sobj->sprite, 152, 112);
        spSetAttribute(&D_803AE440_54E850[0]->sprite, SP_HIDDEN);
        spClearAttribute(&D_803AE440_54E850[1]->sprite, SP_HIDDEN);
    } else {
        spSetAttribute(&D_803AE440_54E850[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE440_54E850[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE440_54E850[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE440_54E850[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[4]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[5]->sprite, SP_HIDDEN);
    }
    cmdProcessCommands(func_80356118_4F6528);
}

GObj* func_803563A0_4F67B0(void (*arg0)(WorldBlock*), void (*arg1)(s32), GObjFunc arg2, u8 arg3, void (*arg4)(GObj*, GroundResult*)) {
    GObj* sp4C;
    GObj* sp48;
    DObj* sp44;
    SObj* sp40;

    sp48 = omAddGObj(7, &func_80355EF0_4F6300, 9, 0x80000000);
    omGObjAddDObj(sp48, NULL);
    sp44 = sp48->data.dobj;

    D_803AE4A0_54E8B0.kinds[0] = 1;
    D_803AE4A0_54E8B0.kinds[1] = 2;
    D_803AE4A0_54E8B0.kinds[2] = 3;
    sp44->unk_4C = &D_803AE4A0_54E8B0;
    omDObjAddMtx(sp44, MTX_TYPE_62, 0, 0);

    D_803AE518_54E928 = func_8009A8CC();
    D_803AE51C_54E92C = 0;
    if (func_800BFCA0_5CB40(12) == 1) {
        D_803AE51C_54E92C |= 0x1000;
    }
    if (func_800BFCA0_5CB40(13) == 1) {
        D_803AE51C_54E92C |= 0x2000;
    }
    if (func_800BFCA0_5CB40(5) == 1) {
        D_803AE51C_54E92C |= 0x20;
    }
    if (func_800BFCA0_5CB40(0) == 1) {
        D_803AE51C_54E92C |= 1;
    }
    if (func_800BFCA0_5CB40(1) == 1) {
        D_803AE51C_54E92C |= 2;
    }
    if (func_800BFCA0_5CB40(2) == 1) {
        D_803AE51C_54E92C |= 4;
    }
    if (func_800BF864_5C704() >= 4) {
        D_803AE51C_54E92C |= 0x100;
    }
    if (D_803AE518_54E928 != 0) {
        func_80350788_4F0B98(sp48);
    }
    if (D_803AE51C_54E92C & 0x1000) {
        D_803AE520_54E930 = 1;
    } else {
        D_803AE520_54E930 = 0;
    }
    if (D_803AE51C_54E92C & 0x2000) {
        D_803AE521_54E931 = TRUE;
    } else {
        D_803AE521_54E931 = FALSE;
    }
    if (D_803AE51C_54E92C & 0x20) {
        D_803AE522_54E932 = 1;
    } else {
        D_803AE522_54E932 = 0;
    }
    if (D_803AE51C_54E92C & 0x100) {
        D_803AE515_54E925 = 0;
    } else {
        D_803AE515_54E925 = 1;
    }
    D_803AE514_54E924 = 0;
    D_803AE516_54E926 = 0;
    omCreateProcess(sp48, func_80350224_4F0634, 1, 11);
    omCreateProcess(sp48, func_80350AE8_4F0EF8, 1, 9);
    omCreateProcess(sp48, func_80350950_4F0D60, 1, 9);
    omCreateProcess(sp48, func_803512FC_4F170C, 1, 9);
    omCreateProcess(sp48, func_80351534_4F1944, 1, 9);
    ohPauseProcessByFunction(sp48, func_80351534_4F1944);
    omCreateProcess(sp48, func_80351768_4F1B78, 1, 9);
    omCreateProcess(sp48, func_803507EC_4F0BFC, 0, 9);
    D_80366BA4_506FB4.unk_00 = 0.0f;
    D_80366BA4_506FB4.unk_04 = 0.5f;
    D_80366BA4_506FB4.unk_28 = 0.0005f;
    func_800E3EE8_61698(&D_80366BA4_506FB4, 0, arg0, arg1);
    func_80351768_4F1B78(sp48);
    GET_TRANSFORM(sp44)->pos.v.x = D_80366BA4_506FB4.unk_0C.x;
    GET_TRANSFORM(sp44)->pos.v.y = D_80366BA4_506FB4.unk_0C.y;
    GET_TRANSFORM(sp44)->pos.v.z = D_80366BA4_506FB4.unk_0C.z;
    GET_TRANSFORM(sp44)->rot.f[1] = D_80366BA4_506FB4.unk_18.x;
    GET_TRANSFORM(sp44)->rot.f[2] = D_80366BA4_506FB4.unk_18.x; // BUG
    GET_TRANSFORM(sp44)->rot.f[3] = D_80366BA4_506FB4.unk_18.z;
    sp4C = D_80382C00_523010 = sp48;
    D_80382C04_523014 = sp44;
    D_80382C44_523054 = 0.0005f;
    D_80382C94_5230A4 = GET_TRANSFORM(sp44)->pos.v;

    sp48 = ohCreateSprite(25, func_80356124_4F6534, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_80366DF0_507200, 1, func_80355F18_4F6328, 9);
    D_80382C38_523048 = sp48;
    D_803AE440_54E850[0] = sp48->data.sobj;

    D_803AE440_54E850[1] = sp40 = omGObjAddSprite(sp48, &D_80367580_507990);
    spMove(&sp40->sprite, 143, 103);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);

    D_803AE440_54E850[2] = sp40 = omGObjAddSprite(sp48, &D_80367D10_508120);
    spMove(&sp40->sprite, 143, 103);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);

    D_803AE440_54E850[3] = sp40 = omGObjAddSprite(sp48, &D_80367DC0_5081D0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 157, 117);

    D_803AE458_54E868[0] = sp40 = omGObjAddSprite(sp48, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 78, 58);
    spScale(&sp40->sprite, 82.0f, 1.0f);

    D_803AE458_54E868[1] = sp40 = omGObjAddSprite(sp48, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 78, 180);
    spScale(&sp40->sprite, 82.0f, 1.0f);

    D_803AE458_54E868[2] = sp40 = omGObjAddSprite(sp48, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 78, 60);
    spScale(&sp40->sprite, 1.0f, 60.0f);

    D_803AE458_54E868[3] = sp40 = omGObjAddSprite(sp48, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 240, 60);
    spScale(&sp40->sprite, 1.0f, 60.0f);

    D_803AE458_54E868[4] = sp40 = omGObjAddSprite(sp48, &D_803706E0_510AF0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 0, 0);

    D_803AE458_54E868[5] = sp40 = omGObjAddSprite(sp48, &D_80378D88_519198);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 0, 187);

    Items_Init();
    Items_SetCustomFunctions(arg2, arg3, arg4);
    Icons_Init();
    func_8035E37C_4FE78C();
    func_803588D4_4F8CE4();

    D_80382C30_523040->perspMtx.persp.fovy = 55.0f;
    D_803AE478_54E888 = 1.0f;
    D_803AE47C_54E88C = 0.0f;
    sp48 = omAddGObj(26, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(sp48, renDrawSprite, 1, 0x80000000, -1);
    D_80382C6C_52307C = sp48;

    D_80382C70_523080 = sp40 = omGObjAddSprite(sp48, &D_80378ED8_5192E8);
    spMove(&sp40->sprite, 0, 0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    sp40->sprite.scalex = 32.0f;
    sp40->sprite.scaley = 24.0f;

    D_80382C74_523084 = sp40 = omGObjAddSprite(sp48, &D_8037A9A0_51ADB0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);

    D_80382C78_523088 = sp40 = omGObjAddSprite(sp48, &D_8037C468_51C878);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);

    D_80382C7C_52308C = sp40 = omGObjAddSprite(sp48, &D_8037D2A0_51D6B0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 156);

    D_80382C80_523090 = sp40 = omGObjAddSprite(sp48, &D_8037E0D8_51E4E8);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 156);

    D_80382C84_523094 = sp40 = omGObjAddSprite(sp48, &D_8037EF10_51F320);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 133);

    D_80382C88_523098 = sp40 = omGObjAddSprite(sp48, &D_8037FD48_520158);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 133);

    D_80382C8C_52309C = sp40 = omGObjAddSprite(sp48, &D_80380B80_520F90);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 179);

    D_80382C90_5230A0 = sp40 = omGObjAddSprite(sp48, &D_803819B8_521DC8);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 179);

    if (D_803AE518_54E928 == 0) {
        omCreateProcess(sp48, func_803549A4_4F4DB4, 1, 9);
    }
    omCreateProcess(sp48, func_80353118_4F3528, 1, 9);
    switch (getLevelId()) {
        case SCENE_BEACH:
            if (D_803AE515_54E925 == 1) {
                omCreateProcess(sp4C, func_803554EC_4F58FC, 1, 9);
                D_80382D0C_52311C = TRUE;
            } else {
                func_800BFEBC_5CD5C(8, 1);
            }
            D_80382C5C_52306C = 2.0f;
            D_80382C60_523070 = 25.0f;
            omCreateProcess(sp4C, func_80353BCC_4F3FDC, 0, 9);
            break;
        case SCENE_CAVE:
            D_80382C5C_52306C = 40.0f;
            D_80382C60_523070 = 1.5f;
            omCreateProcess(sp4C, func_80353BCC_4F3FDC, 0, 9);
            break;
        case SCENE_RAINBOW:
            D_80382C5C_52306C = 35.0f;
            D_80382C60_523070 = 1.5f;
            omCreateProcess(sp4C, func_80353BCC_4F3FDC, 0, 9);
            break;
        case SCENE_VALLEY:
            D_80382C5C_52306C = 10.0f;
            D_80382C60_523070 = 2.0f;
            omCreateProcess(sp4C, func_80353BCC_4F3FDC, 0, 9);
            break;
        case SCENE_RIVER:
            D_80382C5C_52306C = 15.0f;
            D_80382C60_523070 = 1.5f;
            omCreateProcess(sp4C, func_80353BCC_4F3FDC, 0, 9);
            break;
    }
    func_80365B24_505F34();
    return sp4C;
}

void func_80356FBC_4F73CC(void) {
    omDeleteGObj(D_80382C00_523010);
}

void func_80356FE0_4F73F0(void) {
    omCreateProcess(D_80382C00_523010, func_80351114_4F1524, 1, 9);
}

void func_80357014_4F7424(f32* arg0, f32* arg1) {
    *arg0 = D_80366BA4_506FB4.unk_00;
    *arg1 = D_80366BA4_506FB4.unk_04;
}

GObj* func_80357030_4F7440(void) {
    return D_80382C00_523010;
}

DObj* func_8035703C_4F744C(void) {
    return D_80382C04_523014;
}

u32 getProgressFlags(void) {
    return D_803AE51C_54E92C;
}

void func_80357054_4F7464(f32 arg0, f32 arg1) {
    D_80382CEC_5230FC = arg0;
    D_80382CF0_523100 = arg1;
}

void func_80357068_4F7478(void) {
    if (D_80382D10_523120 != NULL) {
        D_80382D10_523120->flags |= 0xFFFF0000;
    }
    if (D_80382D14_523124 != NULL) {
        D_80382D14_523124->flags |= 0xFFFF0000;
    }
}

void func_803570B0_4F74C0(void) {
    if (D_80382D10_523120 != NULL) {
        D_80382D10_523120->flags &= ~0xFFFF0000;
    }
    if (D_80382D14_523124 != NULL) {
        D_80382D14_523124->flags &= ~0xFFFF0000;
    }
}

void func_803570F0_4F7500(GObj* arg0, AnimCmd* arg1, f32 arg2) {
    func_80355664_4F5A74(arg0, 1, arg1, arg2);
}

void func_80357120_4F7530(GObj* arg0) {
    func_80355614_4F5A24(arg0);
    Items_Pause();
    func_80357068_4F7478();
}

void func_80357150_4F7560(GObj* arg0) {
    ohResumeObjectProcesses(arg0);
}

void func_80357170_4F7580(void) {
    GObj* pokemonObj;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        ohResumeObjectProcesses(pokemonObj);
    }
    Items_UnPause();
    func_803570B0_4F74C0();
}

void func_803571C4_4F75D4(void) {
    Icons_Hide();
    func_8035E764_4FEB74();
    D_80382C38_523048->flags |= GOBJ_FLAG_HIDDEN;
    ohPauseProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
    ohPauseProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
    ohPauseProcessByFunction(D_80382C00_523010, func_803512FC_4F170C);
    ohPauseProcessByFunction(D_80382C00_523010, func_80350950_4F0D60);
    ohPauseProcessByFunction(D_80382C00_523010, func_80351768_4F1B78);
    ohPauseProcessByFunction(D_80382C6C_52307C, func_803549A4_4F4DB4);
}

void func_80357278_4F7688(GObj* arg0) {
    ohWait(2);
    D_80382D04_523114 = 1;
    omEndProcess(NULL);
}

void func_803572B0_4F76C0(void) {
    Icons_Show();
    func_8035E754_4FEB64();
    D_80382C38_523048->flags &= ~GOBJ_FLAG_HIDDEN;
    ohResumeProcessByFunction(D_80382C00_523010, func_80350224_4F0634);
    ohResumeProcessByFunction(D_80382C00_523010, func_80350AE8_4F0EF8);
    ohResumeProcessByFunction(D_80382C00_523010, func_803512FC_4F170C);
    ohResumeProcessByFunction(D_80382C00_523010, func_80350950_4F0D60);
    ohResumeProcessByFunction(D_80382C00_523010, func_80351768_4F1B78);
    ohResumeProcessByFunction(D_80382C6C_52307C, func_803549A4_4F4DB4);
    omCreateProcess(D_80382C00_523010, func_80357278_4F7688, 0, 9);
}

UnkGoldViper* func_80357378_4F7788(void) {
    return &D_80366BA4_506FB4;
}

void func_80357384_4F7794(s32* arg0, f32* arg1) {
    *arg0 = D_80366BA4_506FB4.unk_08->index;
    *arg1 = D_80366BA4_506FB4.unk_00;
}

u8 func_803573A4_4F77B4(void) {
    return D_80382D20_523130;
}

DObj* func_803573B0_4F77C0(void) {
    return D_80382C04_523014;
}

void func_803573BC_4F77CC(void) {
    func_80007C20(&D_80382C30_523040->vp, 0.0f, 0.0f, 320.0f, 240.0f);
    D_80382C30_523040->perspMtx.persp.fovy = 55.0f;
    func_80357D18_4F8128(0, 0, 320, 240);
}

void func_80357428_4F7838(GObj* arg0) {
    if (D_80382C3C_52304C != 0 && arg0 == D_80382C40_523050) {
        D_80382C40_523050 = 0;
        D_80382C3C_52304C = 0;
    }
}

f32 func_80357460_4F7870(OMCamera* arg0, f32 arg1, f32 arg2, f32 arg3) {
    Mtx4f spA0;
    Mtx4f sp60;
    u16 sp5E;
    f32 outX, outY, outZ, outS;

    if (arg0 == NULL) {
        return -1.0f;
    }
    hal_look_at_f(spA0,
                  arg0->viewMtx.lookAt.eye.x, arg0->viewMtx.lookAt.eye.y, arg0->viewMtx.lookAt.eye.z,
                  arg0->viewMtx.lookAt.at.x, arg0->viewMtx.lookAt.at.y, arg0->viewMtx.lookAt.at.z,
                  0.0f, 1.0f, 0.0f);
    hal_perspective_fast_f(sp60, &sp5E,
                           arg0->perspMtx.persp.fovy,
                           arg0->perspMtx.persp.aspect,
                           arg0->perspMtx.persp.near,
                           arg0->perspMtx.persp.far,
                           arg0->perspMtx.persp.scale);
    guMtxCatF(spA0, sp60, sp60);

    outX = sp60[0][0] * arg1 + sp60[1][0] * arg2 + sp60[2][0] * arg3 + sp60[3][0];
    outY = sp60[0][1] * arg1 + sp60[1][1] * arg2 + sp60[2][1] * arg3 + sp60[3][1];
    outZ = sp60[0][2] * arg1 + sp60[1][2] * arg2 + sp60[2][2] * arg3 + sp60[3][2];
    outS = sp60[0][3] * arg1 + sp60[1][3] * arg2 + sp60[2][3] * arg3 + sp60[3][3];
    outS = 1.0f / outS;
    outX *= outS;
    outY *= outS;
    outZ *= outS;

    if (ABS(outX) < 0.2f && ABS(outY) < 0.2f && outS > 0.0f && outZ > 0.0f) {
        return outZ;
    }
    return -1.0f;
}

f32 func_8035769C_4F7AAC(Mtx3f m) {
    f32 det = m[0][0] * m[1][1] * m[2][2]
            + m[1][0] * m[2][1] * m[0][2]
            + m[2][0] * m[0][1] * m[1][2]
            - m[0][2] * m[1][1] * m[2][0]
            - m[1][2] * m[2][1] * m[0][0]
            - m[2][2] * m[0][1] * m[1][0];

    return det;
}

f32 func_80357774_4F7B84(f32 arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5) {
    Mtx4f sp88;
    Mtx4f sp48;
    u16 sp46;
    f32 w;

    if (D_80382C30_523040 == NULL) {
        return -1.0f;
    }

    hal_look_at_f(sp88,
                  D_80382C30_523040->viewMtx.lookAt.eye.x, D_80382C30_523040->viewMtx.lookAt.eye.y, D_80382C30_523040->viewMtx.lookAt.eye.z,
                  D_80382C30_523040->viewMtx.lookAt.at.x, D_80382C30_523040->viewMtx.lookAt.at.y, D_80382C30_523040->viewMtx.lookAt.at.z,
                  0.0f, 1.0f, 0.0f);
    hal_perspective_fast_f(sp48, &sp46,
                           D_80382C30_523040->perspMtx.persp.fovy,
                           D_80382C30_523040->perspMtx.persp.aspect,
                           D_80382C30_523040->perspMtx.persp.near,
                           D_80382C30_523040->perspMtx.persp.far,
                           D_80382C30_523040->perspMtx.persp.scale);
    guMtxCatF(sp88, sp48, sp48);

    *arg3 = sp48[0][0] * arg0 + sp48[1][0] * arg1 + sp48[2][0] * arg2 + sp48[3][0];
    *arg4 = sp48[0][1] * arg0 + sp48[1][1] * arg1 + sp48[2][1] * arg2 + sp48[3][1];
    *arg5 = sp48[0][2] * arg0 + sp48[1][2] * arg1 + sp48[2][2] * arg2 + sp48[3][2];
    w = sp48[0][3] * arg0 + sp48[1][3] * arg1 + sp48[2][3] * arg2 + sp48[3][3];
    w = 1.0f / w;
    *arg3 *= w;
    *arg4 *= w;
    *arg5 *= w;

    if (ABS(*arg3) < 1.0f && ABS(*arg4) < 1.0f && *arg5 > 0.0f) {
        return *arg5;
    }

    return -1.0f;
}

void func_803579C8_4F7DD8(f32* arg0, f32* arg1, f32* arg2) {
    Mtx4f sp150;
    Mtx4f sp110;
    Mtx3f spEC;
    Mtx4f spAC;
    s32 i, j, k, l, p;
    u16 sp96;
    s32 q;
    f32 f0, f2;
    f32 x1, y1, z1, w1;
    f32 invS;

    hal_look_at_f(sp150,
                  D_80382C30_523040->viewMtx.lookAt.eye.x, D_80382C30_523040->viewMtx.lookAt.eye.y, D_80382C30_523040->viewMtx.lookAt.eye.z,
                  D_80382C30_523040->viewMtx.lookAt.at.x, D_80382C30_523040->viewMtx.lookAt.at.y, D_80382C30_523040->viewMtx.lookAt.at.z,
                  D_80382C30_523040->viewMtx.lookAt.up.x, D_80382C30_523040->viewMtx.lookAt.up.y, D_80382C30_523040->viewMtx.lookAt.up.z);
    hal_perspective_fast_f(sp110, &sp96,
                           D_80382C30_523040->perspMtx.persp.fovy,
                           D_80382C30_523040->perspMtx.persp.aspect,
                           D_80382C30_523040->perspMtx.persp.near,
                           D_80382C30_523040->perspMtx.persp.far,
                           D_80382C30_523040->perspMtx.persp.scale);
    guMtxCatF(sp150, sp110, sp110);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (l = 0, k = 0; k < 4; k++) {
                p = 0;
                if (k != i) {
                    for (q = 0; q < 4; q++) {
                        if (j != q) {
                            spEC[l][p++] = sp110[k][q];
                        }
                    }
                    l++;
                }
            }

            f0 = func_8035769C_4F7AAC(spEC);
            if (((i + j) % 2) == 0) {
                f2 = 1.0f;
            } else {
                f2 = -1.0f;
            }
            spAC[j][i] = f2 * f0;
        }
    }

    x1 = spAC[0][0] * *arg0 + spAC[1][0] * *arg1 + spAC[2][0] * *arg2 + spAC[3][0];
    y1 = spAC[0][1] * *arg0 + spAC[1][1] * *arg1 + spAC[2][1] * *arg2 + spAC[3][1];
    z1 = spAC[0][2] * *arg0 + spAC[1][2] * *arg1 + spAC[2][2] * *arg2 + spAC[3][2];
    w1 = spAC[0][3] * *arg0 + spAC[1][3] * *arg1 + spAC[2][3] * *arg2 + spAC[3][3];
    w1 = 1.0f / w1;
    *arg0 = x1 * w1;
    *arg1 = y1 * w1;
    *arg2 = z1 * w1;
}

void func_80357D18_4F8128(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_803AE540_54E950 = arg0;
    D_803AE544_54E954 = arg1;
    D_803AE548_54E958 = arg2;
    D_803AE54C_54E95C = arg3;

    if (D_803AE540_54E950 < viScreenWidth / 320 * D_80382DAC_5231BC) {
        D_803AE540_54E950 = viScreenWidth / 320 * D_80382DAC_5231BC;
    }
    if (D_803AE544_54E954 < viScreenHeight / 240 * D_80382DA4_5231B4) {
        D_803AE544_54E954 = viScreenHeight / 240 * D_80382DA4_5231B4;
    }
    if (D_803AE548_54E958 > viScreenWidth - viScreenWidth / 320 * D_80382DB0_5231C0) {
        D_803AE548_54E958 = viScreenWidth - viScreenWidth / 320 * D_80382DB0_5231C0;
    }
    if (D_803AE54C_54E95C > viScreenHeight - viScreenHeight / 240 * D_80382DA8_5231B8) {
        D_803AE54C_54E95C = viScreenHeight - viScreenHeight / 240 * D_80382DA8_5231B8;
    }
}

void func_80357E0C_4F821C(Gfx** gfxPtr) {
    Gfx* gfxPos = *gfxPtr;

    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, D_803AE540_54E950, D_803AE544_54E954, D_803AE548_54E958, D_803AE54C_54E95C);

    *gfxPtr = gfxPos;
}

void func_80357EC8_4F82D8(OMCamera* cam, s32 mode) {
    func_80357E0C_4F821C(&gMainGfxPos[mode]);
}

void func_80357EF8_4F8308(Gfx** gfxPtr, s32 xmin, s32 ymin, s32 xmax, s32 ymax) {
    Gfx* gfxPos = *gfxPtr;

    gDPFillRectangle(gfxPos++, 0, 0, 319, ymin);
    gDPPipeSync(gfxPos++);
    gDPFillRectangle(gfxPos++, 0, ymax, 319, 239);
    gDPPipeSync(gfxPos++);
    gDPFillRectangle(gfxPos++, 0, ymin - 1, xmin, ymax);
    gDPPipeSync(gfxPos++);
    gDPFillRectangle(gfxPos++, xmax, ymin - 1, 319, ymax);
    gDPPipeSync(gfxPos++);

    *gfxPtr = gfxPos;
}

void func_80357FD4_4F83E4(GObj* obj) {
    OMCamera* cam  = obj->data.cam;
    Vec3f sp20;
    f32 f2;

    sp20.x = cam->viewMtx.lookAt.eye.x - cam->viewMtx.lookAt.at.x;
    sp20.z = cam->viewMtx.lookAt.eye.z - cam->viewMtx.lookAt.at.z;
    f2 = 1.0f / sqrtf(SQ(sp20.x) + SQ(sp20.z));
    sp20.x *= f2;
    sp20.y = 1.0f;
    sp20.z *= f2;
    Vec3fNormalize(&sp20);
    func_800A1E6C(&sp20);
}

void func_80358064_4F8474(GObjCmdData cmdData) {
    if (cmdData.cmd == 1) {
        D_80382DA0_5231B0 = 1;
    }
}

void func_80358088_4F8498(GObj* arg0) {
    cmdProcessCommands(func_80358064_4F8474);
}

void func_803580B0_4F84C0(GObj* obj) {
    if (D_80382DA0_5231B0 > 0) {
        D_80382DA0_5231B0--;
        renInitCamera(&gMainGfxPos[0], obj->data.cam, 0);
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_FILL);
        gDPSetRenderMode(gMainGfxPos[0]++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetScissor(gMainGfxPos[0]++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPSetFillColor(gMainGfxPos[0]++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gMainGfxPos[0]++, 0, 0, 319, 239);
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
        gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPPipeSync(gMainGfxPos[0]++);
        renCameraPostRender(obj->data.cam);
        D_80382D10_523120->flags |= GOBJ_FLAG_HIDDEN;
        return;
    }

    D_80382D10_523120->flags &= ~GOBJ_FLAG_HIDDEN;

    if (D_803AE540_54E950 > 0) {
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
        gDPSetRenderMode(gMainGfxPos[0]++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetScissor(gMainGfxPos[0]++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPSetColorImage(gMainGfxPos[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viScreenWidth, viZBuffer);
        gDPSetFillColor(gMainGfxPos[0]++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        func_80357EF8_4F8308(&gMainGfxPos[0], D_803AE540_54E950, D_803AE544_54E954, D_803AE548_54E958, D_803AE54C_54E95C);
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetColorImage(gMainGfxPos[0]++, G_IM_FMT_RGBA, viBitDepth, viScreenWidth, 0x0F000000);
        gDPSetFillColor(gMainGfxPos[0]++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        func_80357EF8_4F8308(&gMainGfxPos[0], D_803AE540_54E950, D_803AE544_54E954, D_803AE548_54E958, D_803AE54C_54E95C);
    }
    func_80357E0C_4F821C(&gMainGfxPos[0]);
    ren_func_800192DC(obj);
    func_80359034_4F9444();
}

GObj* func_80358420_4F8830(s32 arg0) {
    GObj* sp4C;
    OMCamera* cam;

    sp4C = ohCreateCamera(1, func_80358088_4F8498, NULL, 0x80000000, func_803580B0_4F84C0, 5, 0x38, -1, 0, 1, 0, 0, 0);
    if (sp4C == NULL) {
        return NULL;
    }
    omCreateProcess(sp4C, func_80357FD4_4F83E4, 1, 1);
    cam = sp4C->data.cam;
    D_80382C30_523040 = cam;
    cam->flags |= 5;
    cam->bgColor = arg0;
    D_803AE530_54E940[0] = 14;
    D_803AE530_54E940[1] = 12;
    D_803AE530_54E940[2] = 304;
    D_803AE530_54E940[3] = 232;
    func_80007C20(&cam->vp, D_803AE530_54E940[0], D_803AE530_54E940[1], D_803AE530_54E940[2], D_803AE530_54E940[3]);
    func_80357D18_4F8128(cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4,
                         cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4,
                         cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4,
                         cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4);
    cam->fnPreRender = func_80357EC8_4F82D8;
    omCameraAddMtx(cam, MTX_TYPE_PERSP_FAST, 0);
    omCameraAddMtx(cam, MTX_TYPE_LOOKAT_REFLECT_ROLL, 0);
    cam->vp = cam->vp; // required to match
    cam->perspMtx.persp.fovy = 60.0f;
    cam->perspMtx.persp.near = 10.0f;
    cam->perspMtx.persp.far = 25600.0f;

    cam->viewMtx.lookAt.at.x = 0.0f;
    cam->viewMtx.lookAt.at.y = 1600.0f;
    cam->viewMtx.lookAt.eye.x = 0.0f;
    cam->viewMtx.lookAt.at.z = 0.0f;
    cam->viewMtx.lookAt.eye.y = 1600.0f;
    cam->viewMtx.lookAt.eye.z = 60.0f;
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 1.0f;
    cam->viewMtx.lookAt.up.z = 0.0f;

    D_803AE410_54E820.x = cam->viewMtx.lookAt.eye.x;
    D_803AE410_54E820.y = cam->viewMtx.lookAt.eye.y;
    D_803AE410_54E820.z = cam->viewMtx.lookAt.eye.z;
    D_803AE420_54E830.x = cam->viewMtx.lookAt.at.x;
    D_803AE420_54E830.y = cam->viewMtx.lookAt.at.y;
    D_803AE420_54E830.z = cam->viewMtx.lookAt.at.z;

    return ohCreateCamera(3, ohUpdateDefault, 0, 0x80000000, renSpriteCameraRender, 3, 2, -1, FALSE, 0, NULL, 1, 0);
}

void func_803586C0_4F8AD0(void) {
    omDeleteGObj(D_80382C30_523040->obj);
}

GObj* func_803586E8_4F8AF8(void) {
    return D_80382C30_523040->obj;
}

OMCamera* func_803586F8_4F8B08(void) {
    return D_80382C30_523040;
}
