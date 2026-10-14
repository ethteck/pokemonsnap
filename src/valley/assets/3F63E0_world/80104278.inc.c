/* ROM 3FA6B8, VRAM 80104278: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80104278 D_80104278_3FA6B8 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80104260_3FA6A0 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTY | SCALEX) << 15) | 0, { 0.467266321182251f, 0.0f, 2.5f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 50, { 0.293599009513855f, -0.0060629635117948055f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTY) << 15) | 38, { -0.13511691987514496f, -0.010392745956778526f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 62, { 0.6981316804885864f, 0.05526876077055931f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 12 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 50, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
