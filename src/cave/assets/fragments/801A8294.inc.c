/* ROM 274044, VRAM 801A8294: complete native animation command stream. */
struct Cave_Animation801A8294 D_801A8294_274044 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSY) << 15) | 0, { 1000.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 21 },
    { (ANIM_CMD_16 << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 9 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A8294_274044 },
};
