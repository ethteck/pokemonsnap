#include "common.h"
#include "world/world.h"
#include "app_level.h"

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
extern s32 D_80382BFC_52300C;
extern GObj* D_80382C00_523010;
extern DObj* D_80382C04_523014;
extern s32 D_80382C14_523024;
extern s32 D_80382C18_523028;
extern f32 D_80382C1C_52302C;
extern f32 D_80382C20_523030;
extern f32 D_80382C24_523034;
extern f32 D_80382C2C_52303C;
extern OMCamera* D_80382C30_523040;
extern GObj* D_80382C38_523048;
extern f32 D_80382C44_523054;
extern f32 D_80382C5C_52306C;
extern f32 D_80382C60_523070;
extern s32 D_80382C64_523074;
extern GObj* D_80382C6C_52307C;
extern SObj* D_80382C70_523080;
extern SObj* D_80382C74_523084;
extern SObj* D_80382C78_523088;
extern SObj* D_80382C7C_52308C;
extern SObj* D_80382C80_523090;
extern SObj* D_80382C84_523094;
extern SObj* D_80382C88_523098;
extern SObj* D_80382C8C_52309C;
extern SObj* D_80382C90_5230A0;
extern Vec3f D_80382C94_5230A4;
extern s32 D_80382CA0_5230B0;
extern s32 D_80382CB4_5230C4;
extern s32 D_80382CB8_5230C8;
extern f32 D_80382CC0_5230D0;
extern s32 D_80382CF4_523104;
extern s32 D_80382D0C_52311C;
extern void (*D_80382D18_523128)(s32);
extern u8 D_80382D20_523130;
extern s8 D_80382D44_523154;
extern s32 D_80382D48_523158;
extern s32 D_80382D9C_5231AC;
extern s32 D_80382DC0_5231D0;
extern s32 Icons_NumItemsAvailable;
extern Sprite D_80388E00_529210;
extern SObj* D_803AE440_54E850[4];
extern SObj* D_803AE458_54E868[6];
extern f32 D_803AE478_54E888;
extern f32 D_803AE47C_54E88C;
extern struct DObjDynamicStore D_803AE4A0_54E8B0;
extern s8 D_803AE514_54E924;
extern s8 D_803AE515_54E925;
extern s8 D_803AE516_54E926;
extern s32 D_803AE518_54E928;
extern u32 D_803AE51C_54E92C;
extern s8 D_803AE520_54E930;
extern s8 D_803AE521_54E931;
extern s8 D_803AE522_54E932;

