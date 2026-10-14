/* ROM 27586C, VRAM 801A9ABC: complete native animation command stream. */
struct Cave_Animation801A9ABC D_801A9ABC_27586C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 195.3533935546875f, 0.0009775161743164062f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 32 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A9ABC_27586C },
};
