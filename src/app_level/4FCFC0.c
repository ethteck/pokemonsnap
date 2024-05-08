#include "common.h"

typedef struct SpriteStruct {
    /* 0x00 */ u32 x;
    /* 0x04 */ u32 y;
    /* 0x08 */ SObj* spriteObj;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Sprite* spriteDef;
} SpriteStruct; // size = 0x18

// data
// TODO make sprite assets
extern Sprite D_80383B48_523F58;
extern Sprite D_803841C8_5245D8;
extern Sprite D_80384E68_525278;
extern Sprite D_80385B08_525F18;
extern Sprite D_803867A8_526BB8;
extern Sprite D_80387448_527858;
extern Sprite D_803880E8_5284F8;
// we have to make this small array because of alignment
u32 EndOfSpriteData[] = {
    0x803AF790,
    0x00000000,
    0x00000000
};

SpriteStruct D_8038812C_52853C[] = {
    { 148, 104, NULL, 0, 0, NULL},
    { 124,  80, NULL, 0, 0, NULL},
    { 148,  80, NULL, 0, 0, NULL},
    { 172,  80, NULL, 0, 0, NULL},
    { 124, 104, NULL, 0, 0, NULL},
    { 172, 104, NULL, 0, 0, NULL},
    { 124, 128, NULL, 0, 0, NULL},
    { 148, 128, NULL, 0, 0, NULL},
    { 172, 128, NULL, 0, 0, NULL},
};
s32 D_80388204_528614[] = { 163, 162, 161 };
SObj* D_80388210_528620[] = { NULL, NULL, NULL };
u32 D_8038821C_52862C = 0;
u8 D_80388220_528630 = 0;
SObj* D_80388224_528634[] = { NULL, NULL, NULL };
GObj* D_80388230_528640 = NULL;
s32 D_80388234_528644 = 1;
s32 D_80388238_528648 = 3;
u8 D_8038823C_52864C = 0;
u8 D_80388240_528650 = 0;
SpriteStruct D_80388244_528654[] = {
    { 210, 189, NULL, 0, 2, &D_80387448_527858 },
    { 182, 185, NULL, 0, 0, &D_803867A8_526BB8 },
    { 238, 185, NULL, 0, 4, &D_803880E8_5284F8 },
    { 268, 189, NULL, 1, 6, &D_80383B48_523F58 },
    { 268, 155, NULL, 1, 8, &D_80384E68_525278 },
    { 316, 155, (SObj*)1, 1, 4, &D_80384E68_525278 },
    { 238, 233, (SObj*)1, 0, 0, &D_80385B08_525F18 },
    { 316, 189, (SObj*)1, 1, 2, &D_803841C8_5245D8 },
};
u8 D_80388304_528714 = 0;

// bss
extern s32 D_803AF8B8_54FCC8;
extern s32 D_803AF8BC_54FCCC;
extern s32 D_803AF8C0_54FCD0[8];

extern s32 D_80382CF4_523104;
u32 func_80357048_4F7458(void);
void func_8035DB80_4FDF90(GObj*);

void func_8035CBB0_4FCFC0(GObj* arg0) {

}

void func_8035CBB8_4FCFC8(Sprite* arg0, Sprite* arg1) {
    arg0->width = arg1->width;
    arg0->height = arg1->height;
    arg0->bitmap = arg1->bitmap;
    arg0->rsp_dl = arg1->rsp_dl;
}

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

void func_8035CCD4_4FD0E4(GObj* arg0) {
    f32 scale;
    s32 i;
    SpriteStruct* spr = &D_8038812C_52853C[6];

    if (spr->spriteObj != NULL) {
        scale = 1.0f;

        while (scale > 0.1f) {
            spScale(&spr->spriteObj->sprite, 1.0f, scale);
            spMove(&spr->spriteObj->sprite, 
                   spr->x,
                   spr->y + (1.0f - scale) * 10.0f);
            ohWait(1);
            scale -= 0.2f;            
        }

        spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
        for (i = 0; i < 2; i++) {
            ohWait(1);
        }
        spClearAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
        spScale(&spr->spriteObj->sprite, 1.0f, 1.0f);
        spMove(&spr->spriteObj->sprite, 
                spr->x,
                spr->y);
    }
    omEndProcess(NULL);
}

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

