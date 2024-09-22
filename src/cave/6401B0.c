#include "common.h"
#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "cave.h"

extern EnvSoundData D_802C6150_648600;
extern PokemonDef D_802C6234_6486E4;
extern PokemonDef D_802C6358_648808;
extern s32 D_802C6378_648828;
extern ScreenSettings D_802C637C_64882C;
extern SceneSetup D_802C6398_648848;

extern HeightMap D_80317610_699AC0;
extern HeightMap D_80317618_699AC8;

void func_802BDD00_6401B0(GObj* obj) {
    DObj* a0;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* roomA;
    PokemonDef def = D_802C6358_648808;

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

void func_802BDDCC_64027C(GObj*, GroundResult*);
#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BDDCC_64027C.s")

void func_802BDF34_6403E4(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, &D_802C6234_6486E4);
}

void func_802BDF58_640408(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802C6234_6486E4);
}

void func_802BDF7C_64042C(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802C6234_6486E4);
}

void func_802BDFA0_640450(void) {
    setHeightMap(&D_80317610_699AC0);
    setCeilingMap(&D_80317618_699AC8);
    createWorld(&D_8012A0E8, 0x63, 0x64, 0x7E, 9, 3, func_802BDF34_6403E4, func_802BDF7C_64042C, func_802BDF58_640408);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(0x80, 0xE4, 3, 5);
}

void func_802BE038_6404E8(s32 arg0) {
    D_802C6378_648828 = arg0;
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

void func_802BE09C_64054C(GObj* arg0) {
}

void func_802BE0A4_640554(s32 arg0) {
}

void func_802BE0AC_64055C(WorldBlock* arg0) {
    WorldBlock* next;

    if (D_802C6378_648828 <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_802BE038_6404E8(2);
        }
    }
}

void func_802BE140_6405F0(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) AC6890_ROM_START, (u32) AC6890_ROM_END);
    temp_v0_2 = func_800A73C0((u32) AC6A80_ROM_START, (u32) AC6A80_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void func_802BE22C_6406DC(void) {
    s32 i;
    u8 r, g, b;

    D_802C637C_64882C.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_802C637C_64882C);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(0, func_802BE09C_64054C, 0, 0x80000000);
    Pokemons_Init();
    func_802BDFA0_640450();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    getMainCamera()->flags |= CAMERA_FLAG_2;
    initUI(func_802BE0AC_64055C, func_802BE450_640900, NULL, 0, func_802BDDCC_64027C);
    setEndLevelCallback(func_802BE038_6404E8);
    setPauseCallback(func_802BE0A4_640554);
    EnvSound_Init(&D_802C6150_648600, 57);
    func_802BE140_6405F0();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802C60F4_6485A4();
    setPitchLimits(-1.0471976f, 0.7853982f);
    *((s32*) &D_8033E138_6C05E8) = 0; // TODO how do you clear a bitfield?
}

void func_802BE3A8_640858(s32 arg0) {
}

s32 func_802BE3B0_640860(s32 arg0) {
    D_802C6398_648848.gtlSetup.heapSize = (uintptr_t) cave_code_VRAM - (uintptr_t) _1F5E70_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802C6398_648848);

    if (D_802C6378_648828 == 6) {
        return SCENE_CAVE;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);

    return SCENE_OAKS_LAB_2;
}
