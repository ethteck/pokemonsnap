/* ROM 2D4678, VRAM 801645A8: complete native animation command stream. */
struct river_29A1A0_Animation801645A8 D_801645A8_2D4678 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTY) << 15) | 0, { -0.3499999940395355f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.6073206663131714f, 1.3824939727783203f, -163.3826904296875f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 10, { -0.7482749819755554f, -0.02494249865412712f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 20, { -0.3499999940395355f, 0.02825000137090683f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x302) << 15) | 9 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 20, { -0.7482749819755554f, 0.02494249865412712f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 3 },
    { (ANIM_CMD_16 << 25) | ((0x302) << 15) | 7 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 20, { 0.7800000309944153f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_16 << 25) | ((0x302) << 15) | 3 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 10, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
