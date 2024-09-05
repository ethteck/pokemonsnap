#include "common.h"
#include "unk_end_level_3.h"

extern Bitmap* D_801C5404_98AC24[4];
extern Bitmap* D_801C5414_98AC34[6];
extern Bitmap* D_801C542C_98AC4C[9];
extern Bitmap* D_801C5450_98AC70[6];
extern Bitmap* D_801C5468_98AC88[3];
extern Vec3f D_801C5494_98ACB4[];
extern Vec3f D_801C54E8_98AD08;
extern Vec3f D_801C54F4_98AD14;
extern Vec3f D_801C5500_98AD20;

void func_800E5740_8AAF60(GObj* obj) {
    s32 frame;
    s32 var_s1;

    frame = 0;
    var_s1 = 0xC;
    while (true) {
        var_s1--;
        switch (D_801C5510_98AD30) {
            case 0:
                D_80206B7C_9CC39C->sprite.attr |= SP_HIDDEN;
                D_80206B80_9CC3A0->sprite.attr |= SP_HIDDEN;
                break;
            case 1:
                frame &= 3;
                D_80206B7C_9CC39C->sprite.bitmap = D_801C5484_98ACA4[frame];
                D_80206B7C_9CC39C->sprite.attr &= ~SP_HIDDEN;
                D_80206B80_9CC3A0->sprite.attr |= SP_HIDDEN;
                break;
            case 2:
                frame &= 3;
                D_80206B80_9CC3A0->sprite.bitmap = D_801C5474_98AC94[frame];
                D_80206B80_9CC3A0->sprite.attr &= ~SP_HIDDEN;
                D_80206B7C_9CC39C->sprite.attr |= SP_HIDDEN;
                break;
        }
        if (var_s1 == 0) {
            var_s1 = 12;
            frame++;
        }
        ohWait(1);
    }
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8AAF60/func_800E58D0_8AB0F0.s")
#else
void func_800E58D0_8AB0F0(GObj* arg0) {
    Vec3f sp6C;
    s32 new_var;
    f32 temp_f20;
    s32 frameCounter;
    u32 idx;
    s32 i;

    while (true) {
        switch (D_801C5514_98AD34) {
            case 0:
                frameCounter = 12;
                idx = 0;
                while (D_801C5514_98AD34 == 0) {
                    frameCounter -= 1;
                    if (frameCounter == 0) {
                        frameCounter = 12;
                        idx++;
                        idx %= 4;
                        D_80206B64_9CC384->sprite.bitmap = D_801C5404_98AC24[idx];
                    }
                    ohWait(1);
                }
                break;
            case 1:
                D_80206B68_9CC388->sprite.x = 137;
                D_80206B68_9CC388->sprite.y = 121;

                D_80206B64_9CC384->sprite.attr |= SP_HIDDEN;
                D_80206B68_9CC388->sprite.attr &= ~SP_HIDDEN;
                D_801C5514_98AD34 = 2;

                for (frameCounter = 0, idx = 0, i = 0; i < 15; i++, ohWait(1)) {
                    frameCounter++;
                    if (frameCounter >= 4) {
                        frameCounter = 0;
                        idx++;
                        idx %= 6;
                        D_80206B68_9CC388->sprite.bitmap = D_801C5414_98AC34[idx];
                    }
                    sp6C = D_801C54F4_98AD14;
                    Vec3fSub(&sp6C, &D_801C54E8_98AD08);
                    Vec3fScale(&sp6C, i / 15.0f);
                    Vec3fAdd(&sp6C, &D_801C54E8_98AD08);
                    D_80206B68_9CC388->sprite.x = sp6C.x;
                    D_80206B68_9CC388->sprite.y = sp6C.y;
                }
                break;
            case 2:
                D_80206B70_9CC390->sprite.x = 105;
                D_80206B70_9CC390->sprite.y = 117;
                D_80206B60_9CC380->sprite.attr |= SP_HIDDEN;
                D_80206B68_9CC388->sprite.attr |= SP_HIDDEN;
                D_80206B70_9CC390->sprite.attr &= ~SP_HIDDEN;
                D_801C5514_98AD34 = 3;
                D_801C5510_98AD30 = 2;
                auPlaySound(0x16);

                for (i = 0, idx = 0, frameCounter = 0; i < 21; i++, ohWait(1)) {
                    frameCounter++;
                    if (frameCounter >= 4) {
                        frameCounter = 0;
                        idx++;
                        if (idx < 6) {
                            D_80206B70_9CC390->sprite.bitmap = D_801C5450_98AC70[idx];
                        }
                    }
                }
                break;
            case 3:
                D_80206B74_9CC394->sprite.x = 170;
                D_80206B74_9CC394->sprite.y = 121;
                D_80206B70_9CC390->sprite.attr |= SP_HIDDEN;
                D_80206B74_9CC394->sprite.attr &= ~SP_HIDDEN;

                idx = 0;
                frameCounter = 0;
                for (i = 0; i < 60; i++, ohWait(1)) {
                    frameCounter++;
                    if (frameCounter >= 4) {
                        frameCounter = 0;
                        idx++;
                        idx %= 3;
                        D_80206B74_9CC394->sprite.bitmap = D_801C5468_98AC88[idx];
                    }
                    temp_f20 = i / 60.0f;
                    sp6C = D_801C5494_98ACB4[D_801C5518_98AD38];
                    Vec3fSub(&sp6C, &D_801C5500_98AD20);
                    Vec3fScale(&sp6C, temp_f20);
                    Vec3fAdd(&sp6C, &D_801C5500_98AD20);
                    D_80206B74_9CC394->sprite.x = sp6C.x;
                    D_80206B74_9CC394->sprite.y = sp6C.y;
                    D_80206B74_9CC394->sprite.scalex = 1.0 - temp_f20;
                    D_80206B74_9CC394->sprite.scaley = 1.0 - temp_f20;
                }

                D_801C551C_98AD3C = 0;

                while (true) {
                    D_801C550C_98AD2C = 0;
                    ohWait(1);
                }
                break;
            case 4:
                D_801C5514_98AD34 = 0;
                D_80206B64_9CC384->sprite.attr |= SP_HIDDEN;
                D_80206B6C_9CC38C->sprite.attr &= ~SP_HIDDEN;
                D_80206B6C_9CC38C->sprite.bitmap = D_801C542C_98AC4C[0];
                auPlaySoundWithParams(0xA1, 0x7FFF, 0x40, 0.75f, 0);

                frameCounter = 0;
                idx = 0;
                while (true) {
                    frameCounter++;
                    if (frameCounter >= 7) {
                        frameCounter = 0;
                        idx++;
                        if (idx >= 9) {
                            break;
                        }
                        D_80206B6C_9CC38C->sprite.bitmap = D_801C542C_98AC4C[idx];
                    }
                    if (D_80206B6C_9CC38C->sprite.attr & SP_HIDDEN) {
                        break;
                    }
                    ohWait(1);
                }

                if (!(D_80206B6C_9CC38C->sprite.attr & SP_HIDDEN)) {
                    ohWait(30);
                    D_80206B64_9CC384->sprite.attr &= ~SP_HIDDEN;
                    D_80206B6C_9CC38C->sprite.attr |= SP_HIDDEN;
                }
                D_801C551C_98AD3C = 0;
                break;
        }
    }
}
#endif

void func_800E5EBC_8AB6DC(void) {
    if ((rand() & 0x12) == 0) {
        func_800BF780_5C620(randT());
    }
}

void func_800E5EF8_8AB718(GObj* obj) {
    f32 var_f20;

    if (func_800C0290_5D130() == func_800BFC5C_5CAFC()) {
        if (func_800BFC5C_5CAFC() != 6) {
            D_80206B78_9CC398->sprite.attr |= SP_HIDDEN;
        }
        while (true) {
            ohWait(1);
        }
    }

    if (func_800C0290_5D130() != 6) {
        D_80206B78_9CC398->sprite.attr |= SP_HIDDEN;
        while (true) {
            ohWait(1);
        }
    }

    while (D_801C5520_98AD40 == 0) {
        ohWait(1);
    }

    D_80206B78_9CC398->sprite.attr &= ~SP_HIDDEN;
    var_f20 = 0.0f;

    while (true) {
        D_80206B78_9CC398->sprite.alpha = (s32) ((f32) ((__sinf(var_f20) / __sinf(PI_2)) + 0.001) * 254.0f);
        var_f20 += PI / 96;
        if (var_f20 > PI_2) {
            break;
        }

        ohWait(1);
    }
    D_80206B78_9CC398->sprite.scalex = 1.0f;
    D_80206B78_9CC398->sprite.scaley = 1.0f;

    while (true) {
        ohWait(1);
    }
}

void func_800E60C8_8AB8E8(void) {
    D_801C5520_98AD40 = 1;
}

void func_800E60D8_8AB8F8(s32 arg0) {
    if (D_80206B78_9CC398 != NULL && func_800BFC5C_5CAFC() == 6) {
        if (arg0) {
            D_80206B78_9CC398->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80206B78_9CC398->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_800E614C_8AB96C(s32 arg0) {
    if (D_80206B78_9CC398 == NULL) {
        return;
    }

    D_80206B80_9CC3A0->sprite.alpha = arg0;
    if (func_800BFC5C_5CAFC() == 6) {
        D_80206B78_9CC398->sprite.red = arg0;
        D_80206B78_9CC398->sprite.green = arg0;
        D_80206B78_9CC398->sprite.blue = arg0;
    }
}

void func_800E61B4_8AB9D4(s32 arg0, s32 arg1) {
    if (D_80206B78_9CC398 != NULL) {
        switch (arg0) { /* irregular */
            case 0:
                D_801C5514_98AD34 = 0;
                D_80206B60_9CC380->sprite.attr |= SP_HIDDEN;
                D_80206B64_9CC384->sprite.attr |= SP_HIDDEN;
                D_80206B68_9CC388->sprite.attr |= SP_HIDDEN;
                D_80206B6C_9CC38C->sprite.attr |= SP_HIDDEN;
                D_80206B70_9CC390->sprite.attr |= SP_HIDDEN;
                D_80206B74_9CC394->sprite.attr |= SP_HIDDEN;
                D_80206B78_9CC398->sprite.attr |= SP_HIDDEN;
                D_80206B60_9CC380->sprite.x = 105;
                D_80206B60_9CC380->sprite.y = 117;
                D_80206B64_9CC384->sprite.x = 170;
                D_80206B64_9CC384->sprite.y = 121;
                D_80206B68_9CC388->sprite.x = 137;
                D_80206B68_9CC388->sprite.y = 121;
                D_80206B6C_9CC38C->sprite.x = 105;
                D_80206B6C_9CC38C->sprite.y = 117;
                D_80206B70_9CC390->sprite.x = 170;
                D_80206B70_9CC390->sprite.y = 121;
                D_80206B74_9CC394->sprite.x = 170;
                D_80206B74_9CC394->sprite.y = 121;
                D_801C5510_98AD30 = 0;
                return;
            case 1:
                D_801C5514_98AD34 = 0;
                D_80206B60_9CC380->sprite.attr &= ~SP_HIDDEN;
                D_80206B64_9CC384->sprite.attr &= ~SP_HIDDEN;
                if (func_800BFC5C_5CAFC() == 6) {
                    D_80206B78_9CC398->sprite.attr &= ~SP_HIDDEN;
                }
                D_801C5510_98AD30 = 1;
                return;
            case 2:
                D_801C5514_98AD34 = 1;
                D_801C5518_98AD38 = arg1;
                D_801C550C_98AD2C = 1;
                D_801C551C_98AD3C = 1;
                while (D_801C550C_98AD2C != 0) {
                    ohWait(1);
                }
                break;
            case 3:
                D_801C5514_98AD34 = 4;
                D_801C551C_98AD3C = 1;
                break;
        }
    }
}

s32 func_800E6404_8ABC24(void) {
    return D_801C551C_98AD3C;
}

void func_800E6410_8ABC30(void) {
    D_801C5514_98AD34 = 0;

    D_80206B78_9CC398 = func_800A9F10(func_800E5EF8_8AB718, LINK_6, &D_801BED90_9845B0)->data.sobj;
    D_80206B78_9CC398->sprite.x = 109;
    D_80206B78_9CC398->sprite.y = 24;
    D_80206B78_9CC398->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;

    D_80206B60_9CC380 = func_800A9F10(func_800E58D0_8AB0F0, LINK_6, &D_80197EB0_95D6D0)->data.sobj;
    D_80206B60_9CC380->sprite.x = 105;
    D_80206B60_9CC380->sprite.y = 117;
    D_80206B60_9CC380->sprite.attr |= SP_HIDDEN;

    D_80206B64_9CC384 = func_800A9F10(NULL, LINK_6, &D_80198FB8_95E7D8)->data.sobj;
    D_80206B64_9CC384->sprite.x = 170;
    D_80206B64_9CC384->sprite.y = 121;
    D_80206B64_9CC384->sprite.attr |= SP_HIDDEN;

    D_80206B68_9CC388 = func_800A9F10(NULL, LINK_6, &D_8019C2D0_961AF0)->data.sobj;
    D_80206B68_9CC388->sprite.x = 137;
    D_80206B68_9CC388->sprite.y = 121;
    D_80206B68_9CC388->sprite.attr |= SP_HIDDEN;

    D_80206B6C_9CC38C = func_800A9F10(NULL, LINK_6, &D_801A2900_968120)->data.sobj;
    D_80206B6C_9CC38C->sprite.x = 170;
    D_80206B6C_9CC38C->sprite.y = 121;
    D_80206B6C_9CC38C->sprite.attr |= SP_HIDDEN;

    D_80206B70_9CC390 = func_800A9F10(NULL, LINK_6, &D_801AD198_9729B8)->data.sobj;
    D_80206B70_9CC390->sprite.x = 105;
    D_80206B70_9CC390->sprite.y = 117;
    D_80206B70_9CC390->sprite.attr |= SP_HIDDEN;

    D_80206B74_9CC394 = func_800A9F10(NULL, LINK_6, &D_801B93A8_97EBC8)->data.sobj;
    D_80206B74_9CC394->sprite.x = 170;
    D_80206B74_9CC394->sprite.y = 121;
    D_80206B74_9CC394->sprite.attr |= SP_SCALE | SP_HIDDEN;

    D_80206B7C_9CC39C = func_800A9F10(func_800E5740_8AAF60, LINK_6, &D_801C31B0_9889D0)->data.sobj;
    D_80206B7C_9CC39C->sprite.x = 263;
    D_80206B7C_9CC39C->sprite.y = 121;
    D_80206B7C_9CC39C->sprite.attr |= SP_HIDDEN;

    D_80206B80_9CC3A0 = func_800A9F10(NULL, LINK_6, &D_801BFE98_9856B8)->data.sobj;
    D_80206B80_9CC3A0->sprite.x = 263;
    D_80206B80_9CC3A0->sprite.y = 121;
    D_80206B80_9CC3A0->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;
}

void func_800E66B8_8ABED8(void) {
    D_80206B78_9CC398 = 0;
    D_801C551C_98AD3C = 0;
}
