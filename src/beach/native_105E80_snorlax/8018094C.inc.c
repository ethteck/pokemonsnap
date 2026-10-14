/* ROM 10CDDC, VRAM 8018094C: complete native animation command stream. */
struct native_105E80_snorlax_Animation8018094C D_8018094C_10CDDC = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 36 },
    { (ANIM_CMD_16 << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018094C_10CDDC },
};
