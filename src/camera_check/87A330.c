#include "common.h"
#include "camera_check.h"
#include "more_funcs/more_funcs.h"
#include "string.h"

UIElement* func_camera_check_801DCB40(void) {
    return D_camera_check_80249914;
}

UIElement* func_camera_check_801DCB4C(void) {
    return D_camera_check_80249918;
}

// TODO bs required to match
void func_camera_check_801DCB58(s32 rgb) {
    SObj** tmp1;
    SObj** tmp2;
    SObj** tmp3;
    SObj** tmp4;

    tmp1 = &D_camera_check_802499B0;
    tmp2 = &D_camera_check_802499B4;
    tmp3 = &D_camera_check_802499B8;
    tmp4 = &D_camera_check_802499BC;
    if (1) {
        D_camera_check_802499A8->sprite.red = rgb;
        D_camera_check_802499A8->sprite.green = rgb;
        D_camera_check_802499A8->sprite.blue = rgb;
    }
    (*tmp1)->sprite.red = rgb;
    (*tmp1)->sprite.green = rgb;
    (*tmp1)->sprite.blue = rgb;
    (*tmp2)->sprite.red = rgb;
    (*tmp2)->sprite.green = rgb;
    (*tmp2)->sprite.blue = rgb;
    (*tmp3)->sprite.red = rgb;
    (*tmp3)->sprite.green = rgb;
    (*tmp3)->sprite.blue = rgb;
    (*tmp4)->sprite.red = rgb;
    (*tmp4)->sprite.green = rgb;
    (*tmp4)->sprite.blue = rgb;
}

void func_camera_check_801DCC0C(void) {
    SObj* sobj;

    sobj = func_80371D14_8454C4(0, 6, &D_camera_check_801FD5C8)->data.sobj;
    sobj->sprite.x = 96;
    sobj->sprite.y = 42;
    D_camera_check_802499B0 = sobj;

    sobj = func_80371E68_845618(sobj, &D_camera_check_801FD6A8);
    sobj->sprite.x = 8;
    sobj->sprite.y = 0;
    sobj->sprite.attr |= SP_SCALE;
    sobj->sprite.scalex = 25.0f;
    D_camera_check_802499B4 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD4E8);
    sobj->sprite.x = 0;
    sobj->sprite.y = 8;
    sobj->sprite.height = 112;
    sobj->sprite.istep = 0;
    D_camera_check_802499B8 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD408);
    sobj->sprite.x = 8;
    sobj->sprite.y = 8;
    sobj->sprite.height = 0x70;
    sobj->sprite.istep = 0;
    sobj->sprite.attr |= SP_SCALE;
    sobj->sprite.scalex = 25.0f;
    D_camera_check_802499BC = sobj;
}

void func_camera_check_801DCD00(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_camera_check_802499C0[i].unk_00->data.sobj->sprite.x = ((i % 3) * 66) + 104;
        D_camera_check_802499C0[i].unk_00->data.sobj->sprite.y = ((i / 3) * 55) + 53;
    }
}

GObj* func_camera_check_801DCF9C(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 pad;
    u8* dest;
    Bitmap* sp24;
    s32 x;
    u8* src;

    gobj = func_80371C68_845418(NULL, 6, &D_camera_check_801FE318);
    sobj = gobj->data.sobj;
    D_camera_check_802499C0[arg0].unk_00 = gobj;

    sobj = func_80371E68_845618(sobj, &D_camera_check_801FE318);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FE448);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FE448);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FCE78);
    sobj->sprite.x = 56;
    sobj->sprite.y = 0;
    D_camera_check_802499C0[arg0].unk_04 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_80201520);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_camera_check_802499C0[arg0].unk_0C = sobj;

    sp24 = func_8036A194_83D944(0x30);
    dest = func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *sp24 = *sobj->sprite.bitmap;
    sp24->buf = dest;
    sobj->sprite.bitmap = sp24;

    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD088);
    sobj->sprite.x = -2;
    sobj->sprite.y = -2;
    D_camera_check_802499C0[arg0].unk_08 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FFB08);
    sobj->sprite.x = 6;
    sobj->sprite.y = 33;
    sobj->sprite.attr |= 0x4000 | SP_SCALE | SP_TRANSPARENT;
    D_camera_check_802499C0[arg0].unk_10 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FFC88);
    sobj->sprite.x = 38;
    sobj->sprite.y = 33;
    sobj->sprite.attr |= 0x4000 | SP_SCALE | SP_TRANSPARENT;
    D_camera_check_802499C0[arg0].unk_14 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_802004E8);
    sobj->sprite.x = 38;
    sobj->sprite.y = 33;
    sobj->sprite.attr |= SP_HIDDEN;
    D_camera_check_802499C0[arg0].unk_18 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_802004E8);
    sobj->sprite.x = 38;
    sobj->sprite.y = 33;
    sobj->sprite.attr |= SP_HIDDEN;
    D_camera_check_802499C0[arg0].unk_1C = sobj;

    return gobj;
}

