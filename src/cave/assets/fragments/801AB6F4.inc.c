/* ROM 2774A4, VRAM 801AB6F4: complete native animation command stream. */
struct Cave_Animation801AB6F4 D_801AB6F4_2774A4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 195.35000610351562f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 90 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
