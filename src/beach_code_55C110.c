#include "common.h"

extern animalDef D_802CBFF4;
extern animalDef beachAnimalData[17];

#ifdef NON_MATCHING
// void beachSpawnMagikarpAtGObj(GObj* obj) {
//     geoNode* pxVar1;
//     geoNode* pxVar2;
//     GObj* animalObj;
//     objectSpawn spawn;
//     roomGFX* roomA;
//     animalDef def = D_802CBFF4;
    
//     roomA = getCurrentRoom();
//     spawn.id = AnimalID_MAGIKARP;
//     spawn.translation.x = 0.0;
//     spawn.translation.y = 0.0;
//     spawn.translation.z = 0.0;
//     spawn.euler.x = 0.0;
//     spawn.euler.y = 0.0;
//     spawn.euler.z = 0.0;
//     spawn.scale.x = 1.0;
//     spawn.scale.y = 1.0;
//     spawn.scale.z = 1.0;
    
//     animalObj = animalAddOne(roomA, roomA, &spawn, &def);

//     pxVar1 = obj->rootNode;
//     pxVar2 = animalObj->rootNode;
        
//     pxVar2->xform->translation.x = pxVar1->translation.x;
//     pxVar2->xform->translation.y = pxVar1->translation.y;
//     pxVar2->xform->translation.z = pxVar1->translation.z;
// }
#else
#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/beachSpawnMagikarpAtGObj.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C416C.s")

void beachAnimalAdd(roomGFX* param_1, roomGFX* param_2) {
    animalAdd(param_1, param_2, beachAnimalData);
}

void func_802C42F8(s32* param_1, objectSpawn* param_2) {
    func_8036406C(param_1, param_2, beachAnimalData);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C431C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C4340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C43CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C4430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C4438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C4440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C44D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C45C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C4738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach_code_55C110/func_802C4740.s")
