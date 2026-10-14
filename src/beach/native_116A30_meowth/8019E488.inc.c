/* ROM 12A918, VRAM 8019E488: complete native animation command stream. */
struct native_116A30_meowth_Animation8019E488 D_8019E488_12A918 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 54, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 1, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
