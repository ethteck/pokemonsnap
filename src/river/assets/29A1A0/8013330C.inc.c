/* ROM 2A33DC, VRAM 8013330C: complete native animation command stream. */
struct river_29A1A0_Animation8013330C D_8013330C_2A33DC = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_801332F4_2A33C4 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { 0.8726646304130554f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 100, { -1.2217304706573486f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 83, { 0.8548223376274109f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 17, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
