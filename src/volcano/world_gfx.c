#include "world/world.h"

extern Gfx D_80101610_328290[];
extern Texture** D_80103790_32A410[];
extern AnimCmd** D_801038C0_32A540[];
extern UnkEC64Arg3 D_80103A30_32A6B0[];
extern AnimCmd* D_80103AE0_32A760[];

extern Gfx D_80103C80_32A900[];
extern Texture** D_801053A0_32C020[];
extern AnimCmd** D_80105440_32C0C0[];
extern UnkEC64Arg3 D_80105580_32C200[];
extern AnimCmd* D_80105630_32C2B0[];

extern Gfx D_80105860_32C4E0[];
extern UnkEC64Arg3 D_80106300_32CF80[];
extern AnimCmd* D_801063B0_32D030[];

extern Gfx D_801065F0_32D270[];
extern Texture** D_80109300_32FF80[];
extern AnimCmd** D_80109430_3300B0[];
extern UnkEC64Arg3 D_801095C0_330240[];
extern AnimCmd* D_80109670_3302F0[];

extern Gfx D_80109DE0_330A60[];
extern Texture** D_8010C730_3333B0[];
extern AnimCmd** D_8010C8F0_333570[];
extern UnkEC64Arg3 D_8010CA90_333710[];
extern AnimCmd* D_8010CB40_3337C0[];

extern Gfx D_8010CEE0_333B60[];
extern Texture** D_80110AF0_337770[];
extern AnimCmd** D_80110CB0_337930[];
extern UnkEC64Arg3 D_80110E50_337AD0[];
extern AnimCmd* D_80110F00_337B80[];

extern Gfx D_80111580_338200[];
extern Texture** D_80112260_338EE0[];
extern AnimCmd** D_80112300_338F80[];

WorldBlockGFX volcano_block0_gfx = {
    D_80101610_328290,
    D_80103790_32A410,
    D_801038C0_32A540,
    renderModelTypeAFogged,
    D_80103A30_32A6B0,
    3,
    D_80103AE0_32A760,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block1_gfx = {
    D_80103C80_32A900,
    D_801053A0_32C020,
    D_80105440_32C0C0,
    renderModelTypeAFogged,
    D_80105580_32C200,
    3,
    D_80105630_32C2B0,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block2_gfx = {
    D_80105860_32C4E0,
    NULL,
    NULL,
    renderModelTypeAFogged,
    D_80106300_32CF80,
    3,
    D_801063B0_32D030,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block3_gfx = {
    D_801065F0_32D270,
    D_80109300_32FF80,
    D_80109430_3300B0,
    renderModelTypeAFogged,
    D_801095C0_330240,
    3,
    D_80109670_3302F0,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block4_gfx = {
    D_80109DE0_330A60,
    D_8010C730_3333B0,
    D_8010C8F0_333570,
    renderModelTypeAFogged,
    D_8010CA90_333710,
    3,
    D_8010CB40_3337C0,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block5_gfx = {
    D_8010CEE0_333B60,
    D_80110AF0_337770,
    D_80110CB0_337930,
    renderModelTypeAFogged,
    D_80110E50_337AD0,
    3,
    D_80110F00_337B80,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_uvBlock0_gfx = {
    D_80111580_338200,
    D_80112260_338EE0,
    D_80112300_338F80,
    renderModelTypeAFogged,
    NULL,
    0,
    NULL,
    0,
    { 0.0f }
};

