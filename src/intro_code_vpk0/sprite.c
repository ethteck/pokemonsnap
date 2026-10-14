#include "common.h"

extern Gfx D_802BC110_intro_code_vpk0[NUM_DL(8)];

/* Payload order: eight end-list/image pairs, Bitmap[8], Sprite, then
 * twelve zero alignment bytes. All image rows use SP_TEXSHUF word order.
 * The display-list workspace begins at the end of the decompressed data;
 * it is writable storage, not a pointer object or compressed payload data.
 */
Gfx D_802B5000_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802B5000_intro_code_vpk0.dl.inc.c"
};

u8 D_802B5008_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_00.png.bin.c"
};

Gfx D_802B6008_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802B6008_intro_code_vpk0.dl.inc.c"
};

u8 D_802B6010_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_01.png.bin.c"
};

Gfx D_802B7010_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802B7010_intro_code_vpk0.dl.inc.c"
};

u8 D_802B7018_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_02.png.bin.c"
};

Gfx D_802B8018_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802B8018_intro_code_vpk0.dl.inc.c"
};

u8 D_802B8020_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_03.png.bin.c"
};

Gfx D_802B9020_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802B9020_intro_code_vpk0.dl.inc.c"
};

u8 D_802B9028_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_04.png.bin.c"
};

Gfx D_802B9C28_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802B9C28_intro_code_vpk0.dl.inc.c"
};

u8 D_802B9C30_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_05.png.bin.c"
};

Gfx D_802BA830_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802BA830_intro_code_vpk0.dl.inc.c"
};

u8 D_802BA838_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_06.png.bin.c"
};

Gfx D_802BB438_intro_code_vpk0[] = {
#include "build/assets/native/gfx/D_802BB438_intro_code_vpk0.dl.inc.c"
};

u8 D_802BB440_intro_code_vpk0[] = {
#include "assets/intro_code_vpk0/tile_07.png.bin.c"
};

/* 0x802BC040..0x802BC0C0: four 32x64 tiles, then four 32x48 tiles. */
Bitmap D_802BC040_intro_code_vpk0[] = {
    { 32, 32, 0, 0, D_802B5008_intro_code_vpk0, 64, 0 },
    { 32, 32, 0, 0, D_802B6010_intro_code_vpk0, 64, 0 },
    { 32, 32, 0, 0, D_802B7018_intro_code_vpk0, 64, 0 },
    { 32, 32, 0, 0, D_802B8020_intro_code_vpk0, 64, 0 },
    { 32, 32, 0, 0, D_802B9028_intro_code_vpk0, 48, 0 },
    { 32, 32, 0, 0, D_802B9C30_intro_code_vpk0, 48, 0 },
    { 32, 32, 0, 0, D_802BA838_intro_code_vpk0, 48, 0 },
    { 32, 32, 0, 0, D_802BB440_intro_code_vpk0, 48, 0 },
};

/* 0x802BC0C0..0x802BC104: Sprite; its two ABI padding bytes are zero. */
Sprite D_802BC0C0_intro_code_vpk0 = {
    0,                               /* x */
    0,                               /* y */
    128,                             /* width */
    112,                             /* height */
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
    8,                               /* nbitmaps */
    NUM_DL(8),                       /* ndisplist */
    64,                              /* bmheight */
    64,                              /* bmHreal */
    G_IM_FMT_RGBA,                   /* bmfmt */
    G_IM_SIZ_16b,                    /* bmsiz */
    D_802BC040_intro_code_vpk0,      /* bitmap */
    D_802BC110_intro_code_vpk0,      /* rsp_dl */
    NULL,                            /* rsp_dl_next */
    0,                               /* frac_s */
    0,                               /* frac_t */
};

/* 0x802BC104..0x802BC110: explicit zero fill to the 16-byte payload end. */
static u32 sprite_padding[3] = { 0 };

/* 0x802BC110..0x802BC4D0: NOLOAD sprite display-list workspace. */
Gfx D_802BC110_intro_code_vpk0[NUM_DL(8)];
