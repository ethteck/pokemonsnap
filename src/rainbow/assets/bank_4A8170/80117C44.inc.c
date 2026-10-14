/* ROM 4CA014, VRAM 80117C44: complete native animation command stream. */
struct bank_4A8170_Animation80117C44 D_80117C44_4CA014 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 110 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
