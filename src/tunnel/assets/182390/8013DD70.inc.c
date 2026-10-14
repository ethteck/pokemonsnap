/* ROM 183ED0, VRAM 8013DD70: complete native animation command stream. */
struct tunnel_182390_Animation8013DD70 D_8013DD70_183ED0 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { -0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, -24.60002326965332f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 90, { -0.1745329350233078f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { 0.016826322302222252f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 30, { 0.2654670774936676f, 7.20994285074994e-05f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 30, { 0.2654670774936676f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
