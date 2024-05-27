#include "common.h"
#include "world/world.h"
#include "app_level.h"

typedef struct PokemonObjectListEntry {
    /* 0x00 */ struct PokemonObjectListEntry* prev;
    /* 0x04 */ struct PokemonObjectListEntry* next;
    /* 0x08 */ GObj* obj;
} PokemonObjectListEntry; // size 0xC

typedef struct PokemonTransformListEntry {
    /* 0x00 */ struct PokemonTransformListEntry* next;
    /* 0x04 */ PokemonTransformBase* transform;
} PokemonTransformListEntry; // size 0x8

typedef struct PokemonDataListEntry {
    /* 0x00 */ struct PokemonDataListEntry* next;
    /* 0x04 */ Pokemon* pokemon;
} PokemonDataListEntry; // size 0x8

typedef struct ItemListEntry {
    /* 0x00 */ struct ItemListEntry* next;
    /* 0x04 */ Item* item;
} ItemListEntry; // size 0x8

Gfx D_8038A3D0_52A7E0[] = {
    gsDPPipeSync(),
    gsSPFogPosition(968, 990),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | G_RM_FOG_SHADE_A, Z_CMP | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA)),
    gsSPSetGeometryMode(G_FOG),
    gsSPEndDisplayList(),
};
Gfx D_8038A400_52A810[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_FOG),
    gsDPSetCombineMode(G_CC_MODULATEIDECALA, G_CC_PASS2),
    gsSPEndDisplayList(),
};

extern DObj* gPlayerDObj;
extern GObj* gPokemonInFocus;

void pokemonChangeBlockOnGround(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_800A5E98(Vec3f*, Vec3f*, DObj*);
void func_800AB1F8(EggStruct*);
s32 func_800AB138(EggStruct* arg0, f32 arg1);
void func_80360074_500484(GObj*);
void deletePokemon(GObj* pokemonObj);
void func_800A716C(GObj*);
u8 getIsPaused(void);
void func_80366864_506C74(GObj*, u8);
void func_803667C0_506BD0(GObj*, UNK_TYPE, UNK_TYPE);
s32 func_8036381C_503C2C(void);
s32 Pokemon_StepWalkInDirection(GObj* arg0, f32 arg1, u32 arg2);

// bss
extern PokemonObjectListEntry D_803B0A28_550E38[40];
extern PokemonObjectListEntry* D_803B0C08_551018;
extern PokemonObjectListEntry* D_803B0C0C_55101C;
extern PokemonObjectListEntry* D_803B0C10_551020;
extern PokemonTransformListEntry D_803B0C18_551028[40];
extern PokemonTransformListEntry* D_803B0D58_551168;
extern PokemonTransformListEntry* D_803B0D5C_55116C;
extern PokemonDataListEntry D_803B0D60_551170[40];
extern PokemonDataListEntry* D_803B0EA0_5512B0;
extern PokemonDataListEntry* D_803B0EA4_5512B4;
extern ItemListEntry D_803B0EA8_5512B8[20];
extern ItemListEntry* D_803B0F48_551358;
extern ItemListEntry* D_803B0F4C_55135C;

void Pokemon_LinkObject(GObj* arg0) {
    PokemonObjectListEntry* entry = D_803B0C10_551020;

    if (D_803B0C10_551020 == NULL) {
        return;
    }

    D_803B0C10_551020 = D_803B0C10_551020->next;

    entry->prev = D_803B0C0C_55101C;
    entry->next = NULL;

    if (entry->prev != NULL) {
        entry->prev->next = D_803B0C0C_55101C = entry;
    } else {
        D_803B0C08_551018 = D_803B0C0C_55101C = entry;
    }
    entry->obj = arg0;
}

void Pokemon_UnLinkObject(GObj* obj) {
    PokemonObjectListEntry* entry = D_803B0C08_551018;

    while (entry != NULL) {
        if (entry->obj == obj) {
            break;
        }
        entry = entry->next;
    }

    if (entry->prev != NULL) {
        entry->prev->next = entry->next;
    } else {
        D_803B0C08_551018 = entry->next;
    }
    if (entry->next != NULL) {
        entry->next->prev = entry->prev;
    } else {
        D_803B0C0C_55101C = entry->prev;
    }

    entry->next = D_803B0C10_551020;
    entry->obj = NULL;
    D_803B0C10_551020 = entry;
}

s32 func_8035E868_4FEC78(GObj* obj) {
    PokemonObjectListEntry* entry = D_803B0C08_551018;

    while (entry != NULL) {
        if (entry->obj == obj) {
            return TRUE;
        }
        entry = entry->next;
    }
    return FALSE;
}

void Pokemon_InitTransforms(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803B0C18_551028) - 1; i++) {
        D_803B0C18_551028[i].next = &D_803B0C18_551028[i+1];
    }
    D_803B0C18_551028[i].next = NULL;

    D_803B0D58_551168 = NULL;
    D_803B0D5C_55116C = D_803B0C18_551028;
}

PokemonTransformBase* Pokemon_GetTransform(void) {
    PokemonTransformBase* ret;
    PokemonTransformListEntry* v0 = D_803B0D58_551168;

    if (v0 != NULL) {
        ret = v0->transform;
        D_803B0D58_551168 = v0->next;
        v0->next = D_803B0D5C_55116C;
        D_803B0D5C_55116C = v0;
    } else {
        ret = gtlMalloc(sizeof(PokemonTransformBase), 0x40);
    }
    return ret;
}

void Pokemon_FreeTransform(PokemonTransformBase* arg0) {
    PokemonTransformListEntry* temp_v0;

    temp_v0 = D_803B0D5C_55116C;
    if (temp_v0 != NULL) {
        temp_v0->transform = arg0;
        D_803B0D5C_55116C = temp_v0->next;

        temp_v0->next = D_803B0D58_551168;
        D_803B0D58_551168 = temp_v0;
    }
}

void Pokemon_InitPokemonsData(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803B0D60_551170) - 1; i++) {
        D_803B0D60_551170[i].next = &D_803B0D60_551170[i+1];
    }
    D_803B0D60_551170[i].next = NULL;

    D_803B0EA0_5512B0 = NULL;
    D_803B0EA4_5512B4 = D_803B0D60_551170;
}

Pokemon* Pokemon_GetPokemonData(void) {
    Pokemon* ret;
    PokemonDataListEntry* v0 = D_803B0EA0_5512B0;

    if (v0 != NULL) {
        ret = v0->pokemon;
        D_803B0EA0_5512B0 = v0->next;
        v0->next = D_803B0EA4_5512B4;
        D_803B0EA4_5512B4 = v0;
    } else {
        ret = gtlMalloc(sizeof(Pokemon), 0x40);
    }
    return ret;
}

void Pokemon_FreePokemonData(Pokemon* arg0) {
    PokemonDataListEntry* temp_v0;

    temp_v0 = D_803B0EA4_5512B4;
    if (temp_v0 != NULL) {
        temp_v0->pokemon = arg0;
        D_803B0EA4_5512B4 = temp_v0->next;

        temp_v0->next = D_803B0EA0_5512B0;
        D_803B0EA0_5512B0 = temp_v0;
    }
}

void Pokemon_InitItems(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803B0EA8_5512B8) - 1; i++) {
        D_803B0EA8_5512B8[i].next = &D_803B0EA8_5512B8[i+1];
    }
    D_803B0EA8_5512B8[i].next = NULL;

    D_803B0F48_551358 = NULL;
    D_803B0F4C_55135C = D_803B0EA8_5512B8;
}

Item* Pokemon_GetItem(void) {
    Item* ret;
    ItemListEntry* v0 = D_803B0F48_551358;

    if (v0 != NULL) {
        ret = v0->item;
        D_803B0F48_551358 = v0->next;
        v0->next = D_803B0F4C_55135C;
        D_803B0F4C_55135C = v0;
    } else {
        ret = gtlMalloc(sizeof(Item), 0x40);
    }
    return ret;
}

void Pokemon_FreeItem(Item* arg0) {
    ItemListEntry* temp_v0;

    temp_v0 = D_803B0F4C_55135C;
    if (temp_v0 != NULL) {
        temp_v0->item = arg0;
        D_803B0F4C_55135C = temp_v0->next;

        temp_v0->next = D_803B0F48_551358;
        D_803B0F48_551358 = temp_v0;
    }
}

void Pokemon_SetState(GObj* obj, GObjFunc stateProc) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->stateProc;

    pokemon->transitionGraph = NULL;
    if (stateProc != NULL) {
        pokemon->stateProc = omCreateProcess(obj, stateProc, 0, 7);
    } else {
        pokemon->stateProc = NULL;
    }
    omEndProcess(oldProc);
}

void Pokemon_SetStateRandom(GObj* obj, RandomState* stateList) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->stateProc;
    s32 sumWeight = 0;
    s32 i;
    s32 randValue;

    pokemon->transitionGraph = NULL;

    for (i = 0; stateList[i].func != NULL; i++) {
        sumWeight += stateList[i].weight;
    }
    randValue = randRange(sumWeight);

    sumWeight = stateList[0].weight;
    for (i = 0; sumWeight <= randValue; i++) {
        sumWeight += stateList[i+1].weight;
    }

    if (stateList[i].func != NULL) {
        pokemon->stateProc = omCreateProcess(obj, stateList[i].func, 0, 7);
        omEndProcess(oldProc);
    }
}

// TODO: figure out what functions are passed here as an argument, and maybe come up with a better name
void Pokemon_StartAuxProc(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_AUX_ENDED;
    omCreateProcess(obj, func, 0, 6);
}

void Pokemon_StopAuxProc(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_AUX_ENDED;
    omEndProcess(NULL);
}

