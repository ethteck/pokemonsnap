#include "world/world.h"

extern Gfx volcano_skybox_gfx[];

SkyBox volcano_skybox = {
    volcano_skybox_gfx,
    drawSkyBox1Cycle,
    NULL,
    NULL,
    0.0f,
};

static u32 padding[] = { 0, 0, 0, 0, 0 };

u8 volcano_skybox_texture[] = {
#include "assets/volcano/skybox.png.bin.c"
};

#include "assets/volcano/skybox.vtx.inc.c"
#include "assets/volcano/skybox.gfx.inc.c"
