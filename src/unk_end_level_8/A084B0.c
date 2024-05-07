#include "common.h"
#include "ld_addrs.h"

GObj* D_801DD240_A08E30;
OMCamera* D_801DD244_A08E34;
s32 D_801DD248_A08E38; // padding
s32 D_801DD24C_A08E3C;
s32 D_801DD250_A08E40;
s32 D_801DD254_A08E44;
s32 D_801DD258_A08E48;
s32 D_801DD25C_A08E4C;
u8 D_801DD260_A08E50[0x32000];

void func_801DD070_A08C60(UNK_PTR);
void func_801DCFE0_A08BD0(void);
void func_801DC9E8_A085D8(UNK_PTR);

s32 D_801DD120_A08D10[] = {
    0x05000000,
    0x09000000,
    0x03000000,
};

s32 D_801DD12C_A08D1C = 0;

ScreenSettings D_801DD130_A08D20 = {
    D_803B5000,
    D_803DA800,
    NULL,
    NULL,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0x00016A99,
};

SceneSetup D_801DD14C_A08D3C = {
    {
        0x00000000,
        omUpdateAll,
        omDrawAll,
        unk_end_level_8_VRAM_END,
        0x00000000,
        0x00000001,
        0x00000001,
        0x0000E000,
        0x00002000,
        0x00000000,
        0x00000000,
        0x00005000,
        0x0002,
        0x00003000,
        func_800A1A50,
        contUpdate,
    },
    0x00000010,
    0x00004000,
    0x00000010,
    0x00000000,
    0x00000020,
    0x00000000,
    0x0000005C,
    0x00000400,
    0x00000000,
    func_801DD070_A08C60,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000088,
    0x00000000,
    0x00000060,
    0x00000000,
    0x00000090,
    func_801DCFE0_A08BD0,
};

