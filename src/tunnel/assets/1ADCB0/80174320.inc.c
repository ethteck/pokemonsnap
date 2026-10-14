/* ROM 1BA480, VRAM 80174320: complete native animation command stream. */
struct tunnel_1ADCB0_Animation80174320 D_80174320_1BA480 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 51.199989318847656f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80174320_1BA480 },
};
