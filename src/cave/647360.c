#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/effect.h"
#include "cave.h"

extern f32 D_8012A0F8;
extern AnimCmd* D_80145E30;
extern AnimCmd** D_80146AB0;
extern AnimCmd D_801474EC;
extern AnimCmd* D_80147540;
extern AnimCmd** D_80148420;
extern AnimCmd D_80148EA0;

extern AnimationHeader D_802C7D1C_64A1CC;
extern AnimationHeader D_802C7D30_64A1E0;
extern AnimationHeader D_802C7D44_64A1F4;
extern AnimationHeader D_802C7D58_64A208;
extern AnimationHeader D_802C7D6C_64A21C;
extern AnimationHeader D_802C7D80_64A230;
extern InteractionHandler D_802C7D94_64A244[];
extern InteractionHandler D_802C7DDC_64A28C[];
extern InteractionHandler D_802C7E1C_64A2CC[];
extern InteractionHandler D_802C7E4C_64A2FC[];
extern InteractionHandler D_802C7E7C_64A32C[];
extern PokemonInitData D_802C7EC0_64A370;
extern AnimationHeader D_802C7F08_64A3B8;
extern PokemonInitData D_802C7F30_64A3E0;
extern AnimationHeader D_802C7F70_64A420;
extern AnimationHeader D_802C7F84_64A434;
extern AnimationHeader D_802C7F98_64A448;
extern AnimationHeader D_802C7FAC_64A45C;
extern s32 D_802C7FC0_64A470;
extern s32 D_802C7FC4_64A474;
extern InteractionHandler D_802C7FC8_64A478[];
extern UnkBlueShark D_802C7FE8_64A498;
extern PokemonInitData D_802C8000_64A4B0;
extern s32 D_802C8040_64A4F0;
extern GObj* D_802C8044_64A4F4;

extern u8 D_8033F698_6C1B48;
extern u8 D_8033F699_6C1B49;
extern u8 D_8033F69A_6C1B4A;

void func_802C4F5C_64740C(GObj*);
void func_802C502C_6474DC(GObj*);
void func_802C5468_647918(GObj*);
void func_802C54DC_64798C(GObj*);
void func_802C5644_647AF4(GObj*);
void func_802C5970_647E20(GObj*);
void func_802C5230_6476E0(GObj*);

void func_802C4EB0_647360(PokemonTransform* transform, f32 arg1) {
    GroundResult ground;

    getGroundAt(transform->pos.v.x, transform->pos.v.z, &ground);
    transform->pos.v.y = ground.height + arg1;
}

void func_802C4EF4_6473A4(GObj* obj) {
    Pokemon* pokemon;
    DObj* dobj;
    PokemonTransform* transform;
    Mtx4Float* temp_a3;

    // clang-format off
    do { \
        dobj = obj->data.dobj; \
        transform = GET_TRANSFORM(dobj); \
        temp_a3 = &GET_TRANSFORM(dobj)->rot;\
        pokemon = GET_POKEMON(obj);

        pokemon->miscVars[0].field0 = temp_a3->v.y;
        pokemon->miscVars[1].field0 = -53.25f;
        pokemon->miscVars[2].field0 = 0.0f;
        func_802C4EB0_647360(transform, pokemon->miscVars[1].field0);
    } while (0); // required to match
    // clang-format on

    Pokemon_SetState(obj, func_802C4F5C_64740C);
}

void func_802C4F5C_64740C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7D1C_64A1CC);
    pokemon->transitionGraph = D_802C7D94_64A244;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C4F5C_64740C);
}

void func_802C4FB8_647468(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802C502C_6474DC);
    Pokemon_SetAnimation(obj, &D_802C7D30_64A1E0);
    pokemon->transitionGraph = D_802C7D94_64A244;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C4F5C_64740C);
}

