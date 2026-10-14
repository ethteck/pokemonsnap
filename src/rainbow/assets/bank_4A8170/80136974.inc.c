/* ROM 4E8D44, VRAM 80136974: complete native animation command stream. */
struct bank_4A8170_Animation80136974 D_80136974_4E8D44 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { -0.09999999403953552f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 0, { 0.0f, -1.0000001192092896f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 35, { -0.049999989569187164f, 0.0016749188071116805f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 35, { 34.179996490478516f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 39, { -65.25f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 49, { 0.040693193674087524f, 0.0005617976421490312f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 16 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 23 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 50, { 14.18001651763916f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 40, { 0.0f, -0.0027586896903812885f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 11, { 0.0f, -1.1333333253860474f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 11, { -0.09999999403953552f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80136974_4E8D44 },
};
