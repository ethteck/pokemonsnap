/* ROM 2BABE0, VRAM 8014AB10: complete native animation command stream. */
struct river_29A1A0_Animation8014AB10 D_8014AB10_2BABE0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { -1.2217304706573486f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -3.0f, -21.25f, 29.48000144958496f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 65, { -1.2217304706573486f, -0.0003028553328476846f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 25, { -0.7853981852531433f, 0.03328890725970268f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 23 },
    { (ANIM_CMD_16 << 25) | ((0x8) << 15) | 2 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 20, { 0.1745329201221466f, -0.0072722053155303f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 9 },
    { (ANIM_CMD_16 << 25) | ((0x8) << 15) | 11 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 40, { -1.2217304706573486f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
