/* ROM 2EA338, VRAM 8017A268: complete native animation command stream. */
struct river_29A1A0_Animation8017A268 D_8017A268_2EA338 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A268_2EA338 },
};
