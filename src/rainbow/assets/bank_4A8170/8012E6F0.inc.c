/* ROM 4E0AC0, VRAM 8012E6F0: complete native animation command stream. */
struct bank_4A8170_Animation8012E6F0 D_8012E6F0_4E0AC0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.15000000596046448f, 0.0f, 0.0f, 0.0f, -10.289999961853027f, 22.15999984741211f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012E6F0_4E0AC0 },
};
