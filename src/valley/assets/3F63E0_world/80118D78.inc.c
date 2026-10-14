/* ROM 40F1B8, VRAM 80118D78: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80118D78 D_80118D78_40F1B8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, -47.89198303222656f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118D78_40F1B8 },
};
