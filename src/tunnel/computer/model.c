#include "../tunnel.h"

extern u8 computer_tex_front_png[];
extern u8 computer_tex_side_png[];
extern u8 computer_tex_back_pal[];
extern u8 computer_tex_back_png[];

extern Vtx computer_vtx[];

#include "assets/tunnel/computer/draw.gfx.inc.c"
__ALIGNER
#include "assets/tunnel/computer/model.vtx.inc.c"
