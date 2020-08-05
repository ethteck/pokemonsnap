#include "common.h"

extern animalDef extraStaryuDef;
extern animalDef extraStarmieDef;
extern randomTransition D_802ECB00;
extern animalInitData D_802ECB2C;

void spawnStaryuAtGeo(GObj* obj) {
    addAnimalAtGeo(obj, 0x78, &extraStaryuDef);
    endGObjProcess(NULL);
}

void spawnStarmieAtGeo(GObj* obj) {
    addAnimalAtGeo(obj, 0x79, &extraStarmieDef);
    endGObjProcess(NULL);
}

void func_802D25E0(GObj* obj) {
    weightedRandomStaightTransition(obj, &D_802ECB00);
}

void func_802D2604(GObj* obj) {
    s32 pad[3];
    animal* animal = obj->data.animal;

    runGObjProcess(obj, spawnStaryuAtGeo, 1, 1);
    
    animal->counter = 1; animal->processFlags &= ~4;
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802D2684(GObj* obj) {
    s32 pad[3];
    animal* animal = obj->data.animal;

    runGObjProcess(obj, spawnStarmieAtGeo, 1, 1);
    animal->counter = 1; animal->processFlags &= ~4;
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802D2704(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_802ECB2C);
}
