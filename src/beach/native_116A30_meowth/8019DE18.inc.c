/* ROM 12A2A8, VRAM 8019DE18: complete native animation command stream. */
struct native_116A30_meowth_Animation8019DE18 D_8019DE18_12A2A8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019DE18_12A2A8 },
};
