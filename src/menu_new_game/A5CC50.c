#include "common.h"
#include "ld_addrs.h"
#include "sys/vi.h"
#include "sys/gtl.h"
#include "../window/window.h"

extern Sprite D_80117F98_A93348; // card
extern Sprite D_80109880_A84C30; // background

// clang-format off
char* D_800E2FF0[] = {
    "あ", "い", "う", "え", "お",
    "か", "き", "く", "け", "こ",
    "さ", "し", "す", "せ", "そ",
    "た", "ち", "つ", "て", "と",
    "な", "に", "ぬ", "ね", "の",
    "は", "ひ", "ふ", "へ", "ほ",
    "ま", "み", "む", "め", "も",
    "や", "ゆ", "よ", "　", "　",
    "ら", "り", "る", "れ", "ろ",
    "わ", "を", "ん", "　", "　",
    "が", "ぎ", "ぐ", "げ", "ご",
    "ざ", "じ", "ず", "ぜ", "ぞ",
    "だ", "ぢ", "づ", "で", "ど",
    "ば", "び", "ぶ", "べ", "ぼ",
    "ぱ", "ぴ", "ぷ", "ぺ", "ぽ",
    "ぁ", "ぃ", "ぅ", "ぇ", "ぉ",
    "っ", "ゃ", "ゅ", "ょ", "\xA1\xDD",
    "ア", "イ", "ウ", "エ", "オ",
    "カ", "キ", "ク", "ケ", "コ",
    "サ", "シ", "ス", "セ", "ソ",
    "タ", "チ", "ツ", "テ", "ト",
    "ナ", "ニ", "ヌ", "ネ", "ノ",
    "ハ", "ヒ", "フ", "ヘ", "ホ",
    "マ", "ミ", "ム", "メ", "モ",
    "ヤ", "ユ", "ヨ", "　", "　",
    "ラ", "リ", "ル", "レ", "ロ",
    "ワ", "ヲ", "ン", "　", "　",
    "ガ", "ギ", "グ", "ゲ", "ゴ",
    "ザ", "ジ", "ズ", "ゼ", "ゾ",
    "ダ", "ヂ", "ヅ", "デ", "ド",
    "バ", "ビ", "ブ", "ベ", "ボ",
    "パ", "ピ", "プ", "ペ", "ポ",
    "ァ", "ィ", "ゥ", "ェ", "ォ",
    "ッ", "ャ", "ュ", "ョ", "\xA1\xDD",

    "Ａ", "Ｂ", "Ｃ", "Ｄ", "Ｅ",
    "Ｆ", "Ｇ", "Ｈ", "Ｉ", "Ｊ",
    "Ｋ", "Ｌ", "Ｍ", "Ｎ", "Ｏ",
    "Ｐ", "Ｑ", "Ｒ", "Ｓ", "Ｔ",
    "Ｕ", "Ｖ", "Ｗ", "Ｘ", "Ｙ",
    "Ｚ", "　", "　", "　", "　",
    "ａ", "ｂ", "ｃ", "ｄ", "ｅ",
    "ｆ", "ｇ", "ｈ", "ｉ", "ｊ",
    "ｋ", "ｌ", "ｍ", "ｎ", "ｏ",
    "ｐ", "ｑ", "ｒ", "ｓ", "ｔ",
    "ｕ", "ｖ", "ｗ", "ｘ", "ｙ",
    "ｚ", "　", "　", "　", "　",
    "０", "１", "２", "３", "４",
    "５", "６", "７", "８", "９",
    "！", "？", "、", "。", "・",
    "\xA1\xDD", "\xA1\xC1", "　", "　", "　",
    "　", "　", "　", "　", "　",

    "Ａ", "Ｂ", "Ｃ", "Ｄ", "Ｅ",
    "Ｆ", "Ｇ", "Ｈ", "Ｉ", "Ｊ",
    "Ｋ", "Ｌ", "Ｍ", "Ｎ", "Ｏ",
    "Ｐ", "Ｑ", "Ｒ", "Ｓ", "Ｔ",
    "Ｕ", "Ｖ", "Ｗ", "Ｘ", "Ｙ",
    "Ｚ", "ａ", "ｂ", "ｃ", "ｄ",
    "ｅ", "ｆ", "ｇ", "ｈ", "ｉ",
    "ｊ", "ｋ", "ｌ", "ｍ", "ｎ",
    "ｏ", "ｐ", "ｑ", "ｒ", "ｓ",
    "ｔ", "ｕ", "ｖ", "ｗ", "ｘ",
    "ｙ", "ｚ", "０", "１", "２",
    "３", "４", "５", "６", "７",
    "８", "９", "†", "‡", "¶",
    "\xA1\xC1", "！", "？", "＠", "＃",
    "％", "＆", "＊", "（", "）",
    "＿", "＋", "＝", "ー", "’",
    "”", "；", "：", "／", "＄",
    "．", "，", "＜", "＞", "♂",
    "♀", "［", "］", "ε", "　",
    "\0",
};
// clang-format on

