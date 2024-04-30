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
    runInteractionsAndWaitForFlags(obj, 1U);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9B40(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD5BC);
    animal->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, 1U);
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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9CF8.s")

void func_beach_802C9D70(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9E70.s")

void func_beach_802C9EBC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD620);
    runPathProcess(obj, func_beach_802C9F30);
    animal->transitionGraph = &D_beach_802CD6F4;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C9CF8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9F30.s")

void func_beach_802C9F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, func_beach_802CA010);
    setAnimalAnimation(obj, &D_beach_802CD5E4);
    animal->transitionGraph = &D_beach_802CD6C4;
    runInteractionsAndWaitForFlags(obj, 1U);
    weightedRandomStaightTransition(obj, &D_beach_802CD764);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802CA010.s")

void func_beach_802CA05C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CD7A8);
}