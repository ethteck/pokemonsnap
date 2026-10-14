/* ROM 26FE5C, VRAM 801A40AC: complete native animation command stream. */
struct Cave_Animation801A40AC D_801A40AC_26FE5C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A40AC_26FE5C },
};
