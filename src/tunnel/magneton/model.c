#include <common.h>

extern u8 magneton_tex_screw_head_png[];
extern u8 magneton_tex_unk_circles_png[];
extern u8 magneton_tex_eye_png[];
extern u8 magneton_tex_magnet_blue_png[];
extern u8 magneton_tex_magnet_red_png[];
extern u8 magneton_tex_screw_thread_png[];

extern Gfx magneton_part0[];

#include "assets/tunnel/magneton/model.vtx.inc.c"
#include "assets/tunnel/magneton/first.gfx.inc.c"
#include "assets/tunnel/magneton/part0.gfx.inc.c"
#include "assets/tunnel/magneton/part1.gfx.inc.c"
#include "assets/tunnel/magneton/part2.gfx.inc.c"
#include "assets/tunnel/magneton/part3.gfx.inc.c"
#include "assets/tunnel/magneton/part4.gfx.inc.c"
#include "assets/tunnel/magneton/part5.gfx.inc.c"
#include "assets/tunnel/magneton/part6.gfx.inc.c"
#include "assets/tunnel/magneton/part7.gfx.inc.c"
#include "assets/tunnel/magneton/part8.gfx.inc.c"
#include "assets/tunnel/magneton/part9.gfx.inc.c"
#include "assets/tunnel/magneton/part10.gfx.inc.c"
#include "assets/tunnel/magneton/part11.gfx.inc.c"
#include "assets/tunnel/magneton/part12.gfx.inc.c"
#include "assets/tunnel/magneton/part13.gfx.inc.c"
#include "assets/tunnel/magneton/part14.gfx.inc.c"
#include "assets/tunnel/magneton/part15.gfx.inc.c"
#include "assets/tunnel/magneton/part16.gfx.inc.c"
#include "assets/tunnel/magneton/part17.gfx.inc.c"
#include "assets/tunnel/magneton/part18.gfx.inc.c"
#include "assets/tunnel/magneton/part19.gfx.inc.c"
#include "assets/tunnel/magneton/last.gfx.inc.c"

UnkEC64Arg3 magneton_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      magneton_first,
      { 0.0, 972.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part1,
      { 3.000000106112566e-06, 0.2792719900608063, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { 1.9998799562454224, 0.2792840003967285, 0.0 },
      { -0.026179999113082886, -2.862339973449707, 0.6283190250396729 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magneton_part2,
      { -141.99888610839844, 5.412303924560547, -0.4706990122795105 },
      { 0.00014699999883305281, -0.0033209999091923237, -8.70000003487803e-05 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { 1.9998799562454224, 0.2792840003967285, 0.0 },
      { 0.026179999113082886, -0.27576199173927307, -0.6283190250396729 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magneton_part3,
      { -141.99859619140625, 5.452274799346924, -0.026446999981999397 },
      { -0.0002530000056140125, -0.00017800000205170363, -0.00036800000816583633 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part4,
      { 70.00000762939453, -87.00000762939453, 50.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part5,
      { -70.0, -87.0, 50.0 },
      { 0.0, -3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part6,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      magneton_part7,
      { 320.00006103515625, 450.0, -100.0 },
      { 0.0, 0.0, 2.0943949222564697 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part8,
      { -2.3602960109710693, -2.257823944091797, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { 9.500000305706635e-05, 5.999999848427251e-05, 0.0 },
      { -0.026179999113082886, -2.862339973449707, -0.2588909864425659 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magneton_part9,
      { 50.5661735534668, -122.44389343261719, 51.41727828979492 },
      { -0.30071499943733215, 0.38175100088119507, 2.00137996673584 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { 9.500000305706635e-05, 5.999999848427251e-05, 0.0 },
      { 0.026179999113082886, -0.27576199173927307, 0.2588909864425659 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magneton_part10,
      { 59.796478271484375, 114.0987548828125, -59.9932746887207 },
      { -0.22109399735927582, -0.4278320074081421, -2.0126090049743652 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part11,
      { -110.0, 0.0, 110.0 },
      { 1.233610987663269, -1.2601449489593506, 1.7453290224075317 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part12,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, -2.0943949222564697 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      magneton_part13,
      { -320.0000305175781, 450.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part14,
      { -2.909230947494507, 1.5035150051116943, 6.000000212225132e-06 },
      { 0.0, 3.1415929794311523, -2.0943949222564697 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { -2.4000000848900527e-05, -4.8000001697801054e-05, -6.000000212225132e-06 },
      { -0.026179999113082886, -2.862339973449707, 0.15987199544906616 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magneton_part15,
      { -141.99880981445312, 5.4123640060424805, -0.470661997795105 },
      { 0.00014699999883305281, -0.0033209999091923237, -8.70000003487803e-05 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { -2.4000000848900527e-05, -4.8000001697801054e-05, -6.000000212225132e-06 },
      { 0.026179999113082886, -0.27576199173927307, -0.15987199544906616 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magneton_part16,
      { -141.99855041503906, 5.45220422744751, -0.02642899937927723 },
      { -0.0002530000056140125, -0.00017800000205170363, -0.00036800000816583633 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part17,
      { -65.0, -50.0, 140.0 },
      { -5.759585857391357, -0.13002699613571167, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magneton_part18,
      { -3.000000106112566e-06, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 32769,
      magneton_last,
      { 4.199999966658652e-05, 700.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 }
    },
};
