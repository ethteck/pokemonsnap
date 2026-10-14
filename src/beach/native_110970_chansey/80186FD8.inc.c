/* ROM 113468, VRAM 80186FD8: complete native animation command stream. */
struct native_110970_chansey_Animation80186FD8 D_80186FD8_113468 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -0.3490658402442932f, -39.9998664855957f, 84.28573608398438f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186FD8_113468 },
};
