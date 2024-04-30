#include "common.h"

extern animationHeader D_beach_802CC344;
extern idFuncStruct D_beach_802CC854;
extern idFuncStruct D_beach_802CC904;
extern idFuncStruct D_beach_802CC7E4;

void func_beach_802C6FF8(GObj*);
void func_beach_802C6D44(GObj*);
void func_beach_802C667C(GObj*);
void func_beach_802C6DD4(GObj*);
void func_beach_802C6E40(GObj*);
void func_beach_802C62E4(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5EF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C60E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C619C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C62E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C63F4.s")

void func_beach_802C6478(GObj* arg0) {
    updateAnimalState(arg0, func_beach_802C62E4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C660C.s")

void func_beach_802C6658(GObj* obj) {
    updateAnimalState(obj, func_beach_802C667C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C667C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C67E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C68D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C69D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6AA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6B28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6B8C.s")

void func_beach_802C6C10(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= GOBJ_FLAG_1 | GOBJ_FLAG_2;
    animal->transitionGraph = &D_beach_802CC7E4;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6CC4.s")

void func_beach_802C6D20(GObj* obj) {
    updateAnimalState(obj, func_beach_802C6D44);
}

void func_beach_802C6D44(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC344);
    animal->transitionGraph = &D_beach_802CC854;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

void func_beach_802C6D9C(GObj* arg0) {
    runPathProcess(arg0, func_beach_802C6DD4);
    updateAnimalState(arg0, func_beach_802C6E40);
}

void func_beach_802C6DD4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1.0f, 0.033333335f, 0.0f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6F6C.s")

void func_beach_802C6FD4(GObj* obj) {
    updateAnimalState(obj, func_beach_802C6FF8);
}

void func_beach_802C6FF8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    setAnimalAnimation(obj, &D_beach_802CC344);
    animal->transitionGraph = &D_beach_802CC904;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C7050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C70C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C7130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C71E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C7270.s")
