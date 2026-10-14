#include "common.h"

extern Gfx D_80169EF0_A95200[NUM_DL(1)];

Gfx D_80117FE0_A93390[] = {
#include "build/assets/native/gfx/D_80117FE0_A93390.dl.inc.c"
};

u8 D_80117FE8_A93398[] = {
#include "assets/menu_new_game/cursor.png.bin.c"
};

Bitmap D_80118058_A93408[] = {
    { 4, 4, 0, 0, D_80117FE8_A93398, 14, 0 },
};

Sprite D_80118068_A93418 = {
    0,                               /* x */
    0,                               /* y */
    4,                               /* width */
    14,                              /* height */
    1.0f,                            /* scalex */
    1.0f,                            /* scaley */
    0,                               /* expx */
    0,                               /* expy */
    SP_TEXSHUF | SP_FASTCOPY | SP_Z, /* attr */
    0x1234,                          /* zdepth */
    0xFF,                            /* red */
    0xFF,                            /* green */
    0xFF,                            /* blue */
    0xFF,                            /* alpha */
    0,                               /* startTLUT */
    0,                               /* nTLUT */
    NULL,                            /* LUT */
    0,                               /* istart */
    1,                               /* istep */
    1,                               /* nbitmaps */
    NUM_DL(1),                       /* ndisplist */
    14,                              /* bmheight */
    14,                              /* bmHreal */
    G_IM_FMT_RGBA,                   /* bmfmt */
    G_IM_SIZ_16b,                    /* bmsiz */
    D_80118058_A93408,               /* bitmap */
    D_80169EF0_A95200,               /* rsp_dl */
    NULL,                            /* rsp_dl_next */
    0,                               /* frac_s */
    0,                               /* frac_t */
};

static u32 sprite_cursor_padding = 0;
