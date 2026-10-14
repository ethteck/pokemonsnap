/* ROM 1CD144, VRAM 80186FE4: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80186FE4 D_80186FE4_1CD144 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 20, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 10, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 20, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 15 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
