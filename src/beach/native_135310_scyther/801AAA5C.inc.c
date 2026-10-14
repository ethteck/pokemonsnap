/* ROM 136EEC, VRAM 801AAA5C: complete native animation command stream. */
struct native_135310_scyther_Animation801AAA5C D_801AAA5C_136EEC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.9020001888275146f, 0.0f, 0.0f, 2.6469779601696886e-21f, 750.0f, 7.449861527675239e-07f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 108 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801AAA5C_136EEC },
};
