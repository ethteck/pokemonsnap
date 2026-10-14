/* ROM 416F20, VRAM 80120AE0: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80120AE0 D_80120AE0_416F20 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.17459514737129211f, 0.026913534849882126f, 0.004684454295784235f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
