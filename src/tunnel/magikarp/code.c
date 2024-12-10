#include "../tunnel.h"

extern AnimationHeader D_802EFE20_5ECEF0;
extern InteractionHandler D_802EFE48_5ECF18[];
extern PokemonInitData D_802EFE7C_5ECF4C;

void func_802EBD6C_5E8E3C(GObj*);
void func_802EBE0C_5E8EDC(GObj*);
void func_802EBEC4_5E8F94(GObj*);

POKEMON_FUNC(func_802EBD20_5E8DF0)
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802EBD6C_5E8E3C);
    }

    Pokemon_SetState(obj, func_802EBE0C_5E8EDC);
}

POKEMON_FUNC(func_802EBD6C_5E8E3C)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = D_802EFE48_5ECF18;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EBDBC_5E8E8C)
    pokemon->tangible = true;
    obj->flags = 0;

    EnvSound_PlaySound(obj, 1, SOUND_ID_377);
    func_8035E1D4_4FE5E4(obj);
    Pokemon_SetState(obj, func_802EBE0C_5E8EDC);
}

POKEMON_FUNC(func_802EBE0C_5E8EDC)
    Pokemon_ForceAnimation(obj, &D_802EFE20_5ECEF0);
    rotation->v.y = randRange(360) * PI / 180.0f;
    Pokemon_StartPathProc(obj, func_802EBEC4_5E8F94);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    D_802EE10C_5EB1DC = false;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EBEC4_5E8F94)
    func_8035E298_4FE6A8(obj);

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802EBF04_5E8FD4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EFE7C_5ECF4C);
}
