#include "volcano/volcano.h"

extern UnkEC64Arg3 D_800F1D10[];
extern Texture** D_800F07A0[];

extern AnimCmd* D_800F1DF0[];
extern AnimCmd* D_800F1ED0[];
extern AnimCmd* D_800F1FD0[];
extern AnimCmd* D_800F20D0[];

extern AnimCmd** D_800F1E40[];
extern AnimCmd** D_800F1F20[];
extern AnimCmd** D_800F2020[];
extern AnimCmd** D_800F2110[];

extern AnimCmd D_8011749C[];
extern f32 D_800FFFC8;

extern AnimCmd* D_80115E80[];
extern AnimCmd** D_80116A80[];

void func_802DF3D4_7305D4(GObj*);
void func_802DF3B0_7305B0(GObj*);
void func_802DF42C_73062C(GObj*);
void func_802DF880_730A80(GObj*);

AnimationHeader D_802E36B0_7348B0 = {
    1,
    100,
    D_800F1DF0,
    D_800F1E40,
    NULL
};

AnimationHeader D_802E36C4_7348C4 = {
    1,
    100,
    D_800F1ED0,
    D_800F1F20,
    NULL
};

AnimationHeader D_802E36D8_7348D8 = {
    1,
    100,
    D_800F1FD0,
    D_800F2020,
    NULL
};

AnimationHeader D_802E36EC_7348EC = {
    1,
    100,
    D_800F20D0,
    D_800F2110,
    NULL
};

s32 D_802E3700_734900 = -1;
s32 D_802E3704_734904 = 0;

InteractionHandler D_802E3708_734908[] = {
    { POKEMON_CMD_16, func_802DF42C_73062C, 2000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

u16 D_802E3728_734928[] = { PokemonID_1001, 0 };

PokemonAnimationSetup D_802E372C_73492C = {
    &D_802E36B0_7348B0,
    func_802DF3B0_7305B0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E3740_734940 = {
    D_800F1D10,
    D_800F07A0,
    renderModelTypeDFogged,
    &D_802E372C_73492C,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0.01,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

extern u8 D_8034E0F8_79F2F8;
extern u8 D_8034E0F9_79F2F9;

POKEMON_FUNC(func_802DF3B0_7305B0)
    Pokemon_SetState(obj, func_802DF3D4_7305D4);
}

POKEMON_FUNC(func_802DF3D4_7305D4)
    Pokemon_SetAnimation(obj, &D_802E36B0_7348B0);
    pokemon->transitionGraph = D_802E3708_734908;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DF42C_73062C)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_9, NULL);
    auPlaySound(SOUND_ID_38);

    Pokemon_SetAnimation(obj, &D_802E36C4_7348C4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    auPlaySound(SOUND_ID_40);
    D_802E3700_734900 = auPlaySound(SOUND_ID_39);

    Pokemon_SetAnimation(obj, &D_802E36D8_7348D8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E36EC_7348EC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DF880_730A80);
}

void func_802DF508_730708(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_802E3704_734904 = 1;
    }
}

POKEMON_FUNC(func_802DF534_730734)
    f32 var_f20 = 1.0f;
    f32 N = 240;
    s32 i;

    for (i = 239; i > 0; i--) {
        var_f20 += -1.0f / N;
        auSetBGMVolume(BGM_PLAYER_MAIN, 32512.0f * var_f20);
        auSetBGMVolume(BGM_PLAYER_AUX, 32512.0f * var_f20);
        auSetSoundVolume(D_8034E0F9_79F2F9, 22528.0f * var_f20);
        auSetSoundVolume(D_8034E0F8_79F2F8, 26624.0f * var_f20);
        ohWait(1);
    }

    auSetBGMVolume(BGM_PLAYER_MAIN, 0);
    auSetBGMVolume(BGM_PLAYER_AUX, 0);
    auSetSoundVolume(D_8034E0F9_79F2F9, 0);
    auSetSoundVolume(D_8034E0F8_79F2F8, 0);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802DF7F4_7309F4)
    s32 i;

    for (i = 0; i < 220; i++) {
        ohWait(1);
    }

    auPlaySound(SOUND_ID_41);
    if (D_802E3700_734900 != -1 && auPlayingSound[D_802E3700_734900] != -1) {
        auStopSound(D_802E3700_734900);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802DF880_730A80)
    OMCamera* camera;
    GObj* camObj;
    GObj* player;
    s32 i;
    u16 sp2C[2] = D_802E3728_734928;

    Pokemon_RemovePokemons(sp2C);
    ohWait(1);
    Pokemon_StartAuxProc(obj, func_802DF534_730734);
    Pokemon_StartAuxProc(obj, func_802DF7F4_7309F4);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Camera_StartCutScene(obj, 0, 0);

    camera = getMainCamera();
    camObj = camera->obj;

    ohPauseObjectProcesses(camObj);
    camera->animSpeed = 0.5f;
    animSetCameraAnimation(camera, D_8011749C, 0);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    func_800E1A78_5F228(D_800FFFC8);

    player = PlayerModel_Init();
    if (player == NULL) {
        cmdSendCommand(gObjPlayer, PLAYER_CMD_7, NULL);
        omEndProcess(NULL);
    }

    PlayerModel_SetAnimation(D_80115E80, D_80116A80, 0.0f, 0.5f);
    D_802E3704_734904 = false;
    player->fnAnimCallback = func_802DF508_730708;

    for (i = 0; !D_802E3704_734904 && i < 1200; i++) {
        ohWait(1);
    }
    auStopAllSounds();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_FINISH, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DFA38_730C38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E3740_734940);
}
