/* ROM 3042D8, VRAM 80194208: complete native animation command stream. */
struct river_29A1A0_Animation80194208 D_80194208_3042D8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80194208_3042D8 },
};
