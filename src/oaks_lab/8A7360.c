#include "common.h"
#include "oaks_lab.h"

#include "build/assets/oaks_lab/lab_bg.png.inc.h"
static u8 aligner_0[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak.png.inc.h"
static u8 aligner_1[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen.png.inc.h"
static u8 aligner_2[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_save_error.png.inc.h"
static u8 aligner_3[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_stage_tunnel.png.inc.h"
static u8 aligner_4[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_stage_river.png.inc.h"
static u8 aligner_5[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_stage_cave.png.inc.h"
static u8 aligner_6[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_stage_rainbow_cloud.png.inc.h"
static u8 aligner_7[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_stage_valley.png.inc.h"
static u8 aligner_8[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_stage_beach.png.inc.h"
static u8 aligner_9[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_stage_vulcano.png.inc.h"
static u8 aligner_10[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_album.png.inc.h"
static u8 aligner_11[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_island.png.inc.h"
static u8 aligner_12[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_zero_one.png.inc.h"
static u8 aligner_13[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_end_gate.png.inc.h"
static u8 aligner_14[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_engine.png.inc.h"
static u8 aligner_15[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_apple.png.inc.h"
static u8 aligner_16[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_pester_ball.png.inc.h"
static u8 aligner_17[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_pokeflute.png.inc.h"
static u8 aligner_18[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_screen_bg.png.inc.h"
static u8 aligner_19[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_0.png.inc.h"
static u8 aligner_20[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_1.png.inc.h"
static u8 aligner_21[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_2.png.inc.h"
static u8 aligner_22[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_3.png.inc.h"
static u8 aligner_23[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_4.png.inc.h"
static u8 aligner_24[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_5.png.inc.h"
static u8 aligner_25[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_mouth_6.png.inc.h"
static u8 aligner_26[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_0.png.inc.h"
static u8 aligner_27[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_1.png.inc.h"
static u8 aligner_28[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_2.png.inc.h"
static u8 aligner_29[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_3.png.inc.h"
static u8 aligner_30[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_4.png.inc.h"
static u8 aligner_31[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_5.png.inc.h"
static u8 aligner_32[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_6.png.inc.h"
static u8 aligner_33[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_7.png.inc.h"
static u8 aligner_34[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_8.png.inc.h"
static u8 aligner_35[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_9.png.inc.h"
static u8 aligner_36[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_10.png.inc.h"
static u8 aligner_37[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_11.png.inc.h"
static u8 aligner_38[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/lab_oak_eyes_12.png.inc.h"
static u8 aligner_39[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_0.png.inc.h"
static u8 aligner_40[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_1.png.inc.h"
static u8 aligner_41[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_2.png.inc.h"
static u8 aligner_42[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_3.png.inc.h"
static u8 aligner_43[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_4.png.inc.h"
static u8 aligner_44[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_5.png.inc.h"
static u8 aligner_45[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_6.png.inc.h"
static u8 aligner_46[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_7.png.inc.h"
static u8 aligner_47[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_0.png.inc.h"
static u8 aligner_48[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_1.png.inc.h"
static u8 aligner_49[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_2.png.inc.h"
static u8 aligner_50[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_3.png.inc.h"
static u8 aligner_51[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_4.png.inc.h"
static u8 aligner_52[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_5.png.inc.h"
static u8 aligner_53[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_6.png.inc.h"
static u8 aligner_54[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_7.png.inc.h"
static u8 aligner_55[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_8.png.inc.h"
static u8 aligner_56[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_9.png.inc.h"
static u8 aligner_57[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_10.png.inc.h"
static u8 aligner_58[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_bg.png.inc.h"
static u8 aligner_59[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_zero_one_8.png.inc.h"
static u8 aligner_60[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_11.png.inc.h"
static u8 aligner_61[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_12.png.inc.h"
static u8 aligner_62[] = { 0, 0, 0, 0 };
#include "build/assets/oaks_lab/map_todd_13.png.inc.h"

s32 D_801957EC_95B00C = 0;

extern s32 D_80195850_95B070;
extern s32 D_80195854_95B074;
extern s32 D_80195858_95B078;
extern s32 D_8019585C_95B07C;
extern s32 D_80195860_95B080[4];
extern s32 D_80195870_95B090;
extern s32 D_80195874_95B094[5];

s32 func_800E3ED4_8A96F4(void);
void func_800E5298_8AAAB8(void);
void func_800E6410_8ABC30(void);

UIElement* func_800E1B40_8A7360(void) {
    return D_80206B1C_9CC33C;
}

UIFrame* func_800E1B4C_8A736C(void) {
    return D_80206B20_9CC340;
}

void func_800E1B58_8A7378(u32 arg0) {
    D_80206B30_9CC350->sprite.red = arg0;
    D_80206B30_9CC350->sprite.green = arg0;
    D_80206B30_9CC350->sprite.blue = arg0;
    D_80206B10_9CC330->sprite.red = arg0;
    D_80206B10_9CC330->sprite.green = arg0;
    D_80206B10_9CC330->sprite.blue = arg0;
    D_80206B14_9CC334->sprite.red = arg0;
    D_80206B14_9CC334->sprite.green = arg0;
    D_80206B14_9CC334->sprite.blue = arg0;
    D_80206B18_9CC338->sprite.red = arg0;
    D_80206B18_9CC338->sprite.green = arg0;
    D_80206B18_9CC338->sprite.blue = arg0;

    func_800E614C_8AB96C(arg0);
}

void func_800E1BF4_8A7414(u32 intensity) {
    D_80206B10_9CC330->sprite.red = intensity;
    D_80206B10_9CC330->sprite.green = intensity;
    D_80206B10_9CC330->sprite.blue = intensity;
}

void func_800E1C18_8A7438(s32 arg0) {
    if (arg0) {
        D_80206B30_9CC350->sprite.attr |= SP_HIDDEN;
        D_80206B14_9CC334->sprite.attr |= SP_HIDDEN;
        D_80206B10_9CC330->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80206B30_9CC350->sprite.attr &= ~SP_HIDDEN;
        D_80206B14_9CC334->sprite.attr &= ~SP_HIDDEN;
        D_80206B10_9CC330->sprite.attr |= SP_HIDDEN;
    }
}

void func_800E1CA0_8A74C0(GObj* arg0) {
    f32 temp_f2;
    f32 var_f0;
    static f32 bla = -72;

    if (D_801957EC_95B00C != 0) {
        var_f0 = 13.0f;
    } else {
        var_f0 = -72.0f;
    }
    temp_f2 = bla + (var_f0 - bla) * 0.2;
    D_80206B18_9CC338->sprite.y = temp_f2;
    bla = temp_f2;
}

// Stage icons
Bitmap* D_801957F4_95B014[] = {
    lab_stage_beach_bitmaps,
    lab_stage_tunnel_bitmaps,
    lab_stage_vulcano_bitmaps,
    lab_stage_river_bitmaps,
    lab_stage_cave_bitmaps,
    lab_stage_valley_bitmaps,
    map_stage_rainbow_cloud_bitmaps,
};

Bitmap* D_80195810_95B030[3][2] = {
    lab_oak_mouth_3_bitmaps,
    lab_oak_mouth_0_bitmaps,
    lab_oak_mouth_4_bitmaps,
    lab_oak_mouth_1_bitmaps,
    lab_oak_mouth_5_bitmaps,
    lab_oak_mouth_2_bitmaps,
};
Bitmap* D_80195828_95B048[5][2] = {
    {
        lab_oak_eyes_4_bitmaps,
        lab_oak_mouth_6_bitmaps,
    },
    {
        lab_oak_eyes_5_bitmaps,
        lab_oak_eyes_0_bitmaps,
    },
    {
        lab_oak_eyes_6_bitmaps,
        lab_oak_eyes_1_bitmaps,
    },
    {
        lab_oak_eyes_11_bitmaps,
        lab_oak_eyes_9_bitmaps,
    },
    {
        lab_oak_eyes_12_bitmaps,
        lab_oak_eyes_10_bitmaps,
    },
};

void func_800E1D1C_8A753C(s32 arg0) {
    if (arg0) {
        D_801957EC_95B00C = 1;
        D_80206B28_9CC348[1]->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_801957EC_95B00C = 0;
        D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
    }
}

void func_800E1D68_8A7588(u32 arg0) {
    switch (arg0) {
        case 0:
            D_801957EC_95B00C = 0;
            D_80206B28_9CC348[0]->sprite.attr |= SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
            return;
        case 1:
            D_801957EC_95B00C = 1;
            return;
        case 2:
            D_80206B28_9CC348[0]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[0]->sprite.bitmap = lab_screen_album_bitmaps; // Album
            D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
            return;
        case 3:
            D_80206B28_9CC348[0]->sprite.attr |= SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.bitmap = lab_screen_island_bitmaps; // Island
            return;
        case 4:
            D_80206B28_9CC348[0]->sprite.attr |= SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.bitmap = lab_screen_zero_one_bitmaps; // zero-one
            return;
        case 5:
            D_80206B28_9CC348[0]->sprite.attr |= SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.bitmap = lab_stage_beach_bitmaps; // Beach
            return;
        case 6:
            D_80206B28_9CC348[0]->sprite.attr |= SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[1]->sprite.bitmap = lab_screen_end_gate_bitmaps; // end gate
            return;
        case 7:
            D_80206B28_9CC348[0]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[0]->sprite.bitmap = lab_screen_apple_bitmaps; // apple
            D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
            return;
        case 8:
            D_80206B28_9CC348[0]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[0]->sprite.bitmap = lab_screen_pester_ball_bitmaps; // pester ball
            D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
            return;
        case 9:
            D_80206B28_9CC348[0]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[0]->sprite.bitmap = lab_screen_pokeflute_bitmaps; // pokeflute
            D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
            return;
        case 10:
            D_80206B28_9CC348[0]->sprite.attr &= ~SP_HIDDEN;
            D_80206B28_9CC348[0]->sprite.bitmap = lab_screen_engine_bitmaps; // engine
            D_80206B28_9CC348[1]->sprite.attr |= SP_HIDDEN;
            return;
    }
}
void func_800E1FEC_8A780C(s32 stage) {
    if (stage >= 0 && stage < 7U) {
        D_80206B28_9CC348[1]->sprite.bitmap = D_801957F4_95B014[stage];
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        func_800E1D1C_8A753C(1);
    } else {
        func_800E1D1C_8A753C(0);
    }
}

void func_800E2058_8A7878(GObj* gobj) {
    s32 var_s4;
    u32 var_s6;
    u32 var_s5;

    var_s4 = 0;
    var_s5 = 12;
    var_s6 = 0;
    while (true) {
        if (D_80195850_95B070 == 2) {
            gobj->data.sobj->unk_58->next->sprite.bitmap = D_80195810_95B030[0][D_80195850_95B070];
            gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[0][D_80195850_95B070];
        } else {
            if (D_80195854_95B074 != 0) {
                D_80195854_95B074--;
                if (D_80195854_95B074 == 0) {
                    var_s4 = 0;
                    gobj->data.sobj->unk_58->next->sprite.bitmap = D_80195810_95B030[0][D_80195850_95B070];
                } else if (var_s5 > 0) {
                    var_s5--;
                } else {
                    var_s6 = (var_s6 + 1) % ARRAY_COUNT(D_80195860_95B080);
                    var_s5 = 7;
                    var_s4 = D_80195860_95B080[var_s6];
                }
                gobj->data.sobj->unk_58->next->sprite.bitmap = D_80195810_95B030[var_s4][D_80195850_95B070];
            }

            if (D_8019585C_95B07C < -30) {
                D_8019585C_95B07C++;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[3][D_80195850_95B070];
            } else if (D_8019585C_95B07C < -6) {
                D_8019585C_95B07C++;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[4][D_80195850_95B070];
            } else if (D_8019585C_95B07C < 0) {
                D_8019585C_95B07C++;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[3][D_80195850_95B070];
            } else if (D_8019585C_95B07C == 0) {
                D_8019585C_95B07C = 180;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[0][D_80195850_95B070];
            } else if (D_8019585C_95B07C > 18) {
                D_8019585C_95B07C--;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[0][D_80195850_95B070];
            } else if (D_8019585C_95B07C > 12) {
                D_8019585C_95B07C--;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[1][D_80195850_95B070];
            } else if (D_8019585C_95B07C > 6) {
                D_8019585C_95B07C--;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[2][D_80195850_95B070];
            } else {
                D_8019585C_95B07C--;
                gobj->data.sobj->unk_58->sprite.bitmap = D_80195828_95B048[1][D_80195850_95B070];
            }
        }

        ohWait(1);
    }
}

void func_800E2350_8A7B70(void) {
    D_80195850_95B070 = 0;
}

void func_800E235C_8A7B7C(s32 arg0) {
    D_80195854_95B074 = 12;
    switch (arg0) {
        case '\\N':
            D_80195850_95B070 = 0;
            D_80195870_95B090 = 0;
            break;
        case '\\O':
            D_80195850_95B070 = 1;
            break;
        case '\\M':
            D_8019585C_95B07C = -36;
            break;
        case '\\0':
            func_800E1D68_8A7588(0);
            break;
        case '\\1':
            func_800E1D68_8A7588(1);
            break;
        case '\\2':
            func_800E1D68_8A7588(2);
            break;
        case '\\3':
            func_800E1D68_8A7588(3);
            break;
        case '\\4':
            func_800E1D68_8A7588(4);
            break;
        case '\\5':
            func_800E1D68_8A7588(5);
            break;
        case '\\6':
            func_800E1D68_8A7588(6);
            break;
        case '\\7':
            func_800E1D68_8A7588(7);
            if (D_80195870_95B090 == 0) {
                auPlaySong(1, 0x20);
            }
            D_80195870_95B090 = 1;
            break;
        case '\\8':
            func_800E1D68_8A7588(8);
            if (D_80195870_95B090 == 0) {
                auPlaySong(1, 0x20);
            }
            D_80195870_95B090 = 1;
            break;
        case '\\9':
            func_800E1D68_8A7588(9);
            if (D_80195870_95B090 == 0) {
                auPlaySong(1, 0x20);
            }
            D_80195870_95B090 = 1;
            break;
        case '\\A':
            func_800E1D68_8A7588(10);
            if (D_80195870_95B090 == 0) {
                auPlaySong(1, 0x20);
            }
            D_80195870_95B090 = 1;
            break;
        case '\\B':
            auPlaySoundWithParams(0xA2, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\C':
            auPlaySoundWithParams(0xA3, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\D':
            auPlaySoundWithParams(0xA4, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\E':
            auPlaySoundWithParams(0xA5, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\F':
            auPlaySoundWithParams(0xA6, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\G':
            auPlaySoundWithParams(0xA7, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\H':
            auPlaySoundWithParams(0xA8, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\I':
            auPlaySoundWithParams(0xA9, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\J':
            auPlaySoundWithParams(0xAA, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\K':
            auPlaySoundWithParams(0xAB, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\L':
            auPlaySoundWithParams(0xAC, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\P':
            auPlaySoundWithParams(0xAD, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\Q':
            auPlaySoundWithParams(0xAE, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\S':
            auPlaySoundWithParams(0xAF, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\T':
            auPlaySoundWithParams(0xB0, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\U':
            auPlaySoundWithParams(0xB1, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\V':
            auPlaySoundWithParams(0xB2, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\W':
            auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case '\\X':
            auPlaySoundWithParams(0xA1, 0x7FFF, 0x40, 0.75f, 0);
            break;
        default:
            if (arg0 >= 'あ' && arg0 <= 'も') {
                D_80195858_95B078 = D_80195874_95B094[(arg0 - 'あ') % ARRAY_COUNT(D_80195874_95B094)];
                return;
            } else if (arg0 >= 'ア' && arg0 <= 'モ') {
                D_80195858_95B078 = D_80195874_95B094[(arg0 - 'ア') % ARRAY_COUNT(D_80195874_95B094)];
                return;
            } else if (arg0 == 'ん' || arg0 == 'ン' || arg0 == '　') {
                D_80195858_95B078 = 0;
            } else if (arg0 & 0x8000) {
                D_80195858_95B078 = -1;
            }
            break;
    }
}

void func_800E2848_8A8068(void) {
    SObj* sobj;

    sobj = func_80371D14_8454C4(func_800E2058_8A7878, 6, &lab_oak_sprite)->data.sobj;
    D_80206B14_9CC334 = sobj;
    sobj->sprite.x = 100;
    sobj->sprite.y = 34;

    sobj = func_80371E68_845618(sobj, &lab_oak_mouth_6_sprite);
    sobj->sprite.x = 43;
    sobj->sprite.y = 32;
    sobj = func_80371DC0_845570(sobj, &lab_oak_mouth_0_sprite);
    sobj->sprite.x = 40;
    sobj->sprite.y = 50;

    sobj = func_80371C68_845418(func_800E1CA0_8A74C0, 6, &lab_screen_sprite)->data.sobj;
    D_80206B18_9CC338 = sobj;
    sobj->sprite.x = 208;
    sobj->sprite.y = 13;

    sobj = func_80371E68_845618(sobj, &lab_stage_beach_sprite);
    sobj->sprite.x = 6;
    sobj->sprite.y = 6;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80206B28_9CC348[1] = sobj;

    sobj = func_80371DC0_845570(sobj, &lab_screen_apple_sprite);
    sobj->sprite.x = 25;
    sobj->sprite.y = 13;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80206B28_9CC348[0] = sobj;
}

s32 func_800E2960_8A8180(UIElement* arg0, char** arg1, s32 arg2) {
    s32 button;

    while (*arg1) {
        UIElement_Draw(arg0);
        func_8037519C_84894C(arg0, *arg1, getPlayerName());
        button = func_80374F30_8486E0(arg0, true);
        if (arg2 && (button == B_BUTTON)) {
            return B_BUTTON;
        }
        arg1++;
    }

    return 0;
}

void func_800E2A04_8A8224(void) {
    UIElement* sp24;
    s32 temp_a1;
    s32 temp_s0;
    s32 i;

    sp24 = D_80206B1C_9CC33C;
    UIElement_SetFont(D_80206B1C_9CC33C, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    temp_s0 = func_800C0290_5D130();
    if (func_800BFC5C_5CAFC() < temp_s0) {
        func_800BFC70_5CB10(func_800C0290_5D130());
        ohWait(1);
        if (func_800BFC5C_5CAFC() != 2 && func_800BFC5C_5CAFC() != 4 && func_800BFC5C_5CAFC() != 6) {
            func_8036EB80_842330(0);
            UIText_SetPrintDelay(2);
            func_800E2960_8A8180(sp24, D_80195888_95B0A8, 0);
            UIText_SetPrintDelay(0);
        } else {
            ohWait(42);
        }
        auPlaySound(0x52);
        temp_a1 = func_800C0290_5D130() + 6;
        UILayout_ShowButton(1, temp_a1);
        UILayout_SetButtonScale(0.1f, temp_a1);
        if (func_800C0290_5D130() == 6) {
            func_800E60C8_8AB8E8();
        }
        for (i = 1; i < 30;) {
            UILayout_SetButtonScale((f32) i / 30.0f, temp_a1);
            i++;
            ohWait(1);
        }
        UILayout_SetButtonScale(1.0f, temp_a1);
        func_800E61B4_8AB9D4(3, 0);
        UIElement_Draw(sp24);
    }
    ohWait(15);
}

void func_800E2BAC_8A83CC(void) {
}

s32 func_800E2BB4_8A83D4(void) {
    s32 i;
    s32 ret;

    ret = 0;
    for (i = 0; i < 60; i++) {
        if (getAlbumPhoto(i) != 0) {
            ret++;
        }
    }

    return ret;
}

void func_800E2C0C_8A842C(GObj* arg0) {
    s32 unused2[3];
    s32 i;
    UIElement* sp4C;
    UIFrame* temp_v0;
    ucolor sp44;
    s32 unused1;
    s32 sp3C;

    UILayout_Init();
    FocusMark_Create();
    UIButtonImage_DeleteAll();
    FocusMark_Show(false);
    FocusMark_SetTargetSize(0x78, 0x1A);
    FocusMark_SetTargetPos(0x32, 0x2C);
    temp_v0 = UIFrame_Create();
    D_80206B20_9CC340 = temp_v0;
    UIFrame_SetStyle(temp_v0, FRAME_STYLE_1);
    UIFrame_GetBackgroundColor(temp_v0, &sp44);
    UIFrame_SetPos(temp_v0, 184, 320);
    UIFrame_Show(temp_v0, false);
    sp4C = UIElement_Create(104, 173, 192, 47, 0);
    D_80206B1C_9CC33C = sp4C;
    UIElement_SetColor(sp4C, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp4C, UI_BACKGROUND, sp44.r, sp44.g, sp44.b, 255);
    UIElement_DrawBackground(sp4C);
    UIElement_SetState(sp4C, UI_HIDDEN);
    if (func_800BF864_5C704() >= 4) {
        setPlayerFlag(PFID_HAS_FINISHED_TUTORIAL, 1);
    }

    for (i = 0; i < 60; i++) {
        func_800E1B58_8A7378(i * 255 / 60);
        ohWait(1);
    }

    func_800E1B58_8A7378(255);
    UILayout_ShowPanel(true);

    ohWait(30);

    if (func_800AAEE8(8) != 0) {
        func_800AAED0(8);
        if (checkPlayerFlag(PFID_6) == 0) {
            setPlayerFlag(PFID_6, 1);
            UILayout_CreateButtons(func_800E3230_8A8A50());
            setPlayerFlag(PFID_6, 0);
            UILayout_ShowButton(0, 3);
        } else {
            UILayout_CreateButtons(func_800E3230_8A8A50());
        }
    } else if (func_800AAEE8(0x20) != 0) {
        func_800AAED0(0x20);
        if (checkPlayerFlag(PFID_7) == 0) {
            setPlayerFlag(PFID_7, 1);
            UILayout_CreateButtons(func_800E3230_8A8A50());
            setPlayerFlag(PFID_7, 0);
            UILayout_ShowButton(0, 2);
        } else {
            UILayout_CreateButtons(func_800E3230_8A8A50());
        }
    } else {
        UILayout_CreateButtons(func_800E3230_8A8A50());
    }
    if (func_800BFC5C_5CAFC() != func_800C0290_5D130()) {
        func_800AAED0(0x400);
        setPlayerFlag(PFID_19, 0);
    }
    if (func_800E2BB4_8A83D4() == 0) {
        UILayout_DisableButton(1, 3);
    }
    UILayout_WaitPanelTransitionComplete();
    UIFrame_FadeIn(temp_v0, FRAME_STYLE_1);
    UIElement_SetState(sp4C, UI_NORMAL);
    UIText_SetPrintDelay(0);
    UIElement_SetFont(sp4C, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    func_800E5298_8AAAB8();
    func_800E6410_8ABC30();

    while (true) {
        sp3C = func_800E3ED4_8A96F4();
        func_80375284_848A34(3);
        FocusMark_Show(false);
        UIElement_SetState(D_80206B1C_9CC33C, UI_HIDDEN);
        UIFrame_ShowBackground(temp_v0, true);
        UILayout_SetHeaderFlags(0);
        UILayout_SetInstantTransition(false);
        UILayout_HideButtons();
        UILayout_WaitPanelTransitionComplete();
        UILayout_ShowPanel(false);

        for (i = 10; i >= 0; i--) {
            func_800E1B58_8A7378(i * 255 / 10);
            UIFrame_SetOpacity(temp_v0, i * 255 / 10);
            ohWait(1);
        }

        func_800E1B58_8A7378(0);
        UIButtonImage_DeleteAll();
        UILayout_WaitPanelTransitionComplete();
        func_800AAF10();
        ohWait(6);
        func_800AADF0(sp3C);
        ohWait(1);
    }
}

void func_800E307C_8A889C(void) {
    if ((osGetTime() & 0x28) == 0) {
        func_800BF780_5C620(randT());
    }
}

void func_800E30B8_8A88D8(void) {
    SObj* sobj;

    sobj = func_80371D14_8454C4(NULL, 6, &lab_save_error_sprite)->data.sobj;
    sobj->sprite.x = 40;
    sobj->sprite.y = 92;
    FocusMark_SetTargetPos(40, 92);
    FocusMark_SetTargetSize(240, 56);
    UIText_SetPrintDelay(1);
    func_8036EB80_842330(0);
    auSetBGMVolumeSmooth(0, 0x3F80, 60);
    UIElement_SetFont(D_80206B1C_9CC33C, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIElement_Draw(D_80206B1C_9CC33C);
    UIElement_PrintText(D_80206B1C_9CC33C, "\n\\OThis is... awful!");

    while (1) {
        ohWait(1);
    }
}

void func_800E3190_8A89B0(void) {
    func_800A85E8(func_800E2C0C_8A842C, LINK_6, DL_LINK_0, NULL);
    D_80206B30_9CC350 = func_80371D14_8454C4(NULL, 6, &lab_bg_sprite)->data.sobj;
    D_80206B10_9CC330 = func_80371D14_8454C4(NULL, 6, &map_bg_sprite)->data.sobj;
    func_800E2848_8A8068();
    func_800E66B8_8ABED8();
    func_8036EB8C_84233C(func_800E235C_8A7B7C);
    func_800E1B58_8A7378(0);
    func_800E1C18_8A7438(0);
}
