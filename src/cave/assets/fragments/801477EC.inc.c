/* ROM 21359C, VRAM 801477EC: complete native animation command stream. */
struct Cave_Animation801477EC D_801477EC_21359C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.6981316804885864f, 0.0f, 0.0f, 19.199975967407227f, -20.648849487304688f, 29.48945426940918f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
