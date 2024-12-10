#include "../tunnel.h"

typedef struct Unks16 {
    /* 0x00 */ s16 unk_00[2];
} Unks16;

extern AnimCmd D_8013D8D0[];
extern AnimCmd* D_8013C230[];
extern AnimCmd** D_8013CEB0[];

extern AnimationHeader D_802F0110_5ED1E0;
extern AnimationHeader D_802F0124_5ED1F4;
extern AnimationHeader D_802F0138_5ED208;
extern AnimationHeader D_802F014C_5ED21C;
extern s32 D_802F0160_5ED230;
extern bool D_802F0164_5ED234;
extern InteractionHandler D_802F0168_5ED238[];
extern Unks16 D_802F0188_5ED258;
extern PokemonInitData D_802F01A0_5ED270;

void func_802ECAE4_5E9BB4(GObj*);
void func_802ECE10_5E9EE0(GObj*);

POKEMON_FUNC(func_802ECAC0_5E9B90)
    Pokemon_SetState(obj, func_802ECAE4_5E9BB4);
}

POKEMON_FUNC(func_802ECAE4_5E9BB4)
    Pokemon_SetAnimation(obj, &D_802F0110_5ED1E0);
    pokemon->transitionGraph = D_802F0168_5ED238;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802ECB3C_5E9C0C)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_9, NULL);
    auPlaySound(SOUND_ID_38);

    Pokemon_SetAnimation(obj, &D_802F0124_5ED1F4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    auPlaySound(SOUND_ID_40);
    D_802F0160_5ED230 = auPlaySound(SOUND_ID_39);

    Pokemon_SetAnimation(obj, &D_802F0138_5ED208);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802F014C_5ED21C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802ECE10_5E9EE0);
}

void func_802ECC18_5E9CE8(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_802F0164_5ED234 = true;
    }
}

POKEMON_FUNC(func_802ECC44_5E9D14)
    f32 fader;
    s32 i;
    u32 vol;

    f32 steps = 240;
    fader = 1.0f;

    for (i = 239; i > 0; i--) {
        fader += -1.0f / steps;
        vol = 32512.0f * fader;
        auSetBGMVolume(BGM_PLAYER_MAIN, vol);
        auSetBGMVolume(BGM_PLAYER_AUX, vol);
        ohWait(1);
    }

    auSetBGMVolume(BGM_PLAYER_MAIN, 0);
    auSetBGMVolume(BGM_PLAYER_AUX, 0);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802ECD84_5E9E54)
    s32 i;

    for (i = 0; i < 220; i++) {
        ohWait(1);
    }

    auPlaySound(SOUND_ID_41);
    if (D_802F0160_5ED230 != -1 && auPlayingSound[D_802F0160_5ED230] != -1) {
        auStopSound(D_802F0160_5ED230);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802ECE10_5E9EE0)
    OMCamera* camera;
    GObj* camObj;
    GObj* player;
    s32 i;
    Unks16 sp2C = D_802F0188_5ED258;

    Pokemon_RemovePokemons(&sp2C);
    ohWait(1);
    Pokemon_StartAuxProc(obj, func_802ECC44_5E9D14);
    Pokemon_StartAuxProc(obj, func_802ECD84_5E9E54);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Camera_StartCutScene(obj, 0, 0);

    camera = getMainCamera();
    camObj = camera->obj;

    ohPauseObjectProcesses(camObj);
    camera->animSpeed = 0.5f;
    animSetCameraAnimation(camera, D_8013D8D0, 0);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    setSkyBoxAnimationSpeed(tunnel_WorldSetup.unk_10);

    player = PlayerModel_Init();
    if (player == NULL) {
        cmdSendCommand(gObjPlayer, PLAYER_CMD_7, NULL);
        omEndProcess(NULL);
    }

    PlayerModel_SetAnimation(D_8013C230, D_8013CEB0, 0.0f, 0.5f);
    D_802F0164_5ED234 = false;
    player->fnAnimCallback = func_802ECC18_5E9CE8;

    for (i = 0; !D_802F0164_5ED234 && i < 1200; i++) {
        ohWait(1);
    }
    auStopAllSounds();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_FINISH, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802ECFC8_5EA098(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802F01A0_5ED270);
}
