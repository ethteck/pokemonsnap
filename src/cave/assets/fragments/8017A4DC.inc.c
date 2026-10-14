/* ROM 24628C, VRAM 8017A4DC: complete native animation command stream. */
struct Cave_Animation8017A4DC D_8017A4DC_24628C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { 1200.0f } },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 60, { 600.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A4DC_24628C },
};
