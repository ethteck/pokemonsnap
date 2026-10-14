/* ROM 1169AC, VRAM 8018A51C: complete native animation command stream. */
struct native_110970_chansey_Animation8018A51C D_8018A51C_1169AC = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 30, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
