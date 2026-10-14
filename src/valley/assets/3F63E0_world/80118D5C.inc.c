/* ROM 40F19C, VRAM 80118D5C: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80118D5C D_80118D5C_40F19C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118D5C_40F19C },
};
