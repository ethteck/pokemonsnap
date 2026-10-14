/* ROM 4E61F0, VRAM 80133E20: complete native animation command stream. */
struct bank_4A8170_Animation80133E20 D_80133E20_4E61F0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 10.014891624450684f, 17.526023864746094f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 110 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
