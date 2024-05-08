#include "common.h"

typedef struct SpriteStruct {
    /* 0x00 */ u32 x;
    /* 0x04 */ u32 y;
    /* 0x08 */ SObj* spriteObj;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Sprite* spriteDef;
} SpriteStruct; // size = 0x18

extern f32 D_8038A3B8_52A7C8;
extern SpriteStruct D_8038812C_52853C[10];
extern GObj* D_80388230_528640;
extern u8 D_8038823C_52864C;
extern u8 D_80388240_528650;
extern u8 D_80388304_528714;
extern SpriteStruct D_80388244_528654[8];
extern s32 D_803AF8C0_54FCD0[8];
extern s32 D_803AF8B8_54FCC8;

void func_8035DB80_4FDF90(GObj*);

void func_8035CBB0_4FCFC0(GObj* arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CBB8_4FCFC8.s")

void func_8035CBDC_4FCFEC(s32 arg0) {
    if (D_8038812C_52853C[arg0].spriteObj != NULL) {
        s32 x = D_8038812C_52853C[arg0].x;
        s32 y = D_8038812C_52853C[arg0].y;
        f32 scale = 1.0f;

        if (D_8038823C_52864C) {
            x += randRange(5) - 2;
            y += randRange(5) - 2;
            scale = 1.2f;
        }
        spMove(&D_8038812C_52853C[arg0].spriteObj->sprite, x, y);
        spScale(&D_8038812C_52853C[arg0].spriteObj->sprite, scale, scale);
    }
}

void func_8035CCA8_4FD0B8(GObj* arg0) {
    func_8035CBDC_4FCFEC(4);
    func_8035CBDC_4FCFEC(5);
}

#ifdef NON_EQUIVALENT
void func_8035CCD4_4FD0E4(GObj* arg0) {
    f32 scale;
    s32 i;

    if (D_8038812C_52853C[6].spriteObj != NULL) {
        scale = 1.0f;

        while (scale > 0.1f) {
            spScale(&D_8038812C_52853C[6].spriteObj->sprite, 1.0f, scale);
            spMove(&D_8038812C_52853C[6].spriteObj->sprite, 
                   D_8038812C_52853C[6].x,
                   D_8038812C_52853C[6].y + (1.0f - scale) * 10.0f);
            ohWait(1);
            scale -= 0.2f;            
        }

        spSetAttribute(&D_8038812C_52853C[6].spriteObj->sprite, SP_HIDDEN);
        for (i = 0; i < 2; i++) {
            ohWait(1);
        }
        spClearAttribute(&D_8038812C_52853C[6].spriteObj->sprite, SP_HIDDEN);
        spScale(&D_8038812C_52853C[6].spriteObj->sprite, 1.0f, 1.0f);
        spMove(&D_8038812C_52853C[6].spriteObj->sprite, 
                D_8038812C_52853C[6].x,
                D_8038812C_52853C[6].y);
    }
    omEndProcess(NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035CCD4_4FD0E4.s")
void func_8035CCD4_4FD0E4(GObj* arg0);
#endif

void func_8035CE74_4FD284(void) {
}

void func_8035CE7C_4FD28C(s32 arg0, f32 arg1, f32 arg2) {
    f32 scale = 1.0f;

    while (scale > 0.1f) {
        spScale(&D_8038812C_52853C[arg0].spriteObj->sprite, scale, scale);
        spMove(&D_8038812C_52853C[arg0].spriteObj->sprite, 
               D_8038812C_52853C[arg0].x + (1.0f - scale) * 10.0f,
               D_8038812C_52853C[arg0].y + (1.0f - scale) * 10.0f);
        ohWait(1);
        scale -= 0.025f;            
    }
    spScale(&D_8038812C_52853C[arg0].spriteObj->sprite, 1.0f, 1.0f);
    spMove(&D_8038812C_52853C[arg0].spriteObj->sprite, 
            D_8038812C_52853C[arg0].x,
            D_8038812C_52853C[arg0].y);
}

void func_8035CFF4_4FD404(GObj* arg0) {
    func_8035CE7C_4FD28C(0, 4.0f, 0.3f);
    omEndProcess(NULL);
}

void func_8035D02C_4FD43C(GObj* arg0) {
    func_8035CE7C_4FD28C(1, 5.0f, 0.5f);
    omEndProcess(NULL);
}

void func_8035D060_4FD470(GObj* arg0) {
    f32 scaleX = 1.0f;
    f32 scaleY = 1.0f;
    f32 scaleXIncr = 0.05f;
    f32 scaleYIncr = 0.05f;

    while (TRUE) {
        if (!D_80388240_528650) {
            break;
        }
        scaleX += scaleXIncr;
        scaleY += scaleYIncr;

        if (scaleX > 1.5f) {
            scaleXIncr = -scaleXIncr;
        }
        if (scaleY > 1.5f) {
            scaleYIncr = -scaleYIncr;
        }
        if (scaleX < 0.8f) {
            scaleXIncr = -scaleXIncr;
        }
        if (scaleY < 0.8f) {
            scaleYIncr = -scaleYIncr;
        }
        spScale(&D_8038812C_52853C[2].spriteObj->sprite, scaleX, scaleY);
        ohWait(1);
    }
    spScale(&D_8038812C_52853C[2].spriteObj->sprite, 1.0f, 1.0f);
    omEndProcess(0);
}

// needs data migration ??
#if 0


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

void func_8035D650_4FDA60(s32 arg0) {
    D_8038823C_52864C = arg0;
}

extern SpriteStruct D_80388244_528654[];

void func_8035D65C_4FDA6C(s32 arg0, s32 arg1) {
    D_8038812C_52853C[arg0].x += D_80388244_528654[arg0].unk_0C ? arg1 : 0;
    D_8038812C_52853C[arg0].y += D_80388244_528654[arg0].unk_0C ? 0 : arg1;
    spMove(&D_8038812C_52853C[arg0].spriteObj->sprite, D_8038812C_52853C[arg0].x, D_8038812C_52853C[arg0].y);
}

void func_8035D6E0_4FDAF0(GObj* arg0) {
    s32 i;
    s32 s3;

    while (TRUE) {
        s3 = FALSE;
        if (!D_80388304_528714) {
            break;
        }

        for (i = 0; i < 8; i++) {
            if (D_80388244_528654[i].spriteObj == NULL && D_8038812C_52853C[i].spriteObj != NULL && D_803AF8C0_54FCD0[i] < 8) {
                s3 = TRUE;
                D_803AF8C0_54FCD0[i]++;
                func_8035D65C_4FDA6C(i, 6);
            }
        }

        if (s3) {
            if (D_803AF8B8_54FCC8 < 8) {
                D_803AF8B8_54FCC8++;
            }
            ohWait(1);
            continue;
        }

        for (i = 0; i < 8; i++) {
            if (D_80388244_528654[i].spriteObj == NULL && D_8038812C_52853C[i].spriteObj != NULL) {
                spSetAttribute(&D_8038812C_52853C[i].spriteObj->sprite, SP_HIDDEN);
            }
        }
        omCreateProcess(D_80388230_528640, func_8035DB80_4FDF90, 0, 1);
        break;
    }
    omEndProcess(NULL);
}

void func_8035D868_4FDC78(GObj* arg0) {
    s32 i;
    s32 s3;

    for (i = 0; i < 8; i++) {
        if (D_80388244_528654[i].spriteObj == NULL && D_8038812C_52853C[i].spriteObj != NULL) {
            spClearAttribute(&D_8038812C_52853C[i].spriteObj->sprite, SP_HIDDEN);
        }
    }

    while (TRUE) {
        s3 = FALSE;
        if (D_80388304_528714 == 1) {
            break;
        }

        for (i = 0; i < 8; i++) {
            if (D_80388244_528654[i].spriteObj == NULL && D_8038812C_52853C[i].spriteObj != NULL) {
                if (D_80388244_528654[i].unk_10 <= 8 - D_803AF8B8_54FCC8) {
                    if (D_803AF8C0_54FCD0[i] > 0) {
                        s3 = TRUE;
                        D_803AF8C0_54FCD0[i]--;
                        func_8035D65C_4FDA6C(i, -6);
                    }
                } else {
                    s3 = TRUE;
                }
            }
        }

        if (s3) {
            if (D_803AF8B8_54FCC8 > 0) {
                D_803AF8B8_54FCC8--;
            }
            ohWait(1);
            continue;
        }
        break;
    }
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035D9F4_4FDE04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DB80_4FDF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DD14_4FE124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DDA0_4FE1B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DDC8_4FE1D8.s")

void func_8035DDE8_4FE1F8(s32 arg0) {
    if (arg0 == 162) {
        omCreateProcess(D_80388230_528640, func_8035D02C_4FD43C, 0, 1);
    } else if (arg0 == 163) {
        omCreateProcess(D_80388230_528640, func_8035CFF4_4FD404, 0, 1);
    } else if (arg0 == 161) {
        if (D_80388240_528650 == 0) {
            omCreateProcess(D_80388230_528640, func_8035D060_4FD470, 0, 1);
            D_80388240_528650 = 1;
        }
    } else {
        D_80388240_528650 = 0;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DEA0_4FE2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DED4_4FE2E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FCFC0/func_8035DEF8_4FE308.s")
