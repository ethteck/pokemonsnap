#include "tunnel.h"

EnvSoundData tunnel_EnvSounds[] = {
    { SOUND_ID_361, PITCH_MOD_1, 20 },
    { SOUND_ID_362, PITCH_MOD_1, 30 },
    { SOUND_ID_51, PITCH_MOD_4, 30 },
    { SOUND_ID_50, PITCH_MOD_4, 30 },
    { SOUND_ID_49, PITCH_MOD_4, 30 },
    { SOUND_ID_327, PITCH_MOD_1, 7 },
    { SOUND_ID_220, PITCH_MOD_1, 9 },
    { SOUND_ID_221, PITCH_MOD_1, 9 },
    { SOUND_ID_222, PITCH_MOD_1, 9 },
    { SOUND_ID_219, PITCH_MOD_1, 10 },
    { SOUND_ID_218, PITCH_MOD_1, 6 },
    { SOUND_ID_204, PITCH_MOD_1, 10 },
    { SOUND_ID_209, PITCH_MOD_1, 10 },
    { SOUND_ID_207, PITCH_MOD_1, 10 },
    { SOUND_ID_205, PITCH_MOD_1, 10 },
    { SOUND_ID_206, PITCH_MOD_1, 10 },
    { SOUND_ID_208, PITCH_MOD_1, 10 },
    { SOUND_ID_105, PITCH_MOD_0, 5 },
    { SOUND_ID_393, PITCH_MOD_0, 15 },
    { SOUND_ID_104, PITCH_MOD_0, 10 },
    { SOUND_ID_151, PITCH_MOD_2, 8 },
    { SOUND_ID_210, PITCH_MOD_1, 8 },
    { SOUND_ID_211, PITCH_MOD_1, 8 },
    { SOUND_ID_376, PITCH_MOD_0, 8 },
    { SOUND_ID_114, PITCH_MOD_0, 8 },
    { SOUND_ID_135, PITCH_MOD_0, 14 },
    { SOUND_ID_60, PITCH_MOD_0, 14 },
    { SOUND_ID_263, PITCH_MOD_1, 8 },
    { SOUND_ID_264, PITCH_MOD_1, 10 },
    { SOUND_ID_265, PITCH_MOD_1, 8 },
    { SOUND_ID_266, PITCH_MOD_1, 8 },
    { SOUND_ID_267, PITCH_MOD_2, 8 },
    { SOUND_ID_268, PITCH_MOD_2, 8 },
    { SOUND_ID_371, PITCH_MOD_0, 8 },
    { SOUND_ID_127, PITCH_MOD_0, 10 },
    { SOUND_ID_360, PITCH_MOD_0, 10 },
    { SOUND_ID_353, PITCH_MOD_1, 10 },
    { SOUND_ID_119, PITCH_MOD_0, 15 },
    { SOUND_ID_137, PITCH_MOD_0, 15 },
    { SOUND_ID_134, PITCH_MOD_0, 15 },
    { SOUND_ID_139, PITCH_MOD_0, 15 },
    { SOUND_ID_309, PITCH_MOD_1, 5 },
    { SOUND_ID_133, PITCH_MOD_0, 5 },
};

