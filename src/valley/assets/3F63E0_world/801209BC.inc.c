/* ROM 416DFC, VRAM 801209BC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation801209BC D_801209BC_416DFC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 4.656612873077393e-10f, 0.0f, -3.187385082244873f, -20.648801803588867f, 29.48947525024414f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 89 },
    { (ANIM_CMD_16 << 25) | ((0x14) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x14) << 15) | 51 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
