/* ROM 10E974, VRAM 801824E4: complete native animation command stream. */
struct native_105E80_snorlax_Animation801824E4 D_801824E4_10E974 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 71 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801824E4_10E974 },
};
