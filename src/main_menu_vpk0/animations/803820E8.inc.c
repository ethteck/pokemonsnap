/* 0x803820E8: native struct MainMenuAnimation803820E8. */
struct MainMenuAnimation803820E8 {
    AnimLine0 command_803820E8;
    AnimLine2 command_803820EC;
    AnimLine7 command_803820F8;
    AnimLine7 command_80382118;
    AnimLine2 command_80382138;
    AnimLine9 command_80382144;
    AnimLine0 command_8038216C;
    AnimLine0 command_80382170;
    AnimLine0 command_80382174;
    AnimLine0 command_80382178;
};

struct MainMenuAnimation803820E8 D_803820E8_main_menu_vpk0 = {
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSX | POSZ) << 15) | 0, { -4815.12841796875f, 27.31989097595215f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTY | ROTZ | POSY | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.4901161193847656e-08f, -1.1920928955078125e-07f, 1.7763568394002505e-15f, 1083.141845703125f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTY | ROTZ | POSY | SCALEX | SCALEY | SCALEZ) << 15) | 345, { -1.4901262446187502e-08f, 0.002318727783858776f, -2.0320169158427603e-11f, 1083.781005859375f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSX | POSZ) << 15) | 345, { -4763.46337890625f, -475.1292724609375f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 1515, { -1.4901262446187502e-08f, 0.002318727783858776f, -2.0320169158427603e-11f, -4763.46337890625f, 1083.781005859375f, -475.1292724609375f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 122 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 268 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 1125 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