void Pokemon_StartPathProc(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->pathProc;

    if (func != NULL) {
        pokemon->pathProc = omCreateProcess(obj, func, 0, 5);
        pokemon->processFlags &= ~(POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_10 | POKEMON_PROCESS_FLAG_MOVEMENT_ENDED);
    } else {
        pokemon->pathProc = NULL;
    }
    if (oldProc != NULL) {
        omEndProcess(oldProc);
    }
}

void Pokemon_SetTexture(MObj* mobj, Texture* arg1) {
    f32 var_f6;
    u8 temp_t6;

    omMObjResetAObjList(mobj);
    mobj->lodLevel = arg1->unk_54 / 255.0f;
    mobj->texture = *arg1;

    mobj->texture.unk_24 = arg1->unk_14;
    mobj->texture.unk_28 = arg1->scaleS;
    mobj->imageIndex = 0;
    mobj->nextImageIndex = 0;
    mobj->animList = NULL;
    mobj->timeLeft = ANIMATION_DISABLED;
    mobj->animSpeed = 1.0f;
    mobj->timePassed = 0.0f;
}

void Pokemon_SetTextures(GObj* obj, Texture*** arg1) {
    DObj* dobj = obj->data.dobj;
    MObj* mobj;
    Texture** csr;

    while (dobj != NULL) {
        mobj = dobj->mobjList;
        if (arg1 != NULL) {
            if (*arg1 != NULL) {
                csr = *arg1;
                while (*csr != NULL) {
                    Pokemon_SetTexture(mobj, *csr);
                    csr++;
                    mobj = mobj->next;
                }
            }
            arg1++;
        }
        dobj = animModelTreeNextNode(dobj);
    }
}

void Pokemon_SetAnimationCommon(GObj* obj, AnimationHeader* header, f32 startTime, s32 force) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (header != NULL) {
        if (pokemon->modelAnims == NULL) {
            ohResumeProcessByFunction(obj, animUpdateModelTreeAnimation);
        }

        if (pokemon->modelAnims != header->modelAnims || force) {
            func_80366864_506C74(obj, 0);
            anim_func_8000F8E4(obj, header->modelAnims, startTime, pokemon->initData->tree);
            pokemon->modelAnims = header->modelAnims;
        }

        if (header->matAnims != NULL) {
            if (pokemon->matAnims != header->matAnims || force) {
                animSetModelTreeTextureAnimation(obj, header->matAnims, 0.0f);
                pokemon->matAnims = header->matAnims;
            }
            animSetModelAndTextureAnimationSpeed(obj, header->speed);
        } else {
            if (pokemon->initData->textures != NULL) {
                Pokemon_SetTextures(obj, pokemon->initData->textures);
            }
            animSetModelAnimationSpeed(obj, header->speed);
            pokemon->matAnims = NULL;
        }

        pokemon->animHeader = header;
        animUpdateModelTreeAnimation(obj);
    } else {
        ohPauseProcessByFunction(obj, animUpdateModelTreeAnimation);
        pokemon->animHeader = NULL;
        pokemon->matAnims = NULL;
        pokemon->modelAnims = NULL;
    }

    pokemon->loopCount = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_ANIMATION_ENDED;
    pokemon->pokemonLoopTarget = 1;
    pokemon->lastAnimationFrame = 0.0f;
}

void Pokemon_SetAnimation(GObj* obj, AnimationHeader* header) {
    Pokemon_SetAnimationCommon(obj, header, 0, FALSE);
}

void Pokemon_ForceAnimation(GObj* obj, AnimationHeader* header) {
    Pokemon_SetAnimationCommon(obj, header, 0, TRUE);
}

void Pokemon_SetAnimationAtTime(GObj* obj, AnimationHeader* header, f32 time) {
    Pokemon_SetAnimationCommon(obj, header, time, FALSE);
}

void Pokemon_ForceAnimationAtTime(GObj* obj, AnimationHeader* header, f32 time) {
    Pokemon_SetAnimationCommon(obj, header, time, TRUE);
}

void func_8035F1D0_4FF5E0(GObj* arg0, u8 arg1, s32 arg2) {
    if (func_8036381C_503C2C() != 0 && !(arg0->flags & GOBJ_FLAG_HIDDEN)) {
        func_803667C0_506BD0(arg0, arg1, arg2);
    }
}

f32 Pokemon_GetGroundAt(f32 x, f32 z) {
    GroundResult result;

    if (getGroundAt(x, z, &result)) {
        return result.height;
    }
    return 0.0f;
}

f32 Pokemon_WrapAngleSum(f32 angle1, f32 angle2) {
    f32 sum = angle1 + angle2;
    f32 ret = sum - (s32)(sum / TAU) * TAU;

    if (ret < 0.0f) {
        ret += TAU;
    }
    return ret;
}

f32 Pokemon_GetDistance(GObj* obj1, GObj* obj2) {
    s32 unused;
    DObj* model1;
    DObj* model2;
    Vec3f pos1;
    Vec3f pos2;
    Vec3f dir;

    if (obj1 == NULL || obj2 == NULL) {
        return FLOAT_MAX;
    }

    model1 = obj1->data.dobj;
    model2 = obj2->data.dobj;

    if (model1->unk_4C != NULL) {
        pos1.x = GET_TRANSFORM(model1)->pos.v.x;
        pos1.y = GET_TRANSFORM(model1)->pos.v.y;
        pos1.z = GET_TRANSFORM(model1)->pos.v.z;
    } else {
        pos1.x = model1->position.v.x;
        pos1.y = model1->position.v.y;
        pos1.z = model1->position.v.z;
    }

    if (model2 == NULL) {
        return FLOAT_MAX;
    }

    if (model2->unk_4C != NULL) {
        pos2.x = GET_TRANSFORM(model2)->pos.v.x;
        pos2.y = GET_TRANSFORM(model2)->pos.v.y;
        pos2.z = GET_TRANSFORM(model2)->pos.v.z;
    } else {
        pos2.x = model2->position.v.x;
        pos2.y = model2->position.v.y;
        pos2.z = model2->position.v.z;
    }

    return Vec3fDirection(&dir, &pos1, &pos2);
}

void Pokemon_CalcDistanceToPlayer(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (gPlayerDObj != NULL) {
        Vec3f posPlayer;
        Vec3f posPokemon;
        Vec3f dir;

        posPokemon.x = GET_TRANSFORM(model)->pos.v.x;
        posPokemon.y = GET_TRANSFORM(model)->pos.v.y;
        posPokemon.z = GET_TRANSFORM(model)->pos.v.z;

        posPlayer.x = GET_TRANSFORM(gPlayerDObj)->pos.v.x;
        posPlayer.y = GET_TRANSFORM(gPlayerDObj)->pos.v.y;
        posPlayer.z = GET_TRANSFORM(gPlayerDObj)->pos.v.z;

        pokemon->playerDist = Vec3fDirection(&dir, &posPlayer, &posPokemon);
    } else {
        pokemon->playerDist = FLOAT_MAX;
    }
}

#ifdef NON_MATCHING
GObj* Pokemon_GetClosestItem(GObj* obj, f32* distance) {
    GObj* closestItem = NULL;
    GObj* currItem = NULL;
    DObj* model = obj->data.dobj;
    f32 closestDist2 = FLOAT_MAX;
    f32 x, y, z;

    x = GET_TRANSFORM(model)->pos.v.x;
    y = GET_TRANSFORM(model)->pos.v.y;
    z = GET_TRANSFORM(model)->pos.v.z;

    Items_InitIterator();
    while ((currItem = Items_NextValidItem()) != NULL) {
        DObj* itemModel = currItem->data.dobj;
        f32 currDist2 = SQ(x - itemModel->position.v.x) + SQ(y - itemModel->position.v.y) + SQ(z - itemModel->position.v.z);
        if (closestDist2 > currDist2) {
            closestItem = currItem;
            closestDist2 = currDist2;
        }
    }
    if (closestItem != NULL) {
        *distance = sqrtf(closestDist2);
    }
    return closestItem;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/Pokemon_GetClosestItem.s")
GObj* Pokemon_GetClosestItem(GObj* obj, f32* distance);
#endif

f32 Pokemon_HeadingBetweenPoints(Vec3f* pointTo, Vec3f* pointFrom) {
    f32 dx = pointTo->x - pointFrom->x;
    f32 dy = pointTo->y - pointFrom->y;
    f32 dz = pointTo->z - pointFrom->z;
    f32 invLen;
    f32 heading;

    if (ABS(dz) < 0.00001) {
        dx = 1.0f;
        dz = 0.0f;
    }

    invLen = 1.0f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    dx *= invLen;
    dz *= invLen;
    heading = atan2f(dx, dz);

    if (heading < 0.0f) {
        heading += TAU;
    } else if (heading > TAU) {
        heading -= (s32)(heading / TAU) * TAU;
    }
    return heading;
}

f32 Pokemon_GetHeadingVector(Vec3f* pointTo, Vec3f* pointFrom, Vec3f* outVec, f32 length) {
    f32 dx = pointTo->x - pointFrom->x;
    f32 dy = pointTo->y - pointFrom->y;
    f32 dz = pointTo->z - pointFrom->z;
    f32 invLen;
    f32 heading;

    if (ABS(dz) < 0.00001) {
        dx = 1.0f;
        dz = 0.0f;
    }

    invLen = length / sqrtf(SQ(dx) + SQ(dz));
    dx *= invLen;
    dz *= invLen;
    heading = atan2f(dx, dz);

    if (heading < 0.0f) {
        heading += TAU;
    } else if (heading > TAU) {
        heading -= (s32)(heading / TAU) * TAU;
    }
    if (outVec != NULL) {
        outVec->x = dx;
        outVec->y = 0.0f;
        outVec->z = dz;
    }
    return heading;
}

f32 Pokemon_GetDirToNeighbours(GObj* obj, Vec3f* outDir) {
    GObj* pokemonObj;
    DObj* model = obj->data.dobj;
    f32 dist;
    s32 hasNeighbour = FALSE;
    Vec3f pos;
    Vec3f neighbourPos;
    Vec3f dir;

    pos.x = GET_TRANSFORM(model)->pos.v.x;
    pos.y = GET_TRANSFORM(model)->pos.v.y;
    pos.z = GET_TRANSFORM(model)->pos.v.z;

    outDir->x = outDir->y = outDir->z = 0.0f;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        if (pokemonObj != obj) {
            DObj* model2 = pokemonObj->data.dobj;

            neighbourPos.x = GET_TRANSFORM(model2)->pos.v.x;
            neighbourPos.y = GET_TRANSFORM(model2)->pos.v.y;
            neighbourPos.z = GET_TRANSFORM(model2)->pos.v.z;

            dist = Vec3fDirection(&dir, &pos, &neighbourPos);
            if (dist < 100.0f) {
                hasNeighbour = TRUE;
                outDir->x += dist * dir.x;
                outDir->y += dist * dir.y;
                outDir->z += dist * dir.z;
            }
        }
    }

    if (hasNeighbour) {
        return Vec3fNormalize(outDir);
    } else {
        return 0.0f;
    }
}

