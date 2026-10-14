/* ROM C79B0, VRAM 8013B520: complete native animation command stream. */
struct native_a74f0_Animation8013B520 D_8013B520_C79B0 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { -2.4511289596557617f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.13962633907794952f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 15, { -2.4511289596557617f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 90, { -2.0071287155151367f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 45, { -2.0071287155151367f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
