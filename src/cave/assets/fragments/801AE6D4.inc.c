/* ROM 27A484, VRAM 801AE6D4: complete native animation command stream. */
struct Cave_Animation801AE6D4 D_801AE6D4_27A484 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, -0.5f, -0.5f, 2.0f, 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801AE6D4_27A484 },
};
