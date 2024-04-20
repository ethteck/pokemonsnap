#include "common.h"

void func_802DE3FC_72F5FC(GObj* obj);
void func_802DE450_72F650(GObj* obj);
void func_802DE4C0_72F6C0(GObj* obj);

extern animationHeader D_802E31F4;
extern animationHeader D_802E3208;
extern animationHeader D_802E321C;
extern animalInitData koffingSmokeData;

void func_802DE390_72F590(GObj* obj) {
    UNUSED s32 pad[3];
    animal* animal = obj->data.animal;

    forceAnimalAnimation(obj, &D_802E31F4);
    runPathProcess(obj, func_802DE4C0_72F6C0);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_802DE3FC_72F5FC);
}

void func_802DE3FC_72F5FC(GObj* obj) {
    UNUSED s32 pad[3];
    animal* animal = obj->data.animal;

    forceAnimalAnimation(obj, &D_802E3208);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_802DE450_72F650);
}

void func_802DE450_72F650(GObj* obj) {
    UNUSED s32 pad[3];
    animal* animal = obj->data.animal;

    setAnimalAnimation(obj, &D_802E321C);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    sendSignalToLink(3, 0x21, obj);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_802DE4C0_72F6C0(GObj* obj) {
    UNUSED s32 pad[3];
    animal* animal = obj->data.animal;

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1.0f, 0.05f, 0.0f, 2);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    om_end_process(NULL);
}

void spawnKoffingSmoke(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &koffingSmokeData);
}
