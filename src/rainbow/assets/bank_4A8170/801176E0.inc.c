/* ROM 4C9AB0, VRAM 801176E0: complete native animation command stream. */
struct bank_4A8170_Animation801176E0 D_801176E0_4C9AB0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEZ) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 0, { 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 25, { 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 15, { 8.0f, 8.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
