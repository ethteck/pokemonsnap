#include "volcano/volcano.h"

extern UnkEC64Arg3 smoke_puff_model[];
extern Texture** smoke_puff_materials[];
extern AnimCmd* smoke_puff_modelanim[];
extern AnimCmd** smoke_puff_matanim[];

void func_802DE570_72F770(GObj*);
void func_802DE648_72F848(GObj*);

AnimationHeader D_802E3290_734490 = {
    1.0,
    100,
    smoke_puff_modelanim,
    smoke_puff_matanim,
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
    smoke_puff_model,
    smoke_puff_materials,
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

POKEMON_FUNC(func_802DE570_72F770)
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

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_33, obj);
    Pokemon_SetState(obj, func_802DE570_72F770);
}

POKEMON_FUNC(func_802DE648_72F848)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DE6B4_72F8B4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E32C8_7344C8);
}
