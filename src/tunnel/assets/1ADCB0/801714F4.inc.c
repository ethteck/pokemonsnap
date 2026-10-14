/* ROM 1B7654, VRAM 801714F4: complete native animation command stream. */
struct tunnel_1ADCB0_Animation801714F4 D_801714F4_1B7654 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.429999977350235f, 0.0f, 0.0f, 5.539178848266602f, -83.44506072998047f, -34.08803939819336f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801714F4_1B7654 },
};
