/* ROM 266414, VRAM 8019A664: complete native animation command stream. */
struct Cave_Animation8019A664 D_8019A664_266414 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -1.997639742512547e-08f, 7.270813728865733e-09f, 0.0f, 450.0f, 250.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 120 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019A664_266414 },
};
