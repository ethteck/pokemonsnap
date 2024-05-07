#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7BB8.s")

void func_beach_802C7C7C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, randFloat(), 0, 0.1f, 0.0f, 2);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C7CF0(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags &= ~0x20;
    func_8035ED90_4FF1A0(obj, func_beach_802C7DA0);
    setAnimalAnimation(obj, &D_beach_802CCD4C);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 8);
    func_8035ED90_4FF1A0(obj, func_beach_802C7DEC);
    setAnimalAnimation(obj, &D_beach_802CCD24);
    animal->transitionGraph = &D_beach_802CCD60;
    runInteractionsAndWaitForFlags(obj, 8);
    updateAnimalState(obj, func_beach_802C7BB8);
}

void func_beach_802C7DA0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->jumpVel = 300.0f;
    func_80360300_500710(obj, 400, 0, 0, 0);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C7DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->jumpVel = 90.0f;
    func_80360590_5009A0(obj, 400, 0, 0, 0);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C7E38(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CCDA4);
}

// TODO: potential file split

void func_beach_802C7E70(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= 2 | 1;
    if (animal->behavior == 2) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C816C);
    }
    if (animal->behavior == 4) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C81C4);
    }
    if (animal->behavior == 5) {
        updateAnimalState(obj, func_beach_802C821C);
    }
    updateAnimalState(obj, func_beach_802C7F1C);
}

void func_beach_802C7F1C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    func_8035ED90_4FF1A0(obj, func_beach_802C7F74);
    animal->transitionGraph = &D_beach_802CCE1C;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C7F74(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= 2 | 1;
    forceAnimalAnimation(obj, &D_beach_802CCE08);

    // clang-format off
    animal->counter = randRange(600) + 1; animal->processFlags &= ~4;
    // clang-format on

    func_8035FC54_500064(obj, 4);
    animal->tangible = 1;
    obj->flags = 0;
    forceAnimalAnimation(obj, &D_beach_802CCDE8);
    func_8035FC54_500064(obj, 1);
    func_8035ED90_4FF1A0(obj, func_beach_802C7F74);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8028(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    if (animal->behavior == 0) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C80BC);
    }
    if (animal->behavior == 1) {
        animal = animal;
        updateAnimalState(obj, func_beach_802C80F0);
    }
    if (animal->behavior == 2) {
        updateAnimalState(obj, func_beach_802C8124);
    }
    updateAnimalState(obj, NULL);
}

void func_beach_802C80BC(GObj* obj) {
    D_beach_802CCDFC++;
    updateAnimalState(obj, NULL);
}

void func_beach_802C80F0(GObj* obj) {
    D_beach_802CCE00++;
    updateAnimalState(obj, NULL);
}

void func_beach_802C8124(GObj* obj) {
    D_beach_802CCE00++;
    D_beach_802CCE04++;
    updateAnimalState(obj, NULL);
}

void func_beach_802C816C(GObj* obj) {
    while (TRUE) {
        if (D_beach_802CCDFC > 0) {
            break;
        }

        ohWait(1);
    }

    updateAnimalState(obj, func_beach_802C7F1C);
}

void func_beach_802C81C4(GObj* obj) {
    while (TRUE) {
        if (D_beach_802CCE00 > 0) {
            break;
        }

        ohWait(1);
    }

    updateAnimalState(obj, func_beach_802C7F1C);
}

void func_beach_802C821C(GObj* obj) {
    while (TRUE) {
        if (D_beach_802CCE04 > 0) {
            break;
        }

        ohWait(1);
    }

    updateAnimalState(obj, func_beach_802C7F1C);
}

void func_beach_802C8274(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CCE50);
}
