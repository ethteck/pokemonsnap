/* ROM 2F1A6C, VRAM 8018199C: complete native animation command stream. */
struct river_29A1A0_Animation8018199C D_8018199C_2F1A6C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.03399990499019623f, 0.0f, 0.0f, 0.0f, 383.560791015625f, -9.253483772277832f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 90 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018199C_2F1A6C },
};
