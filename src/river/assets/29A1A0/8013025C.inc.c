/* ROM 2A032C, VRAM 8013025C: complete native animation command stream. */
struct river_29A1A0_Animation8013025C D_8013025C_2A032C = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80130244_2A0314 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { 2.268928050994873f, 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 100, { 0.8726646304130554f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 68, { 0.7366117238998413f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 32, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
