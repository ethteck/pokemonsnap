#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

typedef struct Unk6 {
    u16 data[3];
} Unk6;

void func_802E0094_6C7E74(GObj*);

extern AnimCmd* D_80148F30;
extern AnimCmd** D_80149BE0;
extern AnimCmd D_8014A600[];

extern AnimationHeader D_802E4420_6CC200;
extern AnimationHeader D_802E4434_6CC214;
extern AnimationHeader D_802E4448_6CC228;
extern AnimationHeader D_802E445C_6CC23C;
extern s32 D_802E4470_6CC250;
extern u32 D_802E4474_6CC254;
extern InteractionHandler D_802E4478_6CC258[];
extern Unk6 D_802E4498_6CC278;
extern PokemonInitData D_802E44B4_6CC294;

void func_802E03C0_6C81A0(GObj*);

void func_802E0070_6C7E50(GObj* obj) {
    Pokemon_SetState(obj, func_802E0094_6C7E74);
}

void func_802E0094_6C7E74(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4420_6CC200);
    pokemon->transitionGraph = D_802E4478_6CC258;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802E00EC_6C7ECC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommand(gObjPlayer, 9, NULL);
    auPlaySound(0x26);
    Pokemon_SetAnimation(obj, &D_802E4434_6CC214);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    auPlaySound(0x28);
    D_802E4470_6CC250 = auPlaySound(0x27);
    Pokemon_SetAnimation(obj, &D_802E4448_6CC228);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E445C_6CC23C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802E03C0_6C81A0);
}

void func_802E01C8_6C7FA8(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_802E4474_6CC254 = 1;
    }
}

void func_802E01F4_6C7FD4(GObj* obj) {
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

void func_802E0334_6C8114(GObj* obj) {
    s32 i;

    for (i = 0; i < 200; i++) {
        ohWait(1);
    }
    auPlaySound(0x29);
    if (D_802E4470_6CC250 != -1 && auPlayingSound[D_802E4470_6CC250] != -1) {
        auStopSound(D_802E4470_6CC250);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802E03C0_6C81A0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    GObj* camObj;
    GObj* playerModelObj;
    OMCamera* cam;
    s32 i;
    Unk6 sp28;

    sp28 = D_802E4498_6CC278;
    Pokemon_StartAuxProc(obj, func_802E01F4_6C7FD4);
    Pokemon_StartAuxProc(obj, func_802E0334_6C8114);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Pokemon_RemovePokemons(sp28.data);
    ohWait(1);
    Camera_StartCutScene(obj, NULL, 0.0f);
    cam = getMainCamera();
    camObj = cam->obj;
    ohPauseObjectProcesses(camObj);
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, D_8014A600, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    func_800E1A78_5F228(D_8012ACA0);
    playerModelObj = PlayerModel_Init();
    if (playerModelObj == NULL) {
        cmdSendCommand(gObjPlayer, 7, NULL);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_80148F30, &D_80149BE0, 0.0f, 0.5f);
    D_802E4474_6CC254 = 0;
    playerModelObj->fnAnimCallback = func_802E01C8_6C7FA8;
    for (i = 0; D_802E4474_6CC254 == 0 && i < 1200; i++) {
        ohWait(1);
    }
    auStopAllSounds();
    cmdSendCommand(gObjPlayer, 6, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802E0584_6C8364(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E44B4_6CC294);
}
