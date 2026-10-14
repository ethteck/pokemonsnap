/* ROM 244604, VRAM 80178854: complete native animation command stream. */
struct Cave_Animation80178854 D_80178854_244604 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 9, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 6, { 2.60770320892334e-08f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 45, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 25 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80178854_244604 },
};
