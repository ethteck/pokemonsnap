#include "common.h"
#include "beach.h"

void func_beach_802C72E0(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    while (D_beach_802CD3F4 == NULL) {
        ohWait(1);
    }
    animal->path = D_beach_802CD3F4;
    ohWait(60);
    animal->flags |= 0x200;
    animal->flags |= 0x800;
    if (animal->behavior == 1) {
        updateAnimalState(obj, func_beach_802C78B0);
    }
    updateAnimalState(obj, func_beach_802C737C);
}

void func_beach_802C737C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC9AC);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CCA10;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CCAA0);
}

void func_beach_802C73EC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC9C0);
    animal->animalLoopTarget = 5;
    runPathProcess(obj, func_beach_802C7490);
    animal->transitionGraph = &D_beach_802CCA10;
    runInteractionsAndWaitForFlags(obj, 3);
    if (animal->processFlags & 2) {
        updateAnimalState(obj, func_beach_802C737C);
    }
    weightedRandomStaightTransition(obj, &D_beach_802CCAA0);
}

void func_beach_802C7490(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C74EC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CC9E8);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CCAB8;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C737C);
}

void func_beach_802C755C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC9D4);
    runPathProcess(obj, func_beach_802C75D0);
    animal->transitionGraph = &D_beach_802CCAE8;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C737C);
}

void func_beach_802C75D0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C762C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC9C0);
    runPathProcess(obj, func_beach_802C76C4);
    animal->transitionGraph = &D_beach_802CCB28;
    runInteractionsAndWaitForFlags(obj, 2);
    if (!(animal->processFlags & 0x10)) {
        updateAnimalState(obj, func_beach_802C737C);
    }
    updateAnimalState(obj, func_beach_802C7748);
}

void func_beach_802C76C4(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    func_8036148C_50189C(obj, 0.1f, 0);
    setAnimalAnimation(obj, &D_beach_802CC9D4);
    animal->hSpeed = 80.0f;
    func_80361748_501B58(obj, 50.0f, 0.1f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C7748(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC9FC);
    animal->transitionGraph = &D_beach_802CCBA8;
    runInteractionsAndWaitForFlags(obj, 1);
    if (animal->interactionTarget != NULL) {
        updateAnimalState(obj, func_beach_802C7748);
    }
    weightedRandomStaightTransition(obj, &D_beach_802CCAA0);
}

void func_beach_802C77CC(GObj* obj) {
    updateAnimalState(obj, func_beach_802C762C);
}

void func_beach_802C77F0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC9C0);
    runPathProcess(obj, func_beach_802C7864);
    animal->transitionGraph = &D_beach_802CCBF8;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C737C);
}

void func_beach_802C7864(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2E);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C78B0(GObj* obj) {
    runPathProcess(obj, func_beach_802C796C);
    updateAnimalState(obj, func_beach_802C78E8);
}

void func_beach_802C78E8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags &= ~0x20;
    cmdSendCommandToLink(3, 0x22, obj);
    setAnimalAnimation(obj, &D_beach_802CC9D4);
    animal->transitionGraph = &D_beach_802CCC28;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C796C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 0, 0.05f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C79DC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CC9E8);
    animal->processFlags |= 0x20;
    cmdSendCommandToLink(3, 0x21, obj);
    animal->transitionGraph = &D_beach_802CCC68;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C78E8);
}

void func_beach_802C7A60(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, NULL);
    setAnimalAnimation(obj, &D_beach_802CC9FC);
    animal->transitionGraph = &D_beach_802CCCA8;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C737C);
}

void func_beach_802C7AD0(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CCCEC);
}
