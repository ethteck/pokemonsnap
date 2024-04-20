#include "common.h"

void func_802D2580_7ABB10(GObj* obj) { // spawnStaryuAtGeo
    addAnimalAtGeo(obj, AnimalID_STARYU, &extraStaryuDef);
    omEndProcess(NULL);
}

void func_802D25B0_7ABB40(GObj* obj) { // spawnStarmieAtGeo
    addAnimalAtGeo(obj, AnimalID_STARMIE, &extraStarmieDef);
    omEndProcess(NULL);
}

void func_802D25E0(GObj* obj) {
    weightedRandomStaightTransition(obj, &D_802ECB00);
}

#pragma GLOBAL_ASM("asm/nonmatchings/7ABB10/func_802D2604_7ABB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7ABB10/func_802D2684_7ABC14.s")

/*
void func_802D2604(GObj* obj) {
    UNUSED s32 pad[3];
    animal* animal = obj->data.animal;

    omCreateProcess(obj, spawnStaryuAtGeo, 1, 1);
    
    animal->counter = 1; animal->processFlags &= ~4;
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802D2684(GObj* obj) {
    UNUSED s32 pad[3];
    animal* animal = obj->data.animal;

    omCreateProcess(obj, spawnStarmieAtGeo, 1, 1);
    animal->counter = 1; animal->processFlags &= ~4;
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}
*/

void func_802D2704(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_802ECB2C);
}
