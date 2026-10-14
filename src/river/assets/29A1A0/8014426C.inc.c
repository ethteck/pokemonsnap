/* ROM 2B433C, VRAM 8014426C: complete native animation command stream. */
struct river_29A1A0_Animation8014426C D_8014426C_2B433C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 20, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8014426C_2B433C },
};
