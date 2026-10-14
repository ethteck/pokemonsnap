/* ROM 1B5500, VRAM 8016F3A0: complete native animation command stream. */
struct tunnel_1ADCB0_Animation8016F3A0 D_8016F3A0_1B5500 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 11 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 8 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016F3A0_1B5500 },
};
