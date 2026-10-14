#include "common.h"

// Complete ambient/directional states share the SDK's aligned Lights1 layout.
Lights1 D_800AEBD0 = gdSPDefLights1(100, 100, 100, 180, 180, 180, 30, 30, 30);
Lights1 D_800AEBE8 = gdSPDefLights1(0, 0, 0, 0, 0, 0, 30, 30, 30);
static s32 D_800AEC00 = 1500;
static s32 D_800AEC04 = 2000;
s32 D_800AEC08 = 200;
s32 D_800AEC0C = 200;
s32 D_800AEC10 = 200;
static s32 padding1[] = { 0 };

Gfx D_800AEC18[] = {
#include "build/assets/native/gfx/D_800AEC18.dl.inc.c"
};
static s32 padding2[] = { 0, 0 };

// IDO word-aligns the byte/halfword globals; Vtx supplies the final 8-byte alignment.
u8 fx_colorDitherMode = G_CD_MAGICSQ;
u8 fx_alphaDitherMode = G_AD_PATTERN;
u16 fx_currentEffectID = 0;

// Full-screen fade quad, circular iris, and star iris geometry.
Vtx D_800AEC70[] = {
#include "assets/native/vertices/D_800AEC70.vtx.inc.c"
};

Gfx D_800AECB0[] = {
#include "build/assets/native/gfx/D_800AECB0.dl.inc.c"
};

Vtx D_800AECE0[] = {
#include "assets/native/vertices/D_800AECE0.vtx.inc.c"
};

Gfx D_800AEEE0[] = {
#include "build/assets/native/gfx/D_800AEEE0.dl.inc.c"
};

Vtx D_800AEF80[] = {
#include "assets/native/vertices/D_800AEF80.vtx.inc.c"
};

Gfx D_800AF020[] = {
#include "build/assets/native/gfx/D_800AF020.dl.inc.c"
};

s32 D_800AF050 = false;
s32 D_800AF054 = 0; // Fade primitive red.
s32 D_800AF058 = 0; // Fade primitive green.
s32 D_800AF05C = 0; // Fade primitive blue.
s32 D_800AF060 = 0; // Fade primitive alpha.

static Vec3f D_800AF064[] = {
    { 0.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f },
};
Vec3f D_800AF094 = { -1.0f, 0.0f, 0.0f };
static Vec3f D_800AF0A0[] = {
    { 0.0f, -1.0f, 0.0f },
    { 0.0f, 0.0f, -1.0f },
    { 0.0f, 0.0f, 0.0f },
};
Vec3f D_800AF0C4 = { 0.0f, 0.0f, 0.0f };
static s32 padding6[] = { 0 };

s32 D_800AF0D4 = 0;

typedef struct Rect {
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;
} Rect;

// Seven-segment character strokes followed by the optional decimal point.
Rect D_800AF0D8[] = {
    { 0, 0, 3, 0 },
    { 0, 0, 0, 3 },
    { 3, 0, 3, 3 },
    { 0, 3, 3, 3 },
    { 0, 3, 0, 6 },
    { 3, 3, 3, 6 },
    { 0, 6, 3, 6 },
    { 5, 6, 5, 6 },
};

// Hexadecimal characters and the minus sign, each with eight stroke flags.
s32 D_800AF158[17][8] = {
    { 1, 1, 1, 0, 1, 1, 1, 0 }, // 0
    { 0, 0, 1, 0, 0, 1, 0, 0 }, // 1
    { 1, 0, 1, 1, 1, 0, 1, 0 }, // 2
    { 1, 0, 1, 1, 0, 1, 1, 0 }, // 3
    { 0, 1, 1, 1, 0, 1, 0, 0 }, // 4
    { 1, 1, 0, 1, 0, 1, 1, 0 }, // 5
    { 1, 1, 0, 1, 1, 1, 1, 0 }, // 6
    { 1, 0, 1, 0, 0, 1, 0, 0 }, // 7
    { 1, 1, 1, 1, 1, 1, 1, 0 }, // 8
    { 1, 1, 1, 1, 0, 1, 1, 0 }, // 9
    { 1, 1, 1, 1, 1, 1, 0, 0 }, // A
    { 0, 1, 0, 1, 1, 1, 1, 0 }, // B
    { 0, 0, 0, 1, 1, 0, 1, 0 }, // C
    { 0, 0, 1, 1, 1, 1, 1, 0 }, // D
    { 1, 1, 0, 1, 1, 0, 1, 0 }, // E
    { 1, 1, 0, 1, 1, 0, 0, 0 }, // F
    { 0, 0, 0, 1, 0, 0, 0, 0 }, // Minus sign
};

// Decimal-place multipliers used by the fixed-point number renderer.
f32 D_800AF378[10] = { 1.0f, 10.0f, 100.0f, 1000.0f, 10000.0f, 100000.0f, 1000000.0f, 10000000.0f, 100000000.0f, 1000000000.0f };
