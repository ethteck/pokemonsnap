/* ROM 269DA4, VRAM 8019DFF4: complete native animation command stream. */
struct Cave_Animation8019DFF4 D_8019DFF4_269DA4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 450.0f, 250.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 36 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
