/* ROM 4CA738, VRAM 80118368: complete native animation command stream. */
struct bank_4A8170_Animation80118368 D_80118368_4CA738 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 20.0f, 20.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118368_4CA738 },
};
