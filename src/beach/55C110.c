#include "common.h"
#include "sys/om.h"
#include "beach.h"
#include "world/world.h"
#include "ld_addrs.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

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
    s32 numOptions = 2; // ARRAY_COUNT(D_beach_802CC004);
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
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) AB85E0_ROM_START, (u32) AB85E0_ROM_END);
    temp_v0_2 = func_800A73C0((u32) AB8780_ROM_START, (u32) AB8780_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void func_beach_802C45C0(void) {
    s32 i;
    u8 r, g, b;

    D_beach_802CC01C.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_beach_802CC01C);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(0, func_beach_802C4430, 0, 0x80000000);
    Pokemons_Init();
    func_beach_802C4340();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    if (func_8009A8E4() != 0) {
        setIdleScript(func_800A73C0((u32) AAA660_ROM_START, (u32) AAA660_ROM_END));
    }
    initUI(func_beach_802C4440, func_beach_802C4800, NULL, 0, func_beach_802C416C);

    setEndLevelCallback(func_beach_802C43CC);
    setPauseCallback(func_beach_802C4438);
    EnvSound_Init(&D_beach_802CBE10, 0x35);
    func_beach_802C44D4();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_beach_802C55CC();
}

void func_beach_802C4738(s32 arg0) {
}

s32 func_beach_802C4740(s32 sceneID) {
    D_beach_802CC038.gtlSetup.heapSize = (uintptr_t) beach_code_VRAM - (uintptr_t) A74E0_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_beach_802CC038);

    switch (D_beach_802CC018) {
        case 6:
            return SCENE_BEACH;
        case 7:
        case 8:
            return SCENE_8;
        default:
            if (func_8009BC68() > 0) {
                return SCENE_CAMERA_CHECK;
            }
            func_800AAED0(0x10);
            return SCENE_13;
    }
}
