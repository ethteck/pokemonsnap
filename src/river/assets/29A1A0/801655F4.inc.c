/* ROM 2D56C4, VRAM 801655F4: complete native animation command stream. */
struct river_29A1A0_Animation801655F4 D_801655F4_2D56C4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { -5.815381050109863f, 217.95443725585938f, -38.32883834838867f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801655F4_2D56C4 },
};
