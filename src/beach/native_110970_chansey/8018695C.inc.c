/* ROM 112DEC, VRAM 8018695C: complete native animation command stream. */
struct native_110970_chansey_Animation8018695C D_8018695C_112DEC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.4363323152065277f, -0.3490658402442932f, 0.0f, 225.0f, 150.0f, 275.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018695C_112DEC },
};