void Pokemon_RunInteractions(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 i;
    s32 continueSearch = TRUE;
    Vec3f dirToNeighbors;
    f32 interactionDist;
    GObj* interactionTarget;
    GObjFunc stateProc = NULL;
    GObjFunc auxProc = NULL;
    InteractionHandler* transitionGraph = pokemon->transitionGraph;

    if (transitionGraph == NULL) {
        return;
    }

    for (i = 0; continueSearch && transitionGraph[i].cmd != 58; i++) {
        if (transitionGraph[i].state == NULL && transitionGraph[i].aux == NULL) {
            continue;
        }

        switch (transitionGraph[i].cmd) {
            case POKEMON_CMD_15:
                interactionTarget = Pokemon_GetClosestItem(obj, &interactionDist);
                if (interactionTarget != NULL) {
                    Item* item = GET_ITEM(interactionTarget);
                    if (interactionTarget != pokemon->apple && item->itemID == ITEM_ID_APPLE && item->state == ITEM_STATE_STILL && interactionDist < 600.0f) {
                        pokemon->apple = interactionTarget;
                        continueSearch = FALSE;
                        pokemon->interactionDist = interactionDist;
                        pokemon->interactionTarget = interactionTarget;
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                    }
                }
                break;
            case POKEMON_CMD_16:
                if (pokemon->playerDist < transitionGraph[i].value) {
                    pokemon->interactionDist = interactionDist; // BUG: interactionDist undefined here, must use 'playerDist'
                    continueSearch = FALSE;
                    pokemon->interactionTarget = gObjPlayer;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                }
                break;
            case POKEMON_CMD_17:
                if (Pokemon_GetDirToNeighbours(obj, &dirToNeighbors) > 0.0f) {
                    pokemon->dirToNeighbors.x = dirToNeighbors.x;
                    pokemon->dirToNeighbors.y = dirToNeighbors.y;
                    pokemon->dirToNeighbors.z = dirToNeighbors.z;
                    continueSearch = FALSE;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                }
                break;
            case POKEMON_CMD_5:
            case POKEMON_CMD_6:
            case POKEMON_CMD_7:
                if (Items_GetPokeFluteCmd() == transitionGraph[i].cmd && pokemon->playerDist < 1400.0f) {
                    continueSearch = FALSE;
                    pokemon->interactionTarget = gObjPlayer;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                }
                break;
            case POKEMON_CMD_23:
                if (D_80382CF8_523108 > transitionGraph[i].value && obj == gPokemonInFocus) {
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    continueSearch = FALSE;
                }
                break;
            case POKEMON_CMD_25:
                if (gDirectionIndex < 0 && pokemon->playerDist < transitionGraph[i].value) {
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    continueSearch = FALSE;
                }
                break;
        }
    }

    if (auxProc != NULL) {
        Pokemon_StartAuxProc(obj, auxProc);
    }
    if (stateProc != NULL) {
        Pokemon_SetState(obj, stateProc);
    }
    if (!func_80353D68_4F4178()) {
        ohPauseObjectProcesses(obj);
    }
}

// if multiple flags specified, setting one of them is enough to stop this process
void Pokemon_WaitForFlag(GObj* obj, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        Pokemon_RunInteractions(obj);
        if (pokemon->processFlags & flags) {
            break;
        }
        ohWait(1);
    }
    pokemon->transitionGraph = NULL;
}

void Pokemon_WaitForFlagNoInteraction(GObj* obj, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        if (pokemon->processFlags & flags) {
            break;
        }
        ohWait(1);
    }
}

void Pokemon_SendDieCommand(GObj* thisObj) {
    PokemonObjectListEntry* entry;

    for (entry = D_803B0C08_551018; entry != NULL; entry = entry->next) {
        GObj* obj = entry->obj;
        Pokemon* pokemon = GET_POKEMON(obj);
        if (thisObj == pokemon->interactionTarget) {
            cmdSendCommand(obj, POKEMON_CMD_22, thisObj);
        }
    }
}

void Pokemon_Cleanup(GObj* obj) {
    obj->flags |= GOBJ_FLAG_HIDDEN;
    PokemonDetector_CleanupPokemon(obj);
    func_80357428_4F7838(obj);
    Pokemon_SendDieCommand(obj);
    Pokemon_FreeTransform(GET_TRANSFORM_BASE(obj->data.dobj));
    Pokemon_FreePokemonData(GET_POKEMON(obj));
    Pokemon_UnLinkObject(obj);
    func_800A716C(obj);
    deletePokemon(obj);
}

void Pokemon_RunCleanup(GObj* obj) {
    omCreateProcess(obj, Pokemon_Cleanup, 1, 4);
}

void Pokemon_RemovePokemons(u16* exceptionList) {
    GObj* pokemonObj;
    u16* ptr;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        u16 id = GET_POKEMON(pokemonObj)->id;

        for (ptr = exceptionList; *ptr != 0; ptr++) {
            if (*ptr == id) {
                break;
            }
        }
        if (*ptr == 0) {
            Pokemon_RunCleanup(pokemonObj);
        }
    }
}

GObj* Pokemon_AddAtGeo(GObj* gobj, u16 id, PokemonDef* def) {
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemonTmp;
    GObj* pokemonObj;

    pokemonTmp = GET_POKEMON(gobj);
    block = getCurrentWorldBlock();
    spawn.id = id;
    spawn.translation.x = 0.0f;
    spawn.translation.y = 0.0f;
    spawn.translation.z = 0.0f;
    spawn.euler.x = 0.0f;
    spawn.euler.y = 0.0f;
    spawn.euler.z = 0.0f;
    spawn.scale.x = 1.0f;
    spawn.scale.y = 1.0f;
    spawn.scale.z = 1.0f;
    spawn.path = pokemonTmp->path;
    spawn.behavior = pokemonTmp->behavior;

    pokemonObj = pokemonAddOne(block, block, &spawn, def);

    if (pokemonObj != NULL) {
        PokemonTransformBase* transform2 = GET_TRANSFORM_BASE(gobj->data.dobj);
        PokemonTransformBase* transform1 = GET_TRANSFORM_BASE(pokemonObj->data.dobj);

        transform1->xform.pos.v.x = transform2->xform.pos.v.x;
        transform1->xform.pos.v.y = transform2->xform.pos.v.y;
        transform1->xform.pos.v.z = transform2->xform.pos.v.z;
    }

    return pokemonObj;
}

void Pokemon_SetFlag100(GObj* obj, s32 enabled) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (enabled == TRUE) {
        pokemon->flags |= POKEMON_FLAG_100;
    } else {
        pokemon->flags &= ~POKEMON_FLAG_100;
    }
}

s32 Pokemon_GetFlag100(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 ret;

    if (pokemon->flags & POKEMON_FLAG_100) {
        ret = TRUE;
    } else {
        ret = FALSE;
    }
    return ret;
}

void func_8035FF44_500354(GObj* obj, s32 arg1, s32 arg2) {
    s32 v1;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 f20 = 255.0f;
    f32 delta;

    obj->fnRender = func_80360074_500484;
    v1 = 255 - arg1;
    if (v1 < 0) {
        v1 = 0;
    }
    delta = (f32)v1 / (f32)arg2;
    while (arg2-- > 0) {
        f20 -= delta;
        pokemon->unk_E4 = f20;
        ohWait(1);
    }
    pokemon->unk_E4 = arg1;
}

void func_80360074_500484(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    gSPDisplayList(gMainGfxPos[0]++, D_8038A3D0_52A7E0);
    gDPSetFogColor(gMainGfxPos[0]++, 230, 250, 180, pokemon->unk_E4);
    renderPokemonModelTypeI(obj);
    gSPDisplayList(gMainGfxPos[0]++, D_8038A400_52A810);
}

void Pokemon_EatApple(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (Items_CheckObjectExists(pokemon->apple)) {
        Items_DeleteItem(pokemon->apple);
    }
}

void Pokemon_SetScale(GObj* obj, f32 newScale) {
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonInitData* initData = pokemon->initData;

    GET_TRANSFORM(model)->scale.v.x = initData->scale.x * 0.1f * newScale;
    GET_TRANSFORM(model)->scale.v.y = initData->scale.y * 0.1f * newScale;
    GET_TRANSFORM(model)->scale.v.z = initData->scale.z * 0.1f * newScale;

    pokemon->collisionOffset.x = initData->scaleNumerator.x / initData->scale.x * newScale;
    pokemon->collisionOffset.y = initData->scaleNumerator.y / initData->scale.y * newScale;
    pokemon->collisionOffset.z = initData->scaleNumerator.z / initData->scale.z * newScale;
    pokemon->collisionRadius = initData->radius * initData->scale.y * newScale;
}

