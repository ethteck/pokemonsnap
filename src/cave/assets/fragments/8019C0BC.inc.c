/* ROM 267E6C, VRAM 8019C0BC: complete native animation command stream. */
struct Cave_Animation8019C0BC D_8019C0BC_267E6C = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 31 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 58 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 31 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019C0BC_267E6C },
};