char* D_800E356C[] = { "←", "→", "　", "End" };

ScreenSettings menu_new_game_video_settings = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00016A99     /* flags*/
};

Lights1 D_800E3598 = gdSPDefLights1(100, 100, 100, 180, 180, 180, 30, 30, 30);

Gfx D_800E35B0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPFogFactor(256, -512),
    gsDPSetFogColor(0, 0, 0, 255),
    gsSPSetGeometryMode(G_FOG),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPSetLights1(D_800E3598),
    gsSPEndDisplayList(),
};

// BSS
static GObj* D_801180B0;
static GObj* D_801180B4;
static GObj* D_801180B8;
static UIElement* D_801180C0[20];
UIElement* D_80118110;
UIElement* D_80118114;
static u8 D_80118118[0x50000];

void func_800E2ED0_A5E280(void);

void func_800E18A0_A5CC50(SObj* arg0, u8 color) {
    arg0->sprite.red = color;
    arg0->sprite.green = color;
    arg0->sprite.blue = color;
}

char** func_800E18B4_A5CC64(s32 arg0) {
    return &D_800E2FF0[255];
}

void func_800E18C4_A5CC74(void) {
}

void func_800E18CC_A5CC7C(void) {
    SObj* sobj;

    D_801180B4 = ohCreateSprite(14, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_80109880_A84C30, 0, 0, 1);
    sobj = D_801180B4->data.sobj;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E1950_A5CD00(void) {
    SObj* sobj;

    D_801180B8 = ohCreateSprite(14, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_80117F98_A93348, 0, 0, 1);
    sobj = D_801180B8->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 96, 21);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E19E4_A5CD94(void) {
    func_800E18CC_A5CC7C();
    func_800E1950_A5CD00();
}

void func_800E1A0C_A5CDBC(void) {
    UIElement* id;
    UIFrame* unk;
    s8 i;
    ucolor sp28;

    unk = UIFrame_Create();
    UIFrame_SetStyle(unk, FRAME_STYLE_1);
    UIFrame_GetBackgroundColor(unk, &sp28);
    UIFrame_SetPos(unk, 184, 320);
    UIFrame_Show(unk, true);
    UIFrame_ShowBackground(unk, false);
    UIFrame_FadeIn(unk, FRAME_STYLE_1);

    // description
    id = UIElement_Create(104, 173, 192, 47, 0);
    UIElement_SetColor(id, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(id, UI_BACKGROUND, sp28.r, sp28.g, sp28.b, 255);
    UIElement_DrawBackground(id);
    UIElement_SetTextPos(id, 0, 0);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIElement_SetFont(id, FONT_12);
    UIElement_PrintText(id, "Enter your name on the card.\n"
                             "Choose with the Control Stick\n"
                             "and select with the \\a Button!");

    // character grid
    for (i = 0; i < ARRAY_COUNT(D_801180C0); i++) {
        UIText_SetPrintDelay(0);
        UIText_SetShadowOffset(1);
        UIText_SetSpacing(-1, 3);
        id = UIElement_Create(23, i * 10 + 20, 60, 8, 0);
        UIElement_SetFont(id, FONT_8);
        UIElement_SetColor(id, UI_BACKGROUND, 0, 0, 0, 0);
        UIElement_DrawBackground(id);
        D_801180C0[i] = id;
    }

    UIText_SetPrintDelay(0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);

    // name input
    id = UIElement_Create(203, 64, 62, 12, UI_FLAG_32BIT);
    UIElement_SetFont(id, FONT_12);
    UIElement_SetColor(id, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_SetColor(id, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_DrawBackground(id);
    D_80118110 = id;

    UIText_SetPrintDelay(0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);

    id = UIElement_Create(206, 64, 12, 12, UI_FLAG_32BIT);
    UIElement_SetFont(id, FONT_12);
    UIElement_SetColor(id, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_SetColor(id, UI_FOREGROUND, 255, 0, 0, 255);
    UIElement_DrawBackground(id);
    D_80118114 = id;
}

void func_800E1CF8_A5D0A8(s8 arg0) {
    s16 i;
    s16 j;
    UIElement* temp_s2;
    s16 temp_s1;
    char** temp_s4 = func_800E18B4_A5CC64(arg0);

    for (i = 0; i < ARRAY_COUNT(D_801180C0); i++) {
        UIElement_Draw(D_801180C0[i]);
    }

    temp_s1 = 0;
    func_8036D4B4_840C64(1, 0);

    for (i = 0; i < ARRAY_COUNT(D_801180C0) - 1; i++) {
        temp_s2 = D_801180C0[i];
        for (j = 0; j < 5; j++) {
            UIElement_SetTextPos(temp_s2, j * 13, 0);
            UIElement_PrintText(temp_s2, temp_s4[temp_s1++]);
        }
    }

    func_8036D4B4_840C64(1, 1);
    temp_s1 = 0;
    temp_s2 = D_801180C0[i];
    for (j = 0; j < 4; j++) {
        UIElement_SetTextPos(temp_s2, j * 13, 0);
        UIElement_PrintText(temp_s2, D_800E356C[temp_s1++]);
    }
}

void func_800E1E94_A5D244(void) {
    FocusMark_Create();
    FocusMark_Show(false);
    FocusMark_SetTargetSize(4, 5);
    FocusMark_SetTargetPos(25, 22);
    FocusMark_MoveFront();
    FocusMark_Show(true);
}

void func_800E1EE4_A5D294(void) {
    u8 var_a1;

    for (var_a1 = 255; var_a1 > 128; var_a1 -= 5) {
        func_800E18A0_A5CC50(D_801180B4->data.sobj, var_a1);
        ohWait(1);
    }
    func_800E18A0_A5CC50(D_801180B4->data.sobj, 128);
    ohWait(1);
}

void func_800E1F58_A5D308(GObj* arg0) {
    s32 sp24;
    s32 sp20;
    u8 i;

    func_800E19E4_A5CD94();
    func_800E1A0C_A5CDBC();
    func_800E1CF8_A5D0A8(0);
    func_800E1E94_A5D244();
    func_800E1EE4_A5D294();
    auSetBGMVolume(0, 0x7F00);
    auPlaySong(0, 12);
    func_800E2ED0_A5E280();
    auSetBGMVolumeSmooth(0, 0, 60);
    func_800A7470(0, 0, 0);
    func_800A7860(0, 1.0f);
    // wait 60 frames
    for (i = 0; i < 60; i++) {
        ohWait(1);
    }
    func_800BFC18_5CAB8(sp24, sp20); // BUG: why not pointers ?
    viSetScreenOffsets(sp24, sp24, sp20, sp20);
    func_800067DC();
    while (true) {
        ohWait(1);
    }
}

void func_800E2054_A5D404(Gfx** gfxPtr) {
    gSPDisplayList((*gfxPtr)++, D_800E35B0);
}

void new_game_init(void) {
    func_8036A3F8_83DBA8(D_80118118, sizeof(D_80118118));
    func_800AAE28();
    func_800AA85C(24, 6);
    func_800AA870(0xF0000);
    UIText_Initialize();
    ohCreateCameraWrapper(0, 0x80000000, 100, 6, 0);
    D_801180B0 = ohCreateCamera(3, ohUpdateDefault, 0, 0x80000000, renSpriteCameraRender, 3, 2, -1, true, 1, NULL, 1, true);
    D_801180B0->data.cam->flags = CAMERA_FLAG_8;
    func_800A7F68(0, 0x101);
    omCreateProcess(omAddGObj(0xE, NULL, 0, 0x80000000), func_800E1F58_A5D308, 0, 1);
}

SceneSetup menu_new_game_setup = {
    {
        0,                      /* unk_00*/
        omUpdateAll,            /* fnUpdate */
        omDrawAll,              /* fnDraw */
        menu_new_game_VRAM_END, /* heapBase */
        0,                      /* heapSize */
        2,                      /* unk_14 */
        1,                      /* numContexts */
        0x5000,                 /* dlBufferSize0 */
        0x2000,                 /* dlBufferSize1 */
        0x0000,                 /* dlBufferSize2 */
        0x0000,                 /* dlBufferSize3 */
        0xC800,                 /* gfxHeapSize */
        0,                      /* unk30 */
        0x2000,                 /* rdpOutputBufferSize */
        func_800A1A50,          /* fnPreRender */
        contUpdate              /* fnUpdateInput */
    },
    32,               /* numOMThreads */
    1024,             /* omThreadStackSize */
    128,              /* numOMStacks */
    0,                /* unk4C */
    64,               /* numOMProcesses */
    64,               /* numOMGobjs */
    sizeof(GObj),     /* objectSize */
    1024,             /* numOMMtx */
    0,                /* unk60 */
    NULL,             /* unk64 */
    16,               /* numOMAobjs */
    8,                /* numOMMobjs */
    16,               /* numOMDobjs */
    sizeof(DObj),     /* omDobjSize */
    128,              /* numOMSobjs */
    0x58,             /* omSobjSize */
    8,                /* numOMCameras */
    sizeof(OMCamera), /* omCameraSize */
    new_game_init     /* postInitFunc */
};

s32 menu_new_game_entry(s32 arg0) {
    viApplyScreenSettings(&menu_new_game_video_settings);
    menu_new_game_setup.gtlSetup.heapSize = (uintptr_t) window_VRAM - (uintptr_t) menu_new_game_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&menu_new_game_setup);
    setPlayerFlag(PFID_16, 1);
    return SCENE_OAKS_LAB;
}
