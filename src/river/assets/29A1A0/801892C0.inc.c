/* ROM 2F9390, VRAM 801892C0: complete native animation command stream. */
struct river_29A1A0_Animation801892C0 D_801892C0_2F9390 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ) << 15) | 0, { 0.2617993950843811f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 21, { 0.28306227922439575f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 19, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801892C0_2F9390 },
};
