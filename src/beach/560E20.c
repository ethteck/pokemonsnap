#include "common.h"
#include "beach.h"

void func_beach_802C8DB0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[0].field0 = animal->collisionRadius;
    animal->collisionRadius = 0;
    updateAnimalState(obj, func_beach_802C8DE8);
}

void func_beach_802C8DE8(GObj* obj) {
    runPathProcess(obj, func_beach_802C8E20);
    updateAnimalState(obj, func_beach_802C8E90);
}

void func_beach_802C8E20(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 0, 0.1f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C8E90.s")

void func_beach_802C8F48(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->collisionRadius = animal->miscVars[0].field0;
    obj->flags = 0;
    runPathProcess(obj, func_beach_802C907C);
    setAnimalAnimation(obj, &D_beach_802CD168);
    animal->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CD1A4);
    animal->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, 2);
    setAnimalAnimation(obj, &D_beach_802CD190);
    animal->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, 1);
    cmdSendCommandToLink(3, 0x1E, obj);
    setAnimalAnimation(obj, &D_beach_802CD17C);
    animal->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, 2);
    runPathProcess(obj, func_beach_802C90E0);
    animal->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, 2);
    runAnimalCleanup(obj);
    updateAnimalState(obj, func_beach_802C8F48);
}

void func_beach_802C907C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 0.0f;
    animal->jumpVel = 100.0f;
    func_80360300_500710(obj, 150.0f, 0.0f, 0.0f, 0.0f);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C90E0(GObj* obj) {
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

void func_beach_802C914C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    // required to match
    if (FALSE) {
    }

    animal->hSpeed = 0.0f;
    animal->jumpVel = 150.0f;
    func_80360590_5009A0(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    animal->jumpVel = 150.0f;
    func_80360300_500710(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C91CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}

void func_beach_802C9204(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}
