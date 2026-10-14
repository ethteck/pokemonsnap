/* ROM 2D54E8, VRAM 80165418: complete native animation command stream. */
struct river_29A1A0_Animation80165418 D_80165418_2D54E8 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { -209.16078186035156f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -1200.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 20, { -300.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 20, { -209.16078186035156f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80165418_2D54E8 },
};
