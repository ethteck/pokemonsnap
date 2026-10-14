/* ROM 4C9E70, VRAM 80117AA0: complete native animation command stream. */
struct bank_4A8170_Animation80117AA0 D_80117AA0_4C9E70 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFE600FF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80117AA0_4C9E70 },
};
