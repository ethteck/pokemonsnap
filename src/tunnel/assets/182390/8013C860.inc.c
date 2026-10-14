/* ROM 1829C0, VRAM 8013C860: complete native animation command stream. */
struct tunnel_182390_Animation8013C860 D_8013C860_1829C0 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { -2.4511289596557617f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.13962633907794952f, 0.0f, -6.455591201782227f, -8.370804786682129f, 1.4901161193847656e-06f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 15, { -2.4511289596557617f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 90, { -2.0071287155151367f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 45, { -2.0071287155151367f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
