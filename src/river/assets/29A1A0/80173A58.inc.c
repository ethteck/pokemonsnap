/* ROM 2E3B28, VRAM 80173A58: complete native animation command stream. */
struct river_29A1A0_Animation80173A58 D_80173A58_2E3B28 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { -2.9802322387695312e-08f, 0.0f, 0.0f, 0.0f, 5.152130126953125f, 380.15350341796875f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80173A58_2E3B28 },
};
