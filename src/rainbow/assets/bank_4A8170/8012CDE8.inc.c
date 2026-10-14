/* ROM 4DF1B8, VRAM 8012CDE8: complete native animation command stream. */
struct bank_4A8170_Animation8012CDE8 D_8012CDE8_4DF1B8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 20.44011116027832f, -7.219987869262695f, 14.37197208404541f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CDE8_4DF1B8 },
};
