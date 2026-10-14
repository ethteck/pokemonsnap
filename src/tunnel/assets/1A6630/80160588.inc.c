/* ROM 1A66E8, VRAM 80160588: complete native animation command stream. */
struct tunnel_1A6630_Animation80160588 D_80160588_1A66E8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80160588_1A66E8 },
};
