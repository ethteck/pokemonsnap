/* ROM 10107C, VRAM 80174BEC: complete native animation command stream. */
struct native_F7AD0_kangaskhan_Animation80174BEC D_80174BEC_10107C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -3.308717401502317e-23f, -2.9253962533642985e-12f, 578.2371826171875f, -267.1535949707031f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80174BEC_10107C },
};
