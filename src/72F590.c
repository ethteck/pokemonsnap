#include "common.h"

void func_802DE3FC_72F5FC(GObj* obj);
void func_802DE450_72F650(GObj* obj);
void func_802DE4C0_72F6C0(GObj* obj);

extern animationHeader D_802E31F4_7343F4;
extern animationHeader D_802E3208_734408;
extern animationHeader D_802E321C_73441C;
extern animalInitData koffingSmokeData;



void func_802DE390_72F590(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_802E31F4_7343F4);
    runPathProcess(obj, func_802DE4C0_72F6C0);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_802DE3FC_72F5FC);
}

void func_802DE3FC_72F5FC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_802E3208_734408);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_802DE450_72F650);
}

void func_802DE450_72F650(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_802E321C_73441C);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    cmdSendCommandToLink(3, 0x21, obj);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802DE4C0_72F6C0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1, 0.05f, 0.0f, 2);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void spawnKoffingSmoke(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &koffingSmokeData);
}
