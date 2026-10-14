/* ROM 460094, VRAM 80169C54: struct ValleyAnimation80169C54. */
struct ValleyAnimation80169C54 D_80169C54_460094 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 3, { 3.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 47, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 49 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80169C54_460094 },
};
