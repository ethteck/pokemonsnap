/* ROM 24EC6C, VRAM 80182EBC: complete native animation command stream. */
struct Cave_Animation80182EBC D_80182EBC_24EC6C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 164.67515563964844f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
