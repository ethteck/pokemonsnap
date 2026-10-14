/* ROM 4CA36C, VRAM 80117F9C: complete native animation command stream. */
struct bank_4A8170_Animation80117F9C D_80117F9C_4CA36C = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFE600FF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { -1.862645149230957e-08f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 30, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 25, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 4, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 4, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 20, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 3 },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 4, { 3.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 5, { 4.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 4, { 5.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 4, { 5.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 90, { 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
