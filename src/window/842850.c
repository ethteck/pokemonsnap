#include "common.h"
#include "window.h"

extern Sprite D_80380C88_854438;
extern Bitmap* D_803818B0_855060[];
extern UnkFireHerring D_803A6A10_87A1C0;
extern s32 D_803A6A34_87A1E4;

void func_8036F0A0_842850(UnkFireHerring* arg0, bool show) {
    if (show) {
        arg0->unk_00[6]->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        arg0->unk_00[6]->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

void func_8036F0DC_84288C(UnkFireHerring* arg0, bool show) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_00); i++) {
        if (show) {
            arg0->unk_00[i]->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            arg0->unk_00[i]->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_8036F198_842948(UnkFireHerring* arg0, s32 alpha) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_00); i++) {
        arg0->unk_00[i]->data.sobj->sprite.alpha = alpha;
    }
}

void func_8036F1F4_8429A4(UnkFireHerring* arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;
    u16 new_var;

    arg0->unk_24 = arg1;
    arg0->unk_28 = arg2;

    arg0->unk_00[1]->data.sobj->sprite.x = arg1;
    arg0->unk_00[7]->data.sobj->sprite.x = arg1;
    arg0->unk_00[2]->data.sobj->sprite.x = arg1;

    temp_v0 = ((arg0->unk_00[2]->data.sobj->sprite.scalex * 8.0f) + arg1) - 1.0f;
    arg0->unk_00[8]->data.sobj->sprite.x = temp_v0;
    arg0->unk_00[6]->data.sobj->sprite.x = temp_v0;
    arg0->unk_00[5]->data.sobj->sprite.x = temp_v0;

    temp_v0 = (arg0->unk_2C + arg1) - 8;
    new_var = temp_v0; // required to match
    arg0->unk_00[3]->data.sobj->sprite.x = new_var;
    arg0->unk_00[0]->data.sobj->sprite.x = new_var;
    arg0->unk_00[4]->data.sobj->sprite.x = new_var;

    arg0->unk_00[4]->data.sobj->sprite.y = arg2;
    arg0->unk_00[5]->data.sobj->sprite.y = arg2;
    arg0->unk_00[2]->data.sobj->sprite.y = arg2;

    temp_v0 = ((arg0->unk_00[2]->data.sobj->sprite.scaley * 8.0f) + arg2) - 1.0f;
    arg0->unk_00[0]->data.sobj->sprite.y = temp_v0;
    arg0->unk_00[6]->data.sobj->sprite.y = temp_v0;
    arg0->unk_00[7]->data.sobj->sprite.y = temp_v0;

    temp_v0 = (arg0->unk_30 + arg2) - 8;
    arg0->unk_00[3]->data.sobj->sprite.y = temp_v0;
    arg0->unk_00[8]->data.sobj->sprite.y = temp_v0;
    arg0->unk_00[1]->data.sobj->sprite.y = temp_v0;
}

void func_8036F378_842B28(UnkFireHerring* arg0, s32 arg1, s32 arg2) {
    f32 temp_f0;
    f32 eight;
    s32 i;

    if (arg1 < 6) {
        arg1 = 6;
    } else if (arg1 > SCREEN_WIDTH) {
        arg1 = SCREEN_WIDTH;
    }
    if (arg2 < 6) {
        arg2 = 6;
    } else if (arg2 > SCREEN_HEIGHT) {
        arg2 = SCREEN_HEIGHT;
    }

    arg0->unk_2C = arg1;
    arg0->unk_30 = arg2;

    eight = 8.0f;

    if (arg1 >= 24) {
        arg0->unk_00[7]->data.sobj->sprite.scalex = 1.0f;
        temp_f0 = arg0->unk_00[7]->data.sobj->sprite.scalex;
        arg0->unk_00[0]->data.sobj->sprite.scalex = temp_f0;
        arg0->unk_00[1]->data.sobj->sprite.scalex = temp_f0;
        arg0->unk_00[3]->data.sobj->sprite.scalex = temp_f0;
        arg0->unk_00[2]->data.sobj->sprite.scalex = temp_f0;
        arg0->unk_00[4]->data.sobj->sprite.scalex = temp_f0;
        arg0->unk_00[6]->data.sobj->sprite.scalex = (arg1 - 14) / eight;
        arg0->unk_00[8]->data.sobj->sprite.scalex = (arg1 - 14) / eight;
        arg0->unk_00[5]->data.sobj->sprite.scalex = (arg1 - 14) / eight;
    } else {
        for (i = 0; i < ARRAY_COUNT(arg0->unk_00); i++) {
            arg0->unk_00[i]->data.sobj->sprite.scalex = arg1 / 24.0f;
        }
    }
    if (arg2 >= 24) {
        arg0->unk_00[8]->data.sobj->sprite.scaley = 1.0f;
        temp_f0 = arg0->unk_00[8]->data.sobj->sprite.scaley;
        arg0->unk_00[5]->data.sobj->sprite.scaley = temp_f0;
        arg0->unk_00[1]->data.sobj->sprite.scaley = temp_f0;
        arg0->unk_00[3]->data.sobj->sprite.scaley = temp_f0;
        arg0->unk_00[2]->data.sobj->sprite.scaley = temp_f0;
        arg0->unk_00[4]->data.sobj->sprite.scaley = temp_f0;
        arg0->unk_00[6]->data.sobj->sprite.scaley = (arg2 - 14) / eight;
        arg0->unk_00[7]->data.sobj->sprite.scaley = (arg2 - 14) / eight;
        arg0->unk_00[0]->data.sobj->sprite.scaley = (arg2 - 14) / eight;
    } else {
        for (i = 0; i < ARRAY_COUNT(arg0->unk_00); i++) {
            arg0->unk_00[i]->data.sobj->sprite.scaley = arg2 / 24.0f;
        }
    }
    func_8036F1F4_8429A4(arg0, arg0->unk_24, arg0->unk_28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/842850/func_8036F684_842E34.s")
// void func_8036F684_842E34(UnkFireHerring* arg0, s32 arg1) {
//     s32 i;

//     arg0->unk_34 = arg1;
//     if (arg1 < 0) {
//         arg1 = 0;
//     } else if ((u32) arg1 > 2) {
//         arg1 = 2;
//     }

//     for (i = 0; i < ARRAY_COUNT(arg0->unk_00); i++) {
//         D_803A6A10_87A1C0.unk_00[i]->data.sobj->sprite.bitmap = (&D_803818B0_855060[arg1])[i];
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/window/842850/func_8036F738_842EE8.s")

UnkFireHerring* func_8036F78C_842F3C(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803A6A10_87A1C0.unk_00); i++) {
        D_803A6A10_87A1C0.unk_00[i] = func_800A9F10(0, 6, &D_80380C88_854438);
        if (D_803A6A10_87A1C0.unk_00[i] == NULL) {
            return NULL;
        }
        D_803A6A10_87A1C0.unk_00[i]->data.sobj->sprite.bitmap = D_803818B0_855060[i];
        D_803A6A10_87A1C0.unk_00[i]->data.sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
        D_803A6A10_87A1C0.unk_00[i]->data.sobj->sprite.x = 80;
        D_803A6A10_87A1C0.unk_00[i]->data.sobj->sprite.y = 80;
    }
    D_803A6A10_87A1C0.unk_24 = 60;
    D_803A6A10_87A1C0.unk_28 = 60;
    D_803A6A10_87A1C0.unk_34 = 0;
    D_803A6A10_87A1C0.unk_38 = 1;
    func_8036F378_842B28(&D_803A6A10_87A1C0, 0xCC, 0x38);
    return &D_803A6A10_87A1C0;
}
