#include "common.h"
#include "beach.h"

void func_beach_802CAF90(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBD4);
    pokemon->transitionGraph = D_beach_802CDCD0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CAFEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDBC0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CB054(GObj* obj) {
    Pokemon_StartPathProc(obj, func_beach_802CB128);
    Pokemon_SetState(obj, func_beach_802CB08C);
}

void func_beach_802CB08C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDB84);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_ANIMATION_ENDED) {
        Pokemon_SetState(obj, func_beach_802CB08C);
    }
    pokemon->transitionGraph = D_beach_802CDD40;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CB128(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB194.s")

void func_beach_802CB2D8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    pokemon->flags |= 0x800;
    Pokemon_StartAuxProc(obj, func_beach_802CB814);
    Pokemon_SetAnimation(obj, &D_beach_802CDB5C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDD80;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_beach_802CDE30);
}

void func_beach_802CB36C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDB5C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDD80;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_beach_802CDE30);
}

void func_beach_802CB3DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDB70);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDD80;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_beach_802CDE30);
}

void func_beach_802CB44C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBC0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDE48;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB3DC);
}

void func_beach_802CB4BC() {
}

void func_beach_802CB4C4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CB520(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDBD4);
    Pokemon_StartPathProc(obj, func_beach_802CB6B4);
    pokemon->transitionGraph = D_beach_802CDE78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB594);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB594.s")

void func_beach_802CB6B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    ohWait(60);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CB710(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CB784(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDB84);
    Pokemon_StartPathProc(obj, func_beach_802CB128);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_ANIMATION_ENDED) {
        Pokemon_SetState(obj, func_beach_802CB784);
    }
    Pokemon_SetState(obj, func_beach_802CB3DC);
}

void func_beach_802CB814(GObj* obj) {
    while (func_beach_802CB194(obj)) {
        ohWait(1);
    }

    cmdSendCommand(obj, 0x23, obj);
    Pokemon_StopAuxProc(obj);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB874.s")

void func_beach_802CB9E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBC0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB874);
}

void func_beach_802CBA48(GObj* obj) {
    f32 temp_f0;
    f32 temp_f20;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model;
    Vec3f sp34;

    model = obj->data.dobj;
    ohWait(0x3C);
    func_8001FCE8(&sp34, pokemon->path, 0.99999f);
    temp_f0 = atan2f(sp34.x, sp34.z);
    temp_f20 = temp_f0 - ((s32) (temp_f0 / 6.2831855f) * 6.2831855f);
    while (Pokemon_Turn(model, temp_f20, 0.13962634f) == 0) {
        ohWait(1);
    }
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CBB34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CBB90(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBD4);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CBB90);
}

void func_beach_802CBC4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBC0);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CBB90);
}

void func_beach_802CBCA8(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CE038);
}

void func_beach_802CBCE0(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802CBD04);
}

void func_beach_802CBD04(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_37, obj);
    ohWait(1);
    func_803667C0_506BD0(obj, 1, 0x34);
    Pokemon_ForceAnimation(obj, &D_beach_802CE070);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_38, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CBDA0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_beach_802CE0A8);
}

void func_beach_802CBDD8(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, 0x3EEU, &D_beach_802CE0DC);
    GET_POKEMON(var)->behavior = 0;
}
