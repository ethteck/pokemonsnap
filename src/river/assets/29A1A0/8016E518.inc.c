/* ROM 2DE5E8, VRAM 8016E518: complete native animation command stream. */
struct river_29A1A0_Animation8016E518 D_8016E518_2DE5E8 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 23.06444549560547f, 15.203487396240234f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 24, { 0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 26, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016E518_2DE5E8 },
};
