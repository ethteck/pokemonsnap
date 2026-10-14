/* ROM 2BCF5C, VRAM 8014CE8C: complete native animation command stream. */
struct river_29A1A0_Animation8014CE8C D_8014CE8C_2BCF5C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 450 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
