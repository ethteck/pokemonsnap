#include "valley.h"

extern s32 D_802D2980_7ABF10;
extern u16 D_802D2FF4_7AC584;
extern AnimationHeader D_802D3084_7AC614;
extern AnimationHeader D_802D3098_7AC628;
extern AnimationHeader D_802D30AC_7AC63C;
extern RandomState D_802D30C0_7AC650;
extern Vec3f D_802D30E0_7AC670;
extern PokemonInitData D_802D3100_7AC690;

void func_802CA364_7A38F4(GObj*);
void func_802CA434_7A39C4(GObj*);
void func_802CA574_7A3B04(GObj*);
void func_802CA5B4_7A3B44(GObj*);
void func_802CA65C_7A3BEC(GObj*);

POKEMON_FUNC(func_802CA270_7A3800)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802CA574_7A3B04);
    }
    Pokemon_SetStateRandom(obj, &D_802D30C0_7AC650);
}

POKEMON_FUNC(func_802CA2BC_7A384C)
    Pokemon_ForceAnimation(obj, &D_802D3084_7AC614);
    Pokemon_SetState(obj, func_802CA364_7A38F4);
}

POKEMON_FUNC(func_802CA2F4_7A3884)
    Pokemon_ForceAnimation(obj, &D_802D3098_7AC628);
    Pokemon_SetState(obj, func_802CA364_7A38F4);
}

POKEMON_FUNC(func_802CA32C_7A38BC)
    Pokemon_ForceAnimation(obj, &D_802D30AC_7AC63C);
    Pokemon_SetState(obj, func_802CA364_7A38F4);
}

POKEMON_FUNC(func_802CA364_7A38F4)
    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802CA434_7A39C4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802CA5B4_7A3B44);
    }
    D_802D2980_7ABF10 = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CA434_7A39C4)
    Vec3f pos;
    Vec3f vel = D_802D30E0_7AC670;
    DObj* temp_s1;
    GroundResult ground;

    temp_s1 = model->firstChild->firstChild->next->next;
    ohWait(60);

    while (true) {
        particle_getPosVelDObj(&pos, &vel, temp_s1);
        getGroundAt(pos.x, pos.z, &ground);
        if (pos.y < ground.height) {
            break;
        }
        ohWait(1);
    }

    pos.y = ground.height;
    if (pokemon->behavior == 0) {
        if (ground.surfaceType == SURFACE_TYPE_337FB2 || ground.surfaceType == SURFACE_TYPE_007F66) {
            func_8035E174_4FE584(obj, &pos);
        }
    } else {
        func_8035E264_4FE674(pokemon->miscVars[0].obj, &pos);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CA574_7A3B04)
    pokemon->miscVars[0].obj = func_8035E238_4FE648(obj);
    Pokemon_SetState(obj, func_802CA5B4_7A3B44);
}

POKEMON_FUNC(func_802CA5B4_7A3B44)
    s32 temp_t8;

    pokemon = obj->userData;
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->counter = randRange(180) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    if (D_802D2FF4_7AC584 != 0) {
        Pokemon_SetState(obj, func_802CA65C_7A3BEC);
    }
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetStateRandom(obj, &D_802D30C0_7AC650);
}

POKEMON_FUNC(func_802CA65C_7A3BEC)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802CA688_7A3C18(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D3100_7AC690);
}
