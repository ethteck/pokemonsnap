/* ROM 2D2BE8, VRAM 80162B18: complete native animation command stream. */
struct river_29A1A0_Animation80162B18 D_80162B18_2D2BE8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { -0.0008463859558105469f, 20.197223663330078f, -236.0848846435547f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80162B18_2D2BE8 },
};
