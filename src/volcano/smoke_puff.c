#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern UnkEC64Arg3 D_80113BA0[];
extern Texture** D_80113C50[];
extern AnimCmd* D_80113D00[];
extern AnimCmd** D_80113D30[];

void func_802DE570_72F770(GObj*);
void func_802DE648_72F848(GObj*);

AnimationHeader D_802E3290_734490 = {
    1.0,
    100,
    D_80113D00,
    D_80113D30,
    NULL
};

InteractionHandler D_802E32A4_7344A4[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E32B4_7344B4 = {
    &D_802E3290_734490,
    func_802DE570_72F770,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E32C8_7344C8 = {
    D_80113BA0,
    D_80113C50,
    renderModelTypeDFogged,
    &D_802E32B4_7344B4,
    { 30, 30, 30 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802DE570_72F770(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 30 + randRange(60), pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_802E3290_734490);
    Pokemon_StartPathProc(obj, func_802DE648_72F848);
    pokemon->transitionGraph = D_802E32A4_7344A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_33, obj);
    Pokemon_SetState(obj, func_802DE570_72F770);
}

void func_802DE648_72F848(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DE6B4_72F8B4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E32C8_7344C8);
}