void func_camera_check_801DD1F0(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        func_camera_check_801DCF9C(i);
    }
    func_camera_check_801DCD00();
}

void func_camera_check_801DD238(UnkTealFlounder* arg0, s32 arg1, s32 arg2) {
    UnkIndigoHalibut* temp_v0;
    UNUSED s32 pad[4];
    s32 temp_t4;

    if (arg0 == NULL || (temp_v0 = func_camera_check_801E24D8(arg1), (temp_v0 == NULL))) {
        if (arg0 != NULL) {
            arg0->unk_04->sprite.attr |= SP_HIDDEN;
            arg0->unk_08->sprite.attr |= SP_HIDDEN;
            arg0->unk_14->sprite.attr |= SP_HIDDEN;
            arg0->unk_10->sprite.attr |= SP_HIDDEN;
            arg0->unk_18->sprite.attr |= SP_HIDDEN;
            arg0->unk_0C->sprite.red = 0xFF;
            arg0->unk_0C->sprite.green = 0xFF;
            arg0->unk_0C->sprite.blue = 0xFF;
        }
    } else {
        if (checkPlayerFlag(PFID_6)) {
        }
        temp_t4 = arg2 & 4;
        if (temp_v0->unk_08 != 9999) {
            if (temp_v0->unk_08 <= POKEDEX_MAX) {
                if (arg2 & 1) {
                }
            } else {
                checkPlayerFlag(PFID_HAS_DASH_ENGINE);
            }
        }

        if (temp_v0->unk_18_0x80000000) {
            arg0->unk_04->sprite.attr &= ~SP_HIDDEN;
        } else {
            arg0->unk_04->sprite.attr |= SP_HIDDEN;
        }

        if (temp_v0->unk_18_0x40000000) {
            arg0->unk_08->sprite.attr &= ~SP_HIDDEN;
        } else {
            arg0->unk_08->sprite.attr |= SP_HIDDEN;
        }

        if ((temp_v0->unk_18_0x01000000) && !(arg2 & 0x20)) {
            arg0->unk_00->data.sobj->sprite.red = 0x80;
            arg0->unk_00->data.sobj->sprite.green = 0x80;
            arg0->unk_00->data.sobj->sprite.blue = 0x80;
        } else {
            arg0->unk_00->data.sobj->sprite.red = 0xFF;
            arg0->unk_00->data.sobj->sprite.green = 0xFF;
            arg0->unk_00->data.sobj->sprite.blue = 0xFF;
        }

        if (arg2 & 1) {
            arg0->unk_14->unk_54 = 0;
            arg0->unk_14->sprite.attr &= ~SP_HIDDEN;
            if (temp_v0->unk_18_0x20000000 || temp_v0->unk_18_0x10000000) {
                arg0->unk_14->sprite.alpha = 0xFF;
                arg0->unk_18->sprite.attr |= SP_HIDDEN;
                if (arg2 & 8) {
                    arg0->unk_14->unk_54 = 2;
                } else {
                    arg0->unk_14->unk_54 = 1;
                }
            } else {
                if (arg2 & 0x10) {
                    arg0->unk_14->sprite.attr |= SP_HIDDEN;
                } else {
                    arg0->unk_14->sprite.alpha = 0x80;
                    arg0->unk_14->unk_54 = 0;
                    if (1) {
                    }
                }

                if (arg2 & 0x80) {
                    arg0->unk_18->sprite.attr &= ~SP_HIDDEN;
                } else {
                    arg0->unk_18->sprite.attr |= SP_HIDDEN;
                }
            }
        } else {
            arg0->unk_14->sprite.attr |= SP_HIDDEN;
            arg0->unk_18->sprite.attr |= SP_HIDDEN;
        }

        if (temp_t4 & 0xFFFFFFFF) { // TODO & 0xFFFFFFFF required to match
            arg0->unk_10->unk_54 = 0;
            arg0->unk_10->sprite.attr &= ~SP_HIDDEN;
            if (temp_v0->unk_18_0x08000000) {
                arg0->unk_10->sprite.alpha = 0xFF;
                arg0->unk_1C->sprite.attr |= SP_HIDDEN;
                if (arg2 & 8) {
                    arg0->unk_10->unk_54 = 2;
                } else {
                    arg0->unk_10->unk_54 = 1;
                }
            } else {
                if (arg2 & 0x10) {
                    arg0->unk_10->sprite.attr |= SP_HIDDEN;
                } else {
                    arg0->unk_10->sprite.alpha = 0x80;
                    arg0->unk_10->unk_54 = 0;
                }
                if (arg2 & 0x100) {
                    arg0->unk_1C->sprite.attr &= ~SP_HIDDEN;
                } else {
                    arg0->unk_1C->sprite.attr |= SP_HIDDEN;
                }
            }
        } else {
            arg0->unk_10->sprite.attr |= SP_HIDDEN;
            arg0->unk_1C->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_camera_check_801DD630(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 6; i++, arg0++) {
        func_camera_check_801DD238(&D_camera_check_802499C0[arg0 % 6], arg0, arg1);
    }
}

void func_camera_check_801DD6D0(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (func_camera_check_801E2484(arg0 + i) == 0) {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
            osWritebackDCache(&D_camera_check_802499C0[i].unk_00->data.sobj->sprite, 0x44);
        }
    }

    ohWait(3);

    for (i = 0; i < 6; i++, arg0++) {
        if (func_80374714_847EC4(func_camera_check_801E2484(arg0), &D_camera_check_802499C0[i].unk_0C->sprite) != 0) {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        } else {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        }
        func_camera_check_801DD238(&D_camera_check_802499C0[arg0 % 6], arg0, arg1);
        ohWait(1);
    }
}

void func_camera_check_801DD83C(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 6; i++, arg0++) {
        if (func_80374714_847EC4(func_800BF8BC_5C75C(arg0), &D_camera_check_802499C0[i].unk_0C->sprite) != 0) {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        } else {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        }
        func_camera_check_801DD238(&D_camera_check_802499C0[arg0 % 6], -1, 0);
    }
}

