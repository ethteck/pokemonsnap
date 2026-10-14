/* ROM 4DF0CC, VRAM 8012CCFC: complete native animation command stream. */
struct bank_4A8170_Animation8012CCFC D_8012CCFC_4DF0CC = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 10.014891624450684f, 17.526023864746094f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_12 << 25) | ((0) << 15) | 50 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CCFC_4DF0CC },
};
