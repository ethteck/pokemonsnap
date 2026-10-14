/* ROM 43B880, VRAM 80145440: struct ValleyAnimation80145440. */
struct ValleyAnimation80145440 D_80145440_43B880 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSY) << 15) | 0, { 1395.8050537109375f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 8 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 31 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 21 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80145440_43B880 },
};