void func_801DC8C0_A084B0(void) {
    s32 unk0[2];
    s32 sp2C;
    s32 sp28;
    ucolor sp24;

    sp2C = func_8036F78C_842F3C();
    func_8036F684_842E34(sp2C, 1);
    D_801DD254_A08E44 = sp2C;
    func_8036F738_842EE8(sp2C, &sp24);
    func_8036F1F4_8429A4(sp2C, 0xB8, 0x140);
    func_8036F0DC_84288C(sp2C, 0);
    sp28 = func_8036AC6C_83E41C(0x68, 0xAD, 0xC0, 0x2F, 0);
    func_8036B870_83F020(sp28, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp28, 0, sp24.r, sp24.g, sp24.b, 0xFF);
    func_8036B734_83EEE4(sp28);
    func_8036CB58_840308(sp28, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036D4A0_840C50(0);
    func_8036C898_840048(
        sp28,
        "ほれぼれする　しゃしんだね!\n"
        "\\aつぎをみる　\\bもういいや\n"
        "\\zメッセージを　けす・ひょうじ");
    func_8036D1A4_840954(sp28, 1);
    D_801DD258_A08E48 = sp28;
}

// TODO: try to match this function without using a goto
void func_801DC9E8_A085D8(UNK_PTR arg0) {
    UnkStruct800BEDF8* sp3C;
    s32 pad;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    sp34 = 1;
    sp30 = 0x1E;
    sp2C = 0x28;
    sp28 = 5;
    func_8009FB50(5, 9, 8);
    func_801DC8C0_A084B0();
    func_800A7860(1, 1.0f);
    func_8009FA68(D_801DD244_A08E34, func_800BF574_5C414(D_801DD24C_A08E3C));
    D_801DD240_A08E30->flags &= ~1;
    func_8036FE54_843604(D_801DD254_A08E44, 1);

    while (func_800A7460() != 0) {
        ohWait(1);
    }

    func_8036D1A4_840954(D_801DD258_A08E48, 0);
    D_801DD25C_A08E4C = 0;

    while (D_801DD250_A08E40 == 0x10000000) {
    label:
        ohWait(1);

        sp3C = func_800AA38C(0);
        if (D_801DD12C_A08D1C && (--D_801DD25C_A08E4C == 0)) {

        } else if (sp3C->unk_18 & 0x8000) {

        } else if (sp3C->unk_18 & 0x4000) {
            s8 scopedTemp1;

            D_801DD250_A08E40 = 0x20000000;
        } else {
            if (sp3C->unk_18 & 0x2000) {
                sp34 ^= 1;
                if (sp34 != 0) {
                    func_8036F0DC_84288C(D_801DD254_A08E44, 1);
                    func_8036F0A0_842850(D_801DD254_A08E44, 1);
                    func_8036D1A4_840954(D_801DD258_A08E48, 0);
                } else {
                    func_8036F0DC_84288C(D_801DD254_A08E44, 0);
                    func_8036F0A0_842850(D_801DD254_A08E44, 0);
                    func_8036D1A4_840954(D_801DD258_A08E48, 1);
                }
            }
            if (sp3C->unk_18 & 4 && D_801DD12C_A08D1C > 0) {
                s8 scopedTemp2;

                auPlaySound(0x43);
                D_801DD12C_A08D1C--;
            } else if (sp3C->unk_18 & 8 && D_801DD12C_A08D1C < 5) {
                s8 scopedTemp3;

                auPlaySound(0x42);
                D_801DD12C_A08D1C++;
            } else {
                goto label;
            }
        }

        if (D_801DD250_A08E40 == 0x10000000) {
            D_801DD24C_A08E3C = (D_801DD24C_A08E3C + 1) % 4;
            D_801DD240_A08E30->flags |= 1;
            gtlWaitAllGfxTasksDone();
            func_8009FA68(D_801DD244_A08E34, func_800BF574_5C414(D_801DD24C_A08E3C));
            D_801DD240_A08E30->flags &= ~1;
            ohWait(10);
            D_801DD25C_A08E4C = (D_801DD12C_A08D1C != 0) ? ((sp2C * sp28) / D_801DD12C_A08D1C) : 0;
        }
    }

    func_800A7860(0, 1.0f);

    while (func_800A7460() != 0) {
        ohWait(1);
    }

    D_801DD240_A08E30->flags |= 1;
    func_8009FBC4();
    func_800AADF0(0x17);

    while (TRUE) {
        ohWait(1);
    }
}

void func_801DCE2C_A08A1C(void) {
    func_800A85E8(func_801DC9E8_A085D8, 6, 0, 0);
}

void func_801DCE64_A08A54(void) {
    GObj* obj;
    OMCamera* cam;

    obj = ohCreateCamera(1, ohUpdateDefault, 0, 5, ren_func_800192DC, 0xA, 0x20, -1, 0, 1, NULL, 0, 0);
    cam = obj->data.cam;
    cam->flags = 0x4 | 0x1;
    obj->flags |= 0x1;
    omCameraAddMtx(cam, 3, 0);
    omCameraAddMtx(cam, 0xE, 0);
    cam->perspMtx.persp.near = 10.0f;
    cam->perspMtx.persp.far = 25600.0f;
    cam->perspMtx.persp.fovy = 55.0f;
    cam->viewMtx.lookAt.at.x = 0.0f;
    cam->viewMtx.lookAt.eye.x = cam->viewMtx.lookAt.at.x;
    cam->viewMtx.lookAt.at.y = 0.0f;
    cam->viewMtx.lookAt.eye.y = cam->viewMtx.lookAt.at.y;
    cam->viewMtx.lookAt.eye.z = 100.0f;
    cam->viewMtx.lookAt.at.z = 0.0f;
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 1.0f;
    cam->viewMtx.lookAt.up.z = 0.0f;
    D_801DD240_A08E30 = obj;
    D_801DD244_A08E34 = cam;
}

void func_801DCFE0_A08BD0(void) {
    s32 pad[2];

    D_801DD130_A08D20.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_801DD130_A08D20);
    func_8036A3F8(D_801DD260_A08E50, sizeof(D_801DD260_A08E50));
    func_800AAE28();
    func_801DCE64_A08A54();
    func_8036EB98();
    auSetBGMVolume(0, 0x7F00);
    func_800A7F68(1, 0x101);
    func_801DCE2C_A08A1C();
}

void func_801DD070_A08C60(UNK_PTR arg0) {
    func_8036A228_83D9D8(arg0);
}

s32 func_801DD09C_A08C8C(s32 arg0) {
    D_801DD250_A08E40 = 0x10000000;
    D_801DD24C_A08E3C = 0;
    D_800AF3C0 = SCENE_23;
    D_801DD14C_A08D3C.gtlSetup.heapSize = (uintptr_t) unk_end_level_VRAM - (uintptr_t) unk_end_level_8_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801DD14C_A08D3C);

    return D_800AF3C0;
}
