/* ROM 2ADBB4, VRAM 8013DAE4: complete native animation command stream. */
struct river_29A1A0_Animation8013DAE4 D_8013DAE4_2ADBB4 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8013DACC_2ADB9C },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 0, { 0.6000000238418579f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY | PATH_PARAM) << 15) | 0, { 0.3490658402442932f, 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 53, { -0.4363323152065277f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 10, { 0.6000000238418579f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((SCALEX) << 15) | 50, { 0.6000000238418579f, 0.004444444086402655f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 43 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 47, { -0.5235987901687622f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 40, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
