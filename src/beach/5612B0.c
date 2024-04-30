#include "common.h"
#include "beach.h"

void func_beach_802C9240(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    D_beach_802CD3F4 = animal->path;
    updateAnimalState(obj, func_beach_802C9274);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C92BC.s")

void func_beach_802C9348(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 0, 0.05f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C93B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C943C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C94F0.s")

void func_beach_802C9580(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD2E4);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CD35C;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CD3DC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C95F0.s")

void func_beach_802C9694(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 30.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C96F0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD30C);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CD478;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C9580);
}

void func_beach_802C9760(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD320);
    runPathProcess(obj, func_beach_802C97D4);
    animal->transitionGraph = &D_beach_802CD4A8;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C9580);
}

void func_beach_802C97D4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C98F4.s")

void func_beach_802C9978(GObj* obj) {
    updateAnimalState(obj, func_beach_802C9830);
}

void func_beach_802C999C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD2BC);
    runPathProcess(obj, func_beach_802C9A10);
    animal->transitionGraph = &D_beach_802CD518;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C9580);
}

void func_beach_802C9A10(GObj* obj) {
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

void func_beach_802C9A7C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CD55C);
}