void func_80357120_4F7530(s32);
void func_803579C8_4F7DD8(f32*, f32*, f32*);
void func_803588D4_4F8CE4(void);
void func_803597D4_4F9BE4(void);
void func_8035C44C_4FC85C(UNK_PTR, s32*);
void func_8035C5CC_4FC9DC(UNK_PTR, s32*);
void func_8035C74C_4FCB5C(void);
void func_8035C7E4_4FCBF4(void);
void func_8035C9CC_4FCDDC(s32, u8, s32);
void Icons_ProcessButtonPress(s32);
void func_8035E37C_4FE78C(void);
void func_80365B24_505F34(void);
void func_80365BB0_505FC0(char*, s32, s32, u8, u8, u8, u8, s32, u8);
s32 func_80365E70_506280(void);
s32 func_8009A8CC(void);
void func_800A7918(s32, s32);
void func_800A7F40(f32, f32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350200_4F0610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350224_4F0634.s")
void func_80350224_4F0634(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035024C_4F065C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035038C_4F079C.s")
void func_8035038C_4F079C(void);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350458_4F0868.s")
void func_80350458_4F0868(s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350488_4F0898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350788_4F0B98.s")
void func_80350788_4F0B98(GObj*);

void func_803507E0_4F0BF0(s32 arg0) {
    D_80382D48_523158 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803507EC_4F0BFC.s")
void func_803507EC_4F0BFC(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350898_4F0CA8.s")
void func_80350898_4F0CA8(GObj*);

void func_80350950_4F0D60(GObj* obj) {
    if (D_80382D0C_52311C == 0) {
        if ((gContInputPressedButtons & D_CBUTTONS) && Icons_NumItemsAvailable >= 3 && D_80382CB8_5230C8 == 0) {
            D_80382CF4_523104 = 161;
            D_80382CB8_5230C8 = 45;
            Icons_ProcessButtonPress(161);
            func_8035C74C_4FCB5C();
        } else if (D_80382CB4_5230C4 == 0) {
            if ((gContInputPressedButtons & B_BUTTON) && Icons_NumItemsAvailable >= 2) {
                D_80382CF4_523104 = 162;
                D_80382CB4_5230C4 = 45;
                func_8035C44C_4FC85C(&D_80382C30_523040->viewMtx.lookAt.eye, &D_80382CA0_5230B0);
                Icons_ProcessButtonPress(162);
                func_8035C7E4_4FCBF4();
                Icons_ProcessButtonPress(-1);
                D_80382CB8_5230C8 = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) && Icons_NumItemsAvailable >= 1) {
                D_80382CF4_523104 = 163;
                D_80382CB4_5230C4 = 45;
                func_8035C5CC_4FC9DC(&D_80382C30_523040->viewMtx.lookAt.eye, &D_80382CA0_5230B0);
                Icons_ProcessButtonPress(163);
                func_8035C7E4_4FCBF4();
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80350AE8_4F0EF8.s")
void func_80350AE8_4F0EF8(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80351114_4F1524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80351158_4F1568.s")
void func_80351158_4F1568(s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803511DC_4F15EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803512FC_4F170C.s")
void func_803512FC_4F170C(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80351534_4F1944.s")
void func_80351534_4F1944(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80351768_4F1B78.s")
void func_80351768_4F1B78(GObj*);

void func_80351E8C_4F229C(Vec3f* arg0) {
    f32 sin;
    f32 cos;
    f32 x;
    f32 y;
    f32 z;

    x = arg0->x - D_80366BA4_506FB4.unk_0C.x;
    y = arg0->y - D_80366BA4_506FB4.unk_0C.y;
    z = arg0->z - D_80366BA4_506FB4.unk_0C.z;
    sin = __sinf(-D_80366BA4_506FB4.unk_18.y);
    cos = __cosf(-D_80366BA4_506FB4.unk_18.y);
    arg0->x = (x * cos) + (z * sin);
    arg0->y = y;
    arg0->z = (z * cos) - (x * sin);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80351F44_4F2354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80351FF0_4F2400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035275C_4F2B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80352DC8_4F31D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80352E24_4F3234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80352F20_4F3330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803530B4_4F34C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353118_4F3528.s")
void func_80353118_4F3528(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353180_4F3590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353BCC_4F3FDC.s")
void func_80353BCC_4F3FDC(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353D50_4F4160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353D5C_4F416C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353D68_4F4178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80353D90_4F41A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035403C_4F444C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354140_4F4550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803543B0_4F47C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035453C_4F494C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803545D4_4F49E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354610_4F4A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035464C_4F4A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354860_4F4C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803549A4_4F4DB4.s")
void func_803549A4_4F4DB4(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354D38_4F5148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354E04_4F5214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354E7C_4F528C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354EDC_4F52EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80354FB8_4F53C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355080_4F5490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355110_4F5520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803551A4_4F55B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355228_4F5638.s")
void func_80355228_4F5638(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803552B0_4F56C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803554EC_4F58FC.s")
void func_803554EC_4F58FC(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803555B0_4F59C0.s")
void func_803555B0_4F59C0(s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355614_4F5A24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355664_4F5A74.s")
void func_80355664_4F5A74(GObj*, s32, AnimCmd*, f32);

#ifdef NON_MATCHING
void func_80355860_4F5C70(GObj* arg0) {
    s32 var_s2;
    SObj* sobj1;
    s32 i;
    SObj* sobj2;
    Sprite* newvar;
    s32 one1 = 1;
    s32 one2 = 1;

    D_80382D44_523154 = one1;
    var_s2 = 0;
    goto dummy_label_483273; dummy_label_483273: ; // TODO find better match
    D_803AE516_54E926 = one2;
    func_8035038C_4F079C();
    ohPauseProcessByFunction(D_80382C00_523010, func_80355228_4F5638);
    func_80357120_4F7530(0);
    func_803555B0_4F59C0(0, 0, 255);
    scRemovePostProcessFunc();
    func_80351158_4F1568(0);
    Icons_SetDashEngineEnabled(0);
    sobj1 = omGObjAddSprite(D_80382C6C_52307C, &D_80388E00_529210);
    spMove(&sobj1->sprite, 125, 97);
    newvar = &sobj1->sprite; 
    spColor(newvar, 255, 255, 255, 0);
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
    func_800A7F40(0.0f, 0.0f, 0, 0x40000000);
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

    auPlaySound(20);
    D_80382C64_523074 = 1;
    for (i = 0; i < 180; i++) {
        if (D_80382DC0_5231D0 == -1) {
            i = 0;
        }
        ohWait(1);
    }
    D_80382C64_523074 = 0;
    cmdSendCommand(D_80382C00_523010, 5, arg0);
    omEndProcess(NULL);
}

void func_80355BC4_4F5FD4(GObj* arg0) {
    f32 volume = 1.0f;
    f32 duration = 120.0f;

    func_80350458_4F0868(10, 1);
    func_800A7470(255, 255, 255);
    func_800A7918(0, 0x40000000);
    auSetBGMVolumeSmooth(0, 0, 120);
    auSetBGMVolumeSmooth(1, 0, 120);
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

#ifdef NON_MATCHING
void func_80355D88_4F6198(GObj* source, s32 cmd) {
    switch (cmd) {
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
            func_80355664_4F5A74(source, 1, NULL, 0.0f);
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
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80355D88_4F6198.s")
void func_80355D88_4F6198(GObj* source, s32 cmd);
#endif

void func_80355EF0_4F6300(GObj* arg0) {
    cmdProcessCommands(func_80355D88_4F6198);
}

void func_80355F18_4F6328(GObj* arg0) {
    f32 var_f2;

    if (D_80382D20_523130 == 0 && D_80382D0C_52311C != 1) {
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

void func_80356118_4F6528(GObj* source, s32 cmd) {

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

GObj* func_803563A0_4F67B0(void (*arg0)(WorldBlock*), void (*arg1)(s32), s32 arg2, u8 arg3, s32 arg4) {
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
        D_803AE521_54E931 = 1;
    } else {
        D_803AE521_54E931 = 0;
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

    func_803597D4_4F9BE4();
    func_8035C9CC_4FCDDC(arg2, arg3, arg4);
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
                D_80382D0C_52311C = 1;
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80356FBC_4F73CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80356FE0_4F73F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357014_4F7424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357030_4F7440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035703C_4F744C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/getProgressFlags.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357054_4F7464.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357068_4F7478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803570B0_4F74C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803570F0_4F7500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357120_4F7530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357150_4F7560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357170_4F7580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803571C4_4F75D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357278_4F7688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803572B0_4F76C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357378_4F7788.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357384_4F7794.s")

u8 func_803573A4_4F77B4(void) {
    return D_80382D20_523130;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803573B0_4F77C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803573BC_4F77CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357428_4F7838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357460_4F7870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_8035769C_4F7AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357774_4F7B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803579C8_4F7DD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357D18_4F8128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357E0C_4F821C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357EC8_4F82D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357EF8_4F8308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80357FD4_4F83E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80358064_4F8474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80358088_4F8498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803580B0_4F84C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_80358420_4F8830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803586C0_4F8AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803586E8_4F8AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/func_803586F8_4F8B08.s")
