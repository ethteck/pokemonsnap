/* ROM 4170A0, VRAM 80120C60: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80120C60 D_80120C60_4170A0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -2.0071287155151367f, 0.13962633907794952f, 0.0f, 6.455591201782227f, -8.370780944824219f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
