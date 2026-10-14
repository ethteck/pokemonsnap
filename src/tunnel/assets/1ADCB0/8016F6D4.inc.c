/* ROM 1B5834, VRAM 8016F6D4: complete native animation command stream. */
struct tunnel_1ADCB0_Animation8016F6D4 D_8016F6D4_1B5834 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 8.270144462585449e-07f, 4.470348358154297e-08f, -9.313225746154785e-10f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 23 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016F6D4_1B5834 },
};
