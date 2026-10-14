/* ROM 2AA108, VRAM 8013A038: complete native animation command stream. */
struct river_29A1A0_Animation8013A038 D_8013A038_2AA108 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8013A020_2AA0F0 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { -0.5235987901687622f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 41, { 1.136346697807312f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 29, { 1.3163061141967773f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 30, { 0.3490658402442932f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
