/* ROM 2FD798, VRAM 8018D6C8: complete native animation command stream. */
struct river_29A1A0_Animation8018D6C8 D_8018D6C8_2FD798 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f, -0.0005215634009800851f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -50.0f, 140.00001525878906f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 35, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
