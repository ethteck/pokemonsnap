#include "common.h"
#include "window.h"

extern Sprite D_80380C88_854438;
extern Bitmap* D_803818B0_855060[3][9];
extern UIFrame D_803A6A10_87A1C0;

void UIFrame_ShowBackground(UIFrame* f, bool show) {
    if (show) {
        f->sprites[6]->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        f->sprites[6]->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

void UIFrame_Show(UIFrame* f, bool show) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(f->sprites); i++) {
        if (show) {
            f->sprites[i]->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            f->sprites[i]->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void UIFrame_SetOpacity(UIFrame* f, s32 opacity) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(f->sprites); i++) {
        f->sprites[i]->data.sobj->sprite.alpha = opacity;
    }
}

void UIFrame_SetPos(UIFrame* f, s32 x, s32 y) {
    s16 temp_v0;
    u16 new_var;

    f->x = x;
    f->y = y;

    f->sprites[1]->data.sobj->sprite.x = x;
    f->sprites[7]->data.sobj->sprite.x = x;
    f->sprites[2]->data.sobj->sprite.x = x;

    temp_v0 = ((f->sprites[2]->data.sobj->sprite.scalex * 8.0f) + x) - 1.0f;
    f->sprites[8]->data.sobj->sprite.x = temp_v0;
    f->sprites[6]->data.sobj->sprite.x = temp_v0;
    f->sprites[5]->data.sobj->sprite.x = temp_v0;

    temp_v0 = (f->width + x) - 8;
    new_var = temp_v0;
    // required to match
    f->sprites[3]->data.sobj->sprite.x = new_var;
    f->sprites[0]->data.sobj->sprite.x = new_var;
    f->sprites[4]->data.sobj->sprite.x = new_var;

    f->sprites[4]->data.sobj->sprite.y = y;
    f->sprites[5]->data.sobj->sprite.y = y;
    f->sprites[2]->data.sobj->sprite.y = y;

    temp_v0 = ((f->sprites[2]->data.sobj->sprite.scaley * 8.0f) + y) - 1.0f;
    f->sprites[0]->data.sobj->sprite.y = temp_v0;
    f->sprites[6]->data.sobj->sprite.y = temp_v0;
    f->sprites[7]->data.sobj->sprite.y = temp_v0;

    temp_v0 = (f->height + y) - 8;
    f->sprites[3]->data.sobj->sprite.y = temp_v0;
    f->sprites[8]->data.sobj->sprite.y = temp_v0;
    f->sprites[1]->data.sobj->sprite.y = temp_v0;
}

void UIFrame_SetSize(UIFrame* f, s32 width, s32 height) {
    f32 temp_f0;
    f32 eight;
    s32 i;

    if (width < 6) {
        width = 6;
    } else if (width > SCREEN_WIDTH) {
        width = SCREEN_WIDTH;
    }
    if (height < 6) {
        height = 6;
    } else if (height > SCREEN_HEIGHT) {
        height = SCREEN_HEIGHT;
    }

    f->width = width;
    f->height = height;

    eight = 8.0f;

    if (width >= 24) {
        f->sprites[7]->data.sobj->sprite.scalex = 1.0f;
        temp_f0 = f->sprites[7]->data.sobj->sprite.scalex;
        f->sprites[0]->data.sobj->sprite.scalex = temp_f0;
        f->sprites[1]->data.sobj->sprite.scalex = temp_f0;
        f->sprites[3]->data.sobj->sprite.scalex = temp_f0;
        f->sprites[2]->data.sobj->sprite.scalex = temp_f0;
        f->sprites[4]->data.sobj->sprite.scalex = temp_f0;
        f->sprites[6]->data.sobj->sprite.scalex = (width - 14) / eight;
        f->sprites[8]->data.sobj->sprite.scalex = (width - 14) / eight;
        f->sprites[5]->data.sobj->sprite.scalex = (width - 14) / eight;
    } else {
        for (i = 0; i < ARRAY_COUNT(f->sprites); i++) {
            f->sprites[i]->data.sobj->sprite.scalex = width / 24.0f;
        }
    }
    if (height >= 24) {
        f->sprites[8]->data.sobj->sprite.scaley = 1.0f;
        temp_f0 = f->sprites[8]->data.sobj->sprite.scaley;
        f->sprites[5]->data.sobj->sprite.scaley = temp_f0;
        f->sprites[1]->data.sobj->sprite.scaley = temp_f0;
        f->sprites[3]->data.sobj->sprite.scaley = temp_f0;
        f->sprites[2]->data.sobj->sprite.scaley = temp_f0;
        f->sprites[4]->data.sobj->sprite.scaley = temp_f0;
        f->sprites[6]->data.sobj->sprite.scaley = (height - 14) / eight;
        f->sprites[7]->data.sobj->sprite.scaley = (height - 14) / eight;
        f->sprites[0]->data.sobj->sprite.scaley = (height - 14) / eight;
    } else {
        for (i = 0; i < ARRAY_COUNT(f->sprites); i++) {
            f->sprites[i]->data.sobj->sprite.scaley = height / 24.0f;
        }
    }
    UIFrame_SetPos(f, f->x, f->y);
}

void UIFrame_SetStyle(UIFrame* f, s32 style) {
    s32 i;

    f->style = style;
    if (style < FRAME_STYLE_0) {
        style = FRAME_STYLE_0;
    } else if ((u32) style > FRAME_STYLE_2) {
        // FRAME_STYLE_2 and FRAME_STYLE_3 have same palette
        style = FRAME_STYLE_2;
    }

    for (i = 0; i < ARRAY_COUNT(f->sprites); i++) {
        D_803A6A10_87A1C0.sprites[i]->data.sobj->sprite.bitmap = D_803818B0_855060[style][i];
    }
}

void UIFrame_GetBackgroundColor(UIFrame* f, ucolor* color) {
    u16 bg_first_pixel;

    bg_first_pixel = *(u16*) (D_803A6A10_87A1C0.sprites[6]->data.sobj->sprite.bitmap->buf);
    color->r = (bg_first_pixel >> 8) & 0xF8;
    color->g = (bg_first_pixel >> 3) & 0xF8;
    color->b = (bg_first_pixel << 2) & 0xF8;
    color->a = (bg_first_pixel & 1) * 0xFF;
}

UIFrame* UIFrame_Create(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803A6A10_87A1C0.sprites); i++) {
        D_803A6A10_87A1C0.sprites[i] = func_800A9F10(0, 6, &D_80380C88_854438);
        if (D_803A6A10_87A1C0.sprites[i] == NULL) {
            return NULL;
        }
        D_803A6A10_87A1C0.sprites[i]->data.sobj->sprite.bitmap = D_803818B0_855060[0][i];
        D_803A6A10_87A1C0.sprites[i]->data.sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
        D_803A6A10_87A1C0.sprites[i]->data.sobj->sprite.x = 80;
        D_803A6A10_87A1C0.sprites[i]->data.sobj->sprite.y = 80;
    }
    D_803A6A10_87A1C0.x = 60;
    D_803A6A10_87A1C0.y = 60;
    D_803A6A10_87A1C0.style = 0;
    D_803A6A10_87A1C0.unk_38 = 1;
    UIFrame_SetSize(&D_803A6A10_87A1C0, 204, 56);
    return &D_803A6A10_87A1C0;
}
