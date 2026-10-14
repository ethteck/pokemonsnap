/* ROM 2EAEC0, VRAM 8017ADF0: complete native animation command stream. */
struct river_29A1A0_Animation8017ADF0 D_8017ADF0_2EAEC0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017ADF0_2EAEC0 },
};
