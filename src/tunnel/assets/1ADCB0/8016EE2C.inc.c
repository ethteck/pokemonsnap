/* ROM 1B4F8C, VRAM 8016EE2C: complete native animation command stream. */
struct tunnel_1ADCB0_Animation8016EE2C D_8016EE2C_1B4F8C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 8.270144462585449e-07f, 4.470348358154297e-08f, -9.313225746154785e-10f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 23 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016EE2C_1B4F8C },
};
