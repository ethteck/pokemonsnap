#include "common.h"
#include "window.h"

void func_8036A480_83DC30(void) {
    D_8037EA80_852230 = 0;
    D_8037EA84_852234 = 0;
    D_8037EA88_852238 = 0;
    D_8037EA8C_85223C = NULL;
    D_8037EA90_852240 = NULL;
}

void UIElement_LinkHead(UnkSnowHerring* el) {
    if (D_8037EA8C_85223C == NULL) {
        D_8037EA8C_85223C = el;
        D_8037EA90_852240 = el;
        el->next = NULL;
        el->prev = NULL;
    } else {
        D_8037EA8C_85223C->prev = el;
        el->next = (void*) D_8037EA8C_85223C;
        el->prev = NULL;
        D_8037EA8C_85223C = el;
    }
}

void UIElement_LinkTail(UnkSnowHerring* el) {
    if (D_8037EA90_852240 == NULL) {
        D_8037EA8C_85223C = el;
        D_8037EA90_852240 = el;
        el->next = NULL;
        el->prev = NULL;
    } else {
        D_8037EA90_852240->next = el;
        el->next = NULL;
        el->prev = D_8037EA90_852240;
        D_8037EA90_852240 = el;
    }
}

void UIElement_Unlink(UnkSnowHerring* arg0) {
    if (arg0->next == NULL && arg0->prev == NULL) {
        D_8037EA8C_85223C = NULL;
        D_8037EA90_852240 = NULL;
    } else if (arg0->next == NULL) {
        D_8037EA90_852240 = arg0->prev;
        arg0->prev->next = NULL;
    } else if (arg0->prev == NULL) {
        arg0->next->prev = NULL;
        D_8037EA8C_85223C = arg0->next;
    } else {
        arg0->next->prev = arg0->prev;
        arg0->prev->next = arg0->next;
    }
}

//#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036A5B8_83DD68.s")
void func_8036A5B8_83DD68(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 temp;
    s32 height;
    s32 t1;

    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > arg0->width) {
        arg1 = arg0->width - 1;
    }

    if (arg3 < 0) {
        arg3 = 0;
    } else if (arg3 > arg0->width) {
        arg3 = arg0->width - 1;
    }

    if (arg2 < 0) {
        arg2 = 0;
    } else if (arg2 > arg0->height) {
        arg2 = arg0->height - 1;
    }

    if (arg4 < 0) {
        arg4 = 0;
    } else if (arg4 > arg0->height) {
        arg4 = arg0->height - 1;
    }

    if (arg3 < arg1) {
        temp = arg1;
        arg1 = arg3;
        arg3 = temp;
    }

    if (arg4 < arg2) {
        temp = arg2;
        arg2 = arg4;
        arg4 = temp;
    }

    height = arg4 - arg2 + 1;
    t1 = arg0->unk_44 * (arg2 + arg0->borderHeight) + arg0->borderWidth + arg1;

    if (arg0->flags & 0x200) {

    }
}

