#include "common.h"
#include "beach.h"

void func_beach_802C85B0(GObj* arg0) {
    arg0->flags |= 1;
    updateAnimalState(arg0, func_beach_802C85E0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C85E0.s")

void func_beach_802C86A8(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    if (animal->behavior == 1) {
        updateAnimalState(obj, func_beach_802C8980);
    }

    obj->flags = 0;
    animal->processFlags &= ~0x20;
    setAnimalAnimation(obj, &D_beach_802CCFC0);
    animal->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CCFD4);
    animal->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 2);
    setAnimalAnimation(obj, &D_beach_802CCFE8);
    animal->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CCFFC);
    animal->animalLoopTarget = 1;
    animal->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C8828);
}

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
    runInteractionsAndWaitForFlags(obj, 2);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8894(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    // required to match
    if (FALSE) {
    }

    animal->hSpeed = 200.0f;
    animal->jumpVel = 90.0f;
    func_80360300_500710(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C8900(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    // required to match
    if (FALSE) {
    }

    animal->hSpeed = 0.0f;
    animal->jumpVel = 150.0f;
    animal = animal;
    func_80360590_5009A0(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    animal->jumpVel = 150.0f;
    func_80360300_500710(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8980(GObj* obj) {
    updateAnimalState(obj, func_beach_802C89A4);
}

void func_beach_802C8BC4(GObj*); /* extern */
extern idFuncStruct D_beach_802CD064;

void func_beach_802C89A4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    // required to match
    if (FALSE) {
    }

    animal->miscVars[0].field1 = 0;
    obj->flags = 0;
    animal->processFlags &= ~0x20;
    setAnimalAnimation(obj, &D_beach_802CCFC0);
    animal->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CCFD4);
    animal->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 2);
    func_8035ED90_4FF1A0(obj, func_beach_802C8BC4);
    setAnimalAnimation(obj, &D_beach_802CCFE8);
    animal->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CCFFC);
    animal->animalLoopTarget = 1;
    animal->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C8828);
}

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
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8CC0(GObj* obj) {
    cmdSendCommandToLink(3, 0x1F, obj);
    updateAnimalState(obj, func_beach_802C86A8);
}

void func_beach_802C8CFC(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->transitionGraph = &D_beach_802CD0E4;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8D3C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}

void func_beach_802C8D74(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}
