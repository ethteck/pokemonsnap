#include "common.h"

typedef struct SiennaHaddock {
    char pad[0x48];
    SObj* var_48;
} SiennaHaddock;

typedef struct PurpleMackerel {
    /* 0x00 */ SiennaHaddock* var_0;
    /* 0x04 */ char pad_04[0x1C];
} PurpleMackerel; // size: 0x20

typedef struct TealFlounder {
    GObj* unk0;
    SObj* unk4;
    SObj* unk8;
    SObj* unkC;
    SObj* unk10;
    SObj* unk14;
    SObj* unk18;
    SObj* unk1C;
} TealFlounder;

extern Sprite D_camera_check_801FCC58;
extern Sprite D_camera_check_801FD088;
extern Sprite D_camera_check_801FD9E0;
extern Sprite D_camera_check_801FDDB8;
extern Sprite D_camera_check_801FE160;
extern Sprite D_camera_check_801FF128;
extern Sprite D_camera_check_801FF988;
extern Sprite D_camera_check_802004E8;
extern Sprite D_camera_check_80208900;
extern char D_camera_check_80208A34[];
extern char D_camera_check_80208A3C[];
extern TealFlounder D_camera_check_802498F0;
extern s32 D_camera_check_802498FC;
extern s32 D_camera_check_80249910;
extern s32 D_camera_check_80249914;
extern s32 D_camera_check_80249918;
extern s32 D_camera_check_8024991C;
extern SObj* D_camera_check_802499A8;
extern PurpleMackerel D_camera_check_802499C0[];

int func_800BF8BC_5C75C(int);
void func_camera_check_801DCB58(int);
void func_camera_check_801DCC0C(void);
void func_camera_check_801DCD00(void);
void func_camera_check_801DCF9C(int);
void func_camera_check_801DD238(void*, s32, int);
void func_camera_check_801DDF28(s32 arg0);
void func_camera_check_801DE288(int);
void func_camera_check_801DF2D8(UNK_PTR);
int func_camera_check_801E2484(int);
int func_camera_check_801E24D8(int);
void func_803713D4_844B84(int);
void func_803713EC_844B9C(int);
void func_80374714_847EC4(int, int);

s32 func_camera_check_801DCB40(void) {
    return D_camera_check_80249914;
}

s32 func_camera_check_801DCB4C(void) {
    return D_camera_check_80249918;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DCB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DCC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DCD00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DCF9C.s")

void func_camera_check_801DD1F0(void) {
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 7; var_s0++) {
        func_camera_check_801DCF9C(var_s0);
    }
    func_camera_check_801DCD00();
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD238.s")

void func_camera_check_801DD630(s32 arg0, int arg1) {
    s32 i;

    for (i = 0; i < 6; i++, arg0++) {
        func_camera_check_801DD238(&D_camera_check_802499C0[arg0 % 6], arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD83C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DD93C.s")

void func_camera_check_801DDA44(s32 arg0) {
    int i;

    if (arg0) {
        return;
    }

    for (i = 0; i < 6; i += 2) {
        if (arg0) {
            D_camera_check_802499C0[i].var_0->var_48->sprite.attr &= ~4;
        } else {
            D_camera_check_802499C0[i].var_0->var_48->sprite.attr |= 4;
        }
        if (arg0) {
            D_camera_check_802499C0[i + 1].var_0->var_48->sprite.attr &= ~4;
        } else {
            D_camera_check_802499C0[i + 1].var_0->var_48->sprite.attr |= 4;
        }
    }
}

void func_camera_check_801DDAD8(s32 arg0) {
    D_camera_check_802499C0[6].var_0->var_48->sprite.x = 0x19;
    D_camera_check_802499C0[6].var_0->var_48->sprite.y = 0x41;
}

void func_camera_check_801DDB08(s32 arg0) {
    if (arg0) {
        return;
    }

    if (arg0) {
        D_camera_check_802499C0[6].var_0->var_48->sprite.attr &= ~4;
        func_8036D1A4_840954(D_camera_check_8024991C, 0);
    } else {
        D_camera_check_802499C0[6].var_0->var_48->sprite.attr |= 4;
        func_8036D1A4_840954(D_camera_check_8024991C, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DDB80.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DDDA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DDF28.s")

void* func_camera_check_801DDFC4(void) {
    GObj* temp_v0;
    SObj* sobj;
    s32 temp_v0_2;

    temp_v0 = func_80371C68_845418(func_camera_check_801DDF28, 6, &D_camera_check_801FDDB8);
    D_camera_check_802498F0.unk0 = temp_v0;
    sobj = temp_v0->data.sobj;
    sobj->sprite.x = 0x65;
    sobj->sprite.y = 0x2F;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_camera_check_801FDDB8);
    sobj->sprite.x = 0x8F;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FE160);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FE160);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0x6C;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD9E0);
    sobj->sprite.x = 0xA1;
    sobj->sprite.y = 0x3C;
    D_camera_check_802498F0.unk4 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_80208900);
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;
    D_camera_check_802498F0.unkC = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FD088);
    sobj->sprite.x = -2;
    sobj->sprite.y = -2;
    D_camera_check_802498F0.unk8 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FF128);
    sobj->sprite.x = 0xE;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    D_camera_check_802498F0.unk10 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_801FF988);
    sobj->sprite.x = 0x64;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    D_camera_check_802498F0.unk14 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_802004E8);
    sobj->sprite.x = 0x64;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_HIDDEN;
    D_camera_check_802498F0.unk18 = sobj;

    sobj = func_80371DC0_845570(sobj, &D_camera_check_802004E8);
    sobj->sprite.x = 0xE;
    sobj->sprite.y = 0x48;
    sobj->sprite.attr |= SP_HIDDEN;
    D_camera_check_802498F0.unk1C = sobj;

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
    func_8036C898_840048(temp_v0_2, D_camera_check_80208A34);
    func_8036B9EC_83F19C(temp_v0_2, 0, 0x1C);
    func_8036C898_840048(temp_v0_2, D_camera_check_80208A3C);

    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DE288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DE59C.s")

