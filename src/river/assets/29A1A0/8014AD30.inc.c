/* ROM 2BAE00, VRAM 8014AD30: complete native animation command stream. */
struct river_29A1A0_Animation8014AD30 D_8014AD30_2BAE00 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -2.0071287155151367f, -0.13962633907794952f, 0.0f, -6.455591201782227f, -8.370804786682129f, 1.4901161193847656e-06f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
