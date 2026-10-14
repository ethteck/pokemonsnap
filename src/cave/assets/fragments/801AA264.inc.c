/* ROM 276014, VRAM 801AA264: complete native animation command stream. */
struct Cave_Animation801AA264 D_801AA264_276014 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSY) << 15) | 0, { 1000.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 14 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 25 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 20 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
