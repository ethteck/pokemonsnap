#include "common.h"

typedef struct HelloThere {
    char pad[0x10];
    s16 var_10;
    s16 var_12;
} HelloThere;

typedef struct Wonderful {
    char pad[0x48];
    HelloThere* var_48;
} Wonderful;

typedef struct Wow {
    char pad[0xC0];
    Wonderful* var_C0;
} Wow;

extern Sprite D_801FCC58_89A448;
extern char D_802498F0_8E70E0;
extern s32 D_80249910_8E7100;
extern s32 D_80249914_8E7104;
extern s32 D_80249918_8E7108;
extern SObj* D_802499A8_8E7198;
extern Wow D_802499C0_8E71B0;

void func_801DCB58_87A348(int);
void func_801DCC0C_87A3FC(void);
void func_801DCD00_87A4F0(void);
void func_801DCF9C_87A78C(int);
void func_801DD238_87AA28(void*, s32, int);
void func_801DDA44_87B234(int);
void func_801DF2D8_87CAC8(s32);
void func_8036A8E4_83E094(s32);
void func_803713EC_844B9C(int);

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

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD630_87AE20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD6D0_87AEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD83C_87B02C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DD93C_87B12C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDA44_87B234.s")

void func_801DDAD8_87B2C8(s32 arg0) {
    D_802499C0_8E71B0.var_C0->var_48->var_10 = 0x19;
    D_802499C0_8E71B0.var_C0->var_48->var_12 = 0x41;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDB08_87B2F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDB80_87B370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDD28_87B518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDDA4_87B594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDF28_87B718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DDFC4_87B7B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE288_87BA78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE59C_87BD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE80C_87BFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87A330/func_801DE8AC_87C09C.s")

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
