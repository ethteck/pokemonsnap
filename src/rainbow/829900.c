#include "common.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "rainbow.h"

extern AnimCmd* D_80119AE0;
extern AnimCmd** D_8011A970;
extern AnimCmd D_8011B3E0;

extern AnimationHeader D_8034B600_82AD70;
extern PokemonInitData D_8034B638_82ADA8;
extern s32 D_8034B670_82ADE0;
extern GObj* D_8034B674_82ADE4;
extern f32 D_8034B720_82AE90;
extern f32 D_8034B724_82AE94;
extern f32 D_8034B728_82AE98;
extern f32 D_8034B72C_82AE9C;
extern f32 D_8034B730_82AEA0;
extern f32 D_8034B734_82AEA4;
extern f32 D_8034B738_82AEA8;
extern u8 D_803501E8_82F958;
extern u8 D_803501E9_82F959;
extern u8 D_803501EA_82F95A;

void func_8034A334_829AA4(GObj*);
void func_8034A3A0_829B10(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A190_829900.s")

void func_8034A27C_8299EC(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A27C_8299EC.s")

void func_8034A334_829AA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_8034B600_82AD70);
    Pokemon_StartPathProc(obj, func_8034A3A0_829B10);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_8034A27C_8299EC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A3A0_829B10.s")

GObj* func_8034A4E8_829C58(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034B638_82ADA8);
}

void func_8034A520_829C90(GObj* obj) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(obj);
    func_803570B0_4F74C0();
}

void func_8034A550_829CC0(void) {
    func_803572B0_4F76C0();
    setBackgroundMusic(0xE);
}

void func_8034A578_829CE8(DObj* arg0, s32 arg1, f32 arg2) {
    UnkPinkRat* temp_v0;
    s32 temp_a1;

    if (arg1 == -2 || arg1 == -1) {
        D_8034B670_82ADE0 = 1;
        return;
    }

    temp_a1 = (s32) arg2 - 1;
    if (temp_a1 >= 0) {
        temp_v0 = func_800A6C48(arg1, temp_a1);
        if (temp_v0 != NULL) {
            temp_v0->dobj = arg0;
        }
    }
}

void func_8034A5EC_829D5C(void) {
    if (auPlayingSound[D_803501E8_82F958] == 0x27) {
        auStopSound((u32) D_803501E8_82F958);
    }
    if (auPlayingSound[D_803501E9_82F959] == 0x15) {
        auStopSound((u32) D_803501E9_82F959);
    }
    if (auPlayingSound[D_803501EA_82F95A] == 0xF) {
        auStopSound((u32) D_803501EA_82F95A);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_8034A550_829CC0();
    omDeleteGObj(NULL);
}

void func_8034A6B4_829E24(GObj* arg0) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }

    D_803501E9_82F959 = auPlaySoundWithParams(0x15U, 0x7000, 0x40, 1.0f, 0x1E);
    D_803501E8_82F958 = auPlaySoundWithParams(0x27U, 0x7000, 0x40, 1.0f, 0x14);
    omEndProcess(NULL);
}

void func_8034A748_829EB8(GObj* arg0) {
    s32 i;

    for (i = 0; i < 170; i++) {
        ohWait(1);
    }

    D_803501EA_82F95A = auPlaySoundWithParams(0xFU, 0x7000, 0x40, 1.0f, 0x1E);
    auStopSound(D_803501E8_82F958);
    omEndProcess(NULL);
}

void func_8034A7C4_829F34(GObj* obj) {
    UNUSED s32 pad[7];
    f32 origEyeX, origEyeY, origEyeZ;
    f32 origAtX, origAtY, origAtZ;
    f32 eyeX, eyeY, eyeZ;
    f32 atX, atY, atZ;
    GObjProcess* proc;
    GObj* camObj;
    f32 eyeDiffX, eyeDiffY, eyeDiffZ;
    f32 atDiffX, atDiffY, atDiffZ;
    OMCamera* cam;
    s32 i;

    cam = getMainCamera();
    camObj = getMainCamera()->obj;
    origEyeX = cam->viewMtx.lookAt.eye.x;
    origEyeY = cam->viewMtx.lookAt.eye.y;
    origEyeZ = cam->viewMtx.lookAt.eye.z;
    origAtX = cam->viewMtx.lookAt.at.x;
    origAtY = cam->viewMtx.lookAt.at.y;
    origAtZ = cam->viewMtx.lookAt.at.z;
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, &D_8011B3E0, 0.0f);
    proc = omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(&D_80119AE0, &D_8011A970, 0.0f, 0.5f);
    D_8034B670_82ADE0 = 0;
    obj->fnAnimCallback = func_8034A578_829CE8;
    omCreateProcess(obj, func_8034A6B4_829E24, 0, 1);
    omCreateProcess(obj, func_8034A748_829EB8, 0, 1);

    for (i = 0; D_8034B670_82ADE0 == 0 && i < 290; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            omEndProcess(proc);
            func_8034A5EC_829D5C();
        }
        ohWait(1);
    }

    omEndProcess(proc);

    eyeX = cam->viewMtx.lookAt.eye.x;
    eyeY = cam->viewMtx.lookAt.eye.y;
    eyeZ = cam->viewMtx.lookAt.eye.z;
    atX = cam->viewMtx.lookAt.at.x;
    atY = cam->viewMtx.lookAt.at.y;
    atZ = cam->viewMtx.lookAt.at.z;

    eyeDiffX = origEyeX - eyeX, eyeDiffY = origEyeY - eyeY, eyeDiffZ = origEyeZ - eyeZ;
    atDiffX = origAtX - atX, atDiffY = origAtY - atY, atDiffZ = origAtZ - atZ;

    for (i = 0; i < 11; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            func_8034A5EC_829D5C();
        }
        cam->viewMtx.lookAt.eye.x = ((i * eyeDiffX) / 10.0f) + eyeX;
        cam->viewMtx.lookAt.eye.y = ((i * eyeDiffY) / 10.0f) + eyeY;
        cam->viewMtx.lookAt.eye.z = ((i * eyeDiffZ) / 10.0f) + eyeZ;
        cam->viewMtx.lookAt.at.x = ((i * atDiffX) / 10.0f) + atX;
        cam->viewMtx.lookAt.at.y = ((i * atDiffY) / 10.0f) + atY;
        cam->viewMtx.lookAt.at.z = ((i * atDiffZ) / 10.0f) + atZ;
        ohWait(1);
    }
    func_8034A5EC_829D5C();
    ohWait(1);
}

void func_8034AABC_82A22C(void) {
    GObj* playerObj;

    playerObj = PlayerModel_Init();
    D_8034B674_82ADE4 = playerObj;
    if (playerObj != NULL) {
        omCreateProcess(playerObj, func_8034A7C4_829F34, 0, 1);
        func_8034A520_829C90(playerObj);
    }
}
