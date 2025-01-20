#include "rainbow.h"
#include "ld_addrs.h"

extern f32 D_800F5DB0;

EnvSoundData D_8034AB10_82A280[] = {
    { SOUND_ID_349, PITCH_MOD_1, 22 },
    { SOUND_ID_350, PITCH_MOD_1, 22 },
    { SOUND_ID_351, PITCH_MOD_1, 22 },
    { SOUND_ID_352, PITCH_MOD_1, 22 },
    { SOUND_ID_147, PITCH_MOD_0, 25 },
    { SOUND_ID_145, PITCH_MOD_0, 22 },
    { SOUND_ID_148, PITCH_MOD_0, 35 },
    { SOUND_ID_154, PITCH_MOD_2, 22 },
    { SOUND_ID_155, PITCH_MOD_2, 22 },
};

PokemonDef D_8034AB34_82A2A4[] = {
    { PokemonID_MEW,
      func_80348938_8280A8,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1037,
      func_80349EB8_829628,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_GATE,
      func_80348FB8_828728,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_EVOLUTION_CONTROLLER,
      func_8034A064_8297D4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1038,
      func_8034A4E8_829C58,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

GObj* D_8034AB94_82A304 = NULL;
GObj* D_8034AB98_82A308 = NULL;
s32 D_8034AB9C_82A30C = 0x761FF;
s32 D_8034ABA0_82A310 = 0x761FF;
s32 D_8034ABA4_82A314 = false;

void func_803466C0_825E30(void) {
    Pokemon* pokemon;
    DObj* model;
    Mtx3Float* position;
    GObj* obj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = {
        PokemonID_MEW,
        func_80348938_8280A8,
        pokemonChangeBlock,
        pokemonRemoveOne
    };

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_MEW;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    obj = pokemonAddOne(block, block, &spawn, &def);
    D_8034AB94_82A304 = obj;
    pokemon = GET_POKEMON(D_8034AB94_82A304);
    HIDE_POKEMON();

    model = obj->data.dobj;
    position = &GET_TRANSFORM(model)->pos;
    GET_TRANSFORM(model)->pos.v.x = 0.0f;
    GET_TRANSFORM(model)->pos.v.y = 100.0f;
    GET_TRANSFORM(model)->pos.v.z = 500.0f;
}

void func_803467A4_825F14(GObj* baseObj) {
    Pokemon* pokemon;
    DObj* model;
    Mtx3Float* position;
    GObj* obj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = {
        PokemonID_1037,
        func_80349EB8_829628,
        pokemonChangeBlock,
        pokemonRemoveOne
    };

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_1037;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    obj = pokemonAddOne(block, block, &spawn, &def);
    D_8034AB98_82A308 = obj;
    pokemon = GET_POKEMON(obj);
    HIDE_POKEMON();

    position = &GET_TRANSFORM(baseObj->data.dobj)->pos;
    model = obj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void func_80346898_826008(void) {
    Pokemon* pokemon;
    DObj* model;
    GObj* obj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = {
        PokemonID_1038,
        func_8034A4E8_829C58,
        pokemonChangeBlock,
        pokemonRemoveOne
    };

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_1038;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    obj = pokemonAddOne(block, block, &spawn, &def);
    pokemon = GET_POKEMON(D_8034AB94_82A304);
    HIDE_POKEMON();

    model = obj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = 0.0f;
    GET_TRANSFORM(model)->pos.v.y = 0.0f;
    GET_TRANSFORM(model)->pos.v.z = 0.0f;
}

s32 rainbow_endLevelReason = 0;

void func_80346968_8260D8(s32 arg0) {
    ohWait(1800);
    omEndProcess(NULL);
}

void func_80346994_826104(WorldBlock* arg0, WorldBlock* arg1) {
    s32 i;

    func_803466C0_825E30();

    for (i = 0; i < 1; i++) {
        func_80346898_826008();
    }
}

void func_803469E0_826150(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, D_8034AB34_82A2A4);
}

void func_80346A04_826174(WorldBlock* arg0) {
    pokemonRemove(arg0, D_8034AB34_82A2A4);
}

void func_80346A28_826198(void) {
    createWorld(&D_800F5DA0, OBJID_SKYBOX, OBJID_WORLD_BLOCK_MIN, OBJID_WORLD_BLOCK_MAX, LINK_PLAYER, DL_LINK_3, func_80346994_826104, func_80346A04_826174, func_803469E0_826150);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(OBJID_128, OBJID_228, LINK_POKEMON, 5);
}

void func_80346AA8_826218(s32 endLevelReason) {
    rainbow_endLevelReason = endLevelReason;
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

void func_80346B0C_82627C(GObj* arg0) {
    if (Items_GetPokeFluteCmd() == 0) {
        if (D_8034ABA4_82A314 || D_8034AB9C_82A30C != D_8034ABA0_82A310) {
            D_8034ABA0_82A310 = D_8034AB9C_82A30C;
            D_8034ABA4_82A314 = false;
        }
        auSetBGMTempo(BGM_PLAYER_MAIN, D_8034ABA0_82A310);
        return;
    }
    D_8034ABA4_82A314 = true;
}

void func_80346B94_826304(s32 arg0) {
    if (arg0 == 0) {
        setSkyBoxAnimationSpeed(D_800F5DB0);
    } else {
        setSkyBoxAnimationSpeed(0.0f);
    }
}

void func_80346BD0_826340(WorldBlock* block) {
    WorldBlock* next;

    if (rainbow_endLevelReason <= 0) {
        if (block->next != NULL) {
            next = block->next;
            Items_DisplaceAllItems(
                (block->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (block->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (block->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_80346AA8_826218(2);
        }
    }
}

void func_80346C64_8263D4(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) particle_common_ROM_START, (u32) particle_common_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) ADD310_ROM_START, (u32) ADD310_ROM_END);
    temp_v0_2 = func_800A73C0((u32) particle_rainbow_ROM_START, (u32) particle_rainbow_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

ScreenSettings D_8034ABDC_82A34C = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00000A99     /* flags*/
};

void func_80346D50_8264C0(void) {
    s32 i;
    u8 r, g, b;

    D_8034ABDC_82A34C.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_8034ABDC_82A34C);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(0, func_80346B0C_82627C, 0, 0x80000000);
    Pokemons_Init();
    func_80346A28_826198();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    initUI(func_80346BD0_826340, NULL, NULL, 0, NULL);
    setEndLevelCallback(func_80346AA8_826218);
    setPauseCallback(func_80346B94_826304);
    EnvSound_Init(D_8034AB10_82A280, ARRAY_COUNT(D_8034AB10_82A280));
    auSetBGMExtraReverb(0, 25);
    auSetSoundGlobalReverb(40);
    auPlaySoundWithParams(SOUND_ID_63, 0x4000, 0, 0.7f, 20);
    auPlaySoundWithParams(SOUND_ID_63, 0x4000, 127, 0.8f, 20);
    func_80346C64_8263D4();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_8034AABC_82A22C();
}

void func_80346EE8_826658(s32 arg0) {
}

SceneSetup D_8034ABF8_82A368 = {
    {
        0,                       /* unk_00*/
        omUpdateAll,             /* fnUpdate */
        omDrawAll,               /* fnDraw */
        rainbow_assets_VRAM_END, /* heapBase */
        0,                       /* heapSize */
        1,                       /* unk_14 */
        2,                       /* numContexts */
        0x5000,                  /* dlBufferSize0 */
        0x1000,                  /* dlBufferSize1 */
        0x0400,                  /* dlBufferSize2 */
        0x0000,                  /* dlBufferSize3 */
        0xC800,                  /* gfxHeapSize */
        2,                       /* unk30 */
        0x4000,                  /* rdpOutputBufferSize */
        func_800A1A50,           /* fnPreRender */
        contUpdate               /* fnUpdateInput */
    },
    0,                    /* numOMThreads */
    768,                  /* omThreadStackSize */
    0,                    /* numOMStacks */
    0,                    /* unk4C */
    0,                    /* numOMProcesses */
    0,                    /* numOMGobjs */
    sizeof(GObj),         /* objectSize */
    0,                    /* numOMMtx */
    0,                    /* unk60 */
    func_80346EE8_826658, /* unk64 */
    0,                    /* numOMAobjs */
    0,                    /* numOMMobjs */
    0,                    /* numOMDobjs */
    sizeof(DObj),         /* omDobjSize */
    0,                    /* numOMSobjs */
    0x58,                 /* omSobjSize */
    0,                    /* numOMCameras */
    sizeof(OMCamera),     /* omCameraSize */
    func_80346D50_8264C0  /* postInitFunc */
};

s32 func_80346EF0_826660(s32 arg0) {
    D_8034ABF8_82A368.gtlSetup.heapSize = (uintptr_t) rainbow_code_VRAM - (uintptr_t) rainbow_assets_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_8034ABF8_82A368);

    if (rainbow_endLevelReason == END_LEVEL_REASON_RETRY) {
        return SCENE_RAINBOW;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);
    return SCENE_OAKS_LAB_2;
}
