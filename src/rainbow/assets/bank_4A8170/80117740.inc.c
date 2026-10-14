/* ROM 4C9B10, VRAM 80117740: complete native animation command stream. */
struct bank_4A8170_Animation80117740 D_80117740_4C9B10 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 3.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((IMG_INDEX) << 15) | 10, { 3.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 30, { 3.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 30, { 0x0066FFFF } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
