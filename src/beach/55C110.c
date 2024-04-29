#include "common.h"

extern AnimalDef D_beach_802CBFF4;
extern s32 D_beach_802CC018;
extern AnimalDef beachAnimalData[17];

void beachSpawnMagikarpAtGObj(GObj* obj) {
    geoNode* a0;
    struct Mtx3Float* position;
    GObj* animalObj;
    ObjectSpawn spawn;
    RoomGFX* roomA;
    AnimalDef def = D_beach_802CBFF4;

    roomA = getCurrentRoom();
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

void beachAnimalAdd(RoomGFX* param_1, RoomGFX* param_2) {
    animalAdd(param_1, param_2, beachAnimalData);
}

void func_beach_802C42F8(s32* param_1, ObjectSpawn* param_2) {
    func_8036406C_50447C(param_1, param_2, beachAnimalData);
}

void func_beach_802C431C(s32 arg0) {
    func_803641B8_5045C8(arg0, beachAnimalData);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C4340.s")

void func_beach_802C43CC(s32 arg0) {
    D_beach_802CC018 = arg0;
    func_800A19D8();
    func_80359074_4F9484();
    func_8036650C_50691C();
    auStopBGM();
    auStopAllSounds();
    func_800E3064();
    func_80356FBC_4F73CC();
    func_803586C0_4F8AD0();
    func_800067DC();
}

void func_beach_802C4430(s32 arg0) {
}

void func_beach_802C4438(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C4440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C44D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C45C0.s")

void func_beach_802C4738(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55C110/func_beach_802C4740.s")
