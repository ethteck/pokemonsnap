/* ROM 2133E4, VRAM 80147634: complete native animation command stream. */
struct Cave_Animation80147634 D_80147634_2133E4 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8014761C_2133CC },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { 0.001532547059468925f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((PATH_PARAM) << 15) | 60, { 0.6000000238418579f, 0.021136103197932243f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { -9.130794751399662e-06f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((PATH_PARAM) << 15) | 30, { 0.7300000190734863f, 0.007205913309007883f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((PATH_PARAM) << 15) | 0, { 0.8999999761581421f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 30, { 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
