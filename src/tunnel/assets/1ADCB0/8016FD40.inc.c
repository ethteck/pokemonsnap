/* ROM 1B5EA0, VRAM 8016FD40: complete native animation command stream. */
struct tunnel_1ADCB0_Animation8016FD40 D_8016FD40_1B5EA0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 51.199989318847656f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016FD40_1B5EA0 },
};
