#include "common.h"

typedef struct Wonderful {
    char pad[0x48];
    SObj* var_48;
} Wonderful;

typedef struct Wow {
    /* 0x00 */ Wonderful* var_0;
    /* 0x04 */ char pad_04[0x1C];
} Wow; // size: 0x20

typedef struct ItsTheSky {
    GObj* unk0;
    SObj* unk4;
    SObj* unk8;
    SObj* unkC;
    SObj* unk10;
    SObj* unk14;
    SObj* unk18;
    SObj* unk1C;
} ItsTheSky;

extern Sprite D_801FCC58_89A448;
extern Sprite D_801FD088_89A878;
extern Sprite D_801FD9E0_89B1D0;
extern Sprite D_801FDDB8_89B5A8;
extern Sprite D_801FE160_89B950;
extern Sprite D_801FF128_89C918;
extern Sprite D_801FF988_89D178;
extern Sprite D_802004E8_89DCD8;
extern Sprite D_80208900_8A60F0;
extern char D_80208A34_8A6224[];
extern char D_80208A3C_8A622C[];
extern ItsTheSky D_802498F0_8E70E0;
extern s32 D_802498FC_8E70EC;
extern s32 D_80249910_8E7100;
extern s32 D_80249914_8E7104;
extern s32 D_80249918_8E7108;
extern s32 D_8024991C_8E710C;
extern SObj* D_802499A8_8E7198;
extern Wow D_802499C0_8E71B0[];

int func_800BF8BC_5C75C(int);
void func_801DCB58_87A348(int);
void func_801DCC0C_87A3FC(void);
void func_801DCD00_87A4F0(void);
void func_801DCF9C_87A78C(int);
void func_801DD238_87AA28(void*, s32, int);
void func_801DDF28_87B718(s32 arg0);
void func_801DE288_87BA78(int);
void func_801DF2D8_87CAC8(s32);
int func_801E2484_87FC74(int);
int func_801E24D8_87FCC8(int);
void func_8036A8E4_83E094(s32);
void func_803713D4_844B84(int);
void func_803713EC_844B9C(int);
SObj* func_80371DC0_845570(void*, Sprite*);
SObj* func_80371E68_845618(void*, Sprite*);
GObj* func_80371C68_845418(void*, s32 arg1, Sprite* arg2);
void func_80374714_847EC4(int, int);

s32 func_801DCB40_87A330(void) {
    return D_80249914_8E7104;
}

