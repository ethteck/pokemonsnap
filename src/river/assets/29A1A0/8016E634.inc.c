/* ROM 2DE704, VRAM 8016E634: complete native animation command stream. */
struct river_29A1A0_Animation8016E634 D_8016E634_2DE704 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -0.9857058525085449f, -145.60572814941406f, -5.9060516357421875f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016E634_2DE704 },
};
