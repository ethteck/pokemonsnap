/* ROM 10AD5C, VRAM 8017E8CC: complete native animation command stream. */
struct native_105E80_snorlax_Animation8017E8CC D_8017E8CC_10AD5C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 8 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
