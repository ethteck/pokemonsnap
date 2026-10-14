/* ROM 203790, VRAM 801379E0: complete native animation command stream. */
struct Cave_Animation801379E0 D_801379E0_203790 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 0, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T) << 15) | 1, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T) << 15) | 99, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
