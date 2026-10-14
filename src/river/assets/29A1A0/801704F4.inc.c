/* ROM 2E05C4, VRAM 801704F4: complete native animation command stream. */
struct river_29A1A0_Animation801704F4 D_801704F4_2E05C4 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 60, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 17, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 16 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
