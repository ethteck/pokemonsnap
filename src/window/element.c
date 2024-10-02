#include "common.h"
#include "window.h"

ucolor UIElement_ForegroundColor = { 255, 255, 255, 255 };
ucolor UIElement_BackgroundColor = { 0, 0, 0, 255 };
ucolor UIElement_WhiteColor = { 255, 255, 255, 255 };
ucolor UIElement_TransparentWhiteColor = { 255, 255, 255, 0 };
s32 D_8037EA80_852230 = 0;
s32 UIElement_CurrentFont = 0;
s32 UIElement_Counter = 0;
UIElement* UIElement_ListHead = NULL;
UIElement* UIElement_ListTail = NULL;

void UIElement_ResetList(void) {
    D_8037EA80_852230 = 0;
    UIElement_CurrentFont = 0;
    UIElement_Counter = 0;
    UIElement_ListHead = NULL;
    UIElement_ListTail = NULL;
}

void UIElement_LinkHead(UIElement* el) {
    if (UIElement_ListHead == NULL) {
        UIElement_ListHead = el;
        UIElement_ListTail = el;
        el->next = NULL;
        el->prev = NULL;
    } else {
        UIElement_ListHead->prev = el;
        el->next = (void*) UIElement_ListHead;
        el->prev = NULL;
        UIElement_ListHead = el;
    }
}

void UIElement_LinkTail(UIElement* el) {
    if (UIElement_ListTail == NULL) {
        UIElement_ListHead = el;
        UIElement_ListTail = el;
        el->next = NULL;
        el->prev = NULL;
    } else {
        UIElement_ListTail->next = el;
        el->next = NULL;
        el->prev = UIElement_ListTail;
        UIElement_ListTail = el;
    }
}

void UIElement_Unlink(UIElement* el) {
    if (el->next == NULL && el->prev == NULL) {
        UIElement_ListHead = NULL;
        UIElement_ListTail = NULL;
    } else if (el->next == NULL) {
        UIElement_ListTail = el->prev;
        el->prev->next = NULL;
    } else if (el->prev == NULL) {
        el->next->prev = NULL;
        UIElement_ListHead = el->next;
    } else {
        el->next->prev = el->prev;
        el->prev->next = el->next;
    }
}

