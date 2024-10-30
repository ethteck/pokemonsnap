#include "common.h"
#include "rainbow.h"
#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

extern f32 D_800F5DB0;

extern EnvSoundData D_8034AB10_82A280;
extern PokemonDef D_8034AB34_82A2A4;
extern GObj* D_8034AB94_82A304;
extern GObj* D_8034AB98_82A308;
extern s32 D_8034AB9C_82A30C;
extern s32 D_8034ABA0_82A310;
extern s32 D_8034ABA4_82A314;
extern PokemonDef D_8034ABA8_82A318;
extern PokemonDef D_8034ABB8_82A328;
extern PokemonDef D_8034ABC8_82A338;
extern s32 D_8034ABD8_82A348;
extern ScreenSettings D_8034ABDC_82A34C;
extern SceneSetup D_8034ABF8_82A368;

void func_803466C0_825E30(void) {
    Pokemon* pokemon;
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_8034ABA8_82A318;

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

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);
    D_8034AB94_82A304 = pokemonObj;
    pokemon = GET_POKEMON(D_8034AB94_82A304);
    pokemon->tangible = false;
    pokemonObj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    model = pokemonObj->data.dobj;
    position = &GET_TRANSFORM(model)->pos;
    GET_TRANSFORM(model)->pos.v.x = 0.0f;
    GET_TRANSFORM(model)->pos.v.y = 100.0f;
    GET_TRANSFORM(model)->pos.v.z = 500.0f;
}

void func_803467A4_825F14(GObj* obj) {
    Pokemon* pokemon;
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_8034ABB8_82A328;

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

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);
    D_8034AB98_82A308 = pokemonObj;
    pokemon = GET_POKEMON(pokemonObj);
    pokemon->tangible = false;
    pokemonObj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void func_80346898_826008(void) {
    Pokemon* pokemon;
    DObj* model;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_8034ABC8_82A338;

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

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);
    pokemon = GET_POKEMON(D_8034AB94_82A304);
    pokemon->tangible = false;

    model = pokemonObj->data.dobj;
    pokemonObj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    GET_TRANSFORM(model)->pos.v.x = 0.0f;
    GET_TRANSFORM(model)->pos.v.y = 0.0f;
    GET_TRANSFORM(model)->pos.v.z = 0.0f;
}

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
    pokemonsChangeBlock(arg0, arg1, &D_8034AB34_82A2A4);
}

void func_80346A04_826174(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_8034AB34_82A2A4);
}

void func_80346A28_826198(void) {
    createWorld(&D_800F5DA0, 0x63, 0x64, 0x7E, 9, 3, func_80346994_826104, func_80346A04_826174, func_803469E0_826150);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(0x80, 0xE4, 3, 5);
}

void func_80346AA8_826218(s32 arg0) {
    D_8034ABD8_82A348 = arg0;
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

void func_80346B0C_82627C(GObj* arg0) {
    if (Items_GetPokeFluteCmd() == 0) {
        if (D_8034ABA4_82A314 != 0 || D_8034AB9C_82A30C != D_8034ABA0_82A310) {
            D_8034ABA0_82A310 = D_8034AB9C_82A30C;
            D_8034ABA4_82A314 = 0;
        }
        auSetBGMTempo(0, D_8034ABA0_82A310);
        return;
    }
    D_8034ABA4_82A314 = 1;
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

    if (D_8034ABD8_82A348 <= 0) {
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
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) ADD310_ROM_START, (u32) ADD310_ROM_END);
    temp_v0_2 = func_800A73C0((u32) ADD5D0_ROM_START, (u32) ADD5D0_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

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
    EnvSound_Init(&D_8034AB10_82A280, 9);
    auSetBGMExtraReverb(0, 0x19);
    auSetSoundGlobalReverb(0x28);
    auPlaySoundWithParams(0x3F, 0x4000, 0, 0.7f, 0x14);
    auPlaySoundWithParams(0x3F, 0x4000, 0x7F, 0.8f, 0x14);
    func_80346C64_8263D4();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_8034AABC_82A22C();
}

void func_80346EE8_826658(s32 arg0) {
}

s32 func_80346EF0_826660(s32 arg0) {
    D_8034ABF8_82A368.gtlSetup.heapSize = (uintptr_t) rainbow_code_VRAM - (uintptr_t) _4A8160_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_8034ABF8_82A368);

    if (D_8034ABD8_82A348 == 6) {
        return SCENE_RAINBOW;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);
    return SCENE_OAKS_LAB_2;
}
