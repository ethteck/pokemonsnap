#include "common.h"

extern u8 poliwag_tex_80167418[];
extern u8 poliwag_tex_80167620_png[];
extern u8 poliwag_tex_80167C28[];
extern u8 poliwag_tex_80167C50_png[];
extern u8 poliwag_tex_80167DD8[];
extern u8 poliwag_tex_80168DE0[];
extern u8 poliwag_tex_80168FE8_png[];

extern Gfx poliwag_part0_draw[];
extern Gfx poliwag_part7_draw[];

#include "assets/river/poliwag/model.vtx.inc.c"
#include "assets/river/poliwag/first.gfx.inc.c"
#include "assets/river/poliwag/part0_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part0_draw.gfx.inc.c"
#include "assets/river/poliwag/part1_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part1_draw.gfx.inc.c"
#include "assets/river/poliwag/part2_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part2_draw.gfx.inc.c"
#include "assets/river/poliwag/part3_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part3_draw.gfx.inc.c"
#include "assets/river/poliwag/part4_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part4_draw.gfx.inc.c"
#include "assets/river/poliwag/part5_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part5_draw.gfx.inc.c"
#include "assets/river/poliwag/part6_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part6_draw.gfx.inc.c"
#include "assets/river/poliwag/part6.gfx.inc.c"
#include "assets/river/poliwag/part7.gfx.inc.c"
#include "assets/river/poliwag/part7_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part7_draw.gfx.inc.c"
#include "assets/river/poliwag/part8_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part8_draw.gfx.inc.c"
#include "assets/river/poliwag/part9_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part9_draw.gfx.inc.c"
#include "assets/river/poliwag/part10_draw_near.gfx.inc.c"
#include "assets/river/poliwag/part10_draw.gfx.inc.c"
#include "assets/river/poliwag/last.gfx.inc.c"

DObjPayloadTypeC poliwag_gfxdata[] = {
    { 0, poliwag_first },
    { 4, NULL },
    { 0, poliwag_part1_draw },
    { 4, NULL },
    { 0, poliwag_part2_draw },
    { 4, NULL },
    { 0, poliwag_part3_draw },
    { 4, NULL },
    { 0, poliwag_part4_draw },
    { 4, NULL },
    { 0, poliwag_part5_draw },
    { 4, NULL },
    { 0, poliwag_part6 },
    { 4, NULL },
    { 1, poliwag_part7 },
    { 4, NULL },
    { 1, poliwag_part8_draw },
    { 4, NULL },
    { 1, poliwag_part9_draw },
    { 4, NULL },
    { 1, poliwag_last },
    { 4, NULL },
};

UnkEC64Arg3 poliwag_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &poliwag_gfxdata[0],
      { 0.0, 129.5622100830078, -105.181396484375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &poliwag_gfxdata[2],
      { -2.4000000848900527e-05, 100.85697174072266, 2.4000000848900527e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &poliwag_gfxdata[4],
      { 0.0, 23.06444549560547, 15.203487396240234 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      NULL,
      { 1.4999999621068127e-05, 334.0481262207031, 98.77774810791016 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &poliwag_gfxdata[6],
      { 109.25882720947266, 49.6988410949707, -18.790267944335938 },
      { 0.0, 0.11999999731779099, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &poliwag_gfxdata[8],
      { 1.2351269721984863, -144.81700134277344, -1.1752129793167114 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &poliwag_gfxdata[10],
      { -112.5843734741211, 49.70004653930664, -18.79030418395996 },
      { 0.0, -0.20999999344348907, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &poliwag_gfxdata[12],
      { -0.9857059717178345, -145.60572814941406, -5.906052112579346 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &poliwag_gfxdata[14],
      { 3.000000106112566e-06, 34.097923278808594, -157.53103637695312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &poliwag_gfxdata[16],
      { 3.000000106112566e-06, -0.2500059902667999, -229.49461364746094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &poliwag_gfxdata[18],
      { 0.30231600999832153, -0.18988800048828125, -158.88595581054688 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &poliwag_gfxdata[20],
      { 0.0, -2.0800468921661377, -154.89259338378906 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
