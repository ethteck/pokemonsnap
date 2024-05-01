#include "common.h"
#include "beach.h"

void func_beach_802C9AC0(GObj* obj) {
    updateAnimalState(obj, func_beach_802C9AE4);
}

void func_beach_802C9AE4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD5A8);
    animal->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9B40(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD5BC);
    animal->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9B9C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD60C);
    animal->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9BF8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    setAnimalAnimation(obj, &D_beach_802CD5F8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    runPathProcess(obj, func_beach_802C9C88);
    setAnimalAnimation(obj, &D_beach_802CD5D0);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C9F9C);
}

void func_beach_802C9C88(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    animal = animal;
    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0.0f, 1.0f, 0.05f, 0.1f, 0x81U);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C9CF8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD5A8);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CD634;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CD764);
}

void func_beach_802C9D68() {
}

void func_beach_802C9D70(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C9DCC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, NULL);
    setAnimalAnimation(obj, &D_beach_802CD5F8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    runPathProcess(obj, func_beach_802C9E70);
    setAnimalAnimation(obj, &D_beach_802CD5E4);
    animal->transitionGraph = &D_beach_802CD6C4;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C9CF8);
}

void func_beach_802C9E70(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C9EBC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD620);
    runPathProcess(obj, func_beach_802C9F30);
    animal->transitionGraph = &D_beach_802CD6F4;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C9CF8);
}

void func_beach_802C9F30(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    while (1) {
        if (!func_80361440_501850(obj)) {
            break;
        }

        ohWait(1);
    }

    animal->processFlags |= 2;
    animal->pathProcess = NULL;
    omEndProcess(NULL);
}

void func_beach_802C9F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, func_beach_802CA010);
    setAnimalAnimation(obj, &D_beach_802CD5E4);
    animal->transitionGraph = &D_beach_802CD6C4;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CD764);
}

void func_beach_802CA010(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CA05C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CD7A8);
}
