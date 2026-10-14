/* ROM 1CC6D4, VRAM 80186574: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80186574 D_80186574_1CC6D4 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 30, { 1.5707963705062866f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 15 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 15 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 30, { 0.0f, -0.02617993950843811f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 26 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
