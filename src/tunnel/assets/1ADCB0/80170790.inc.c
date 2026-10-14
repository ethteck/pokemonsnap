/* ROM 1B68F0, VRAM 80170790: complete native animation command stream. */
struct tunnel_1ADCB0_Animation80170790 D_80170790_1B68F0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80170790_1B68F0 },
};
