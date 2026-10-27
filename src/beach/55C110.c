#include "common.h"
#include "sys/om.h"
#include "beach.h"
#include "world/world.h"
#include "ld_addrs.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "app_render/effect.h"

EnvSoundData D_beach_802CBE10[] = {
    { SOUND_ID_253, PITCH_MOD_1, 7 },
    { SOUND_ID_342, PITCH_MOD_1, 8 },
    { SOUND_ID_343, PITCH_MOD_1, 8 },
    { SOUND_ID_344, PITCH_MOD_1, 8 },
    { SOUND_ID_117, PITCH_MOD_0, 8 },
    { SOUND_ID_142, PITCH_MOD_0, 8 },
    { SOUND_ID_143, PITCH_MOD_0, 6 },
    { SOUND_ID_254, PITCH_MOD_1, 8 },
    { SOUND_ID_255, PITCH_MOD_1, 8 },
    { SOUND_ID_110, PITCH_MOD_0, 8 },
    { SOUND_ID_260, PITCH_MOD_1, 10 },
    { SOUND_ID_261, PITCH_MOD_1, 10 },
    { SOUND_ID_262, PITCH_MOD_1, 10 },
    { SOUND_ID_105, PITCH_MOD_0, 10 },
    { SOUND_ID_104, PITCH_MOD_0, 10 },
    { SOUND_ID_293, PITCH_MOD_1, 10 },
    { SOUND_ID_294, PITCH_MOD_1, 10 },
    { SOUND_ID_295, PITCH_MOD_1, 10 },
    { SOUND_ID_355, PITCH_MOD_1, 10 },
    { SOUND_ID_296, PITCH_MOD_1, 10 },
    { SOUND_ID_297, PITCH_MOD_1, 10 },
    { SOUND_ID_125, PITCH_MOD_0, 7 },
    { SOUND_ID_210, PITCH_MOD_1, 8 },
    { SOUND_ID_211, PITCH_MOD_1, 8 },
    { SOUND_ID_376, PITCH_MOD_0, 8 },
    { SOUND_ID_114, PITCH_MOD_0, 8 },
    { SOUND_ID_383, PITCH_MOD_2, 40 },
    { SOUND_ID_251, PITCH_MOD_1, 10 },
    { SOUND_ID_252, PITCH_MOD_1, 10 },
    { SOUND_ID_366, PITCH_MOD_0, 10 },
    { SOUND_ID_121, PITCH_MOD_0, 10 },
    { SOUND_ID_122, PITCH_MOD_0, 10 },
    { SOUND_ID_298, PITCH_MOD_1, 9 },
    { SOUND_ID_299, PITCH_MOD_1, 9 },
    { SOUND_ID_300, PITCH_MOD_1, 9 },
    { SOUND_ID_301, PITCH_MOD_1, 9 },
    { SOUND_ID_302, PITCH_MOD_1, 9 },
    { SOUND_ID_263, PITCH_MOD_1, 8 },
    { SOUND_ID_264, PITCH_MOD_1, 10 },
    { SOUND_ID_265, PITCH_MOD_1, 8 },
    { SOUND_ID_266, PITCH_MOD_1, 8 },
    { SOUND_ID_267, PITCH_MOD_2, 8 },
    { SOUND_ID_268, PITCH_MOD_2, 8 },
    { SOUND_ID_371, PITCH_MOD_0, 8 },
    { SOUND_ID_127, PITCH_MOD_0, 10 },
    { SOUND_ID_360, PITCH_MOD_0, 10 },
    { SOUND_ID_256, PITCH_MOD_1, 8 },
    { SOUND_ID_257, PITCH_MOD_1, 7 },
    { SOUND_ID_124, PITCH_MOD_0, 7 },
    { SOUND_ID_52, PITCH_MOD_1, 15 },
    { SOUND_ID_304, PITCH_MOD_1, 10 },
    { SOUND_ID_363, PITCH_MOD_0, 10 },
    { SOUND_ID_388, PITCH_MOD_0, 10 },
};

