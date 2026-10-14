/* ROM 4DF518, VRAM 8012D148: complete native animation command stream. */
struct bank_4A8170_Animation8012D148 D_8012D148_4DF518 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.3399999737739563f, 0.0f, 0.0f, 0.0f, -27.309999465942383f, 70.44000244140625f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012D148_4DF518 },
};
