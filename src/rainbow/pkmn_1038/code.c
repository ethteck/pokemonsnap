#include "../rainbow.h"


void func_8034A334_829AA4(GObj*);
void func_8034A3A0_829B10(GObj*);

extern UnkEC64Arg3 D_80118210_4CA5E0[];
extern Texture** D_80118160_4CA530[];
extern AnimCmd* D_80118360_4CA730[];
extern AnimCmd** D_80118390_4CA760[];

void func_8034A190_829900(GObj*);

// .data
AnimationHeader D_8034B600_82AD70 = {
    0.1,
    50,
    D_80118360_4CA730,
    D_80118390_4CA760,
    NULL
};

InteractionHandler D_8034B614_82AD84[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_8034B624_82AD94 = {
    &D_8034B600_82AD70,
    func_8034A190_829900,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_8034B638_82ADA8 = {
    D_80118210_4CA5E0,
    D_80118160_4CA530,
    renderModelTypeDFogged,
    &D_8034B624_82AD94,
    { 2, 2, 2 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_8034A190_829900)
    HIDE_POKEMON();
    obj->flags |= GOBJ_FLAG_2;

    ohWait(randRange(60));

    position->v.x = 750.0f - randFloat() * 1500.0f;
    position->v.y = 50.0f + randFloat() * 400.0f;
    position->v.z = 5000.0f;

    SHOW_POKEMON();
    obj->flags &= ~GOBJ_FLAG_2;
    Pokemon_SetState(obj, func_8034A334_829AA4);
}

POKEMON_FUNC(func_8034A27C_8299EC)
    HIDE_POKEMON();

    position->v.x = 750.0f - randFloat() * 1500.0f;
    position->v.y = 50.0f + randFloat() * 400.0f;
    position->v.z = 5000.0f;

    SHOW_POKEMON();
    Pokemon_SetState(obj, func_8034A334_829AA4);
}

POKEMON_FUNC(func_8034A334_829AA4)
    Pokemon_SetAnimation(obj, &D_8034B600_82AD70);
    Pokemon_StartPathProc(obj, func_8034A3A0_829B10);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_8034A27C_8299EC);
}

POKEMON_FUNC(func_8034A3A0_829B10)
    f32 f26 = 1.25f - randFloat() * 2.5f;

    while (position->v.z > -5000.0f) {
        position->v.z -= 200.0f;
        position->v.x += f26;
        if (ABS(position->v.y) < 400.0f) {
            HIDE_POKEMON();
        } else {
            SHOW_POKEMON();
        }
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_8034A4E8_829C58(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034B638_82ADA8);
}
