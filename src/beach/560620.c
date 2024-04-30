#include "common.h"
#include "beach.h"

void func_beach_802C85B0(GObj* arg0) {
    arg0->flags |= 1;
    updateAnimalState(arg0, func_beach_802C85E0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C85E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C86A8.s")

void func_beach_802C87BC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 2);

    animal->pathProcess = 0;
    animal->processFlags |= 2;
    omEndProcess(0);
}

void func_beach_802C8828(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->field_0x10e = 0;
    animal = animal;
    runPathProcess(obj, func_beach_802C8894);
    animal->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 2U);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8900.s")

void func_beach_802C8980(GObj* obj) {
    updateAnimalState(obj, func_beach_802C89A4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C89A4.s")

void func_beach_802C8AAC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    if (++D_beach_802CD060 == 2) {
        cmdSendCommandToLink(3, 0x24, obj);
    }

    animal->miscVars[0].field1 = 1;
    animal->field_0x10e = 0;
    setAnimalAnimation(obj, &D_beach_802CCFD4);
    runPathProcess(obj, func_beach_802C8B60);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8B60(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 0.0f;
    animal->jumpVel = 90.0f;
    func_80360300_500710(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C8BC4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    animal->counter = 0x80;
    animal->processFlags &= ~4;
    animal = animal;
    func_8035FC54_500064(obj, 4);
    if (animal->miscVars[0].field1 == 0) {
        cmdSendCommandToLink(3, 0x1D, obj);
    }
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8C30(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);
    animal->field_0x10e = 7;
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8C58(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);
    animal->field_0x10e = 0;
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8C7C(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    obj->flags = 0;
    animal->transitionGraph = &D_beach_802CD0B4;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8CC0(GObj* obj) {
    cmdSendCommandToLink(3, 0x1F, obj);
    updateAnimalState(obj, func_beach_802C86A8);
}

void func_beach_802C8CFC(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->transitionGraph = &D_beach_802CD0E4;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8D3C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}

void func_beach_802C8D74(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}
