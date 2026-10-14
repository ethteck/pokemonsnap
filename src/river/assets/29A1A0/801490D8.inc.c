/* ROM 2B91A8, VRAM 801490D8: complete native animation command stream. */
struct river_29A1A0_Animation801490D8 D_801490D8_2B91A8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 4.656612873077393e-10f, 0.0f, 3.372035450865951e-08f, 6.556510925292969e-05f, 2.2601962089538574f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
