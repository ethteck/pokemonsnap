#include "../rainbow.h"

extern AnimationHeader D_8034B600_82AD70;
extern PokemonInitData D_8034B638_82ADA8;

void func_8034A334_829AA4(GObj*);
void func_8034A3A0_829B10(GObj*);

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
