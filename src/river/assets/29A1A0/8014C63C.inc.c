/* ROM 2BC70C, VRAM 8014C63C: complete native animation command stream. */
struct river_29A1A0_Animation8014C63C D_8014C63C_2BC70C = {
    { (ANIM_CMD_SET_VALUE << 25) | ((POSY | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -37.401390075683594f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -9.5367431640625e-05f, 0.0003814697265625f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 360, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY) << 15) | 300, { -43.80018615722656f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY) << 15) | 60, { -35.000003814697266f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY | SCALEX | SCALEY | SCALEZ) << 15) | 5, { -57.00053024291992f, 2.0f, 2.0f, 2.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY | SCALEX | SCALEY | SCALEZ) << 15) | 30, { -57.00053024291992f, 2.0f, 2.0f, 2.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY | SCALEX | SCALEY | SCALEZ) << 15) | 15, { -37.401390075683594f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY | SCALEX | SCALEY | SCALEZ) << 15) | 40, { -37.401390075683594f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