PokemonDef beachPokemonData[] = {
    { PokemonID_BUTTERFREE,
      (pokemonInit) func_beach_802C7E38,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_DODUO,
      (pokemonInit) func_beach_802C8570,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_EEVEE,
      (pokemonInit) func_beach_802C7AD0,
      Pokemon_ChangeBlockAndRemove,
      NULL },
    { PokemonID_KANGASKHAN,
      (pokemonInit) func_beach_802CA05C,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_SNORLAX,
      (pokemonInit) func_beach_802C5C28,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_LAPRAS,
      (pokemonInit) func_beach_802C8274,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_CHANSEY,
      (pokemonInit) func_beach_802C9A7C,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_MEOWTH,
      (pokemonInit) func_beach_802C7270,
      func_beach_802C71E8,
      pokemonRemoveOne },
    { PokemonID_PIDGEY,
      (pokemonInit) func_beach_802C8D3C,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_SCYTHER,
      (pokemonInit) func_beach_802C91CC,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_MAGIKARP,
      (pokemonInit) func_beach_802CAC48,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_PIKACHU,
      (pokemonInit) func_beach_802CBCA8,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_1003,
      func_8035E0D4_4FE4E4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1004,
      (pokemonInit) func_beach_802CA418,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1005,
      (pokemonInit) func_beach_802CA2BC,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_GATE,
      (pokemonInit) func_beach_802CAB14,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

PokemonDef D_beach_802CBFF4 = {
    PokemonID_MAGIKARP,
    (pokemonInit) func_beach_802CAC48,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

RandomState2 D_beach_802CC004[2] = {
    { 3, beachSpawnMagikarpAtGObj },
    { 7, NULL }
};

u16 D_beach_802CC014 = 0;
s32 D_beach_802CC018 = 0;
ScreenSettings D_beach_802CC01C = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00000A99     /* flags*/
};
SceneSetup D_beach_802CC038 = {
    {
        0,                     /* unk_00*/
        omUpdateAll,           /* fnUpdate */
        omDrawAll,             /* fnDraw */
        beach_assets_VRAM_END, /* heapBase */
        0,                     /* heapSize */
        1,                     /* unk_14 */
        2,                     /* numContexts */
        0x5000,                /* dlBufferSize0 */
        0x0C00,                /* dlBufferSize1 */
        0x0400,                /* dlBufferSize2 */
        0x0000,                /* dlBufferSize3 */
        0xC800,                /* gfxHeapSize */
        2,                     /* unk30 */
        0x4000,                /* rdpOutputBufferSize */
        func_800A1A50,         /* fnPreRender */
        contUpdate             /* fnUpdateInput */
    },
    0,                   /* numOMThreads */
    1088,                /* omThreadStackSize */
    0,                   /* numOMStacks */
    0,                   /* unk4C */
    0,                   /* numOMProcesses */
    0,                   /* numOMGobjs */
    sizeof(GObj),        /* objectSize */
    0,                   /* numOMMtx */
    0,                   /* unk60 */
    func_beach_802C4738, /* unk64 */
    0,                   /* numOMAobjs */
    0,                   /* numOMMobjs */
    0,                   /* numOMDobjs */
    sizeof(DObj),        /* omDobjSize */
    0,                   /* numOMSobjs */
    0x58,                /* omSobjSize */
    0,                   /* numOMCameras */
    sizeof(OMCamera),    /* omCameraSize */
    func_beach_802C45C0  /* postInitFunc */
};

void beachSpawnMagikarpAtGObj(GObj* obj) {
    DObj* a0;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* roomA;
    PokemonDef def = D_beach_802CBFF4;

    roomA = getCurrentWorldBlock();
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

    pokemonObj = pokemonAddOne(roomA, roomA, &spawn, &def);

    position = &obj->data.dobj->position;
    a0 = pokemonObj->data.dobj;
    GET_TRANSFORM(a0)->pos.v.x = position->v.x;
    GET_TRANSFORM(a0)->pos.v.y = position->v.y;
    GET_TRANSFORM(a0)->pos.v.z = position->v.z;
}

void func_beach_802C416C(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    s32 i;
    s32 numOptions = ARRAY_COUNT(D_beach_802CC004);
    s32 sumWeight;
    s32 randValue;

    if (groundResult->surfaceType == SURFACE_TYPE_337FB2 && Vec3fDistance(&GET_TRANSFORM(gPlayerDObj)->pos.v, &model->position.v) > 50.0f) {
        sumWeight = 0;
        for (i = 0; i < numOptions; i++) {
            sumWeight += D_beach_802CC004[i].weight;
        }
        randValue = randRange(sumWeight);
        sumWeight = 0;
        for (i = 0; i < numOptions; i++) {
            sumWeight += D_beach_802CC004[i].weight;
            if (sumWeight > randValue) {
                if (D_beach_802CC004[i].func != NULL && !D_beach_802CC014) {
                    D_beach_802CC004[i].func(obj);
                    D_beach_802CC014 = true;
                }
                break;
            }
        }
    }
}

void beachPokemonAdd(WorldBlock* param_1, WorldBlock* param_2) {
    pokemonAdd(param_1, param_2, beachPokemonData);
}

void func_beach_802C42F8(WorldBlock* param_1, WorldBlock* param_2) {
    pokemonsChangeBlock(param_1, param_2, beachPokemonData);
}

void func_beach_802C431C(WorldBlock* arg0) {
    pokemonRemove(arg0, beachPokemonData);
}

void func_beach_802C4340(void) {
    setHeightMap(&D_beach_80318F00);
    createWorld(&D_8011B914, 99, 100, 126, 9, 3, beachPokemonAdd, func_beach_802C431C, func_beach_802C42F8);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(0x80, 0xE4, 3, 5);
}

void func_beach_802C43CC(s32 arg0) {
    D_beach_802CC018 = arg0;
    func_800A19D8(arg0);
    PokemonDetector_Disable();
    EnvSound_Cleanup();
    auStopBGM();
    auStopAllSounds();
    destroyWorld();
    func_80356FBC_4F73CC();
    removeMainCamera();
    func_800067DC();
}

void func_beach_802C4430(GObj* arg0) {
}

void func_beach_802C4438(s32 arg0) {
}

void func_beach_802C4440(WorldBlock* arg0) {
    WorldBlock* next;

    if (D_beach_802CC018 <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_beach_802C43CC(2);
        }
    }
}

void func_beach_802C44D4(void) {
    void* scriptDesc;
    void* spritesDesc;

    scriptDesc = func_800A73C0((u32) fx_script_common_ROM_START, (u32) fx_script_common_ROM_END);
    spritesDesc = func_800A73C0((u32) fx_img_common_ROM_START, (u32) fx_img_common_ROM_END);
    if (scriptDesc != NULL && spritesDesc != NULL) {
        fx_setupBankID(3, scriptDesc, spritesDesc);
    }
    scriptDesc = func_800A73C0((u32) fx_script_beach_ROM_START, (u32) fx_script_beach_ROM_END);
    spritesDesc = func_800A73C0((u32) fx_img_beach_ROM_START, (u32) fx_img_beach_ROM_END);
    if (scriptDesc != NULL && spritesDesc != NULL) {
        fx_setupBankID(0, scriptDesc, spritesDesc);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = fx_allocEffects(10);
    fx_setDitherModes(0xC0, 0x30);
}

void func_beach_802C45C0(void) {
    s32 i;
    u8 r, g, b;

    D_beach_802CC01C.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_beach_802CC01C);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(fx_SpriteBanksNum); i++) { fx_ScriptBanksNum[i] = fx_SpriteBanksNum[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(0, func_beach_802C4430, 0, 0x80000000);
    Pokemons_Init();
    func_beach_802C4340();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    if (func_8009A8E4() != 0) {
        setIdleScript(func_800A73C0((u32) idle_script_beach_ROM_START, (u32) idle_script_beach_ROM_END));
    }
    initUI(func_beach_802C4440, func_beach_802C4800, NULL, 0, func_beach_802C416C);

    setEndLevelCallback(func_beach_802C43CC);
    setPauseCallback(func_beach_802C4438);
    EnvSound_Init(D_beach_802CBE10, ARRAY_COUNT(D_beach_802CBE10));
    func_beach_802C44D4();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_beach_802C55CC();
}

void func_beach_802C4738(s32 arg0) {
}

s32 func_beach_802C4740(s32 sceneID) {
    D_beach_802CC038.gtlSetup.heapSize = (uintptr_t) beach_code_VRAM - (uintptr_t) beach_assets_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_beach_802CC038);

    switch (D_beach_802CC018) {
        case 6:
            return SCENE_BEACH;
        case 7:
        case 8:
            return SCENE_MAIN_MENU;
        default:
            if (func_8009BC68() > 0) {
                return SCENE_CAMERA_CHECK;
            }
            func_800AAED0(0x10);
            return SCENE_OAKS_LAB_2;
    }
}
