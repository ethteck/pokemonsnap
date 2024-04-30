#include "common.h"
#include "beach.h"

void func_beach_802CAF90(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBD4);
    animal->transitionGraph = &D_beach_802CDCD0;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802CAF90);
}

void func_beach_802CAFEC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CDBC0);
    runPathProcess(obj, NULL);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802CAF90);
}

void func_beach_802CB054(GObj* obj) {
    runPathProcess(obj, func_beach_802CB128);
    updateAnimalState(obj, func_beach_802CB08C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB2D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB3DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB44C.s")

void func_beach_802CB4C4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CB520(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CDBD4);
    runPathProcess(obj, func_beach_802CB6B4);
    animal->transitionGraph = &D_beach_802CDE78;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802CB594);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB874.s")

void func_beach_802CB9E0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBC0);
    runPathProcess(obj, NULL);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802CB874);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CBA48.s")

void func_beach_802CBB34(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_80361B50_501F60(obj, animal->pos1.x, animal->pos1.z);
    func_80361E58_502268(obj, 0.1f);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CBB90(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBD4);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1U);
    setAnimalAnimation(obj, &D_beach_802CDBFC);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1U);
    forceAnimalAnimation(obj, &D_beach_802CDBFC);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802CBB90);
}

void func_beach_802CBC4C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBC0);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802CBB90);
}

void func_beach_802CBCA8(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CE038);
}

void func_beach_802CBCE0(GObj* obj) {
    updateAnimalState(obj, func_beach_802CBD04);
}

void func_beach_802CBD04(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    cmdSendCommandToLink(3, 0x25, obj);
    ohWait(1);
    func_803667C0_506BD0(obj, 1, 0x34);
    forceAnimalAnimation(obj, &D_beach_802CE070);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1U);
    cmdSendCommandToLink(3, 0x26, obj);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802CBDA0(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_beach_802CE0A8);
}

void func_beach_802CBDD8(GObj* obj) {
    GObj* var;

    var = addAnimalAtGeo(obj, 0x3EEU, &D_beach_802CE0DC);
    GET_ANIMAL(var)->behavior = 0;
}
