#include "common.h"

extern u8 shellder_tex_80181D18[];
extern u8 shellder_tex_80181D40_png[];
extern u8 shellder_tex_80181F48[];
extern u8 shellder_tex_80182150[];
extern u8 shellder_tex_80182178_png[];

extern u8 D_801822F8_river_extra[];
extern u8 D_80182320_river_extra[];
extern u8 D_80182528_river_extra[];
extern u8 D_80182730_river_extra[];
extern u8 D_80182758_river_extra[];
extern u8 D_801A9060_river_extra[];
extern u8 D_801A9070_river_extra[];
extern u8 D_801A9080_river_extra[];
extern u8 D_801A9090_river_extra[];
extern u8 D_801A90B0_river_extra[];
extern u8 D_801A90E0_river_extra[];
extern u8 D_801A9110_tunnel_extra[];
extern u8 D_801A9170_river_extra[];
extern u8 D_801A9190_river_extra[];
extern u8 D_801A91A0_river_extra[];
extern u8 D_801A91B0_river_extra[];
extern u8 D_801A91E0_river_extra[];
extern u8 D_801A91F0_river_extra[];
extern u8 D_801A9200_river_extra[];
extern u8 D_801A9260_river_extra[];
extern u8 D_801A9290_river_extra[];
extern u8 D_801A92C0_river_extra[];
extern u8 D_801A92E0_river_extra[];
extern u8 D_801A9320_river_extra[];
extern u8 D_801A9360_river_extra[];
extern u8 D_801A93F0_river_extra[];
extern u8 D_801A9400_river_extra[];
extern u8 D_801A9410_river_extra[];
extern u8 D_801A9420_river_extra[];
extern u8 D_801A9430_tunnel_extra[];
extern u8 D_801A9440_river_extra[];
extern u8 D_801A9450_river_extra[];
extern u8 D_801A9470_tunnel_extra[];
extern u8 D_801A9480_river_extra[];
extern u8 D_801A94A0_river_extra[];
extern u8 D_801A94B0_river_extra[];
extern u8 D_801A94E0_river_extra[];
extern u8 D_801A94F0_river_extra[];
extern u8 D_801A9510_river_extra[];
extern u8 D_801A9520_river_extra[];
extern u8 D_801A9550_river_extra[];
extern u8 D_801A9560_river_extra[];
extern u8 D_801A95B0_tunnel_extra[];
extern u8 D_801A95C0_river_extra[];
extern u8 D_801A9620_river_extra[];
extern u8 D_801A96D0_river_extra[];
extern u8 D_801A96F0_tunnel_extra[];
extern u8 D_801A98F0_river_extra[];
extern u8 D_801A9920_river_extra[];
extern u8 D_801A9970_river_extra[];
extern u8 D_801A9A20_river_extra[];
extern u8 D_801A9C20_river_extra[];
extern u8 D_801A9C30_river_extra[];
extern u8 D_801A9C40_river_extra[];
extern u8 D_801A9D00_river_extra[];
extern u8 D_801A9D60_river_extra[];
extern u8 D_801A9DC0_river_extra[];
extern u8 D_801A9E00_river_extra[];
extern u8 D_801AA000_river_extra[];
extern u8 D_801AA020_river_extra[];
extern u8 D_801AA030_river_extra[];
extern u8 D_801AA040_river_extra[];
extern u8 D_801AA170_river_extra[];
extern u8 D_801AA1A0_river_extra[];
extern u8 D_801AA1B0_river_extra[];
extern u8 D_801AA1D0_river_extra[];
extern u8 D_801AA3D0_river_extra[];
extern u8 D_801AA3E0_river_extra[];
extern u8 D_801AA410_river_extra[];
extern u8 D_801AA490_river_extra[];
extern u8 D_801AA4A0_river_extra[];
extern u8 D_801AA4F0_river_extra[];
extern u8 D_801AA520_tunnel_extra[];
extern u8 D_801AA540_river_extra[];
extern u8 D_801AA580_river_extra[];
extern u8 D_801AA5D0_river_extra[];
extern u8 D_801AA5F0_river_extra[];
extern u8 D_801AA600_river_extra[];
extern u8 D_801AA620_river_extra[];
extern u8 D_801AA630_river_extra[];
extern u8 D_801AA660_river_extra[];
extern u8 D_801AA670_river_extra[];
extern u8 D_801AA680_river_extra[];
extern u8 D_801AA690_river_extra[];
extern u8 D_801AA6A0_river_extra[];
extern u8 D_801AA860_tunnel_extra[];
extern u8 D_801AA8A8_river_extra[];

extern Gfx shellder_hd_part0_draw[];

#include "assets/river/shellder/hd_model.vtx.inc.c"
#include "assets/river/shellder/hd_first.gfx.inc.c"
#include "assets/river/shellder/hd_part0_draw.gfx.inc.c"
#include "assets/river/shellder/hd_part1_draw.gfx.inc.c"
#include "assets/river/shellder/hd_part2_draw.gfx.inc.c"
#include "assets/river/shellder/hd_part3_draw.gfx.inc.c"
#include "assets/river/shellder/hd_part4_draw.gfx.inc.c"
#include "assets/river/shellder/hd_part5_draw.gfx.inc.c"
#include "assets/river/shellder/hd_part6_draw.gfx.inc.c"

UnkEC64Arg3 shellder_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      shellder_hd_first,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      shellder_hd_part1_draw,
      { 0.0, 149.99998474121094, 30.000001907348633 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999979734420776 } },
    { 3,
      shellder_hd_part2_draw,
      { 0.0, -14.555370330810547, 121.25611114501953 },
      { 0.2483540028333664, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      shellder_hd_part3_draw,
      { -0.016891999170184135, -6.486690044403076, 75.96707153320312 },
      { 0.05739400163292885, 0.0, 0.0 },
      { 1.0, 1.0000020265579224, 1.0000009536743164 } },
    { 5,
      shellder_hd_part4_draw,
      { 0.016891000792384148, -8.125031471252441, 77.00171661376953 },
      { 0.1305920034646988, 0.0, 0.0 },
      { 1.0, 0.9999960064888, 0.9999970197677612 } },
    { 6,
      shellder_hd_part5_draw,
      { 0.0, -15.441333770751953, 73.78752136230469 },
      { 0.1152300015091896, 0.0, 0.0 },
      { 0.9999979734420776, 0.9999970197677612, 0.9999960064888 } },
    { 2,
      shellder_hd_part6_draw,
      { 0.0, 94.99999237060547, -110.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999979734420776 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
