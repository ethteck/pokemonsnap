/* ROM 2B9110, VRAM 80149040: complete native animation command stream. */
struct river_29A1A0_Animation80149040 D_80149040_2B9110 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80149028_2B90F8 },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.5400002598762512f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 150, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