void UIElement_FillRect(UIElement* el, s32 x1, s32 y1, s32 x2, s32 y2, s32 r, s32 g, s32 b, s32 a) {
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

    if (el->flags & UI_FLAG_8BIT) {
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
    } else if (el->flags & UI_FLAG_32BIT) {
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

        if (el->flags & UI_FLAG_GRAYSCALE) {
            if (el->flags & UI_FLAG_10) {
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

void UIElement_Draw(UIElement* el) {
    UIElement_FillRect(el, 0, 0, el->width, el->height, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
    el->text.curX = 0;
    el->text.curY = 0;
    el->text.unk_118 = 0;
    func_8036EEB0_842660(el->x, el->y, el->x + el->width, el->y + el->height);
}

void UIElement_FillRectDefault(UIElement* el, s32 x1, s32 y1, s32 x2, s32 y2) {
    UIElement_FillRect(el, x1, y1, x2, y2, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
}

void UIElement_FillRectWithBorder(UIElement* el, s32 x1, s32 y1, s32 x2, s32 y2, s32 r, s32 g, s32 b, s32 a) {
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

    if (el->flags & UI_FLAG_8BIT) {
        u8 val;
        u8* ptr;

        val = (r & 0xF0) | ((a >> 4) & 0xF);
        ptr = (u8*) el->image + el->imageWidth * y1 + x1;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += el->imageWidth - fillWidth;
        }
    } else if (el->flags & UI_FLAG_32BIT) {
        u32 val;
        u32* ptr;

        val = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        ptr = (u32*) el->image + el->imageWidth * y1 + x1;
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

        if (el->flags & UI_FLAG_GRAYSCALE) {
            if (el->flags & UI_FLAG_10) {
                val = a;
                val |= 0xFF00;
            } else {
                val = (r << 8) | 0xFF;
            }
        } else {
            val = ((r << 8) & 0xF800) | ((g * 8) & 0x7C0) | ((b >> 2) & 0x3E) | (a & 1);
        }

        ptr = (u16*) el->image + el->imageWidth * y1 + x1;
        while (fillHeight > 0) {
            // clang-format off
            for (j = fillWidth; j > 0; j--) { *ptr++ = val; }
            // clang-format on
            fillHeight--;
            ptr += el->imageWidth - fillWidth;
        }
    }
}

UIElement* UIElement_Create(s32 x, s32 y, s32 width, s32 height, s32 flags) {
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
    UIElement* el;
    s32 totalHeight;
    s32 tileWidth;
    s32 objsize;
    GObj* obj;

    objsize = sizeof(UIElement);

    if (flags & UI_FLAG_BORDER) {
        borderWidth = 4;
        borderHeight = 4;
    } else if (flags & UI_FLAG_THICK_BORDER) {
        borderWidth = 8;
        borderHeight = 8;
    } else {
        borderWidth = 0;
        borderHeight = 0;
    }

    if (flags & UI_FLAG_8BIT) {
        bytesPerPixel = 1;
    } else if (flags & UI_FLAG_32BIT) {
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

    if (flags & UI_FLAG_USE_ALT_IMAGE) {
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

    el->fgColor = UIElement_ForegroundColor;
    el->bgColor = UIElement_BackgroundColor;
    el->imageWidth = tileWidth;

    el->text.font = UIElement_CurrentFont;
    el->text.unk_118 = 0;
    el->text.unk_11C = D_8037EA80_852230;

    el->text.curX = 0;
    el->text.curY = 0;
    el->id = UIElement_Counter++;

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

    if (flags & UI_FLAG_USE_ALT_IMAGE) {
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
    el->altX = x;
    el->altSprite.x = x;
    el->altSprite.y = y;
    el->text.bpp = bytesPerPixel;
    el->altWidth = el->altSprite.width;
    el->altHeight = el->altSprite.height;

    if (flags & UI_FLAG_GRAYSCALE) {
        el->text.unk_10 = true;
        el->sprite.bmfmt = G_IM_FMT_IA;
    } else {
        el->text.unk_10 = false;
        el->sprite.bmfmt = G_IM_FMT_RGBA;
    }

    if (flags & UI_FLAG_8BIT) {
        el->sprite.bmsiz = G_IM_SIZ_8b;
    } else if (flags & UI_FLAG_32BIT) {
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

    el->sprite.attr = SP_HIDDEN | SP_TRANSPARENT;
    if (flags & UI_FLAG_SCALABLE) {
        el->sprite.attr |= SP_SCALE;
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

    if (flags & UI_FLAG_USE_ALT_IMAGE) {
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

void UIElement_Delete(UIElement* el) {
    if (el != NULL) {
        UIElement_Unlink(el);
        omDeleteGObj(el->spriteObj);
        func_8036A228_83D9D8(el);
    }
}

void UIElement_SwapImages(UIElement* arg0) {
    void* temp;

    if (!(arg0->flags & UI_FLAG_USE_ALT_IMAGE) || arg0->altImage == NULL) {
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

void UIElement_DrawBackground(UIElement* el) {
    el->unk_1C = 0;
    el->unk_20 = 0;
    el->unk_24 = 0;
    el->unk_28 = 0;

    if (el->flags & UI_FLAG_BORDER) {
        UIElement_FillRectWithBorder(el, 0, 0, el->width + el->borderWidth * 2, el->height + el->borderHeight * 2, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
    } else {
        UIElement_FillRect(el, 0, 0, el->width - 1, el->height - 1, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
    }

    el->sprite.attr &= ~SP_HIDDEN;
    el->text.unk_118 = func_8036D774_840F24();
    UIElement_SwapImages(el);
    el->spriteObj->data.sobj->sprite = el->sprite;
}

void UIElement_SetColor(UIElement* el, s32 fg, s32 r, s32 g, s32 b, s32 a) {
    if (fg) {
        UIElement_ForegroundColor.r = r;
        UIElement_ForegroundColor.a = a;
        UIElement_ForegroundColor.g = g;
        UIElement_ForegroundColor.b = b;
        UIElement_WhiteColor.a = a;
        if (el) {
            el->fgColor = UIElement_ForegroundColor;
        }
    } else {
        UIElement_BackgroundColor.a = a;
        UIElement_BackgroundColor.r = r;
        UIElement_BackgroundColor.g = g;
        UIElement_BackgroundColor.b = b;
        UIElement_TransparentWhiteColor.a = a;
        if (el) {
            el->bgColor = UIElement_BackgroundColor;
        }
    }

    if (!el) {
        return;
    }

    if (el->flags & UI_FLAG_GRAYSCALE) {
        UIText_MakePalettes(&el->text, &UIElement_WhiteColor, &UIElement_TransparentWhiteColor);
        el->sprite.red = UIElement_ForegroundColor.r;
        el->sprite.green = UIElement_ForegroundColor.g;
        el->sprite.blue = UIElement_ForegroundColor.b;
    } else {
        UIText_MakePalettes(&el->text, &UIElement_ForegroundColor, &UIElement_BackgroundColor);
    }
}

u32 UIElement_GetColor(UIElement* el, s32 fg) {
    u32 out;

    if (fg) {
        out = (el->fgColor.r << 24) | (el->fgColor.g << 16) | (el->fgColor.b << 8) | el->fgColor.a;
    } else {
        out = (el->bgColor.r << 24) | (el->bgColor.g << 16) | (el->bgColor.b << 8) | el->bgColor.a;
    }

    return out;
}

void UIElement_SetTextPos(UIElement* el, s32 x, s32 y) {
    if (x < 0) {
        x = 0;
    } else if (x >= el->width) {
        x = el->width - 1;
    }

    if (y >= el->height) {
        y = el->height - 1;
    }

    el->text.curX = x;
    el->text.curY = y;
    el->text.unk_118 = func_8036D774_840F24();
}

void UIElement_Scroll(UIElement* el, s32 scrollAmt, s32 dir) {
    s32 i, j;
    u8* src8;
    u8* ptr8;
    u16* src16;
    u16* ptr16;
    u32* src32;
    u32* ptr32;

    if (scrollAmt == 0) {
        return;
    }

    switch (dir) {
        case 0:
            if (el->flags & UI_FLAG_8BIT) {
                src8 = (u8*) el->image + el->imageWidth * (el->borderHeight + scrollAmt) + el->borderWidth;
                ptr8 = (u8*) el->image + el->imageWidth * (el->borderHeight) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *ptr8 = *src8;
                        src8++;
                        ptr8++;
                    }
                    ptr8 += el->imageWidth - el->width;
                    src8 += el->imageWidth - el->width;
                }
            } else if (el->flags & UI_FLAG_32BIT) {
                src32 = (u32*) el->image + el->imageWidth * (el->borderHeight + scrollAmt) + el->borderWidth;
                ptr32 = (u32*) el->image + el->imageWidth * (el->borderHeight) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *ptr32 = *src32;
                        src32++;
                        ptr32++;
                    }
                    ptr32 += el->imageWidth - el->width;
                    src32 += el->imageWidth - el->width;
                }
            } else {
                src16 = (u16*) el->image + el->imageWidth * (el->borderHeight + scrollAmt) + el->borderWidth;
                ptr16 = (u16*) el->image + el->imageWidth * (el->borderHeight) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *ptr16 = *src16;
                        src16++;
                        ptr16++;
                    }
                    ptr16 += el->imageWidth - el->width;
                    src16 += el->imageWidth - el->width;
                }
            }
            UIElement_FillRect(el, 0, el->height - scrollAmt, el->width, el->height, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
            break;
        case 1:
            if (el->flags & UI_FLAG_8BIT) {
                src8 = (u8*) el->image + el->imageWidth * (el->borderHeight + el->height - scrollAmt - 1) + el->borderWidth;
                ptr8 = (u8*) el->image + el->imageWidth * (el->borderHeight + el->height - 1) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *ptr8 = *src8;
                        src8++;
                        ptr8++;
                    }
                    ptr8 -= el->imageWidth + el->width;
                    src8 -= el->imageWidth + el->width;
                }
            } else if (el->flags & UI_FLAG_32BIT) {
                src32 = (u32*) el->image + el->imageWidth * (el->borderHeight + el->height - scrollAmt - 1) + el->borderWidth;
                ptr32 = (u32*) el->image + el->imageWidth * (el->borderHeight + el->height - 1) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *ptr32 = *src32;
                        src32++;
                        ptr32++;
                    }
                    ptr32 -= el->imageWidth + el->width;
                    src32 -= el->imageWidth + el->width;
                }
            } else {
                src16 = (u16*) el->image + el->imageWidth * (el->borderHeight + el->height - scrollAmt - 1) + el->borderWidth;
                ptr16 = (u16*) el->image + el->imageWidth * (el->borderHeight + el->height - 1) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *ptr16 = *src16;
                        src16++;
                        ptr16++;
                    }
                    ptr16 -= el->imageWidth + el->width;
                    src16 -= el->imageWidth + el->width;
                }
            }
            UIElement_FillRect(el, 0, 0, el->width, scrollAmt, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
            break;
        case 2:
            if (el->flags & UI_FLAG_8BIT) {
                src8 = (u8*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + el->width - scrollAmt - 1;
                ptr8 = (u8*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + el->width - 1;
                for (i = el->height; i > 0; i--) {
                    for (j = el->width - scrollAmt; j > 0; j--) {
                        *ptr8 = *src8;
                        src8--;
                        ptr8--;
                    }
                    ptr8 += el->imageWidth + el->width - scrollAmt;
                    src8 += el->imageWidth + el->width - scrollAmt;
                }
            } else if (el->flags & UI_FLAG_32BIT) {
                src32 = (u32*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + el->width - scrollAmt - 1;
                ptr32 = (u32*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + el->width - 1;
                for (i = el->height; i > 0; i--) {
                    for (j = el->width - scrollAmt; j > 0; j--) {
                        *ptr32 = *src32;
                        src32--;
                        ptr32--;
                    }
                    ptr32 += el->imageWidth + el->width - scrollAmt;
                    src32 += el->imageWidth + el->width - scrollAmt;
                }
            } else {
                src16 = (u16*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + el->width - scrollAmt - 1;
                ptr16 = (u16*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + el->width - 1;
                for (i = el->height; i > 0; i--) {
                    for (j = el->width - scrollAmt; j > 0; j--) {
                        *ptr16 = *src16;
                        src16--;
                        ptr16--;
                    }
                    ptr16 += el->imageWidth + el->width - scrollAmt;
                    src16 += el->imageWidth + el->width - scrollAmt;
                }
            }
            UIElement_FillRect(el, 0, 0, scrollAmt - 1, el->height, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
            break;
        case 3:
            if (el->flags & UI_FLAG_8BIT) {
                src8 = (u8*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + scrollAmt;
                ptr8 = (u8*) el->image + el->imageWidth * el->borderHeight + el->borderWidth;
                for (i = el->height; i > 0; i--) {
                    for (j = el->width - scrollAmt; j > 0; j--) {
                        *ptr8 = *src8;
                        src8++;
                        ptr8++;
                    }
                    ptr8 += el->imageWidth + el->width - scrollAmt;
                    src8 += el->imageWidth + el->width - scrollAmt;
                }
            } else if (el->flags & UI_FLAG_32BIT) {
                src32 = (u32*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + scrollAmt;
                ptr32 = (u32*) el->image + el->imageWidth * el->borderHeight + el->borderWidth;
                for (i = el->height; i > 0; i--) {
                    for (j = el->width - scrollAmt; j > 0; j--) {
                        *ptr32 = *src32;
                        src32++;
                        ptr32++;
                    }
                    ptr32 += el->imageWidth + el->width - scrollAmt;
                    src32 += el->imageWidth + el->width - scrollAmt;
                }
            } else {
                src16 = (u16*) el->image + el->imageWidth * el->borderHeight + el->borderWidth + scrollAmt;
                ptr16 = (u16*) el->image + el->imageWidth * el->borderHeight + el->borderWidth;
                for (i = el->height; i > 0; i--) {
                    for (j = el->width - scrollAmt; j > 0; j--) {
                        *ptr16 = *src16;
                        src16++;
                        ptr16++;
                    }
                    ptr16 += el->imageWidth - el->width + scrollAmt;
                    src16 += el->imageWidth - el->width + scrollAmt;
                }
            }
            UIElement_FillRect(el, el->width - scrollAmt, 0, el->width - 1, el->height, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
            break;
    }
}

void UIElement_VertScroll(UIElement* el, s32 scrollAmt, s32 direction, s32 x1, s32 y1, s32 x2, s32 y2) {
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

    if (x1 > el->width) {
        x1 = el->width;
    }
    if (y1 > el->height) {
        y1 = el->height;
    }
    if (x2 > el->width) {
        x2 = el->width;
    }
    if (y2 > el->height) {
        y2 = el->height;
    }

    fillWidth = x2 - x1;
    fillHeight = y2 - y1 - scrollAmt;

    switch (direction) {
        case 0:
            if (el->flags & UI_FLAG_8BIT) {
                for (i = 0; i <= fillHeight; i++) {
                    u8* src = (u8*) el->image + el->imageWidth * (el->borderHeight + scrollAmt + i) + el->borderWidth + x1;
                    u8* dst = (u8*) el->image + el->imageWidth * (el->borderHeight + i) + el->borderWidth + x1;
                    for (j = el->width; j > 0; j--) {
                        *dst = *src;
                        src++;
                        dst++;
                    }
                }
            } else if (el->flags & UI_FLAG_32BIT) {
                for (i = 0; i <= fillHeight; i++) {
                    u32* src = (u32*) el->image + el->imageWidth * (el->borderHeight + scrollAmt + i) + el->borderWidth;
                    u32* dst = (u32*) el->image + el->imageWidth * (el->borderHeight + i) + el->borderWidth;
                    for (j = 0; j <= fillWidth; j++) {
                        *dst = *src;
                        src++;
                        dst++;
                    }
                }
            } else {
                for (i = 0; i <= fillHeight; i++) {
                    u16* src = (u16*) el->image + el->imageWidth * (el->borderHeight + scrollAmt + i) + el->borderWidth + x1;
                    u16* dst = (u16*) el->image + el->imageWidth * (el->borderHeight + i) + el->borderWidth + x1;
                    for (j = 0; j <= fillWidth; j++) {
                        *dst = *src;
                        src++;
                        dst++;
                    }
                }
            }
            UIElement_FillRect(el, x1, y2 - scrollAmt, x2, y2, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
            break;
        case 1:
            if (el->flags & UI_FLAG_8BIT) {
                u8* src = (u8*) el->image + el->imageWidth * (el->borderHeight + el->height - scrollAmt - 1) + el->borderWidth;
                u8* dst = (u8*) el->image + el->imageWidth * (el->borderHeight + el->height - 1) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *dst = *src;
                        src++;
                        dst++;
                    }
                    dst -= el->imageWidth + el->width;
                    src -= el->imageWidth + el->width;
                }
            } else if (el->flags & UI_FLAG_32BIT) {
                u32* src = (u32*) el->image + el->imageWidth * (el->borderHeight + el->height - scrollAmt - 1) + el->borderWidth;
                u32* dst = (u32*) el->image + el->imageWidth * (el->borderHeight + el->height - 1) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *dst = *src;
                        src++;
                        dst++;
                    }
                    dst -= el->imageWidth + el->width;
                    src -= el->imageWidth + el->width;
                }
            } else {
                u16* src = (u16*) el->image + el->imageWidth * (el->borderHeight + el->height - scrollAmt - 1) + el->borderWidth;
                u16* dst = (u16*) el->image + el->imageWidth * (el->borderHeight + el->height - 1) + el->borderWidth;
                for (i = el->height - scrollAmt; i > 0; i--) {
                    for (j = el->width; j > 0; j--) {
                        *dst = *src;
                        src++;
                        dst++;
                    }
                    dst -= el->imageWidth + el->width;
                    src -= el->imageWidth + el->width;
                }
            }
            UIElement_FillRect(el, 0, 0, el->width, scrollAmt, el->bgColor.r, el->bgColor.g, el->bgColor.b, el->bgColor.a);
            break;
        case 2:
            break;
        case 3:
            break;
    }
}

void UIElement_PrintText(UIElement* el, char* str) {
    UNUSED s32 pad[6];
    ucolor a1;
    ucolor a2;

    if (str == NULL) {
        return;
    }

    UIText_SetFont(el->text.font);
    el->text.width = el->imageWidth;
    el->text.image = el->image + (el->imageWidth * el->borderHeight + el->borderWidth) * el->bpp;
    el->text.bpp = el->bpp;
    el->text.height = el->height;
    el->text.screenX = el->x + el->borderWidth;
    el->text.screenY = el->y + el->borderHeight;
    if (el->flags & UI_FLAG_GRAYSCALE) {
        a1 = UIElement_WhiteColor;
        a2 = UIElement_TransparentWhiteColor;
        a1.a = el->fgColor.a;
        a2.a = el->bgColor.a;
        UIText_MakePalettes(&el->text, &a1, &a2);
    } else {
        UIText_MakePalettes(&el->text, &el->fgColor, &el->bgColor);
    }

    UIText_PrintString(&el->text, &el->text.curX, &el->text.curY, str);

    osWritebackDCache(el->bitmaps, el->imageWidth * el->height); // doesn't make sense
}

void UIElement_PrintAsciiString(UIElement* el, char* str) {
    UNUSED s32 pad[6];
    ucolor fgColor;
    ucolor bgColor;

    if (str == NULL) {
        return;
    }

    UIText_SetFont(el->text.font);
    el->text.width = el->imageWidth;
    el->text.image = el->image + (el->imageWidth * el->borderHeight + el->borderWidth) * el->bpp;
    el->text.bpp = el->bpp;
    el->text.height = el->height;
    el->text.screenX = el->x + el->borderWidth;
    el->text.screenY = el->y + el->borderHeight;
    if (el->flags & UI_FLAG_GRAYSCALE) {
        fgColor = UIElement_WhiteColor;
        bgColor = UIElement_TransparentWhiteColor;
        fgColor.a = el->fgColor.a;
        bgColor.a = el->bgColor.a;
        UIText_MakePalettes(&el->text, &fgColor, &bgColor);
    } else {
        UIText_MakePalettes(&el->text, &el->fgColor, &el->bgColor);
    }

    UIText_PrintAsciiString(&el->text, &el->text.curX, &el->text.curY, str);

    osWritebackDCache(el->bitmaps, el->imageWidth * el->height); // doesn't make sense
}

void UIElement_PrintChar(UIElement* el, s32 chr) {
    char str[2];

    str[0] = chr;
    str[1] = '\0';
    UIElement_PrintText(el, str);
}

void UIElement_SetScale(UIElement* el, f32 scalex, f32 scaley) {
    if (el != NULL && (el->flags & UI_FLAG_SCALABLE)) {
        el->spriteObj->data.sobj->sprite.scalex = scalex;
        el->spriteObj->data.sobj->sprite.scaley = scaley;
        el->sprite.scalex = scalex;
        el->sprite.scaley = scaley;
    }
}

void UIElement_SetTextStyle(UIElement* el, s32 style) {
    if (UIText_SetFont(style)) {
        return;
    }

    if (el) {
        el->text.font = style;
    } else {
        UIElement_CurrentFont = style;
    }
}

void UIElement_SetPos(UIElement* el, s32 x, s32 y) {
    if (el == NULL) {
        return;
    }

    el->x = x;
    el->y = y;
    el->sprite.x = x - el->borderWidth;
    el->sprite.y = y - el->borderHeight;
    if (!(el->flags & UI_FLAG_SHOW_ALT)) {
        el->spriteObj->data.sobj->sprite.x = el->sprite.x;
        el->spriteObj->data.sobj->sprite.y = el->sprite.y;
    }
}

void UIElement_SetAltPos(UIElement* el, s32 x, s32 y) {
    if (el == NULL) {
        return;
    }

    el->altX = x;
    el->altY = y;
    el->altSprite.x = x;
    el->altSprite.y = y;
    if (el->flags & UI_FLAG_SHOW_ALT) {
        el->spriteObj->data.sobj->sprite.x = el->altSprite.x;
        el->spriteObj->data.sobj->sprite.y = el->altSprite.y;
    }
}

void UIElement_SetAltSprite(UIElement* el, Sprite* sprite) {
    if (el != NULL && sprite != NULL) {
        el->altWidth = sprite->width;
        el->altHeight = sprite->height;

        el->altSprite = *sprite;

        el->altSprite.x = el->altX;
        el->altSprite.y = el->altY;

        if (el->flags & UI_FLAG_SHOW_ALT) {
            el->spriteObj->data.sobj->sprite.x = el->altSprite.x;
            el->spriteObj->data.sobj->sprite.y = el->altSprite.y;
        }
    }
}

void UIElement_ShowAltSprite(UIElement* el, s32 isAlt) {
    if (el != NULL) {
        if (isAlt) {
            el->spriteObj->data.sobj->sprite = el->altSprite;
            el->flags |= UI_FLAG_SHOW_ALT;
        } else {
            el->spriteObj->data.sobj->sprite = el->sprite;
            el->flags &= ~UI_FLAG_SHOW_ALT;
        }
    }
}

void UIElement_DrawImage(UIElement* arg0, s32 x, s32 y, s32 width, s32 height, u8* image) {
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

    if (arg0->flags & UI_FLAG_8BIT) {
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
    } else if (arg0->flags & UI_FLAG_32BIT) {
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

UIElement* UIElement_GetList(void) {
    return UIElement_ListHead;
}

UIElement* UIElement_GetNext(UIElement* el) {
    if (el == NULL) {
        return NULL;
    }
    return el->next;
}

void UIElement_MoveToHead(UIElement* el) {
    GObj* gobj;

    if (UIElement_ListHead != NULL && el != UIElement_ListHead && el != NULL) {
        gobj = el->spriteObj;
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
        UIElement_Unlink(el);
        UIElement_LinkHead(el);
    }
}

void UIElement_MoveToTail(UIElement* el) {
    GObj* gobj;

    if (UIElement_ListHead != NULL && el != UIElement_ListHead && el != NULL) {
        gobj = el->spriteObj;
        omMoveGObjDLHead(gobj, gobj->dlLink, gobj->dlPriority);
        UIElement_Unlink(el);
        UIElement_LinkTail(el);
    }
}

UIElement* UIElement_CreateText(s32 x, s32 y, char* str, s32 font, s32 flags) {
    UIElement* el;
    s32 temp_s0;

    UIText_SetFont(font);
    temp_s0 = UIText_GetStringWidth(str);
    // TODO: look into a "ceil to multiple of" macro
    el = UIElement_Create(x, y, (temp_s0 + 1 + 0xF) & ~0xF, ((UIText_GetCharsWidth() + 1) & ~1) + 4, flags);
    UIElement_SetTextStyle(el, font);
    UIElement_DrawBackground(el);
    UIElement_SetTextPos(el, 0, 0);
    UIElement_PrintText(el, str);

    return el;
}

void UIElement_SetState(UIElement* el, s32 state) {
    if (el == NULL) {
        return;
    }

    func_8036EFEC_84279C(state, el->x, el->y, el->x + el->width, el->y + el->height);

    if (state != UI_NORMAL) {
        el->spriteObj->data.sobj->sprite.attr |= SP_HIDDEN;
    } else {
        el->spriteObj->data.sobj->sprite.attr &= ~SP_HIDDEN;
    }
}

GObj* UIElement_GetGObj(UIElement* arg0) {
    if (arg0 == NULL) {
        return NULL;
    }

    return arg0->spriteObj;
}

void UIElement_SetSpriteColor(UIElement* el, s32 r, s32 g, s32 b, s32 a) {
    if (el != NULL) {
        el->spriteObj->data.sobj->sprite.red = r;
        el->spriteObj->data.sobj->sprite.green = g;
        el->spriteObj->data.sobj->sprite.blue = b;
        el->spriteObj->data.sobj->sprite.alpha = a;
    }
}

s32 UIElement_GetWidth(UIElement* el) {
    return el->width;
}
