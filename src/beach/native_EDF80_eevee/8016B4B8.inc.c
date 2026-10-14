/* ROM F7948, VRAM 8016B4B8: complete native animation command stream. */
struct native_EDF80_eevee_Animation8016B4B8 D_8016B4B8_F7948 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 36 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016B4B8_F7948 },
};
