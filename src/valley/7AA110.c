#include "valley.h"

typedef struct SomeS16s {
    s16 data[2];
} SomeS16s;

extern f32 D_80100730;
extern AnimCmd* D_8011C5A0;
extern AnimCmd** D_8011CFB0;
extern AnimCmd D_8011DA1C;
extern AnimationHeader D_802EC6C0_7C5C50;
extern AnimationHeader D_802EC6D4_7C5C64;
extern AnimationHeader D_802EC6E8_7C5C78;
extern AnimationHeader D_802EC6FC_7C5C8C;
extern s32 D_802EC710_7C5CA0;
extern s32 D_802EC714_7C5CA4;
extern InteractionHandler D_802EC718_7C5CA8[];
extern SomeS16s D_802EC738_7C5CC8;
extern PokemonInitData D_802EC750_7C5CE0;

extern u8 D_8034C8C8_825E58;

void func_802D0BA4_7AA134(GObj*);
void func_802D0F98_7AA528(GObj*);

POKEMON_FUNC(func_802D0B80_7AA110)
    Pokemon_SetState(obj, func_802D0BA4_7AA134);
}

POKEMON_FUNC(func_802D0BA4_7AA134)
    Pokemon_SetAnimation(obj, &D_802EC6C0_7C5C50);
    pokemon->transitionGraph = D_802EC718_7C5CA8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D0BFC_7AA18C)
    cmdSendCommand(gObjPlayer, 9, NULL);
    auPlaySound(SOUND_ID_38);
    Pokemon_SetAnimation(obj, &D_802EC6D4_7C5C64);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    auPlaySound(SOUND_ID_40);
    D_802EC710_7C5CA0 = auPlaySound(SOUND_ID_39);
    Pokemon_SetAnimation(obj, &D_802EC6E8_7C5C78);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802EC6FC_7C5C8C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D0F98_7AA528);
}

void func_802D0CD8_7AA268(DObj* obj, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_802EC714_7C5CA4 = 1;
        obj->timeLeft = FLOAT_NEG_MAX;
    }
}

POKEMON_FUNC(func_802D0D0C_7AA29C)
    f32 var_f20;
    s32 i;
    f32 tmp;

    tmp = 240.0f;

    var_f20 = 1.0f;
    for (i = 239; i != 0; i--) {
        var_f20 += -1.0f / tmp;
        auSetBGMVolume(BGM_PLAYER_MAIN, 32512.0f * var_f20);
        auSetBGMVolume(BGM_PLAYER_AUX, 32512.0f * var_f20);
        auSetSoundVolume(D_8034C8C8_825E58, 14336.0f * var_f20);
        ohWait(1);
    }

    auSetBGMVolume(0, 0);
    auSetBGMVolume(1, 0);
    auSetSoundVolume(D_8034C8C8_825E58, 0);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802D0F0C_7AA49C)
    s32 i;

    for (i = 0; i < 230; i++) {
        ohWait(1);
    }
    auPlaySound(SOUND_ID_41);
    if (D_802EC710_7C5CA0 != -1 && auPlayingSound[D_802EC710_7C5CA0] != -1) {
        auStopSound(D_802EC710_7C5CA0);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802D0F98_7AA528)
    GObj* playerObj;
    GObj* camObj;
    OMCamera* cam;
    s32 i;
    SomeS16s sp2C;

    sp2C = D_802EC738_7C5CC8;
    Pokemon_StartAuxProc(obj, func_802D0D0C_7AA29C);
    Pokemon_StartAuxProc(obj, func_802D0F0C_7AA49C);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Pokemon_RemovePokemons(&sp2C);
    ohWait(1);
    Camera_StartCutScene(obj, NULL, 0.0f);
    cam = getMainCamera();
    camObj = cam->obj;
    ohPauseObjectProcesses(camObj);
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, &D_8011DA1C, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    setSkyBoxAnimationSpeed(D_80100730);
    playerObj = PlayerModel_Init();
    if (playerObj == NULL) {
        cmdSendCommand(gObjPlayer, 7, NULL);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_8011C5A0, &D_8011CFB0, 0, 0.5f);
    D_802EC714_7C5CA4 = 0;
    playerObj->fnAnimCallback = func_802D0CD8_7AA268;

    for (i = 0; D_802EC714_7C5CA4 == 0 && i < 1200; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_FINISH, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802D1154_7AA6E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802EC750_7C5CE0);
}
