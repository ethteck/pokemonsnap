/* ROM 2EB280, VRAM 8017B1B0: complete native animation command stream. */
struct river_29A1A0_Animation8017B1B0 D_8017B1B0_2EB280 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B1B0_2EB280 },
};
