/* ROM 2BC640, VRAM 8014C570: complete native animation command stream. */
struct river_29A1A0_Animation8014C570 D_8014C570_2BC640 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -30.000019073486328f, -25.199979782104492f, -0.0003814697265625f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 360, { 0.0f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { -0.0459180548787117f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 30, { -0.5235987901687622f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 60, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
