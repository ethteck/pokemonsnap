#include "volcano.h"
#include "app_render/particle.h"

__ALIGNER2

EnvSoundData volcano_EnvSounds[] = {
    { SOUND_ID_58, PITCH_MOD_0, 15 },
    { SOUND_ID_59, PITCH_MOD_0, 18 },
    { SOUND_ID_62, PITCH_MOD_0, 18 },
    { SOUND_ID_60, PITCH_MOD_0, 35 },
    { SOUND_ID_61, PITCH_MOD_0, 35 },
    { SOUND_ID_283, PITCH_MOD_1, 10 },
    { SOUND_ID_284, PITCH_MOD_1, 10 },
    { SOUND_ID_285, PITCH_MOD_1, 10 },
    { SOUND_ID_286, PITCH_MOD_1, 10 },
    { SOUND_ID_287, PITCH_MOD_1, 10 },
    { SOUND_ID_141, PITCH_MOD_0, 10 },
    { SOUND_ID_189, PITCH_MOD_3, 30 },
    { SOUND_ID_139, PITCH_MOD_0, 22 },
    { SOUND_ID_120, PITCH_MOD_0, 18 },
    { SOUND_ID_347, PITCH_MOD_1, 11 },
    { SOUND_ID_128, PITCH_MOD_0, 8 },
    { SOUND_ID_129, PITCH_MOD_0, 8 },
    { SOUND_ID_130, PITCH_MOD_0, 8 },
    { SOUND_ID_131, PITCH_MOD_0, 8 },
    { SOUND_ID_274, PITCH_MOD_1, 13 },
    { SOUND_ID_275, PITCH_MOD_1, 13 },
    { SOUND_ID_276, PITCH_MOD_1, 13 },
    { SOUND_ID_277, PITCH_MOD_1, 13 },
    { SOUND_ID_117, PITCH_MOD_0, 11 },
    { SOUND_ID_279, PITCH_MOD_1, 6 },
    { SOUND_ID_280, PITCH_MOD_1, 6 },
    { SOUND_ID_281, PITCH_MOD_1, 6 },
    { SOUND_ID_282, PITCH_MOD_1, 6 },
    { SOUND_ID_278, PITCH_MOD_1, 6 },
    { SOUND_ID_373, PITCH_MOD_0, 5 },
    { SOUND_ID_134, PITCH_MOD_0, 12 },
    { SOUND_ID_395, PITCH_MOD_0, 12 },
    { SOUND_ID_210, PITCH_MOD_1, 7 },
    { SOUND_ID_211, PITCH_MOD_1, 7 },
    { SOUND_ID_376, PITCH_MOD_0, 7 },
    { SOUND_ID_114, PITCH_MOD_0, 7 },
    { SOUND_ID_288, PITCH_MOD_1, 15 },
    { SOUND_ID_289, PITCH_MOD_1, 15 },
    { SOUND_ID_290, PITCH_MOD_1, 15 },
    { SOUND_ID_190, PITCH_MOD_1, 45 },
    { SOUND_ID_191, PITCH_MOD_1, 45 },
    { SOUND_ID_140, PITCH_MOD_0, 45 },
    { SOUND_ID_291, PITCH_MOD_1, 7 },
    { SOUND_ID_292, PITCH_MOD_1, 7 },
    { SOUND_ID_270, PITCH_MOD_1, 17 },
    { SOUND_ID_271, PITCH_MOD_1, 17 },
    { SOUND_ID_272, PITCH_MOD_1, 17 },
    { SOUND_ID_273, PITCH_MOD_1, 17 },
    { SOUND_ID_388, PITCH_MOD_0, 16 },
};

