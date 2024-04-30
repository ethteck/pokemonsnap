#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAB50.s")

void func_beach_802CAC08(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    func_8035E298_4FE6A8(obj);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802CAC48(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CDAEC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CACD4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CADCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAE14.s")

void func_beach_802CAEB0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAF1C.s")
