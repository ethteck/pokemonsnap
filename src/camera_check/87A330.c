#include "common.h"
#include "camera_check.h"
#include "more_funcs/more_funcs.h"
#include "string.h"

UnkSnowHerring* func_camera_check_801DCB40(void) {
    return D_camera_check_80249914;
}

UnkSnowHerring* func_camera_check_801DCB4C(void) {
    return D_camera_check_80249918;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DCB58.s")

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

    gobj = func_80371C68_845418(0, 6, &D_camera_check_801FE318);
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

void func_camera_check_801DD238(UnkTealFlounder*, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD238.s")

// void func_camera_check_801DD238(UnkTealFlounder* arg0, s32 arg1, s32 arg2) {
//     UNUSED s32 pad[4];
//     UnkIndigoHalibut* temp_v0;

//     if (arg0 == NULL || (temp_v0 = func_camera_check_801E24D8(arg1), (temp_v0 == NULL))) {
//         if (arg0 != NULL) {
//             arg0->unk_04->sprite.attr |= SP_HIDDEN;
//             arg0->unk_08->sprite.attr |= SP_HIDDEN;
//             arg0->unk_14->sprite.attr |= SP_HIDDEN;
//             arg0->unk_10->sprite.attr |= SP_HIDDEN;
//             arg0->unk_18->sprite.attr |= SP_HIDDEN;
//             arg0->unk_0C->sprite.red = 0xFF;
//             arg0->unk_0C->sprite.green = 0xFF;
//             arg0->unk_0C->sprite.blue = 0xFF;
//         }
//     } else {
//         checkPlayerFlag(6);
//         if (temp_v0->unk_08 != 9999) {
//             if (temp_v0->unk_08 <= POKEDEX_MAX) {
//                 if (arg2 & 1) {
//                 }
//             } else {
//                 checkPlayerFlag(5);
//             }
//         }

//         if (temp_v0->unk_18_0x80000000) {
//             arg0->unk_04->sprite.attr &= ~SP_HIDDEN;
//         } else {
//             arg0->unk_04->sprite.attr |= SP_HIDDEN;
//         }

//         if (temp_v0->unk_18_0x40000000) {
//             arg0->unk_08->sprite.attr &= ~SP_HIDDEN;
//         } else {
//             arg0->unk_08->sprite.attr |= SP_HIDDEN;
//         }

//         if ((temp_v0->unk_18_0x01000000) && !(arg2 & 0x20)) {
//             arg0->unk_00->data.sobj->sprite.red = 0x80;
//             arg0->unk_00->data.sobj->sprite.green = 0x80;
//             arg0->unk_00->data.sobj->sprite.blue = 0x80;
//         } else {
//             arg0->unk_00->data.sobj->sprite.red = 0xFF;
//             arg0->unk_00->data.sobj->sprite.green = 0xFF;
//             arg0->unk_00->data.sobj->sprite.blue = 0xFF;
//         }

//         if (arg2 & 1) {
//             arg0->unk_14->unk_54 = 0;
//             arg0->unk_14->sprite.attr &= ~SP_HIDDEN;
//             if (temp_v0->unk_18_0x20000000 || temp_v0->unk_18_0x10000000) {
//                 arg0->unk_14->sprite.alpha = 0xFF;
//                 arg0->unk_18->sprite.attr |= SP_HIDDEN;
//                 if (arg2 & 8) {
//                     arg0->unk_14->unk_54 = 2;
//                 } else {
//                     arg0->unk_14->unk_54 = 1;
//                 }
//             } else {
//                 if (arg2 & 0x10) {
//                     arg0->unk_14->sprite.attr |= SP_HIDDEN;
//                 } else {
//                     arg0->unk_14->sprite.alpha = 0x80;
//                     arg0->unk_14->unk_54 = 0;
//                 }

//                 if (arg2 & 0x80) {
//                     arg0->unk_18->sprite.attr &= ~SP_HIDDEN;
//                 } else {
//                     arg0->unk_18->sprite.attr |= SP_HIDDEN;
//                 }
//             }
//         } else {
//             arg0->unk_14->sprite.attr |= SP_HIDDEN;
//             arg0->unk_18->sprite.attr |= SP_HIDDEN;
//         }

//         if (arg2 & 4) {
//             arg0->unk_10->unk_54 = 0;
//             arg0->unk_10->sprite.attr &= ~SP_HIDDEN;
//             if (temp_v0->unk_18_0x08000000) {
//                 arg0->unk_10->sprite.alpha = 0xFF;
//                 arg0->unk_1C->sprite.attr |= SP_HIDDEN;
//                 if (arg2 & 8) {
//                     arg0->unk_10->unk_54 = 2;
//                 } else {
//                     arg0->unk_10->unk_54 = 1;
//                 }
//             } else {
//                 if (arg2 & 0x10) {
//                     arg0->unk_10->sprite.attr |= SP_HIDDEN;
//                 } else {
//                     arg0->unk_10->sprite.alpha = 0x80;
//                     arg0->unk_10->unk_54 = 0;
//                 }
//                 if (arg2 & 0x100) {
//                     arg0->unk_1C->sprite.attr &= ~SP_HIDDEN;
//                 } else {
//                     arg0->unk_1C->sprite.attr |= SP_HIDDEN;
//                 }
//             }
//         } else {
//             arg0->unk_10->sprite.attr |= SP_HIDDEN;
//             arg0->unk_1C->sprite.attr |= SP_HIDDEN;
//         }
//     }
// }

void func_camera_check_801DD630(s32 arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 6; i++, arg0++) {
        func_camera_check_801DD238(&D_camera_check_802499C0[arg0 % 6], arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD83C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD93C.s")

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
        func_8036D1A4_840954(D_camera_check_8024991C, 0);
    } else {
        D_camera_check_802499C0[6].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        func_8036D1A4_840954(D_camera_check_8024991C, 1);
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
        func_8036D1A4_840954(D_camera_check_8024991C, 1);
        return;
    }

    D_camera_check_802499C0[6].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
    func_8036A8E4_83E094(D_camera_check_8024991C);
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
        func_8036B9EC_83F19C(D_camera_check_8024991C, 0, 2);
    }
    func_8036B9EC_83F19C(D_camera_check_8024991C, 0, 2);
    func_8036C898_840048(D_camera_check_8024991C, sp1C);
    func_8036D1A4_840954(D_camera_check_8024991C, 0);
}

void func_camera_check_801DDD28(s32 arg0) {
    if (!D_camera_check_80249910) {
        return;
    }

    if (arg0) {
        func_8036D1A4_840954(D_camera_check_80249910, 0);
        func_803713D4_844B84(4);
        func_8036D1A4_840954(D_camera_check_80249918, 0);
    } else {
        func_8036D1A4_840954(D_camera_check_80249910, 1);
        func_8036D1A4_840954(D_camera_check_80249918, 1);
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
    UnkSnowHerring* temp_v0_2;

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

    temp_v0_2 = func_8036AC6C_83E41C(0x100, 0x32, 0x54, 0x70, 0x10);
    func_8036B870_83F020(temp_v0_2, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(temp_v0_2, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(temp_v0_2);
    func_8036D1A4_840954(temp_v0_2, 1);
    D_camera_check_80249910 = temp_v0_2;
    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036CB58_840308(temp_v0_2, 8);
    func_8036B9EC_83F19C(temp_v0_2, 0, 0);
    func_8036C898_840048(temp_v0_2, "Course");
    func_8036B9EC_83F19C(temp_v0_2, 0, 0x1C);
    func_8036C898_840048(temp_v0_2, "Photo by");

    return temp_v0;
}

void func_camera_check_801DE288(UnkIndigoHalibut* arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DE288.s")

// void func_camera_check_801DE288(UnkIndigoHalibut* arg0) {
//     char* sp68;
//     char* var_a3_2;
//     char sp48[0x20];
//     UnkSnowHerring* temp_s0;
//     char* levelName;

//     temp_s0 = D_camera_check_80249910;
//     func_8036A5B8_83DD68(temp_s0, 0, 0xC, 0x53, 0x16, 0, 0, 0, 0);
//     func_8036A5B8_83DD68(temp_s0, 0, 0x28, 0x53, 0x32, 0, 0, 0, 0);
//     func_8036A5B8_83DD68(temp_s0, 0, 0x38, 0x53, 0x42, 0, 0, 0, 0);
//     func_8036A5B8_83DD68(temp_s0, 0, 0x44, 0x53, 0x4E, 0, 0, 0, 0);
//     func_8036A5B8_83DD68(temp_s0, 0, 0x54, 0x53, 0x6A, 0, 0, 0, 0);
//     if (arg0 != NULL) {
//         func_8036D448_840BF8(1);
//         func_8036D3E8_840B98(-1, 3);
//         func_8036CB58_840308(temp_s0, 8);
//         levelName = getLevelName(arg0->unk_00->levelID);
//         if (levelName == NULL) {
//             levelName = "ーーー";
//         }
//         sprintf(sp48, "%s", levelName, levelName);
//         func_8036CB58_840308(temp_s0, 8);
//         func_8036B9EC_83F19C(temp_s0, 0x2D - func_8036D4F0_840CA0(sp48), 0xC);
//         func_8036C898_840048(temp_s0, sp48);
//         sprintf(sp48, "%s", get_player_name());

//         if (var_a3_2 && var_a3_2 && var_a3_2) {
//         }

//         func_8036CB58_840308(temp_s0, 8);
//         func_8036B9EC_83F19C(temp_s0, 0x2D - func_8036D4F0_840CA0(sp48), 0x28);
//         func_8036C898_840048(temp_s0, sp48);
//         var_a3_2 = "";
//         if (!(arg0->unk_18_0x04000000)) {
//             sprintf(sp48, "%s", getPokemonName(arg0->unk_08));
//             sp68 = sp48;
//             var_a3_2 = sp48;
//             if (func_camera_check_801E2EA0(arg0->unk_08)) {
//                 if (arg0->unk_18_0x80000000) {
//                     var_a3_2 = "Sign?";
//                 } else {
//                     var_a3_2 = "Sign";
//                 }
//             }
//         }
//         sp68 = var_a3_2;
//         func_8036A8E4_83E094(D_camera_check_80249918);
//         func_8036CB58_840308(D_camera_check_80249918, 0xC);
//         func_8036B9EC_83F19C(D_camera_check_80249918, (108 - func_8036D4F0_840CA0(sp68)) / 2, 0);
//         func_8036C898_840048(D_camera_check_80249918, sp68);
//     } else {
//         func_8036B9EC_83F19C(temp_s0, 0, 12);
//         func_8036C898_840048(temp_s0, "ーーーーー");
//         func_8036B9EC_83F19C(temp_s0, 0, 40);
//         func_8036C898_840048(temp_s0, "ーーーーー");
//     }
// }

void func_camera_check_801DE59C(UnkIndigoHalibut* arg0) {
    s32 sp6C; // BUG: never set?
    UnkSnowHerring* temp_s0;
    char* levelName;
    char sp44[0x20];
    UNUSED s32 pad;

    temp_s0 = D_camera_check_80249910;
    func_8036A5B8_83DD68(temp_s0, 0, 0xC, 0x53, 0x16, 0, 0, 0, 0);
    func_8036A5B8_83DD68(temp_s0, 0, 0x28, 0x53, 0x32, 0, 0, 0, 0);
    func_8036A5B8_83DD68(temp_s0, 0, 0x44, 0x53, 0x4E, 0, 0, 0, 0);
    func_8036A5B8_83DD68(temp_s0, 0, 0x54, 0x53, 0x6A, 0, 0, 0, 0);
    func_8036B9EC_83F19C(temp_s0, 0, 0x38);
    func_8036C898_840048(temp_s0, "Score");

    if (sp6C) {
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036CB58_840308(temp_s0, 8);
        levelName = getLevelName(arg0->unk_00->levelID);
        if (levelName == NULL) {
            levelName = "ーーー";
        }
        sprintf(sp44, "%s", levelName);
        func_8036B9EC_83F19C(temp_s0, 45 - func_8036D4F0_840CA0(sp44), 12);
        func_8036C898_840048(temp_s0, sp44);
        sprintf(sp44, "%s", get_player_name());
        func_8036B9EC_83F19C(temp_s0, 45 - func_8036D4F0_840CA0(sp44), 40);
        func_8036C898_840048(temp_s0, sp44);
        sprintf(sp44, "%d", arg0->unk_04);
        func_8036B9EC_83F19C(temp_s0, 45 - func_8036D4F0_840CA0(sp44), 68);
        func_8036C898_840048(temp_s0, sp44);
    } else {
        func_8036B9EC_83F19C(temp_s0, 0, 12);
        func_8036C898_840048(temp_s0, "ーーーーー");
        func_8036B9EC_83F19C(temp_s0, 0, 40);
        func_8036C898_840048(temp_s0, "ーーーーー");
        func_8036B9EC_83F19C(temp_s0, 0, 68);
        func_8036C898_840048(temp_s0, "ーーーーー");
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

UnkSnowHerring* func_camera_check_801DEA50(void) {
    return D_camera_check_80249910;
}

extern s32 D_camera_check_80208954;

void func_camera_check_801DEA5C(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DEA5C.s")

// TODO unused? arg type may be wrong, requiring the weird temp
void func_camera_check_801DEAC0(s32 arg0) {
    UnkSnowHerring* sp34;
    s32 sp30;
    ucolor sp2C;
    s32* weird;

    weird = &arg0; // TODO required to match

    if (D_camera_check_80208954 != *weird) {
        sp34 = D_camera_check_80249914;
        sp30 = D_camera_check_80249920;
        func_8036A8E4_83E094(D_camera_check_80249914);
        func_8036EE40_8425F0();
        if (D_camera_check_80208954 == 3) {
            func_800A86A4(&func_camera_check_801DEA5C, 6, 0, NULL)->userData = (void*) 0xFF;
        }
        func_8036D1A4_840954(sp34, 1);
        func_8036FF20_8436D0(sp30);
        switch (*weird) {
            case 1:
                func_8036FE54_843604(sp30, 1);
                break;
            case 2:
                func_8036FE54_843604(sp30, 1);
                break;
            case 3:
                func_800A86A4(func_camera_check_801DEA5C, 6, 0, NULL)->userData = (void*) -0xFF;
                func_8036FE54_843604(sp30, 2);
                break;
            case 4:
                func_8036FE54_843604(sp30, 3);
                break;
        }
        func_8036D1A4_840954(sp34, 0);
        func_8036F738_842EE8(sp30, &sp2C);
        func_8036B870_83F020(sp34, 0, sp2C.r, sp2C.g, sp2C.b, 0xFF);
        D_camera_check_80208954 = arg0;
    }
}

void func_camera_check_801DEC2C(char* arg0) {
    UnkSnowHerring* temp_a0;

    func_8036A8E4_83E094(D_camera_check_80249914);
    temp_a0 = D_camera_check_80249914;
    func_8036CB58_840308(temp_a0, 8);
    func_8036B9EC_83F19C(temp_a0, 0, 0);
    func_8036C898_840048(temp_a0, arg0);
}

void func_camera_check_801DEC84(void) {
    auPlaySong(0, 0x10);
    func_camera_check_801DDA44(0);
    func_803700A4_843854(0);
    func_803713EC_844B9C(3);
    func_8036B5F0_83EDA0(D_camera_check_80249910);
}

void func_camera_check_801DECCC(s32 arg0) {
    UnkSnowHerring* sp4C;
    char sp24[0x28];

    sp4C = D_camera_check_80249914;
    switch (arg0) {
        case 1:
        case 9:
            func_8036A968_83E118(sp4C, 0, 0, 0xBF, 0xE);
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
            func_8036A968_83E118(sp4C, 0, 0, 9, 0xE);
            sprintf(sp24, "\\i%d\\g", arg0 + 1);
            break;
        default:
            func_8036A968_83E118(sp4C, 0, 0, 0x12, 0xE);
            sprintf(sp24, "\\i%d\\g", arg0 + 1);
            break;
    }
    func_8036B9EC_83F19C(sp4C, 0, 0);
    func_8036C898_840048(sp4C, sp24);
    auPlaySound(0x5C);
    ohWait(1);
}

void func_camera_check_801DEDEC(UnkSnowHerring* arg0) {
    char* sp34;
    s32 pad;
    s32 sp2C;
    s32 pad2;

    sp34 = getLevelName(getLevelId());
    if (sp34 != NULL) {
        func_8036A8E4_83E094(arg0);
        func_8036CB58_840308(arg0, 0xC);
        func_8036B9EC_83F19C(arg0, 54 - (strlen(sp34) * 3), 0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B870_83F020(arg0, 0, 0x40, 0x40, 0x40, 0);
        func_8037519C_84894C(arg0, "%s Course", sp34);
        func_8036CB58_840308(arg0, 8);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036B870_83F020(arg0, 0, 0, 0, 0, 0);

        if (checkPlayerFlag(PFID_11)) {
            sp2C = func_803751F8_8489A8(getLevelId());
            if (sp2C < func_800C0224_5D0C4(getLevelId())) {
                func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0, 0xFF);
            } else {
                func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_8036B9EC_83F19C(arg0, 0, 16);
            func_8036C898_840048(arg0, "HI-SCORE");
            sprintf(D_camera_check_80249928, "\\i%8d\\g pts", func_800C0224_5D0C4(getLevelId()));
            func_8036B9EC_83F19C(arg0, 85, 16);
            func_8036C898_840048(arg0, D_camera_check_80249928);
            sp2C = func_803751F8_8489A8(getLevelId());
            if (sp2C < func_800C0224_5D0C4(getLevelId())) {
                func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0, 0xFF);
            }
            func_8036B9EC_83F19C(arg0, 0, 28);
            func_8036C898_840048(arg0, "CHALLENGE SCORE");
            sprintf(D_camera_check_80249928, "\\i%8d\\g pts", func_803751F8_8489A8(getLevelId()));
            func_8036B9EC_83F19C(arg0, 85, 28);
            func_8036C898_840048(arg0, D_camera_check_80249928);
            func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }
}

void func_camera_check_801DF0D4(UnkSnowHerring* arg0, UnkSnowHerring* arg1, s32 arg2, s32 arg3) {
    func_8036A8E4_83E094(arg0);
    func_8036B9EC_83F19C(arg0, 0, 0);
    func_8036C898_840048(arg0, "Pictures");
    sprintf(D_camera_check_80249928, "\\i%10d\\g pts", func_camera_check_801E246C());
    func_8036B9EC_83F19C(arg0, 56, 0);
    func_8036C898_840048(arg0, D_camera_check_80249928);
    func_8036B9EC_83F19C(arg0, 0, 16);
    func_8036C898_840048(arg0, "Pokεmon");
    sprintf(D_camera_check_80249928, "\\i       x%2d\\g kinds", func_camera_check_801E2478());
    func_8036B9EC_83F19C(arg0, 56, 16);
    func_8036C898_840048(arg0, D_camera_check_80249928);

    if (arg3) {
        if (func_800C0224_5D0C4(getLevelId()) < arg2) {
            func_800C0254_5D0F4(getLevelId(), arg2);
            if (func_803751F8_8489A8(getLevelId()) < arg2) {
                auPlaySong(1, 0x21);
                func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0, 0xFF);
            }
            func_camera_check_801DEDEC(arg1);
        }
        func_8036B9EC_83F19C(arg0, 0, 0x20);
        func_8036C898_840048(arg0, "Score");
        sprintf(D_camera_check_80249928, "\\i%10d\\g pts", arg2);
        func_8036B9EC_83F19C(arg0, 0x38, 0x20);
        func_8036C898_840048(arg0, D_camera_check_80249928);
        func_8036B870_83F020(arg0, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    }
}

void func_camera_check_801DF2D8(GObj* arg0) {
    char pad[0x10];
    UnkSnowHerring* sp6C;
    s32 sp68;
    ucolor sp64;
    char pad2[0x8];
    UnkSnowHerring* temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    GObj* gobj;
    s32 i;
    UnkSnowHerring* new_var;
    UnkSnowHerring* sp44;

    func_803717E8_844F98();
    func_80370428_843BD8();
    func_803700A4_843854(0);
    func_8036EE40_8425F0();

    if (temp_s0 && temp_s0 && temp_s0) {
        // TODO fake match - fixes regalloc
    }

    sp68 = func_8036F78C_842F3C();
    D_camera_check_80249920 = sp68;
    func_8036F684_842E34(sp68, 0);
    func_8036F738_842EE8(sp68, &sp64);
    func_8036F1F4_8429A4(sp68, 0xB8, 0x140);
    func_8036F0DC_84288C(sp68, 0);

    sp6C = func_8036AC6C_83E41C(0x92, 0x16, 0x6C, 0x10, 0);
    func_8036B870_83F020(sp6C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp6C, 0, 0xDA, 0x6C, 0, 0);
    func_8036B734_83EEE4(sp6C);
    func_8036CB58_840308(sp6C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036D1A4_840954(sp6C, 0);
    D_camera_check_80249918 = sp6C;

    sp6C = func_8036AC6C_83E41C(0, 0x35, 0x5C, 0xC, 0);
    func_8036B870_83F020(sp6C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp6C, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(sp6C);
    func_8036D1A4_840954(sp6C, 1);
    D_camera_check_8024991C = sp6C;

    sp6C = func_8036AC6C_83E41C(0x68, 0xAD, 0xC0, 0x2F, 0);
    func_8036B870_83F020(sp6C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp6C, 0, sp64.r, sp64.g, sp64.b, 0xFF);
    func_8036B734_83EEE4(sp6C);
    func_8036D1A4_840954(sp6C, 1);
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
    func_8036FE54_843604(sp68, 0);
    func_8036D1A4_840954(sp6C, 0);
    func_8036D4A0_840C50(0);
    func_8036CB58_840308(sp6C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036CB58_840308(sp6C, 0xC);
    func_8036D4A0_840C50(0);
    D_camera_check_80249914 = sp6C;

    gobj = func_80371D14_8454C4(0, 6, &D_camera_check_801F0560);
    gobj->data.sobj->sprite.x = 96;
    gobj->data.sobj->sprite.y = 42;

    sp44 = func_8036AC6C_83E41C(0x80, 0x6E, 0xA0, 38, 0);
    new_var = sp44;
    func_8036B870_83F020(new_var, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp44, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(sp44);
    func_camera_check_801DEDEC(sp44);

    temp_s0 = D_camera_check_80249914;
    func_8036D4A0_840C50(2);
    func_8036B9EC_83F19C(temp_s0, 0, 0);
    func_8036C898_840048(temp_s0, "\\i1\\g picture has been taken.");
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
        func_8036A8E4_83E094(temp_s0);
        func_8036EB80_842330(0);
        func_8036D4A0_840C50(2);
        func_8036C898_840048(temp_s0, "I can use the \"\\hAlbum Mark\\p \\u\"\nto save my favorite pictures\nin the Album.");
        func_8036EB80_842330(1);
    }

    func_80374F30_8486E0(temp_s0, true);
    func_8036D1A4_840954(new_var, 1);
    ohWait(1);
    func_8036B5F0_83EDA0(new_var);
    omDeleteGObj(gobj);
    func_camera_check_801DD1F0();
    func_camera_check_801DDA44(0);
    func_camera_check_801DDFC4();
    func_camera_check_801DDAD8(0);
    func_camera_check_801DDB08(0);

    while (true) {
        func_camera_check_801E21E8();
        func_803700A4_843854(0);
        func_8036D1A4_840954(D_camera_check_80249914, 1);
        if (D_camera_check_80249910 != NULL) {
            func_8036B5F0_83EDA0(D_camera_check_80249910);
        }
        func_803713C8_844B78(0);
        func_80370A48_8441F8();
        func_8036FF20_8436D0(sp68);

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
            func_800AADF0(0xF);
        } else {
            func_800AAED0(0x10);
            func_800AADF0(0xD);
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
