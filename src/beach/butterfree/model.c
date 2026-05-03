#include "common.h"

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

Gfx butterfree_part0_draw[];

#include "assets/beach/butterfree/model.vtx.inc.c"
#include "assets/beach/butterfree/first.gfx.inc.c"
#include "assets/beach/butterfree/part0_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part0_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part0_draw.gfx.inc.c"
#include "assets/beach/butterfree/part1_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part1_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part1_draw.gfx.inc.c"
#include "assets/beach/butterfree/part2_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part2_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part2_draw.gfx.inc.c"
#include "assets/beach/butterfree/part3_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part3_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part3_draw.gfx.inc.c"
#include "assets/beach/butterfree/part4_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part4_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part4_draw.gfx.inc.c"
#include "assets/beach/butterfree/part5_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part5_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part5_draw.gfx.inc.c"
#include "assets/beach/butterfree/part6_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part6_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part6_draw.gfx.inc.c"
#include "assets/beach/butterfree/part7_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part7_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part7_draw.gfx.inc.c"
#include "assets/beach/butterfree/part8_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part8_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part8_draw.gfx.inc.c"
#include "assets/beach/butterfree/part9_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part9_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part9_draw.gfx.inc.c"
#include "assets/beach/butterfree/part10_draw_near.gfx.inc.c"
#include "assets/beach/butterfree/part10_draw_far.gfx.inc.c"
#include "assets/beach/butterfree/part10_draw.gfx.inc.c"
#include "assets/beach/butterfree/last.gfx.inc.c"

UnkEC64Arg3 butterfree_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0011980000417679548, -0.03130200132727623, -0.03826399892568588 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      butterfree_first,
      { 0.0, 0.0, 0.0 },
      { 0.0872659981250763, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      butterfree_part1_draw,
      { 4.8000001697801054e-05, 78.89999389648438, 43.5023307800293 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_part2_draw,
      { -2.4000000848900527e-05, 74.0, 8.899998664855957 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      butterfree_part3_draw,
      { 25.230003356933594, 185.99998474121094, 102.99998474121094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      butterfree_part4_draw,
      { -25.230003356933594, 185.99998474121094, 102.99998474121094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_part5_draw,
      { -3.099999958067201e-05, 25.27529525756836, -97.54306030273438 },
      { 0.44930499792099, 1.1049699783325195, 0.40678900480270386 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_part6_draw,
      { -3.8583929538726807, 22.633310317993164, -104.35246276855469 },
      { 0.7713419795036316, 1.1904070377349854, 0.7343459725379944 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_part7_draw,
      { -6.399999983841553e-05, 25.275287628173828, -97.54304504394531 },
      { 2.6922879219055176, 1.1049699783325195, 2.7348029613494873 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      butterfree_part8_draw,
      { 3.858297109603882, 22.633304595947266, -104.35246276855469 },
      { 2.3702499866485596, 1.1904070377349854, 2.4072470664978027 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      butterfree_part9_draw,
      { 40.0, -70.0, -30.000001907348633 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      butterfree_last,
      { -39.999752044677734, -70.0, -29.99999237060547 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
