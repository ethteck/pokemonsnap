/* ROM 2B42EC, VRAM 8014421C: complete native animation command stream. */
struct river_29A1A0_Animation8014421C D_8014421C_2B42EC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8014421C_2B42EC },
};
