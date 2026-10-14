/* ROM 21415C, VRAM 801483AC: complete native animation command stream. */
struct Cave_Animation801483AC D_801483AC_21415C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 60.000003814697266f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 30 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 90 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