void func_802C502C_6474DC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* dobj = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(dobj);
    Mtx4Float* rot = &GET_TRANSFORM(dobj)->rot;

    while (pokemon->miscVars[1].field0 != -53.25 || pokemon->miscVars[2].field0 != 0.0f) {
        if (pokemon->miscVars[1].field0 > -53.25) {
            pokemon->miscVars[1].field0 -= 1.775;
        } else {
            pokemon->miscVars[1].field0 = -53.25f;
        }
        func_802C4EB0_647360(transform, pokemon->miscVars[1].field0);

        if (pokemon->miscVars[2].field0 > 0.0f) {
            pokemon->miscVars[2].field0 -= PI / 15;
        } else {
            pokemon->miscVars[2].field0 = 0.0f;
        }

        rot->v.y = pokemon->miscVars[0].field0 + pokemon->miscVars[2].field0;
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802C5188_647638(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802C7D44_64A1F4);
    Pokemon_StartPathProc(obj, func_802C5230_6476E0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802C7DDC_64A28C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetState(obj, func_802C4FB8_647468);
}

void func_802C5230_6476E0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* dobj = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(dobj);
    Mtx4Float* rot = &GET_TRANSFORM(dobj)->rot;

    while (pokemon->miscVars[2].field0 != TAU || pokemon->miscVars[1].field0 != 0.0f) {
        if (pokemon->miscVars[1].field0 > 0.0f) {
            pokemon->miscVars[1].field0 += 1.775;
        } else {
            pokemon->miscVars[1].field0 = 0.0f;
        }
        func_802C4EB0_647360(transform, pokemon->miscVars[1].field0);

        if (pokemon->miscVars[2].field0 < TAU) {
            pokemon->miscVars[2].field0 += PI / 15;
        } else {
            pokemon->miscVars[2].field0 = TAU;
        }

        rot->v.y = pokemon->miscVars[0].field0 + pokemon->miscVars[2].field0;
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C5380_647830(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7D58_64A208);
    Pokemon_StartPathProc(obj, func_802C54DC_64798C);
    pokemon->transitionGraph = D_802C7E1C_64A2CC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C4FB8_647468);
}

void func_802C53F4_6478A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7D6C_64A21C);
    Pokemon_StartPathProc(obj, func_802C54DC_64798C);
    pokemon->transitionGraph = D_802C7E4C_64A2FC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C4FB8_647468);
}

void func_802C5468_647918(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7D80_64A230);
    Pokemon_StartPathProc(obj, func_802C54DC_64798C);
    pokemon->transitionGraph = D_802C7E7C_64A32C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C4FB8_647468);
}

void func_802C54DC_64798C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

GObj* func_802C5548_6479F8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C7EC0_64A370);
}

void func_802C5580_647A30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7F08_64A3B8);
    pokemon->transitionGraph = 0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C5580_647A30);
}

void func_802C55D4_647A84(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802C7F30_64A3E0)->data.dobj->firstChild->flags |= 1;
}

void func_802C5620_647AD0(GObj* obj) {
    Pokemon_SetState(obj, func_802C5644_647AF4);
}

void func_802C5644_647AF4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7F70_64A420);
    pokemon->transitionGraph = D_802C7FC8_64A478;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802C569C_647B4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommand(gObjPlayer, 9, NULL);
    auPlaySound(0x26);
    Pokemon_SetAnimation(obj, &D_802C7F84_64A434);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    auPlaySound(0x28);
    D_802C7FC0_64A470 = auPlaySound(0x27);
    Pokemon_SetAnimation(obj, &D_802C7F98_64A448);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C7FAC_64A45C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C5970_647E20);
}

void func_802C5778_647C28(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_802C7FC4_64A474 = 1;
    }
}

void func_802C57A4_647C54(GObj* obj) {
    f32 fader;
    s32 i;
    u32 vol;

    f32 steps = 240;
    fader = 1.0f;

    for (i = 239; i > 0; i--) {
        fader += -1.0f / steps;
        vol = 32512.0f * fader;
        auSetBGMVolume(0, vol);
        auSetBGMVolume(1, vol);
        ohWait(1);
    }

    auSetBGMVolume(0, 0);
    auSetBGMVolume(1, 0);
    Pokemon_StopAuxProc(obj);
}

