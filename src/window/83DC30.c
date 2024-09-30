#include "common.h"
#include "window.h"

void func_8036A480_83DC30(void) {
    D_8037EA80_852230 = 0;
    D_8037EA84_852234 = 0;
    D_8037EA88_852238 = 0;
    D_8037EA8C_85223C = NULL;
    D_8037EA90_852240 = NULL;
}

void func_8036A4AC_83DC5C(UnkSnowHerring* arg0) {
    if (D_8037EA8C_85223C == NULL) {
        D_8037EA8C_85223C = arg0;
        D_8037EA90_852240 = arg0;
        arg0->unk_3C = NULL;
        arg0->unk_40 = 0;
    } else {
        D_8037EA8C_85223C->unk_40 = arg0;
        arg0->unk_3C = (void*) D_8037EA8C_85223C;
        arg0->unk_40 = 0;
        D_8037EA8C_85223C = arg0;
    }
}

void func_8036A4F4_83DCA4(UnkSnowHerring* arg0) {
    if (D_8037EA90_852240 == NULL) {
        D_8037EA8C_85223C = arg0;
        D_8037EA90_852240 = arg0;
        arg0->unk_3C = NULL;
        arg0->unk_40 = NULL;
    } else {
        D_8037EA90_852240->unk_3C = arg0;
        arg0->unk_3C = NULL;
        arg0->unk_40 = D_8037EA90_852240;
        D_8037EA90_852240 = arg0;
    }
}

