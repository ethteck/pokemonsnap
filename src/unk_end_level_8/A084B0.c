#include "common.h"
#include "ld_addrs.h"

#include "../window/window.h"

extern GObj* D_801DD240_A08E30;
extern OMCamera* D_801DD244_A08E34;
extern s32 D_801DD248_A08E38; // padding
extern s32 D_801DD24C_A08E3C;
extern s32 D_801DD250_A08E40;
extern UIFrame* D_801DD254_A08E44;
extern UIElement* D_801DD258_A08E48;
extern s32 D_801DD25C_A08E4C;
extern u8 D_801DD260_A08E50[0x32000];

void func_801DD070_A08C60(UNK_PTR);
void func_801DCFE0_A08BD0(void);

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
    0x16A99,
};

SceneSetup D_801DD14C_A08D3C = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        unk_end_level_8_VRAM_END,
        0,
        0x1,
        0x1,
        0xE000,
        0x2000,
        0,
        0,
        0x5000,
        0x2,
        0x3000,
        func_800A1A50,
        contUpdate,
    },
    0x10,
    0x4000,
    0x10,
    0,
    0x20,
    0,
    sizeof(GObj),
    0x400,
    0,
    func_801DD070_A08C60,
    0,
    0,
    0,
    sizeof(DObj),
    0,
    0x60,
    0,
    sizeof(OMCamera),
    func_801DCFE0_A08BD0,
};

void func_801DC8C0_A084B0(void) {
    s32 unk0[2];
    UIFrame* sp2C;
    UIElement* sp28;
    ucolor sp24;

    sp2C = UIFrame_Create();
    UIFrame_SetStyle(sp2C, FRAME_STYLE_1);
    D_801DD254_A08E44 = sp2C;
    UIFrame_GetBackgroundColor(sp2C, &sp24);
    UIFrame_SetPos(sp2C, 184, 320);
    UIFrame_Show(sp2C, false);
    sp28 = UIElement_Create(104, 173, 192, 47, 0);
    UIElement_SetColor(sp28, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp28, UI_BACKGROUND, sp24.r, sp24.g, sp24.b, 255);
    UIElement_DrawBackground(sp28);
    UIElement_SetFont(sp28, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIText_SetPrintDelay(0);
    UIElement_PrintText(
        sp28,
        "What an amazing picture!\n\\a Continue.   \\b I'm done.\n\\z Shows the full picture.");
    UIElement_SetState(sp28, true);
    D_801DD258_A08E48 = sp28;
}

// TODO: try to match this function without using a goto
void func_801DC9E8_A085D8(GObj* arg0) {
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
    initObjectsOnPhoto(D_801DD244_A08E34, func_800BF574_5C414(D_801DD24C_A08E3C));
    D_801DD240_A08E30->flags &= ~1;
    UIFrame_FadeIn(D_801DD254_A08E44, FRAME_STYLE_1);

    while (func_800A7460() != 0) {
        ohWait(1);
    }

    UIElement_SetState(D_801DD258_A08E48, UI_NORMAL);
    D_801DD25C_A08E4C = 0;

    while (D_801DD250_A08E40 == 0x10000000) {
    label:
        ohWait(1);

        sp3C = func_800AA38C(0);
        if (D_801DD12C_A08D1C && (--D_801DD25C_A08E4C == 0)) {

        } else if (sp3C->pressedButtons & A_BUTTON) {

        } else if (sp3C->pressedButtons & B_BUTTON) {
            s8 scopedTemp1;

            D_801DD250_A08E40 = 0x20000000;
        } else {
            if (sp3C->pressedButtons & Z_TRIG) {
                sp34 ^= 1;
                if (sp34 != 0) {
                    UIFrame_Show(D_801DD254_A08E44, true);
                    UIFrame_ShowBackground(D_801DD254_A08E44, true);
                    UIElement_SetState(D_801DD258_A08E48, UI_NORMAL);
                } else {
                    UIFrame_Show(D_801DD254_A08E44, false);
                    UIFrame_ShowBackground(D_801DD254_A08E44, false);
                    UIElement_SetState(D_801DD258_A08E48, UI_HIDDEN);
                }
            }
            if (sp3C->pressedButtons & 4 && D_801DD12C_A08D1C > 0) {
                s8 scopedTemp2;

                auPlaySound(SOUND_ID_67);
                D_801DD12C_A08D1C--;
            } else if (sp3C->pressedButtons & 8 && D_801DD12C_A08D1C < 5) {
                s8 scopedTemp3;

                auPlaySound(SOUND_ID_66);
                D_801DD12C_A08D1C++;
            } else {
                goto label;
            }
        }

        if (D_801DD250_A08E40 == 0x10000000) {
            D_801DD24C_A08E3C = (D_801DD24C_A08E3C + 1) % 4;
            D_801DD240_A08E30->flags |= 1;
            gtlWaitAllGfxTasksDone();
            initObjectsOnPhoto(D_801DD244_A08E34, func_800BF574_5C414(D_801DD24C_A08E3C));
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
    func_800AADF0(SCENE_GALLERY_2);

    while (true) {
        ohWait(1);
    }
}

void func_801DCE2C_A08A1C(void) {
    func_800A85E8(func_801DC9E8_A085D8, LINK_6, DL_LINK_0, NULL);
}

void func_801DCE64_A08A54(void) {
    GObj* obj;
    OMCamera* cam;

    obj = ohCreateCamera(1, ohUpdateDefault, 0, 5, ren_func_800192DC, 0xA, 0x20, -1, 0, 1, NULL, 0, 0);
    cam = obj->data.cam;
    cam->flags = CAMERA_FLAG_4 | CAMERA_FLAG_1;
    obj->flags |= GOBJ_FLAG_HIDDEN;
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
    UIMem_CreateHeap(D_801DD260_A08E50, sizeof(D_801DD260_A08E50));
    func_800AAE28();
    func_801DCE64_A08A54();
    UIText_Initialize();
    auSetBGMVolume(0, 0x7F00);
    func_800A7F68(1, 0x101);
    func_801DCE2C_A08A1C();
}

void func_801DD070_A08C60(UNK_PTR arg0) {
    UIMem_Deallocate(arg0);
}

s32 func_801DD09C_A08C8C(s32 arg0) {
    D_801DD250_A08E40 = 0x10000000;
    D_801DD24C_A08E3C = 0;
    D_800AF3C0 = SCENE_GALLERY_2;
    D_801DD14C_A08D3C.gtlSetup.heapSize = (uintptr_t) window_VRAM - (uintptr_t) unk_end_level_8_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801DD14C_A08D3C);

    return D_800AF3C0;
}
