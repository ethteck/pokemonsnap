/* ROM 213910, VRAM 80147B60: complete native animation command stream. */
struct Cave_Animation80147B60 D_80147B60_213910 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.6981316804885864f, 0.0f, 0.0f, 0.0f, -30.048728942871094f, -58.51061248779297f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
