/* ROM 278AF0, VRAM 801ACD40: complete native animation command stream. */
struct Cave_Animation801ACD40 D_801ACD40_278AF0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 195.35000610351562f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 65 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
