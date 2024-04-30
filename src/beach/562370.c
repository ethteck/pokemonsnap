#include "common.h"
#include "beach.h"

void func_beach_802CA300(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);
    s32 sp34;
    f32 sp30;
    s32 sp2C;
    f32 sp28;

    obj->flags |= 2;

    while (1) {
        func_80357384_4F7794(&sp34, &sp30);
        if (sp34 > 0) {
            break;
        }

        if (sp34 == 0 && sp30 >= 0.92f) {
            break;
        }

        ohWait(1);
    }

    animal->flags |= 4;

    while (1) {
        func_80357384_4F7794(&sp2C, &sp28);
        if (sp2C > 0) {
            break;
        }

        if (sp2C == 0 && sp28 >= 0.99f) {
            break;
        }

        ohWait(1);
    }

    animal->flags &= 0xFFFB;
    updateAnimalState(obj, NULL);
}

void func_beach_802CA418(s32 gObjId, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjId, id, roomA, roomB, spawn, &D_beach_802CD948);
}

// TODO: potential file split. spawnAnimalUsingDeltaHeight tends to be used at the end of files

void func_beach_802CA450(GObj* obj) {
    updateAnimalState(obj, func_beach_802CA474);
}

void func_beach_802CA474(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CD980);
    animal->transitionGraph = &D_beach_802CD9D8;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA4CC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    cmdSendCommand(D_80382C00_523010, 9, 0);
    auPlaySound(0x26);
    setAnimalAnimation(obj, &D_beach_802CD994);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    auPlaySound(0x28);
    D_beach_802CD9D0 = auPlaySound(0x27);
    setAnimalAnimation(obj, &D_beach_802CD9A8);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CD9BC);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802CA950);
}

void func_beach_802CA5A8(DObj* obj, u32 arg1, f32 arg2) {
    if ((arg1 == -2) || (arg1 == -1)) {
        D_beach_802CD9D4 = 1;
    }
}

void func_beach_802CA5D4() {
}

void func_beach_802CA5DC(GObj* obj) {
    f32 var_f20;
    s32 var_s1;
    f32 steps;

    var_f20 = 1.0f;
    steps = 240.0;
    for (var_s1 = 239; var_s1 > 0; var_s1--) {
        var_f20 += -1.0f / steps;
        auSetBGMVolume(0, (32512.0f * var_f20));
        auSetBGMVolume(1, (32512.0f * var_f20));
        auSetSoundVolume(D_beach_80347578, (8192.0f * var_f20));
        auSetSoundVolume(D_beach_80347579, (8192.0f * var_f20));
        auSetSoundVolume(D_beach_8034757A, (14336.0f * var_f20));
        ohWait(1);
    }

    auSetBGMVolume(0, 0);
    auSetBGMVolume(1, 0);
    auSetSoundVolume(D_beach_80347578, 0);
    auSetSoundVolume(D_beach_80347579, 0);
    auSetSoundVolume(D_beach_8034757A, 0);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802CA8C4(GObj* obj) {
    s32 i;

    for (i = 0; i < 230; i++) {
        ohWait(1);
    }

    auPlaySound(0x29);
    if ((D_beach_802CD9D0 != -1) && D_800968BC[D_beach_802CD9D0] != -1) {
        auStopSound(D_beach_802CD9D0);
    }
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802CA950(GObj* obj) {
    s32 unused[4];
    GObj* temp_s1;
    OMCamera* temp_v0;
    s32 i;
    GObj* temp_v0_2;
    UnkBlueShark sp2C;

    sp2C = D_beach_802CD9F8;
    func_8035ED90_4FF1A0(obj, func_beach_802CA5DC);
    func_8035ED90_4FF1A0(obj, func_beach_802CA8C4);
    func_8035CAB0_4FCEC0();
    func_803573BC_4F77CC();
    func_80365E34_506244();
    func_8035FD9C_5001AC(&sp2C);
    ohWait(1);
    func_803570F0_4F7500(obj, 0, 0);
    temp_v0 = func_803586F8_4F8B08();
    temp_s1 = temp_v0->obj;
    ohPauseObjectProcesses(temp_s1);
    temp_v0->animSpeed = 0.5f;
    animSetCameraAnimation(temp_v0, D_8013C530, 0.0f);
    omCreateProcess(temp_s1, animUpdateCameraAnimation, 1, 1);
    func_800E1A78_5F228(D_8011B924);
    temp_v0_2 = func_80365E80_506290();
    if (temp_v0_2 == NULL) {
        cmdSendCommand(D_80382C00_523010, 7, 0);
        omEndProcess(NULL);
    }
    func_80365F38_506348(&D_8013B030, &D_8013BAA0, 0, 0.5f);
    D_beach_80347658 = temp_v0_2;
    D_beach_802CD9D4 = 0;
    temp_v0_2->fnAnimCallback = func_beach_802CA5A8;

    for (i = 0; D_beach_802CD9D4 == 0 && i != 0x4B0; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(D_80382C00_523010, 6, 0);
    omEndProcess(NULL);
    updateAnimalState(obj, NULL);
}

void func_beach_802CAB14(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_beach_802CDA10);
}
