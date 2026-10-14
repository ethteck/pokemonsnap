/* ROM 467C50, VRAM 80171810: struct ValleyAnimation80171810. */
struct ValleyAnimation80171810 D_80171810_467C50 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 1, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 1, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 36 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
