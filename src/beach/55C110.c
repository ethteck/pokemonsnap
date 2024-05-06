#include "common.h"
#include "beach.h"
#include "world/world.h"
#include "ld_addrs.h"

void beachSpawnMagikarpAtGObj(GObj* obj) {
    geoNode* a0;
    struct Mtx3Float* position;
    GObj* animalObj;
    ObjectSpawn spawn;
    WorldBlock* roomA;
    AnimalDef def = D_beach_802CBFF4;

    roomA = getCurrentWorldBlock(); // TODO: type
    spawn.id = AnimalID_MAGIKARP;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    animalObj = animalAddOne(roomA, roomA, &spawn, &def);

    position = &obj->data.dobj->position;
    a0 = (geoNode*) animalObj->data.any;
    a0->xform->translation.x = position->v.x;
    a0->xform->translation.y = position->v.y;
    a0->xform->translation.z = position->v.z;
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C416C.s")

void beachAnimalAdd(WorldBlock* param_1, WorldBlock* param_2) {
    animalAdd(param_1, param_2, beachAnimalData);
}

void func_beach_802C42F8(WorldBlock* param_1, WorldBlock* param_2) {
    func_8036406C_50447C(param_1, param_2, beachAnimalData);
}

void func_beach_802C431C(WorldBlock* arg0) {
    func_803641B8_5045C8(arg0, beachAnimalData);
}

void func_beach_802C4340(void) {
    setHeightMap(&D_beach_80318F00);
    createWorld(&D_8011B914, 99, 100, 126, 9, 3, beachAnimalAdd, func_beach_802C431C, func_beach_802C42F8);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(0x80, 0xE4, 3, 5);
}

void func_beach_802C43CC(s32 arg0) {
    D_beach_802CC018 = arg0;
    func_800A19D8(arg0);
    func_80359074_4F9484();
    func_8036650C_50691C();
    auStopBGM();
    auStopAllSounds();
    destroyWorld();
    func_80356FBC_4F73CC();
    func_803586C0_4F8AD0();
    func_800067DC();
}

void func_beach_802C4430(s32 arg0) {
}

void func_beach_802C4438(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C4440.s")

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
    D_80382D10_523120 = func_800A2094(4, 100, func_803586F8_4F8B08());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C45C0.s")

void func_beach_802C4738(s32 arg0) {
}

s32 func_beach_802C4740(s32 sceneID) {
    D_beach_802CC038.gtlSetup.heapSize = (s32) beach_code_VRAM - (s32) &D_801B0310;
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
