#include "volcano/volcano.h"

extern UnkEC64Arg3 koffing_smoke_model[];
extern Texture** koffing_smoke_materials[];

extern AnimCmd* koffing_smoke_modelanim_show[];
extern AnimCmd* koffing_smoke_modelanim_reveal[];
extern AnimCmd* koffing_smoke_modelanim_hide[];

extern AnimCmd** koffing_smoke_matanim_show[];
extern AnimCmd** koffing_smoke_matanim_reveal[];
extern AnimCmd** koffing_smoke_matanim_hide[];

void koffing_smoke_RevealFace(GObj* obj);
void koffing_smoke_Hide(GObj* obj);
void koffing_smoke_Rise(GObj* obj);
void koffing_smoke_InitialState(GObj*);

s32 koffing_smoke_animsounds_reveal[] = { SOUND_ID_61 };

AnimationHeader koffing_smoke_animation_show = {
    1.0,
    100,
    koffing_smoke_modelanim_show,
    koffing_smoke_matanim_show,
    NULL
};

AnimationHeader koffing_smoke_animation_reveal = {
    1.0,
    100,
    koffing_smoke_modelanim_reveal,
    koffing_smoke_matanim_reveal,
    koffing_smoke_animsounds_reveal
};

AnimationHeader koffing_smoke_animation_hide = {
    1.0,
    100,
    koffing_smoke_modelanim_hide,
    koffing_smoke_matanim_hide,
    NULL
};

InteractionHandler koffing_smoke_tg_Unused[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup koffing_smoke_animSetup = {
    &koffing_smoke_animation_show,
    koffing_smoke_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData koffing_smoke_initData = {
    koffing_smoke_model,
    koffing_smoke_materials,
    renderPokemonModelTypeDFogged,
    &koffing_smoke_animSetup,
    { 30, 30, 30 },
    { 0, 0, 0 },
    0,
    POKEMON_FLAG_4,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(koffing_smoke_InitialState)
    Pokemon_ForceAnimation(obj, &koffing_smoke_animation_show);
    Pokemon_StartPathProc(obj, koffing_smoke_Rise);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, koffing_smoke_RevealFace);
}

POKEMON_FUNC(koffing_smoke_RevealFace)
    Pokemon_ForceAnimation(obj, &koffing_smoke_animation_reveal);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, koffing_smoke_Hide);
}

POKEMON_FUNC(koffing_smoke_Hide)
    Pokemon_SetAnimation(obj, &koffing_smoke_animation_hide);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_SMOKE_FADED, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(koffing_smoke_Rise)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* koffing_smoke_Spawn(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    return Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &koffing_smoke_initData);
}
