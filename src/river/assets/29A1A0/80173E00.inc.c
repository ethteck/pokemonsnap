/* ROM 2E3ED0, VRAM 80173E00: complete native animation command stream. */
struct river_29A1A0_Animation80173E00 D_80173E00_2E3ED0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { -2.9802322387695312e-08f, 0.0f, 0.0f, 0.0f, 5.150032043457031f, 380.1499328613281f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80173E00_2E3ED0 },
};
