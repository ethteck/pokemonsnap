/* ROM 4DF1EC, VRAM 8012CE1C: complete native animation command stream. */
struct bank_4A8170_Animation8012CE1C D_8012CE1C_4DF1EC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 21.144359588623047f, -6.5598907470703125f, 13.152737617492676f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CE1C_4DF1EC },
};