PokemonDef volcano_PokemonDefs[] = {
    { PokemonID_MAGMAR,
      magmar_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_RAPIDASH,
      rapidash_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_CHARMANDER,
      charmander_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_VULPIX,
      vulpix_Spawn,
      Pokemon_ChangeBlockAndRemove,
      pokemonRemoveOne },
    { PokemonID_CHARMELEON,
      charmeleon_Spawn,
      volcano_CharmeleonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_CHARIZARD,
      charizard_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_ARCANINE,
      arcanine_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_GROWLITHE,
      growlithe_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_SMOKE_SPAWNER,
      smoke_spawner_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_SMOKE_PUFF,
      smoke_puff_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_KOFFING_SMOKE,
      koffing_smoke_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_EVOLUTION_CONTROLLER,
      evolution_controller_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_MOLTRES_EGG,
      moltres_egg_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_MOLTRES,
      moltres_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_MAGIKARP,
      volcano_magikarp_Spawn,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_1003,
      func_8035E0D4_4FE4E4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_GROWLITHE_SPAWNER,
      growlithe_spawner_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_LAVA_SPLASH,
      lava_splash_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_VOLCANO_SMOKE,
      volcano_smoke_Spawn,
      pokemonChangeBlock,
      NULL },
    { PokemonID_GATE,
      volcano_gate_Spawn,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

PokemonDef volcano_MagikarpDef = {
    PokemonID_MAGIKARP,
    volcano_magikarp_Spawn,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

RandomState2 volcano_MagikarpProbabilities[] = {
    { 3, volcano_SpawnMagikarp },
    { 7, NULL },
};

u16 volcano_MagikarpHasSpawned = false;
s32 volcano_EndLevelReason = 0;

ScreenSettings volcano_ScreenSettings = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00000A99     /* flags*/
};

SceneSetup volcano_SceneSetup = {
    {
        0,                       /* unk_00*/
        omUpdateAll,             /* fnUpdate */
        omDrawAll,               /* fnDraw */
        volcano_assets_VRAM_END, /* heapBase */
        0,                       /* heapSize */
        1,                       /* unk_14 */
        2,                       /* numContexts */
        0x5000,                  /* dlBufferSize0 */
        0x1400,                  /* dlBufferSize1 */
        0x0400,                  /* dlBufferSize2 */
        0x0000,                  /* dlBufferSize3 */
        0xC800,                  /* gfxHeapSize */
        2,                       /* unk30 */
        0x4000,                  /* rdpOutputBufferSize */
        func_800A1A50,           /* fnPreRender */
        contUpdate               /* fnUpdateInput */
    },
    0,                            /* numOMThreads */
    1024,                         /* omThreadStackSize */
    0,                            /* numOMStacks */
    0,                            /* unk4C */
    0,                            /* numOMProcesses */
    0,                            /* numOMGobjs */
    sizeof(GObj),                 /* objectSize */
    0,                            /* numOMMtx */
    0,                            /* unk60 */
    volcano_func_802D6780_727980, /* unk64 */
    0,                            /* numOMAobjs */
    0,                            /* numOMMobjs */
    0,                            /* numOMDobjs */
    sizeof(DObj),                 /* omDobjSize */
    0,                            /* numOMSobjs */
    0x58,                         /* omSobjSize */
    0,                            /* numOMCameras */
    sizeof(OMCamera),             /* omCameraSize */
    volcano_Init                  /* postInitFunc */
};

PokemonDef volcano_ArcanineDef = {
    PokemonID_ARCANINE,
    arcanine_Spawn,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

PokemonDef volcano_GrowlitheDef = {
    PokemonID_GROWLITHE,
    growlithe_Spawn,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

PokemonDef volcano_CharizardDef = {
    PokemonID_CHARIZARD,
    charizard_Spawn,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

PokemonDef volcano_LavaSplashDef = {
    PokemonID_LAVA_SPLASH,
    lava_splash_Spawn,
    pokemonChangeBlock,
    pokemonRemoveOne
};

u16 volcano_GrowlitheAndArcanineCounter = 4;

Vec3f D_802E0FA8_7321A8 = { 0, 0, 0 };

void volcano_SpawnMagikarp(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_MagikarpDef;

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
}

void volcano_HandleCollision(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    s32 i;
    s32 numOptions = ARRAY_COUNT(volcano_MagikarpProbabilities);
    s32 sumWeight;
    s32 randValue;

    if (groundResult->surfaceType != SURFACE_TYPE_00FF00) {
        if (groundResult->surfaceType == SURFACE_TYPE_337FB2 && Vec3fDistance(&GET_TRANSFORM(gPlayerDObj)->pos.v, &model->position.v) > 50.0f) {
            sumWeight = 0;
            for (i = 0; i < numOptions; i++) {
                sumWeight += volcano_MagikarpProbabilities[i].weight;
            }
            randValue = randRange(sumWeight);
            sumWeight = 0;
            for (i = 0; i < numOptions; i++) {
                sumWeight += volcano_MagikarpProbabilities[i].weight;
                if (sumWeight > randValue) {
                    if (volcano_MagikarpProbabilities[i].func != NULL && !volcano_MagikarpHasSpawned) {
                        volcano_MagikarpProbabilities[i].func(obj);
                        volcano_MagikarpHasSpawned = true;
                    }
                    break;
                }
            }
        }
    } else if (item->itemID == ITEM_ID_PESTER_BALL) {
        cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_PESTER_BALL_IN_LAVA, obj);
    }
}

void volcano_PokemonAdd(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, volcano_PokemonDefs);
}

void volcano_PokemonChangeBlock(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, volcano_PokemonDefs);
}

void volcano_PokemonRemove(WorldBlock* arg0) {
    pokemonRemove(arg0, volcano_PokemonDefs);
}

void volcano_InitWorld(void) {
    setHeightMap(&volcano_heightMap);
    createWorld(&volcano_WorldSetup, OBJID_SKYBOX, OBJID_WORLD_BLOCK_MIN, OBJID_WORLD_BLOCK_MAX, LINK_PLAYER, DL_LINK_3, volcano_PokemonAdd, volcano_PokemonRemove, volcano_PokemonChangeBlock);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(OBJID_128, OBJID_228, LINK_POKEMON, 5);
}

void volcano_EndLevel(s32 endLevelReason) {
    volcano_EndLevelReason = endLevelReason;
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

void volcano_func_802D64A0_7276A0(GObj* obj) {
}

void volcano_Pause(s32 arg0) {
}

void volcano_ExitBlock(WorldBlock* arg0) {
    WorldBlock* next;

    if (volcano_EndLevelReason <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            volcano_EndLevel(END_LEVEL_REASON_FINISH);
        }
    }
}

void volcano_LoadEffects(void) {
    void* scriptDesc;
    void* spritesDesc;

    scriptDesc = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    spritesDesc = func_800A73C0((u32) particle_common_ROM_START, (u32) particle_common_ROM_END);
    if (scriptDesc != NULL && spritesDesc != NULL) {
        particle_setupBankID(3, scriptDesc, spritesDesc);
    }
    scriptDesc = func_800A73C0((u32) ACF6F0_ROM_START, (u32) ACF6F0_ROM_END);
    spritesDesc = func_800A73C0((u32) particle_volcano_ROM_START, (u32) particle_volcano_ROM_END);
    if (scriptDesc != NULL && spritesDesc != NULL) {
        particle_setupBankID(0, scriptDesc, spritesDesc);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = particle_allocGenerators(0xA);
    particle_setDitherModes(G_CD_DISABLE, G_AD_DISABLE);
}

void volcano_Init(void) {
    s32 i;
    u8 r, g, b;

    volcano_ScreenSettings.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&volcano_ScreenSettings);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(particle_SpriteBanksNum); i++) { particle_ScriptBanksNum[i] = particle_SpriteBanksNum[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(OBJID_0, volcano_func_802D64A0_7276A0, LINK_0, 0x80000000);
    Pokemons_Init();
    volcano_InitWorld();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    initUI(volcano_ExitBlock, volcano_UpdateSounds, NULL, 0, volcano_HandleCollision);
    setEndLevelCallback(volcano_EndLevel);
    setPauseCallback(volcano_Pause);
    EnvSound_Init(volcano_EnvSounds, ARRAY_COUNT(volcano_EnvSounds));
    volcano_LoadEffects();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    volcano_StartIntro();
}

void volcano_func_802D6780_727980(s32 arg0) {
}

void volcano_CheckIllegalCopy(void) {
    if (!gSPImemOkay || !gSPDmemOkay) {
        setPlayerFlag(PFID_ILLEGAL_COPY, true);
    }
}

s32 volcano_Start(s32 arg0) {
    volcano_SceneSetup.gtlSetup.heapSize = (uintptr_t) volcano_code_VRAM - (uintptr_t) volcano_assets_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    volcano_CheckIllegalCopy();
    omSetupScene(&volcano_SceneSetup);
    if (volcano_EndLevelReason == END_LEVEL_REASON_RETRY) {
        return SCENE_VOLCANO;
    }
    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }
    func_800AAED0(0x10);
    return SCENE_OAKS_LAB_2;
}

void volcano_SpawnArcanine(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_ArcanineDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_ARCANINE;
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

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void volcano_SpawnGrowlithe(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_GrowlitheDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_GROWLITHE;
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

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void volcano_CharmeleonChangeBlock(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    pokemonChangeBlockOnGround(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

void volcano_SpawnCharizard(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_CharizardDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_CHARIZARD;
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

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
}

void volcano_CreateSplashFromGrowlitheSpawner(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &volcano_LavaSplashDef);
    GET_POKEMON(var)->behavior = 0;
    omEndProcess(NULL);
}

void volcano_CreateSplashFromGrowlitheOrArcanine(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &volcano_LavaSplashDef);
    GET_POKEMON(var)->behavior = 4;
    GET_POKEMON(obj)->miscVars[1].obj = var;
    omEndProcess(NULL);
}

void volcano_CreateSplashFromMoltres(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &volcano_LavaSplashDef);
    GET_POKEMON(var)->behavior = 1;
    GET_TRANSFORM(var->data.dobj)->scale.v.x *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.y *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.z *= 4.0f;
    omEndProcess(NULL);
}

void volcano_CreateSplashFromMoltresEgg(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &volcano_LavaSplashDef);
    GET_POKEMON(var)->behavior = 5;
    GET_TRANSFORM(var->data.dobj)->scale.v.x *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.y *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.z *= 4.0f;
    omEndProcess(NULL);
}

void volcano_CreateSplashFromCharmeleon(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &volcano_LavaSplashDef);
    GET_POKEMON(var)->behavior = 5;
    omEndProcess(NULL);
}

void volcano_CreateSplashFromCharizard(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &volcano_LavaSplashDef);
    GET_POKEMON(var)->behavior = 2;
    GET_TRANSFORM(var->data.dobj)->scale.v.x *= 1.0f;
    GET_TRANSFORM(var->data.dobj)->scale.v.y *= 1.0f;
    GET_TRANSFORM(var->data.dobj)->scale.v.z *= 2.0f;
    omEndProcess(NULL);
}

