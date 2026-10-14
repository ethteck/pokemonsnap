/* ROM 29EAE4, VRAM 8012EA14: complete native animation command stream. */
struct river_29A1A0_Animation8012EA14 D_8012EA14_29EAE4 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8012E9FC_29EACC },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { 1.3962633609771729f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 39, { 0.3126903176307678f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 33, { 2.7925267219543457f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 57, { 2.7925267219543457f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 61, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 51 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 10, { 2.268928050994873f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
