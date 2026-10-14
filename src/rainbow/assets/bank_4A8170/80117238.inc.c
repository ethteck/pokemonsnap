/* ROM 4C9608, VRAM 80117238: complete native animation command stream. */
struct bank_4A8170_Animation80117238 D_80117238_4C9608 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.5f, 1.5f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80117238_4C9608 },
};
