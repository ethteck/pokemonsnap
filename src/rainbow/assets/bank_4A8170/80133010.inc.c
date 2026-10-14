/* ROM 4E53E0, VRAM 80133010: complete native animation command stream. */
struct bank_4A8170_Animation80133010 D_80133010_4E53E0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.4901161193847656e-08f, 0.0f, -1.4901161193847656e-08f, 0.0f, 0.822746753692627f, -78.9834976196289f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 90 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
