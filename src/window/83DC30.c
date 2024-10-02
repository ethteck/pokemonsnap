#include "common.h"
#include "window.h"

extern ucolor D_8037EA70_852220;
extern ucolor D_8037EA74_852224;
extern ucolor D_8037EA78_852228;
extern ucolor D_8037EA7C_85222C;
extern s32 D_8037EA80_852230;
extern s32 D_8037EA84_852234;
extern s32 D_8037EA88_852238;
extern UnkSnowHerring* D_8037EA8C_85223C;
extern UnkSnowHerring* D_8037EA90_852240;

void UIElement_ResetList(void) {
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

void UIElement_Unlink(UnkSnowHerring* el) {
    if (el->next == NULL && el->prev == NULL) {
        D_8037EA8C_85223C = NULL;
        D_8037EA90_852240 = NULL;
    } else if (el->next == NULL) {
        D_8037EA90_852240 = el->prev;
        el->prev->next = NULL;
    } else if (el->prev == NULL) {
        el->next->prev = NULL;
        D_8037EA8C_85223C = el->next;
    } else {
        el->next->prev = el->prev;
        el->prev->next = el->next;
    }
}

void UIElement_FillRect(UnkSnowHerring* el, s32 x1, s32 y1, s32 x2, s32 y2, s32 r, s32 g, s32 b, s32 a) {
    s32 temp;
    s32 fillHeight;
    s32 fillWidth;
    s32 skipPixels;
    s32 i;
    s32 j;

    if (x1 < 0) {
        x1 = 0;
    } else if (x1 >= el->width) {
        x1 = el->width - 1;
    }

    if (x2 < 0) {
        x2 = 0;
    } else if (x2 >= el->width) {
        x2 = el->width - 1;
    }

    if (y1 < 0) {
        y1 = 0;
    } else if (y1 >= el->height) {
        y1 = el->height - 1;
    }

    if (y2 < 0) {
        y2 = 0;
    } else if (y2 >= el->height) {
        y2 = el->height - 1;
    }

    if (x2 < x1) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (y2 < y1) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    fillHeight = y2 - y1 + 1;
    fillWidth = x2 - x1 + 1;

    skipPixels = el->imageWidth * (el->borderHeight + y1) + el->borderWidth + x1;

    if (el->flags & 0x200) {
        u8 val;
        u8* ptr;

        val = (r & 0xF0) | ((a >> 4) & 0xF);
        ptr = (u8*) el->image + skipPixels;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += el->imageWidth - fillWidth;
        }
    } else if (el->flags & 0x400) {
        u32 val;
        u32* ptr;

        val = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        ptr = (u32*) el->image + skipPixels;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += el->imageWidth - fillWidth;
        }
    } else {
        u16 val;
        u16* ptr;

        if (el->flags & 0x800) {
            if (el->flags & 0x10) {
                val = a;
                val |= 0xFF00;
            } else {
                val = (r << 8) | 0xFF;
            }
        } else {
            val = ((r << 8) & 0xF800) | ((g * 8) & 0x7C0) | ((b >> 2) & 0x3E) | (a & 1);
        }

        ptr = (u16*) el->image + skipPixels;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += el->imageWidth - fillWidth;
        }
    }
}

void func_8036A8E4_83E094(UnkSnowHerring* el) {
    UIElement_FillRect(el, 0, 0, el->width, el->height, el->unk_4C.r, el->unk_4C.g, el->unk_4C.b, el->unk_4C.a);
    el->unk_120 = 0;
    el->unk_124 = 0;
    el->unk_118 = 0;
    func_8036EEB0_842660(el->x, el->y, el->x + el->width, el->y + el->height);
}

void UIElement_FillRectDefault(UnkSnowHerring* el, s32 x1, s32 y1, s32 x2, s32 y2) {
    UIElement_FillRect(el, x1, y1, x2, y2, el->unk_4C.r, el->unk_4C.g, el->unk_4C.b, el->unk_4C.a);
}

