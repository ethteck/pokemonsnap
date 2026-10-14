/* ROM 228078, VRAM 8015C2C8: complete native animation command stream. */
struct Cave_Animation8015C2C8 D_8015C2C8_228078 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 73 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