bool volcano_SpawnGrowlitheOrArcanine(GObj* obj) {
    u16 randomValue;

    randomValue = randRange(10);
    if (volcano_GrowlitheAndArcanineCounter == 0) {
        return false;
    }
    if (randomValue < 2) {
        // 20 %
        omCreateProcess(obj, volcano_SpawnArcanine, 1, 1);
    } else if (randomValue < 7) {
        // 50 %
        omCreateProcess(obj, volcano_SpawnGrowlithe, 1, 1);
    } else {
        // 30 %
        return false;
    }
    volcano_GrowlitheAndArcanineCounter--;
    return true;
}

void volcano_PokemonMove(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    f32 yaw = GET_TRANSFORM(model)->rot.v.y;
    f32 speedX = sinf(yaw) * hSpeed;
    f32 speedZ = cosf(yaw) * hSpeed;

    GET_TRANSFORM(model)->pos.v.x += speedX;
    GET_TRANSFORM(model)->pos.v.z += speedZ;
}

void volcano_PokemonMoveInDirection(GObj* obj, f32 heading) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    f32 speedX = sinf(heading) * hSpeed;
    f32 speedZ = cosf(heading) * hSpeed;

    GET_TRANSFORM(model)->pos.v.x += speedX;
    GET_TRANSFORM(model)->pos.v.z += speedZ;
}

