/* ROM 4EA90C, VRAM 8013853C: complete native animation command stream. */
struct bank_4A8170_Animation8013853C D_8013853C_4EA90C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.15000000596046448f, 0.0f, 0.0f, 0.0f, -10.289999961853027f, 22.15999984741211f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 135 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8013853C_4EA90C },
};
