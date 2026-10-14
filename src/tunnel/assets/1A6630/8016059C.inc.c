/* ROM 1A66FC, VRAM 8016059C: complete native animation command stream. */
struct tunnel_1A6630_Animation8016059C D_8016059C_1A66FC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016059C_1A66FC },
};