void func_camera_check_801DD93C(s32 rgb) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_camera_check_802499C0[i].unk_00->data.sobj->sprite.red = rgb;
        D_camera_check_802499C0[i].unk_00->data.sobj->sprite.green = rgb;
        D_camera_check_802499C0[i].unk_00->data.sobj->sprite.blue = rgb;
    }
}

void func_camera_check_801DDA44(s32 arg0) {
    s32 i;

    if (arg0) {
        return;
    }

    for (i = 0; i < 6; i += 2) {
        if (arg0) {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_camera_check_802499C0[i].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        }
        if (arg0) {
            D_camera_check_802499C0[i + 1].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_camera_check_802499C0[i + 1].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_camera_check_801DDAD8(s32 arg0) {
    D_camera_check_802499C0[6].unk_00->data.sobj->sprite.x = 25;
    D_camera_check_802499C0[6].unk_00->data.sobj->sprite.y = 65;
}

void func_camera_check_801DDB08(s32 arg0) {
    if (arg0) {
        return;
    }

    if (arg0) {
        D_camera_check_802499C0[6].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        UIElement_SetState(D_camera_check_8024991C, UI_NORMAL);
    } else {
        D_camera_check_802499C0[6].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        UIElement_SetState(D_camera_check_8024991C, UI_HIDDEN);
    }
}

void func_camera_check_801DDB80(s32 arg0, s32 arg1, s32 arg2) {
    UnkIndigoHalibut* var_a2;
    PhotoData* photoData;
    char* sp1C;
    UNUSED s32 pad[2];

    if (arg1 != 0) {
        var_a2 = NULL;
    } else {
        var_a2 = func_camera_check_801E286C(arg0);
    }

    if (var_a2 != NULL) {
        photoData = var_a2->unk_00;
    } else {
        photoData = func_800BF710_5C5B0(arg0);
    }

    if (func_80374714_847EC4(photoData, &D_camera_check_802499C0[6].unk_0C->sprite) != 0) {
        D_camera_check_802499C0[6].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        UIElement_SetState(D_camera_check_8024991C, UI_HIDDEN);
        return;
    }

    D_camera_check_802499C0[6].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
    UIElement_Draw(D_camera_check_8024991C);
    sp1C = "";
    if (var_a2 != NULL) {
        func_camera_check_801DD238(&D_camera_check_802499C0[6], func_camera_check_801E2948(var_a2), arg2 | 0x10 | 0x20);
        if (!(arg2 & 0x40)) {
            sp1C = "\\i    \\g I choose this!";
        }
    } else {
        func_camera_check_801DD238(&D_camera_check_802499C0[6], -1, arg2 | 0x10 | 0x20);
        if (!(arg2 & 0x40)) {
            sp1C = "\\i    \\gAlready Shown";
        }
    }
    if (!(arg2 & 0x40)) {
        UIElement_SetTextPos(D_camera_check_8024991C, 0, 2);
    }
    UIElement_SetTextPos(D_camera_check_8024991C, 0, 2);
    UIElement_PrintText(D_camera_check_8024991C, sp1C);
    UIElement_SetState(D_camera_check_8024991C, UI_NORMAL);
}

void func_camera_check_801DDD28(s32 arg0) {
    if (!D_camera_check_80249910) {
        return;
    }

    if (arg0) {
        UIElement_SetState(D_camera_check_80249910, UI_NORMAL);
        func_803713D4_844B84(4);
        UIElement_SetState(D_camera_check_80249918, UI_NORMAL);
    } else {
        UIElement_SetState(D_camera_check_80249910, UI_HIDDEN);
        UIElement_SetState(D_camera_check_80249918, UI_HIDDEN);
        func_803713EC_844B9C(4);
    }
}

void func_camera_check_801DDDA4(SObj* sobj, f32 arg1, f32* arg2, s32 x, s32 y) {
    f32 scale;
    s32 delta;

    if (sobj->unk_54 == 1) {
        scale = (__cosf(*arg2) * 0.5) + 1.5;
        delta = -8 - (s32) (__cosf(*arg2) * 8.0);
        if (*arg2 < PI) {
            *arg2 += PI / 18;
        } else {
            scale = 1.0f;
            delta = 0;
        }
    } else if (sobj->unk_54 == 0) {
        scale = (__sinf(arg1) * 0.1) + 0.9;
        delta = 1 - (s32) (__sinf(arg1) * 1.9);
        *arg2 = 0.0f;
    } else {
        scale = 1.0f;
        delta = 0;
        *arg2 = 0.0f;
    }
    sobj->sprite.scalex = scale;
    sobj->sprite.scaley = scale;
    sobj->sprite.x = x + delta;
    sobj->sprite.y = y + delta;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DDF28.s")

void* func_camera_check_801DDFC4(void) {
    GObj* temp_v0;
    SObj* sobj;
    UIElement* temp_v0_2;

    temp_v0 = func_80371C68_845418(func_camera_check_801DDF28, 6, &D_camera_check_801FDDB8);
    D_camera_check_802498F0.unk_00 = temp_v0;
    sobj = temp_v0->data.sobj;
    sobj->sprite.x = 101;
    sobj->sprite.y = 47;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_camera_check_801FDDB8);
    sobj->sprite.x = 143;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FE160);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FE160);
    sobj->sprite.x = 3;
    sobj->sprite.y = 108;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD9E0);
    sobj->sprite.x = 161;
    sobj->sprite.y = 60;
    D_camera_check_802498F0.unk_04 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_80208900);
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;
    D_camera_check_802498F0.unk_0C = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD088);
    sobj->sprite.x = -2;
    sobj->sprite.y = -2;
    D_camera_check_802498F0.unk_08 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FF128);
    sobj->sprite.x = 14;
    sobj->sprite.y = 72;
    sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    D_camera_check_802498F0.unk_10 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FF988);
    sobj->sprite.x = 100;
    sobj->sprite.y = 72;
    sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    D_camera_check_802498F0.unk_14 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_802004E8);
    sobj->sprite.x = 100;
    sobj->sprite.y = 72;
    sobj->sprite.attr |= SP_HIDDEN;
    D_camera_check_802498F0.unk_18 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_802004E8);
    sobj->sprite.x = 14;
    sobj->sprite.y = 72;
    sobj->sprite.attr |= SP_HIDDEN;
    D_camera_check_802498F0.unk_1C = sobj;

    temp_v0_2 = UIElement_Create(256, 50, 84, 112, UI_FLAG_10);
    UIElement_SetColor(temp_v0_2, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(temp_v0_2, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_DrawBackground(temp_v0_2);
    UIElement_SetState(temp_v0_2, UI_HIDDEN);
    D_camera_check_80249910 = temp_v0_2;
    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    UIElement_SetTextStyle(temp_v0_2, FONT_8);
    UIElement_SetTextPos(temp_v0_2, 0, 0);
    UIElement_PrintText(temp_v0_2, "Course");
    UIElement_SetTextPos(temp_v0_2, 0, 28);
    UIElement_PrintText(temp_v0_2, "Photo by");

    return temp_v0;
}

void func_camera_check_801DE288(UnkIndigoHalibut* arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DE288.s")

// void func_camera_check_801DE288(UnkIndigoHalibut* arg0) {
//     char* sp68;
//     char* var_a3_2;
//     char sp48[0x20];
//     UIElement* temp_s0;
//     char* levelName;

//     temp_s0 = D_camera_check_80249910;
//     UIElement_FillRect(temp_s0, 0, 0xC, 0x53, 0x16, 0, 0, 0, 0);
//     UIElement_FillRect(temp_s0, 0, 0x28, 0x53, 0x32, 0, 0, 0, 0);
//     UIElement_FillRect(temp_s0, 0, 0x38, 0x53, 0x42, 0, 0, 0, 0);
//     UIElement_FillRect(temp_s0, 0, 0x44, 0x53, 0x4E, 0, 0, 0, 0);
//     UIElement_FillRect(temp_s0, 0, 0x54, 0x53, 0x6A, 0, 0, 0, 0);
//     if (arg0 != NULL) {
//         func_8036D448_840BF8(1);
//         func_8036D3E8_840B98(-1, 3);
//         UIElement_SetTextStyle(temp_s0, FONT_8);
//         levelName = getLevelName(arg0->unk_00->levelID);
//         if (levelName == NULL) {
//             levelName = "ーーー";
//         }
//         sprintf(sp48, "%s", levelName, levelName);
//         UIElement_SetTextStyle(temp_s0, FONT_8);
//         UIElement_SetTextPos(temp_s0, 45 - UIText_GetStringWidth(sp48), 0xC);
//         UIElement_PrintText(temp_s0, sp48);
//         sprintf(sp48, "%s", get_player_name());

//         if (var_a3_2 && var_a3_2 && var_a3_2) {
//         }

//         UIElement_SetTextStyle(temp_s0, FONT_8);
//         UIElement_SetTextPos(temp_s0, 45 - UIText_GetStringWidth(sp48), 0x28);
//         UIElement_PrintText(temp_s0, sp48);
//         if (!(arg0->unk_18_0x04000000)) {
//             sprintf(sp48, "%s", getPokemonName(arg0->unk_08));
//             var_a3_2 = sp48;
//             if (func_camera_check_801E2EA0(arg0->unk_08)) {
//                 if (arg0->unk_18_0x80000000) {
//                     var_a3_2 = "Sign?";
//                 } else {
//                     var_a3_2 = "Sign";
//                 }
//             }
//         } else {
//             var_a3_2 = "";
//         }
//         sp68 = var_a3_2;
//         UIElement_Draw(D_camera_check_80249918);
//         UIElement_SetTextStyle(D_camera_check_80249918, FONT_12);
//         UIElement_SetTextPos(D_camera_check_80249918, (108 - UIText_GetStringWidth(sp68)) / 2, 0);
//         UIElement_PrintText(D_camera_check_80249918, sp68);
//     } else {
//         UIElement_SetTextPos(temp_s0, 0, 12);
//         UIElement_PrintText(temp_s0, "ーーーーー");
//         UIElement_SetTextPos(temp_s0, 0, 40);
//         UIElement_PrintText(temp_s0, "ーーーーー");
//     }
// }

void func_camera_check_801DE59C(UnkIndigoHalibut* arg0) {
    s32 sp6C; // BUG: never set?
    UIElement* temp_s0;
    char* levelName;
    char sp44[0x20];
    UNUSED s32 pad;

    temp_s0 = D_camera_check_80249910;
    UIElement_FillRect(temp_s0, 0, 12, 83, 22, 0, 0, 0, 0);
    UIElement_FillRect(temp_s0, 0, 40, 83, 50, 0, 0, 0, 0);
    UIElement_FillRect(temp_s0, 0, 68, 83, 78, 0, 0, 0, 0);
    UIElement_FillRect(temp_s0, 0, 84, 83, 106, 0, 0, 0, 0);
    UIElement_SetTextPos(temp_s0, 0, 56);
    UIElement_PrintText(temp_s0, "Score");

    if (sp6C) {
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        UIElement_SetTextStyle(temp_s0, FONT_8);
        levelName = getLevelName(arg0->unk_00->levelID);
        if (levelName == NULL) {
            levelName = "ーーー";
        }
        sprintf(sp44, "%s", levelName);
        UIElement_SetTextPos(temp_s0, 45 - UIText_GetStringWidth(sp44), 12);
        UIElement_PrintText(temp_s0, sp44);
        sprintf(sp44, "%s", get_player_name());
        UIElement_SetTextPos(temp_s0, 45 - UIText_GetStringWidth(sp44), 40);
        UIElement_PrintText(temp_s0, sp44);
        sprintf(sp44, "%d", arg0->unk_04);
        UIElement_SetTextPos(temp_s0, 45 - UIText_GetStringWidth(sp44), 68);
        UIElement_PrintText(temp_s0, sp44);
    } else {
        UIElement_SetTextPos(temp_s0, 0, 12);
        UIElement_PrintText(temp_s0, "ーーーーー");
        UIElement_SetTextPos(temp_s0, 0, 40);
        UIElement_PrintText(temp_s0, "ーーーーー");
        UIElement_SetTextPos(temp_s0, 0, 68);
        UIElement_PrintText(temp_s0, "ーーーーー");
    }
}

void func_camera_check_801DE80C(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        D_camera_check_802498F0.unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_camera_check_802498F0.unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
    }
    if (arg0 != 0) {
        func_80374714_847EC4(func_camera_check_801E2484(arg1), &D_camera_check_802498F0.unk_0C->sprite);
        func_camera_check_801DD238(&D_camera_check_802498F0, arg1, arg2);
    }
    func_camera_check_801DE288(func_camera_check_801E24D8(arg1));
}

void func_camera_check_801DE8AC(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        D_camera_check_802498F0.unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_camera_check_802498F0.unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
    }
    if (arg0 != 0) {
        func_80374714_847EC4(func_800BF8BC_5C75C(arg1), &D_camera_check_802498F0.unk_0C->sprite);
        func_camera_check_801DD238(&D_camera_check_802498F0, -1, 0);
    }
}

