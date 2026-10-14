#undef __ANIMFILE
#define __ANIMFILE gate_animation

#include <anim_script.h>

/* The closed material script sets three packed colors in one command. */
typedef struct GateAnimLineColors3 {
    u32 cmd;
    u32 colors[3];
} GateAnimLineColors3;

extern AnimLine3 D_800F1E00_6F5B0;
extern AnimLine3 D_800F1E1C_6F5CC;
extern AnimLine1 D_800F1E50_6F600;
extern AnimLine1 D_800F1E7C_6F62C;
extern GateAnimLineColors3 D_800F1EA8_6F658;
extern AnimCmd* D_800F1EC4_6F674[];
extern AnimCmd* D_800F1EC8_6F678[];
extern AnimCmd* D_800F1ECC_6F67C[];
extern AnimLine3 D_800F1EE0_6F690;
extern AnimLine2 D_800F1EF8_6F6A8;
extern AnimLine1 D_800F1F30_6F6E0;
extern AnimLine1 D_800F1F58_6F708;
extern AnimLineI1 D_800F1F80_6F730;
extern AnimCmd* D_800F1FB8_6F768[];
extern AnimCmd* D_800F1FBC_6F76C[];
extern AnimCmd* D_800F1FC0_6F770[];
extern AnimLine2 D_800F1FE0_6F790;
extern AnimLine1 D_800F2010_6F7C0;
extern AnimLine1 D_800F2030_6F7E0;
extern AnimLine1 D_800F2058_6F808;
extern AnimLineI1 D_800F2080_6F830;
extern AnimCmd* D_800F20B8_6F868[];
extern AnimCmd* D_800F20BC_6F86C[];
extern AnimCmd* D_800F20C0_6F870[];
extern AnimLine3 D_800F20E0_6F890;
extern AnimLine1 D_800F20FC_6F8AC;
extern AnimLine1 D_800F2120_6F8D0;
extern AnimLine1 D_800F214C_6F8FC;
extern AnimLineI1 D_800F2178_6F928;
extern AnimCmd* D_800F21B4_6F964[];
extern AnimCmd* D_800F21B8_6F968[];
extern AnimCmd* D_800F21BC_6F96C[];

/* modelanim closed */
AnimCmd* gate_modelanim_closed[] = {
    NULL,
    NULL,
    (AnimCmd*) &D_800F1E00_6F5B0,
    (AnimCmd*) &D_800F1E1C_6F5CC,
};

AnimLine3 D_800F1E00_6F5B0 =
    asSetAfter_3f(0, SCALEX, 0.03999999910593033, SCALEY, 0.009999999776482582, SCALEZ, 0.022390341386198997);
asWait(100);
asRestart(D_800F1E00_6F5B0);

AnimLine3 D_800F1E1C_6F5CC =
    asSetAfter_3f(0, POSX, 0.0, POSY, 469.9999694824219, POSZ, -21.999996185302734);
asWait(100);
asRestart(D_800F1E1C_6F5CC);

__ALIGNER

/* matanim closed */
AnimCmd** gate_matanim_closed[] = {
    NULL,
    D_800F1EC4_6F674,
    D_800F1EC8_6F678,
    D_800F1ECC_6F67C,
};

AnimLine1 D_800F1E50_6F600 =
    asSet_1f(0, OFFSET_S, 0.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_T, 0.0, SCALE_S, 2.0, SCALE_T, 1.0);
asSetBlock_1(100, OFFSET_S, -1.0);
asRestart(D_800F1E50_6F600);

AnimLine1 D_800F1E7C_6F62C =
    asSet_1f(0, OFFSET_T, -1.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_S, 0.0, SCALE_S, 1.0, SCALE_T, 2.0);
asSetBlock_1(100, OFFSET_T, 0.0);
asRestart(D_800F1E7C_6F62C);

