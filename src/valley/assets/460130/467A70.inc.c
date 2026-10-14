/* ROM 467A70, VRAM 80171630: struct ValleyAnimation80171630. */
struct ValleyAnimation80171630 D_80171630_467A70 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 1.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 3, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 3, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80171630_467A70 },
};
