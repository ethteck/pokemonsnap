#include "common.h"

extern idFuncStruct D_beach_802CD0E4;
extern animalInitData D_beach_802CD118;
extern animalInitData D_beach_802CD118;

void func_8035EDC8_4FF1D8(GObj*);
void func_beach_802C89A4(GObj*);
void func_beach_802C85E0(GObj*);
void func_beach_802C86A8(GObj*);

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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8900.s")

void func_beach_802C8980(GObj* obj) {
    updateAnimalState(obj, func_beach_802C89A4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C89A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8AAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8BC4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C8C7C.s")

void func_beach_802C8CC0(GObj* arg0) {
    cmdSendCommandToLink(3, 0x1F, arg0);
    updateAnimalState(arg0, func_beach_802C86A8);
}

void func_beach_802C8CFC(GObj* arg0) {
    Animal* animal = GET_ANIMAL(arg0);

    animal->transitionGraph = &D_beach_802CD0E4;
    runInteractionsAndWaitForFlags(arg0, 0U);
    updateAnimalState(arg0, NULL);
}

void func_beach_802C8D3C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}

void func_beach_802C8D74(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}
