/* ROM 1A6660, VRAM 80160500: complete native animation command stream. */
struct tunnel_1A6630_Animation80160500 D_80160500_1A6660 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80160500_1A6660 },
};
