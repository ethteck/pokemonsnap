/* ROM 2F0D7C, VRAM 80180CAC: complete native animation command stream. */
struct river_29A1A0_Animation80180CAC D_80180CAC_2F0D7C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.03399990499019623f, 0.0f, 0.0f, 0.0f, 383.560791015625f, -9.253483772277832f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80180CAC_2F0D7C },
};
