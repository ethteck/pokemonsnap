/* ROM 26AC04, VRAM 8019EE54: complete native animation command stream. */
struct Cave_Animation8019EE54 D_8019EE54_26AC04 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.6981316804885864f, 0.9599310755729675f, -345.0f, 280.0f, -150.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019EE54_26AC04 },
};