void Pokemon_KickItem(GObj* obj, f32 speed) {
    Pokemon* pokemon = GET_POKEMON(obj);
    Item* targetItem = GET_ITEM(pokemon->interactionTarget); // TODO check it's really item
    DObj* model = obj->data.dobj;
    s32 unused;
    f32 speedZ, speedX;
    f32 yaw;

    yaw = GET_TRANSFORM(model)->rot.f[2];
    speedX = sinf(yaw) * speed;
    speedZ = cosf(yaw) * speed;

    targetItem->velocity.x = speedX;
    targetItem->velocity.y = speed;
    targetItem->velocity.z = speedZ;
}

void Pokemon_MoveXZ(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    f32 yaw = GET_TRANSFORM(model)->rot.f[2];
    f32 speedX = sinf(yaw) * hSpeed;
    f32 speedZ = cosf(yaw) * hSpeed;

    GET_TRANSFORM(model)->pos.v.x += speedX;
    GET_TRANSFORM(model)->pos.v.z += speedZ;
}

void Pokemon_Jump(GObj* obj, f32 maxJumpHeight, f32 acceleration, f32 minJumpSpeed, f32 maxJumpSpeed) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 deltaY = 0.0f;
    f32 jumpVel, accel;
    f32 f26, f28;

    jumpVel = pokemon->jumpVel * 0.033;
    minJumpSpeed *= 0.033;
    maxJumpSpeed *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
            accel = acceleration * 0.033;
            Pokemon_MoveXZ(obj);

            deltaY += jumpVel;
            transform->pos.v.y += jumpVel;
            if (accel != 0.0f) {
                jumpVel += accel;
                if (jumpVel > maxJumpSpeed) {
                    jumpVel = maxJumpSpeed;
                }
                if (jumpVel < minJumpSpeed) {
                    jumpVel = minJumpSpeed;
                }
            }
        }

        if (deltaY >= maxJumpHeight) {
            break;
        }
        ohWait(1);
    }
}

void Pokemon_JumpToHeight(GObj* obj, f32 maxHeight, f32 acceleration, f32 minJumpSpeed, f32 maxJumpSpeed) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 jumpVel, accel, f26, f28;

    jumpVel = pokemon->jumpVel * 0.033;
    minJumpSpeed *= 0.033;
    maxJumpSpeed *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
            accel = acceleration * 0.033;
            Pokemon_MoveXZ(obj);
            transform->pos.v.y += jumpVel;
            if (accel != 0.0f) {
                jumpVel += accel;
                if (jumpVel > maxJumpSpeed) {
                    jumpVel = maxJumpSpeed;
                }
                if (jumpVel < minJumpSpeed) {
                    jumpVel = minJumpSpeed;
                }
            }
        }

        if (transform->pos.v.y >= maxHeight) {
            break;
        }
        ohWait(1);
    }
}

void Pokemon_Fall(GObj* obj, f32 maxFallHeight, f32 acceleration, f32 minFallSpeed, f32 maxFallSpeed) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 fallDistance = 0.0f;
    f32 fallSpeed, accel, f26, f28;

    fallSpeed = pokemon->jumpVel * 0.033;
    minFallSpeed *= 0.033;
    maxFallSpeed *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
            accel = acceleration * 0.033;
            Pokemon_MoveXZ(obj);

            fallDistance -= fallSpeed;
            transform->pos.v.y -= fallSpeed;
            if (accel != 0.0f) {
                fallSpeed += accel;
                if (fallSpeed > maxFallSpeed) {
                    fallSpeed = maxFallSpeed;
                }
                if (fallSpeed < minFallSpeed) {
                    fallSpeed = minFallSpeed;
                }
            }
        }

        if (fallDistance <= -1.0f * maxFallHeight) {
            break;
        }
        ohWait(1);
    }
}

void Pokemon_FallToHeight(GObj* obj, f32 minHeight, f32 acceleration, f32 minFallSpeed, f32 maxFallSpeed) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 fallSpeed, accel, f26, f28;

    fallSpeed = pokemon->jumpVel * 0.033;
    minFallSpeed *= 0.033;
    maxFallSpeed *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
            accel = acceleration * 0.033;
            Pokemon_MoveXZ(obj);
            transform->pos.v.y -= fallSpeed;
            if (accel != 0.0f) {
                fallSpeed += accel;
                if (fallSpeed > maxFallSpeed) {
                    fallSpeed = maxFallSpeed;
                }
                if (fallSpeed < minFallSpeed) {
                    fallSpeed = minFallSpeed;
                }
            }
        }

        if (transform->pos.v.y <= minHeight) {
            break;
        }
        ohWait(1);
    }
}

void Pokemon_JumpAndBounceFromGround(GObj* obj, f32 speed, f32 jumpBackwards, f32 arg3) {
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 velYaw;
    f32 velX,velY,velZ;
    Vec3f vectorUp = { 0, 1, 0 };
    Vec3f velDir;
    f32 currentSpeed;
    f32 temp;

    speed *= 0.033;

    velYaw = GET_TRANSFORM(model)->rot.f[2] + (temp = PI * jumpBackwards); // temp required fo matching
    velYaw += arg3 * (randFloat() * TAU - PI);
    if (velYaw < 0.0f) {
        velYaw += TAU;
    } else if (velYaw > TAU) {
        velYaw -= (s32)(velYaw / TAU) * TAU;
    }

    velX = sinf(velYaw) * speed;
    velY = speed;
    velZ = cosf(velYaw) * speed;

    while (TRUE) {
        getGroundAt(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z, &pokemon->currGround);
        if (GET_TRANSFORM(model)->pos.v.y < pokemon->currGround.height) {
            if (Vec3fAngleDiff(&vectorUp, &pokemon->currGround.normal) < PI / 3.0f) {
                cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_20, obj);
                cmdSendCommand(gObjPlayer, PLAYER_CMD_SHAKE_CAMERA, obj);
                GET_TRANSFORM(model)->pos.v.y = pokemon->currGround.height;
                return;
            }
            velDir.x = velX;
            velDir.y = velY;
            velDir.z = velZ;
            currentSpeed = Vec3fNormalize(&velDir);
            Vec3f_func_8001AC98(&velDir, &pokemon->currGround.normal);
            velX = velDir.x * currentSpeed;
            velY = velDir.y * currentSpeed;
            velZ = velDir.z * currentSpeed;
        }

        velY -= 0.6f;
        GET_TRANSFORM(model)->pos.v.x += velX;
        GET_TRANSFORM(model)->pos.v.y += velY;
        GET_TRANSFORM(model)->pos.v.z += velZ;
        ohWait(1);
    }
}

void Pokemon_FallDownOnGround(GObj* obj, f32 acceleration, s32 arg2) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 jumpVel = pokemon->jumpVel * 0.033;

    while (TRUE) {
        if (arg2) {
            Pokemon_StepWalkInDirection(obj, pokemon->facingYaw, 0);
        } else {
            getGroundAt(transform->pos.v.x, transform->pos.v.z, &pokemon->currGround);
        }

        transform->pos.v.y += jumpVel;
        jumpVel += (f32)(acceleration * 0.033);

        if (jumpVel < 0.0f && transform->pos.v.y < pokemon->currGround.height) {
            break;
        }
        ohWait(1);
    }
    transform->pos.v.y = pokemon->currGround.height;
    pokemon->jumpVel = jumpVel * 1 / 0.033;
}

s32 Pokemon_IsGroundForbidden(f32 x, f32 z, GroundResult* groundResult, f32* forbiddenList) {
    s32 ret = FALSE;

    getGroundAt(x, z, groundResult);
    if (forbiddenList == NULL) {
        switch (groundResult->surfaceType) {
            case SURFACE_TYPE_007F66:
            case SURFACE_TYPE_00FF00:
            case SURFACE_TYPE_337FB2:
            case SURFACE_TYPE_4CCCCC:
            case SURFACE_TYPE_7F6633:
            case SURFACE_TYPE_7F667F:
            case SURFACE_TYPE_FF0000:
            case SURFACE_TYPE_FF4C19:
            case SURFACE_TYPE_FF7FB2:
                ret = TRUE;
                break;
        }
    } else {
        while (*forbiddenList != 0.0f) {
            if (*forbiddenList == groundResult->surfaceType) {
                ret = TRUE;
                break;
            }
            forbiddenList++;
        }
    }
    return ret;
}

s32 Pokemon_StepWalk(GObj* obj, f32 velX, f32 velZ, u32 flags) {
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 nextX = GET_TRANSFORM(model)->pos.v.x + velX;
    f32 nextZ = GET_TRANSFORM(model)->pos.v.z + velZ;
    GroundResult groundResult;
    Vec3f sp38;
    Vec3f collOffset;

    if (Pokemon_IsGroundForbidden(nextX, nextZ, &pokemon->currGround, pokemon->forbiddenGround)) {
        return TRUE;
    }

    collOffset.x = velX; collOffset.y = 0.0f; collOffset.z = velZ;
    Vec3fNormalize(&collOffset);
    Vec3fScale(&collOffset, pokemon->collisionRadius);
    if (Pokemon_IsGroundForbidden(GET_TRANSFORM(model)->pos.v.x + collOffset.x, GET_TRANSFORM(model)->pos.v.z + collOffset.z, &groundResult, pokemon->forbiddenGround)) {
        return TRUE;
    }

    if (flags & WALK_FLAG_10) {
        if (ABS(GET_TRANSFORM(model)->pos.v.y - pokemon->currGround.height) != 0.0f) {
            return TRUE;
        }
    }

    GET_TRANSFORM(model)->pos.v.x = nextX;
    GET_TRANSFORM(model)->pos.v.z = nextZ;
    if (flags & WALK_FLAG_1) {
        GET_TRANSFORM(model)->pos.v.y = pokemon->currGround.height;
    }
    return FALSE;
}

