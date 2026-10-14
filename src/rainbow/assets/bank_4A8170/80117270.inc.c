/* ROM 4C9640, VRAM 80117270: complete native animation command stream. */
struct bank_4A8170_Animation80117270 D_80117270_4C9640 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80117270_4C9640 },
};
