#include "common.h"

void func_8035FD00_500110(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E780_4FEB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E7DC_4FEBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E868_4FEC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E8A4_4FECB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E944_4FED54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E9A4_4FEDB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E9E0_4FEDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EA80_4FEE90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EAE0_4FEEF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EB1C_4FEF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EBBC_4FEFCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EC1C_4FF02C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/updateAnimalState.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/weightedRandomStaightTransition.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035ED90_4FF1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EDC8_4FF1D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/runPathProcess.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EE64_4FF274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EF2C_4FF33C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/animalUVStuff.s")

void setAnimalAnimation(GObj* obj, animationHeader* header) {
    animalUVStuff(obj, header, 0, 0);
}

void forceAnimalAnimation(GObj* obj, animationHeader* header) {
    animalUVStuff(obj, header, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F180_4FF590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F1A8_4FF5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F1D0_4FF5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F21C_4FF62C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F24C_4FF65C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F2A4_4FF6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F390_4FF7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F430_4FF840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F51C_4FF92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F648_4FFA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F784_4FFB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F900_4FFD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/runInteractionsAndWaitForFlags.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FC54_500064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FCA0_5000B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FD00_500110.s")

void runAnimalCleanup(GObj* obj) {
    runGObjProcess(obj, func_8035FD00_500110, 1, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FD9C_5001AC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FEEC_5002FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FF1C_50032C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FF44_500354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360074_500484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036010C_50051C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360144_500554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803601FC_50060C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036026C_50067C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360300_500710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036044C_50085C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360590_5009A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803606E8_500AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036082C_500C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360AB8_500EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360BEC_500FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360D18_501128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360E78_501288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360F1C_50132C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360FC8_5013D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361110_501520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361410_501820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361440_501850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036148C_50189C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803615D0_5019E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361720_501B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361748_501B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036194C_501D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B20_501F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B50_501F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B68_501F78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361E58_502268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361EB8_5022C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361EE8_5022F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361FBC_5023CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/setNodePosToNegRoom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/animalPathLoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803623F4_502804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362414_502824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362480_502890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803625B4_5029C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362C50_503060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362D2C_50313C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362DC4_5031D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362E10_503220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/spawnAnimalUsingDeltaHeight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362EE0_5032F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036334C_50375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036345C_50386C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80363738_503B48.s")