void func_camera_check_801DE934(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad;
    UnkIndigoHalibut* sp40;
    UnkIndigoHalibut sp24;
    PhotoData* sp20;

    if (arg0 != 0) {
        D_camera_check_802498F0.unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_camera_check_802498F0.unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
    }

    if (arg0 != 0) {
        sp40 = func_camera_check_801E286C(arg1);
        if (sp40 != NULL) {
            sp20 = sp40->unk_00;
            func_camera_check_801DD238(&D_camera_check_802498F0, func_camera_check_801E2948(sp40), arg2);
            func_camera_check_801DE288(sp40);
        } else {
            sp20 = func_800BF710_5C5B0(arg1);
            func_camera_check_801DD238(&D_camera_check_802498F0, -1, arg2);
            func_camera_check_801E3D8C(sp20, &sp24);
            func_camera_check_801DE59C(&sp24);
        }
        func_80374714_847EC4(sp20, &D_camera_check_802498FC->sprite);
    }
}

void func_camera_check_801DEA20(s32 arg0, s32 arg1) {
    func_camera_check_801DD238(&D_camera_check_802498F0, arg0, arg1);
}

UIElement* func_camera_check_801DEA50(void) {
    return D_camera_check_80249910;
}

void func_camera_check_801DEA5C(GObj* arg0) {
    s32 var_v0 = (s32) arg0->userData;

    if (var_v0 > 0) {
        var_v0 -= 14;
        if (var_v0 <= 0) {
            omDeleteGObj(arg0);
            var_v0 = 0;
        }
    } else {
        var_v0 += 14;
        if (var_v0 >= 0) {
            omDeleteGObj(arg0);
            var_v0 = 0;
        }
    }
    arg0->userData = (void*) var_v0;
}

