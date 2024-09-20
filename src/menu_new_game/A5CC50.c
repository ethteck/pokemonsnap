#include "common.h"
#include "ld_addrs.h"
#include "sys/vi.h"
#include "sys/gtl.h"
#include "../unk_end_level/unk_end_level.h"

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
static UnkSnowHerring* D_801180C0[20];
UnkSnowHerring* D_80118110;
UnkSnowHerring* D_80118114;
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
    UnkSnowHerring* id;
    UnkFireHerring* unk;
    s8 i;
    ucolor sp28;

    unk = func_8036F78C_842F3C();
    func_8036F684_842E34(unk, 1);
    func_8036F738_842EE8(unk, &sp28);
    func_8036F1F4_8429A4(unk, 184, 320);
    func_8036F0DC_84288C(unk, true);
    func_8036F0A0_842850(unk, false);
    func_8036FE54_843604(unk, 1);

    // description
    id = func_8036AC6C_83E41C(104, 173, 192, 47, 0);
    func_8036B870_83F020(id, 1, 255, 255, 255, 255);
    func_8036B870_83F020(id, 0, sp28.r, sp28.g, sp28.b, 255);
    func_8036B734_83EEE4(id);
    func_8036B9EC_83F19C(id, 0, 0);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036CB58_840308(id, 12);
    func_8036C898_840048(id, "Enter your name on the card.\n"
                             "Choose with the Control Stick\n"
                             "and select with the \\a Button!");

    // character grid
    for (i = 0; i < ARRAY_COUNT(D_801180C0); i++) {
        func_8036D4A0_840C50(0);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        id = func_8036AC6C_83E41C(23, i * 10 + 20, 60, 8, 0);
        func_8036CB58_840308(id, 8);
        func_8036B870_83F020(id, 0, 0, 0, 0, 0);
        func_8036B734_83EEE4(id);
        D_801180C0[i] = id;
    }

    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);

    // name input
    id = func_8036AC6C_83E41C(203, 64, 62, 12, 0x400);
    func_8036CB58_840308(id, 12);
    func_8036B870_83F020(id, 0, 0, 0, 0, 0);
    func_8036B870_83F020(id, 1, 0, 0, 0, 255);
    func_8036B734_83EEE4(id);
    D_80118110 = id;

    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);

    id = func_8036AC6C_83E41C(206, 64, 12, 12, 0x400);
    func_8036CB58_840308(id, 12);
    func_8036B870_83F020(id, 0, 0, 0, 0, 0);
    func_8036B870_83F020(id, 1, 255, 0, 0, 255);
    func_8036B734_83EEE4(id);
    D_80118114 = id;
}

void func_800E1CF8_A5D0A8(s8 arg0) {
    s16 i;
    s16 j;
    UnkSnowHerring* temp_s2;
    s16 temp_s1;
    char** temp_s4 = func_800E18B4_A5CC64(arg0);

    for (i = 0; i < ARRAY_COUNT(D_801180C0); i++) {
        func_8036A8E4_83E094(D_801180C0[i]);
    }

    temp_s1 = 0;
    func_8036D4B4_840C64(1, 0);

    for (i = 0; i < ARRAY_COUNT(D_801180C0) - 1; i++) {
        temp_s2 = D_801180C0[i];
        for (j = 0; j < 5; j++) {
            func_8036B9EC_83F19C(temp_s2, j * 13, 0);
            func_8036C898_840048(temp_s2, temp_s4[temp_s1++]);
        }
    }

    func_8036D4B4_840C64(1, 1);
    temp_s1 = 0;
    temp_s2 = D_801180C0[i];
    for (j = 0; j < 4; j++) {
        func_8036B9EC_83F19C(temp_s2, j * 13, 0);
        func_8036C898_840048(temp_s2, D_800E356C[temp_s1++]);
    }
}

void func_800E1E94_A5D244(void) {
    func_80370428_843BD8();
    func_803700A4_843854(0);
    func_80370038_8437E8(4, 5);
    func_8036FFE0_843790(25, 22);
    func_80370134_8438E4();
    func_803700A4_843854(1);
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
    func_8036EB98_842348();
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
    menu_new_game_setup.gtlSetup.heapSize = (uintptr_t) unk_end_level_VRAM - (uintptr_t) menu_new_game_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&menu_new_game_setup);
    setPlayerFlag(PFID_16, 1);
    return SCENE_11;
}
