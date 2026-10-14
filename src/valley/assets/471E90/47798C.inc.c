/* ROM 47798C, VRAM 8018154C: struct ValleyAnimation8018154C. */
struct ValleyAnimation8018154C D_8018154C_47798C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.5707963705062866f, 0.0f, 0.0f, 0.0f, 200.0f, -150.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018154C_47798C },
};