PokemonDef tunnel_PokemonDefs[] = {
    { PokemonID_MAGNEMITE,
      func_802E4AFC_5E1BCC,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_MAGNETON,
      func_802E505C_5E212C,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_ELECTRODE,
      func_802E5C74_5E2D44,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_DIGLETT,
      func_802E6420_5E34F0,
      pokemonChangeBlockOnGround,
      func_802E6458_5E3528 },
    { PokemonID_DUGTRIO,
      func_802E6C28_5E3CF8,
      pokemonChangeBlockOnGround,
      func_802E6C74_5E3D44 },
    { PokemonID_KAKUNA,
      func_802E7620_5E46F0,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_PIKACHU,
      func_802E9390_5E6460,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_ELECTABUZZ,
      func_802EA424_5E74F4,
      pokemonChangeBlock,
      func_802EA45C_5E752C },
    { PokemonID_ZAPDOS,
      func_802EB818_5E88E8,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_ZAPDOS_EGG,
      func_802EC3BC_5E948C,
      pokemonChangeBlock,
      func_802EC398_5E9468 },
    { PokemonID_ZUBAT,
      func_802EBBA8_5E8C78,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_HAUNTER,
      func_802EBCE8_5E8DB8,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_MAGIKARP,
      func_802EBF04_5E8FD4,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_1009,
      func_802EAF18_5E7FE8,
      pokemonChangeBlock,
      NULL },
    { PokemonID_1003,
      func_8035E0D4_4FE4E4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1008,
      func_802EA6F8_5E77C8,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1010,
      func_802EB3A8_5E8478,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1012,
      func_802EC720_5E97F0,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1013,
      func_802ECA80_5E9B50,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1014,
      func_802EDEC0_5EAF90,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_GATE,
      func_802ECFC8_5EA098,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

u16 D_802EE10C_5EB1DC = false;

PokemonDef tunnel_MagikarpDef = {
    0x81,
    func_802EBF04_5E8FD4,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

RandomState2 tunnel_MagikarpProbabilities[2] = {
    { 3, tunnel_SpawnMagikarp },
    { 4, NULL }
};

s32 tunnel_EndLEvelReason = 0;

ScreenSettings tunnel_ScreenSettings = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00000A99     /* flags*/
};

SceneSetup tunnel_SceneSetup = {
    {
        0,                      /* unk_00*/
        omUpdateAll,            /* fnUpdate */
        omDrawAll,              /* fnDraw */
        tunnel_assets_VRAM_END, /* heapBase */
        0,                      /* heapSize */
        1,                      /* unk_14 */
        2,                      /* numContexts */
        0x5400,                 /* dlBufferSize0 */
        0x0C00,                 /* dlBufferSize1 */
        0x0400,                 /* dlBufferSize2 */
        0x0000,                 /* dlBufferSize3 */
        0xC800,                 /* gfxHeapSize */
        2,                      /* unk30 */
        0x4000,                 /* rdpOutputBufferSize */
        func_800A1A50,          /* fnPreRender */
        contUpdate              /* fnUpdateInput */
    },
    0,                    /* numOMThreads */
    1088,                 /* omThreadStackSize */
    0,                    /* numOMStacks */
    0,                    /* unk4C */
    0,                    /* numOMProcesses */
    0,                    /* numOMGobjs */
    sizeof(GObj),         /* objectSize */
    0,                    /* numOMMtx */
    0,                    /* unk60 */
    func_802E2BB0_5DFC80, /* unk64 */
    0,                    /* numOMAobjs */
    0,                    /* numOMMobjs */
    0,                    /* numOMDobjs */
    sizeof(DObj),         /* omDobjSize */
    0,                    /* numOMSobjs */
    0x58,                 /* omSobjSize */
    0,                    /* numOMCameras */
    sizeof(OMCamera),     /* omCameraSize */
    tunnel_Init           /* postInitFunc */
};

extern s32 D_803430E8_6401B8;

void tunnel_SpawnMagikarp(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = tunnel_MagikarpDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_MAGIKARP;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &obj->data.dobj->position;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    GET_POKEMON(pokemonObj)->behavior = 0;
}

void tunnel_HandleCollision(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    s32 i;
    s32 numOptions = ARRAY_COUNT(tunnel_MagikarpProbabilities);
    s32 sumWeight;
    s32 randValue;

    if (groundResult->surfaceType == SURFACE_TYPE_337FB2 && Vec3fDistance(&GET_TRANSFORM(gPlayerDObj)->pos.v, &model->position.v) > 50.0f) {
        sumWeight = 0;
        for (i = 0; i < numOptions; i++) {
            sumWeight += tunnel_MagikarpProbabilities[i].weight;
        }
        randValue = randRange(sumWeight);
        sumWeight = 0;
        for (i = 0; i < numOptions; i++) {
            sumWeight += tunnel_MagikarpProbabilities[i].weight;
            if (sumWeight > randValue) {
                if (tunnel_MagikarpProbabilities[i].func != NULL && !D_802EE10C_5EB1DC) {
                    tunnel_MagikarpProbabilities[i].func(obj);
                    D_802EE10C_5EB1DC = true;
                }
                break;
            }
        }
    }
}

void tunnel_PokemonAdd(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, tunnel_PokemonDefs);
}

void tunnel_PokemonChangeBlock(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, tunnel_PokemonDefs);
}

