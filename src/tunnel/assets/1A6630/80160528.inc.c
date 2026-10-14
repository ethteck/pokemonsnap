/* ROM 1A6688, VRAM 80160528: complete native animation command stream. */
struct tunnel_1A6630_Animation80160528 D_80160528_1A6688 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80160528_1A6688 },
};
