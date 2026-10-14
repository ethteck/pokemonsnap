/* ROM 113828, VRAM 80187398: complete native animation command stream. */
struct native_110970_chansey_Animation80187398 D_80187398_113828 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTZ) << 15) | 0, { -0.13089969754219055f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 30, { 0.13089969754219055f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 30, { -0.13089969754219055f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187398_113828 },
};
