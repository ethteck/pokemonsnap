/* ROM 40F26C, VRAM 80118E2C: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80118E2C D_80118E2C_40F26C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 20, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118E2C_40F26C },
};