// TODO unused? arg type may be wrong, requiring the weird temp
void func_camera_check_801DEAC0(s32 arg0) {
    UIElement* sp34;
    UIFrame* sp30;
    ucolor sp2C;
    s32* weird;

    weird = &arg0; // TODO required to match

    if (D_camera_check_80208954 != *weird) {
        sp34 = D_camera_check_80249914;
        sp30 = D_camera_check_80249920;
        UIElement_Draw(D_camera_check_80249914);
        func_8036EE40_8425F0();
        if (D_camera_check_80208954 == 3) {
            func_800A86A4(func_camera_check_801DEA5C, 6, 0, NULL)->userData = (void*) 0xFF;
        }
        UIElement_SetState(sp34, UI_HIDDEN);
        UIFrame_FadeOut(sp30);
        switch (*weird) {
            case 1:
                UIFrame_FadeIn(sp30, FRAME_STYLE_1);
                break;
            case 2:
                UIFrame_FadeIn(sp30, FRAME_STYLE_1);
                break;
            case 3:
                func_800A86A4(func_camera_check_801DEA5C, 6, 0, NULL)->userData = (void*) -0xFF;
                UIFrame_FadeIn(sp30, FRAME_STYLE_2);
                break;
            case 4:
                UIFrame_FadeIn(sp30, FRAME_STYLE_3);
                break;
        }
        UIElement_SetState(sp34, UI_NORMAL);
        UIFrame_GetBackgroundColor(sp30, &sp2C);
        UIElement_SetColor(sp34, UI_BACKGROUND, sp2C.r, sp2C.g, sp2C.b, 255);
        D_camera_check_80208954 = arg0;
    }
}

