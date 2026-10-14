/* ROM 2EB000, VRAM 8017AF30: complete native animation command stream. */
struct river_29A1A0_Animation8017AF30 D_8017AF30_2EB000 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017AF30_2EB000 },
};
