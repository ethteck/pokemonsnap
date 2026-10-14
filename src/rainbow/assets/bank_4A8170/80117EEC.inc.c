/* ROM 4CA2BC, VRAM 80117EEC: complete native animation command stream. */
struct bank_4A8170_Animation80117EEC D_80117EEC_4CA2BC = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 140 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
