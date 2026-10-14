/* ROM 223C9C, VRAM 80157EEC: complete native animation command stream. */
struct Cave_Animation80157EEC D_80157EEC_223C9C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -5.163061618804932f, 106.10499572753906f, 166.04161071777344f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 36 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80157EEC_223C9C },
};
