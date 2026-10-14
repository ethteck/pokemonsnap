/* ROM C92AC, VRAM 8013CE1C: complete native animation command stream. */
struct native_a74f0_Animation8013CE1C D_8013CE1C_C92AC = {
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.5f, 1.5f, 1.5f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 60, { 1.5f, 1.5f, 1.5f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.29874280095100403f, 0.28330129384994507f, 0.286972314119339f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 5, { 3.0f, 3.0f, 3.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 85, { 3.0f, 3.0f, 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 84 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
