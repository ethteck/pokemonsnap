#include "common.h"

extern u8 D_801B02F0_13C780[]; // TODO: remove after splat is fixed

extern u8 grimer_tex_80154258[];
extern u8 grimer_tex_80155260[];
extern u8 grimer_tex_80156268[];
extern u8 grimer_tex_80156A70[];
extern u8 grimer_tex_80156A98_png[];

extern Texture* grimer_hd_part1_mat[];
extern Texture* grimer_hd_part2_mat[];
extern Texture* grimer_hd_part3_mat[];
extern Texture* grimer_hd_part4_mat[];
extern Texture* grimer_hd_part5_mat[];
extern Texture* grimer_hd_part6_mat[];
extern Texture* grimer_hd_part7_mat[];
extern Texture* grimer_hd_part8_mat[];
extern Texture* grimer_hd_part9_mat[];
extern Texture* grimer_hd_part10_mat[];
extern Texture* grimer_hd_part11_mat[];
extern Texture* grimer_hd_part12_mat[];
extern Texture* grimer_hd_part13_mat[];
extern Texture* grimer_hd_part14_mat[];
extern Texture* grimer_hd_part15_mat[];
extern Texture* grimer_hd_part17_mat[];
extern Gfx grimer_hd_part0_draw[];

Texture** grimer_hd_materials[] = {
    NULL,
    grimer_hd_part1_mat,
    grimer_hd_part2_mat,
    grimer_hd_part3_mat,
    grimer_hd_part4_mat,
    grimer_hd_part5_mat,
    grimer_hd_part6_mat,
    grimer_hd_part7_mat,
    grimer_hd_part8_mat,
    grimer_hd_part9_mat,
    grimer_hd_part10_mat,
    grimer_hd_part11_mat,
    grimer_hd_part12_mat,
    grimer_hd_part13_mat,
    grimer_hd_part14_mat,
    grimer_hd_part15_mat,
    NULL,
    grimer_hd_part17_mat,
    NULL,
};

u8* grimer_hd_part1_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part2_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part3_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part4_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part5_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part6_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part7_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part8_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part9_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part10_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part11_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part12_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part13_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part14_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part15_mat0_textures[] = {
    grimer_tex_80156268,
};

u8* grimer_hd_part17_mat0_textures[] = {
    grimer_tex_80156268,
    NULL,
};

Texture grimer_hd_part1_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part1_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part2_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part2_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part3_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part3_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part4_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part4_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part5_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part5_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part6_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part6_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part7_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part7_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part8_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part8_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part9_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part9_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part10_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part10_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part11_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part11_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part12_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part12_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part13_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part13_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part14_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part14_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part15_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part15_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture grimer_hd_part17_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    grimer_hd_part17_mat0_textures,
    128,
    64,
    96,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    96,
    64,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* grimer_hd_part1_mat[] = {
    &grimer_hd_part1_mat0,
    NULL,
};

Texture* grimer_hd_part2_mat[] = {
    &grimer_hd_part2_mat0,
    NULL,
};

Texture* grimer_hd_part3_mat[] = {
    &grimer_hd_part3_mat0,
    NULL,
};

Texture* grimer_hd_part4_mat[] = {
    &grimer_hd_part4_mat0,
    NULL,
};

Texture* grimer_hd_part5_mat[] = {
    &grimer_hd_part5_mat0,
    NULL,
};

Texture* grimer_hd_part6_mat[] = {
    &grimer_hd_part6_mat0,
    NULL,
};

Texture* grimer_hd_part7_mat[] = {
    &grimer_hd_part7_mat0,
    NULL,
};

Texture* grimer_hd_part8_mat[] = {
    &grimer_hd_part8_mat0,
    NULL,
};

Texture* grimer_hd_part9_mat[] = {
    &grimer_hd_part9_mat0,
    NULL,
};

Texture* grimer_hd_part10_mat[] = {
    &grimer_hd_part10_mat0,
    NULL,
};

Texture* grimer_hd_part11_mat[] = {
    &grimer_hd_part11_mat0,
    NULL,
};

Texture* grimer_hd_part12_mat[] = {
    &grimer_hd_part12_mat0,
    NULL,
};

Texture* grimer_hd_part13_mat[] = {
    &grimer_hd_part13_mat0,
    NULL,
};

Texture* grimer_hd_part14_mat[] = {
    &grimer_hd_part14_mat0,
    NULL,
};

Texture* grimer_hd_part15_mat[] = {
    &grimer_hd_part15_mat0,
    NULL,
};

Texture* grimer_hd_part17_mat[] = {
    &grimer_hd_part17_mat0,
    NULL,
};

