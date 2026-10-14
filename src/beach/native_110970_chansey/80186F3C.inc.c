/* ROM 1133CC, VRAM 80186F3C: complete native animation command stream. */
struct native_110970_chansey_Animation80186F3C D_80186F3C_1133CC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -15.000000953674316f, 1.0f, 0.699999988079071f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186F3C_1133CC },
};
