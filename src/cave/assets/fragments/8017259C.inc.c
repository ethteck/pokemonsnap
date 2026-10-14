/* ROM 23E34C, VRAM 8017259C: complete native animation command stream. */
struct Cave_Animation8017259C D_8017259C_23E34C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -1.2665987014770508e-07f, -0.5235987901687622f, 200.0f, -2.9802322387695312e-06f, 7.152557373046875e-05f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017259C_23E34C },
};