s32 Pokemon_StepWalkInDirection(GObj* obj, f32 direction, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
        f32 hSpeed = pokemon->hSpeed * 0.033;
        f32 velX = sinf(direction) * hSpeed;
        f32 velZ = cosf(direction) * hSpeed;

        if (Pokemon_StepWalk(obj, velX, velZ, flags)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 Pokemon_StepWalkInDirectionFacing(GObj* obj, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
        f32 hSpeed = pokemon->hSpeed * 0.033;
        f32 direction = GET_TRANSFORM(model)->rot.f[2];
        f32 velX = sinf(direction) * hSpeed;
        f32 velZ = cosf(direction) * hSpeed;

        if (Pokemon_StepWalk(obj, velX, velZ, flags)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 Pokemon_Turn(DObj* model, f32 targetYaw, f32 turnSpeed) {
    f32 yaw;
    f32 delta;
    f32 sign;

    yaw = GET_TRANSFORM(model)->rot.f[2];
    yaw -= (s32)(yaw / TAU) * TAU;
    if (yaw < 0.0f) {
        yaw += TAU;
    }

    delta = targetYaw - yaw;
    if (ABS(delta) > turnSpeed) {
        if (ABS(delta) < PI) {
            sign = SIGN(delta);
        } else {
            sign = -SIGN(delta);
        }
        GET_TRANSFORM(model)->rot.f[2] = yaw + sign * turnSpeed;
    } else {
        GET_TRANSFORM(model)->rot.f[2] = targetYaw;
        return TRUE;
    }
    return FALSE;
}

void Pokemon_RunInCircles(GObj* obj, f32 radius, f32 maxModelTurnSpeed, s32 unusedArg) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    f32 nextYaw;
    f32 prevX, prevZ;
    f32 backwardDir;
    f32 realTurnSpeed;
    f32 nextX, nextZ, deltaX, deltaZ;
    f32 currentYaw, deltaYaw, sign;
    Vec3f centerPos;
    s32 unused[2];

    switch (randRange(300) % 3) {
        case 0:
            nextYaw = Pokemon_WrapAngleSum(GET_TRANSFORM(model)->rot.f[2], PI / 6.0f);
            break;
        case 1:
            nextYaw = Pokemon_WrapAngleSum(GET_TRANSFORM(model)->rot.f[2], -PI / 6.0f);
            break;
        case 2:
            nextYaw = Pokemon_WrapAngleSum(GET_TRANSFORM(model)->rot.f[2], PI);
            break;
    }

    centerPos.x = GET_TRANSFORM(model)->pos.v.x + sinf(nextYaw) * radius;
    centerPos.z = GET_TRANSFORM(model)->pos.v.z + cosf(nextYaw) * radius;

    backwardDir = Pokemon_WrapAngleSum(nextYaw, PI);
    realTurnSpeed = hSpeed / radius;

    prevX = GET_TRANSFORM(model)->pos.v.x;
    prevZ = GET_TRANSFORM(model)->pos.v.z;

    while (TRUE) {
        backwardDir = Pokemon_WrapAngleSum(backwardDir, realTurnSpeed);
        nextYaw = Pokemon_WrapAngleSum(backwardDir, PI_2);
        nextX = sinf(backwardDir) * radius + centerPos.x;
        nextZ = cosf(backwardDir) * radius + centerPos.z;
        deltaX = nextX - prevX;
        prevX = nextX;
        deltaZ = nextZ - prevZ;
        prevZ = nextZ;
        if (Pokemon_StepWalk(obj, deltaX, deltaZ, WALK_FLAG_1)) {
            return;
        }

        currentYaw = Pokemon_WrapAngleSum(GET_TRANSFORM(model)->rot.f[2], 0.0f);
        deltaYaw = nextYaw - currentYaw;
        if (ABS(deltaYaw) > maxModelTurnSpeed) {
            if (ABS(deltaYaw) < PI) {
                sign = SIGN(deltaYaw);
            } else {
                sign = -SIGN(deltaYaw);
            }
            GET_TRANSFORM(model)->rot.f[2] = Pokemon_WrapAngleSum(currentYaw, sign * maxModelTurnSpeed);
        } else {
            GET_TRANSFORM(model)->rot.f[2] = nextYaw;
        }
        ohWait(1);
    }
}

void Pokemon_RunInCirclesDefault(GObj* obj, f32 radius) {
    Pokemon_RunInCircles(obj, radius, 0.1f, 1);
}

s32 Pokemon_HearsPokeFlute(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 ret = Items_GetPokeFluteCmd();

    if (pokemon->playerDist > 1400.0f) {
        ret = 0;
    }
    return ret;
}

void Pokemon_TurnToTarget(GObj* obj, f32 turnSpeed, u32 flags) {
    f32 targetDir;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    s32 updateDir = TRUE;
    Vec3f* targetPos;
    Vec3f* currentPos;
    DObj* targetModel;

    if (flags & WALK_FLAG_20) {
        targetModel = gPlayerDObj;
    } else if (pokemon->interactionTarget != NULL) {
        targetModel = pokemon->interactionTarget->data.dobj;
    } else {
        return;
    }

    if (GET_TRANSFORM_BASE(targetModel) != NULL) {
        targetPos = &GET_TRANSFORM(targetModel)->pos.v;
    } else {
        targetPos = &targetModel->position.v;
    }
    currentPos = &GET_TRANSFORM(model)->pos.v;

    while (TRUE) {
        if ((flags & WALK_FLAG_4) && !Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        if (updateDir || (flags & WALK_FLAG_2)) {
            updateDir = FALSE;
            if (flags & WALK_FLAG_40) {
                targetDir = Pokemon_HeadingBetweenPoints(currentPos, targetPos);
            } else {
                targetDir = Pokemon_HeadingBetweenPoints(targetPos, currentPos);
            }
        }

        if (Pokemon_Turn(model, targetDir, turnSpeed) && !(flags & WALK_FLAG_8)) {
            break;
        }
        ohWait(1);
    }
}

void Pokemon_TurnToModelNode(GObj* obj, DObj* modelNode, f32 turnSpeed, u32 flags) {
    f32 targetDir;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    s32 updateDir;
    Vec3f* currentPos;
    Vec3f targetPos;
    Vec3f sp54 = { 0, 0, 0 };

    updateDir = TRUE;
    currentPos = &GET_TRANSFORM(model)->pos.v;

    while (TRUE) {
        func_800A5E98(&targetPos, &sp54, modelNode);
        if ((flags & WALK_FLAG_4) && !Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        if (updateDir || (flags & WALK_FLAG_2)) {
            updateDir = FALSE;
            if (flags & WALK_FLAG_40) {
                targetDir = Pokemon_HeadingBetweenPoints(currentPos, &targetPos);
            } else {
                targetDir = Pokemon_HeadingBetweenPoints(&targetPos, currentPos);
            }
        }

        if (Pokemon_Turn(model, targetDir, turnSpeed) && !(flags & WALK_FLAG_8)) {
            break;
        }
        ohWait(1);
    }
}

void func_80361720_501B30(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, pokemon->hSpeed, 0);
}

void Pokemon_RunToTarget(GObj* obj, f32 targetDistance, f32 turnSpeed, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    DObj* targetModel;
    Vec3f* targetPos;
    s32 updateDir = TRUE;
    f32 distance;
    f32 targetYaw;
    s32 unused[5];
    Vec3f* currentPos;
    Vec3f walkDir;
    s32 unused2;

    while (TRUE) {
        if (updateDir || (flags & WALK_FLAG_2)) {
            updateDir = FALSE;
            if (pokemon->interactionTarget == NULL) {
                break;
            }

            targetModel = pokemon->interactionTarget->data.dobj;
            if (GET_TRANSFORM_BASE(targetModel) != NULL) {
                targetPos = &GET_TRANSFORM(targetModel)->pos.v;
                pokemon->targetPos.x = GET_TRANSFORM(targetModel)->pos.v.x;
                pokemon->targetPos.y = GET_TRANSFORM(targetModel)->pos.v.y;
                pokemon->targetPos.z = GET_TRANSFORM(targetModel)->pos.v.z;
            } else {
                targetPos = &targetModel->position.v;
                pokemon->targetPos.x = targetModel->position.v.x;
                pokemon->targetPos.y = targetModel->position.v.y;
                pokemon->targetPos.z = targetModel->position.v.z;
            }
            currentPos = &GET_TRANSFORM(model)->pos.v;
            targetYaw = Pokemon_GetHeadingVector(targetPos, currentPos, &walkDir, hSpeed);
        }

        if (Pokemon_StepWalk(obj, walkDir.x, walkDir.z, flags | WALK_FLAG_1)) {
            break;
        }

        Pokemon_Turn(model, targetYaw, turnSpeed);
        distance = sqrtf(SQ(pokemon->targetPos.x - currentPos->x) + SQ(pokemon->targetPos.y - currentPos->y) + SQ(pokemon->targetPos.z - currentPos->z));
        if (ABS(distance - targetDistance) < hSpeed || distance < targetDistance) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
            break;
        }

        ohWait(1);
    }
}

void Pokemon_RunAwayFromTarget(GObj* obj, f32 targetDistance, f32 turnSpeed, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    DObj* targetModel;
    Vec3f* targetPos;
    s32 updateDir = TRUE;
    f32 distance;
    f32 targetYaw;
    s32 unused[7];
    Vec3f* currentPos;
    Vec3f walkDir;

    while (TRUE) {
        if (updateDir || (flags & WALK_FLAG_2)) {
            updateDir = FALSE;
            if (pokemon->interactionTarget == NULL) {
                break;
            }

            targetModel = pokemon->interactionTarget->data.dobj;
            if (GET_TRANSFORM_BASE(targetModel) != NULL) {
                targetPos = &GET_TRANSFORM(targetModel)->pos.v;
                pokemon->targetPos.x = GET_TRANSFORM(targetModel)->pos.v.x;
                pokemon->targetPos.y = GET_TRANSFORM(targetModel)->pos.v.y;
                pokemon->targetPos.z = GET_TRANSFORM(targetModel)->pos.v.z;
            } else {
                targetPos = &targetModel->position.v;
                pokemon->targetPos.x = targetModel->position.v.x;
                pokemon->targetPos.y = targetModel->position.v.y;
                pokemon->targetPos.z = targetModel->position.v.z;
            }
            currentPos = &GET_TRANSFORM(model)->pos.v;
            targetYaw = Pokemon_GetHeadingVector(currentPos, targetPos, &walkDir, hSpeed);
        }

        if (Pokemon_StepWalk(obj, walkDir.x, walkDir.z, flags | WALK_FLAG_1)) {
            break;
        }

        Pokemon_Turn(model, targetYaw, turnSpeed);
        distance = sqrtf(SQ(pokemon->targetPos.x - currentPos->x) + SQ(pokemon->targetPos.y - currentPos->y) + SQ(pokemon->targetPos.z - currentPos->z));
        if (distance > targetDistance) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
            break;
        }

        ohWait(1);
    }
}

void Pokemon_RunAwayDefault(GObj* obj, f32 minDistance) {
    Pokemon_RunAwayFromTarget(obj, minDistance, 0.1f, WALK_FLAG_1);
}

void Pokemon_SetTargetPos(GObj* obj, f32 x, f32 z) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->targetPos.x = x;
    pokemon->targetPos.z = z;
}

s32 Pokemon_StepToTargetPos(GObj* obj, f32 turnSpeed, u32 flags) {
    f32 dx, dz;
    f32 velX;
    f32 velZ;
    f32 unused;
    f32 currentYaw;
    f32 targetYaw;
    f32 sign;
    f32 deltaYaw;
    f32 hSpeed;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    hSpeed = pokemon->hSpeed * 0.033;
    dx = pokemon->targetPos.x - GET_TRANSFORM(model)->pos.v.x;
    dz = pokemon->targetPos.z - GET_TRANSFORM(model)->pos.v.z;

    if (SQ(dx) + SQ(dz) < SQ(hSpeed)) {
        pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
        return 1;
    }

    targetYaw = atan2f(dx, dz);
    if (targetYaw < 0.0f) {
        targetYaw += TAU;
    } else if (targetYaw > TAU){
        targetYaw -= (s32)(targetYaw / TAU) * TAU;
    }

    velX = sinf(targetYaw) * hSpeed;
    velZ = cosf(targetYaw) * hSpeed;
    if (Pokemon_StepWalk(obj, velX, velZ, flags)) {
        return 2;
    }

    currentYaw = GET_TRANSFORM(model)->rot.f[2];
    currentYaw -= (s32)(currentYaw / TAU) * TAU;
    if (currentYaw < 0.0f) {
        currentYaw += TAU;
    }

    deltaYaw = targetYaw - currentYaw;
    if (ABS(deltaYaw) > turnSpeed) {
        if (ABS(deltaYaw) < M_PI_F) {
            sign = SIGN(deltaYaw);
        } else {
            sign = -SIGN(deltaYaw);
        }
        GET_TRANSFORM(model)->rot.f[2] = currentYaw + sign * turnSpeed;
    } else {
        GET_TRANSFORM(model)->rot.f[2] = targetYaw;
    }

    dx = pokemon->targetPos.x - GET_TRANSFORM(model)->pos.v.x;
    dz = pokemon->targetPos.z - GET_TRANSFORM(model)->pos.v.z;
    if (SQ(dx) + SQ(dz) < SQ(hSpeed)) {
        pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
        return 1;
    }

    return 0;
}

void Pokemon_RunToTargetPos(GObj* obj, f32 turnSpeed) {
    while (!Pokemon_StepToTargetPos(obj, turnSpeed, WALK_FLAG_1)) {
        ohWait(1);
    }
}

void Pokemon_RunToTargetDefault(GObj* obj, f32 distance) {
    Pokemon_RunToTarget(obj, distance, 0.1f, 0);
}

void Pokemon_TurnToPokeFlute(GObj* obj, f32 turnSpeed) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    DObj* targetModel;
    Vec3f* targetPos;
    Vec3f* currentPos;

    if (pokemon->interactionTarget == NULL) {
        return;
    }

    targetModel = pokemon->interactionTarget->data.dobj;
    if (GET_TRANSFORM_BASE(targetModel) != NULL) {
        targetPos = &GET_TRANSFORM(targetModel)->pos.v;
    } else {
        targetPos = &targetModel->position.v;
    }
    currentPos = &GET_TRANSFORM(model)->pos.v;

    while (TRUE) {
        if (Items_GetPokeFluteCmd() == 0 || pokemon->playerDist > 1400.0f) {
            break;
        }

        Pokemon_Turn(model, Pokemon_HeadingBetweenPoints(targetPos, currentPos), turnSpeed);
        ohWait(1);
    }
}

