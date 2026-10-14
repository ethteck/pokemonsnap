/* ROM 26C09C, VRAM 801A02EC: complete native animation command stream. */
struct Cave_Animation801A02EC D_801A02EC_26C09C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 24, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 2, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
