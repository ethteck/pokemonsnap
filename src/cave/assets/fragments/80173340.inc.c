/* ROM 23F0F0, VRAM 80173340: complete native animation command stream. */
struct Cave_Animation80173340 D_80173340_23F0F0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -5.238691258568906e-09f, -7.450582728552035e-08f, 3.445894591891374e-08f, 1.043081283569336e-05f, 4.172325134277344e-05f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 116 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80173340_23F0F0 },
};
