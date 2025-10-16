#include "common.h"

extern u8 scyther_tex_801A8E88[];
extern u8 scyther_tex_801A8FB8_png[];
extern u8 scyther_tex_801A97C0[];
extern u8 scyther_tex_801A97E8_png[];
extern u8 scyther_tex_801A9BF0[];
extern u8 scyther_tex_801A9C18_png[];
extern u8 scyther_tex_801A9CA0[];
extern u8 scyther_tex_801A9CC8_png[];
extern u8 scyther_tex_801AA0D0[];
extern u8 scyther_tex_801AA0F0_png[];
extern u8 scyther_tex_801AA178[];
extern u8 scyther_tex_801AA1A0_png[];
extern u8 scyther_tex_801AA1E8[];
extern u8 scyther_tex_801AA210_png[];
extern u8 scyther_tex_801AA258[];
extern u8 scyther_tex_801AA460_png[];
extern u8 scyther_tex_801AA4E8[];
extern u8 scyther_tex_801AA5C8_png[];

#include "assets/beach/scyther/hd_model.vtx.inc.c"
#include "assets/beach/scyther/hd_part0_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part1_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part2_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part3_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part4_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part5_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part6_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part7_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part8_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part11_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part14_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part15_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part16_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part17_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part9_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part10_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part12_draw.gfx.inc.c"
#include "assets/beach/scyther/hd_part13_draw.gfx.inc.c"

DObjPayloadTypeC scyther_hd_gfxdata[] = {
    { 0, scyther_hd_part0_draw },
    { 4, NULL },
    { 0, scyther_hd_part1_draw },
    { 4, NULL },
    { 0, scyther_hd_part2_draw },
    { 4, NULL },
    { 0, scyther_hd_part3_draw },
    { 4, NULL },
    { 0, scyther_hd_part4_draw },
    { 4, NULL },
    { 0, scyther_hd_part5_draw },
    { 4, NULL },
    { 0, scyther_hd_part6_draw },
    { 4, NULL },
    { 0, scyther_hd_part7_draw },
    { 4, NULL },
    { 0, scyther_hd_part8_draw },
    { 1, scyther_hd_part9_draw },
    { 4, NULL },
    { 1, scyther_hd_part10_draw },
    { 4, NULL },
    { 0, scyther_hd_part11_draw },
    { 1, scyther_hd_part12_draw },
    { 4, NULL },
    { 1, scyther_hd_part13_draw },
    { 4, NULL },
    { 0, scyther_hd_part14_draw },
    { 4, NULL },
    { 0, scyther_hd_part15_draw },
    { 4, NULL },
    { 0, scyther_hd_part16_draw },
    { 4, NULL },
    { 0, scyther_hd_part17_draw },
    { 4, NULL },
};

UnkEC64Arg3 scyther_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &scyther_hd_gfxdata[0],
      { 0.0, 750.0, 9.999999974752427e-07 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &scyther_hd_gfxdata[2],
      { 0.0, 0.0, 9.000000318337698e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[4],
      { 0.0, 465.62921142578125, 23.311189651489258 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &scyther_hd_gfxdata[6],
      { 0.0, -3.7465100288391113, 34.81619644165039 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[8],
      { 249.9999542236328, 250.0, -14.999911308288574 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &scyther_hd_gfxdata[10],
      { 18.295024871826172, -385.7263488769531, 21.918668746948242 },
      { -0.021462999284267426, 0.030435999855399132, 0.04106999933719635 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[12],
      { -249.9999542236328, 250.0, -14.999911308288574 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &scyther_hd_gfxdata[14],
      { -18.295024871826172, -385.7263488769531, 21.918668746948242 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[16],
      { 99.99996185302734, 276.6004638671875, -152.74143981933594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[19],
      { 100.00004577636719, 276.6004638671875, -152.74143981933594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[21],
      { -99.99996185302734, 276.6004638671875, -152.74143981933594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[24],
      { -99.99996185302734, 276.6004638671875, -152.74143981933594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &scyther_hd_gfxdata[26],
      { 200.0, -187.3737335205078, -27.506366729736328 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[28],
      { 29.06060218811035, -310.2272644042969, -16.464733123779297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &scyther_hd_gfxdata[30],
      { -200.0, -187.3737335205078, -27.506366729736328 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &scyther_hd_gfxdata[32],
      { -29.06060218811035, -310.2272644042969, -16.464731216430664 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
