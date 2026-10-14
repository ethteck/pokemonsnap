/* ROM 2BC99C, VRAM 8014C8CC: complete native animation command stream. */
struct river_29A1A0_Animation8014C8CC D_8014C8CC_2BC99C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.011911885812878609f, 0.0f, -1.2928155768143768e-10f, -9.5367431640625e-05f, -18.0533447265625f, -0.0003814697265625f, 0.5f, 0.5f, 0.5f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 360 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 90 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
