/* ROM 2B42BC, VRAM 801441EC: complete native animation command stream. */
struct river_29A1A0_Animation801441EC D_801441EC_2B42BC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801441EC_2B42BC },
};
