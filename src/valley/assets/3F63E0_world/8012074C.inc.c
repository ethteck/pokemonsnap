/* ROM 416B8C, VRAM 8012074C: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8012074C D_8012074C_416B8C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -4.656612873077393e-10f, 0.0f, 0.0f, -5.9604644775390625e-06f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
