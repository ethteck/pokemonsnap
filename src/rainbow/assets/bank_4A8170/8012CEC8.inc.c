/* ROM 4DF298, VRAM 8012CEC8: complete native animation command stream. */
struct bank_4A8170_Animation8012CEC8 D_8012CEC8_4DF298 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -21.439998626708984f, -6.55999755859375f, 13.15000057220459f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CEC8_4DF298 },
};
