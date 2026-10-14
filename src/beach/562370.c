#include "common.h"
#include "beach.h"

extern u8 D_800F1D10_6F4C0[];
extern u8 D_800FAE40_78260[];
extern u8 D_800FBF50_79370[];
extern u8 D_800FDC70_7B090[];
extern u8 D_80136AC0_C2F50[];
extern u8 D_beach_802CD920[];
void func_beach_802CA300(GObj*);
void func_beach_802CA450(GObj*);
void func_beach_802CA4CC(GObj*);
extern u8 gate_matanim_closed[];
extern u8 gate_matanim_opened[];
extern u8 gate_matanim_opening[];
extern u8 gate_matanim_raise_bar[];
extern u8 gate_materials[];
extern u8 gate_modelanim_closed[];
extern u8 gate_modelanim_opened[];
extern u8 gate_modelanim_opening[];
extern u8 gate_modelanim_raise_bar[];
extern PokemonAnimationSetup D_beach_802CD934;
extern PokemonAnimationSetup D_beach_802CD9FC;
extern u32 D_beach_802CDA50;
extern u32 D_beach_802CDA54[];

// .data
u32 D_beach_802CD930 = 0x00000000;
PokemonAnimationSetup D_beach_802CD934 = { (AnimationHeader*) &D_beach_802CD920, (GObjFunc) func_beach_802CA300, 0, "", NULL, NULL };
PokemonInitData D_beach_802CD948 = { (UnkEC64Arg3*) &D_80136AC0_C2F50, NULL, (GObjFunc) renderPokemonModelTypeDFogged, (PokemonAnimationSetup*) &D_beach_802CD934, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 64, 0, 0, 0, "" };
u32 D_beach_802CD97C = 0x00000000;
AnimationHeader D_beach_802CD980 = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_closed, (AnimCmd***) &gate_matanim_closed, NULL };
AnimationHeader D_beach_802CD994 = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_raise_bar, (AnimCmd***) &gate_matanim_raise_bar, NULL };
AnimationHeader D_beach_802CD9A8 = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_opening, (AnimCmd***) &gate_matanim_opening, NULL };
AnimationHeader D_beach_802CD9BC = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_opened, (AnimCmd***) &gate_matanim_opened, NULL };
s32 D_beach_802CD9D0 = -1;
s32 D_beach_802CD9D4 = 0;

InteractionHandler D_beach_802CD9D8[2] = {
    { 16, (GObjFunc) func_beach_802CA4CC, 2000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

UnkBlueShark D_beach_802CD9F8 = { 0x3E9, 0 };
PokemonAnimationSetup D_beach_802CD9FC = { (AnimationHeader*) &D_beach_802CD980, (GObjFunc) func_beach_802CA450, 0, "", NULL, NULL };
PokemonInitData D_beach_802CDA10 = { (UnkEC64Arg3*) &D_800F1D10_6F4C0, (Texture***) &gate_materials, (GObjFunc) renderModelTypeDFogged, (PokemonAnimationSetup*) &D_beach_802CD9FC, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.01f, 0, 0, 0, 0, "" };

u32 D_beach_802CDA44[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_beach_802CDA50 = 0x000000D3;

u32 D_beach_802CDA54[] = {
    0x000000D2, 0x00000178, 0x00000072,
};

u32 D_beach_802CDA60[] = {
    0x000000D3, 0x00000178, 0x00000072,
};

u32 D_beach_802CDA6C[] = {
    0x00000000, 0x00000178, 0x00000072, 0x3F000000,
    0x42700000, (u32) &D_800FDC70_7B090, 0x00000000, (u32) &D_beach_802CDA50,
};

u32 D_beach_802CDA8C[] = {
    0x3F000000, 0x42820000, (u32) &D_800FAE40_78260, 0x00000000,
    (u32) &D_beach_802CDA54, 0x3F000000, 0x426C0000, (u32) &D_800FBF50_79370,
    0x00000000,
};

// .bss
u8 D_beach_80347650[0x8];
void* D_beach_80347658;
u32 D_beach_8034765C;
u8 D_beach_80347660[0x40];

void func_beach_802CA300(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 sp34;
    f32 sp30;
    s32 sp2C;
    f32 sp28;

    obj->flags |= GOBJ_FLAG_2;

    while (true) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 0) {
            break;
        }

        if (sp34 == 0 && sp30 >= 0.92f) {
            break;
        }

        ohWait(1);
    }

    pokemon->flags |= POKEMON_FLAG_4;

    while (true) {
        getLevelProgress(&sp2C, &sp28);
        if (sp2C > 0) {
            break;
        }

        if (sp2C == 0 && sp28 >= 0.99f) {
            break;
        }

        ohWait(1);
    }

    pokemon->flags &= ~POKEMON_FLAG_4;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA418(s32 gObjId, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjId, id, roomA, roomB, spawn, &D_beach_802CD948);
}

// TODO: potential file split. Pokemon_Spawn tends to be used at the end of files

void func_beach_802CA450(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802CA474);
}

void func_beach_802CA474(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD980);
    pokemon->transitionGraph = D_beach_802CD9D8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA4CC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommand(gObjPlayer, PLAYER_CMD_9, 0);
    auPlaySound(0x26);
    Pokemon_SetAnimation(obj, &D_beach_802CD994);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    auPlaySound(0x28);
    D_beach_802CD9D0 = auPlaySound(0x27);
    Pokemon_SetAnimation(obj, &D_beach_802CD9A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CD9BC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CA950);
}

void func_beach_802CA5A8(DObj* obj, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_beach_802CD9D4 = 1;
    }
}

void func_beach_802CA5D4() {
}

void func_beach_802CA5DC(GObj* obj) {
    f32 var_f20;
    s32 i;
    f32 steps;

    var_f20 = 1.0f;
    steps = 240.0;
    for (i = 239; i > 0; i--) {
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
    Pokemon_StopAuxProc(obj);
}

void func_beach_802CA8C4(GObj* obj) {
    s32 i;

    for (i = 0; i < 230; i++) {
        ohWait(1);
    }

    auPlaySound(0x29);
    if (D_beach_802CD9D0 != -1 && auPlayingSound[D_beach_802CD9D0] != -1) {
        auStopSound(D_beach_802CD9D0);
    }
    Pokemon_StopAuxProc(obj);
}

void func_beach_802CA950(GObj* obj) {
    s32 unused[4];
    GObj* camObj;
    OMCamera* cam;
    s32 i;
    GObj* playerObj;
    UnkBlueShark sp2C;

    sp2C = D_beach_802CD9F8;
    Pokemon_StartAuxProc(obj, func_beach_802CA5DC);
    Pokemon_StartAuxProc(obj, func_beach_802CA8C4);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Pokemon_RemovePokemons(&sp2C);
    ohWait(1);
    Camera_StartCutScene(obj, NULL, 0);
    cam = getMainCamera();
    camObj = cam->obj;
    ohPauseObjectProcesses(camObj);
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, D_8013C530_C89C0, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    setSkyBoxAnimationSpeed(D_8011B924_A7DB4);
    playerObj = PlayerModel_Init();
    if (playerObj == NULL) {
        cmdSendCommand(gObjPlayer, PLAYER_CMD_7, 0);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_8013B030_C74C0, &D_8013BAA0_C7F30, 0, 0.5f);
    D_beach_80347658 = playerObj;
    D_beach_802CD9D4 = 0;
    playerObj->fnAnimCallback = func_beach_802CA5A8;

    for (i = 0; D_beach_802CD9D4 == 0 && i != 1200; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_FINISH, 0);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CAB14(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_beach_802CDA10);
}
