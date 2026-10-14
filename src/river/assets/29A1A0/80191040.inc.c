/* ROM 301110, VRAM 80191040: complete native animation command stream. */
struct river_29A1A0_Animation80191040 D_80191040_301110 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 3.1415927410125732f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80191040_301110 },
};
