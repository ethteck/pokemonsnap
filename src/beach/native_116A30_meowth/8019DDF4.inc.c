/* ROM 12A284, VRAM 8019DDF4: complete native animation command stream. */
struct native_116A30_meowth_Animation8019DDF4 D_8019DDF4_12A284 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 1.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019DDF4_12A284 },
};
