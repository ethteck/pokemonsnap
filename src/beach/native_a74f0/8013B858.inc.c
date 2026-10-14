/* ROM C7CE8, VRAM 8013B858: complete native animation command stream. */
struct native_a74f0_Animation8013B858 D_8013B858_C7CE8 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { -1.0460002422332764f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 15, { -1.0460002422332764f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { 0.023666681721806526f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 15, { -0.33599981665611267f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 35, { -1.0460002422332764f, -0.012909099459648132f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 20, { -1.0460002422332764f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 65, { -1.0460002422332764f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