void func_camera_check_801DEC2C(char* arg0) {
    UIElement* temp_a0;

    UIElement_Draw(D_camera_check_80249914);
    temp_a0 = D_camera_check_80249914;
    UIElement_SetTextStyle(temp_a0, FONT_8);
    UIElement_SetTextPos(temp_a0, 0, 0);
    UIElement_PrintText(temp_a0, arg0);
}

void func_camera_check_801DEC84(void) {
    auPlaySong(0, 0x10);
    func_camera_check_801DDA44(0);
    func_803700A4_843854(0);
    func_803713EC_844B9C(3);
    UIElement_Delete(D_camera_check_80249910);
}

void func_camera_check_801DECCC(s32 arg0) {
    UIElement* sp4C;
    char sp24[0x28];

    sp4C = D_camera_check_80249914;
    switch (arg0) {
        case 1:
        case 9:
            UIElement_FillRectDefault(sp4C, 0, 0, 191, 14);
            sprintf(sp24, "\\i%d\\g pictures have been taken.", arg0 + 1);
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            UIElement_FillRectDefault(sp4C, 0, 0, 9, 14);
            sprintf(sp24, "\\i%d\\g", arg0 + 1);
            break;
        default:
            UIElement_FillRectDefault(sp4C, 0, 0, 18, 14);
            sprintf(sp24, "\\i%d\\g", arg0 + 1);
            break;
    }
    UIElement_SetTextPos(sp4C, 0, 0);
    UIElement_PrintText(sp4C, sp24);
    auPlaySound(0x5C);
    ohWait(1);
}