GateAnimLineColors3 D_800F1EA8_6F658 = {
    (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR | LIGHT_COLOR_1 | LIGHT_COLOR_2) << 15),
    {
        ((u32) 102 << 24) | (0 << 16) | (102 << 8) | 255,
        ((u32) 255 << 24) | (255 << 16) | (255 << 8) | 0,
        ((u32) 38 << 24) | (38 << 16) | (38 << 8) | 0,
    }
};
asWait(100);
asRestart(D_800F1EA8_6F658);

AnimCmd* D_800F1EC4_6F674[] = {
    (AnimCmd*) &D_800F1E50_6F600,
};

AnimCmd* D_800F1EC8_6F678[] = {
    (AnimCmd*) &D_800F1E7C_6F62C,
};

AnimCmd* D_800F1ECC_6F67C[] = {
    (AnimCmd*) &D_800F1EA8_6F658,
};

/* modelanim raise bar */
AnimCmd* gate_modelanim_raise_bar[] = {
    NULL,
    NULL,
    (AnimCmd*) &D_800F1EE0_6F690,
    (AnimCmd*) &D_800F1EF8_6F6A8,
};

AnimLine3 D_800F1EE0_6F690 =
    asSetAfter_3f(0, SCALEX, 0.03999999910593033, SCALEY, 0.009999999776482582, SCALEZ, 0.022390341386198997);
asWait(100);
asEnd();

AnimLine2 D_800F1EF8_6F6A8 =
    asSet_2f(0, POSY, 469.9999694824219, POSZ, -15.999998092651367);
asSetAfter_1(0, POSX, 0.0);
asSetBlock_2(100, POSY, 528.6123046875, POSZ, 0.0);
asEnd();

static u8 gate_animation_padding_800F1F1C[4] = { 0 };

/* matanim raise bar */
AnimCmd** gate_matanim_raise_bar[] = {
    NULL,
    D_800F1FB8_6F768,
    D_800F1FBC_6F76C,
    D_800F1FC0_6F770,
};

AnimLine1 D_800F1F30_6F6E0 =
    asSet_1f(0, OFFSET_S, 0.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_T, 0.0, SCALE_S, 2.0, SCALE_T, 1.0);
asSetBlock_1(100, OFFSET_S, -1.0);
asEnd();

AnimLine1 D_800F1F58_6F708 =
    asSet_1f(0, OFFSET_T, -1.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_S, 0.0, SCALE_S, 1.0, SCALE_T, 2.0);
asSetBlock_1(100, OFFSET_T, 0.0);
asEnd();

AnimLineI1 D_800F1F80_6F730 =
    asSetExtra_1f(0, PRIM_COLOR, 102, 0, 102, 255);
asSetExtraAfterBlock_2(0, LIGHT_COLOR_1, 255, 255, 255, 0, LIGHT_COLOR_2, 38, 38, 38, 0);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 0, 255, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 255, 255, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 255, 0, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 102, 0, 102, 255);
asEnd();

AnimCmd* D_800F1FB8_6F768[] = {
    (AnimCmd*) &D_800F1F30_6F6E0,
};

AnimCmd* D_800F1FBC_6F76C[] = {
    (AnimCmd*) &D_800F1F58_6F708,
};

AnimCmd* D_800F1FC0_6F770[] = {
    (AnimCmd*) &D_800F1F80_6F730,
};

static u8 gate_animation_padding_800F1FC4[12] = { 0 };

/* modelanim opening */
AnimCmd* gate_modelanim_opening[] = {
    NULL,
    NULL,
    (AnimCmd*) &D_800F1FE0_6F790,
    (AnimCmd*) &D_800F2010_6F7C0,
};

AnimLine2 D_800F1FE0_6F790 =
    asSet_2f(0, SCALEX, 0.03999999910593033, SCALEY, 0.009999999776482582);
asSetAfter_1(0, SCALEZ, 0.022390341386198997);
asSetBlock_2(50, SCALEX, 0.03999999910593033, SCALEY, 1.0);
asSetBlock_2(50, SCALEX, 1.0, SCALEY, 1.0);
asEnd();

AnimLine1 D_800F2010_6F7C0 =
    asSetAfter_1f(0, POSY, 528.6123046875);
asWait(100);
asEnd();

