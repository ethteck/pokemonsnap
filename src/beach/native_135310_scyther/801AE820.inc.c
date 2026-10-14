/* ROM 13ACB0, VRAM 801AE820: complete native animation command stream. */
struct native_135310_scyther_Animation801AE820 D_801AE820_13ACB0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.3135988712310791f, 0.0f, 0.0f, 2.6469779601696886e-21f, 750.0f, 7.449861527675239e-07f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 108 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801AE820_13ACB0 },
};