void UIElement_FillRectWithBorder(UnkSnowHerring* arg0, s32 x1, s32 y1, s32 x2, s32 y2, s32 r, s32 g, s32 b, s32 a) {
    s32 temp;
    s32 fillHeight;
    s32 fillWidth;
    s32 skipPixels;
    s32 i;
    s32 j;

    if (x2 < x1) {
        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    if (y2 < y1) {
        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    fillHeight = y2 - y1 + 1;
    fillWidth = x2 - x1 + 1;

    if (arg0->flags & 0x200) {
        u8 val;
        u8* ptr;

        val = (r & 0xF0) | ((a >> 4) & 0xF);
        ptr = (u8*) arg0->image + arg0->imageWidth * y1 + x1;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += arg0->imageWidth - fillWidth;
        }
    } else if (arg0->flags & 0x400) {
        u32 val;
        u32* ptr;

        val = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        ptr = (u32*) arg0->image + arg0->imageWidth * y1 + x1;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += arg0->imageWidth - fillWidth;
        }
    } else {
        u16 val;
        u16* ptr;

        if (arg0->flags & 0x800) {
            if (arg0->flags & 0x10) {
                val = a;
                val |= 0xFF00;
            } else {
                val = (r << 8) | 0xFF;
            }
        } else {
            val = ((r << 8) & 0xF800) | ((g * 8) & 0x7C0) | ((b >> 2) & 0x3E) | (a & 1);
        }

        ptr = (u16*) arg0->image + arg0->imageWidth * y1 + x1;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += arg0->imageWidth - fillWidth;
        }
    }
}

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
    el->image = rasters_ptr;
    el->bitmaps = (Bitmap*) bitmaps_ptr;
    el->rsp_dl = (Gfx*) (bitmaps_ptr + bitmapsBytes);

    el->x = x;
    el->y = y;
    el->borderWidth = borderWidth;
    el->borderHeight = borderHeight;
    el->width = width;
    el->height = height;
    el->flags = flags;

    el->unk_48 = D_8037EA70_852220;
    el->unk_4C = D_8037EA74_852224;
    el->imageWidth = tileWidth;

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

    ptr = (u64*) el->image;
    tmp = ((u32) rastersBytes >> 3) + 1;
    // clang-format off
    while (--tmp > 0) { *ptr++ = 0; }
    // clang-format on

    if (flags & 0x80) {
        rastersBytes /= 2;
        bitmapsBytes /= 2;
        el->altImage = el->image + rastersBytes;
        el->altBitmaps = (Bitmap*) ((uintptr_t) (el->bitmaps) + bitmapsBytes);
        el->unk_5C = rastersBytes;
    } else {
        el->altImage = NULL;
        el->altBitmaps = NULL;
        el->unk_5C = rastersBytes;
    }
    el->unk_2C = x;
    el->unk_A8.x = x;
    el->unk_A8.y = y;
    el->unk_F8.bpp = bytesPerPixel;
    el->unk_34 = el->unk_A8.width;
    el->unk_38 = el->unk_A8.height;

    if (flags & 0x800) {
        el->unk_F8.unk_10 = true;
        el->sprite.bmfmt = G_IM_FMT_IA;
    } else {
        el->unk_F8.unk_10 = false;
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
        el->bitmaps[i].buf = el->image + i * tileWidth * tileHeight * bytesPerPixel;
        el->bitmaps[i].actualHeight = tileHeight < totalHeight - tileHeight * i ? tileHeight : totalHeight - tileHeight * i;
        el->bitmaps[i].LUToffset = 0;
    }

    if (flags & 0x80) {
        for (i = 0; i < numTiles; i++) {
            el->altBitmaps[i].width = totalWidth;
            el->altBitmaps[i].width_img = tileWidth;
            el->altBitmaps[i].s = 0;
            el->altBitmaps[i].t = 0;
            el->altBitmaps[i].buf = el->altImage + i * tileWidth * tileHeight * bytesPerPixel;
            el->altBitmaps[i].actualHeight = tileHeight < totalHeight - tileHeight * i ? tileHeight : totalHeight - tileHeight * i;
            if (!rastersBytes) {
            } // fake?
            el->altBitmaps[i].LUToffset = 0;
        }
        el->sprite.bitmap = el->altBitmaps;
    }

    obj = func_800A9F10(NULL, LINK_6, &el->sprite);
    if (obj == NULL) {
        func_8036A228_83D9D8(el);
        return NULL;
    }
    el->spriteObj = obj;
    el->prev = NULL;
    UIElement_LinkHead(el);
    return el;
}