f32 volcano_GetHeightAt(f32 x, f32 z) {
    GroundResult result;

    if (getGroundAt(x, z, &result)) {
        return result.height;
    }
    return 0.0f;
}

void volcano_FollowPath(GObj* obj, f32* pathParam, f32 pathEnd, f32 speedMult, s32 flags) {
    DObj* temp_s1 = obj->data.dobj;
    Vec3f sp88 = D_802E0FA8_7321A8;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 var_f20 = *pathParam;
    Vec3f sp74;
    f32 angle;
    f32 sp6C;

    while (true) {
        if (pokemon->path != NULL) {
            break;
        }
        ohWait(1);
    }

    sp6C = 1.0f / pokemon->path->duration * speedMult;

    while (true) {
        while (true) {
            if (var_f20 >= 0.0f && var_f20 <= 1.0f) {
                break;
            }
            ohWait(1);
        }
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED)) {
            GET_TRANSFORM(temp_s1)->pos.v.x -= sp88.x * 100.0f;
            GET_TRANSFORM(temp_s1)->pos.v.z -= sp88.z * 100.0f;
            if (flags & 1) {
                GET_TRANSFORM(temp_s1)->pos.v.y -= sp88.y;
            } else {
                GET_TRANSFORM(temp_s1)->pos.v.y -= sp88.y * 100.0f;
            }

            GetInterpolatedVelocity(&sp74, pokemon->path, var_f20);

            angle = atan2f(sp74.x, sp74.z);
            if (angle < 0.0f) {
                angle += TAU;
            } else if (angle > TAU) {
                angle -= (s32) (angle / TAU) * TAU;
            }
            GET_TRANSFORM(temp_s1)->rot.v.y = angle;

            switch (pokemon->path->type) {
                case 1:
                    GetInterpolatedPosition(&sp88, pokemon->path, var_f20);
                    break;
                case 2:
                    GetInterpolatedPosition(&sp88, pokemon->path, var_f20);
                    break;
                case 3:
                    GetInterpolatedPosition(&sp88, pokemon->path, var_f20);
                    break;
            }

            GET_TRANSFORM(temp_s1)->pos.v.x += sp88.x * 100.0f;
            GET_TRANSFORM(temp_s1)->pos.v.z += sp88.z * 100.0f;
            if (flags & 1) {
                sp88.y = volcano_GetHeightAt(GET_TRANSFORM(temp_s1)->pos.v.x, GET_TRANSFORM(temp_s1)->pos.v.z);
                GET_TRANSFORM(temp_s1)->pos.v.y += sp88.y;
            } else {
                GET_TRANSFORM(temp_s1)->pos.v.y += sp88.y * 100.0f;
            }

            var_f20 += sp6C;

            if (pathEnd > 0.0f && pathEnd < var_f20) {
                return;
            }
            if (var_f20 > 1.0f) {
                var_f20 -= 1.0f;
            }
            *pathParam = var_f20;
        }
        ohWait(1);
    }
}
