#include "common.h"

void func_8035FD00(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E7DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EBBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EC1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/updateAnimalState.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/weightedRandomStaightTransition.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035ED90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/runPathProcess.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EE64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/animalUVStuff.s")

void setAnimalAnimation(GObj* obj, animationHeader* header) {
    animalUVStuff(obj, header, 0, 0);
}

void forceAnimalAnimation(GObj* obj, animationHeader* header) {
    animalUVStuff(obj, header, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/runInteractionsAndWaitForFlags.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FC54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FD00.s")

void runAnimalCleanup(GObj* obj) {
    runGObjProcess(obj, func_8035FD00, 1, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FD9C.s")

GObj* addAnimalAtGeo(GObj *gobj, AnimalID id, animalDef *def) {
    objectSpawn spawn;
    roomGFX* roomA;
    animal* animalTmp;
    GObj* animalObj;
    
    animalTmp = gobj->data.animal;
    roomA = getCurrentRoom();
    spawn.id = id;
    spawn.translation.x = 0.0f;
    spawn.translation.y = 0.0f;
    spawn.translation.z = 0.0f;
    spawn.euler.x = 0.0f;
    spawn.euler.y = 0.0f;
    spawn.euler.z = 0.0f;
    spawn.scale.x = 1.0f;
    spawn.scale.y = 1.0f;
    spawn.scale.z = 1.0f;
    spawn.path = animalTmp->path;
    spawn.behavior = animalTmp->behavior;
    
    animalObj = animalAddOne(roomA, roomA, &spawn, def);

    if (animalObj != NULL) {
        xformData* pxVar1 = gobj->rootNode->xform;
        xformData* pxVar2 = animalObj->rootNode->xform;
        
        pxVar2->translation.x = pxVar1->translation.x;
        pxVar2->translation.y = pxVar1->translation.y;
        pxVar2->translation.z = pxVar1->translation.z;
    }

    return animalObj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FF1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FF44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360074.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036010C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803601FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036026C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036044C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803606E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036082C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360D18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360FC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036148C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803615D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036194C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/setNodePosToNegRoom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/animalPathLoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803623F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803625B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362C50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/spawnAnimalUsingDeltaHeight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036334C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036345C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80363738.s")
