/* ROM 2FC2B4, VRAM 8018C1E4: complete native animation command stream. */
struct river_29A1A0_Animation8018C1E4 D_8018C1E4_2FC2B4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 150.0f, 0.9999999403953552f, 1.0f, 0.9999999403953552f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 42 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
