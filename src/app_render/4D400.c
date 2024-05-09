#include "common.h"

typedef struct Some14 {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ s8 unk_10;
    /* 0x11 */ s8 unk_11;
    /* 0x12 */ s8 unk_12;
    /* 0x13 */ char unk_13[0x1];
} Some14;

extern Some14 D_800AEBD0;
extern s32 D_800AEC08;
extern s32 D_800AEC0C;
extern s32 D_800AEC10;
extern Gfx D_800AEC18[];

void func_800A1A50(Gfx** gfx) {
    gSPDisplayList((*gfx)++, D_800AEC18);
}

void func_800A1A74(s32 arg0) {
    f32 theta;
    f32 cos;
    UNUSED s32 pad;
    f32 sin;
    s32 var_a1;

    theta = ((f32) (arg0 * 0.25) * M_PI_F) / 180.0f;
    cos = __cosf(theta) * 127.0;
    sin = __sinf(theta);
    D_800AEBD0.unk_10 = cos;
    D_800AEBD0.unk_11 = (f32) (sin * 127.0);
    D_800AEBD0.unk_12 = 0;

    if (arg0 >= 880 && arg0 <= 1280) {
        var_a1 = arg0 - 1080 < 0 ? 1080 - arg0 : arg0 - 1080;
        gSPFogPosition(&D_800AEC18[3], 996 - ((200 - var_a1) / 5), 1000);
    } else {
        gSPFogFactor(&D_800AEC18[3], 256, -512);
    }

    if (arg0 >= 720 && arg0 < 800) {
        D_800AEC08 = 200 - (((arg0 - 720) / 5) * 2);
        if (D_800AEC08 < 0) {
            D_800AEC08 = 0;
        }
        D_800AEC0C = 200 - (((arg0 - 720) / 5) * 5);
        if (D_800AEC0C < 0) {
            D_800AEC0C = 0;
        }
        D_800AEC10 = 200 - (((arg0 - 720) / 5) * 5);
        if (D_800AEC10 < 0) {
            D_800AEC10 = 0;
        }
    } else if (arg0 >= 0x320 && arg0 < 880) {
        D_800AEC08 = 170 - (((arg0 - 800) / 3) * 4);
        if (D_800AEC08 < 0) {
            D_800AEC08 = 0;
        }
        D_800AEC0C = 125 - (((arg0 - 800) / 3) * 4);
        if (D_800AEC0C < 0) {
            D_800AEC0C = 0;
        }
        D_800AEC10 = 125 - (((arg0 - 800) / 3) * 4);
        if (D_800AEC10 < 0) {
            D_800AEC10 = 0;
        }
    } else if (arg0 >= 880 && arg0 < 1280) {
        D_800AEC08 = 66;
        D_800AEC0C = 21;
        D_800AEC10 = 21;
    } else if (arg0 >= 1280 && arg0 < 1440) {
        D_800AEC08 = (((arg0 - 1280) / 3) * 4) + 66;
        if (D_800AEC08 > 200) {
            D_800AEC08 = 200;
        }
        D_800AEC0C = (((arg0 - 1280) / 3) * 4) + 21;;
        if (D_800AEC0C > 200) {
            D_800AEC0C = 200;
        }
        D_800AEC10 = (((arg0 - 1280) / 3) * 4) + 21;;
        if (D_800AEC10 > 200) {
            D_800AEC10 = 200;
        }
    } else {
        D_800AEC08 = 200;
        D_800AEC0C = 200;
        D_800AEC10 = 200;
    }
}

void func_800A1E44(s32* arg0, s32* arg1, s32* arg2) {
    *arg0 = D_800AEC08;
    *arg1 = D_800AEC0C;
    *arg2 = D_800AEC10;
}

void func_800A1E6C(Vec3f* arg0) {
    D_800AEBD0.unk_10 = arg0->x * 127.0f;
    D_800AEBD0.unk_11 = arg0->y * 127.0f;
    D_800AEBD0.unk_12 = arg0->z * 127.0f;
}