void func_8036A8E4_83E094(UnkSnowHerring* arg0) {
    func_8036A5B8_83DD68(arg0, 0, 0, arg0->width, arg0->height, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    arg0->unk_120 = 0;
    arg0->unk_124 = 0;
    arg0->unk_118 = 0;
    func_8036EEB0_842660(arg0->x, arg0->y, arg0->x + arg0->width, arg0->y + arg0->height);
}

void func_8036A968_83E118(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8036A5B8_83DD68(arg0, arg1, arg2, arg3, arg4, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036A9AC_83E15C.s")

UnkSnowHerring* UIElement_Create(s32 x, s32 y, s32 width, s32 height, s32 flags) {
    u8* bitmaps_ptr;
    s32 tmp;
    s32 borderWidth;
    s32 borderHeight;
    s32 i;
    s32 totalWidth;
    s32 numTiles;
    s32 tileHeight;
    s32 rastersBytes;
    s32 bitmapsBytes;
    u32 ndisplist;
    s32 bytesPerPixel;
    s32 new_var;
    Bitmap* new_var3;
    u8* rasters_ptr;
    u64* ptr;
    s32 numTiles2;
    UnkSnowHerring* el;
    s32 totalHeight;
    s32 tileWidth;
    s32 objsize;
    GObj* obj;

    objsize = sizeof(UnkSnowHerring);

    if (flags & 1) {
        borderWidth = 4;
        borderHeight = 4;
    } else if (flags & 2) {
        borderWidth = 8;
        borderHeight = 8;
    } else {
        borderWidth = 0;
        borderHeight = 0;
    }

    if (flags & 0x200) {
        bytesPerPixel = 1;
    } else if (flags & 0x400) {
        bytesPerPixel = 4;
    } else {
        bytesPerPixel = 2;
    }

    totalWidth = width + borderWidth * 2;
    totalHeight = height + borderHeight * 2;
    tileWidth = (32 + totalWidth + (bytesPerPixel >> 2) * 0x10 + 0xF) & ~0xF;

    tileHeight = 0x1000 / bytesPerPixel / tileWidth;
    numTiles = (totalHeight + tileHeight - 1) / tileHeight;

    bitmapsBytes = numTiles * sizeof(Bitmap);
    bitmapsBytes = ((u32) (bitmapsBytes) + 7) & ~7;

    rastersBytes = tileWidth * tileHeight * numTiles * bytesPerPixel;
    rastersBytes = (rastersBytes + 7) & ~7;

    if (flags & 0x80) {
        rastersBytes *= 2;
        bitmapsBytes *= 2;
    }

    ndisplist = (numTiles2 = numTiles ^ (totalHeight * 0)) * 12;
    new_var = 24;
    ndisplist += new_var;
    el = func_8036A194_83D944(objsize + rastersBytes + bitmapsBytes + ndisplist * sizeof(Gfx));
    rasters_ptr = (u8*) el + objsize;
    bitmaps_ptr = rasters_ptr + rastersBytes;
    el->rasters = rasters_ptr;
    el->bitmaps = bitmaps_ptr;
    el->rsp_dl = bitmaps_ptr + bitmapsBytes;

    el->x = x;
    el->y = y;
    el->borderWidth = borderWidth;
    el->borderHeight = borderHeight;
    el->width = width;
    el->height = height;
    el->flags = flags;

    el->unk_48 = D_8037EA70_852220;
    el->unk_4C = D_8037EA74_852224;
    el->unk_44 = tileWidth;

    el->unk_114 = D_8037EA84_852234;
    el->unk_118 = 0;
    el->unk_11C = D_8037EA80_852230;

    el->unk_120 = 0;
    el->unk_124 = 0;
    el->id = D_8037EA88_852238++;

    el->unk_1C = 0;
    el->unk_20 = 0;
    el->unk_24 = 0;
    el->unk_28 = 0;

    el->bpp = bytesPerPixel;

    ptr = el->rasters;
    tmp = ((u32) rastersBytes >> 3) + 1;
    // clang-format off
    while (--tmp > 0) { *ptr++ = 0; }
    // clang-format on

    if (flags & 0x80) {
        rastersBytes /= 2;
        bitmapsBytes /= 2;
        el->unk_58 = el->rasters + rastersBytes;
        el->unk_F4 = (Bitmap*) ((uintptr_t) (el->bitmaps) + bitmapsBytes);
        el->unk_5C = rastersBytes;
    } else {
        el->unk_58 = NULL;
        el->unk_F4 = NULL;
        el->unk_5C = rastersBytes;
    }
    el->unk_2C = x;
    el->unk_A8.x = x;
    el->unk_A8.y = y;
    el->unk_104 = bytesPerPixel;
    el->unk_34 = el->unk_A8.width;
    el->unk_38 = el->unk_A8.height;

    if (flags & 0x800) {
        el->unk_108 = true;
        el->sprite.bmfmt = G_IM_FMT_IA;
    } else {
        el->unk_108 = false;
        el->sprite.bmfmt = G_IM_FMT_RGBA;
    }

    if (flags & 0x200) {
        el->sprite.bmsiz = G_IM_SIZ_8b;
    } else if (flags & 0x400) {
        el->sprite.bmsiz = G_IM_SIZ_32b;
    } else {
        el->sprite.bmsiz = G_IM_SIZ_16b;
    }

    el->sprite.x = el->x - el->borderWidth;
    el->sprite.y = el->y - el->borderHeight;
    el->sprite.width = tileWidth;
    el->sprite.height = totalHeight;
    el->sprite.scalex = 1.0f;
    el->sprite.scaley = 1.0f;
    el->sprite.expx = 0;
    el->sprite.expy = 0;

    el->sprite.attr = 5;
    if (flags & 0x100) {
        el->sprite.attr |= 0x10;
    }

    el->sprite.zdepth = 0x100;
    el->sprite.red = 255;
    el->sprite.green = 255;
    el->sprite.blue = 255;
    el->sprite.alpha = 255;
    el->sprite.startTLUT = 0;
    el->sprite.nTLUT = 0;
    el->sprite.LUT = 0;
    el->sprite.istart = 0;
    el->sprite.istep = 1;
    el->sprite.nbitmaps = numTiles2;
    el->sprite.ndisplist = ndisplist;
    el->sprite.bmheight = tileHeight;
    el->sprite.bmHreal = tileHeight;
    // clang-format off
    el->sprite.frac_t = 0; \
    el->sprite.frac_s = 0; \
    new_var3 = el->bitmaps; \
    el->sprite.rsp_dl = el->rsp_dl; \
    el->sprite.rsp_dl_next = 0;
    // clang-format on
    el->sprite.bitmap = new_var3;
    for (i = 0; i < numTiles; i++) {
        el->bitmaps[i].width = totalWidth;
        el->bitmaps[i].width_img = tileWidth;
        el->bitmaps[i].s = 0;
        el->bitmaps[i].t = 0;
        el->bitmaps[i].buf = el->rasters + i * tileWidth * tileHeight * bytesPerPixel;
        el->bitmaps[i].actualHeight = tileHeight < totalHeight - tileHeight * i ? tileHeight : totalHeight - tileHeight * i;
        el->bitmaps[i].LUToffset = 0;
    }

    if (flags & 0x80) {
        for (i = 0; i < numTiles; i++) {
            el->unk_F4[i].width = totalWidth;
            el->unk_F4[i].width_img = tileWidth;
            el->unk_F4[i].s = 0;
            el->unk_F4[i].t = 0;
            el->unk_F4[i].buf = el->unk_58 + i * tileWidth * tileHeight * bytesPerPixel;
            el->unk_F4[i].actualHeight = tileHeight < totalHeight - tileHeight * i ? tileHeight : totalHeight - tileHeight * i;
            if (!rastersBytes) {
            } // fake?
            el->unk_F4[i].LUToffset = 0;
        }
        el->sprite.bitmap = el->unk_F4;
    }

    obj = func_800A9F10(NULL, LINK_6, &el->sprite);
    if (obj == NULL) {
        func_8036A228_83D9D8(el);
        return NULL;
    }
    el->spriteObj = obj;
    el->prev = 0;
    UIElement_LinkHead(el);
    return el;
}

void func_8036B5F0_83EDA0(UnkSnowHerring* arg0) {
    if (arg0 != 0) {
        UIElement_Unlink(arg0);
        omDeleteGObj(arg0->spriteObj);
        func_8036A228_83D9D8(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/83DC30/func_8036B628_83EDD8.s")

void func_8036B734_83EEE4(UnkSnowHerring* arg0) {
    arg0->unk_1C = 0;
    arg0->unk_20 = 0;
    arg0->unk_24 = 0;
    arg0->unk_28 = 0;

    if (arg0->flags & 1) {
        func_8036A9AC_83E15C(arg0, 0, 0, arg0->width + (arg0->borderWidth * 2), arg0->height + (arg0->borderHeight * 2), arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    } else {
        func_8036A5B8_83DD68(arg0, 0, 0, arg0->width - 1, arg0->height - 1, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    }

    arg0->sprite.attr &= ~SP_HIDDEN;
    arg0->unk_118 = func_8036D774_840F24();
    func_8036B628_83EDD8(arg0);
    arg0->spriteObj->data.sobj->sprite = arg0->sprite;
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

    if (arg0->flags & 0x800) {
        func_8036D77C_840F2C(&arg0->unk_F8, &D_8037EA78_852228, &D_8037EA7C_85222C);
        arg0->sprite.red = D_8037EA70_852220.r;
        arg0->sprite.green = D_8037EA70_852220.g;
        arg0->sprite.blue = D_8037EA70_852220.b;
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
    } else if (x >= arg0->width) {
        x = arg0->width - 1;
    }

    if (y >= arg0->height) {
        y = arg0->height - 1;
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
    arg0->unk_F8 = (arg0->rasters + (((arg0->unk_44 * arg0->borderHeight) + arg0->borderWidth) * arg0->bpp));
    arg0->unk_104 = arg0->bpp;
    arg0->unk_100 = arg0->height;
    arg0->unk_10C = arg0->x + arg0->borderWidth;
    arg0->unk_110 = arg0->y + arg0->borderHeight;
    if (arg0->flags & 0x800) {
        a1 = D_8037EA78_852228;
        a2 = D_8037EA7C_85222C;
        a1.a = arg0->unk_48.a;
        a2.a = arg0->unk_4C.a;
        func_8036D77C_840F2C(&arg0->unk_F8, &a1, &a2);
    } else {
        func_8036D77C_840F2C(&arg0->unk_F8, &arg0->unk_48, &arg0->unk_4C);
    }

    func_8036E490_841C40(&arg0->unk_F8, &arg0->unk_120, &arg0->unk_124, arg1);

    osWritebackDCache(arg0->bitmaps, arg0->unk_44 * arg0->height);
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
    arg0->unk_F8 = (arg0->rasters + (((arg0->unk_44 * arg0->borderHeight) + arg0->borderWidth) * arg0->bpp));
    arg0->unk_104 = arg0->bpp;
    arg0->unk_100 = arg0->height;
    arg0->unk_10C = arg0->x + arg0->borderWidth;
    arg0->unk_110 = arg0->y + arg0->borderHeight;
    if (arg0->flags & 0x800) {
        a1 = D_8037EA78_852228;
        a2 = D_8037EA7C_85222C;
        a1.a = arg0->unk_48.a;
        a2.a = arg0->unk_4C.a;
        func_8036D77C_840F2C(&arg0->unk_F8, &a1, &a2);
    } else {
        func_8036D77C_840F2C(&arg0->unk_F8, &arg0->unk_48, &arg0->unk_4C);
    }

    func_8036E9BC_84216C(&arg0->unk_F8, &arg0->unk_120, &arg0->unk_124, arg1);

    osWritebackDCache(arg0->bitmaps, arg0->unk_44 * arg0->height);
}

void func_8036CAE8_840298(UnkSnowHerring* arg0, s32 arg1) {
    char sp1C[2];

    sp1C[0] = arg1;
    sp1C[1] = '\0';
    func_8036C898_840048(arg0, sp1C);
}

void func_8036CB10_8402C0(UnkSnowHerring* arg0, f32 scalex, f32 scaley) {
    if ((arg0 != NULL) && (arg0->flags & 0x100)) {
        arg0->spriteObj->data.sobj->sprite.scalex = scalex;
        arg0->spriteObj->data.sobj->sprite.scaley = scaley;
        arg0->sprite.scalex = scalex;
        arg0->sprite.scaley = scaley;
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

    arg0->x = x;
    arg0->y = y;
    arg0->sprite.x = x - arg0->borderWidth;
    arg0->sprite.y = y - arg0->borderHeight;
    if (!(arg0->flags & 0x40)) {
        arg0->spriteObj->data.sobj->sprite.x = arg0->sprite.x;
        arg0->spriteObj->data.sobj->sprite.y = arg0->sprite.y;
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
    if (arg0->flags & 0x40) {
        arg0->spriteObj->data.sobj->sprite.x = arg0->unk_A8.x;
        arg0->spriteObj->data.sobj->sprite.y = arg0->unk_A8.y;
    }
}

void func_8036CC48_8403F8(UnkSnowHerring* arg0, Sprite* arg1) {
    if (arg0 != NULL && arg1 != NULL) {
        arg0->unk_34 = arg1->width;
        arg0->unk_38 = arg1->height;

        arg0->unk_A8 = *arg1;

        arg0->unk_A8.x = arg0->unk_2C;
        arg0->unk_A8.y = arg0->unk_30;

        if (arg0->flags & 0x40) {
            arg0->spriteObj->data.sobj->sprite.x = arg0->unk_A8.x;
            arg0->spriteObj->data.sobj->sprite.y = arg0->unk_A8.y;
        }
    }
}

void func_8036CCEC_84049C(UnkSnowHerring* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg1 != 0) {
            arg0->spriteObj->data.sobj->sprite = arg0->unk_A8;
            arg0->flags |= 0x40;
        } else {
            arg0->spriteObj->data.sobj->sprite = arg0->sprite;
            arg0->flags &= ~0x40;
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
    return arg0->next;
}

void func_8036D040_8407F0(UnkSnowHerring* arg0) {
    GObj* gobj;

    if ((D_8037EA8C_85223C != NULL) && (arg0 != D_8037EA8C_85223C) && (arg0 != NULL)) {
        gobj = arg0->spriteObj;
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
        UIElement_Unlink(arg0);
        UIElement_LinkHead(arg0);
    }
}

void func_8036D09C_84084C(UnkSnowHerring* arg0) {
    GObj* temp_a0;

    if ((D_8037EA8C_85223C != NULL) && (arg0 != D_8037EA8C_85223C) && (arg0 != NULL)) {
        temp_a0 = arg0->spriteObj;
        omMoveGObjDLHead(temp_a0, temp_a0->dlLink, temp_a0->dlPriority);
        UIElement_Unlink(arg0);
        UIElement_LinkTail(arg0);
    }
}

UnkSnowHerring* func_8036D0F8_8408A8(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    UnkSnowHerring* temp_v0;
    s32 temp_s0;

    func_8036D344_840AF4(arg3);
    temp_s0 = func_8036D4F0_840CA0(arg2);
    // TODO: look into a "ceil to multiple of" macro
    temp_v0 = UIElement_Create(arg0, arg1, (temp_s0 + 1 + 0xF) & ~0xF, ((func_8036D758_840F08() + 1) & ~1) + 4, arg4);
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

    func_8036EFEC_84279C(arg1, arg0->x, arg0->y, arg0->x + arg0->width, arg0->y + arg0->height);

    if (arg1) {
        arg0->spriteObj->data.sobj->sprite.attr |= SP_HIDDEN;
    } else {
        arg0->spriteObj->data.sobj->sprite.attr &= ~SP_HIDDEN;
    }
}

GObj* func_8036D22C_8409DC(UnkSnowHerring* arg0) {
    if (!arg0) {
        return NULL;
    }

    return arg0->spriteObj;
}

void func_8036D248_8409F8(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != NULL) {
        arg0->spriteObj->data.sobj->sprite.red = arg1;
        arg0->spriteObj->data.sobj->sprite.green = arg2;
        arg0->spriteObj->data.sobj->sprite.blue = arg3;
        arg0->spriteObj->data.sobj->sprite.alpha = arg4;
    }
}

s32 func_8036D28C_840A3C(UnkSnowHerring* arg0) {
    return arg0->width;
}
