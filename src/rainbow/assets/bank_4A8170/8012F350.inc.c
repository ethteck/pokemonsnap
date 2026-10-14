/* ROM 4E1720, VRAM 8012F350: complete native animation command stream. */
struct bank_4A8170_Animation8012F350 D_8012F350_4E1720 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 21.144359588623047f, -6.5598907470703125f, 13.152737617492676f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 70 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012F350_4E1720 },
};
