#include "common.h"
#include "beach.h"

void func_beach_802C5620(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    s32 sp34;
    f32 sp30;

    while (1) {
        func_80357384_4F7794(&sp34, &sp30);
        if (sp34 >= 4) {
            break;
        }

        if (sp34 == 3 && sp30 >= 0.3) {
            break;
        }

        ohWait(1);
    }

    runAnimalCleanup(obj);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C56C8(GObj* obj) {
    func_8035ED90_4FF1A0(obj, func_beach_802C5620);
    updateAnimalState(obj, func_beach_802C5700);
}

void func_beach_802C5700(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 8;
    setAnimalAnimation(obj, &D_beach_802CC10C);
    animal->transitionGraph = &D_beach_802CC1D4;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CC2C4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5768.s")

void func_beach_802C5828(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CC134);
    animal->transitionGraph = &D_beach_802CC1D4;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C5700);
}

void func_beach_802C5884(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 8;
    updateAnimalState(obj, func_beach_802C5768);
}

void func_beach_802C58B8(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 8;
    updateAnimalState(obj, func_beach_802C5828);
}

void func_beach_802C58EC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags &= ~8;
    setAnimalAnimation(obj, &D_beach_802CC148);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C594C);
}

void func_beach_802C594C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC170);
    runPathProcess(obj, func_beach_802C5B68);
    animal->transitionGraph = &D_beach_802CC234;
    ;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C5BD4);
}

void func_beach_802C59C0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags &= ~8;
    setAnimalAnimation(obj, &D_beach_802CC148);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C5A20);
}

void func_beach_802C5A20(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC184);
    runPathProcess(obj, func_beach_802C5B68);
    animal->transitionGraph = &D_beach_802CC264;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C5BD4);
}

void func_beach_802C5A94(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags &= ~8;
    setAnimalAnimation(obj, &D_beach_802CC148);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C5AF4);
}

void func_beach_802C5AF4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC198);
    runPathProcess(obj, func_beach_802C5B68);
    animal->transitionGraph = &D_beach_802CC294;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C5BD4);
}

void func_beach_802C5B68(GObj* obj) {
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

void func_beach_802C5BD4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC15C);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C5700);
}

void func_beach_802C5C28(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CC2F0);
}
