#ifndef _ENUMS_H
#define _ENUMS_H

enum SceneIds {
    SCENE_BEACH = 0,
    SCENE_TUNNEL = 1,
    SCENE_VOLCANO = 2,
    SCENE_RIVER = 3,
    SCENE_CAVE = 4,
    SCENE_VALLEY = 5,
    SCENE_RAINBOW = 6,
    SCENE_7 = 7,
    SCENE_8 = 8,
    SCENE_CAMERA_CHECK = 9,
    SCENE_10 = 10,
    SCENE_11 = 11,
    SCENE_12 = 12,
    SCENE_13 = 13,
    SCENE_14 = 14,
    SCENE_15 = 15,
    SCENE_16 = 16,
    SCENE_CREDITS_17 = 17,
    SCENE_CREDITS_18 = 18,
    SCENE_CREDITS_19 = 19,
    SCENE_CREDITS_20 = 20,
    SCENE_21 = 21,
    SCENE_22 = 22,
    SCENE_23 = 23,
    SCENE_24 = 24
};

enum ProgressFlags {
    PF_HAS_APPLE        = 0x0001,
    PF_HAS_PESTER_BALL  = 0x0002,
    PF_HAS_FLUTE        = 0x0004,
    PF_0008             = 0x0008,
    PF_0010             = 0x0010,
    PF_HAS_DASH_ENGINE  = 0x0020,
    PF_0040             = 0x0040,
    PF_0080             = 0x0080,
    PF_0100             = 0x0100,
    PF_0200             = 0x0200,
    PF_0400             = 0x0400,
    PF_0800             = 0x0800,
    PF_CAN_ZOOM_OFF     = 0x1000, // not sure what it is
    PF_2000             = 0x2000,
    PF_4000             = 0x4000,
    PF_8000             = 0x8000
};

#endif
