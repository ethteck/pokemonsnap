/* ROM 2D4CF8, VRAM 80164C28: complete native animation command stream. */
struct river_29A1A0_Animation80164C28 D_80164C28_2D4CF8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { -0.0008463859558105469f, 173.68701171875f, -192.00320434570312f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80164C28_2D4CF8 },
};
