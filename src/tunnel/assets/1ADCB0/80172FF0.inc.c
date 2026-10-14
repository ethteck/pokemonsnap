/* ROM 1B9150, VRAM 80172FF0: complete native animation command stream. */
struct tunnel_1ADCB0_Animation80172FF0 D_80172FF0_1B9150 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 51.199989318847656f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 16 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 5 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 10 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
