/* ROM 1A669C, VRAM 8016053C: complete native animation command stream. */
struct tunnel_1A6630_Animation8016053C D_8016053C_1A669C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 8, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 92, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 52 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016053C_1A669C },
};
