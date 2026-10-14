/* ROM 227EE4, VRAM 8015C134: complete native animation command stream. */
struct Cave_Animation8015C134 D_8015C134_227EE4 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 0, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T) << 15) | 73, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
