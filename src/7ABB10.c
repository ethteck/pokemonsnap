#include "common.h"

void spawnStaryuAtGeo(GObj* obj) {
    addAnimalAtGeo(obj, AnimalID_STARYU, &extraStaryuDef);
    omEndProcess(NULL);
}

void spawnStarmieAtGeo(GObj* obj) {
    addAnimalAtGeo(obj, AnimalID_STARMIE, &extraStarmieDef);
    omEndProcess(NULL);
}

void func_802D25E0(GObj* obj) {
    weightedRandomStaightTransition(obj, &D_802ECB00_7C6090);
}

void func_802D2604(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    omCreateProcess(obj, spawnStaryuAtGeo, 1, 1);

    // clang-format off
    animal->counter = 1; animal->processFlags &= ~SP_HIDDEN;
    // clang-format on
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802D2684(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    omCreateProcess(obj, spawnStarmieAtGeo, 1, 1);
    // clang-format off
    animal->counter = 1; animal->processFlags &= ~SP_HIDDEN;
    // clang-format on
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802D2704(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_802ECB2C_7C60BC);
}
