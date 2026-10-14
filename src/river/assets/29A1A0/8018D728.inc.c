/* ROM 2FD7F8, VRAM 8018D728: complete native animation command stream. */
struct river_29A1A0_Animation8018D728 D_8018D728_2FD7F8 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 0, { -0.06981316953897476f, 0.031476642936468124f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -25.0f, -5.000019073486328f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 55, { -0.06981316953897476f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
