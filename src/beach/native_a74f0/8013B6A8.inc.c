/* ROM C7B38, VRAM 8013B6A8: complete native animation command stream. */
struct native_a74f0_Animation8013B6A8 D_8013B6A8_C7B38 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.05728084594011307f, 0.43702393770217896f, -0.1942342221736908f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 15, { 0.05728084594011307f, 0.43702393770217896f, -0.1942342221736908f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 90, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 45, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
