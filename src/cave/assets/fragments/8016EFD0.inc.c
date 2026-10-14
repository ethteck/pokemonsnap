/* ROM 23AD80, VRAM 8016EFD0: complete native animation command stream. */
struct Cave_Animation8016EFD0 D_8016EFD0_23AD80 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 8, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 34, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 68, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 48 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
