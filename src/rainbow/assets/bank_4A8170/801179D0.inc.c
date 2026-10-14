/* ROM 4C9DA0, VRAM 801179D0: complete native animation command stream. */
struct bank_4A8170_Animation801179D0 D_801179D0_4C9DA0 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801179D0_4C9DA0 },
};
