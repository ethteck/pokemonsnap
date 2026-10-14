/* ROM 416F50, VRAM 80120B10: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80120B10 D_80120B10_416F50 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 4.656612873077393e-10f, 0.0f, 0.0f, -30.048728942871094f, -58.51061248779297f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
