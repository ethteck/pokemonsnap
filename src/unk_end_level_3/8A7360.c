#include "common.h"
#include "unk_end_level_3.h"

// TODO: part of Sprite. Included for alignment.
s32 D_801957E0_95B000 = 0;
s32 D_801957E4_95B004 = 0;
s32 D_801957E4_95B008 = 0;
// end Sprite

s32 D_801957EC_95B00C = 0;

s32 func_800E1B40_8A7360(void) {
    return D_80206B1C_9CC33C;
}

s32 func_800E1B4C_8A736C(void) {
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

void func_800E1BF4_8A7414(u32 arg0) {
    D_80206B10_9CC330->sprite.red = arg0;
    D_80206B10_9CC330->sprite.green = arg0;
    D_80206B10_9CC330->sprite.blue = arg0;
}

void func_800E1C18_8A7438(s32 arg0) {
    if (arg0) {
        D_80206B30_9CC350->sprite.attr |= 4;
        D_80206B14_9CC334->sprite.attr |= 4;
        D_80206B10_9CC330->sprite.attr &= 0xFFFB;
    } else {
        D_80206B30_9CC350->sprite.attr &= 0xFFFB;
        D_80206B14_9CC334->sprite.attr &= 0xFFFB;
        D_80206B10_9CC330->sprite.attr |= 4;
    }
}

void func_800E1CA0_8A74C0(s32 arg0) {
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
    D_80136468_8FBC88,
    D_8012B298_8F0AB8,
    D_801387F8_8FE018,
    D_8012D628_8F2E48,
    D_8012F9B8_8F51D8,
    D_801340D8_8F98F8,
    D_80131D48_8F7568,
};

Bitmap* D_80195810_95B030[] = {
    D_801482E8_90DB08,
    D_80146908_90C128,
    D_80148B88_90E3A8,
    D_801471A8_90C9C8,
    D_80149428_90EC48,
    D_80147A48_90D268,
};
Bitmap* D_80195828_95B048[] = {
    D_8014B828_911048,
    D_80149A28_90F248,
    D_8014BE28_911648,
    D_8014A028_90F848,
    D_8014C428_911C48,
    D_8014A628_90FE48,
    D_8014E228_913A48,
    D_8014D628_912E48,
    D_8014E828_914048,
    D_8014DC28_913448,
};

void func_800E1D1C_8A753C(s32 arg0) {
    if (arg0) {
        D_801957EC_95B00C = 1;
        D_80206B28_9CC348[1]->sprite.attr &= 0xFFFB;
    } else {
        D_801957EC_95B00C = 0;
        D_80206B28_9CC348[1]->sprite.attr |= 4;
    }
}

void func_800E1D68_8A7588(u32 arg0) {
    switch (arg0) {
        case 0:
            D_801957EC_95B00C = 0;
            D_80206B28_9CC348[0]->sprite.attr |= 4;
            D_80206B28_9CC348[1]->sprite.attr |= 4;
            return;
        case 1:
            D_801957EC_95B00C = 1;
            return;
        case 2:
            D_80206B28_9CC348[0]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[0]->sprite.bitmap = D_801396E8_8FEF08; // Album
            D_80206B28_9CC348[1]->sprite.attr |= 4;
            return;
        case 3:
            D_80206B28_9CC348[0]->sprite.attr |= 4;
            D_80206B28_9CC348[1]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[1]->sprite.bitmap = D_8013BA58_901278; // Island
            return;
        case 4:
            D_80206B28_9CC348[0]->sprite.attr |= 4;
            D_80206B28_9CC348[1]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[1]->sprite.bitmap = D_8013DDE8_903608; // zero-one
            return;
        case 5:
            D_80206B28_9CC348[0]->sprite.attr |= 4;
            D_80206B28_9CC348[1]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[1]->sprite.bitmap = D_80136468_8FBC88; // Beach
            return;
        case 6:
            D_80206B28_9CC348[0]->sprite.attr |= 4;
            D_80206B28_9CC348[1]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[1]->sprite.bitmap = D_80140178_905998; // end gate
            return;
        case 7:
            D_80206B28_9CC348[0]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[0]->sprite.bitmap = D_80141F38_907758; // apple
            D_80206B28_9CC348[1]->sprite.attr |= 4;
            return;
        case 8:
            D_80206B28_9CC348[0]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[0]->sprite.bitmap = D_80142E08_908628; // pester ball
            D_80206B28_9CC348[1]->sprite.attr |= 4;
            return;
        case 9:
            D_80206B28_9CC348[0]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[0]->sprite.bitmap = D_80143CD8_9094F8; // pokeflute
            D_80206B28_9CC348[1]->sprite.attr |= 4;
            return;
        case 10:
            D_80206B28_9CC348[0]->sprite.attr &= 0xFFFB;
            D_80206B28_9CC348[0]->sprite.bitmap = D_80141068_906888; // engine
            D_80206B28_9CC348[1]->sprite.attr |= 4;
            return;
    }
}
void func_800E1FEC_8A780C(s32 stage) {
    if ((stage >= 0) && ((u32) stage < 7U)) {
        D_80206B28_9CC348[1]->sprite.bitmap = D_801957F4_95B014[stage];
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_800E1D1C_8A753C(1);
        return;
    }
    func_800E1D1C_8A753C(0);
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A7360/func_800E2058_8A7878.s")
#else
extern Bitmap* D_80195810_95B030[];
extern Bitmap* D_80195828_95B048[];
extern s32 D_80195854_95B074;
extern s32 D_8019585C_95B07C;
extern u32 D_80195860_95B080[];

void func_800E2058_8A7878(GObj* arg0) {
    s32 var_s4;
    s32 var_s6;
    s32 var_s5;
    s32 temp_t9;
    Bitmap** var_v1;

    var_s6 = 0;
    var_s5 = 0xC;
    var_s4 = 0;
    while (1) {
        if (D_80195850_95B070 == 2) {
            arg0->data.sobj->unk58->next->sprite.bitmap = D_80195810_95B030[D_80195850_95B070];
            arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
        } else {
            temp_t9 = D_80195854_95B074 - 1;
            if (D_80195854_95B074 != 0) {
                D_80195854_95B074 = temp_t9;
                if (temp_t9 == 0) {
                    var_s4 = 0;
                    arg0->data.sobj->unk58->next->sprite.bitmap = D_80195810_95B030[D_80195850_95B070];
                } else if (var_s5 != 0) {
                    var_s5 -= 1;
                    arg0->data.sobj->unk58->next->sprite.bitmap = D_80195810_95B030[var_s4 + D_80195850_95B070];
                } else {
                    var_s6 = (var_s6 + 1) & 3;
                    var_s4 = D_80195860_95B080[var_s6];
                    var_s5 = 7;
                    arg0->data.sobj->unk58->next->sprite.bitmap = D_80195810_95B030[var_s4 + D_80195850_95B070];
                }
            }
            if (D_8019585C_95B07C < -0x1E) {
                D_8019585C_95B07C += 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else if (D_8019585C_95B07C < -6) {
                D_8019585C_95B07C += 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else if (D_8019585C_95B07C < 0) {
                D_8019585C_95B07C += 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else if (D_8019585C_95B07C == 0) {
                D_8019585C_95B07C = 0xB4;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else if (D_8019585C_95B07C >= 0x13) {
                D_8019585C_95B07C -= 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else if (D_8019585C_95B07C >= 0xD) {
                D_8019585C_95B07C -= 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else if (D_8019585C_95B07C >= 7) {
                D_8019585C_95B07C -= 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            } else {
                D_8019585C_95B07C -= 1;
                arg0->data.sobj->unk58->sprite.bitmap = D_80195828_95B048[D_80195850_95B070];
            }
        }

        ohWait(1);
    }
}
#endif

void func_800E2350_8A7B70(void) {
    D_80195850_95B070 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A7360/func_800E235C_8A7B7C.s")

void func_800E2848_8A8068(void) {
    SObj* sobj;

    sobj = func_80371D14_8454C4(func_800E2058_8A7878, 6, &D_8011EEA0_8E46C0)->data.sobj;
    D_80206B14_9CC334 = sobj;
    sobj->sprite.x = 0x64;
    sobj->sprite.y = 0x22;

    sobj = func_80371E68_845618(sobj, &D_80149A38_90F258);
    sobj->sprite.x = 0x2B;
    sobj->sprite.y = 0x20;
    sobj = func_80371DC0_845570(sobj, &D_80146918_90C138);
    sobj->sprite.x = 0x28;
    sobj->sprite.y = 0x32;

    sobj = func_80371C68_845418(&func_800E1CA0_8A74C0, 6, &D_80122548_8E7D68)->data.sobj;
    D_80206B18_9CC338 = sobj;
    sobj->sprite.x = 0xD0;
    sobj->sprite.y = 0xD;

    sobj = func_80371E68_845618(sobj, &D_80136498_8FBCB8);
    sobj->sprite.x = 6;
    sobj->sprite.y = 6;
    sobj->sprite.attr |= 4;
    D_80206B28_9CC348[1] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_80141F48_907768);
    sobj->sprite.x = 0x19;
    sobj->sprite.y = 0xD;
    sobj->sprite.attr |= 4;
    D_80206B28_9CC348[0] = sobj;
}

s32 func_800E2960_8A8180(s32 arg0, char** arg1, s32 arg2) {
    s32 temp_v0;

    while (*arg1) {
        func_8036A8E4_83E094(arg0);
        func_8037519C_84894C(arg0, *arg1, get_player_name());
        temp_v0 = func_80374F30_8486E0(arg0, 1);
        if (arg2 && (temp_v0 == 0x4000)) {
            return 0x4000;
        }
        arg1++;
    }

    return 0;
}

void func_800E2A04_8A8224(void) {
    s32 sp24;
    s32 temp_a1;
    s32 temp_s0;
    s32 var_s0;

    sp24 = D_80206B1C_9CC33C;
    func_8036CB58_840308(D_80206B1C_9CC33C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    temp_s0 = func_800C0290_5D130();
    if (func_800BFC5C_5CAFC() < temp_s0) {
        func_800BFC70_5CB10(func_800C0290_5D130());
        ohWait(1);
        if ((func_800BFC5C_5CAFC() != 2) && (func_800BFC5C_5CAFC() != 4) && (func_800BFC5C_5CAFC() != 6)) {
            func_8036EB80_842330(0);
            func_8036D4A0_840C50(2);
            func_800E2960_8A8180(sp24, D_80195888_95B0A8, 0);
            func_8036D4A0_840C50(0);
        } else {
            ohWait(0x2A);
        }
        auPlaySound(0x52U);
        temp_a1 = func_800C0290_5D130() + 6;
        func_80370900_8440B0(1, temp_a1);
        func_80370990_844140(0.1f, temp_a1);
        if (func_800C0290_5D130() == 6) {
            func_800E60C8_8AB8E8();
        }
        var_s0 = 1;
        do {
            func_80370990_844140((f32) var_s0 / 30.0f, temp_a1);
            var_s0 += 1;
            ohWait(1);
        } while (var_s0 != 0x1E);
        func_80370990_844140(1.0f, temp_a1);
        func_800E61B4_8AB9D4(3, 0);
        func_8036A8E4_83E094(sp24);
    }
    ohWait(0xF);
}

void func_800E2BAC_8A83CC(void) {
}

s32 func_800E2BB4_8A83D4(void) {
    s32 i;
    s32 ret;

    ret = 0;
    for (i = 0; i < 0x3C; i++) {
        if (func_800BFA44_5C8E4(i) != 0) {
            ret++;
        }
    }

    return ret;
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A7360/func_800E2C0C_8A842C.s")
#else
void func_80370780_843F30(int, int);
void func_800E5298_8AAAB8(void);
void func_800E6410_8ABC30(void);
s32 func_800E3ED4_8A96F4(void);

void func_800E2C0C_8A842C(UNK_PTR arg0) {
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s0;
    s32 sp4C;
    s32 temp_v0_2;
    ucolor sp44;
    s32 var_s0_2;
    s32 sp3C;

    func_803717E8_844F98();
    func_80370428_843BD8();
    func_8036EE40_8425F0();
    func_803700A4_843854(0);
    func_80370038_8437E8(0x78, 0x1A);
    func_8036FFE0_843790(0x32, 0x2C);
    temp_v0 = func_8036F78C_842F3C();
    D_80206B20_9CC340 = temp_v0;
    func_8036F684_842E34(temp_v0, 1);
    func_8036F738_842EE8(temp_v0, &sp44);
    func_8036F1F4_8429A4(temp_v0, 0xB8, 0x140);
    func_8036F0DC_84288C(temp_v0, 0);
    sp4C = func_8036AC6C_83E41C(0x68, 0xAD, 0xC0, 0x2F, 0);
    D_80206B1C_9CC33C = sp4C;
    func_8036B870_83F020(sp4C, 1, 0xFFU, 0xFFU, 0xFF, 0xFF);
    func_8036B870_83F020(sp4C, 0, sp44.r, sp44.g, sp44.b, 0xFF);
    func_8036B734_83EEE4(sp4C);
    func_8036D1A4_840954(sp4C, 1);
    if (func_800BF864_5C704() >= 4) {
        func_800BFEBC_5CD5C(8, 1);
    }
    var_s0 = 0;
    for (var_s0 = 0; var_s0 != 0x3BC4; var_s0 += 0xFF) {
        func_800E1B58_8A7378(var_s0 / 60);
        ohWait(1);
    }
    func_800E1B58_8A7378(0xFF);
    func_8037172C_844EDC(1);
    ohWait(0x1E);
    if (func_800AAEE8(8) != 0) {
        func_800AAED0(8);
        if (func_800BFCA0_5CB40(6) == 0) {
            func_800BFEBC_5CD5C(6, 1);
            func_80370C34_8443E4(func_800E3230_8A8A50());
            func_800BFEBC_5CD5C(6, 0);
            func_80370900_8440B0(0, 3);
        } else {
            func_80370C34_8443E4(func_800E3230_8A8A50());
        }
    } else if (func_800AAEE8(0x20) != 0) {
        func_800AAED0(0x20);
        if (func_800BFCA0_5CB40(7) == 0) {
            func_800BFEBC_5CD5C(7, 1);
            func_80370C34_8443E4(func_800E3230_8A8A50());
            func_800BFEBC_5CD5C(7, 0);
            func_80370900_8440B0(0, 2);
        } else {
            func_80370C34_8443E4(func_800E3230_8A8A50());
        }
    } else {
        func_80370C34_8443E4(func_800E3230_8A8A50());
    }
    temp_s0 = func_800BFC5C_5CAFC();
    if (func_800C0290_5D130() != temp_s0) {
        func_800AAED0(0x400);
        func_800BFEBC_5CD5C(0x13, 0);
    }
    if (func_800E2BB4_8A83D4() == 0) {
        func_80370780_843F30(1, 3);
    }
    func_803705A4_843D54();
    func_8036FE54_843604(temp_v0, 1);
    func_8036D1A4_840954(sp4C, 0);
    func_8036D4A0_840C50(0);
    func_8036CB58_840308(sp4C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_800E5298_8AAAB8();
    func_800E6410_8ABC30();

    while (1) {
        sp3C = func_800E3ED4_8A96F4();
        func_80375284_848A34(3);
        func_803700A4_843854(0);
        func_8036D1A4_840954(D_80206B1C_9CC33C, 1);
        func_8036F0A0_842850(temp_v0, 1);
        func_803713C8_844B78(0);
        func_803705F0_843DA0(0);
        func_80370A48_8441F8();
        func_803705A4_843D54();
        func_8037172C_844EDC(0);
        for (var_s0_2 = 0x9F6; var_s0_2 >= 0; var_s0_2 -= 0xFF) {
            temp_lo = var_s0_2 / 10;
            func_800E1B58_8A7378(temp_lo);
            func_8036F198_842948(temp_v0, temp_lo);
            ohWait(1);
        }
        func_800E1B58_8A7378(0);
        func_8036EE40_8425F0();
        func_803705A4_843D54();
        func_800AAF10();
        ohWait(6);
        func_800AADF0(sp3C);
        ohWait(1);
    }
}
#endif

void func_800E307C_8A889C(void) {
    if (!((u32) osGetTime() & 0x28)) {
        func_800BF780_5C620(randT());
    }
}

void func_800E30B8_8A88D8(void) {
    SObj* sobj;

    sobj = func_80371D14_8454C4(NULL, 6, &D_80128F38_8EE758)->data.sobj;
    sobj->sprite.x = 0x28;
    sobj->sprite.y = 0x5C;
    func_8036FFE0_843790(0x28, 0x5C);
    func_80370038_8437E8(0xF0, 0x38);
    func_8036D4A0_840C50(1);
    func_8036EB80_842330(0);
    auSetBGMVolumeSmooth(0, 0x3F80U, 0x3CU);
    func_8036CB58_840308(D_80206B1C_9CC33C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036A8E4_83E094(D_80206B1C_9CC33C);
    func_8036C898_840048(D_80206B1C_9CC33C, "\n\\OThis is... awful!");

    while (1) {
        ohWait(1);
    }
}

void func_800E3190_8A89B0(void) {
    func_800A85E8(func_800E2C0C_8A842C, 6, 0, 0);
    D_80206B30_9CC350 = func_80371D14_8454C4(NULL, 6, &D_8010C590_8D1DB0)->data.sobj;
    D_80206B10_9CC330 = func_80371D14_8454C4(NULL, 6, &D_80190438_955C58)->data.sobj;
    func_800E2848_8A8068();
    func_800E66B8_8ABED8();
    func_8036EB8C_84233C(func_800E235C_8A7B7C);
    func_800E1B58_8A7378(0);
    func_800E1C18_8A7438(0);
}
