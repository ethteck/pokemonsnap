/* ROM 4E0508, VRAM 8012E138: complete native animation command stream. */
struct bank_4A8170_Animation8012E138 D_8012E138_4E0508 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 10.014891624450684f, 17.526023864746094f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_12 << 25) | ((0) << 15) | 50 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012E138_4E0508 },
};
