/* ROM 26C23C, VRAM 801A048C: complete native animation command stream. */
struct Cave_Animation801A048C D_801A048C_26C23C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A048C_26C23C },
};
