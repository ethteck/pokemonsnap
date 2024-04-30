#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAB50.s")

void func_beach_802CAC08(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8035E298_4FE6A8(obj);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CAC48(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CDAEC);
}

// TODO: potential file split. func_80362EE0_5032F0 tends to be used at the end of files

void func_beach_802CAC80(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 0x200;
    animal->flags |= 0x800;
    animal->transitionGraph = &D_beach_802CDC60;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

void func_beach_802CACD4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    if (animal->behavior == 1) {
        updateAnimalState(obj, func_beach_802CAD58);
    }

    if (animal->behavior == 4) {
        updateAnimalState(obj, func_beach_802CB2D8);
    }
    updateAnimalState(obj, func_beach_802CAC80);
    updateAnimalState(obj, NULL);
}

void func_beach_802CAD58(GObj* obj) {
    updateAnimalState(obj, func_beach_802CAD7C);
}

void func_beach_802CAD7C(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= GOBJ_FLAG_1 | GOBJ_FLAG_2;
    animal->transitionGraph = &D_beach_802CDC80;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802CADCC(GObj* ob) {
    Animal* animal = GET_ANIMAL(ob);

    animal->tangible = 1;
    ob->flags = 0;
    runPathProcess(ob, func_beach_802CAEB0);
    updateAnimalState(ob, func_beach_802CAE14);
}

void func_beach_802CAE14(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 1;
    obj->flags = 0;
    setAnimalAnimation(obj, &D_beach_802CDBAC);
    animal->transitionGraph = &D_beach_802CDCA0;
    runInteractionsAndWaitForFlags(obj, 2U);
    animal->field_0x10e = 5;
    setAnimalAnimation(obj, &D_beach_802CDBFC);
    animal->transitionGraph = &D_beach_802CDCA0;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802CAF90);
}

void func_beach_802CAEB0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(0);
}

void func_beach_802CAF1C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags |= 0x20;
    setAnimalAnimation(obj, &D_beach_802CDBC0);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    animal->processFlags &= ~0x20;
    updateAnimalState(obj, func_beach_802CAE14);
}
