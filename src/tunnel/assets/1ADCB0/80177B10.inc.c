/* ROM 1BDC70, VRAM 80177B10: complete native animation command stream. */
struct tunnel_1ADCB0_Animation80177B10 D_80177B10_1BDC70 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.004999999888241291f, 0.0f, 0.9900000095367432f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 10, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 2, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 63, { 2.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
