#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C72E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C737C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C73EC.s")

void func_beach_802C7490(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C74EC.s")

void func_beach_802C755C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);
    ;

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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C762C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C76C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C7748.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C78E8.s")

void func_beach_802C796C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 0, 0.05f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C79DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C7A60.s")

void func_beach_802C7AD0(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CCCEC);
}