void func_80361FBC_5023CC(Vec3f* arg0, InterpData* arg1, f32 arg2) {
    switch (arg1->type) {
        case 1:
            func_8001FCA4(arg0, arg1, arg2);
            break;
        case 2:
            func_8001FCA4(arg0, arg1, arg2);
            break;
        case 3:
            func_8001FCA4(arg0, arg1, arg2);
            break;
        case 0:
            func_8001FCA4(arg0, arg1, arg2);
            break;
    }
}

void Pokemon_ResetPathPos(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    WorldBlock* block = getCurrentWorldBlock();

    GET_TRANSFORM(model)->pos.v.x = -(block->descriptor->worldPos.x * 100.0f);
    GET_TRANSFORM(model)->pos.v.y = -(block->descriptor->worldPos.y * 100.0f);
    GET_TRANSFORM(model)->pos.v.z = -(block->descriptor->worldPos.z * 100.0f);
}

void Pokemon_FollowPath(GObj* obj, f32 startParam, f32 endParam, f32 speedMult, f32 turnSpeed, u32 flags) {
    DObj* model = obj->data.dobj;
    Vec3f worldPos = { 0, 0, 0 };
    Pokemon* pokemon = GET_POKEMON(obj);
    Vec3f sp70;
    f32 f2;
    f32 paramStep;


    pokemon->pathParam = startParam;

    if (pokemon->path == NULL) {
        while (TRUE) {
            ohWait(1);
        }
    }

    paramStep = 1.0f / pokemon->path->unk_0C * speedMult;

    while (TRUE) {
        if (!(pokemon->pathParam >= 0.0f) || !(pokemon->pathParam <= 1.0f)) {
            while (TRUE) {
                ohWait(1);
            }
        }
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_ENDED)) {
            GET_TRANSFORM(model)->pos.v.x -= worldPos.x * 100.0f;
            GET_TRANSFORM(model)->pos.v.z -= worldPos.z * 100.0f;
            if (!(flags & WALK_FLAG_10)) {
                if (flags & WALK_FLAG_1) {
                    GET_TRANSFORM(model)->pos.v.y -= worldPos.y;
                } else {
                    GET_TRANSFORM(model)->pos.v.y -= worldPos.y * 100.0f;
                }
            }

            if (flags & (WALK_FLAG_80 | WALK_FLAG_2)) {
                func_8001FCE8(&sp70, pokemon->path, pokemon->pathParam);
                f2 = atan2f(sp70.x, sp70.z);
                if (f2 < 0.0f) {
                    f2 += TAU;
                } else if (f2 > TAU) {
                    f2 -= (s32)(f2 / TAU) * TAU;
                }
                if (flags & WALK_FLAG_80) {
                    Pokemon_Turn(model, f2, turnSpeed);
                } else {
                    GET_TRANSFORM(model)->rot.f[2] = f2;
                }
            }

            func_80361FBC_5023CC(&worldPos, pokemon->path, pokemon->pathParam);

            GET_TRANSFORM(model)->pos.v.x += worldPos.x * 100.0f;
            GET_TRANSFORM(model)->pos.v.z += worldPos.z * 100.0f;
            if (!(flags & WALK_FLAG_10)) {
                if (flags & WALK_FLAG_1) {
                    worldPos.y = Pokemon_GetGroundAt(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z);
                    GET_TRANSFORM(model)->pos.v.y += worldPos.y;
                    if (1) { } if (1) { } // TODO fake match
                } else {
                    GET_TRANSFORM(model)->pos.v.y += worldPos.y * 100.0f;
                }
            }

            pokemon->pathParam += paramStep;
            if (endParam > 0.0f && endParam <= pokemon->pathParam) {
                return;
            }

            if (pokemon->pathParam > 1.0f){
                pokemon->pathParam -= 1.0f;
            }
        }
        ohWait(1);
    }
}

f32 func_803623F4_502804(f32 x, f32 z) {
    return Pokemon_GetGroundAt(x, z);
}

void func_80362414_502824(Pokemon* obj, EggStruct* egg, f32 arg2) {
    obj->eggGeo = egg;
    func_800AB1F8(egg);
    while (func_800AB138(egg, arg2)) {
        ohWait(1);
    }
}

