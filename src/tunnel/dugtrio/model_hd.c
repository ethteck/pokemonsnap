#include "common.h"

extern u8 dugtrio_tex_body_pal[];
extern u8 dugtrio_tex_body_png[];
extern u8 dugtrio_tex_head_pal[];
extern u8 dugtrio_tex_head_png[];
extern u8 dugtrio_tex_left_eye_pal[];
extern u8 dugtrio_tex_left_eye_png[];
extern u8 dugtrio_tex_nose_pal[];
extern u8 dugtrio_tex_nose_png[];
extern u8 dugtrio_tex_right_eye_pal[];
extern u8 dugtrio_tex_right_eye_png[];
extern u8 dugtrio_tex_soil_pal[];
extern u8 dugtrio_tex_soil_png[];

extern Gfx dugtrio_hd_part0_draw[];

#include "assets/tunnel/dugtrio/hd_model.vtx.inc.c"
#include "assets/tunnel/dugtrio/hd_first.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part0_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part1_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part2_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part3_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part4_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part5_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part6_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part7_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part8_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part9_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part10_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part11_draw.gfx.inc.c"
#include "assets/tunnel/dugtrio/hd_part12_draw.gfx.inc.c"

UnkEC64Arg3 dugtrio_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      dugtrio_hd_first,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      dugtrio_hd_part1_draw,
      { 0.0, 0.0, -200.33314514160156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      dugtrio_hd_part2_draw,
      { 0.0, 282.6976318359375, -0.386929988861084 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      dugtrio_hd_part3_draw,
      { 0.0, 153.9112548828125, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      NULL,
      { 0.0, 363.39111328125, 200.72007751464844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      dugtrio_hd_part4_draw,
      { 189.66015625, 0.0, 120.61872863769531 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      dugtrio_hd_part5_draw,
      { -2.2301549911499023, 91.06852722167969, -0.10871899873018265 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      dugtrio_hd_part6_draw,
      { -185.83009338378906, 0.0, 148.0842742919922 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      dugtrio_hd_part7_draw,
      { -0.1698489934206009, 248.78074645996094, -0.08430500328540802 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      dugtrio_hd_part8_draw,
      { 0.0, -9.999999974752427e-07, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      dugtrio_hd_part9_draw,
      { 0.0, -9.999999974752427e-07, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      dugtrio_hd_part10_draw,
      { 0.0, -9.999999974752427e-07, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      dugtrio_hd_part11_draw,
      { 0.0, 0.0, -1.0000009536743164 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      dugtrio_hd_part12_draw,
      { 0.0, 0.0, -1.0000009536743164 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
