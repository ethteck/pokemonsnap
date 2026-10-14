/* ROM 129F50, VRAM 8019DAC0: complete native animation command stream. */
struct native_116A30_meowth_Animation8019DAC0 D_8019DAC0_129F50 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 24 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019DAC0_129F50 },
};
