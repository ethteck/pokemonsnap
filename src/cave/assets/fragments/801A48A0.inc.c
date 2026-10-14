/* ROM 270650, VRAM 801A48A0: complete native animation command stream. */
struct Cave_Animation801A48A0 D_801A48A0_270650 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEZ) << 15) | 0, { 3.0f, 3.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ | SCALEY) << 15) | 0, { 0.0f, 600.5308227539062f, 100.08841705322266f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEZ) << 15) | 4, { 3.0f, 3.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEZ) << 15) | 25, { 14.0f, 14.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEZ) << 15) | 70, { 14.0f, 14.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
