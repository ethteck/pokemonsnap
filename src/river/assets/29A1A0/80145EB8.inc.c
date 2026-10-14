/* ROM 2B5F88, VRAM 80145EB8: complete native animation command stream. */
struct river_29A1A0_Animation80145EB8 D_80145EB8_2B5F88 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80145EB8_2B5F88 },
};
