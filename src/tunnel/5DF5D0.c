#include "tunnel.h"

extern EnvSoundData D_802EDF00_5EAFD0[43];
extern PokemonDef D_802EDFAC_5EB07C[];
extern u16 D_802EE10C_5EB1DC;
extern PokemonDef D_802EE110_5EB1E0;
extern RandomState2 D_802EE120_5EB1F0[2];
extern s32 D_802EE130_5EB200;
extern ScreenSettings D_802EE134_5EB204;
extern SceneSetup D_802EE150_5EB220;

extern s32 D_803430E8_6401B8;

extern HeightMap D_80326EE0_623FB0;
extern HeightMap D_80326EE8_623FB8;
extern WorldSetup D_8011E6CC;

void func_802E2500_5DF5D0(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_802EE110_5EB1E0;

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

void func_802E25D4_5DF6A4(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    s32 i;
    s32 numOptions = ARRAY_COUNT(D_802EE120_5EB1F0);
    s32 sumWeight;
    s32 randValue;

    if (groundResult->surfaceType == SURFACE_TYPE_337FB2 && Vec3fDistance(&GET_TRANSFORM(gPlayerDObj)->pos.v, &model->position.v) > 50.0f) {
        sumWeight = 0;
        for (i = 0; i < numOptions; i++) {
            sumWeight += D_802EE120_5EB1F0[i].weight;
        }
        randValue = randRange(sumWeight);
        sumWeight = 0;
        for (i = 0; i < numOptions; i++) {
            sumWeight += D_802EE120_5EB1F0[i].weight;
            if (sumWeight > randValue) {
                if (D_802EE120_5EB1F0[i].func != NULL && !D_802EE10C_5EB1DC) {
                    D_802EE120_5EB1F0[i].func(obj);
                    D_802EE10C_5EB1DC = true;
                }
                break;
            }
        }
    }
}

void func_802E273C_5DF80C(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, D_802EDFAC_5EB07C);
}

void func_802E2760_5DF830(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, D_802EDFAC_5EB07C);
}

void func_802E2784_5DF854(WorldBlock* arg0) {
    pokemonRemove(arg0, D_802EDFAC_5EB07C);
}

void func_802E27A8_5DF878(void) {
    setHeightMap(&D_80326EE0_623FB0);
    setCeilingMap(&D_80326EE8_623FB8);
    createWorld(&D_8011E6CC, OBJID_SKYBOX, OBJID_WORLD_BLOCK_MIN, OBJID_WORLD_BLOCK_MAX, LINK_PLAYER, DL_LINK_3, func_802E273C_5DF80C, func_802E2784_5DF854, func_802E2760_5DF830);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(OBJID_128, OBJID_228, LINK_POKEMON, 5);
}

void func_802E2840_5DF910(s32 endLevelReason) {
    D_802EE130_5EB200 = endLevelReason;
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

void func_802E28AC_5DF97C(s32 arg0) {
}

void func_802E28B4_5DF984(WorldBlock* arg0) {
    WorldBlock* next;

    if (D_802EE130_5EB200 <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_802E2840_5DF910(END_LEVEL_REASON_FINISH);
        }
    }
}

void func_802E2948_5DFA18(void) {
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

void func_802E2A34_5DFB04(void) {
    s32 i;
    u8 r, g, b;

    D_802EE134_5EB204.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_802EE134_5EB204);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(OBJID_0, func_802E28A4_5DF974, LINK_0, 0x80000000);
    Pokemons_Init();
    func_802E27A8_5DF878();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    if (func_8009A8E4() != 0) {
        setIdleScript(func_800A73C0((u32)AB1470_ROM_START, (u32)AB1470_ROM_END));
    }
    initUI(func_802E28B4_5DF984, func_802E2C70_5DFD40, NULL, 0, func_802E25D4_5DF6A4);
    setEndLevelCallback(func_802E2840_5DF910);
    setPauseCallback(func_802E28AC_5DF97C);
    EnvSound_Init(D_802EDF00_5EAFD0, ARRAY_COUNT(D_802EDF00_5EAFD0));
    func_802E2948_5DFA18();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802ED5C8_5EA698();
    D_803430E8_6401B8 = 0;
}

void func_802E2BB0_5DFC80(s32 arg0) {
}

s32 func_802E2BB8_5DFC88(s32 arg0) {
    D_802EE150_5EB220.gtlSetup.heapSize = (uintptr_t) tunnel_code_VRAM - (uintptr_t) _162CB0_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802EE150_5EB220);

    switch (D_802EE130_5EB200) {
        case 6:
            return SCENE_TUNNEL;
        case 7:
        case 8:
            return SCENE_MAIN_MENU;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);
    return SCENE_OAKS_LAB_2;
}
