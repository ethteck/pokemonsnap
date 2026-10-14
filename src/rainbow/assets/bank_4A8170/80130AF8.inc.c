/* ROM 4E2EC8, VRAM 80130AF8: complete native animation command stream. */
struct bank_4A8170_Animation80130AF8 D_80130AF8_4E2EC8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -21.439998626708984f, -6.55999755859375f, 13.15000057220459f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 200 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
