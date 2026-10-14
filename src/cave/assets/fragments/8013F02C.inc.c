/* ROM 20ADDC, VRAM 8013F02C: complete native animation command stream. */
struct Cave_Animation8013F02C D_8013F02C_20ADDC = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8013F014_20ADC4 },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 0, { 0.6499999761581421f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 1, { 1.0800000429153442f, 0.005375000648200512f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 79, { 1.0800000429153442f, -0.001818182528950274f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 20, { 0.8999999761581421f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