void Pokemon_AnimationCallback(DObj* model, s32 param, f32 value) {
    GObj* obj = model->obj;
    Pokemon* pokemon = GET_POKEMON(obj);
    AnimationHeader* animHeader = pokemon->animHeader;

    switch (param) {
        case -1:
            pokemon->loopCount++;
            break;
        case -2:
            pokemon->loopCount++;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
            if ((s32)model->parent == 1) { // toplevel
                s32 val = value;
                if (val != 0) {
                    if (animHeader->ids != NULL) {
                        func_8035F1D0_4FF5E0(obj, param, animHeader->ids[val - 1]);
                    }
                } else {
                    func_80366864_506C74(obj, param);
                }
            } else if (pokemon->tangible) {
                s32 val = value;
                if (val > 0 && D_80382D10_523120 != NULL && D_80382D14_523124 != NULL) {
                    UnkBrassLynx* unk = func_800A6C48(param, val - 1);
                    if (unk != NULL) {
                        unk->unk_48 = model;
                    }
                }
            }
            break;
    }
}

void Pokemon_HandleCommand(GObjCmdData cmdData) {
    InteractionHandler* transitionGraph;
    f32 distance;
    s32 i;
    Pokemon* pokemon;
    GObjFunc stateProc;
    GObjFunc auxProc;

    pokemon = GET_POKEMON(omCurrentObject);
    stateProc = NULL;
    auxProc = NULL;
    transitionGraph = pokemon->transitionGraph;

    switch(cmdData.cmd) {
        case POKEMON_CMD_14:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == cmdData.cmd) {
                    distance = Pokemon_GetDistance(omCurrentObject, cmdData.source);
                    if (distance < 600.0f) {
                        pokemon->apple = cmdData.source;
                        pokemon->interactionDist = distance;
                        pokemon->interactionTarget = cmdData.source;
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                    }
                    break;
                }
            }
            break;
        case POKEMON_CMD_10:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == cmdData.cmd) {
                    distance = Pokemon_GetDistance(omCurrentObject, cmdData.source);
                    if (distance < 150.0) {
                        pokemon->apple = cmdData.source;
                        pokemon->interactionDist = distance;
                        pokemon->interactionTarget = cmdData.source;
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                    }
                    break;
                }
            }
            break;
        case POKEMON_CMD_9:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_9) {
                    pokemon->interactionTarget = cmdData.source;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
        case POKEMON_CMD_13:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_13) {
                    pokemon->interactionTarget = cmdData.source;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
        case POKEMON_CMD_8:
        case POKEMON_CMD_12:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == cmdData.cmd) {
                    pokemon->interactionTarget = cmdData.source;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
        case POKEMON_CMD_21:
            if (pokemon->apple == cmdData.source) {
                pokemon->apple = NULL;
                if (transitionGraph == NULL) {
                    break;
                }
                for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                    if (transitionGraph[i].cmd == POKEMON_CMD_21) {
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                        break;
                    }
                }
            }
            break;
        case POKEMON_CMD_18:
            if (pokemon->playerDist < 400.0f) {
                if (transitionGraph == NULL) {
                    break;
                }
                for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                    if (transitionGraph[i].cmd == POKEMON_CMD_18) {
                        pokemon->interactionTarget = cmdData.source;
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                        break;
                    }
                }
            }
            break;
        case POKEMON_CMD_24:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_24) {
                    pokemon->interactionTarget = cmdData.source;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
        case POKEMON_CMD_19:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_19) {
                    if (getCurrentWorldBlock() == pokemon->baseBlock) {
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                    }
                }
            }
            break;
        case POKEMON_CMD_20:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_20) {
                    distance = Pokemon_GetDistance(omCurrentObject, cmdData.source);
                    if (distance < 600.0f) {
                        pokemon->interactionTarget = cmdData.source;
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                    }
                    break;
                }
            }
            break;
        case POKEMON_CMD_22:
            if (pokemon->interactionTarget == cmdData.source) {
                pokemon->interactionTarget = NULL;
                if (transitionGraph == NULL) {
                    break;
                }
                for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                    if (transitionGraph[i].cmd == POKEMON_CMD_22) {
                        stateProc = transitionGraph[i].state;
                        auxProc = transitionGraph[i].aux;
                        break;
                    }
                }
            }
            break;
        case POKEMON_CMD_26:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_26) {
                    pokemon->interactionTarget = cmdData.source;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
        case POKEMON_CMD_27:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == POKEMON_CMD_27) {
                    pokemon->interactionTarget = cmdData.source;
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
        case POKEMON_CMD_28:
        case POKEMON_CMD_29:
        case POKEMON_CMD_30:
        case POKEMON_CMD_31:
        case POKEMON_CMD_32:
        case POKEMON_CMD_33:
        case POKEMON_CMD_34:
        case POKEMON_CMD_35:
        case POKEMON_CMD_36:
        case POKEMON_CMD_37:
        case POKEMON_CMD_38:
        case POKEMON_CMD_39:
        case POKEMON_CMD_40:
        case POKEMON_CMD_41:
        case POKEMON_CMD_42:
        case POKEMON_CMD_43:
        case POKEMON_CMD_44:
        case POKEMON_CMD_45:
        case POKEMON_CMD_46:
        case POKEMON_CMD_47:
        case POKEMON_CMD_48:
        case POKEMON_CMD_49:
        case POKEMON_CMD_50:
        case POKEMON_CMD_51:
        case POKEMON_CMD_52:
        case POKEMON_CMD_53:
        case POKEMON_CMD_54:
        case POKEMON_CMD_55:
        case POKEMON_CMD_56:
        case POKEMON_CMD_57:
            if (transitionGraph == NULL) {
                break;
            }
            for (i = 0; transitionGraph[i].cmd != POKEMON_CMD_58; i++) {
                if (transitionGraph[i].cmd == cmdData.cmd) {
                    if (cmdData.source != NULL) {
                        pokemon->interactionTarget = cmdData.source;
                    }
                    stateProc = transitionGraph[i].state;
                    auxProc = transitionGraph[i].aux;
                    break;
                }
            }
            break;
    }

    if (auxProc != NULL) {
        Pokemon_StartAuxProc(omCurrentObject, auxProc);
    }
    if (stateProc != NULL) {
        Pokemon_SetState(omCurrentObject, stateProc);
    }
    if (!func_80353D68_4F4178()) {
        ohPauseObjectProcesses(omCurrentObject);
    }
}

void Pokemon_Update(GObj* obj) {
    Pokemon* pokemon;
    if (obj == NULL) {
        return;
    }

    pokemon = GET_POKEMON(obj);
    if (getIsPaused() == 0 && !(pokemon->processFlags & POKEMON_PROCESS_FLAG_4)) {
        if (pokemon->counter > 0) {
            pokemon->counter--;
            if (pokemon->counter <= 0) {
                pokemon->processFlags |= POKEMON_PROCESS_FLAG_4;
            }
        }
    }
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_ANIMATION_ENDED)) {
        if (pokemon->loopCount >= pokemon->pokemonLoopTarget) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_ANIMATION_ENDED;
        } else if (pokemon->lastAnimationFrame > 0.0f && pokemon->lastAnimationFrame < obj->animationTime) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_ANIMATION_ENDED;
        }
    }
    cmdProcessCommands(Pokemon_HandleCommand);
}

void Pokemon_ChangeBlockAndRemove(GObj* obj, f32 prevBlockX, f32 prevBlockY, f32 prevBlockZ, f32 currBlockX, f32 currBlockY, f32 currBlockZ) {
    Pokemon* pokemon = GET_POKEMON(obj);
    WorldBlock* block;

    pokemonChangeBlockOnGround(obj, prevBlockX, prevBlockY, prevBlockZ, currBlockX, currBlockY, currBlockZ);
    if (getCurrentWorldBlock()->index > (block = pokemon->baseBlock)->index && pokemon->playerDist > 10000.0f) {
        Pokemon_RunCleanup(obj);
    }
}

GObj* Pokemon_SpawnDlLink4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = Pokemon_Spawn(objID, id, block, blockB, spawn, initData);
    omMoveGObjDL(pokemonObj, DL_LINK_4, 0x80000000);
    return pokemonObj;
}

GObj* Pokemon_SpawnOnGroundDlLink4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, initData);
    omMoveGObjDL(pokemonObj, DL_LINK_4, 0x80000000);
    return pokemonObj;
}

GObj* Pokemon_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, initData);
    GET_TRANSFORM(pokemonObj->data.dobj)->pos.v.y = spawn->translation.y * 100.0f + (block->descriptor->worldPos.y - blockB->descriptor->worldPos.y) * 100.0f;
    return pokemonObj;
}

