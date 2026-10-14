/* ROM 274A04, VRAM 801A8C54: complete native animation command stream. */
struct Cave_Animation801A8C54 D_801A8C54_274A04 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSY) << 15) | 0, { 1000.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 59 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A8C54_274A04 },
};
