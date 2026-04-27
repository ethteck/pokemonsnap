#include "common.h"

extern u8 cloyster_tex_80170538[];
extern u8 cloyster_tex_80170550_png[];
extern u8 cloyster_tex_80170758[];
extern u8 cloyster_tex_80170780_png[];
extern u8 cloyster_tex_80170B88[];
extern u8 cloyster_tex_80170BB0_png[];
extern u8 cloyster_tex_80170DB8[];
extern u8 cloyster_tex_80170DE0_png[];
extern u8 cloyster_tex_801711E8[];
extern u8 cloyster_tex_80171210_png[];
extern u8 cloyster_tex_80171318[];
extern u8 cloyster_tex_80171340_png[];
extern u8 cloyster_tex_80171388[];
extern u8 cloyster_tex_801713D0[];
extern u8 cloyster_tex_80171418[];
extern u8 cloyster_tex_80171440_png[];

extern u8 D_80170B18_river_extra[];
extern u8 D_80170B30_river_extra[];
extern u8 D_80170D38_river_extra[];
extern u8 D_80170D60_river_extra[];
extern u8 D_80171168_river_extra[];
extern u8 D_80171190_river_extra[];
extern u8 D_80171398_river_extra[];
extern u8 D_801713C0_river_extra[];
extern u8 D_801717C8_river_extra[];
extern u8 D_801717F0_river_extra[];
extern u8 D_801718F8_river_extra[];
extern u8 D_80171920_river_extra[];
extern u8 D_80171968_river_extra[];
extern u8 D_801719B0_river_extra[];
extern u8 D_801719F8_river_extra[];
extern u8 D_80171A20_river_extra[];
extern u8 D_801A0290_river_extra[];
extern u8 D_801A0380_river_extra[];
extern u8 D_801A0440_river_extra[];
extern u8 D_801A05D0_river_extra[];
extern u8 D_801A0690_river_extra[];
extern u8 D_801A06A0_river_extra[];
extern u8 D_801A06F0_river_extra[];
extern u8 D_801A0700_river_extra[];
extern u8 D_801A0720_river_extra[];
extern u8 D_801A0760_river_extra[];
extern u8 D_801A0790_river_extra[];
extern u8 D_801A07E0_river_extra[];
extern u8 D_801A0810_river_extra[];
extern u8 D_801A0890_river_extra[];
extern u8 D_801A08A0_river_extra[];
extern u8 D_801A08F0_river_extra[];
extern u8 D_801A0950_river_extra[];
extern u8 D_801A09C0_river_extra[];
extern u8 D_801A09D0_river_extra[];
extern u8 D_801A09F0_river_extra[];
extern u8 D_801A0A00_river_extra[];
extern u8 D_801A0A20_river_extra[];
extern u8 D_801A0A30_river_extra[];
extern u8 D_801A0A40_river_extra[];
extern u8 D_801A0A50_river_extra[];
extern u8 D_801A0A60_river_extra[];
extern u8 D_801A0A80_river_extra[];
extern u8 D_801A0AE0_river_extra[];
extern u8 D_801A0B00_river_extra[];
extern u8 D_801A0D00_river_extra[];
extern u8 D_801A0D10_river_extra[];
extern u8 D_801A0F10_river_extra[];
extern u8 D_801A0F20_river_extra[];
extern u8 D_801A0F70_river_extra[];
extern u8 D_801A0F80_river_extra[];
extern u8 D_801A0FA0_river_extra[];
extern u8 D_801A0FE0_river_extra[];
extern u8 D_801A1010_river_extra[];
extern u8 D_801A1060_river_extra[];
extern u8 D_801A1090_river_extra[];
extern u8 D_801A1110_river_extra[];
extern u8 D_801A1120_river_extra[];
extern u8 D_801A1170_river_extra[];
extern u8 D_801A11D0_river_extra[];
extern u8 D_801A1240_river_extra[];
extern u8 D_801A1250_river_extra[];
extern u8 D_801A1270_river_extra[];
extern u8 D_801A1280_river_extra[];
extern u8 D_801A12A0_river_extra[];
extern u8 D_801A12B0_river_extra[];
extern u8 D_801A12C0_river_extra[];
extern u8 D_801A12D0_river_extra[];
extern u8 D_801A12E0_river_extra[];
extern u8 D_801A1300_river_extra[];
extern u8 D_801A1360_river_extra[];
extern u8 D_801A1380_river_extra[];
extern u8 D_801A1580_river_extra[];
extern u8 D_801A1590_river_extra[];
extern u8 D_801A1790_river_extra[];
extern u8 D_801A17F0_river_extra[];
extern u8 D_801A1810_river_extra[];
extern u8 D_801A18D0_river_extra[];
extern u8 D_801A18E0_river_extra[];
extern u8 D_801A18F0_river_extra[];
extern u8 D_801A19C0_river_extra[];
extern u8 D_801A1A50_river_extra[];
extern u8 D_801A1B50_river_extra[];

extern Gfx cloyster_hd_part0_draw[];

#include "assets/river/cloyster/hd_model.vtx.inc.c"
#include "assets/river/cloyster/hd_first.gfx.inc.c"
#include "assets/river/cloyster/hd_part0_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part1_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part2_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part3_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part4_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part5_draw.gfx.inc.c"

UnkEC64Arg3 cloyster_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 1246.9437255859375, 0.0 },
      { 0.10306400060653687, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_first,
      { 0.0, 103.96995544433594, 311.5775146484375 },
      { 0.03089199960231781, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part1_draw,
      { 0.0, 23.198890686035156, -587.8619384765625 },
      { 0.0, 0.22689299285411835, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part2_draw,
      { 0.0, 23.198890686035156, -587.8619384765625 },
      { 0.0, 2.9147000312805176, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part3_draw,
      { 0.0, 428.43121337890625, 232.9755859375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part4_draw,
      { 1.5999999959603883e-05, 547.4850463867188, -33.62914276123047 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      cloyster_hd_part5_draw,
      { 3.600000127335079e-05, 0.0, -2.4000000848900527e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0920000076293945, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
