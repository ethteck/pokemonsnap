/* ROM 2A6980, VRAM 801368B0: complete native animation command stream. */
struct river_29A1A0_Animation801368B0 D_801368B0_2A6980 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80136898_2A6968 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { -1.2217304706573486f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 10, { -1.2217304706573486f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 34, { -0.4818482995033264f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 36, { 0.5159573554992676f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 10, { -0.0017719788011163473f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 10, { -0.5235987901687622f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