GObj* Pokemon_SpawnOnGround(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    f32 blockBX, blockBY, blockBZ;
    s32 unused;
    GObj* pokemonObj;
    DObj* model;
    PokemonTransformBase* matrixStore;
    Pokemon* pokemon;

    if (block == NULL || block->descriptor == NULL) {
        return NULL;
    }

    blockBX = blockB->descriptor->worldPos.x;
    blockBZ = blockB->descriptor->worldPos.z;

    pokemonObj = omAddGObj(objID, Pokemon_Update, LINK_POKEMON, 0x80000000);

    if (initData->fnRender != NULL && initData->tree != NULL) {
        omLinkGObjDL(pokemonObj, initData->fnRender, DL_LINK_5, 0x80000000, -1);
        if (initData->flags & POKEMON_FLAG_10) {
            anim_func_80010230(pokemonObj, initData->tree, initData->textures, NULL, initData->matrix1, initData->matrix2, initData->matrix3);
        } else {
            anim_func_80010230(pokemonObj, initData->tree, initData->textures, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
        }
        model = pokemonObj->data.dobj;
    } else {
        model = omGObjAddDObj(pokemonObj, NULL);
        if (initData->flags & POKEMON_FLAG_10) {
            anim_func_8000FDA0(model, initData->matrix1, initData->matrix2, initData->matrix3);
        } else {
            anim_func_8000FDA0(model, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
        }
    }

    matrixStore = Pokemon_GetTransform();
    matrixStore->kinds[0] = 1;
    matrixStore->kinds[1] = 2;
    matrixStore->kinds[2] = 3;
    model->unk_4C = (struct DObjDynamicStore*)matrixStore;
    omDObjAddMtx(model, MTX_TYPE_63, 0, 0);

    GET_TRANSFORM(model)->pos.v.x = spawn->translation.x * 100.0f + (block->descriptor->worldPos.x - blockBX) * 100.0f;
    GET_TRANSFORM(model)->pos.v.z = spawn->translation.z * 100.0f + (block->descriptor->worldPos.z - blockBZ) * 100.0f;
    GET_TRANSFORM(model)->pos.v.y = Pokemon_GetGroundAt(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z);
    GET_TRANSFORM(model)->rot.f[1] = spawn->euler.x;
    GET_TRANSFORM(model)->rot.f[2] = spawn->euler.y;
    GET_TRANSFORM(model)->rot.f[3] = spawn->euler.z;
    GET_TRANSFORM(model)->scale.v.x = initData->scale.x * 0.1f;
    GET_TRANSFORM(model)->scale.v.y = initData->scale.y * 0.1f;
    GET_TRANSFORM(model)->scale.v.z = initData->scale.z * 0.1f;

    pokemonObj->userData = pokemon = Pokemon_GetPokemonData();
    pokemon->initData = initData;
    pokemon->pos1.x = GET_TRANSFORM(model)->pos.v.x;
    pokemon->pos1.y = GET_TRANSFORM(model)->pos.v.y;
    pokemon->pos1.z = GET_TRANSFORM(model)->pos.v.z;
    pokemon->targetPos.x = GET_TRANSFORM(model)->pos.v.x;
    pokemon->targetPos.y = GET_TRANSFORM(model)->pos.v.y;
    pokemon->targetPos.z = GET_TRANSFORM(model)->pos.v.z;
    pokemon->euler.x = GET_TRANSFORM(model)->rot.f[1];
    pokemon->euler.y = GET_TRANSFORM(model)->rot.f[2];
    pokemon->euler.z = GET_TRANSFORM(model)->rot.f[3];
    pokemon->collisionOffset.x = initData->scaleNumerator.x / initData->scale.x;
    pokemon->collisionOffset.y = initData->scaleNumerator.y / initData->scale.y;
    pokemon->collisionOffset.z = initData->scaleNumerator.z / initData->scale.z;
    pokemon->collisionRadius = initData->radius * initData->scale.y;
    pokemon->flags = initData->flags;
    pokemon->id = id;
    pokemon->tangible = TRUE;
    pokemon->animSetup = initData->animSetup;
    pokemon->baseBlock = block;
    pokemon->forbiddenGround = NULL;
    pokemon->loopCount = 0;
    pokemon->playerDist = FLOAT_MAX;
    pokemon->interactionDist = FLOAT_MAX;
    pokemonObj->fnAnimCallback = Pokemon_AnimationCallback;
    pokemon->modelAnims = NULL;
    omCreateProcess(pokemonObj, animUpdateModelTreeAnimation, 1, 3);
    Pokemon_ForceAnimation(pokemonObj, initData->animSetup->animations);
    omCreateProcess(pokemonObj, Pokemon_CalcDistanceToPlayer, 1, 8);

    pokemon->stateProc = omCreateProcess(pokemonObj, initData->animSetup->initialState, initData->animSetup->kind, 7);
    pokemon->unk_18 = -1;
    pokemon->processFlags = 0;
    pokemon->counter = 0;
    pokemon->pathProc = NULL;
    pokemon->transitionGraph = NULL;
    pokemon->pokemonLoopTarget = 0;
    pokemon->lastAnimationFrame = 0.0f;
    pokemon->jumpVel = 0.0f;
    pokemon->hSpeed = 0.0f;
    pokemon->facingYaw = 0.0f;
    pokemon->transitionGraph = initData->animSetup->transitionGraph;
    pokemon->unk_E4 = 255;
    pokemon->path = spawn->path;
    pokemon->pathParam = 0.0f;
    pokemon->behavior = spawn->behavior;
    pokemon->eggGeo = NULL;
    pokemon->unk_10C = 0;
    pokemon->field_0x10e = 0;
    pokemon->playerDist = FLOAT_MAX;
    Pokemon_LinkObject(pokemonObj);
    return pokemonObj;
}

void func_8036334C_50375C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    Mtx4f sp78;
    Mtx4f sp38;

    hal_rotate_rpy_translate_f(sp78, GET_TRANSFORM(model)->pos.v.x,
                                     GET_TRANSFORM(model)->pos.v.y,
                                     GET_TRANSFORM(model)->pos.v.z,
                                     GET_TRANSFORM(model)->rot.f[1],
                                     GET_TRANSFORM(model)->rot.f[2],
                                     GET_TRANSFORM(model)->rot.f[3]);
    if (pokemon->flags & POKEMON_FLAG_1) {
        hal_translate_f(sp38, pokemon->collisionOffset.x + model->position.v.x * GET_TRANSFORM(model)->scale.v.x,
                              pokemon->collisionOffset.y + model->position.v.y * GET_TRANSFORM(model)->scale.v.y,
                              pokemon->collisionOffset.z + model->position.v.z * GET_TRANSFORM(model)->scale.v.z);
    } else {
        hal_translate_f(sp38, pokemon->collisionOffset.x, pokemon->collisionOffset.y, pokemon->collisionOffset.z);
    }
    guMtxCatF(sp38, sp78, sp78);

    pokemon->collPosition.x = sp78[3][0];
    pokemon->collPosition.y = sp78[3][1];
    pokemon->collPosition.z = sp78[3][2];
}

void func_8036345C_50386C(GObj* arg0) {
    PokemonObjectListEntry* entry;
    PokemonObjectListEntry* entry2;
    Pokemon* pokemon;
    Pokemon* pokemon2;
    Vec3f sp84;
    Vec3f sp78;
    Vec3f sp6C;
    f32 f20;
    s32 unused[2];

    for (entry = D_803B0C08_551018; entry != NULL; entry = entry->next) {
        func_8036334C_50375C(entry->obj);
        pokemon = GET_POKEMON(entry->obj);
        pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_80;
    }

    for (entry = D_803B0C08_551018; entry != NULL; entry = entry->next) {
        pokemon = GET_POKEMON(entry->obj);
        if (pokemon->flags & POKEMON_FLAG_200) {
            sp84.x = pokemon->collPosition.x;
            sp84.y = pokemon->collPosition.y;
            sp84.z = pokemon->collPosition.z;

            for (entry2 = entry->next; entry2 != NULL; entry2 = entry2->next) {
                pokemon2 = GET_POKEMON(entry2->obj);
                if (pokemon2->flags & POKEMON_FLAG_200) {
                    sp78.x = pokemon2->collPosition.x;
                    sp78.y = pokemon2->collPosition.y;
                    sp78.z = pokemon2->collPosition.z;
                    f20 = Vec3fDirection(&sp6C, &sp84, &sp78) - (pokemon->collisionRadius + pokemon2->collisionRadius);
                    if (f20 < 0.0f) {
                        if (f20 < 0.0f) {
                            f20 = -f20;
                        }

                        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_80)) {
                            pokemon->processFlags |= POKEMON_PROCESS_FLAG_80;
                            cmdSendCommand(entry->obj, POKEMON_CMD_26, entry2->obj);
                        }

                        if (!(pokemon2->processFlags & POKEMON_PROCESS_FLAG_80)) {
                            pokemon2->processFlags |= POKEMON_PROCESS_FLAG_80;
                            cmdSendCommand(entry2->obj, POKEMON_CMD_26, entry->obj);
                        }

                        // BUG same pokemon checked twice
                        if ((pokemon2->flags & POKEMON_FLAG_800) && (pokemon2->flags & POKEMON_FLAG_800)) {
                            Pokemon_GetHeadingVector(&sp84, &sp78, &sp6C, f20 / 2);
                            Pokemon_StepWalk(entry->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry->obj);

                            Pokemon_GetHeadingVector(&sp78, &sp84, &sp6C, f20 / 2);
                            Pokemon_StepWalk(entry2->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry2->obj);
                        } else if (pokemon2->flags & POKEMON_FLAG_800) {
                            Pokemon_GetHeadingVector(&sp78, &sp84, &sp6C, f20);
                            Pokemon_StepWalk(entry2->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry2->obj);
                        } else if (pokemon->flags & POKEMON_FLAG_800) {
                            Pokemon_GetHeadingVector(&sp84, &sp78, &sp6C, f20);
                            Pokemon_StepWalk(entry->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry->obj);
                        }
                    }
                }
            }
        }
        if (FALSE) { } // required to match
    }
}

void Pokemons_Init(void) {
    s32 i;

    D_803B0C08_551018 = NULL;
    D_803B0C0C_55101C = NULL;
    D_803B0C10_551020 = D_803B0A28_550E38;

    for (i = 0; i < ARRAY_COUNT(D_803B0A28_550E38); i++) {
        if (i == 0) {
            D_803B0A28_550E38[i].prev = NULL;
        } else {
            D_803B0A28_550E38[i].prev = &D_803B0A28_550E38[i - 1];
        }
        if (i == ARRAY_COUNT(D_803B0A28_550E38) - 1) {
            D_803B0A28_550E38[i].next = NULL;
        } else {
            D_803B0A28_550E38[i].next = &D_803B0A28_550E38[i + 1];
        }
        D_803B0A28_550E38[i].obj = NULL;
    }

    omCreateProcess(ohFindByLinkAndId(LINK_0, OBJID_0), func_8036345C_50386C, 1, 2);
    Pokemon_InitTransforms();
    Pokemon_InitPokemonsData();
    Pokemon_InitItems();
}
