#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E3CF8_6CBAD8;
extern AnimationHeader D_802E3D0C_6CBAEC;
extern AnimationHeader D_802E3D20_6CBB00;
extern InteractionHandler D_802E3D34_6CBB14[];
extern PokemonInitData D_802E3D68_6CBB48;
extern s32 D_802E3DA0_6CBB80;
extern PokemonInitData D_802E3DCC_6CBBAC;
extern GObj* D_8033F5C8_7273A8;

void func_802DEB00_6C68E0(GObj*);
void func_802DEBB8_6C6998(GObj*);

POKEMON_FUNC(func_802DE900_6C66E0)
    Pokemon_SetAnimation(obj, &D_802E3D20_6CBB00);
    pokemon->transitionGraph = D_802E3D34_6CBB14;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DE958_6C6738)
    Pokemon_SetAnimation(obj, &D_802E3CF8_6CBAD8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3D0C_6CBAEC);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DE9C0_6C67A0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_8033F5C8_7273A8 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802E3D68_6CBB48);

    return D_8033F5C8_7273A8;
}

POKEMON_FUNC(func_802DEA00_6C67E0)
    s32 blockCount;
    f32 blockPart;

    obj->flags |= GOBJ_FLAG_2;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 2 && (blockCount != 1 || !(blockPart >= 0.9f))) {
            ohWait(1);
        } else {
            break;
        }
    }
    Pokemon_StartAuxProc(obj, func_802DEBB8_6C6998);
    Pokemon_StartPathProc(obj, func_802DEB00_6C68E0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->flags &= ~POKEMON_FLAG_4;
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEB00_6C68E0)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 3 && (blockCount != 2 || !(blockPart >= 0.9f))) {
            ohWait(1);
        } else {
            break;
        }
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DEBB8_6C6998)
    while (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        if (D_802E3DA0_6CBB80 != 0) {
            pokemon->flags |= POKEMON_FLAG_4;
        } else {
            pokemon->flags &= ~POKEMON_FLAG_4;
        }
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

GObj* func_802DEC50_6C6A30(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802E3DCC_6CBBAC);
}
