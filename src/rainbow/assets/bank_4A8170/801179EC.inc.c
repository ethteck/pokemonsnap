/* ROM 4C9DBC, VRAM 801179EC: complete native animation command stream. */
struct bank_4A8170_Animation801179EC D_801179EC_4C9DBC = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { -1.862645149230957e-08f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 25, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801179EC_4C9DBC },
};