void func_camera_check_801DEDEC(UIElement* arg0) {
    char* sp34;
    s32 pad;
    s32 sp2C;
    s32 pad2;

    sp34 = getLevelName(getLevelId());
    if (sp34 != NULL) {
        UIElement_Draw(arg0);
        UIElement_SetTextStyle(arg0, FONT_12);
        UIElement_SetTextPos(arg0, 54 - (strlen(sp34) * 3), 0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        UIElement_SetColor(arg0, UI_BACKGROUND, 64, 64, 64, 0);
        func_8037519C_84894C(arg0, "%s Course", sp34);
        UIElement_SetTextStyle(arg0, FONT_8);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        UIElement_SetColor(arg0, UI_BACKGROUND, 0, 0, 0, 0);

        if (checkPlayerFlag(PFID_11)) {
            sp2C = func_803751F8_8489A8(getLevelId());
            if (sp2C < func_800C0224_5D0C4(getLevelId())) {
                UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 0, 255);
            } else {
                UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 255, 255);
            }
            UIElement_SetTextPos(arg0, 0, 16);
            UIElement_PrintText(arg0, "HI-SCORE");
            sprintf(D_camera_check_80249928, "\\i%8d\\g pts", func_800C0224_5D0C4(getLevelId()));
            UIElement_SetTextPos(arg0, 85, 16);
            UIElement_PrintText(arg0, D_camera_check_80249928);
            sp2C = func_803751F8_8489A8(getLevelId());
            if (sp2C < func_800C0224_5D0C4(getLevelId())) {
                UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 255, 255);
            } else {
                UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 0, 255);
            }
            UIElement_SetTextPos(arg0, 0, 28);
            UIElement_PrintText(arg0, "CHALLENGE SCORE");
            sprintf(D_camera_check_80249928, "\\i%8d\\g pts", func_803751F8_8489A8(getLevelId()));
            UIElement_SetTextPos(arg0, 85, 28);
            UIElement_PrintText(arg0, D_camera_check_80249928);
            UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 255, 255);
        }
    }
}

void func_camera_check_801DF0D4(UIElement* arg0, UIElement* arg1, s32 arg2, s32 arg3) {
    UIElement_Draw(arg0);
    UIElement_SetTextPos(arg0, 0, 0);
    UIElement_PrintText(arg0, "Pictures");
    sprintf(D_camera_check_80249928, "\\i%10d\\g pts", func_camera_check_801E246C());
    UIElement_SetTextPos(arg0, 56, 0);
    UIElement_PrintText(arg0, D_camera_check_80249928);
    UIElement_SetTextPos(arg0, 0, 16);
    UIElement_PrintText(arg0, "Pokεmon");
    sprintf(D_camera_check_80249928, "\\i       x%2d\\g kinds", func_camera_check_801E2478());
    UIElement_SetTextPos(arg0, 56, 16);
    UIElement_PrintText(arg0, D_camera_check_80249928);

    if (arg3) {
        if (func_800C0224_5D0C4(getLevelId()) < arg2) {
            func_800C0254_5D0F4(getLevelId(), arg2);
            if (func_803751F8_8489A8(getLevelId()) < arg2) {
                auPlaySong(1, 0x21);
                UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 0, 255);
            }
            func_camera_check_801DEDEC(arg1);
        }
        UIElement_SetTextPos(arg0, 0, 32);
        UIElement_PrintText(arg0, "Score");
        sprintf(D_camera_check_80249928, "\\i%10d\\g pts", arg2);
        UIElement_SetTextPos(arg0, 56, 32);
        UIElement_PrintText(arg0, D_camera_check_80249928);
        UIElement_SetColor(arg0, UI_FOREGROUND, 255, 255, 255, 255);
    }
}

