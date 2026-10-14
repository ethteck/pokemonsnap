/* 0x803824B4: native struct MainMenuAnimation803824B4. */
struct MainMenuAnimation803824B4 {
    AnimLine1 command_803824B4;
    AnimLine2 command_803824BC;
    AnimLine3 command_803824C8;
    AnimLine2 command_803824D8;
    AnimLine1 command_803824E4;
    AnimLine3 command_803824EC;
    AnimLine0 command_803824FC;
};

struct MainMenuAnimation803824B4 D_803824B4_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSZ) << 15) | 0, { 2066.366943359375f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSX | POSY) << 15) | 0, { 1473.527587890625f, -1229.601318359375f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.19238348305225372f, -3.0535666942596436f, -0.537583589553833f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSX | POSY) << 15) | 345, { 1495.7138671875f, -1227.843505859375f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSZ) << 15) | 345, { 1426.408447265625f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 1515, { 1495.7138671875f, -1227.843505859375f, 1426.408447265625f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
