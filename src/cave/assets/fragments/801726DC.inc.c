/* ROM 23E48C, VRAM 801726DC: complete native animation command stream. */
struct Cave_Animation801726DC D_801726DC_23E48C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 7.194466888904572e-08f, -0.5235987901687622f, 200.0f, -5.6624412536621094e-05f, -7.152557373046875e-05f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801726DC_23E48C },
};
