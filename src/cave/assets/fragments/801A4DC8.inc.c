/* ROM 270B78, VRAM 801A4DC8: complete native animation command stream. */
struct Cave_Animation801A4DC8 D_801A4DC8_270B78 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_12 << 25) | ((0) << 15) | 1 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 99 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
