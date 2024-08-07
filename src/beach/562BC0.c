#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAB50.s")

void func_beach_802CAC08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CAC48(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CDAEC);
}

// TODO: potential file split. Pokemon_SpawnOnGround tends to be used at the end of files

void func_beach_802CAC80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->transitionGraph = D_beach_802CDC60;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CACD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_beach_802CAD58);
    }

    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_beach_802CB2D8);
    }
    Pokemon_SetState(obj, func_beach_802CAC80);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CAD58(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802CAD7C);
}

void func_beach_802CAD7C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = D_beach_802CDC80;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CADCC(GObj* ob) {
    Pokemon* pokemon = GET_POKEMON(ob);

    pokemon->tangible = 1;
    ob->flags = 0;
    Pokemon_StartPathProc(ob, func_beach_802CAEB0);
    Pokemon_SetState(ob, func_beach_802CAE14);
}

void func_beach_802CAE14(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 1;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_beach_802CDBAC);
    pokemon->transitionGraph = D_beach_802CDCA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->unk_10E = 5;
    Pokemon_SetAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDCA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CAEB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802CAF1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CDBC0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_beach_802CAE14);
}