void func_8036A53C_83DCEC(UnkSnowHerring* arg0) {
    if (!arg0->unk_3C && !arg0->unk_40) {
        D_8037EA8C_85223C = NULL;
        D_8037EA90_852240 = NULL;
    } else if (!arg0->unk_3C) {
        D_8037EA90_852240 = arg0->unk_40;
        arg0->unk_40->unk_3C = NULL;
    } else if (!arg0->unk_40) {
        arg0->unk_3C->unk_40 = NULL;
        D_8037EA8C_85223C = arg0->unk_3C;
    } else {
        arg0->unk_3C->unk_40 = arg0->unk_40;
        arg0->unk_40->unk_3C = arg0->unk_3C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036A5B8_83DD68.s")

void func_8036A8E4_83E094(UnkSnowHerring* arg0) {
    func_8036A5B8_83DD68(arg0, 0, 0, arg0->unk_10, arg0->unk_14, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    arg0->unk_120 = 0;
    arg0->unk_124 = 0;
    arg0->unk_118 = 0;
    func_8036EEB0_842660(arg0->unk_0, arg0->unk_4, arg0->unk_0 + arg0->unk_10, arg0->unk_4 + arg0->unk_14);
}

void func_8036A968_83E118(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8036A5B8_83DD68(arg0, arg1, arg2, arg3, arg4, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036A9AC_83E15C.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036AC6C_83E41C.s")

UnkSnowHerring* func_8036AC6C_83E41C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8* temp_a2_2;
    s32 tmp;
    s32 sp9C;
    s32 sp98;
    s32 i;
    s32 var0;
    s32 sp24;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    u32 sp20;
    s32 sp78;    
    s32 new_var;
    Bitmap *new_var3;
    u8* temp_a1_2;    
    u64* ptr;
    s32 new_var2;
    UnkSnowHerring* sp60;
    s32 sp38;
    s32 sp34;
    s32 objsize;    
    GObj* temp_v0_2;

    objsize = 0x130;
    
    if (arg4 & 1) {
        sp9C = 4;
        sp98 = 4;
    } else if (arg4 & 2) {
        sp9C = 8;
        sp98 = 8;
    } else {
        sp9C = 0;
        sp98 = 0;
    }

    if (arg4 & 0x200) {
        sp78 = 1;
    } else if (arg4 & 0x400) {
        sp78 = 4;
    } else {
        sp78 = 2;
    }

    var0 = arg2 + sp9C * 2;
    sp38 = arg3 + sp98 * 2;
    sp34 = (32 + var0 + (sp78 >> 2) * 0x10 + 0xF) & ~0xF;
    
    sp88 = 0x1000 / sp78 / sp34;
    sp24 = (sp38 + sp88 - 1) / sp88;
    
    
    sp80 = sp24 * 0x10;
    sp80 = ((u32)(sp80) + 7) & ~7;
    
    sp84 = sp34 * sp88 * sp24 * sp78;
    sp84 = (sp84 + 7) & ~7;

    if (arg4 & 0x80) {
        sp84 *= 2;
        sp80 *= 2;
    }
    
    //sp20 = sp24 * 12 + 24;
    sp20 = (new_var2 = sp24 ^ (sp38 *0)) * 12;
    new_var = 24;
    sp20 += new_var;
    sp60 = func_8036A194_83D944(objsize + sp84 + sp80 + sp20 * 8);
    temp_a1_2 = (u8*)sp60 + objsize;
    temp_a2_2 = temp_a1_2 + sp84;
    sp60->unk_54 = temp_a1_2;
    sp60->unk_F0 = temp_a2_2;
    sp60->unk_EC = temp_a2_2 + sp80;

    sp60->unk_0 = arg0;
    sp60->unk_4 = arg1;
    sp60->unk_8 = sp9C;
    sp60->unk_C = sp98;
    sp60->unk_10 = arg2;
    sp60->unk_14 = arg3;
    sp60->unk_18 = arg4;

    sp60->unk_48 = D_8037EA70_852220;
    sp60->unk_4C = D_8037EA74_852224;
    sp60->unk_44 = sp34;

    sp60->unk_114 = D_8037EA84_852234;
    sp60->unk_118 = 0;
    sp60->unk_11C = D_8037EA80_852230;
    
    sp60->unk_120 = 0;
    sp60->unk_124 = 0;
    sp60->unk_128 = D_8037EA88_852238++;

    sp60->unk_1C = 0;
    sp60->unk_20 = 0;
    sp60->unk_24 = 0;
    sp60->unk_28 = 0;

    sp60->unk_60 = sp78;
    
    ptr = sp60->unk_54;
    tmp = ((u32)sp84 >> 3) + 1;
#pragma _permuter sameline start
    while (--tmp > 0) { *ptr++ = 0; }
#pragma _permuter sameline end

    if (arg4 & 0x80) {
        sp84 /= 2;
        sp80 /= 2;        
        sp60->unk_58 = sp60->unk_54 + sp84;
        sp60->unk_F4 = (Bitmap*) ((uintptr_t) (sp60->unk_F0) + sp80);
        sp60->unk_5C = sp84;
    } else {
        sp60->unk_58 = NULL;
        sp60->unk_F4 = NULL;
        sp60->unk_5C = sp84;
    }
    sp60->unk_2C = arg0;
    sp60->unk_A8.x = arg0;
    sp60->unk_A8.y = arg1;
    sp60->unk_104 = sp78;
    sp60->unk_34 = sp60->unk_A8.width;
    sp60->unk_38 = sp60->unk_A8.height;

    if (arg4 & 0x800) {
        sp60->unk_108 = 1;
        sp60->unk_64.bmfmt = 3;
    } else {
        sp60->unk_108 = 0;
        sp60->unk_64.bmfmt = 0;
    }

    if (arg4 & 0x200) {
        sp60->unk_64.bmsiz = 1;
    } else if (arg4 & 0x400) {
        sp60->unk_64.bmsiz = 3;
    } else {
        sp60->unk_64.bmsiz = 2;
    }

    sp60->unk_64.x = sp60->unk_0 - sp60->unk_8;
    sp60->unk_64.y = sp60->unk_4 - sp60->unk_C;
    sp60->unk_64.width = sp34;
    sp60->unk_64.height = sp38;
    sp60->unk_64.scalex = 1.0f;
    sp60->unk_64.scaley = 1.0f;
    sp60->unk_64.expx = 0;
    sp60->unk_64.expy = 0;

    sp60->unk_64.attr = 5;
    if (arg4 & 0x100) {
        sp60->unk_64.attr |= 0x10;
    }

    sp60->unk_64.zdepth = 0x100;
    sp60->unk_64.red = 255;
    sp60->unk_64.green = 255;
    sp60->unk_64.blue = 255;
    sp60->unk_64.alpha = 255;
    sp60->unk_64.startTLUT = 0;
    sp60->unk_64.nTLUT = 0;
    sp60->unk_64.LUT = 0;
    sp60->unk_64.istart = 0;
    sp60->unk_64.istep = 1;
    sp60->unk_64.nbitmaps = new_var2;
    sp60->unk_64.ndisplist = sp20;
    sp60->unk_64.bmheight = sp88;
    sp60->unk_64.bmHreal = sp88;
#pragma _permuter sameline start
    sp60->unk_64.frac_t = 0;\
    sp60->unk_64.frac_s = 0;\
    new_var3 = sp60->unk_F0;\
    sp60->unk_64.rsp_dl = sp60->unk_EC;\
    sp60->unk_64.rsp_dl_next = 0;
#pragma _permuter sameline end
    sp60->unk_64.bitmap = new_var3;
    for (i = 0; i < sp24; i++) {
        sp60->unk_F0[i].width = var0;
        sp60->unk_F0[i].width_img = sp34;
        sp60->unk_F0[i].s = 0;
        sp60->unk_F0[i].t = 0;
        sp60->unk_F0[i].buf = sp60->unk_54 + i * sp34 * sp88 * sp78;
        sp60->unk_F0[i].actualHeight = sp88 < sp38 - sp88 * i ? sp88 : sp38 - sp88 * i;
        sp60->unk_F0[i].LUToffset = 0;
    }

    if (arg4 & 0x80) {
        for (i = 0; i < sp24; i++) {
            sp60->unk_F4[i].width = var0;
            sp60->unk_F4[i].width_img = sp34;
            sp60->unk_F4[i].s = 0;
            sp60->unk_F4[i].t = 0;
            sp60->unk_F4[i].buf = sp60->unk_58 + i * sp34 * sp88 * sp78;
            sp60->unk_F4[i].actualHeight = sp88 < sp38 - sp88 * i ? sp88 : sp38 - sp88 * i;
            if (!sp84) {} // fake?
            sp60->unk_F4[i].LUToffset = 0;
        }
        sp60->unk_64.bitmap = sp60->unk_F4;
    }

    temp_v0_2 = func_800A9F10(NULL, 6, &sp60->unk_64);
    if (temp_v0_2 == NULL) {
        func_8036A228_83D9D8(sp60);
        return NULL;
    }
    sp60->unk_50 = temp_v0_2;
    sp60->unk_40 = 0;
    func_8036A4AC_83DC5C(sp60);
    return sp60;
}

void func_8036B5F0_83EDA0(UnkSnowHerring* arg0) {
    if (arg0 != 0) {
        func_8036A53C_83DCEC(arg0);
        omDeleteGObj(arg0->unk_50);
        func_8036A228_83D9D8(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036B628_83EDD8.s")

void func_8036B734_83EEE4(UnkSnowHerring* arg0) {
    arg0->unk_1C = 0;
    arg0->unk_20 = 0;
    arg0->unk_24 = 0;
    arg0->unk_28 = 0;

    if (arg0->unk_18 & 1) {
        func_8036A9AC_83E15C(arg0, 0, 0, arg0->unk_10 + (arg0->unk_8 * 2), arg0->unk_14 + (arg0->unk_C * 2), arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    } else {
        func_8036A5B8_83DD68(arg0, 0, 0, arg0->unk_10 - 1, arg0->unk_14 - 1, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    }

    arg0->unk_64.attr &= ~SP_HIDDEN;
    arg0->unk_118 = func_8036D774_840F24();
    func_8036B628_83EDD8(arg0);
    arg0->unk_50->data.sobj->sprite = arg0->unk_64;
}

void func_8036B870_83F020(UnkSnowHerring* arg0, s32 arg1, s32 r, s32 g, s32 b, s32 a) {
    if (arg1) {
        D_8037EA70_852220.r = r;
        D_8037EA70_852220.a = a;
        D_8037EA70_852220.g = g;
        D_8037EA70_852220.b = b;
        D_8037EA78_852228.a = a;
        if (arg0) {
            arg0->unk_48 = D_8037EA70_852220;
        }
    } else {
        D_8037EA74_852224.a = a;
        D_8037EA74_852224.r = r;
        D_8037EA74_852224.g = g;
        D_8037EA74_852224.b = b;
        D_8037EA7C_85222C.a = a;
        if (arg0) {
            arg0->unk_4C = D_8037EA74_852224;
        }
    }

    if (!arg0) {
        return;
    }

    if (arg0->unk_18 & 0x800) {
        func_8036D77C_840F2C(&arg0->unk_F8, &D_8037EA78_852228, &D_8037EA7C_85222C);
        arg0->unk_64.red = D_8037EA70_852220.r;
        arg0->unk_64.green = D_8037EA70_852220.g;
        arg0->unk_64.blue = D_8037EA70_852220.b;
        return;
    }
    func_8036D77C_840F2C(&arg0->unk_F8, &D_8037EA70_852220, &D_8037EA74_852224);
}

u32 func_8036B988_83F138(UnkSnowHerring* arg0, s32 arg1) {
    u32 out;

    if (arg1) {
        out = (arg0->unk_48.r << 24) | (arg0->unk_48.g << 16) | (arg0->unk_48.b << 8) | arg0->unk_48.a;
    } else {
        out = (arg0->unk_4C.r << 24) | (arg0->unk_4C.g << 16) | (arg0->unk_4C.b << 8) | arg0->unk_4C.a;
    }

    return out;
}

void func_8036B9EC_83F19C(UnkSnowHerring* arg0, s32 x, s32 y) {
    if (x < 0) {
        x = 0;
    } else if (x >= arg0->unk_10) {
        x = arg0->unk_10 - 1;
    }

    if (y >= arg0->unk_14) {
        y = arg0->unk_14 - 1;
    }

    arg0->unk_120 = x;
    arg0->unk_124 = y;
    arg0->unk_118 = func_8036D774_840F24();
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036BA50_83F200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036C2FC_83FAAC.s")

void func_8036C898_840048(UnkSnowHerring* arg0, char* arg1) {
    UNUSED s32 pad[6];
    ucolor a1;
    ucolor a2;

    if (!arg1) {
        return;
    }

    func_8036D344_840AF4(arg0->unk_114);
    arg0->unk_FC = arg0->unk_44;
    arg0->unk_F8 = (arg0->unk_54 + (((arg0->unk_44 * arg0->unk_C) + arg0->unk_8) * arg0->unk_60));
    arg0->unk_104 = arg0->unk_60;
    arg0->unk_100 = arg0->unk_14;
    arg0->unk_10C = arg0->unk_0 + arg0->unk_8;
    arg0->unk_110 = arg0->unk_4 + arg0->unk_C;
    if (arg0->unk_18 & 0x800) {
        a1 = D_8037EA78_852228;
        a2 = D_8037EA7C_85222C;
        a1.a = arg0->unk_48.a;
        a2.a = arg0->unk_4C.a;
        func_8036D77C_840F2C(&arg0->unk_F8, &a1, &a2);
    } else {
        func_8036D77C_840F2C(&arg0->unk_F8, &arg0->unk_48, &arg0->unk_4C);
    }

    func_8036E490_841C40(&arg0->unk_F8, &arg0->unk_120, &arg0->unk_124, arg1);

    osWritebackDCache(arg0->unk_F0, arg0->unk_44 * arg0->unk_14);
}

void func_8036C9C0_840170(UnkSnowHerring* arg0, char* arg1) {
    UNUSED s32 pad[6];
    ucolor a1;
    ucolor a2;

    if (!arg1) {
        return;
    }

    func_8036D344_840AF4(arg0->unk_114);
    arg0->unk_FC = arg0->unk_44;
    arg0->unk_F8 = (arg0->unk_54 + (((arg0->unk_44 * arg0->unk_C) + arg0->unk_8) * arg0->unk_60));
    arg0->unk_104 = arg0->unk_60;
    arg0->unk_100 = arg0->unk_14;
    arg0->unk_10C = arg0->unk_0 + arg0->unk_8;
    arg0->unk_110 = arg0->unk_4 + arg0->unk_C;
    if (arg0->unk_18 & 0x800) {
        a1 = D_8037EA78_852228;
        a2 = D_8037EA7C_85222C;
        a1.a = arg0->unk_48.a;
        a2.a = arg0->unk_4C.a;
        func_8036D77C_840F2C(&arg0->unk_F8, &a1, &a2);
    } else {
        func_8036D77C_840F2C(&arg0->unk_F8, &arg0->unk_48, &arg0->unk_4C);
    }

    func_8036E9BC_84216C(&arg0->unk_F8, &arg0->unk_120, &arg0->unk_124, arg1);

    osWritebackDCache(arg0->unk_F0, arg0->unk_44 * arg0->unk_14);
}

void func_8036CAE8_840298(UnkSnowHerring* arg0, s32 arg1) {
    char sp1C[2];

    sp1C[0] = arg1;
    sp1C[1] = '\0';
    func_8036C898_840048(arg0, sp1C);
}

void func_8036CB10_8402C0(UnkSnowHerring* arg0, f32 scalex, f32 scaley) {
    if ((arg0 != NULL) && (arg0->unk_18 & 0x100)) {
        arg0->unk_50->data.sobj->sprite.scalex = scalex;
        arg0->unk_50->data.sobj->sprite.scaley = scaley;
        arg0->unk_64.scalex = scalex;
        arg0->unk_64.scaley = scaley;
    }
}

void func_8036CB58_840308(UnkSnowHerring* arg0, s32 arg1) {
    if (func_8036D344_840AF4(arg1)) {
        return;
    }

    if (arg0) {
        arg0->unk_114 = arg1;
    } else {
        D_8037EA84_852234 = arg1;
    }
}

void func_8036CBA0_840350(UnkSnowHerring* arg0, s32 x, s32 y) {
    if (!arg0) {
        return;
    }

    arg0->unk_0 = x;
    arg0->unk_4 = y;
    arg0->unk_64.x = x - arg0->unk_8;
    arg0->unk_64.y = y - arg0->unk_C;
    if (!(arg0->unk_18 & 0x40)) {
        arg0->unk_50->data.sobj->sprite.x = arg0->unk_64.x;
        arg0->unk_50->data.sobj->sprite.y = arg0->unk_64.y;
    }
}

void func_8036CBFC_8403AC(UnkSnowHerring* arg0, s32 x, s32 y) {
    if (!arg0) {
        return;
    }

    arg0->unk_2C = x;
    arg0->unk_30 = y;
    arg0->unk_A8.x = x;
    arg0->unk_A8.y = y;
    if (arg0->unk_18 & 0x40) {
        arg0->unk_50->data.sobj->sprite.x = arg0->unk_A8.x;
        arg0->unk_50->data.sobj->sprite.y = arg0->unk_A8.y;
    }
}

void func_8036CC48_8403F8(UnkSnowHerring* arg0, Sprite* arg1) {
    if (arg0 != NULL && arg1 != NULL) {
        arg0->unk_34 = arg1->width;
        arg0->unk_38 = arg1->height;

        arg0->unk_A8 = *arg1;

        arg0->unk_A8.x = arg0->unk_2C;
        arg0->unk_A8.y = arg0->unk_30;

        if (arg0->unk_18 & 0x40) {
            arg0->unk_50->data.sobj->sprite.x = arg0->unk_A8.x;
            arg0->unk_50->data.sobj->sprite.y = arg0->unk_A8.y;
        }
    }
}

void func_8036CCEC_84049C(UnkSnowHerring* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg1 != 0) {
            arg0->unk_50->data.sobj->sprite = arg0->unk_A8;
            arg0->unk_18 |= 0x40;
        } else {
            arg0->unk_50->data.sobj->sprite = arg0->unk_64;
            arg0->unk_18 &= ~0x40;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036CDAC_84055C.s")

UnkSnowHerring* func_8036D018_8407C8(void) {
    return D_8037EA8C_85223C;
}

UnkSnowHerring* func_8036D024_8407D4(UnkSnowHerring* arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk_3C;
}

void func_8036D040_8407F0(UnkSnowHerring* arg0) {
    GObj* gobj;

    if ((D_8037EA8C_85223C != NULL) && (arg0 != D_8037EA8C_85223C) && (arg0 != NULL)) {
        gobj = arg0->unk_50;
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
        func_8036A53C_83DCEC(arg0);
        func_8036A4AC_83DC5C(arg0);
    }
}

void func_8036D09C_84084C(UnkSnowHerring* arg0) {
    GObj* temp_a0;

    if ((D_8037EA8C_85223C != NULL) && (arg0 != D_8037EA8C_85223C) && (arg0 != NULL)) {
        temp_a0 = arg0->unk_50;
        omMoveGObjDLHead(temp_a0, temp_a0->dlLink, temp_a0->dlPriority);
        func_8036A53C_83DCEC(arg0);
        func_8036A4F4_83DCA4(arg0);
    }
}

UnkSnowHerring* func_8036D0F8_8408A8(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    UnkSnowHerring* temp_v0;
    s32 temp_s0;

    func_8036D344_840AF4(arg3);
    temp_s0 = func_8036D4F0_840CA0(arg2);
    // TODO: look into a "ceil to multiple of" macro
    temp_v0 = func_8036AC6C_83E41C(arg0, arg1, (temp_s0 + 1 + 0xF) & ~0xF, ((func_8036D758_840F08() + 1) & ~1) + 4, arg4);
    func_8036CB58_840308(temp_v0, arg3);
    func_8036B734_83EEE4(temp_v0);
    func_8036B9EC_83F19C(temp_v0, 0, 0);
    func_8036C898_840048(temp_v0, arg2);

    return temp_v0;
}

void func_8036D1A4_840954(UnkSnowHerring* arg0, s32 arg1) {
    if (!arg0) {
        return;
    }

    func_8036EFEC_84279C(arg1, arg0->unk_0, arg0->unk_4, arg0->unk_0 + arg0->unk_10, arg0->unk_4 + arg0->unk_14);

    if (arg1) {
        arg0->unk_50->data.sobj->sprite.attr |= SP_HIDDEN;
    } else {
        arg0->unk_50->data.sobj->sprite.attr &= ~SP_HIDDEN;
    }
}

GObj* func_8036D22C_8409DC(UnkSnowHerring* arg0) {
    if (!arg0) {
        return NULL;
    }

    return arg0->unk_50;
}

void func_8036D248_8409F8(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != NULL) {
        arg0->unk_50->data.sobj->sprite.red = arg1;
        arg0->unk_50->data.sobj->sprite.green = arg2;
        arg0->unk_50->data.sobj->sprite.blue = arg3;
        arg0->unk_50->data.sobj->sprite.alpha = arg4;
    }
}

s32 func_8036D28C_840A3C(UnkSnowHerring* arg0) {
    return arg0->unk_10;
}