void tunnel_PokemonRemove(WorldBlock* arg0) {
    pokemonRemove(arg0, tunnel_PokemonDefs);
}

void tunnel_InitWorld(void) {
    setHeightMap(&D_80326EE0_623FB0);
    setCeilingMap(&D_80326EE8_623FB8);
    createWorld(&tunnel_WorldSetup, OBJID_SKYBOX, OBJID_WORLD_BLOCK_MIN, OBJID_WORLD_BLOCK_MAX, LINK_PLAYER, DL_LINK_3, tunnel_PokemonAdd, tunnel_PokemonRemove, tunnel_PokemonChangeBlock);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(OBJID_128, OBJID_228, LINK_POKEMON, 5);
}

void tunnel_EndLevel(s32 endLevelReason) {
    tunnel_EndLEvelReason = endLevelReason;
    func_800A19D8(endLevelReason);
    PokemonDetector_Disable();
    EnvSound_Cleanup();
    auStopBGM();
    auStopAllSounds();
    destroyWorld();
    func_80356FBC_4F73CC();
    removeMainCamera();
    func_800067DC();
}

void func_802E28A4_5DF974(GObj* obj) {
}

void tunnel_Pause(s32 arg0) {
}

void tunnel_ExitBlock(WorldBlock* arg0) {
    WorldBlock* next;

    if (tunnel_EndLEvelReason <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            tunnel_EndLevel(END_LEVEL_REASON_FINISH);
        }
    }
}

void tunnel_LoadEffects(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) ABE7A0_ROM_START, (u32) ABE7A0_ROM_END);
    temp_v0_2 = func_800A73C0((u32) ABEBD0_ROM_START, (u32) ABEBD0_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void tunnel_Init(void) {
    s32 i;
    u8 r, g, b;

    tunnel_ScreenSettings.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&tunnel_ScreenSettings);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(OBJID_0, func_802E28A4_5DF974, LINK_0, 0x80000000);
    Pokemons_Init();
    tunnel_InitWorld();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    if (func_8009A8E4() != 0) {
        setIdleScript(func_800A73C0((u32) AB1470_ROM_START, (u32) AB1470_ROM_END));
    }
    initUI(tunnel_ExitBlock, tunnel_UpdateSounds, NULL, 0, tunnel_HandleCollision);
    setEndLevelCallback(tunnel_EndLevel);
    setPauseCallback(tunnel_Pause);
    EnvSound_Init(tunnel_EnvSounds, ARRAY_COUNT(tunnel_EnvSounds));
    tunnel_LoadEffects();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802ED5C8_5EA698();
    D_803430E8_6401B8 = 0;
}

void func_802E2BB0_5DFC80(s32 arg0) {
}

s32 tunnel_Start(s32 arg0) {
    tunnel_SceneSetup.gtlSetup.heapSize = (uintptr_t) tunnel_code_VRAM - (uintptr_t) tunnel_assets_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&tunnel_SceneSetup);

    switch (tunnel_EndLEvelReason) {
        case END_LEVEL_REASON_RETRY:
            return SCENE_TUNNEL;
        case END_LEVEL_REASON_IDLE_FINISHED:
        case END_LEVEL_REASON_IDLE_INTERRUPTED:
            return SCENE_MAIN_MENU;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);
    return SCENE_OAKS_LAB_2;
}
