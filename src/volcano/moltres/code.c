#include "volcano/volcano.h"

extern AnimCmd* moltres_modelanim_fly[];
extern AnimCmd* moltres_modelanim_fly2[];
extern AnimCmd* moltres_modelanim_shake_off[];
extern AnimCmd* moltres_modelanim_appear[];
extern AnimCmd* moltres_modelanim_fly_away[];

extern AnimCmd** moltres_matanim_fly[];
extern AnimCmd** moltres_matanim_fly2[];
extern AnimCmd** moltres_matanim_shake_off[];
extern AnimCmd** moltres_matanim_appear[];
extern AnimCmd** moltres_matanim_fly_away[];

void moltres_Render(GObj*);
void moltres_InitialState(GObj*);
void moltres_Appear(GObj*);
void moltres_UnusedPlayerIsClose(GObj*);
void moltres_UnusedBehavior(GObj*);
void moltres_Fly(GObj*);
void moltres_FlyAway(GObj*);

s32 moltres_animsounds_fly[] = { 0, SOUND_ID_120 };
s32 moltres_animsounds_fly2[] = { 0, SOUND_ID_120 };
s32 moltres_animsounds_shake_off[] = { SOUND_ID_189, SOUND_ID_139, SOUND_ID_120 };
s32 moltres_animsounds_appear[] = { SOUND_ID_189 };
s32 moltres_animsounds_fly_away[] = { SOUND_ID_189, SOUND_ID_120 };

AnimationHeader moltres_animation_fly = {
    0.6,
    60,
    moltres_modelanim_fly,
    moltres_matanim_fly,
    moltres_animsounds_fly
};

AnimationHeader moltres_animation_fly2 = {
    0.6,
    60,
    moltres_modelanim_fly2,
    moltres_matanim_fly2,
    moltres_animsounds_fly2
};

AnimationHeader moltres_animation_shake_off = {
    0.6,
    117,
    moltres_modelanim_shake_off,
    moltres_matanim_shake_off,
    moltres_animsounds_shake_off
};

AnimationHeader moltres_animation_appear = {
    0.6,
    57,
    moltres_modelanim_appear,
    moltres_matanim_appear,
    moltres_animsounds_appear
};

AnimationHeader moltres_animation_fly_away = {
    0.6,
    60,
    moltres_modelanim_fly_away,
    moltres_matanim_fly_away,
    moltres_animsounds_fly_away
};

InteractionHandler moltres_tg_WaitForEgg[] = {
    { VOLCANO_CMD_SPAWN_MOLTRES, moltres_Appear, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler moltres_tg_UnusedBehavior[] = {
    { POKEMON_CMD_16, moltres_UnusedPlayerIsClose, 4000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup moltres_animSetup = {
    &moltres_animation_appear,
    moltres_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData moltres_initData = {
    moltres_model,
    moltres_materials,
    moltres_Render,
    &moltres_animSetup,
    { 1.5, 1.5, 1.5 },
    { 0, 3.5, 0 },
    87,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(moltres_InitialState)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, moltres_UnusedBehavior);
    }
    pokemon->transitionGraph = moltres_tg_WaitForEgg;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(moltres_Appear)
    DObj* eggModel = pokemon->interactionTarget->data.dobj;

    GET_TRANSFORM(model)->pos.v.x = GET_TRANSFORM(eggModel)->pos.v.x;
    GET_TRANSFORM(model)->pos.v.y = GET_TRANSFORM(eggModel)->pos.v.y;
    GET_TRANSFORM(model)->pos.v.z = GET_TRANSFORM(eggModel)->pos.v.z;
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &moltres_animation_appear);
    Pokemon_StartPathProc(obj, moltres_Fly);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &moltres_animation_fly);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &moltres_animation_shake_off);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &moltres_animation_fly2);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &moltres_animation_fly_away);
    Pokemon_StartPathProc(obj, moltres_FlyAway);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(moltres_FlyAway)
    pokemon->hSpeed = pokemon->jumpVel = 400.0f;
    Pokemon_Jump(obj, 5000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(moltres_Fly)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(moltres_UnusedBehavior)
    pokemon->transitionGraph = moltres_tg_UnusedBehavior;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(moltres_UnusedPlayerIsClose)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &moltres_animation_fly2);
    Pokemon_StartPathProc(obj, moltres_Fly);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(moltres_Render)
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

    renderPokemonModelTypeI(obj);

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
}

GObj* moltres_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &moltres_initData);
}
