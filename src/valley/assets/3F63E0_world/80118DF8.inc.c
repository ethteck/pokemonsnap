/* ROM 40F238, VRAM 80118DF8: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80118DF8 D_80118DF8_40F238 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118DF8_40F238 },
};
