/* ROM 2DE4F4, VRAM 8016E424: complete native animation command stream. */
struct river_29A1A0_Animation8016E424 D_8016E424_2DE4F4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 62.0f, 30.000001907348633f, -163.81809997558594f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016E424_2DE4F4 },
};
