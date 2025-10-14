#include "common.h"

extern u8 D_801B1230[]; // TODO: remove after splat is fixed

extern u8 butterfree_tex_80152928[];
extern u8 butterfree_tex_80152950_png[];
extern u8 butterfree_tex_801529D8[];
extern u8 butterfree_tex_80152A00_png[];
extern u8 butterfree_tex_80152A28[];
extern u8 butterfree_tex_80152A50_png[];
extern u8 butterfree_tex_80153258[];
extern u8 butterfree_tex_80153280_png[];
extern u8 butterfree_tex_80153A88[];
extern u8 butterfree_tex_80153AB0_png[];
extern u8 butterfree_tex_80153AF8[];
extern u8 butterfree_tex_80153B20_png[];
extern u8 butterfree_tex_80153BA8[];
extern u8 butterfree_tex_80153BD0_png[];
extern u8 butterfree_tex_80153C58[];
extern u8 butterfree_tex_80154680[];
extern u8 butterfree_tex_80154888_png[];

extern Gfx butterfree_hd_part0_draw[];

#include "assets/beach/butterfree/hd_model.vtx.inc.c"
#include "assets/beach/butterfree/hd_first.gfx.inc.c"
#include "assets/beach/butterfree/hd_part0_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part1_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part2_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part3_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part4_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part5_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part6_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part7_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part8_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part9_draw.gfx.inc.c"
#include "assets/beach/butterfree/hd_part10_draw.gfx.inc.c"

UnkEC64Arg3 butterfree_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      butterfree_hd_first,
      { 0.0, -69.9000015258789, -100.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      butterfree_hd_part1_draw,
      { 6.000000212225132e-06, 78.89999389648438, 43.5 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_hd_part2_draw,
      { 0.0, 74.0, 8.899998664855957 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      butterfree_hd_part3_draw,
      { 25.229999542236328, 186.00001525878906, 103.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      butterfree_hd_part4_draw,
      { -25.230533599853516, 186.00001525878906, 103.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_hd_part5_draw,
      { 1.1000000085914508e-05, 25.27529525756836, -97.54073333740234 },
      { 0.44930499792099, 1.1049699783325195, 0.40678998827934265 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_hd_part6_draw,
      { -3.858350992202759, 22.633310317993164, -104.35013580322266 },
      { 0.7713419795036316, 1.1904070377349854, 0.7343459725379944 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_hd_part7_draw,
      { -2.300000051036477e-05, 25.275287628173828, -97.54071807861328 },
      { 2.6922879219055176, 1.1049699783325195, 2.7348029613494873 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_hd_part8_draw,
      { 3.8583390712738037, 22.633304595947266, -104.35013580322266 },
      { 2.3702499866485596, 1.1904070377349854, 2.4072470664978027 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      butterfree_hd_part9_draw,
      { 40.0, -70.0, -30.000001907348633 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      butterfree_hd_part10_draw,
      { -40.0, -70.0, -30.000001907348633 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