void UIElement_Delete(UnkSnowHerring* el) {
    if (el != NULL) {
        UIElement_Unlink(el);
        omDeleteGObj(el->spriteObj);
        func_8036A228_83D9D8(el);
    }
}

void UIElement_SwapImages(UnkSnowHerring* arg0) {
    void* temp;

    if (!(arg0->flags & 0x80) || arg0->altImage == NULL) {
        arg0->spriteObj->data.sobj->sprite = arg0->sprite;
    } else {
        s32 tmp = ((u32) arg0->unk_5C >> 3);
        u64* src = (u64*) arg0->image;
        u64* dst = (u64*) arg0->altImage;

        while (tmp > 0) {
            *dst = *src;
            src++;
            dst++;
            tmp--;
        }

        temp = arg0->image;
        arg0->image = arg0->altImage;
        arg0->altImage = temp;

        temp = arg0->bitmaps;
        arg0->bitmaps = arg0->altBitmaps;
        arg0->altBitmaps = temp;

        arg0->sprite.bitmap = arg0->altBitmaps;
        arg0->spriteObj->data.sobj->sprite = arg0->sprite;
    }
}

void func_8036B734_83EEE4(UnkSnowHerring* arg0) {
    arg0->unk_1C = 0;
    arg0->unk_20 = 0;
    arg0->unk_24 = 0;
    arg0->unk_28 = 0;

    if (arg0->flags & 1) {
        UIElement_FillRectWithBorder(arg0, 0, 0, arg0->width + arg0->borderWidth * 2, arg0->height + arg0->borderHeight * 2, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    } else {
        UIElement_FillRect(arg0, 0, 0, arg0->width - 1, arg0->height - 1, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
    }

    arg0->sprite.attr &= ~SP_HIDDEN;
    arg0->unk_118 = func_8036D774_840F24();
    UIElement_SwapImages(arg0);
    arg0->spriteObj->data.sobj->sprite = arg0->sprite;
}

void UIElement_SetColor(UnkSnowHerring* el, s32 arg1, s32 r, s32 g, s32 b, s32 a) {
    if (arg1) {
        D_8037EA70_852220.r = r;
        D_8037EA70_852220.a = a;
        D_8037EA70_852220.g = g;
        D_8037EA70_852220.b = b;
        D_8037EA78_852228.a = a;
        if (el) {
            el->unk_48 = D_8037EA70_852220;
        }
    } else {
        D_8037EA74_852224.a = a;
        D_8037EA74_852224.r = r;
        D_8037EA74_852224.g = g;
        D_8037EA74_852224.b = b;
        D_8037EA7C_85222C.a = a;
        if (el) {
            el->unk_4C = D_8037EA74_852224;
        }
    }

    if (!el) {
        return;
    }

    if (el->flags & 0x800) {
        func_8036D77C_840F2C(&el->unk_F8, &D_8037EA78_852228, &D_8037EA7C_85222C);
        el->sprite.red = D_8037EA70_852220.r;
        el->sprite.green = D_8037EA70_852220.g;
        el->sprite.blue = D_8037EA70_852220.b;
    } else {
        func_8036D77C_840F2C(&el->unk_F8, &D_8037EA70_852220, &D_8037EA74_852224);
    }
}

u32 UIElement_GetColor(UnkSnowHerring* arg0, s32 arg1) {
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

void func_8036BA50_83F200(UnkSnowHerring* arg0, s32 arg1, s32 arg2) {
    s32 i, j;
    u8* src8;
    u8* ptr8;
    u16* src16;
    u16* ptr16;
    u32* src32;
    u32* ptr32;

    if (arg1 == 0) {
        return;
    }

    switch (arg2) {
        case 0:
            if (arg0->flags & 0x200) {
                src8 = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg1) + arg0->borderWidth;
                ptr8 = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr8 = *src8;
                        src8++;
                        ptr8++;
                    }
                    ptr8 += arg0->imageWidth - arg0->width;
                    src8 += arg0->imageWidth - arg0->width;
                }
            } else if (arg0->flags & 0x400) {
                src32 = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg1) + arg0->borderWidth;
                ptr32 = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr32 = *src32;
                        src32++;
                        ptr32++;
                    }
                    ptr32 += arg0->imageWidth - arg0->width;
                    src32 += arg0->imageWidth - arg0->width;
                }
            } else {
                src16 = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg1) + arg0->borderWidth;
                ptr16 = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr16 = *src16;
                        src16++;
                        ptr16++;
                    }
                    ptr16 += arg0->imageWidth - arg0->width;
                    src16 += arg0->imageWidth - arg0->width;
                }
            }
            UIElement_FillRect(arg0, 0, arg0->height - arg1, arg0->width, arg0->height, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
            break;
        case 1:
            if (arg0->flags & 0x200) {
                src8 = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - arg1 - 1) + arg0->borderWidth;
                ptr8 = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - 1) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr8 = *src8;
                        src8++;
                        ptr8++;
                    }
                    ptr8 -= arg0->imageWidth + arg0->width;
                    src8 -= arg0->imageWidth + arg0->width;
                }
            } else if (arg0->flags & 0x400) {
                src32 = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - arg1 - 1) + arg0->borderWidth;
                ptr32 = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - 1) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr32 = *src32;
                        src32++;
                        ptr32++;
                    }
                    ptr32 -= arg0->imageWidth + arg0->width;
                    src32 -= arg0->imageWidth + arg0->width;
                }
            } else {
                src16 = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - arg1 - 1) + arg0->borderWidth;
                ptr16 = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - 1) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr16 = *src16;
                        src16++;
                        ptr16++;
                    }
                    ptr16 -= arg0->imageWidth + arg0->width;
                    src16 -= arg0->imageWidth + arg0->width;
                }
            }
            UIElement_FillRect(arg0, 0, 0, arg0->width, arg1, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
            break;
        case 2:
            if (arg0->flags & 0x200) {
                src8 = (u8*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg0->width - arg1 - 1;
                ptr8 = (u8*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg0->width - 1;
                for (i = arg0->height; i > 0; i--) {
                    for (j = arg0->width - arg1; j > 0; j--) {
                        *ptr8 = *src8;
                        src8--;
                        ptr8--;
                    }
                    ptr8 += arg0->imageWidth + arg0->width - arg1;
                    src8 += arg0->imageWidth + arg0->width - arg1;
                }
            } else if (arg0->flags & 0x400) {
                src32 = (u32*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg0->width - arg1 - 1;
                ptr32 = (u32*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg0->width - 1;
                for (i = arg0->height; i > 0; i--) {
                    for (j = arg0->width - arg1; j > 0; j--) {
                        *ptr32 = *src32;
                        src32--;
                        ptr32--;
                    }
                    ptr32 += arg0->imageWidth + arg0->width - arg1;
                    src32 += arg0->imageWidth + arg0->width - arg1;
                }
            } else {
                src16 = (u16*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg0->width - arg1 - 1;
                ptr16 = (u16*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg0->width - 1;
                for (i = arg0->height; i > 0; i--) {
                    for (j = arg0->width - arg1; j > 0; j--) {
                        *ptr16 = *src16;
                        src16--;
                        ptr16--;
                    }
                    ptr16 += arg0->imageWidth + arg0->width - arg1;
                    src16 += arg0->imageWidth + arg0->width - arg1;
                }
            }
            UIElement_FillRect(arg0, 0, 0, arg1 - 1, arg0->height, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
            break;
        case 3:
            if (arg0->flags & 0x200) {
                src8 = (u8*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg1;
                ptr8 = (u8*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth;
                for (i = arg0->height; i > 0; i--) {
                    for (j = arg0->width - arg1; j > 0; j--) {
                        *ptr8 = *src8;
                        src8++;
                        ptr8++;
                    }
                    ptr8 += arg0->imageWidth + arg0->width - arg1;
                    src8 += arg0->imageWidth + arg0->width - arg1;
                }
            } else if (arg0->flags & 0x400) {
                src32 = (u32*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg1;
                ptr32 = (u32*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth;
                for (i = arg0->height; i > 0; i--) {
                    for (j = arg0->width - arg1; j > 0; j--) {
                        *ptr32 = *src32;
                        src32++;
                        ptr32++;
                    }
                    ptr32 += arg0->imageWidth + arg0->width - arg1;
                    src32 += arg0->imageWidth + arg0->width - arg1;
                }
            } else {
                src16 = (u16*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth + arg1;
                ptr16 = (u16*) arg0->image + arg0->imageWidth * arg0->borderHeight + arg0->borderWidth;
                for (i = arg0->height; i > 0; i--) {
                    for (j = arg0->width - arg1; j > 0; j--) {
                        *ptr16 = *src16;
                        src16++;
                        ptr16++;
                    }
                    ptr16 += arg0->imageWidth - arg0->width + arg1;
                    src16 += arg0->imageWidth - arg0->width + arg1;
                }
            }
            UIElement_FillRect(arg0, arg0->width - arg1, 0, arg0->width - 1, arg0->height, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
            break;
    }
}

void func_8036C2FC_83FAAC(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 x1, s32 y1, s32 x2, s32 y2) {
    s32 fillHeight;
    s32 fillWidth;
    s32 i, j;
    s32 skipPixels;

    if (x1 < 0) {
        x1 = 0;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (x2 < 0) {
        x2 = 0;
    }
    if (y2 < 0) {
        y2 = 0;
    }

    if (x1 > arg0->width) {
        x1 = arg0->width;
    }
    if (y1 > arg0->height) {
        y1 = arg0->height;
    }
    if (x2 > arg0->width) {
        x2 = arg0->width;
    }
    if (y2 > arg0->height) {
        y2 = arg0->height;
    }

    fillWidth = x2 - x1;
    fillHeight = y2 - y1 - arg1;

    switch (arg2) {
        case 0:
            if (arg0->flags & 0x200) {
                for (i = 0; i <= fillHeight; i++) {
                    u8* src = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg1 + i) + arg0->borderWidth + x1;
                    u8* ptr = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + i) + arg0->borderWidth + x1;
                    for (j = arg0->width; j > 0; j--) {
                        *ptr = *src;
                        src++;
                        ptr++;
                    }
                }
            } else if (arg0->flags & 0x400) {
                for (i = 0; i <= fillHeight; i++) {
                    u32* src = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg1 + i) + arg0->borderWidth;
                    u32* ptr = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + i) + arg0->borderWidth;
                    for (j = 0; j <= fillWidth; j++) {
                        *ptr = *src;
                        src++;
                        ptr++;
                    }
                }
            } else {
                for (i = 0; i <= fillHeight; i++) {
                    u16* src = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg1 + i) + arg0->borderWidth + x1;
                    u16* ptr = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + i) + arg0->borderWidth + x1;
                    for (j = 0; j <= fillWidth; j++) {
                        *ptr = *src;
                        src++;
                        ptr++;
                    }
                }
            }
            UIElement_FillRect(arg0, x1, y2 - arg1, x2, y2, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
            break;
        case 1:
            if (arg0->flags & 0x200) {
                u8* src = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - arg1 - 1) + arg0->borderWidth;
                u8* ptr = (u8*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - 1) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr = *src;
                        src++;
                        ptr++;
                    }
                    ptr -= arg0->imageWidth + arg0->width;
                    src -= arg0->imageWidth + arg0->width;
                }
            } else if (arg0->flags & 0x400) {
                u32* src = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - arg1 - 1) + arg0->borderWidth;
                u32* ptr = (u32*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - 1) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr = *src;
                        src++;
                        ptr++;
                    }
                    ptr -= arg0->imageWidth + arg0->width;
                    src -= arg0->imageWidth + arg0->width;
                }
            } else {
                u16* src = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - arg1 - 1) + arg0->borderWidth;
                u16* ptr = (u16*) arg0->image + arg0->imageWidth * (arg0->borderHeight + arg0->height - 1) + arg0->borderWidth;
                for (i = arg0->height - arg1; i > 0; i--) {
                    for (j = arg0->width; j > 0; j--) {
                        *ptr = *src;
                        src++;
                        ptr++;
                    }
                    ptr -= arg0->imageWidth + arg0->width;
                    src -= arg0->imageWidth + arg0->width;
                }
            }
            UIElement_FillRect(arg0, 0, 0, arg0->width, arg1, arg0->unk_4C.r, arg0->unk_4C.g, arg0->unk_4C.b, arg0->unk_4C.a);
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void func_8036C898_840048(UnkSnowHerring* arg0, char* arg1) {
    UNUSED s32 pad[6];
    ucolor a1;
    ucolor a2;

    if (arg1 == NULL) {
        return;
    }

    func_8036D344_840AF4(arg0->unk_114);
    arg0->unk_F8.width = arg0->imageWidth;
    arg0->unk_F8.image = arg0->image + (arg0->imageWidth * arg0->borderHeight + arg0->borderWidth) * arg0->bpp;
    arg0->unk_F8.bpp = arg0->bpp;
    arg0->unk_F8.height = arg0->height;
    arg0->unk_F8.x = arg0->x + arg0->borderWidth;
    arg0->unk_F8.y = arg0->y + arg0->borderHeight;
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

    osWritebackDCache(arg0->bitmaps, arg0->imageWidth * arg0->height); // doesn't make sense
}

void UIElement_PrintText2(UnkSnowHerring* el, char* text) {
    UNUSED s32 pad[6];
    ucolor a1;
    ucolor a2;

    if (text == NULL) {
        return;
    }

    func_8036D344_840AF4(el->unk_114);
    el->unk_F8.width = el->imageWidth;
    el->unk_F8.image = el->image + (el->imageWidth * el->borderHeight + el->borderWidth) * el->bpp;
    el->unk_F8.bpp = el->bpp;
    el->unk_F8.height = el->height;
    el->unk_F8.x = el->x + el->borderWidth;
    el->unk_F8.y = el->y + el->borderHeight;
    if (el->flags & 0x800) {
        a1 = D_8037EA78_852228;
        a2 = D_8037EA7C_85222C;
        a1.a = el->unk_48.a;
        a2.a = el->unk_4C.a;
        func_8036D77C_840F2C(&el->unk_F8, &a1, &a2);
    } else {
        func_8036D77C_840F2C(&el->unk_F8, &el->unk_48, &el->unk_4C);
    }

    func_8036E9BC_84216C(&el->unk_F8, &el->unk_120, &el->unk_124, text);

    osWritebackDCache(el->bitmaps, el->imageWidth * el->height);// doesn't make sense
}

void UIElement_PrintChar(UnkSnowHerring* arg0, s32 chr) {
    char str[2];

    str[0] = chr;
    str[1] = '\0';
    func_8036C898_840048(arg0, str);
}

void UIElement_SetScale(UnkSnowHerring* arg0, f32 scalex, f32 scaley) {
    if (arg0 != NULL && (arg0->flags & 0x100)) {
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

void UIElement_SetPos(UnkSnowHerring* el, s32 x, s32 y) {
    if (!el) {
        return;
    }

    el->x = x;
    el->y = y;
    el->sprite.x = x - el->borderWidth;
    el->sprite.y = y - el->borderHeight;
    if (!(el->flags & 0x40)) {
        el->spriteObj->data.sobj->sprite.x = el->sprite.x;
        el->spriteObj->data.sobj->sprite.y = el->sprite.y;
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

void func_8036CC48_8403F8(UnkSnowHerring* el, Sprite* arg1) {
    if (el != NULL && arg1 != NULL) {
        el->unk_34 = arg1->width;
        el->unk_38 = arg1->height;

        el->unk_A8 = *arg1;

        el->unk_A8.x = el->unk_2C;
        el->unk_A8.y = el->unk_30;

        if (el->flags & 0x40) {
            el->spriteObj->data.sobj->sprite.x = el->unk_A8.x;
            el->spriteObj->data.sobj->sprite.y = el->unk_A8.y;
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

void UIElement_DrawImage(UnkSnowHerring* arg0, s32 x, s32 y, s32 width, s32 height, u8* image) {
    s32 fillHeight;
    s32 fillWidth;
    s32 i;
    s32 j;
    s32 skipPixels;

    if (!arg0 || width <= 0 || height <= 0) {
        return;
    }

    if (x < 0) {
        x = 0;
    } else if (x >= arg0->width) {
        x = arg0->width - 1;
    }

    if (y < 0) {
        y = 0;
    } else if (y >= arg0->height) {
        y = arg0->height - 1;
    }

    skipPixels = arg0->imageWidth * (arg0->borderHeight + y) + arg0->borderWidth + x;

    if (arg0->flags & 0x200) {
        u8* ptr;
        u8* src;

        ptr = (u8*) arg0->image + skipPixels;
        src = (u8*) image;
        for (i = height; i > 0; i--) {
            // clang-format off
            for (j = width; j > 0; j--) { *ptr++ = *src++; }
            // clang-format on
            ptr += arg0->imageWidth - width;
        }
    } else if (arg0->flags & 0x400) {
        u32* ptr;
        u32* src;

        ptr = (u32*) arg0->image + skipPixels;
        src = (u32*) image;
        for (i = height; i > 0; i--) {
            // clang-format off
            for (j = width; j > 0; j--) { *ptr++ = *src++; }
            // clang-format on
            ptr += arg0->imageWidth - width;
        }
    } else {
        u16* ptr;
        u16* src;

        ptr = (u16*) arg0->image + skipPixels;
        src = (u16*) image;
        for (i = height; i > 0; i--) {
            // clang-format off
            for (j = width; j > 0; j--) { *ptr++ = *src++; }
            // clang-format on
            ptr += arg0->imageWidth - width;
        }
    }
}

UnkSnowHerring* UIElement_GetList(void) {
    return D_8037EA8C_85223C;
}

UnkSnowHerring* UIElement_GetNext(UnkSnowHerring* arg0) {
    if (arg0 == NULL) {
        return NULL;
    }
    return arg0->next;
}

void func_8036D040_8407F0(UnkSnowHerring* arg0) {
    GObj* gobj;

    if (D_8037EA8C_85223C != NULL && arg0 != D_8037EA8C_85223C && arg0 != NULL) {
        gobj = arg0->spriteObj;
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
        UIElement_Unlink(arg0);
        UIElement_LinkHead(arg0);
    }
}

void func_8036D09C_84084C(UnkSnowHerring* arg0) {
    GObj* gobj;

    if (D_8037EA8C_85223C != NULL && arg0 != D_8037EA8C_85223C && arg0 != NULL) {
        gobj = arg0->spriteObj;
        omMoveGObjDLHead(gobj, gobj->dlLink, gobj->dlPriority);
        UIElement_Unlink(arg0);
        UIElement_LinkTail(arg0);
    }
}

UnkSnowHerring* func_8036D0F8_8408A8(s32 x, s32 y, char* text, s32 arg3, s32 flags) {
    UnkSnowHerring* el;
    s32 temp_s0;

    func_8036D344_840AF4(arg3);
    temp_s0 = func_8036D4F0_840CA0(text);
    // TODO: look into a "ceil to multiple of" macro
    el = UIElement_Create(x, y, (temp_s0 + 1 + 0xF) & ~0xF, ((func_8036D758_840F08() + 1) & ~1) + 4, flags);
    func_8036CB58_840308(el, arg3);
    func_8036B734_83EEE4(el);
    func_8036B9EC_83F19C(el, 0, 0);
    func_8036C898_840048(el, text);

    return el;
}

void func_8036D1A4_840954(UnkSnowHerring* arg0, s32 arg1) {
    if (arg0 == NULL) {
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
    if (arg0 == NULL) {
        return NULL;
    }

    return arg0->spriteObj;
}

void func_8036D248_8409F8(UnkSnowHerring* el, s32 r, s32 g, s32 b, s32 a) {
    if (el != NULL) {
        el->spriteObj->data.sobj->sprite.red = r;
        el->spriteObj->data.sobj->sprite.green = g;
        el->spriteObj->data.sobj->sprite.blue = b;
        el->spriteObj->data.sobj->sprite.alpha = a;
    }
}

s32 func_8036D28C_840A3C(UnkSnowHerring* el) {
    return el->width;
}
