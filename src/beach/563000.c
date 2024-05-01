#include "common.h"
#include "beach.h"

void func_beach_802CAF90(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBD4);
    animal->transitionGraph = &D_beach_802CDCD0;
    runInteractionsAndWaitForFlags(obj, 1);
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

void func_beach_802CB08C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDB84);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 3);
    if (animal->processFlags & 1) {
        updateAnimalState(obj, func_beach_802CB08C);
    }
    animal->transitionGraph = &D_beach_802CDD40;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802CAF90);
}

void func_beach_802CB128(GObj* obj) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB194.s")

void func_beach_802CB2D8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 0x200;
    animal->flags |= 0x800;
    func_8035ED90_4FF1A0(obj, func_beach_802CB814);
    setAnimalAnimation(obj, &D_beach_802CDB5C);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CDD80;
    runInteractionsAndWaitForFlags(obj, 1U);
    weightedRandomStaightTransition(obj, &D_beach_802CDE30);
}

void func_beach_802CB36C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CDB5C);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CDD80;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CDE30);
}

void func_beach_802CB3DC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDB70);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CDD80;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CDE30);
}

void func_beach_802CB44C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBC0);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CDE48;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802CB3DC);
}

void func_beach_802CB4BC() {
}

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
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802CB594);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB594.s")

void func_beach_802CB6B4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    ohWait(60);
    func_8036148C_50189C(obj, 0.1f, 0);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CB710(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 80.0f;
    func_80361748_501B58(obj, 50, 0.1f, 3);
    func_8036148C_50189C(obj, 0.1f, 0);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CB784(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDB84);
    runPathProcess(obj, func_beach_802CB128);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 3U);
    if (animal->processFlags & 1) {
        updateAnimalState(obj, func_beach_802CB784);
    }
    updateAnimalState(obj, func_beach_802CB3DC);
}

void func_beach_802CB814(GObj* obj) {
    while (func_beach_802CB194(obj)) {
        ohWait(1);
    }

    cmdSendCommand(obj, 0x23, obj);
    func_8035EDC8_4FF1D8(obj);
}

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

void func_beach_802CBA48(GObj* obj) {
    f32 temp_f0;
    f32 temp_f20;
    Animal* animal = GET_ANIMAL(obj);
    geoNode* node;
    Vec3f sp34;

    // TODO: verify cast
    node = (geoNode*) obj->data.any;
    ohWait(0x3C);
    func_8001FCE8(&sp34, animal->path, 0.99999f);
    temp_f0 = atan2f(sp34.x, sp34.z);
    temp_f20 = temp_f0 - ((s32) (temp_f0 / 6.2831855f) * 6.2831855f);
    if (func_80360FC8_5013D8(node, temp_f20, 0.13962634f) == 0) {
        do {
            ohWait(1);
        } while (func_80360FC8_5013D8(node, temp_f20, 0.13962634f) == 0);
    }
    animal->pathProcess = 0;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

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
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CDBFC);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1);
    forceAnimalAnimation(obj, &D_beach_802CDBFC);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802CBB90);
}

void func_beach_802CBC4C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CDBC0);
    animal->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, 1);
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
    runInteractionsAndWaitForFlags(obj, 1);
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
