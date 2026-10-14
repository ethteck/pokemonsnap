/* ROM 2E1C18, VRAM 80171B48: complete native animation command stream. */
struct river_29A1A0_Animation80171B48 D_80171B48_2E1C18 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 44, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 44, { 2.421438694000244e-08f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 57 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80171B48_2E1C18 },
};