void func_802C58E4_647D94(GObj* obj) {
    s32 i;

    for (i = 0; i < 220; i++) {
        ohWait(1);
    }

    auPlaySound(0x29);
    if (D_802C7FC0_64A470 != -1 && auPlayingSound[D_802C7FC0_64A470] != -1) {
        auStopSound(D_802C7FC0_64A470);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802C5970_647E20(GObj* obj) {
    UNUSED s32 pad[4];
    GObj* camObj;
    GObj* playerObj;
    OMCamera* cam;
    s32 i;
    UnkBlueShark sp2C;

    sp2C = D_802C7FE8_64A498;
    Pokemon_RemovePokemons(&sp2C);
    ohWait(1);
    Pokemon_StartAuxProc(obj, func_802C57A4_647C54);
    Pokemon_StartAuxProc(obj, func_802C58E4_647D94);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Camera_StartCutScene(obj, NULL, 0.0f);
    cam = getMainCamera();
    camObj = cam->obj;
    ohPauseObjectProcesses(camObj);
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, &D_801474EC, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    setSkyBoxAnimationSpeed(D_8012A0F8);
    playerObj = PlayerModel_Init();
    if (playerObj == NULL) {
        cmdSendCommand(gObjPlayer, PLAYER_CMD_7, NULL);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_80145E30, &D_80146AB0, 0.0f, 0.5f);
    D_802C7FC4_64A474 = 0;
    playerObj->fnAnimCallback = func_802C5778_647C28;

    for (i = 0; D_802C7FC4_64A474 == 0 && i < 1200; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(gObjPlayer, 6, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802C5B28_647FD8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802C8000_64A4B0);
}

void func_802C5B60_648010(GObj* arg0) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(arg0);
    func_803570B0_4F74C0();
}

void func_802C5B90_648040(void) {
    func_803572B0_4F76C0();
}

void func_802C5BB0_648060(DObj* dobj, s32 arg1, f32 arg2) {
    Effect* fx;
    s32 temp_a1;

    if (arg1 == -2 || arg1 == -1) {
        D_802C8040_64A4F0 = 1;
        return;
    }

    temp_a1 = (s32) arg2 - 1;
    if (temp_a1 >= 0) {
        fx = fx_createEffect(arg1, temp_a1);
        if (fx != NULL) {
            fx->dobj = dobj;
        }
    }
}

void func_802C5C24_6480D4(void) {
    if (auPlayingSound[D_8033F698_6C1B48] == 0x27) {
        auStopSound(D_8033F698_6C1B48);
    }
    if (auPlayingSound[D_8033F699_6C1B49] == 0x15) {
        auStopSound(D_8033F699_6C1B49);
    }
    if (auPlayingSound[D_8033F69A_6C1B4A] == 0xF) {
        auStopSound(D_8033F69A_6C1B4A);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_802C5B90_648040();
    omDeleteGObj(NULL);
}

void func_802C5CEC_64819C(GObj* obj) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }

    D_8033F699_6C1B49 = auPlaySoundWithParams(0x15, 0x6000, 0x40, 1.0f, 20);
    D_8033F698_6C1B48 = auPlaySoundWithParams(0x27, 0x6800, 0x40, 1.0f, 20);
    omEndProcess(NULL);
}

void func_802C5D80_648230(GObj* obj) {
    s32 i;

    for (i = 0; i < 160; i++) {
        ohWait(1);
    }

    D_8033F69A_6C1B4A = auPlaySoundWithParams(0xF, 0x7800, 0x40, 1.0f, 30);
    auStopSound(D_8033F698_6C1B48);
    omEndProcess(NULL);
}

void func_802C5DFC_6482AC(GObj* obj) {
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
    animSetCameraAnimation(cam, &D_80148EA0, 0.0f);
    proc = omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(&D_80147540, &D_80148420, 0.0f, 0.5f);
    D_802C8040_64A4F0 = 0;
    obj->fnAnimCallback = func_802C5BB0_648060;
    omCreateProcess(obj, func_802C5CEC_64819C, 0, 1);
    omCreateProcess(obj, func_802C5D80_648230, 0, 1);

    for (i = 0; D_802C8040_64A4F0 == 0 && i < 290; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            omEndProcess(proc);
            func_802C5C24_6480D4();
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
            func_802C5C24_6480D4();
        }
        cam->viewMtx.lookAt.eye.x = ((i * eyeDiffX) / 10.0f) + eyeX;
        cam->viewMtx.lookAt.eye.y = ((i * eyeDiffY) / 10.0f) + eyeY;
        cam->viewMtx.lookAt.eye.z = ((i * eyeDiffZ) / 10.0f) + eyeZ;
        cam->viewMtx.lookAt.at.x = ((i * atDiffX) / 10.0f) + atX;
        cam->viewMtx.lookAt.at.y = ((i * atDiffY) / 10.0f) + atY;
        cam->viewMtx.lookAt.at.z = ((i * atDiffZ) / 10.0f) + atZ;
        ohWait(1);
    }
    func_802C5C24_6480D4();
    ohWait(1);
}

void func_802C60F4_6485A4(void) {
    GObj* playerObj;

    playerObj = PlayerModel_Init();
    D_802C8044_64A4F4 = playerObj;
    if (playerObj != NULL) {
        omCreateProcess(playerObj, func_802C5DFC_6482AC, 0, 1);
        func_802C5B60_648010(playerObj);
    }
}
