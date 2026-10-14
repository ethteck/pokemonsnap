/* ROM 2758A0, VRAM 801A9AF0: complete native animation command stream. */
struct Cave_Animation801A9AF0 D_801A9AF0_2758A0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | POSY | POSZ) << 15) | 0, { 0.0f, -50.349998474121094f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | POSY | POSZ) << 15) | 15, { -0.1592319756746292f, -58.87449264526367f, -15.241241455078125f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | POSY | POSZ) << 15) | 17, { 0.0f, -50.349998474121094f, 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A9AF0_2758A0 },
};
