/* ROM 40083C, VRAM 8010A3FC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8010A3FC D_8010A3FC_40083C = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8010A3E4_400824 },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 0, { 4.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 0, { 0.3490658402442932f, 0.02327105589210987f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 55, { 1.3962633609771729f, 0.019258828833699226f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 29, { 2.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((SCALEX) << 15) | 36, { 3.0f, 0.030303029343485832f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 26 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 45, { 2.094395160675049f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 30, { 4.0f, -5.266666630632244e-05f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((SCALEX) << 15) | 0, { -5.333333319867961e-05f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 5, { 4.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