void func_camera_check_801DF2D8(GObj* arg0) {
    char pad[0x10];
    UIElement* sp6C;
    UIFrame* sp68;
    ucolor sp64;
    char pad2[0x8];
    UIElement* temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    GObj* gobj;
    s32 i;
    UIElement* new_var;
    UIElement* sp44;

    func_803717E8_844F98();
    func_80370428_843BD8();
    func_803700A4_843854(0);
    func_8036EE40_8425F0();

    if (temp_s0 && temp_s0 && temp_s0) {
        // TODO fake match - fixes regalloc
    }

    sp68 = UIFrame_Create();
    D_camera_check_80249920 = sp68;
    UIFrame_SetStyle(sp68, FRAME_STYLE_0);
    UIFrame_GetBackgroundColor(sp68, &sp64);
    UIFrame_SetPos(sp68, 184, 320);
    UIFrame_Show(sp68, false);

    sp6C = UIElement_Create(146, 22, 108, 16, 0);
    UIElement_SetColor(sp6C, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp6C, UI_BACKGROUND, 218, 108, 0, 0);
    UIElement_DrawBackground(sp6C);
    UIElement_SetTextStyle(sp6C, FONT_12);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    UIElement_SetState(sp6C, UI_NORMAL);
    D_camera_check_80249918 = sp6C;

    sp6C = UIElement_Create(0, 53, 92, 12, 0);
    UIElement_SetColor(sp6C, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp6C, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_DrawBackground(sp6C);
    UIElement_SetState(sp6C, UI_HIDDEN);
    D_camera_check_8024991C = sp6C;

    sp6C = UIElement_Create(104, 173, 192, 47, 0);
    UIElement_SetColor(sp6C, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp6C, UI_BACKGROUND, sp64.r, sp64.g, sp64.b, 255);
    UIElement_DrawBackground(sp6C);
    UIElement_SetState(sp6C, UI_HIDDEN);
    ohWait(1);

    for (i = 0; i < 60; i++) {
        func_camera_check_801DCB58(i * 255 / 60);
        ohWait(1);
    }

    func_camera_check_801DCB58(0xFF);
    func_8037172C_844EDC(1);
    func_803713C8_844B78(0);
    ohWait(12);
    func_80370C34_8443E4(func_camera_check_801DFA4C());
    if (!checkPlayerFlag(8)) {
        func_80370780_843F30(1, 0x18);
    }
    func_803705A4_843D54();
    UIFrame_FadeIn(sp68, FRAME_STYLE_0);
    UIElement_SetState(sp6C, UI_NORMAL);
    func_8036D4A0_840C50(0);
    UIElement_SetTextStyle(sp6C, FONT_12);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    UIElement_SetTextStyle(sp6C, FONT_12);
    func_8036D4A0_840C50(0);
    D_camera_check_80249914 = sp6C;

    gobj = func_80371D14_8454C4(0, 6, &D_camera_check_801F0560);
    gobj->data.sobj->sprite.x = 96;
    gobj->data.sobj->sprite.y = 42;

    sp44 = UIElement_Create(128, 110, 160, 38, 0);
    new_var = sp44;
    UIElement_SetColor(new_var, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp44, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_DrawBackground(sp44);
    func_camera_check_801DEDEC(sp44);

    temp_s0 = D_camera_check_80249914;
    func_8036D4A0_840C50(2);
    UIElement_SetTextPos(temp_s0, 0, 0);
    UIElement_PrintText(temp_s0, "\\i1\\g picture has been taken.");
    func_8036D4A0_840C50(0);
    func_camera_check_801E3EEC(func_camera_check_801DECCC);
    temp_s2 = func_camera_check_801E246C();
    temp_s1 = func_camera_check_801E2478() * temp_s2;

    if (checkPlayerFlag(PFID_11)) {
        func_camera_check_801DF0D4(temp_s0, new_var, temp_s1, false);
        func_80374F30_8486E0(temp_s0, true);
        func_camera_check_801DF0D4(temp_s0, new_var, temp_s1, true);
    }

    if (!checkPlayerFlag(PFID_18) && func_800BF864_5C704() >= 4) {
        setPlayerFlag(PFID_18, 1);
        func_80374F30_8486E0(temp_s0, true);
        UIElement_Draw(temp_s0);
        func_8036EB80_842330(0);
        func_8036D4A0_840C50(2);
        UIElement_PrintText(temp_s0, "I can use the \"\\hAlbum Mark\\p \\u\"\nto save my favorite pictures\nin the Album.");
        func_8036EB80_842330(1);
    }

    func_80374F30_8486E0(temp_s0, true);
    UIElement_SetState(new_var, UI_HIDDEN);
    ohWait(1);
    UIElement_Delete(new_var);
    omDeleteGObj(gobj);
    func_camera_check_801DD1F0();
    func_camera_check_801DDA44(0);
    func_camera_check_801DDFC4();
    func_camera_check_801DDAD8(0);
    func_camera_check_801DDB08(0);

    while (true) {
        func_camera_check_801E21E8();
        func_803700A4_843854(0);
        UIElement_SetState(D_camera_check_80249914, UI_HIDDEN);
        if (D_camera_check_80249910 != NULL) {
            UIElement_Delete(D_camera_check_80249910);
        }
        func_803713C8_844B78(0);
        func_80370A48_8441F8();
        UIFrame_FadeOut(sp68);

        for (i = 10; i >= 0; i--) {
            func_camera_check_801DCB58(i * 255 / 10);
            func_camera_check_801DD93C(i * 255 / 10);
            ohWait(1);
        }

        func_camera_check_801DCB58(0);
        func_camera_check_801DD93C(0);
        func_803705A4_843D54();
        ohWait(3);
        func_8036EE40_8425F0();
        func_80374D20_8484D0();
        if (func_camera_check_801E27FC()) {
            func_800AADF0(SCENE_PHOTO_CHECK);
        } else {
            func_800AAED0(SCENE_16);
            func_800AADF0(SCENE_OAKS_LAB_2);
        }
        ohWait(1);
    }
}

void func_camera_check_801DF938(void) {
    SObj* sobj;

    func_800A85E8(func_camera_check_801DF2D8, LINK_6, DL_LINK_0, NULL);
    sobj = func_80371D14_8454C4(0, 6, &D_camera_check_801FCC58)->data.sobj;
    sobj->sprite.width = 640;
    sobj->sprite.height = 480;
    sobj->sprite.istep = 0;
    D_camera_check_802499A8 = sobj;
    func_camera_check_801DCC0C();
    func_camera_check_801DCB58(0);
}
