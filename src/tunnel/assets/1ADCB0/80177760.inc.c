/* ROM 1BD8C0, VRAM 80177760: complete native animation command stream. */
struct tunnel_1ADCB0_Animation80177760 D_80177760_1BD8C0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 2.0f, 0.004999999888241291f, 0.0f, 0.9900000095367432f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80177760_1BD8C0 },
};
