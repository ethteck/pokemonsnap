#include "volcano/volcano.h"

extern UnkEC64Arg3 gate_model[];
extern Texture** gate_materials[];

extern AnimCmd* gate_modelanim_closed[];
extern AnimCmd* gate_modelanim_raise_bar[];
extern AnimCmd* gate_modelanim_opening[];
extern AnimCmd* gate_modelanim_opened[];

extern AnimCmd** gate_matanim_closed[];
extern AnimCmd** gate_matanim_raise_bar[];
extern AnimCmd** gate_matanim_opening[];
extern AnimCmd** gate_matanim_opened[];

extern AnimCmd volcano_camera_anim_end[];

extern AnimCmd* D_80115E80[];
extern AnimCmd** D_80116A80[];

void volcano_gate_Idle(GObj*);
void volcano_gate_InitialState(GObj*);
void volcano_gate_PlayerApproaching(GObj*);
void volcano_gate_Cutscene(GObj*);

AnimationHeader volcano_gate_animation_closed = {
    1,
    100,
    gate_modelanim_closed,
    gate_matanim_closed,
    NULL
};

AnimationHeader volcano_gate_animation_raise_bar = {
    1,
    100,
    gate_modelanim_raise_bar,
    gate_matanim_raise_bar,
    NULL
};

AnimationHeader volcano_gate_animation_opening = {
    1,
    100,
    gate_modelanim_opening,
    gate_matanim_opening,
    NULL
};

AnimationHeader volcano_gate_animation_opened = {
    1,
    100,
    gate_modelanim_opened,
    gate_matanim_opened,
    NULL
};

s32 volcano_gate_SoundHandle = -1;
s32 volcano_gate_IsPlayerNearGate = false;

InteractionHandler volcano_gate_tg_Normal[] = {
    { POKEMON_CMD_16, volcano_gate_PlayerApproaching, 2000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

u16 volcano_gate_remainingPokemons[] = { PokemonID_GATE, 0 };

PokemonAnimationSetup volcano_gate_animSetup = {
    &volcano_gate_animation_closed,
    volcano_gate_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData volcano_gate_initData = {
    gate_model,
    gate_materials,
    renderModelTypeDFogged,
    &volcano_gate_animSetup,
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

POKEMON_FUNC(volcano_gate_InitialState)
    Pokemon_SetState(obj, volcano_gate_Idle);
}

POKEMON_FUNC(volcano_gate_Idle)
    Pokemon_SetAnimation(obj, &volcano_gate_animation_closed);
    pokemon->transitionGraph = volcano_gate_tg_Normal;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(volcano_gate_PlayerApproaching)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_9, NULL);
    auPlaySound(SOUND_ID_38);

    Pokemon_SetAnimation(obj, &volcano_gate_animation_raise_bar);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    auPlaySound(SOUND_ID_40);
    volcano_gate_SoundHandle = auPlaySound(SOUND_ID_39);

    Pokemon_SetAnimation(obj, &volcano_gate_animation_opening);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &volcano_gate_animation_opened);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, volcano_gate_Cutscene);
}

void volcano_gate_PlayerAnimCallback(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        volcano_gate_IsPlayerNearGate = true;
    }
}

POKEMON_FUNC(volcano_gate_LowerVolume)
    f32 volume = 1.0f;
    f32 N = 240;
    s32 i;

    for (i = 239; i > 0; i--) {
        volume += -1.0f / N;
        auSetBGMVolume(BGM_PLAYER_MAIN, 32512.0f * volume);
        auSetBGMVolume(BGM_PLAYER_AUX, 32512.0f * volume);
        auSetSoundVolume(D_8034E0F9_79F2F9, 22528.0f * volume);
        auSetSoundVolume(D_8034E0F8_79F2F8, 26624.0f * volume);
        ohWait(1);
    }

    auSetBGMVolume(BGM_PLAYER_MAIN, 0);
    auSetBGMVolume(BGM_PLAYER_AUX, 0);
    auSetSoundVolume(D_8034E0F9_79F2F9, 0);
    auSetSoundVolume(D_8034E0F8_79F2F8, 0);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(volcano_gate_StopSounds)
    s32 i;

    for (i = 0; i < 220; i++) {
        ohWait(1);
    }

    auPlaySound(SOUND_ID_41);
    if (volcano_gate_SoundHandle != -1 && auPlayingSound[volcano_gate_SoundHandle] != -1) {
        auStopSound(volcano_gate_SoundHandle);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(volcano_gate_Cutscene)
    OMCamera* camera;
    GObj* camObj;
    GObj* player;
    s32 i;
    u16 sp2C[2] = volcano_gate_remainingPokemons;

    Pokemon_RemovePokemons(sp2C);
    ohWait(1);
    Pokemon_StartAuxProc(obj, volcano_gate_LowerVolume);
    Pokemon_StartAuxProc(obj, volcano_gate_StopSounds);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Camera_StartCutScene(obj, 0, 0);

    camera = getMainCamera();
    camObj = camera->obj;

    ohPauseObjectProcesses(camObj);
    camera->animSpeed = 0.5f;
    animSetCameraAnimation(camera, volcano_camera_anim_end, 0);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    setSkyBoxAnimationSpeed(volcano_WorldSetup.unk_10);

    player = PlayerModel_Init();
    if (player == NULL) {
        cmdSendCommand(gObjPlayer, PLAYER_CMD_7, NULL);
        omEndProcess(NULL);
    }

    PlayerModel_SetAnimation(D_80115E80, D_80116A80, 0.0f, 0.5f);
    volcano_gate_IsPlayerNearGate = false;
    player->fnAnimCallback = volcano_gate_PlayerAnimCallback;

    for (i = 0; !volcano_gate_IsPlayerNearGate && i < 1200; i++) {
        ohWait(1);
    }
    auStopAllSounds();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_FINISH, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* volcano_gate_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &volcano_gate_initData);
}
