/* ROM 416B5C, VRAM 8012071C: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8012071C D_8012071C_416B5C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 4.656612873077393e-10f, 0.0f, 3.372035450865951e-08f, 6.556510925292969e-05f, 2.2601962089538574f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
