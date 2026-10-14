/* ROM 1CB098, VRAM 80184F38: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80184F38 D_80184F38_1CB098 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.3720000088214874f, 0.0f, 0.0f, 2.682209014892578e-05f, 4.76837158203125e-05f, -2.384185791015625e-05f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 156 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
