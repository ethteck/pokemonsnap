#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5C60.s")

void func_beach_802C5DAC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[0].field0 = animal->collisionOffset.x;
    animal->miscVars[1].field0 = animal->collisionOffset.y;
    animal->miscVars[2].field0 = animal->collisionOffset.z;
    animal->miscVars[3].field0 = animal->collisionRadius;

    if (animal->behavior == 1) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C6658);
    }

    if (animal->behavior == 2) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C6C10);
    }

    if (animal->behavior == 3) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C6D20);
    }

    if (animal->behavior == 4) {
        updateAnimalState(obj, func_beach_802C6FD4);
    }

    updateAnimalState(obj, func_beach_802C5E88);
}

void func_beach_802C5E88(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC344);
    runPathProcess(obj, NULL);
    animal->transitionGraph = &D_beach_802CC40C;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C5EF8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC358);
    animal->animalLoopTarget = 5;
    runPathProcess(obj, func_beach_802C5F9C);
    animal->transitionGraph = &D_beach_802CC40C;
    runInteractionsAndWaitForFlags(obj, 3);
    if (animal->processFlags & 2) {
        updateAnimalState(obj, func_beach_802C5E88);
    }
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C5F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C5FF8(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[4].field1 = 0;
    runPathProcess(obj, NULL);
    setAnimalAnimation(obj, &D_beach_802CC3A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3BC);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3D0);
    animal->transitionGraph = &D_beach_802CC4C4;
    runInteractionsAndWaitForFlags(obj, 1);
    runPathProcess(obj, func_beach_802C619C);
    setAnimalAnimation(obj, &D_beach_802CC36C);
    animal->animalLoopTarget = 2;
    animal->transitionGraph = &D_beach_802CC4C4;
    runInteractionsAndWaitForFlags(obj, 3);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C60E8.s")

s32 func_80360F1C_50132C(GObj*, s32);

void func_beach_802C619C(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 80.0f;

    while (1) {
        if (func_80360F1C_50132C(obj, 1)) {
            break;
        }

        ohWait(1);
    }

    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C6210(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[4].field1 = 0;
    animal = animal;
    setAnimalAnimation(obj, &D_beach_802CC36C);
    runPathProcess(obj, func_beach_802C6288);
    animal->transitionGraph = &D_beach_802CC524;
    runInteractionsAndWaitForFlags(obj, 2);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C6288(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C62E4.s")

void func_beach_802C63F4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8036148C_50189C(obj, 0.1f, 0);
    setAnimalAnimation(obj, &D_beach_802CC36C);
    animal->hSpeed = 80.0f;
    func_80361748_501B58(obj, 50.0f, 0.1f, 3);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C6478(GObj* obj) {
    updateAnimalState(obj, func_beach_802C62E4);
}

void func_beach_802C649C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[4].field1 = 0;
    setAnimalAnimation(obj, &D_beach_802CC3F8);
    runPathProcess(obj, func_beach_802C6514);
    animal->transitionGraph = &D_beach_802CC594;
    runInteractionsAndWaitForFlags(obj, 2);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C6514(GObj* obj) {
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

void func_beach_802C6580(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, func_beach_802C660C);
    func_8035ED90_4FF1A0(obj, func_beach_802C5C60);
    setAnimalAnimation(obj, &D_beach_802CC380);
    animal->transitionGraph = &D_beach_802CC5C4;
    runInteractionsAndWaitForFlags(obj, 1);
    animal->miscVars[4].field1 = 0;
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C660C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C6658(GObj* obj) {
    updateAnimalState(obj, func_beach_802C667C);
}

void func_beach_802C667C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags &= ~0x20;
    runPathProcess(obj, NULL);
    setAnimalAnimation(obj, &D_beach_802CC344);
    animal->transitionGraph = &D_beach_802CC644;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C67F8() {
}

void func_beach_802C6700(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);
    s32 sp24;
    f32 sp20;

    animal->processFlags |= 0x20;
    runPathProcess(obj, NULL);
    forceAnimalAnimation(obj, &D_beach_802CC3A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    func_80357384_4F7794(&sp24, &sp20);
    sp20 += sp24;
    if (sp20 > 3.0f) {
        runPathProcess(obj, func_beach_802C660C);
        updateAnimalState(obj, func_beach_802C6AA0);
    }
    cmdSendCommandToLink(3, 0x1C, obj);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802C67E0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags |= 0x20;
    runPathProcess(obj, NULL);
    forceAnimalAnimation(obj, &D_beach_802CC394);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C667C);
}

void func_beach_802C6854(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    runPathProcess(obj, func_beach_802C68D8);
    animal->processFlags |= 0x20;
    setAnimalAnimation(obj, &D_beach_802CC3F8);
    animal->transitionGraph = &D_beach_802CC6B4;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C667C);
}

void func_beach_802C68D8(GObj* obj) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6944.s")

extern idFuncStruct D_beach_802CC714;

void func_beach_802C69D4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags &= ~0x20;
    setAnimalAnimation(obj, &D_beach_802CC344);
    animal->transitionGraph = &D_beach_802CC714;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C6A3C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[4].field1 = 0;
    animal->processFlags |= 0x20;
    forceAnimalAnimation(obj, &D_beach_802CC3A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C6AA0);
}
extern animationHeader D_beach_802CC3D0;
extern idFuncStruct D_beach_802CC784;

void func_beach_802C6AA0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CC3BC);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    forceAnimalAnimation(obj, &D_beach_802CC3D0);
    animal->transitionGraph = &D_beach_802CC784;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C69D4);
}

