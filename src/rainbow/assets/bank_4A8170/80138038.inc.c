/* ROM 4EA408, VRAM 80138038: complete native animation command stream. */
struct bank_4A8170_Animation80138038 D_80138038_4EA408 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -21.439998626708984f, -6.55999755859375f, 13.15000057220459f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTY) << 15) | 30, { 0.0f, 0.014571428298950195f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 5, { 0.5099999904632568f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 100, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80138038_4EA408 },
};
