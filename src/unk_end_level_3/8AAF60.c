#include "common.h"
#include "unk_end_level_3.h"

void func_800E5740_8AAF60(GObj* obj) {
    s32 frame;
    s32 var_s1;

    frame = 0;
    var_s1 = 0xC;
    while (1) {
        var_s1 -= 1;
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
            var_s1 = 0xC;
            frame += 1;
        }
        ohWait(1);
    }
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8AAF60/func_800E58D0_8AB0F0.s")
#else
Vec3f* Vec3fAdd(Vec3f* dst, Vec3f* addend);
Vec3f* Vec3fScale(Vec3f* v, f32 scale);
Vec3f* Vec3fSub(Vec3f* dst, Vec3f* subtrahend);

extern Bitmap* D_801C5404_98AC24[4];
extern Bitmap* D_801C5414_98AC34[6];
extern Bitmap* D_801C542C_98AC4C[9];
extern Bitmap* D_801C5450_98AC70[6];
extern Bitmap* D_801C5468_98AC88[3];
extern Vec3f D_801C5494_98ACB4[];
extern Vec3f D_801C54E8_98AD08;
extern Vec3f D_801C54F4_98AD14;
extern Vec3f D_801C5500_98AD20;

extern s32 D_801C550C_98AD2C;
extern s32 D_801C5510_98AD30;
extern volatile u32 D_801C5514_98AD34;
extern s32 D_801C5518_98AD38;

