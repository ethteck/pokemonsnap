/* ROM 2A3508, VRAM 80133438: complete native animation command stream. */
struct river_29A1A0_Animation80133438 D_80133438_2A3508 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80133420_2A34F0 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { 0.8726646304130554f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY | PATH_PARAM) << 15) | 100, { -1.2217304706573486f, 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
