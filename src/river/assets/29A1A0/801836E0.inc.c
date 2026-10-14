/* ROM 2F37B0, VRAM 801836E0: complete native animation command stream. */
struct river_29A1A0_Animation801836E0 D_801836E0_2F37B0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 3.1415927410125732f, 0.0f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 1.5f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801836E0_2F37B0 },
};
