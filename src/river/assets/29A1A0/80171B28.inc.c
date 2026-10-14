/* ROM 2E1BF8, VRAM 80171B28: complete native animation command stream. */
struct river_29A1A0_Animation80171B28 D_80171B28_2E1BF8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 101 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80171B28_2E1BF8 },
};