void func_800E58D0_8AB0F0(GObj* arg0) {
    Vec3f sp6C;
    Vec3f* temp_t1;
    f32 temp_f0;
    f32 temp_f20;
    s32 frame_counter;
    s32 frame;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_v0;
    u32 temp_v0;

    while (1) {
        switch (D_801C5514_98AD34) {
            case 0:
                temp_v0 = D_801C5514_98AD34;
                frame_counter = 0xC;
                frame = 0;
                while (temp_v0 == D_801C5514_98AD34) {
                    frame_counter -= 1;
                    if (frame_counter == 0) {
                        frame = (frame + 1) & 3;
                        frame_counter = 0xC;
                        D_80206B64_9CC384->sprite.bitmap = D_801C5404_98AC24[frame];
                    }

                    ohWait(1);
                }
                break;

            case 1:
                D_80206B68_9CC388->sprite.x = 137;
                D_80206B68_9CC388->sprite.y = 121;
                var_s2 = 0;

                frame = 0;
                frame_counter = 0;
                D_80206B64_9CC384->sprite.attr |= SP_HIDDEN;
                D_80206B68_9CC388->sprite.attr &= ~SP_HIDDEN;
                D_801C5514_98AD34 = 2;
                do {
                    frame_counter += 1;
                    if (frame_counter >= 4) {
                        frame = (frame + 1) % 6U;
                        frame_counter = 0;
                        D_80206B68_9CC388->sprite.bitmap = D_801C5414_98AC34[frame];
                    }
                    sp6C = D_801C54F4_98AD14;
                    Vec3fSub(&sp6C, &D_801C54E8_98AD08);
                    Vec3fScale(&sp6C, (f32) var_s2 / 15.0f);
                    Vec3fAdd(&sp6C, &D_801C54E8_98AD08);
                    var_s2 += 1;
                    D_80206B68_9CC388->sprite.x = sp6C.x;
                    D_80206B68_9CC388->sprite.y = sp6C.y;
                    ohWait(1);
                } while (var_s2 != 0xF);
                break;

            case 2:
                D_80206B70_9CC390->sprite.x = 105;
                D_80206B70_9CC390->sprite.y = 117;
                frame = 0;
                D_80206B60_9CC380->sprite.attr |= SP_HIDDEN;
                var_s2_2 = 0;
                frame_counter = 0;
                D_80206B68_9CC388->sprite.attr |= SP_HIDDEN;
                D_80206B70_9CC390->sprite.attr &= ~SP_HIDDEN;
                D_801C5514_98AD34 = 3;
                D_801C5510_98AD30 = 2;
                auPlaySound(0x16);
                while (1) {
                    frame_counter += 1;
                    var_s2_2 += 1;
                    if (frame_counter >= 4) {
                        frame += 1;
                        frame_counter = 0;

                        if (frame >= 6) {
                            break;
                        }

                        D_80206B70_9CC390->sprite.bitmap = D_801C5450_98AC70[frame];
                    }

                    ohWait(1);
                    if (var_s2_2 == 0x15) {
                        break;
                    }
                }

                break;

            case 3:
                D_80206B74_9CC394->sprite.x = 170;
                D_80206B74_9CC394->sprite.y = 121;
                D_80206B70_9CC390->sprite.attr |= SP_HIDDEN;
                var_s2_3 = 0;
                frame = 0;
                frame_counter = 0;
                D_80206B74_9CC394->sprite.attr &= ~SP_HIDDEN;
                while (var_s2_3 != 0x3C) {
                    frame_counter += 1;
                    if (frame_counter >= 4) {
                        frame = (u32) (frame + 1) % 3U;
                        frame_counter = 0;
                        D_80206B74_9CC394->sprite.bitmap = D_801C5468_98AC88[frame];
                    }
                    temp_f20 = (f32) var_s2_3 / 60.0f;
                    sp6C = D_801C5494_98ACB4[D_801C5518_98AD38];
                    Vec3fSub(&sp6C, &D_801C5500_98AD20);
                    Vec3fScale(&sp6C, temp_f20);
                    Vec3fAdd(&sp6C, &D_801C5500_98AD20);
                    var_s2_3 += 1;
                    D_80206B74_9CC394->sprite.x = sp6C.x;
                    D_80206B74_9CC394->sprite.y = (s16) (s32) sp6C.y;
                    temp_f0 = (f32) (1.0 - (f64) temp_f20);
                    D_80206B74_9CC394->sprite.scalex = temp_f0;
                    D_80206B74_9CC394->sprite.scaley = temp_f0;
                    ohWait(1);
                }
                D_801C551C_98AD3C = 0;

                while (1) {
                    D_801C550C_98AD2C = 0;
                    ohWait(1);
                }
                break;

            case 4:
                D_801C5514_98AD34 = 0;
                D_80206B64_9CC384->sprite.attr |= SP_HIDDEN;
                frame = 0;
                D_80206B6C_9CC38C->sprite.attr &= ~SP_HIDDEN;
                frame_counter = 0;
                D_80206B6C_9CC38C->sprite.bitmap = D_801C542C_98AC4C[0];
                auPlaySoundWithParams(0xA1U, 0x7FFF, 0x40, 0.75f, 0);
                while (1) {
                    frame_counter += 1;
                    if (frame_counter >= 7) {
                        frame += 1;
                        frame_counter = 0;
                        if (frame >= 9) {
                            var_v0 = D_80206B6C_9CC38C->sprite.attr & 4;
                            break;
                        }
                        D_80206B6C_9CC38C->sprite.bitmap = D_801C542C_98AC4C[frame];
                    }

                    var_v0 = D_80206B6C_9CC38C->sprite.attr & 4;
                    if (var_v0 != 0) {
                        break;
                    }
                    ohWait(1);
                }

                if (var_v0 == 0) {
                    ohWait(0x1E);
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

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8AAF60/func_800E5EF8_8AB718.s")
#else
void func_800E5EF8_8AB718(GObj* obj) {
    f32 temp_f22;
    f32 var_f20;
    s32 temp_s0;
    s32 temp_s1;

    temp_s0 = func_800C0290_5D130();
    if (func_800BFC5C_5CAFC() == temp_s0) {
        if (func_800BFC5C_5CAFC() != 6) {
            D_80206B78_9CC398->sprite.attr |= SP_HIDDEN;
        }
        while (1) {
            ohWait(1);
        }
    }

    if (func_800C0290_5D130() != 6) {
        D_80206B78_9CC398->sprite.attr |= SP_HIDDEN;
        while (1) {

            ohWait(1);
        }
    }

    while (D_801C5520_98AD40 == 0) {
        ohWait(1);
    }

    var_f20 = 0.0f;
    D_80206B78_9CC398->sprite.attr &= ~SP_HIDDEN;
    while (1) {
        temp_f22 = __sinf(var_f20);
        temp_s1 = ((temp_f22 / __sinf(1.5707964f)) + 0.001) * 254;
        var_f20 += 0.032724924f;
        D_80206B78_9CC398->sprite.alpha = temp_s1;
        if ((var_f20 > 1.5707964f)) {
            break;
        }

        ohWait(1);
    }
    D_80206B78_9CC398->sprite.scalex = 1.0f;
    D_80206B78_9CC398->sprite.scaley = 1.0f;

    while (1) {
        ohWait(1);
    }
}
#endif

void func_800E60C8_8AB8E8(void) {
    D_801C5520_98AD40 = 1;
}

void func_800E60D8_8AB8F8(s32 arg0) {
    if ((D_80206B78_9CC398 != NULL) && (func_800BFC5C_5CAFC() == 6)) {
        if (arg0 != 0) {
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
