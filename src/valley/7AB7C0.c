#include "valley.h"

extern s32 D_802D2980_7ABF10;
extern AnimationHeader D_802EC994_7C5F24;
extern AnimationHeader D_802EC9A8_7C5F38;
extern AnimationHeader D_802EC9BC_7C5F4C;
extern InteractionHandler D_802EC9D0_7C5F60[];
extern RandomState D_802EC9F0_7C5F80[];
extern Vec3f D_802ECA10_7C5FA0;
extern PokemonInitData D_802ECA30_7C5FC0;

void func_802D237C_7AB90C(GObj*);
void func_802D2428_7AB9B8(GObj*);

POKEMON_FUNC(func_802D2230_7AB7C0)
    HIDE_POKEMON();
    pokemon->counter = 1;
    pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EC9D0_7C5F60;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D22A0_7AB830)
    SHOW_POKEMON();
    Pokemon_SetStateRandom(obj, D_802EC9F0_7C5F80);
}

POKEMON_FUNC(func_802D22D4_7AB864)
    Pokemon_ForceAnimation(obj, &D_802EC994_7C5F24);
    Pokemon_SetState(obj, func_802D237C_7AB90C);
}

POKEMON_FUNC(func_802D230C_7AB89C)
    Pokemon_ForceAnimation(obj, &D_802EC9A8_7C5F38);
    Pokemon_SetState(obj, func_802D237C_7AB90C);
}

POKEMON_FUNC(func_802D2344_7AB8D4)
    Pokemon_ForceAnimation(obj, &D_802EC9BC_7C5F4C);
    Pokemon_SetState(obj, func_802D237C_7AB90C);
}

POKEMON_FUNC(func_802D237C_7AB90C)
    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802D2428_7AB9B8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_802D2980_7ABF10 = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D2428_7AB9B8)
    Vec3f pos;
    Vec3f vel;
    DObj* temp_s1;
    GroundResult sp28;

    vel = D_802ECA10_7C5FA0;
    temp_s1 = model->firstChild->firstChild->next;
    ohWait(60);

    while (true) {
        fx_getPosVelDObj(&pos, &vel, temp_s1);
        getGroundAt(pos.x, pos.z, &sp28);
        if (!(pos.y < sp28.height)) {
            ohWait(1);
        } else {
            break;
        }
    }
    pos.y = sp28.height;
    if ((sp28.surfaceType == SURFACE_TYPE_337FB2) || (sp28.surfaceType == SURFACE_TYPE_007F66)) {
        func_8035E174_4FE584(obj, &pos);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D2540_7ABAD0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_802ECA30_7C5FC0);
}
