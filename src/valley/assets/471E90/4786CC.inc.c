/* ROM 4786CC, VRAM 8018228C: struct ValleyAnimation8018228C. */
struct ValleyAnimation8018228C D_8018228C_4786CC = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -10.0f, 35.0f, 15.000000953674316f, 0.75f, 0.75f, 0.75f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018228C_4786CC },
};
