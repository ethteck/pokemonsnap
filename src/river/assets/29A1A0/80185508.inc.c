/* ROM 2F55D8, VRAM 80185508: complete native animation command stream. */
struct river_29A1A0_Animation80185508 D_80185508_2F55D8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -0.0042438507080078125f, 0.003916025161743164f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 0, { 0.0f, -0.009039998054504395f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 12, { 0.0f, 0.008370368741452694f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 1 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 11 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 15, { 0.22599996626377106f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 13, { 0.0f, -0.009039998054504395f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80185508_2F55D8 },
};