void func_8035D1A0_4FD5B0(void) {
    GObj* sp2C;
    s32 temp_v0_8;
    s32 i;
    u32 sp20;
    SpriteStruct* spr;
    SpriteStruct* sprDef;
    s32 zero = 0;

    sp20 = func_80357048_4F7458();
    D_80388220_528630 = 0;
    D_8038821C_52862C = 0;
    D_80388238_528648 = 0;

    if (sp20 & 1) {
        D_80388220_528630 |= 1;
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

    spr = &D_8038812C_52853C[3];
    sprDef = &D_80388244_528654[3];
    spr->spriteObj = omGObjAddSprite(sp2C, sprDef->spriteDef);
    spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
    spr->x = sprDef->x; spr->y = sprDef->y;

    if (sp20 & 0x20) {
        spr = &D_8038812C_52853C[4];
        sprDef = &D_80388244_528654[4];
        spr->spriteObj = omGObjAddSprite(sp2C, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;

        spr = &D_8038812C_52853C[5];
        sprDef = &D_80388244_528654[5];
        spr->spriteObj = omGObjAddSprite(sp2C, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
        spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
    }
    
    spr = &D_8038812C_52853C[6];
    sprDef = &D_80388244_528654[6];
    spr->spriteObj = omGObjAddSprite(sp2C, sprDef->spriteDef);
    spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
    spr->x = sprDef->x; spr->y = sprDef->y;
    spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);

    if (sp20 & 0x1000) {
        spr = &D_8038812C_52853C[7];
        sprDef = &D_80388244_528654[7];
        spr->spriteObj = omGObjAddSprite(sp2C, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
        spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
    }

    if (D_80388238_528648 >= 3) {
        spr = &D_8038812C_52853C[2];
        sprDef = &D_80388244_528654[2];
        spr->spriteObj = D_80388224_528634[2] = omGObjAddSprite(sp2C, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
    }
    if (D_80388238_528648 >= 1) {
        spr = &D_8038812C_52853C[0];
        sprDef = &D_80388244_528654[0];
        spr->spriteObj = D_80388224_528634[0] = omGObjAddSprite(sp2C, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
    }
    if (D_80388238_528648 >= 2) {
        spr = &D_8038812C_52853C[1];
        sprDef = &D_80388244_528654[1];
        spr->spriteObj = D_80388224_528634[1] = omGObjAddSprite(sp2C, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
    }

    D_80388210_528620[0] = D_80388224_528634[0];
    D_80388210_528620[1] = D_80388224_528634[1];
    D_80388210_528620[2] = D_80388224_528634[2];

    omCreateProcess(sp2C, func_8035CCA8_4FD0B8, 1, 1);

    for (i = 0; i < 8; i++) { D_803AF8C0_54FCD0[i] = 0; }
}

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

void func_8035D9F4_4FDE04(GObj* arg0) {
    s32 i;
    s32 s3;

    while (TRUE) {
        s3 = FALSE;
        if (D_80388304_528714 == 1) {
            break;
        }

        for (i = 0; i < 8; i++) {
            if (D_80388244_528654[i].spriteObj != NULL && D_8038812C_52853C[i].spriteObj != NULL && D_803AF8C0_54FCD0[i] >= 0) {
                s3 = TRUE;
                D_803AF8C0_54FCD0[i]--;
                func_8035D65C_4FDA6C(i, 6);
            }
        }

        if (s3) {
            if (D_803AF8BC_54FCCC > 0) {
                D_803AF8BC_54FCCC--;
            }
            ohWait(1);
            continue;
        }

        for (i = 0; i < 8; i++) {
            if (D_80388244_528654[i].spriteObj != NULL && D_8038812C_52853C[i].spriteObj != NULL) {
                spSetAttribute(&D_8038812C_52853C[i].spriteObj->sprite, SP_HIDDEN);
            }
        }
        omCreateProcess(D_80388230_528640, func_8035D868_4FDC78, 0, 1);
        break;
    }
    omEndProcess(NULL);
}

void func_8035DB80_4FDF90(GObj* arg0) {
    s32 i;
    s32 s3;

    for (i = 0; i < 8; i++) {
        if (D_80388244_528654[i].spriteObj != NULL && D_8038812C_52853C[i].spriteObj != NULL) {
            spClearAttribute(&D_8038812C_52853C[i].spriteObj->sprite, SP_HIDDEN);
        }
    }

    while (TRUE) {
        s3 = FALSE;
        if (D_80388304_528714 == 0) {
            break;
        }

        for (i = 0; i < 8; i++) {
            if (D_80388244_528654[i].spriteObj != NULL && D_8038812C_52853C[i].spriteObj != NULL) {
                if (D_80388244_528654[i].unk_10 <= D_803AF8BC_54FCCC) {
                    if (D_803AF8C0_54FCD0[i] < 8) {
                        s3 = TRUE;
                        D_803AF8C0_54FCD0[i]++;
                        func_8035D65C_4FDA6C(i, -6);
                    }
                } else {
                    s3 = TRUE;
                }
            }
        }

        if (s3) {
            if (D_803AF8BC_54FCCC < 8) {
                D_803AF8BC_54FCCC++;
            }
            ohWait(1);
            continue;
        }
        break;
    }
    omEndProcess(NULL);
}

void func_8035DD14_4FE124(s32 arg0) {
    if (arg0 == 0 && D_80388304_528714 != 0) {
        omCreateProcess(D_80388230_528640, func_8035D9F4_4FDE04, 0, 1);
        D_80388304_528714 = 0;
        return;
    }
    if (arg0 == 1 && D_80388304_528714 != 1) {
        omCreateProcess(D_80388230_528640, func_8035D6E0_4FDAF0, 0, 1);
        D_80388304_528714 = 1;
    }
}

void func_8035DDA0_4FE1B0(void) {
    D_80388230_528640->flags &= ~GOBJ_FLAG_HIDDEN;
    D_80388234_528644 = 1;
}

void func_8035DDC8_4FE1D8(void) {
    D_80388230_528640->flags |= GOBJ_FLAG_HIDDEN;
    D_80388234_528644 = 0;
}

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

void func_8035DEA0_4FE2B0(void) {
    omCreateProcess(D_80388230_528640, func_8035CCD4_4FD0E4, 0, 1);
}

void func_8035DED4_4FE2E4(void) {
    ohPauseObjectProcesses(D_80388230_528640);
}

void func_8035DEF8_4FE308(void) {
    ohResumeObjectProcesses(D_80388230_528640);
}
