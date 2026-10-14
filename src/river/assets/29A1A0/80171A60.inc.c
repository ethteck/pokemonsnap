/* ROM 2E1B30, VRAM 80171A60: complete native animation command stream. */
struct river_29A1A0_Animation80171A60 D_80171A60_2E1B30 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 15, { 1.0f, -0.01880963332951069f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 3, { 0.8286543488502502f, -0.06827759742736816f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 2, { 0.5f, 0.010101573541760445f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 15, { 1.0f, 0.018258575350046158f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 3, { 0.8286543488502502f, -0.06827759742736816f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 2, { 0.5f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX) << 15) | 5, { 0.5f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
