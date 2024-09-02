#include "volcano/volcano.h"

extern UnkEC64Arg3 koffingSmoke_model[];
extern Texture** koffingSmoke_materials[];

extern AnimCmd* koffingSmoke_modelanim_show[];
extern AnimCmd* koffingSmoke_modelanim_reveal[];
extern AnimCmd* koffingSmoke_modelanim_hide[];

extern AnimCmd** koffingSmoke_matanim_show[];
extern AnimCmd** koffingSmoke_matanim_reveal[];
extern AnimCmd** koffingSmoke_matanim_hide[];

void koffingSmoke_RevealFace(GObj* obj);
void koffingSmoke_Hide(GObj* obj);
void koffingSmoke_Rise(GObj* obj);
void koffingSmoke_InitialState(GObj*);

s32 koffingSmoke_animsounds_reveal[] = { SOUND_ID_61 };

AnimationHeader koffingSmoke_animation_show = {
    1.0,
    100,
    koffingSmoke_modelanim_show,
    koffingSmoke_matanim_show,
    NULL
};

AnimationHeader koffingSmoke_animation_reveal = {
    1.0,
    100,
    koffingSmoke_modelanim_reveal,
    koffingSmoke_matanim_reveal,
    koffingSmoke_animsounds_reveal
};

AnimationHeader koffingSmoke_animation_hide = {
    1.0,
    100,
    koffingSmoke_modelanim_hide,
    koffingSmoke_matanim_hide,
    NULL
};

InteractionHandler koffingSmoke_tg_Unused[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup koffingSmoke_animSetup = {
    &koffingSmoke_animation_show,
    koffingSmoke_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData koffingSmoke_initData = {
    koffingSmoke_model,
    koffingSmoke_materials,
    renderPokemonModelTypeDFogged,
    &koffingSmoke_animSetup,
    { 30, 30, 30 },
    { 0, 0, 0 },
    0,
    POKEMON_FLAG_4,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(koffingSmoke_InitialState)
    Pokemon_ForceAnimation(obj, &koffingSmoke_animation_show);
    Pokemon_StartPathProc(obj, koffingSmoke_Rise);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, koffingSmoke_RevealFace);
}

POKEMON_FUNC(koffingSmoke_RevealFace)
    Pokemon_ForceAnimation(obj, &koffingSmoke_animation_reveal);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, koffingSmoke_Hide);
}

POKEMON_FUNC(koffingSmoke_Hide)
    Pokemon_SetAnimation(obj, &koffingSmoke_animation_hide);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_33, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(koffingSmoke_Rise)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* koffingSmoke_Spawn(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    return Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &koffingSmoke_initData);
}
