/* ROM 224A8C, VRAM 80158CDC: complete native animation command stream. */
struct Cave_Animation80158CDC D_80158CDC_224A8C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