void func_camera_check_801DE80C(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        D_camera_check_802498F0.unk0->data.sobj->sprite.attr &= ~4;
    } else {
        D_camera_check_802498F0.unk0->data.sobj->sprite.attr |= 4;
    }
    if (arg0 != 0) {
        func_80374714_847EC4(func_camera_check_801E2484(arg1), D_camera_check_802498FC + 0x10);
        func_camera_check_801DD238(&D_camera_check_802498F0, arg1, arg2);
    }
    func_camera_check_801DE288(func_camera_check_801E24D8(arg1));
}

void func_camera_check_801DE8AC(s32 arg0, int arg1) {
    if (arg0 != 0) {
        D_camera_check_802498F0.unk0->data.sobj->sprite.attr &= ~4;
    } else {
        D_camera_check_802498F0.unk0->data.sobj->sprite.attr |= 4;
    }
    if (arg0 != 0) {
        func_80374714_847EC4(func_800BF8BC_5C75C(arg1), D_camera_check_802498FC + 0x10);
        func_camera_check_801DD238(&D_camera_check_802498F0, -1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DE934.s")

void func_camera_check_801DEA20(s32 arg0, int arg1) {
    func_camera_check_801DD238(&D_camera_check_802498F0, arg0, arg1);
}

s32 func_camera_check_801DEA50(void) {
    return D_camera_check_80249910;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DEA5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DEAC0.s")

void func_camera_check_801DEC2C(char* arg0) {
    s32 temp_a0;

    func_8036A8E4_83E094(D_camera_check_80249914);
    temp_a0 = D_camera_check_80249914;
    func_8036CB58_840308(temp_a0, 8);
    func_8036B9EC_83F19C(temp_a0, 0, 0);
    func_8036C898_840048(temp_a0, arg0);
}

void func_camera_check_801DEC84(void) {
    func_80022374(0, 0x10);
    func_camera_check_801DDA44(0);
    func_803700A4_843854(0);
    func_803713EC_844B9C(3);
    func_8036B5F0_83EDA0(D_camera_check_80249910);
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DECCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DEDEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DF0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87A330/func_camera_check_801DF2D8.s")

void func_camera_check_801DF938(void) {
    SObj* temp_v1;

    func_800A85E8(func_camera_check_801DF2D8, 6, 0, 0);
    temp_v1 = func_80371D14_8454C4(0, 6, &D_camera_check_801FCC58)->data.sobj;
    temp_v1->sprite.width = 0x280;
    temp_v1->sprite.height = 0x1E0;
    temp_v1->sprite.istep = 0;
    D_camera_check_802499A8 = temp_v1;
    func_camera_check_801DCC0C();
    func_camera_check_801DCB58(0);
}
