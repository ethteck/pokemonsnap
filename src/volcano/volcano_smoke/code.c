#include "volcano/volcano.h"

extern UnkEC64Arg3 volcano_smoke_model[];
extern Texture** volcano_smoke_materials[];
extern AnimCmd* volcano_smoke_modelanim[];
extern AnimCmd** volcano_smoke_matanim[];

void volcano_smoke_Idle(GObj*);
void volcano_smoke_Render(GObj*);
void volcano_smoke_InitialState(GObj*);

__ALIGNER2

AnimationHeader volcano_smoke_animation = {
    0.4,
    100,
    volcano_smoke_modelanim,
    volcano_smoke_matanim,
    NULL
};

InteractionHandler volcano_smoke_tg_Normal[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup volcano_smoke_animSetup = {
    &volcano_smoke_animation,
    volcano_smoke_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData volcano_smoke_initData = {
    volcano_smoke_model,
    volcano_smoke_materials,
    volcano_smoke_Render,
    &volcano_smoke_animSetup,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(volcano_smoke_InitialState)
    Pokemon_SetState(obj, volcano_smoke_Idle);
}

POKEMON_FUNC(volcano_smoke_Idle)
    Pokemon_SetAnimation(obj, &volcano_smoke_animation);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(volcano_smoke_Render)
    gDPSetTextureLUT(gMainGfxPos[1]++, G_TT_NONE);
    gDPSetCycleType(gMainGfxPos[1]++, G_CYC_2CYCLE);
    renderModelTypeDFogged(obj);
}

GObj* volcano_smoke_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &volcano_smoke_initData);
}