#include "assets/cave/grimer/hd_model.vtx.inc.c"
#include "assets/cave/grimer/hd_first.gfx.inc.c"
#include "assets/cave/grimer/hd_part0_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part1_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part1_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part2_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part3_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part3_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part4_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part4_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part5_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part5_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part6_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part7_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part7_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part8_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part8_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part9_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part9_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part10_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part11_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part12_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part12_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part13_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part14_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part15_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part16_pre.gfx.inc.c"
#include "assets/cave/grimer/hd_part16_draw.gfx.inc.c"
#include "assets/cave/grimer/hd_part17_draw.gfx.inc.c"

DObjPayloadTypeI grimer_hd_gfxdata[] = {
    { NULL, grimer_hd_first },
    { grimer_hd_part1_pre, grimer_hd_part1_draw },
    { NULL, grimer_hd_part2_draw },
    { grimer_hd_part3_pre, grimer_hd_part3_draw },
    { grimer_hd_part4_pre, grimer_hd_part4_draw },
    { grimer_hd_part5_pre, grimer_hd_part5_draw },
    { NULL, grimer_hd_part6_draw },
    { grimer_hd_part7_pre, grimer_hd_part7_draw },
    { grimer_hd_part8_pre, grimer_hd_part8_draw },
    { grimer_hd_part9_pre, grimer_hd_part9_draw },
    { NULL, grimer_hd_part10_draw },
    { NULL, grimer_hd_part11_draw },
    { grimer_hd_part12_pre, grimer_hd_part12_draw },
    { NULL, grimer_hd_part13_draw },
    { NULL, grimer_hd_part14_draw },
    { NULL, grimer_hd_part15_draw },
    { grimer_hd_part16_pre, grimer_hd_part16_draw },
    { NULL, grimer_hd_part17_draw },
};

UnkEC64Arg3 grimer_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &grimer_hd_gfxdata[0],
      { -45.6797981262207, 48.3671989440918, -67.58760070800781 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &grimer_hd_gfxdata[1],
      { 2.3145968914031982, 78.00299835205078, -3.494096040725708 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &grimer_hd_gfxdata[2],
      { 52.88261795043945, 77.8835678100586, 62.78533935546875 },
      { 0.0, 0.05999999865889549, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &grimer_hd_gfxdata[3],
      { -2.075439929962158, 60.89093780517578, 237.7183380126953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &grimer_hd_gfxdata[4],
      { 3.007396936416626, 130.2604217529297, 17.488706588745117 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &grimer_hd_gfxdata[5],
      { 330.9675598144531, 226.71380615234375, 53.02265930175781 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &grimer_hd_gfxdata[6],
      { 54.348228454589844, 127.80160522460938, 75.66791534423828 },
      { 0.0, 0.0, 0.0 },
      { 1.0099999904632568, 1.0, 1.0099999904632568 } },
    { 7,
      &grimer_hd_gfxdata[7],
      { -15.192031860351562, 92.45357513427734, 47.21398162841797 },
      { 0.0, 0.0, 0.0 },
      { 0.9900990128517151, 1.0, 0.9900990128517151 } },
    { 7,
      &grimer_hd_gfxdata[8],
      { 9.250688552856445, -41.40329360961914, 129.37713623046875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &grimer_hd_gfxdata[9],
      { -278.47479248046875, 229.02120971679688, 36.39888000488281 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &grimer_hd_gfxdata[10],
      { -97.18859100341797, 114.8805160522461, 68.34007263183594 },
      { 0.0, 0.0, 0.0 },
      { 1.0099999904632568, 1.0, 1.0099999904632568 } },
    { 7,
      &grimer_hd_gfxdata[11],
      { -32.470584869384766, 103.7943344116211, 60.61433410644531 },
      { 0.0, 0.0, 0.0 },
      { 0.9900990128517151, 1.0, 0.9900990128517151 } },
    { 5,
      &grimer_hd_gfxdata[12],
      { 7.600909233093262, 301.2770690917969, 202.38922119140625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &grimer_hd_gfxdata[13],
      { -4.102812767028809, -82.11326599121094, 47.63209915161133 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &grimer_hd_gfxdata[14],
      { 50.85847854614258, -148.366455078125, 154.1180877685547 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &grimer_hd_gfxdata[15],
      { -4.539422988891602, 106.10499572753906, 155.66062927246094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &grimer_hd_gfxdata[16],
      { 43.520198822021484, 0.18160000443458557, -6.530099868774414 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32769,
      &grimer_hd_gfxdata[17],
      { 159.3376922607422, 202.25198364257812, 406.3636169433594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
