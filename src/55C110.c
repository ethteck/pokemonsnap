#include "common.h"

extern animalDef D_802CBFF4_564064;
extern s32 D_802CC018_564088;
extern animalDef beachAnimalData[17];

void beachSpawnMagikarpAtGObj(GObj* obj) {
    geoNodeSub* sub;
    geoNode* pxVar2;
    GObj* animalObj;
    objectSpawn spawn;
    roomGFX* roomA;
    animalDef def = D_802CBFF4_564064;
    
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

    sub = &obj->rootNode->unk_18;
    pxVar2 = animalObj->rootNode;
        
    pxVar2->xform->translation.x = sub->translation.x;
    pxVar2->xform->translation.y = sub->translation.y;
    pxVar2->xform->translation.z = sub->translation.z;
}

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C416C_55C1DC.s")

void beachAnimalAdd(roomGFX* param_1, roomGFX* param_2) {
    animalAdd(param_1, param_2, beachAnimalData);
}

void func_802C42F8_55C368(s32* param_1, objectSpawn* param_2) {
    func_8036406C_50447C(param_1, param_2, beachAnimalData);
}

void func_802C431C_55C38C(s32 arg0) {
    func_803641B8_5045C8(arg0, beachAnimalData);
}

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4340_55C3B0.s")

void func_802C43CC_55C43C(s32 arg0) {
    D_802CC018_564088 = arg0;
    func_800A19D8();
    func_80359074_4F9484();
    func_8036650C_50691C();
    func_80022334();
    func_80022B14();
    func_800E3064();
    func_80356FBC_4F73CC();
    func_803586C0_4F8AD0();
    func_800067DC();
}

void func_802C4430_55C4A0(s32 arg0) {

}

void func_802C4438_55C4A8(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4440_55C4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C44D4_55C544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C45C0_55C630.s")

void func_802C4738_55C7A8(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4740_55C7B0.s")
