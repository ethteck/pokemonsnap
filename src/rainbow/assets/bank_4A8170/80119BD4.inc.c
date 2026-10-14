/* ROM 4CBFA4, VRAM 80119BD4: complete native animation command stream. */
struct bank_4A8170_Animation80119BD4 D_80119BD4_4CBFA4 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80119BBC_4CBF8C },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { -0.00019363030150998384f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((PATH_PARAM) << 15) | 60, { 0.550000011920929f, 0.01589340716600418f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0037395667750388384f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((PATH_PARAM) << 15) | 30, { 0.699999988079071f, 0.007499999832361937f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((PATH_PARAM) << 15) | 30, { 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
