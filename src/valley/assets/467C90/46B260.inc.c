/* ROM 46B260, VRAM 80174E20: struct ValleyAnimation80174E20. */
struct ValleyAnimation80174E20 D_80174E20_46B260 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFF00FFFF } },
    { (ANIM_CMD_12 << 25) | ((0) << 15) | 1 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 79 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80174E20_46B260 },
};
