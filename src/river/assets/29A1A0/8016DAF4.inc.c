/* ROM 2DDBC4, VRAM 8016DAF4: complete native animation command stream. */
struct river_29A1A0_Animation8016DAF4 D_8016DAF4_2DDBC4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 21 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 15 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016DAF4_2DDBC4 },
};