void func_beach_802C6B28(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[4].field1 = 0;
    animal->processFlags |= 0x20;
    forceAnimalAnimation(obj, &D_beach_802CC394);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C69D4);
}

void func_beach_802C6B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, func_beach_802C68D8);
    animal->processFlags |= 0x20;
    setAnimalAnimation(obj, &D_beach_802CC3F8);
    animal->transitionGraph = &D_beach_802CC7B4;
    runInteractionsAndWaitForFlags(obj, 2);
    updateAnimalState(obj, func_beach_802C69D4);
}

void func_beach_802C6C10(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= GOBJ_FLAG_1 | GOBJ_FLAG_2;
    animal->transitionGraph = &D_beach_802CC7E4;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C6C60(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 1;
    obj->flags = 0;
    setAnimalAnimation(obj, &D_beach_802CC3BC);
    animal->transitionGraph = &D_beach_802CC804;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C6CC4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC3D0);
    animal->transitionGraph = &D_beach_802CC824;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C6580);
}

void func_beach_802C6D20(GObj* obj) {
    updateAnimalState(obj, func_beach_802C6D44);
}

void func_beach_802C6D44(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC344);
    animal->transitionGraph = &D_beach_802CC854;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C6D9C(GObj* obj) {
    runPathProcess(obj, func_beach_802C6DD4);
    updateAnimalState(obj, func_beach_802C6E40);
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

void func_beach_802C6E40(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags &= ~0x20;
    setAnimalAnimation(obj, &D_beach_802CC36C);
    animal->transitionGraph = &D_beach_802CC874;
    runInteractionsAndWaitForFlags(obj, 2);
    setAnimalAnimation(obj, &D_beach_802CC344);
    updateAnimalState(obj, NULL);
}

void func_beach_802C6EC0(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags |= 0x20;
    setAnimalAnimation(obj, &D_beach_802CC3A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3BC);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3D0);
    animal->transitionGraph = &D_beach_802CC8A4;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C6E40);
}

void func_beach_802C6F6C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags |= 0x20;
    forceAnimalAnimation(obj, &D_beach_802CC394);
    animal->transitionGraph = &D_beach_802CC8D4;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C6E40);
}

void func_beach_802C6FD4(GObj* obj) {
    updateAnimalState(obj, func_beach_802C6FF8);
}

void func_beach_802C6FF8(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC344);
    animal->transitionGraph = &D_beach_802CC904;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C7050(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_beach_802CBDD8(obj);
    setAnimalAnimation(obj, &D_beach_802CC3A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3BC);
    updateAnimalState(obj, NULL);
}

void func_beach_802C70C0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC3F8);
    runPathProcess(obj, func_beach_802C660C);
    animal->transitionGraph = &D_beach_802CC934;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C7130(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    runPathProcess(obj, NULL);
    setAnimalAnimation(obj, &D_beach_802CC3A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3BC);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CC3D0);
    animal->transitionGraph = &D_beach_802CC934;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C70C0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C71E8.s")

void func_beach_802C7270(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    if (spawn->behavior == 1) {
        // required to match
        if (FALSE) {
        }

        spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CC968);
    } else {
        func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CC968);
    }
}
