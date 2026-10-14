/* ROM 1130B8, VRAM 80186C28: complete native animation command stream. */
struct native_110970_chansey_Animation80186C28 D_80186C28_1130B8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY) << 15) | 0, { 0.1745329201221466f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 0, { -0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 10, { 0.0f, 0.017453288659453392f } },
    { (ANIM_CMD_12 << 25) | ((ROTZ) << 15) | 6 },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 149.9999542236328f, 75.0000228881836f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 10, { 0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTZ) << 15) | 10, { 0.0f, -0.017453286796808243f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 10, { -0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 10, { 0.0f, 0.01745329611003399f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186C28_1130B8 },
};
