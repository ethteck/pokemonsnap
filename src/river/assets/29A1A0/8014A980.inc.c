/* ROM 2BAA50, VRAM 8014A980: complete native animation command stream. */
struct river_29A1A0_Animation8014A980 D_8014A980_2BAA50 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { -1.2217304706573486f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 3.0f, -21.25f, 29.48000144958496f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 65, { -1.2217304706573486f, -0.0003028553328476846f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 25, { -0.7853981852531433f, 0.03328890725970268f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 24 },
    { (ANIM_CMD_16 << 25) | ((0x7) << 15) | 1 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 20, { 0.1745329201221466f, -0.0072722053155303f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_16 << 25) | ((0x7) << 15) | 13 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 40, { -1.2217304706573486f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
