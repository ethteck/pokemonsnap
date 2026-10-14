/* ROM EDEB4, VRAM 80161A24: complete native animation command stream. */
struct native_E4E90_doduo_Animation80161A24 D_80161A24_EDEB4 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 1, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 4, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
