/* ROM EDC14, VRAM 80161784: complete native animation command stream. */
struct native_E4E90_doduo_Animation80161784 D_80161784_EDC14 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80161784_EDC14 },
};
