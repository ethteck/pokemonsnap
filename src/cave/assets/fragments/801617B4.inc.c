/* ROM 22D564, VRAM 801617B4: complete native animation command stream. */
struct Cave_Animation801617B4 D_801617B4_22D564 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 1, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 1, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 18, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 1, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
