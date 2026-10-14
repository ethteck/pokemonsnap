/* ROM 2BAD2C, VRAM 8014AC5C: complete native animation command stream. */
struct river_29A1A0_Animation8014AC5C D_8014AC5C_2BAD2C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 4.656612873077393e-10f, 0.0f, 0.0f, -30.048728942871094f, -58.51061248779297f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 60, { 0.0f, 3.2074229238787666e-05f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 90, { -0.2617993950843811f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
