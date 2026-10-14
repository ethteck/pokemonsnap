/* ROM 264E5C, VRAM 801990AC: complete native animation command stream. */
struct Cave_Animation801990AC D_801990AC_264E5C = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 14 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 8 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 51 },
    { (ANIM_CMD_16 << 25) | ((0x302) << 15) | 47 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801990AC_264E5C },
};
