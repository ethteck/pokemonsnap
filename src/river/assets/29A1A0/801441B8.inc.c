/* ROM 2B4288, VRAM 801441B8: complete native animation command stream. */
struct river_29A1A0_Animation801441B8 D_801441B8_2B4288 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, -47.89198303222656f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801441B8_2B4288 },
};
