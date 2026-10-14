/* ROM 2A9F38, VRAM 80139E68: complete native animation command stream. */
struct river_29A1A0_Animation80139E68 D_80139E68_2A9F38 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80139E50_2A9F20 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { -0.5235987901687622f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 41, { 1.1435450315475464f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 13, { 0.13553300499916077f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 10, { 0.19739846885204315f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 23, { 0.3871192932128906f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 18 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 29, { 1.3163061141967773f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 33, { 0.7459390759468079f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 24 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 30, { 0.3490658402442932f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 9 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 21, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
