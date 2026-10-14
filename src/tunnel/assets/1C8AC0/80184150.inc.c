/* ROM 1CA2B0, VRAM 80184150: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80184150 D_80184150_1CA2B0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.3720000088214874f, 0.0f, 0.0f, 2.682209014892578e-05f, 4.76837158203125e-05f, -2.384185791015625e-05f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80184150_1CA2B0 },
};
