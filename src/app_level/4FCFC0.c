#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CBB0_4FCFC0.s")
void func_8035CBB0_4FCFC0(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CBB8_4FCFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CBDC_4FCFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CCA8_4FD0B8.s")
void func_8035CCA8_4FD0B8(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CCD4_4FD0E4.s")

void func_8035CE74_4FD284(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CE7C_4FD28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CFF4_4FD404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D02C_4FD43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D060_4FD470.s")

// needs data migration ??
#if 0
typedef struct SpriteStruct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ SObj* spriteObj;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Sprite* spriteDef;
} SpriteStruct; // size = 0x18

u32 func_80357048_4F7458(void);

extern u8 D_80388220_528630;
extern u32 D_8038821C_52862C;
extern s32 D_80388238_528648;
extern s32 D_80388204_528614[];
extern s32 D_80382CF4_523104;
extern GObj* D_80388230_528640;
extern SObj* D_8038817C_52858C;
extern Sprite* D_803882A0_5286B0;
extern s32 D_8038828C_52869C;
extern s32 D_80388290_5286A0;
extern s32 D_80388178_528588;
extern Sprite* D_803882B8_5286C8;
extern SObj* D_80388194_5285A4;
extern s32 D_803882A4_5286B4;
extern s32 D_803882A8_5286B8;
extern s32 D_8038818C_52859C;
extern s32 D_80388190_5285A0;
extern Sprite* D_803882D0_5286E0;
extern SObj* D_803881AC_5285BC;
extern s32 D_803882BC_5286CC;
extern s32 D_803882C0_5286D0;
extern s32 D_803881A4_5285B4;
extern s32 D_803881A8_5285B8;
extern Sprite* D_803882E8_5286F8;
extern SObj* D_803881C4_5285D4;
extern s32 D_803882D4_5286E4;
extern s32 D_803882D8_5286E8;
extern s32 D_803881BC_5285CC;
extern s32 D_803881C0_5285D0;
extern Sprite* D_80388300_528710;
extern SObj* D_803881DC_5285EC;
extern s32 D_803882EC_5286FC;
extern s32 D_803882F0_528700;
extern s32 D_803881D8_5285E8;
extern Sprite* D_80388288_528698;
extern SObj* D_8038822C_52863C;
extern SObj* D_80388164_528574;
extern s32 D_80388274_528684;
extern s32 D_80388278_528688;
extern s32 D_8038815C_52856C;
extern s32 D_80388160_528570;
extern Sprite* D_80388258_528668;
extern SObj* D_80388224_528634;
extern SObj* D_80388134_528544;
extern s32 D_80388244_528654;
extern s32 D_80388248_528658;
extern s32 D_8038812C_52853C;
extern s32 D_80388130_528540;
extern Sprite* D_80388270_528680;
extern SObj* D_80388228_528638;
extern SObj* D_8038814C_52855C;
extern s32 D_8038825C_52866C;
extern s32 D_80388260_528670;
extern s32 D_80388148_528558;
extern SObj* D_80388210_528620[3];
extern s32 D_803AF8C0_54FCD0[16];

void func_8035D1A0_4FD5B0(void) {
    GObj* sp2C;
    s32 temp_v0_8;
    s32 i;
    u32 sp20;

    sp20 = func_80357048_4F7458();
    D_80388220_528630 = 0;
    D_8038821C_52862C = 0;
    D_80388238_528648 = 0;
    if (sp20 & 1) {
        D_80388220_528630 = 1;
    }
    if (sp20 & 2) {
        D_80388220_528630 |= 2;
    }
    if (sp20 & 4) {
        D_80388220_528630 |= 4;
    }
    if (D_80388220_528630 & 1) {
        D_80388238_528648 = 1;
    }
    if (D_80388220_528630 & 2) {
        D_80388238_528648 = 2;
    }
    if (D_80388220_528630 & 4) {
        D_80388238_528648 = 3;
    }
    if (D_80388238_528648 > 0) {
        D_80382CF4_523104 = D_80388204_528614[D_8038821C_52862C];
    } else {
        D_80382CF4_523104 = -1;
    }
    sp2C = omAddGObj(26, func_8035CBB0_4FCFC0, 0, 0x80000000);
    omLinkGObjDL(sp2C, &renDrawSprite, 1, 0x80000000, -1);
    D_80388230_528640 = sp2C;

    D_8038817C_52858C = omGObjAddSprite(sp2C, D_803882A0_5286B0);
    spMove(&D_8038817C_52858C->sprite, D_8038828C_52869C, D_80388290_5286A0);
    D_80388178_528588 = D_80388290_5286A0;
    D_80388178_528588 = D_8038828C_52869C;

    if (sp20 & 0x20) {
        D_80388194_5285A4 = omGObjAddSprite(sp2C, D_803882B8_5286C8);
        spMove(&D_80388194_5285A4->sprite, D_803882A4_5286B4, D_803882A8_5286B8);
        D_8038818C_52859C = D_803882A4_5286B4;
        D_80388190_5285A0 = D_803882A8_5286B8;

        D_803881AC_5285BC = omGObjAddSprite(sp2C, D_803882D0_5286E0);
        spMove(&D_803881AC_5285BC->sprite, D_803882BC_5286CC, D_803882C0_5286D0);
        D_803881A4_5285B4 = D_803882BC_5286CC;
        D_803881A8_5285B8 = D_803882C0_5286D0;
        spSetAttribute(&D_803881AC_5285BC->sprite, SP_HIDDEN);
    }

    D_803881C4_5285D4 = omGObjAddSprite(sp2C, D_803882E8_5286F8);
    spMove(&D_803881C4_5285D4->sprite, D_803882D4_5286E4, D_803882D8_5286E8);
    D_803881BC_5285CC = D_803882D4_5286E4;
    D_803881C0_5285D0 = D_803882D8_5286E8;
    spSetAttribute(&D_803881C4_5285D4->sprite, SP_HIDDEN);

    if (sp20 & 0x1000) {
        D_803881DC_5285EC = omGObjAddSprite(sp2C, D_80388300_528710);
        spMove(&D_803881DC_5285EC->sprite, D_803882EC_5286FC, D_803882F0_528700);
        D_803881D8_5285E8 = D_803882EC_5286FC;
        D_803881D8_5285E8 = D_803882F0_528700;
        spSetAttribute(&D_803881DC_5285EC->sprite, SP_HIDDEN);
    }
    temp_v0_8 = D_80388238_528648;
    if (temp_v0_8 >= 3) {
        D_80388164_528574 = D_8038822C_52863C = omGObjAddSprite(sp2C, D_80388288_528698);
        spMove(&D_80388164_528574->sprite, D_80388274_528684, D_80388278_528688);
        D_8038815C_52856C = D_80388274_528684;
        D_80388160_528570 = D_80388278_528688;
    }
    if (temp_v0_8 >= 1) {
        D_80388134_528544 = D_80388224_528634 = omGObjAddSprite(sp2C, D_80388258_528668);
        spMove(&D_80388134_528544->sprite, D_80388244_528654, D_80388248_528658);
        D_8038812C_52853C = D_80388244_528654;
        D_80388130_528540 = D_80388248_528658;
    }
    if (temp_v0_8 >= 2) {
        D_8038814C_52855C = D_80388228_528638 = omGObjAddSprite(sp2C, D_80388270_528680);
        spMove(&D_8038814C_52855C->sprite, D_8038825C_52866C, D_80388260_528670);
        D_80388148_528558 = D_8038825C_52866C;
        D_80388148_528558 = D_80388260_528670;
    }

    D_80388210_528620[0] = D_80388224_528634;
    D_80388210_528620[1] = D_80388228_528638;
    D_80388210_528620[2] = D_8038822C_52863C;

    omCreateProcess(sp2C, func_8035CCA8_4FD0B8, 1, 1);

    for (i = 0; i < ARRAY_COUNT(D_803AF8C0_54FCD0); i++) {
        D_803AF8C0_54FCD0[i] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D1A0_4FD5B0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D650_4FDA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D65C_4FDA6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D6E0_4FDAF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D868_4FDC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D9F4_4FDE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DB80_4FDF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DD14_4FE124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DDA0_4FE1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DDC8_4FE1D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DDE8_4FE1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DEA0_4FE2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DED4_4FE2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DEF8_4FE308.s")
