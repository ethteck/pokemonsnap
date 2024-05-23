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

enum PlayerFlagIDs {
    PFID_HAS_APPLE          = 0,
    PFID_HAS_PESTER_BALL    = 1,
    PFID_HAS_FLUTE          = 2,
    PFID_3                  = 3,
    PFID_4                  = 4,
    PFID_HAS_DASH_ENGINE    = 5,
    PFID_6                  = 6,
    PFID_7                  = 7,
    PFID_TUTORIAL_PASSED    = 8,
    PFID_9                  = 9,
    PFID_10                 = 10,
    PFID_11                 = 11,
    PFID_ZOOM_SWITCH        = 12,
    PFID_INVERTED_Y         = 13,
    PFID_14                 = 14,
    PFID_15                 = 15,
    PFID_16                 = 16,
    PFID_17                 = 17,
    PFID_18                 = 18,
    PFID_19                 = 19,
    PFID_20                 = 20,
    PFID_21                 = 21
};

enum PlayerFlags {
    PF_HAS_APPLE        = 0x000001,
    PF_HAS_PESTER_BALL  = 0x000002,
    PF_HAS_FLUTE        = 0x000004,
    PF_0008             = 0x000008,
    PF_0010             = 0x000010,
    PF_HAS_DASH_ENGINE  = 0x000020,
    PF_0040             = 0x000040,
    PF_0080             = 0x000080,
    PF_TUTORIAL_PASSED  = 0x000100,
    PF_0200             = 0x000200,
    PF_0400             = 0x000400,
    PF_0800             = 0x000800,
    PF_ZOOM_SWITCH      = 0x001000,
    PF_INVERTED_Y       = 0x002000,
    PF_4000             = 0x004000,
    PF_8000             = 0x008000,
    PF_10000            = 0x010000,
    PF_20000            = 0x020000,
    PF_40000            = 0x040000,
    PF_80000            = 0x080000,
    PF_100000           = 0x100000,
    PF_200000           = 0x200000
};

enum SoundIds {
    SOUND_ID_TAKE_PHOTO  =  0,
    SOUND_ID_1  =  1,
    SOUND_ID_2  =  2,
    SOUND_ID_4  =  4,
    SOUND_ID_5  =  5,
    SOUND_ID_6  =  6,
    SOUND_ID_8  =  8,
    SOUND_ID_9  =  9,
    SOUND_ID_10 = 10,
    SOUND_ID_11 = 11,
    SOUND_ID_12 = 12,
    SOUND_ID_14 = 14,
    SOUND_ID_15 = 15,
    SOUND_ID_TAKE_PHOTO_2 = 16,
    SOUND_ID_20 = 20,
    SOUND_ID_24 = 24,
    SOUND_ID_25 = 25,
    SOUND_ID_26 = 26,
    SOUND_ID_27 = 27,
    SOUND_ID_29 = 29,
    SOUND_ID_31 = 31,
    SOUND_ID_65 = 65,
    SOUND_ID_66 = 66
};

enum Links {
    LINK_0 = 0,
    LINK_POKEMON = 3,
    LINK_ITEM = 4,
    LINK_PLAYER = 9
};

enum CameraDlLinkMask {
    CAM_MASK_DL_LINK_0 = 0x01,
    CAM_MASK_DL_LINK_1 = 0x02,
    CAM_MASK_DL_LINK_2 = 0x04,
    CAM_MASK_DL_LINK_3 = 0x08,
    CAM_MASK_DL_LINK_4 = 0x10,
    CAM_MASK_DL_LINK_5 = 0x20,
    CAM_MASK_DL_LINK_6 = 0x40,
    CAM_MASK_DL_LINK_7 = 0x80
};

enum DlLinks {
    DL_LINK_1 = 1,
    DL_LINK_3 = 3,
    DL_LINK_5 = 5
};

enum ObjIDs {
    OBJID_0             = 0,
    OBJID_MAIN_CAMERA   = 1,
    OBJID_UI_CAMERA     = 3,
    OBJID_PLAYER        = 7,
    OBJID_BUMP_DETECTOR = 8,
    OBJID_UI_RETICLE    = 25,
    OBJID_UI_PAUSE      = 26
};

enum PokemonIds {
    PokemonID_PIDGEY     =   16,
    PokemonID_MAGNETON   =   82,
    PokemonID_MUK        =   89,
    PokemonID_SHELLDER   =   90,
    PokemonID_CHANSEY    =  113,
    PokemonID_STARYU     =  120,
    PokemonID_STARMIE    =  121,
    PokemonID_SCYTHER    =  123,
    PokemonID_MAGIKARP   =  129,
    PokemonID_MEW        =  151,
    POKEDEX_MAX          =  151,
    PokemonID_1004       = 1004,
    PokemonID_1007       = 1007,
    PokemonID_1010       = 1010,
    PokemonID_1018       = 1018,
    PokemonID_1022       = 1022,
    PokemonID_1035       = 1035
};

enum PokemonFlags {
    POKEMON_FLAG_2      = 0x002,
    POKEMON_FLAG_4      = 0x004,
    POKEMON_FLAG_8      = 0x008,
    POKEMON_FLAG_20     = 0x020,
    POKEMON_FLAG_80     = 0x080,
    POKEMON_FLAG_100    = 0x100
};

enum PokemonProcessFlags {
    POKEMON_PROCESS_FLAG_1   = 0x01,
    POKEMON_PROCESS_FLAG_2   = 0x02,
    POKEMON_PROCESS_FLAG_4   = 0x04,
    POKEMON_PROCESS_FLAG_8   = 0x08,
    POKEMON_PROCESS_FLAG_10  = 0x10,
    POKEMON_PROCESS_FLAG_20  = 0x20
};

#endif
