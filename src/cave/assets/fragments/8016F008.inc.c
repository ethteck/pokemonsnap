/* ROM 23ADB8, VRAM 8016F008: complete native animation command stream. */
struct Cave_Animation8016F008 D_8016F008_23ADB8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 3.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 25, { 4.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 85, { 4.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 65 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
