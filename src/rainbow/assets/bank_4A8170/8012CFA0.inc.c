/* ROM 4DF370, VRAM 8012CFA0: complete native animation command stream. */
struct bank_4A8170_Animation8012CFA0 D_8012CFA0_4DF370 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.2800000011920929f, 0.0f, 0.0f, 0.0f, -9.498119354248047f, 11.872661590576172f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CFA0_4DF370 },
};
