/* ROM 4C9C80, VRAM 801178B0: complete native animation command stream. */
struct bank_4A8170_Animation801178B0 D_801178B0_4C9C80 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFE600FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 3.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((IMG_INDEX) << 15) | 10, { 3.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 30, { 3.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