s32 func_801DCB4C_87A33C(void) {
    return D_80249918_8E7108;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DCB58_87A348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DCC0C_87A3FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DCD00_87A4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DCF9C_87A78C.s")

void func_801DD1F0_87A9E0(void) {
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 7; var_s0++) {
        func_801DCF9C_87A78C(var_s0);
    }
    func_801DCD00_87A4F0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD238_87AA28.s")

void func_801DD630_87AE20(s32 arg0, int arg1) {
    s32 i;

    for (i = 0; i < 6; i++, arg0++) {
        func_801DD238_87AA28(&D_802499C0_8E71B0[arg0 % 6], arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD6D0_87AEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD83C_87B02C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD93C_87B12C.s")

void func_801DDA44_87B234(s32 arg0) {
    int i;

    if (arg0) {
        return;
    }

    for (i = 0; i < 6; i += 2) {
        if (arg0) {
            D_802499C0_8E71B0[i].var_0->var_48->sprite.attr &= ~4;
        } else {
            D_802499C0_8E71B0[i].var_0->var_48->sprite.attr |= 4;
        }
        if (arg0) {
            D_802499C0_8E71B0[i + 1].var_0->var_48->sprite.attr &= ~4;
        } else {
            D_802499C0_8E71B0[i + 1].var_0->var_48->sprite.attr |= 4;
        }
    }
}

void func_801DDAD8_87B2C8(s32 arg0) {
    D_802499C0_8E71B0[6].var_0->var_48->sprite.x = 0x19;
    D_802499C0_8E71B0[6].var_0->var_48->sprite.y = 0x41;
}

void func_801DDB08_87B2F8(s32 arg0) {
    if (arg0) {
        return;
    }

    if (arg0) {
        D_802499C0_8E71B0[6].var_0->var_48->sprite.attr &= ~4;
        func_8036D1A4_840954(D_8024991C_8E710C, 0);
    } else {
        D_802499C0_8E71B0[6].var_0->var_48->sprite.attr |= 4;
        func_8036D1A4_840954(D_8024991C_8E710C, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDB80_87B370.s")

void func_801DDD28_87B518(s32 arg0) {
    if (!D_80249910_8E7100) {
        return;
    }

    if (arg0) {
        func_8036D1A4_840954(D_80249910_8E7100, 0);
        func_803713D4_844B84(4);
        func_8036D1A4_840954(D_80249918_8E7108, 0);
    } else {
        func_8036D1A4_840954(D_80249910_8E7100, 1);
        func_8036D1A4_840954(D_80249918_8E7108, 1);
        func_803713EC_844B9C(4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDDA4_87B594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDF28_87B718.s")

void* func_801DDFC4_87B7B4(void) {
    GObj* temp_v0;
    SObj* sobj;
    s32 temp_v0_2;

    temp_v0 = func_80371C68_845418(func_801DDF28_87B718, 6, &D_801FDDB8_89B5A8);
    D_802498F0_8E70E0.unk0 = temp_v0;
    sobj = temp_v0->userData.sobj;
    sobj->sprite.x = 0x65;
    sobj->sprite.y = 0x2F;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_801FDDB8_89B5A8);
    sobj->sprite.x = 0x8F;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801FE160_89B950);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801FE160_89B950);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0x6C;

    sobj = func_80371DC0_845570(sobj, &D_801FD9E0_89B1D0);
    sobj->sprite.x = 0xA1;
    sobj->sprite.y = 0x3C;
    D_802498F0_8E70E0.unk4 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_80208900_8A60F0);
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;
    D_802498F0_8E70E0.unkC = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801FD088_89A878);
    sobj->sprite.x = -2;
    sobj->sprite.y = -2;
    D_802498F0_8E70E0.unk8 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801FF128_89C918);
    sobj->sprite.x = 0xE;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    D_802498F0_8E70E0.unk10 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801FF988_89D178);
    sobj->sprite.x = 0x64;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    D_802498F0_8E70E0.unk14 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_802004E8_89DCD8);
    sobj->sprite.x = 0x64;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_HIDDEN;
    D_802498F0_8E70E0.unk18 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_802004E8_89DCD8);
    sobj->sprite.x = 0xE;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_HIDDEN;
    D_802498F0_8E70E0.unk1C = sobj;

    temp_v0_2 = func_8036AC6C_83E41C(0x100, 0x32, 0x54, 0x70, 0x10);
    func_8036B870_83F020(temp_v0_2, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(temp_v0_2, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(temp_v0_2);
    func_8036D1A4_840954(temp_v0_2, 1);
    D_80249910_8E7100 = temp_v0_2;
    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036CB58_840308(temp_v0_2, 8);
    func_8036B9EC_83F19C(temp_v0_2, 0, 0);
    func_8036C898_840048(temp_v0_2, D_80208A34_8A6224);
    func_8036B9EC_83F19C(temp_v0_2, 0, 0x1C);
    func_8036C898_840048(temp_v0_2, D_80208A3C_8A622C);

    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE288_87BA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE59C_87BD8C.s")

void func_801DE80C_87BFFC(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        D_802498F0_8E70E0.unk0->userData.sobj->sprite.attr &= ~4;
    } else {
        D_802498F0_8E70E0.unk0->userData.sobj->sprite.attr |= 4;
    }
    if (arg0 != 0) {
        func_80374714_847EC4(func_801E2484_87FC74(arg1), D_802498FC_8E70EC + 0x10);
        func_801DD238_87AA28(&D_802498F0_8E70E0, arg1, arg2);
    }
    func_801DE288_87BA78(func_801E24D8_87FCC8(arg1));
}

void func_801DE8AC_87C09C(s32 arg0, int arg1) {
    if (arg0 != 0) {
        D_802498F0_8E70E0.unk0->userData.sobj->sprite.attr &= ~4;
    } else {
        D_802498F0_8E70E0.unk0->userData.sobj->sprite.attr |= 4;
    }
    if (arg0 != 0) {
        func_80374714_847EC4(func_800BF8BC_5C75C(arg1), D_802498FC_8E70EC + 0x10);
        func_801DD238_87AA28(&D_802498F0_8E70E0, -1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE934_87C124.s")

void func_801DEA20_87C210(s32 arg0, int arg1) {
    func_801DD238_87AA28(&D_802498F0_8E70E0, arg0, arg1);
}

s32 func_801DEA50_87C240(void) {
    return D_80249910_8E7100;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DEA5C_87C24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DEAC0_87C2B0.s")

void func_801DEC2C_87C41C(char* arg0) {
    s32 temp_a0;

    func_8036A8E4_83E094(D_80249914_8E7104);
    temp_a0 = D_80249914_8E7104;
    func_8036CB58_840308(temp_a0, 8);
    func_8036B9EC_83F19C(temp_a0, 0, 0);
    func_8036C898_840048(temp_a0, arg0);
}

void func_801DEC84_87C474(void) {
    func_80022374(0, 0x10);
    func_801DDA44_87B234(0);
    func_803700A4_843854(0);
    func_803713EC_844B9C(3);
    func_8036B5F0_83EDA0(D_80249910_8E7100);
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DECCC_87C4BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DEDEC_87C5DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DF0D4_87C8C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DF2D8_87CAC8.s")

void func_801DF938_87D128(void) {
    SObj* temp_v1;

    func_800A85E8(func_801DF2D8_87CAC8, 6, 0, 0);
    temp_v1 = func_80371D14_8454C4(0, 6, &D_801FCC58_89A448)->userData.sobj;
    temp_v1->sprite.width = 0x280;
    temp_v1->sprite.height = 0x1E0;
    temp_v1->sprite.istep = 0;
    D_802499A8_8E7198 = temp_v1;
    func_801DCC0C_87A3FC();
    func_801DCB58_87A348(0);
}