/* matanim opening */
AnimCmd** gate_matanim_opening[] = {
    NULL,
    D_800F20B8_6F868,
    D_800F20BC_6F86C,
    D_800F20C0_6F870,
};

AnimLine1 D_800F2030_6F7E0 =
    asSet_1f(0, OFFSET_S, 0.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_T, 0.0, SCALE_S, 2.0, SCALE_T, 1.0);
asSetBlock_1(100, OFFSET_S, -1.0);
asEnd();

AnimLine1 D_800F2058_6F808 =
    asSet_1f(0, OFFSET_T, -1.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_S, 0.0, SCALE_S, 1.0, SCALE_T, 2.0);
asSetBlock_1(100, OFFSET_T, 0.0);
asEnd();

AnimLineI1 D_800F2080_6F830 =
    asSetExtra_1f(0, PRIM_COLOR, 102, 0, 102, 255);
asSetExtraAfterBlock_2(0, LIGHT_COLOR_1, 255, 255, 255, 0, LIGHT_COLOR_2, 38, 38, 38, 0);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 255, 0, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 102, 0, 102, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 255, 0, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 102, 0, 102, 255);
asEnd();

AnimCmd* D_800F20B8_6F868[] = {
    (AnimCmd*) &D_800F2030_6F7E0,
};

AnimCmd* D_800F20BC_6F86C[] = {
    (AnimCmd*) &D_800F2058_6F808,
};

AnimCmd* D_800F20C0_6F870[] = {
    (AnimCmd*) &D_800F2080_6F830,
};

static u8 gate_animation_padding_800F20C4[12] = { 0 };

/* modelanim opened */
AnimCmd* gate_modelanim_opened[] = {
    NULL,
    NULL,
    (AnimCmd*) &D_800F20E0_6F890,
    (AnimCmd*) &D_800F20FC_6F8AC,
};

AnimLine3 D_800F20E0_6F890 =
    asSetAfter_3f(0, SCALEX, 1.0, SCALEY, 1.0, SCALEZ, 0.022390341386198997);
asWait(100);
asRestart(D_800F20E0_6F890);

AnimLine1 D_800F20FC_6F8AC =
    asSetAfter_1f(0, POSY, 528.6123046875);
asWait(100);
asRestart(D_800F20FC_6F8AC);

/* matanim opened */
AnimCmd** gate_matanim_opened[] = {
    NULL,
    D_800F21B4_6F964,
    D_800F21B8_6F968,
    D_800F21BC_6F96C,
};

AnimLine1 D_800F2120_6F8D0 =
    asSet_1f(0, OFFSET_S, 0.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_T, 0.0, SCALE_S, 2.0, SCALE_T, 1.0);
asSetBlock_1(100, OFFSET_S, -1.0);
asRestart(D_800F2120_6F8D0);

AnimLine1 D_800F214C_6F8FC =
    asSet_1f(0, OFFSET_T, -1.0);
asSetAfter_4(0, IMG_INDEX, 0.0, OFFSET_S, 0.0, SCALE_S, 1.0, SCALE_T, 2.0);
asSetBlock_1(100, OFFSET_T, 0.0);
asRestart(D_800F214C_6F8FC);

AnimLineI1 D_800F2178_6F928 =
    asSetExtra_1f(0, PRIM_COLOR, 102, 0, 102, 255);
asSetExtraAfterBlock_2(0, LIGHT_COLOR_1, 255, 255, 255, 0, LIGHT_COLOR_2, 38, 38, 38, 0);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 255, 0, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 102, 0, 102, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 255, 255, 0, 255);
asSetExtraBlock_1(25, PRIM_COLOR, 102, 0, 102, 255);
asRestart(D_800F2178_6F928);

AnimCmd* D_800F21B4_6F964[] = {
    (AnimCmd*) &D_800F2120_6F8D0,
};

AnimCmd* D_800F21B8_6F968[] = {
    (AnimCmd*) &D_800F214C_6F8FC,
};

AnimCmd* D_800F21BC_6F96C[] = {
    (AnimCmd*) &D_800F2178_6F928,
};
