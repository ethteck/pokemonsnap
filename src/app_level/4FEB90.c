#include "common.h"
#include "world/world.h"
#include "app_level.h"

extern DObj* gPlayerDObj;
extern GObj* gPokemonInFocus;

extern Vec3f D_8038A430_52A840;
extern Vec3f D_8038A43C_52A84C;

void pokemonChangeBlockOnGround(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

void func_800A5E98(Vec3f*, Vec3f*, DObj*);
void func_800AB1F8(eggStruct*);
s32 func_800AB138(eggStruct* arg0, f32 arg1);

void deletePokemon(GObj* pokemonObj);
void func_800A716C(GObj*);
u8 getIsPaused(void);
void func_80366864_506C74(GObj*, u8);
void func_803667C0_506BD0(GObj*, UNK_TYPE, UNK_TYPE);
s32 func_8036381C_503C2C(void);
s32 func_80360E78_501288(GObj* arg0, f32 arg1, u32 arg2);

typedef struct SomeListEntry {
    /* 0x00 */ struct SomeListEntry* prev;
    /* 0x04 */ struct SomeListEntry* next;
    /* 0x08 */ GObj* obj;
} SomeListEntry; // size ?

typedef struct UnkHeatherLynx {
    /* 0x00 */ struct UnkHeatherLynx* next;
    /* 0x04 */ PokemonTransformBase* unk_04;
} UnkHeatherLynx; // size 0x8

typedef struct UnkHeatherLynx2 {
    /* 0x00 */ struct UnkHeatherLynx2* next;
    /* 0x04 */ Pokemon* unk_04;
} UnkHeatherLynx2; // size 0x8

typedef struct UnkHeatherLynx3 {
    /* 0x00 */ struct UnkHeatherLynx3* next;
    /* 0x04 */ Item* unk_04;
} UnkHeatherLynx3; // size 0x8

extern SomeListEntry* D_803B0C08_551018;
extern SomeListEntry* D_803B0C0C_55101C;
extern SomeListEntry* D_803B0C10_551020;
extern UnkHeatherLynx D_803B0C18_551028[40];
extern UnkHeatherLynx* D_803B0D58_551168;
extern UnkHeatherLynx* D_803B0D5C_55116C;
extern UnkHeatherLynx2 D_803B0D60_551170[40];
extern UnkHeatherLynx2* D_803B0EA0_5512B0;
extern UnkHeatherLynx2* D_803B0EA4_5512B4;
extern UnkHeatherLynx3 D_803B0EA8_5512B8[20];
extern UnkHeatherLynx3* D_803B0F48_551358;
extern UnkHeatherLynx3* D_803B0F4C_55135C;

void func_8035E780_4FEB90(GObj* arg0) {
    SomeListEntry* temp_v1 = D_803B0C10_551020;

    if (D_803B0C10_551020 == NULL) {
        return;
    }
        
    D_803B0C10_551020 = D_803B0C10_551020->next;

    temp_v1->prev = D_803B0C0C_55101C;
    temp_v1->next = 0;
    
    if (temp_v1->prev != NULL) {
        temp_v1->prev->next = D_803B0C0C_55101C = temp_v1;
    } else {
        D_803B0C08_551018 = D_803B0C0C_55101C = temp_v1;
    }
    temp_v1->obj = arg0;
}

void func_8035E7DC_4FEBEC(GObj* obj) {
    SomeListEntry* entry = D_803B0C08_551018;

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
    SomeListEntry* entry = D_803B0C08_551018;

    while (entry != NULL) {
        if (entry->obj == obj) {
            return TRUE;
        }
        entry = entry->next;
    }
    return FALSE;
}

void func_8035E8A4_4FECB4(void) {
    s32 i;

    for (i = 0; i < 39; i++) {
        D_803B0C18_551028[i].next = &D_803B0C18_551028[i+1];
    }
    D_803B0C18_551028[i].next = NULL;

    D_803B0D58_551168 = NULL;
    D_803B0D5C_55116C = D_803B0C18_551028;
}

PokemonTransformBase* func_8035E944_4FED54(void) {
    PokemonTransformBase* ret;
    UnkHeatherLynx* v0 = D_803B0D58_551168;

    if (v0 != NULL) {
        ret = v0->unk_04;
        D_803B0D58_551168 = v0->next;
        v0->next = D_803B0D5C_55116C;
        D_803B0D5C_55116C = v0;
    } else {
        ret = gtlMalloc(sizeof(PokemonTransformBase), 0x40);
    }
    return ret;
}

void func_8035E9A4_4FEDB4(PokemonTransformBase* arg0) {
    UnkHeatherLynx* temp_v0;

    temp_v0 = D_803B0D5C_55116C;
    if (temp_v0 != NULL) {
        temp_v0->unk_04 = arg0;
        D_803B0D5C_55116C = temp_v0->next;

        temp_v0->next = D_803B0D58_551168;
        D_803B0D58_551168 = temp_v0;
    }
}

void func_8035E9E0_4FEDF0(void) {
    s32 i;

    for (i = 0; i < 39; i++) {
        D_803B0D60_551170[i].next = &D_803B0D60_551170[i+1];
    }
    D_803B0D60_551170[i].next = NULL;

    D_803B0EA0_5512B0 = NULL;
    D_803B0EA4_5512B4 = D_803B0D60_551170;
}

Pokemon* func_8035EA80_4FEE90(void) {
    Pokemon* ret;
    UnkHeatherLynx2* v0 = D_803B0EA0_5512B0;

    if (v0 != NULL) {
        ret = v0->unk_04;
        D_803B0EA0_5512B0 = v0->next;
        v0->next = D_803B0EA4_5512B4;
        D_803B0EA4_5512B4 = v0;
    } else {
        ret = gtlMalloc(sizeof(Pokemon), 0x40);
    }
    return ret;
}

void func_8035EAE0_4FEEF0(Pokemon* arg0) {
    UnkHeatherLynx2* temp_v0;

    temp_v0 = D_803B0EA4_5512B4;
    if (temp_v0 != NULL) {
        temp_v0->unk_04 = arg0;
        D_803B0EA4_5512B4 = temp_v0->next;

        temp_v0->next = D_803B0EA0_5512B0;
        D_803B0EA0_5512B0 = temp_v0;
    }
}

void func_8035EB1C_4FEF2C(void) {
    s32 i;

    for (i = 0; i < 19; i++) {
        D_803B0EA8_5512B8[i].next = &D_803B0EA8_5512B8[i+1];
    }
    D_803B0EA8_5512B8[i].next = NULL;

    D_803B0F48_551358 = NULL;
    D_803B0F4C_55135C = D_803B0EA8_5512B8;
}

Item* func_8035EBBC_4FEFCC(void) {
    Item* ret;
    UnkHeatherLynx3* v0 = D_803B0F48_551358;

    if (v0 != NULL) {
        ret = v0->unk_04;
        D_803B0F48_551358 = v0->next;
        v0->next = D_803B0F4C_55135C;
        D_803B0F4C_55135C = v0;
    } else {
        ret = gtlMalloc(sizeof(Item), 0x40);
    }
    return ret;
}

void func_8035EC1C_4FF02C(Item* arg0) {
    UnkHeatherLynx3* temp_v0;

    temp_v0 = D_803B0F4C_55135C;
    if (temp_v0 != NULL) {
        temp_v0->unk_04 = arg0;
        D_803B0F4C_55135C = temp_v0->next;

        temp_v0->next = D_803B0F48_551358;
        D_803B0F48_551358 = temp_v0;
    }
}

void updatePokemonState(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->interactionProc;

    pokemon->transitionGraph = NULL;
    if (func != NULL) {
        pokemon->interactionProc = omCreateProcess(obj, func, 0, 7);
    } else {
        pokemon->interactionProc = NULL;
    }
    omEndProcess(oldProc);
}

void weightedRandomStaightTransition(GObj* obj, randomTransition* arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->interactionProc;
    s32 sumWeight = 0;
    s32 i;
    s32 randValue;

    pokemon->transitionGraph = NULL;

    for (i = 0; arg1[i].func != NULL; i++) {
        sumWeight += arg1[i].value;
    }
    randValue = randRange(sumWeight);

    sumWeight = arg1[0].value;
    for (i = 0; sumWeight <= randValue; i++) {
        sumWeight += arg1[i+1].value;
    }

    if (arg1[i].func != NULL) {
        pokemon->interactionProc = omCreateProcess(obj, arg1[i].func, 0, 7);
        omEndProcess(oldProc);
    }    
}

void func_8035ED90_4FF1A0(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_8;
    omCreateProcess(obj, func, 0, 6);
}

void func_8035EDC8_4FF1D8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_8;
    omEndProcess(NULL);
}

void runPathProcess(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->pathProcess;

    if (func != NULL) {
        pokemon->pathProcess = omCreateProcess(obj, func, 0, 5);
        pokemon->processFlags &= ~(POKEMON_PROCESS_FLAG_2 | POKEMON_PROCESS_FLAG_10 | POKEMON_PROCESS_FLAG_20);
    } else {
        pokemon->pathProcess = NULL;
    }
    if (oldProc != NULL) {
        omEndProcess(oldProc);
    }
}

void func_8035EE64_4FF274(MObj* mobj, Texture* arg1) {
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

void func_8035EF2C_4FF33C(GObj* obj, Texture*** arg1) {
    DObj* dobj = obj->data.dobj;
    MObj* mobj;
    Texture** csr;

    while (dobj != NULL) {
        mobj = dobj->mobjList;
        if (arg1 != NULL) {
            if (*arg1 != NULL) {
                csr = *arg1;
                while (*csr != NULL) {
                    func_8035EE64_4FF274(mobj, *csr);
                    csr++;
                    mobj = mobj->next;
                }
            }
            arg1++;
        }
        dobj = animModelTreeNextNode(dobj);
    }
}

void pokemonUVStuff(GObj* obj, AnimationHeader* header, f32 startTime, s32 force) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (header != NULL) {
        if (pokemon->animators == NULL) {
            ohResumeProcessByFunction(obj, animUpdateModelTreeAnimation);
        }

        if (pokemon->animators != header->animList || force) {
            func_80366864_506C74(obj, 0);
            anim_func_8000F8E4(obj, header->animList, startTime, pokemon->initData->tree);
            pokemon->animators = header->animList;
        }

        if (header->matAnims != NULL) {
            if (pokemon->matAnims != header->matAnims || force) {
                animSetModelTreeTextureAnimation(obj, header->matAnims, 0.0f);
                pokemon->matAnims = header->matAnims;
            }
            animSetModelAndTextureAnimationSpeed(obj, header->speed);
        } else {
            if (pokemon->initData->textures != NULL) {
                func_8035EF2C_4FF33C(obj, pokemon->initData->textures);
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
        pokemon->animators = NULL;
    }

    pokemon->loopCount = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1;
    pokemon->pokemonLoopTarget = 1;
    pokemon->lastAnimationFrame = 0.0f;
}

void setPokemonAnimation(GObj* obj, AnimationHeader* header) {
    pokemonUVStuff(obj, header, 0, FALSE);
}

void forcePokemonAnimation(GObj* obj, AnimationHeader* header) {
    pokemonUVStuff(obj, header, 0, TRUE);
}

void func_8035F180_4FF590(GObj* obj, AnimationHeader* header, f32 time) {
    pokemonUVStuff(obj, header, time, FALSE);
}

void func_8035F1A8_4FF5B8(GObj* obj, AnimationHeader* header, f32 time) {
    pokemonUVStuff(obj, header, time, TRUE);
}

void func_8035F1D0_4FF5E0(GObj* arg0, u8 arg1, s32 arg2) {
    if (func_8036381C_503C2C() != 0 && !(arg0->flags & GOBJ_FLAG_HIDDEN)) {
        func_803667C0_506BD0(arg0, arg1, arg2);
    }
}

f32 func_8035F21C_4FF62C(f32 arg0, f32 arg1) {
    GroundResult sp1C;

    if (getGroundAt(arg0, arg1, &sp1C) != 0) {
        return sp1C.height;
    }
    return 0.0f;
}

f32 func_8035F24C_4FF65C(f32 arg0, f32 arg1) {
    f32 sum = arg0 + arg1;
    f32 ret = sum - (s32)(sum / TAU) * TAU;

    if (ret < 0.0f) {
        ret += TAU;
    }
    return ret;
}

f32 func_8035F2A4_4FF6B4(GObj* arg0, GObj* arg1) {
    s32 unused;
    DObj* model1;
    DObj* model2;
    Vec3f sp38;
    Vec3f sp2C;
    Vec3f sp20;    

    if (arg0 == NULL || arg1 == NULL) {
        return FLOAT_MAX;
    }

    model1 = arg0->data.dobj;
    model2 = arg1->data.dobj;

    if (model1->unk_4C != NULL) {
        sp38.x = GET_TRANSFORM(model1)->pos.v.x;
        sp38.y = GET_TRANSFORM(model1)->pos.v.y;
        sp38.z = GET_TRANSFORM(model1)->pos.v.z;
    } else {
        sp38.x = model1->position.v.x;
        sp38.y = model1->position.v.y;
        sp38.z = model1->position.v.z;
    }

    if (model2 == NULL) {
        return FLOAT_MAX;
    }

    if (model2->unk_4C != NULL) {
        sp2C.x = GET_TRANSFORM(model2)->pos.v.x;
        sp2C.y = GET_TRANSFORM(model2)->pos.v.y;
        sp2C.z = GET_TRANSFORM(model2)->pos.v.z;
    } else {
        sp2C.x = model2->position.v.x;
        sp2C.y = model2->position.v.y;
        sp2C.z = model2->position.v.z;
    }

    return Vec3fDirection(&sp20, &sp38, &sp2C);
}

void func_8035F390_4FF7A0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (gPlayerDObj != NULL) {
        Vec3f sp34;
        Vec3f sp28;
        Vec3f sp1C;

        sp28.x = GET_TRANSFORM(model)->pos.v.x;
        sp28.y = GET_TRANSFORM(model)->pos.v.y;
        sp28.z = GET_TRANSFORM(model)->pos.v.z;

        sp34.x = GET_TRANSFORM(gPlayerDObj)->pos.v.x;
        sp34.y = GET_TRANSFORM(gPlayerDObj)->pos.v.y;
        sp34.z = GET_TRANSFORM(gPlayerDObj)->pos.v.z;

        pokemon->playerDist = Vec3fDirection(&sp1C, &sp34, &sp28);
    } else {
        pokemon->playerDist = FLOAT_MAX;
    }
}

#ifdef NON_MATCHING
GObj* func_8035F430_4FF840(GObj* obj, f32* distance) {
    GObj* closestItem = NULL;
    GObj* currItem = NULL;
    DObj* model = obj->data.dobj;
    f32 closestDist2 = FLOAT_MAX;
    f32 x, y, z;
    
    x = GET_TRANSFORM(model)->pos.v.x;
    y = GET_TRANSFORM(model)->pos.v.y;
    z = GET_TRANSFORM(model)->pos.v.z;

    Items_func_80359880();
    while ((currItem = Items_func_80359894()) != NULL) {
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
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F430_4FF840.s")
GObj* func_8035F430_4FF840(GObj* obj, f32* distance);
#endif

f32 func_8035F51C_4FF92C(Vec3f* arg0, Vec3f* arg1) {
    f32 dx = arg0->x - arg1->x;
    f32 dy = arg0->y - arg1->y;
    f32 dz = arg0->z - arg1->z;
    f32 q;
    f32 angle;

    if (ABS(dz) < 0.00001) {
        dx = 1.0f;
        dz = 0.0f;
    }

    q = 1.0f / sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
    dx *= q;
    dz *= q;
    angle = atan2f(dx, dz);

    if (angle < 0.0f) {
        angle += TAU;
    } else if (angle > TAU) {
        angle -= (s32)(angle / TAU) * TAU;
    }
    return angle;
}

f32 func_8035F648_4FFA58(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3) {
    f32 dx = arg0->x - arg1->x;
    f32 dy = arg0->y - arg1->y;
    f32 dz = arg0->z - arg1->z;
    f32 q;
    f32 angle;

    if (ABS(dz) < 0.00001) {
        dx = 1.0f;
        dz = 0.0f;
    }

    q = arg3 / sqrtf(SQ(dx) + SQ(dz));
    dx *= q;
    dz *= q;
    angle = atan2f(dx, dz);

    if (angle < 0.0f) {
        angle += TAU;
    } else if (angle > TAU) {
        angle -= (s32)(angle / TAU) * TAU;
    }
    if (arg2 != NULL) {
        arg2->x = dx;
        arg2->y = 0.0f;
        arg2->z = dz;
    }
    return angle;
}

f32 func_8035F784_4FFB94(GObj* obj, Vec3f* arg1) {
    GObj* pokemonObj;
    DObj* model = obj->data.dobj;
    f32 dist;
    s32 s5 = FALSE;
    Vec3f sp64;
    Vec3f sp58;
    Vec3f sp4C;    
    
    sp64.x = GET_TRANSFORM(model)->pos.v.x;
    sp64.y = GET_TRANSFORM(model)->pos.v.y;
    sp64.z = GET_TRANSFORM(model)->pos.v.z;

    arg1->x = arg1->y = arg1->z = 0.0f;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        if (pokemonObj != obj) {
            DObj* model2 = pokemonObj->data.dobj;

            sp58.x = GET_TRANSFORM(model2)->pos.v.x;
            sp58.y = GET_TRANSFORM(model2)->pos.v.y;
            sp58.z = GET_TRANSFORM(model2)->pos.v.z;

            dist = Vec3fDirection(&sp4C, &sp64, &sp58);
            if (dist < 100.0f) {
                s5 = TRUE;
                arg1->x += dist * sp4C.x;
                arg1->y += dist * sp4C.y;
                arg1->z += dist * sp4C.z;
            }
        }
    }

    if (s5) {
        return Vec3fNormalize(arg1);
    } else {
        return 0.0f;
    }
}

void func_8035F900_4FFD10(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 i;
    s32 s2 = TRUE;
    Vec3f sp60;
    f32 sp5C;
    GObj* obj2;
    GObjFunc s4 = NULL;
    GObjFunc s3 = NULL;    
    idFuncStruct* transitionGraph = pokemon->transitionGraph;

    if (transitionGraph == NULL) {
        return;
    }

    for (i = 0; s2 && transitionGraph[i].id != 58; i++) {
        if (transitionGraph[i].state == NULL && transitionGraph[i].aux == NULL) {
            continue;
        }

        switch (transitionGraph[i].id) {
            case 15:
                obj2 = func_8035F430_4FF840(obj, &sp5C);
                if (obj2 != NULL) {
                    Item* item = GET_ITEM(obj2);
                    if (obj2 != pokemon->apple && item->itemID == ITEM_ID_APPLE && item->state == ITEM_STATE_STILL && sp5C < 600.0f) {
                        pokemon->apple = obj2;
                        s2 = FALSE;
                        pokemon->interactionDist = sp5C;
                        pokemon->interactionTarget = obj2;
                        s4 = transitionGraph[i].state;
                        s3 = transitionGraph[i].aux;
                    }
                }
                break;
            case 16:
                if (pokemon->playerDist < transitionGraph[i].radius) {
                    pokemon->interactionDist = sp5C; // BUG: sp5C undefined here, must use 'playerDist'
                    s2 = FALSE;
                    pokemon->interactionTarget = gObjPlayer;                    
                    s4 = transitionGraph[i].state;
                    s3 = transitionGraph[i].aux;
                }
                break;
            case 17:
                if (func_8035F784_4FFB94(obj, &sp60) > 0.0f) {
                    pokemon->dirToNeighbors.x = sp60.x;
                    pokemon->dirToNeighbors.y = sp60.y;
                    pokemon->dirToNeighbors.z = sp60.z;
                    s2 = FALSE;
                    s4 = transitionGraph[i].state;
                    s3 = transitionGraph[i].aux;
                }
                break;
            case 5:
            case 6:
            case 7:
                if (Items_func_8035C834() == transitionGraph[i].id && pokemon->playerDist < 1400.0f) {
                    s2 = FALSE;
                    pokemon->interactionTarget = gObjPlayer;
                    s4 = transitionGraph[i].state;
                    s3 = transitionGraph[i].aux;
                }
                break;
            case 23:
                if (D_80382CF8_523108 > transitionGraph[i].radius && obj == gPokemonInFocus) {
                    s4 = transitionGraph[i].state;
                    s3 = transitionGraph[i].aux;
                    s2 = FALSE;
                }
                break;
            case 25:
                if (gDirectionIndex < 0 && pokemon->playerDist < transitionGraph[i].radius) {
                    s4 = transitionGraph[i].state;
                    s3 = transitionGraph[i].aux;
                    s2 = FALSE;
                }
                break;
        }
    }

    if (s3 != 0) {
        func_8035ED90_4FF1A0(obj, s3);
    }
    if (s4 != 0) {
        updatePokemonState(obj, s4);
    }
    if (!func_80353D68_4F4178()) {
        ohPauseObjectProcesses(obj);
    }
}

void runInteractionsAndWaitForFlags(GObj* obj, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        func_8035F900_4FFD10(obj);
        if (pokemon->processFlags & flags) {
            break;
        }
        ohWait(1);
    }
    pokemon->transitionGraph = NULL;
}

void func_8035FC54_500064(GObj* obj, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        if (pokemon->processFlags & flags) {
            break;
        }
        ohWait(1);
    }
}

void func_8035FCA0_5000B0(GObj* arg0) {
    SomeListEntry* entry;

    for (entry = D_803B0C08_551018; entry != NULL; entry = entry->next) {
        GObj* obj = entry->obj;
        Pokemon* pokemon = GET_POKEMON(obj);
        if (arg0 == pokemon->interactionTarget) {
            cmdSendCommand(obj, 22, arg0);
        }
    }
}

void func_8035FD00_500110(GObj* arg0) {
    arg0->flags |= GOBJ_FLAG_HIDDEN;
    PokemonDetector_CleanupPokemon(arg0);
    func_80357428_4F7838(arg0);
    func_8035FCA0_5000B0(arg0);
    func_8035E9A4_4FEDB4(GET_TRANSFORM_BASE(arg0->data.dobj));
    func_8035EAE0_4FEEF0(GET_POKEMON(arg0));
    func_8035E7DC_4FEBEC(arg0);
    func_800A716C(arg0);
    deletePokemon(arg0);
}

void runPokemonCleanup(GObj* obj) {
    omCreateProcess(obj, func_8035FD00_500110, 1, 4);
}

void func_8035FD9C_5001AC(u16* whiteList) {
    GObj* pokemonObj;
    u16* ptr;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        u16 id = GET_POKEMON(pokemonObj)->id;

        for (ptr = whiteList; *ptr != 0; ptr++) {
            if (*ptr == id) {
                break;
            }
        }
        if (*ptr == 0) {
            runPokemonCleanup(pokemonObj);
        }
    }
}

GObj* addPokemonAtGeo(GObj *gobj, u16 id, PokemonDef *def) {
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

void func_8035FEEC_5002FC(GObj* obj, s32 arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (arg1 == TRUE) {
        pokemon->flags |= POKEMON_FLAG_100;
    } else {
        pokemon->flags &= ~POKEMON_FLAG_100;
    }
}

s32 func_8035FF1C_50032C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 ret;

    if (pokemon->flags & POKEMON_FLAG_100) {
        ret = TRUE;
    } else {
        ret = FALSE;
    }
    return ret;
}

void func_80360074_500484(GObj*);

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

extern Gfx D_8038A3D0_52A7E0[];
extern Gfx D_8038A400_52A810[];

void func_80360074_500484(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    gSPDisplayList(gMainGfxPos[0]++, D_8038A3D0_52A7E0);
    gDPSetFogColor(gMainGfxPos[0]++, 230, 250, 180, pokemon->unk_E4);
    renderPokemonModelTypeI(obj);
    gSPDisplayList(gMainGfxPos[0]++, D_8038A400_52A810);
}

void func_8036010C_50051C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (Items_CheckObjectExists(pokemon->apple)) {
        Items_DeleteItem(pokemon->apple);
    }
}

void func_80360144_500554(GObj* obj, f32 arg1) {
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonInitData* initData = pokemon->initData;    

    GET_TRANSFORM(model)->scale.v.x = initData->scale.x * 0.1f * arg1;
    GET_TRANSFORM(model)->scale.v.y = initData->scale.y * 0.1f * arg1;
    GET_TRANSFORM(model)->scale.v.z = initData->scale.z * 0.1f * arg1;

    pokemon->collisionOffset.x = initData->scaleNumerator.x / initData->scale.x * arg1;
    pokemon->collisionOffset.y = initData->scaleNumerator.y / initData->scale.y * arg1;
    pokemon->collisionOffset.z = initData->scaleNumerator.z / initData->scale.z * arg1;
    pokemon->collisionRadius = initData->radius * initData->scale.y * arg1;
}

void func_803601FC_50060C(GObj* obj, f32 arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);
    Item* targetItem = GET_ITEM(pokemon->interactionTarget); // TODO check it's really item
    DObj* model = obj->data.dobj;
    s32 unused;
    f32 f10, sp20;
    f32 sp1C;
    
    sp1C = GET_TRANSFORM(model)->rot.f[2];
    sp20 = sinf(sp1C) * arg1;
    f10 = cosf(sp1C) * arg1;

    targetItem->velocity.x = sp20;
    targetItem->velocity.y = arg1;
    targetItem->velocity.z = f10;
}

void func_8036026C_50067C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 sp24 = pokemon->hSpeed * 0.033;
    f32 sp20 = GET_TRANSFORM(model)->rot.f[2];
    f32 sp1C = sinf(sp20) * sp24;
    f32 sp18 = cosf(sp20) * sp24;

    GET_TRANSFORM(model)->pos.v.x += sp1C;
    GET_TRANSFORM(model)->pos.v.z += sp18;
}

void func_80360300_500710(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 f24 = 0.0f;
    f32 f20, f22, f26, f28;

    f20 = pokemon->jumpVel * 0.033;
    arg3 *= 0.033;
    arg4 *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
            f22 = arg2 * 0.033;
            func_8036026C_50067C(obj);

            f24 += f20;
            transform->pos.v.y += f20;
            if (f22 != 0.0f) {
                f20 += f22;
                if (f20 > arg4) {
                    f20 = arg4;
                }
                if (f20 < arg3) {
                    f20 = arg3;
                }
            }
        }

        if (f24 >= arg1) {
            break;
        }
        ohWait(1);
    }
}

void func_8036044C_50085C(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 f20, f22, f26, f28;

    f20 = pokemon->jumpVel * 0.033;
    arg3 *= 0.033;
    arg4 *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
            f22 = arg2 * 0.033;
            func_8036026C_50067C(obj);
            transform->pos.v.y += f20;
            if (f22 != 0.0f) {
                f20 += f22;
                if (f20 > arg4) {
                    f20 = arg4;
                }
                if (f20 < arg3) {
                    f20 = arg3;
                }
            }
        }

        if (transform->pos.v.y >= arg1) {
            break;
        }
        ohWait(1);
    }
}

void func_80360590_5009A0(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 f24 = 0.0f;
    f32 f20, f22, f26, f28;

    f20 = pokemon->jumpVel * 0.033;
    arg3 *= 0.033;
    arg4 *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
            f22 = arg2 * 0.033;
            func_8036026C_50067C(obj);

            f24 -= f20;
            transform->pos.v.y -= f20;
            if (f22 != 0.0f) {
                f20 += f22;
                if (f20 > arg4) {
                    f20 = arg4;
                }
                if (f20 < arg3) {
                    f20 = arg3;
                }
            }
        }

        if (f24 <= -1.0f * arg1) {
            break;
        }
        ohWait(1);
    }
}

void func_803606E8_500AF8(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 f20, f22, f26, f28;

    f20 = pokemon->jumpVel * 0.033;
    arg3 *= 0.033;
    arg4 *= 0.033;

    while (TRUE) {
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
            f22 = arg2 * 0.033;
            func_8036026C_50067C(obj);
            transform->pos.v.y -= f20;
            if (f22 != 0.0f) {
                f20 += f22;
                if (f20 > arg4) {
                    f20 = arg4;
                }
                if (f20 < arg3) {
                    f20 = arg3;
                }
            }
        }

        if (transform->pos.v.y <= arg1) {
            break;
        }
        ohWait(1);
    }
}

void func_8036082C_500C3C(GObj* obj, f32 arg1, f32 arg2, f32 arg3) {
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 f20;
    f32 vx,vy,vz;
    Vec3f sp8C;
    Vec3f sp80;    
    f32 f2;
    f32 temp;

    sp8C = D_8038A430_52A840;
    arg1 *= 0.033;
    
    f20 = GET_TRANSFORM(model)->rot.f[2] + (temp = PI * arg2); // temp required fo matching
    f20 += arg3 * (randFloat() * TAU - PI);
    if (f20 < 0.0f) {
        f20 += TAU;
    } else if (f20 > TAU) {
        f20 -= (s32)(f20 / TAU) * TAU;
    }

    vx = sinf(f20) * arg1;
    vy = arg1;
    vz = cosf(f20) * arg1;

    while (TRUE) {
        getGroundAt(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z, &pokemon->currGround);
        if (GET_TRANSFORM(model)->pos.v.y < pokemon->currGround.height) {
            if (Vec3fAngleDiff(&sp8C, &pokemon->currGround.normal) < PI / 3.0f) {
                cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_20, obj);
                cmdSendCommand(gObjPlayer, PLAYER_CMD_SHAKE_CAMERA, obj);
                GET_TRANSFORM(model)->pos.v.y = pokemon->currGround.height;
                return;
            }
            sp80.x = vx;
            sp80.y = vy;
            sp80.z = vz;
            f2 = Vec3fNormalize(&sp80);
            Vec3f_func_8001AC98(&sp80, &pokemon->currGround.normal);
            vx = sp80.x * f2;
            vy = sp80.y * f2;
            vz = sp80.z * f2;
        }

        vy -= 0.6f;
        GET_TRANSFORM(model)->pos.v.x += vx;
        GET_TRANSFORM(model)->pos.v.y += vy;
        GET_TRANSFORM(model)->pos.v.z += vz;
        ohWait(1);
    }
}

void func_80360AB8_500EC8(GObj* obj, f32 arg1, s32 arg2) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    f32 f20 = pokemon->jumpVel * 0.033;

    while (TRUE) {
        if (arg2) {
            func_80360E78_501288(obj, pokemon->facingYaw, 0);
        } else {
            getGroundAt(transform->pos.v.x, transform->pos.v.z, &pokemon->currGround);
        }
        
        transform->pos.v.y += f20;
        f20 += (f32)(arg1 * 0.033);

        if (f20 < 0.0f && transform->pos.v.y < pokemon->currGround.height) {
            break;        
        }
        ohWait(1);
    }
    transform->pos.v.y = pokemon->currGround.height;
    pokemon->jumpVel = f20 * 1 / 0.033;
}

s32 func_80360BEC_500FFC(f32 arg0, f32 arg1, GroundResult* arg2, f32* arg3) {
    s32 ret = FALSE;

    getGroundAt(arg0, arg1, arg2);
    if (arg3 == NULL) {
        switch (arg2->surfaceType) {
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
        while (*arg3 != 0.0f) {
            if (*arg3 == arg2->surfaceType) {
                ret = TRUE;
                break;
            }
            arg3++;
        }
    }
    return ret;
}

s32 func_80360D18_501128(GObj* obj, f32 arg1, f32 arg2, u32 arg3) {
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);    
    f32 sp5C = GET_TRANSFORM(model)->pos.v.x + arg1;
    f32 sp58 = GET_TRANSFORM(model)->pos.v.z + arg2;
    GroundResult sp44;
    Vec3f sp38;
    Vec3f sp2C;

    if (func_80360BEC_500FFC(sp5C, sp58, &pokemon->currGround, pokemon->forbiddenGround)) {
        return TRUE;
    }

    sp2C.x = arg1; sp2C.y = 0.0f; sp2C.z = arg2;
    Vec3fNormalize(&sp2C);
    Vec3fScale(&sp2C, pokemon->collisionRadius);
    if (func_80360BEC_500FFC(GET_TRANSFORM(model)->pos.v.x + sp2C.x, GET_TRANSFORM(model)->pos.v.z + sp2C.z, &sp44, pokemon->forbiddenGround)) {
        return TRUE;
    }

    if (arg3 & 0x10) {
        if (ABS(GET_TRANSFORM(model)->pos.v.y - pokemon->currGround.height) != 0.0f) {
            return TRUE;
        }
    }

    GET_TRANSFORM(model)->pos.v.x = sp5C;
    GET_TRANSFORM(model)->pos.v.z = sp58;
    if (arg3 & 0x1) {
        GET_TRANSFORM(model)->pos.v.y = pokemon->currGround.height;
    }
    return FALSE;
}

s32 func_80360E78_501288(GObj* obj, f32 arg1, u32 arg2) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
        f32 sp1C = pokemon->hSpeed * 0.033;
        f32 sp18 = sinf(arg1) * sp1C;
        f32 sp14 = cosf(arg1) * sp1C;
        
        if (func_80360D18_501128(obj, sp18, sp14, arg2)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_80360F1C_50132C(GObj* obj, u32 arg2) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
        f32 sp1C = pokemon->hSpeed * 0.033;
        f32 yaw = GET_TRANSFORM(model)->rot.f[2];
        f32 sp18 = sinf(yaw) * sp1C;
        f32 sp14 = cosf(yaw) * sp1C;
        
        if (func_80360D18_501128(obj, sp18, sp14, arg2)) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_80360FC8_5013D8(DObj* model, f32 arg1, f32 arg2) {
    f32 f0;
    f32 delta;
    f32 sign;

    f0 = GET_TRANSFORM(model)->rot.f[2];
    f0 -= (s32)(f0 / TAU) * TAU;
    if (f0 < 0.0f) {
        f0 += TAU;
    }
    
    delta = arg1 - f0;
    if (ABS(delta) > arg2) {
        if (ABS(delta) < PI) {
            sign = SIGN(delta);
        } else {
            sign = -SIGN(delta);
        }
        GET_TRANSFORM(model)->rot.f[2] = f0 + sign * arg2;
    } else {
        GET_TRANSFORM(model)->rot.f[2] = arg1;
        return TRUE;    
    }
    return FALSE;
}

void func_80361110_501520(GObj* obj, f32 arg1, f32 arg2, s32 arg3) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 f20 = pokemon->hSpeed * 0.033;
    f32 f22;
    f32 f28, f30;
    f32 f24;
    f32 sp54;
    f32 newX, newZ, deltaX, deltaZ;
    f32 f02, delta, sign;
    Vec3f sp68;
    s32 unused[2];

    switch (randRange(300) % 3) {
        case 0:
            f22 = func_8035F24C_4FF65C(GET_TRANSFORM(model)->rot.f[2], PI / 6.0f);
            break;
        case 1:
            f22 = func_8035F24C_4FF65C(GET_TRANSFORM(model)->rot.f[2], -PI / 6.0f);
            break;
        case 2:
            f22 = func_8035F24C_4FF65C(GET_TRANSFORM(model)->rot.f[2], PI);
            break;
    }

    sp68.x = GET_TRANSFORM(model)->pos.v.x + sinf(f22) * arg1;
    sp68.z = GET_TRANSFORM(model)->pos.v.z + cosf(f22) * arg1;

    f24 = func_8035F24C_4FF65C(f22, PI);
    sp54 = f20 / arg1;

    f28 = GET_TRANSFORM(model)->pos.v.x;
    f30 = GET_TRANSFORM(model)->pos.v.z;

    while (TRUE) {
        f24 = func_8035F24C_4FF65C(f24, sp54);
        f22 = func_8035F24C_4FF65C(f24, PI_2);
        newX = sinf(f24) * arg1 + sp68.x;
        newZ = cosf(f24) * arg1 + sp68.z;
        deltaX = newX - f28;
        f28 = newX;
        deltaZ = newZ - f30;
        f30 = newZ;
        if (func_80360D18_501128(obj, deltaX, deltaZ, 1)) {
            return;
        }

        f02 = func_8035F24C_4FF65C(GET_TRANSFORM(model)->rot.f[2], 0.0f);
        delta = f22 - f02;
        if (ABS(delta) > arg2) {
            if (ABS(delta) < PI) {
                sign = SIGN(delta);
            } else {
                sign = -SIGN(delta);
            }
            GET_TRANSFORM(model)->rot.f[2] = func_8035F24C_4FF65C(f02, sign * arg2);
        } else {
            GET_TRANSFORM(model)->rot.f[2] = f22;
        }
        ohWait(1);
    }
}

void func_80361410_501820(GObj* obj, f32 arg1) {
    func_80361110_501520(obj, arg1, 0.1f, 1);
}

s32 func_80361440_501850(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 ret = Items_func_8035C834();

    if (pokemon->playerDist > 1400.0f) {
        ret = 0;
    }
    return ret;
}

void func_8036148C_50189C(GObj* obj, f32 arg1, u32 arg2) {
    f32 f20;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;    
    s32 s3 = TRUE;    
    Vec3f* s2;
    Vec3f* s1;
    DObj* v0;

    if (arg2 & 0x20) {
        v0 = gPlayerDObj;
    } else if (pokemon->interactionTarget != NULL) {
        v0 = pokemon->interactionTarget->data.dobj;
    } else {
        return;
    }

    if (GET_TRANSFORM_BASE(v0) != NULL) {
        s2 = &GET_TRANSFORM(v0)->pos.v;
    } else {
        s2 = &v0->position.v;
    }
    s1 = &GET_TRANSFORM(model)->pos.v;

    while (TRUE) {
        if ((arg2 & 4) && !func_80361440_501850(obj)) {
            break;
        }

        if (s3 || (arg2 & 2)) {
            s3 = FALSE;
            if (arg2 & 0x40) {
                f20 = func_8035F51C_4FF92C(s1, s2);
            } else {
                f20 = func_8035F51C_4FF92C(s2, s1);
            }
        }

        if (func_80360FC8_5013D8(model, f20, arg1) && !(arg2 & 8)) {
            break;
        }
        ohWait(1);
    }
}

void func_803615D0_5019E0(GObj* obj, DObj* arg1, f32 arg12, u32 arg2) {
    f32 f20;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    s32 s3;
    Vec3f* s1;
    Vec3f sp60;
    Vec3f sp54;

    sp54 = D_8038A43C_52A84C;
    s3 = TRUE;

    s1 = &GET_TRANSFORM(model)->pos.v;

    while (TRUE) {
        func_800A5E98(&sp60, &sp54, arg1);
        if ((arg2 & 4) && !func_80361440_501850(obj)) {
            break;
        }

        if (s3 || (arg2 & 2)) {
            s3 = FALSE;
            if (arg2 & 0x40) {
                f20 = func_8035F51C_4FF92C(s1, &sp60);
            } else {
                f20 = func_8035F51C_4FF92C(&sp60, s1);
            }
        }

        if (func_80360FC8_5013D8(model, f20, arg12) && !(arg2 & 8)) {
            break;
        }
        ohWait(1);
    }
}

void func_80361720_501B30(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, pokemon->hSpeed, 0);
}

void func_80361748_501B58(GObj* obj, f32 arg1, f32 arg2, u32 arg3) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 f22 = pokemon->hSpeed * 0.033;
    DObj* v0;
    Vec3f* a0;
    s32 s3 = TRUE;
    f32 f0;
    f32 f24;
    s32 unused[5];
    Vec3f* s1;
    Vec3f sp6C;
    s32 unused2;

    while (TRUE) {
        if (s3 || (arg3 & 2)) {
            s3 = FALSE;
            if (pokemon->interactionTarget == NULL) {
                break;
            }

            v0 = pokemon->interactionTarget->data.dobj;
            if (GET_TRANSFORM_BASE(v0) != NULL) {
                a0 = &GET_TRANSFORM(v0)->pos.v;
                pokemon->targetPos.x = GET_TRANSFORM(v0)->pos.v.x;
                pokemon->targetPos.y = GET_TRANSFORM(v0)->pos.v.y;
                pokemon->targetPos.z = GET_TRANSFORM(v0)->pos.v.z;
            } else {
                a0 = &v0->position.v;
                pokemon->targetPos.x = v0->position.v.x;
                pokemon->targetPos.y = v0->position.v.y;
                pokemon->targetPos.z = v0->position.v.z;
            }
            s1 = &GET_TRANSFORM(model)->pos.v;
            f24 = func_8035F648_4FFA58(a0, s1, &sp6C, f22);
        }

        if (func_80360D18_501128(obj, sp6C.x, sp6C.z, arg3 | 1)) {
            break;
        }

        func_80360FC8_5013D8(model, f24, arg2);
        f0 = sqrtf(SQ(pokemon->targetPos.x - s1->x) + SQ(pokemon->targetPos.y - s1->y) + SQ(pokemon->targetPos.z - s1->z));
        if (ABS(f0 - arg1) < f22 || f0 < arg1) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
            break;
        }

        ohWait(1);
    }
}

void func_8036194C_501D5C(GObj* obj, f32 arg1, f32 arg2, u32 arg3) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 f22 = pokemon->hSpeed * 0.033;
    DObj* v0;
    Vec3f* a0;
    s32 s3 = TRUE;
    f32 f0;
    f32 f24;
    s32 unused[7];
    Vec3f* s1;
    Vec3f sp6C;

    while (TRUE) {
        if (s3 || (arg3 & 2)) {
            s3 = FALSE;
            if (pokemon->interactionTarget == NULL) {
                break;
            }

            v0 = pokemon->interactionTarget->data.dobj;
            if (GET_TRANSFORM_BASE(v0) != NULL) {
                a0 = &GET_TRANSFORM(v0)->pos.v;
                pokemon->targetPos.x = GET_TRANSFORM(v0)->pos.v.x;
                pokemon->targetPos.y = GET_TRANSFORM(v0)->pos.v.y;
                pokemon->targetPos.z = GET_TRANSFORM(v0)->pos.v.z;
            } else {
                a0 = &v0->position.v;
                pokemon->targetPos.x = v0->position.v.x;
                pokemon->targetPos.y = v0->position.v.y;
                pokemon->targetPos.z = v0->position.v.z;
            }
            s1 = &GET_TRANSFORM(model)->pos.v;
            f24 = func_8035F648_4FFA58(s1, a0, &sp6C, f22);
        }

        if (func_80360D18_501128(obj, sp6C.x, sp6C.z, arg3 | 1)) {
            break;
        }

        func_80360FC8_5013D8(model, f24, arg2);
        f0 = sqrtf(SQ(pokemon->targetPos.x - s1->x) + SQ(pokemon->targetPos.y - s1->y) + SQ(pokemon->targetPos.z - s1->z));
        if (f0 > arg1) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
            break;
        }

        ohWait(1);
    }
}

void func_80361B20_501F30(GObj* obj, f32 arg1) {
    func_8036194C_501D5C(obj, arg1, 0.1f, 1);
}

void func_80361B50_501F60(GObj* obj, f32 arg1, f32 arg2) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->targetPos.x = arg1;
    pokemon->targetPos.z = arg2;
}

s32 func_80361B68_501F78(GObj* arg0, f32 arg1, s32 arg2) {
    f32 dx, dz;
    f32 sp4C;
    f32 sp48;
    f32 unused;
    f32 f122;
    f32 sp3C;
    f32 sign;
    f32 delta;
    f32 sp30;
    Pokemon* pokemon = GET_POKEMON(arg0);
    DObj* model = arg0->data.dobj;

    sp30 = pokemon->hSpeed * 0.033;
    dx = pokemon->targetPos.x - GET_TRANSFORM(model)->pos.v.x;
    dz = pokemon->targetPos.z - GET_TRANSFORM(model)->pos.v.z;

    if (SQ(dx) + SQ(dz) < SQ(sp30)) {
        pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
        return 1;
    }

    sp3C = atan2f(dx, dz);
    if (sp3C < 0.0f) {
        sp3C += TAU;
    } else if (sp3C > TAU){
        sp3C -= (s32)(sp3C / TAU) * TAU;
    }

    sp4C = sinf(sp3C) * sp30;
    sp48 = cosf(sp3C) * sp30;
    if (func_80360D18_501128(arg0, sp4C, sp48, arg2)) {
        return 2;
    }

    f122 = GET_TRANSFORM(model)->rot.f[2];
    f122 -= (s32)(f122 / TAU) * TAU;
    if (f122 < 0.0f) {
        f122 += TAU;
    }

    delta = sp3C - f122;
    if (ABS(delta) > arg1) {
        if (ABS(delta) < M_PI_F) {
            sign = SIGN(delta);
        } else {
            sign = -SIGN(delta);
        }
        GET_TRANSFORM(model)->rot.f[2] = f122 + sign * arg1;
    } else {
        GET_TRANSFORM(model)->rot.f[2] = sp3C;
    }

    dx = pokemon->targetPos.x - GET_TRANSFORM(model)->pos.v.x;
    dz = pokemon->targetPos.z - GET_TRANSFORM(model)->pos.v.z;
    if (SQ(dx) + SQ(dz) < SQ(sp30)) {
        pokemon->processFlags |= POKEMON_PROCESS_FLAG_10;
        return 1;
    }

    return 0;
}

void func_80361E58_502268(GObj* obj, f32 arg1) {
    while (!func_80361B68_501F78(obj, arg1, 1)) {
        ohWait(1);
    }
}

void func_80361EB8_5022C8(GObj* obj, f32 arg1) {
    func_80361748_501B58(obj, arg1, 0.1f, 0);
}

void func_80361EE8_5022F8(GObj* obj, f32 arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    DObj* targetModel;
    Vec3f* a0;
    Vec3f* s1;

    if (pokemon->interactionTarget == NULL) {
        return;
    }

    targetModel = pokemon->interactionTarget->data.dobj;
    if (GET_TRANSFORM_BASE(targetModel) != NULL) {
        a0 = &GET_TRANSFORM(targetModel)->pos.v;
    } else {
        a0 = &targetModel->position.v;
    }
    s1 = &GET_TRANSFORM(model)->pos.v;

    while (TRUE) {
        if (Items_func_8035C834() == 0 || pokemon->playerDist > 1400.0f) {
            break;
        }

        func_80360FC8_5013D8(model, func_8035F51C_4FF92C(a0, s1), arg1);
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

void setNodePosToNegRoom(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    WorldBlock* block = getCurrentWorldBlock();

    GET_TRANSFORM(model)->pos.v.x = -(block->descriptor->worldPos.x * 100.0f);
    GET_TRANSFORM(model)->pos.v.y = -(block->descriptor->worldPos.y * 100.0f);
    GET_TRANSFORM(model)->pos.v.z = -(block->descriptor->worldPos.z * 100.0f);
}

extern Vec3f D_8038A448_52A858;

void pokemonPathLoop(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4, u32 arg5) {
    DObj* model = obj->data.dobj;
    Vec3f sp80 = D_8038A448_52A858;
    Pokemon* pokemon = GET_POKEMON(obj);        
    Vec3f sp70;
    f32 f2;
    f32 sp68;
    

    pokemon->pathParam = arg1;

    if (pokemon->path == NULL) {
        while (TRUE) {
            ohWait(1);
        }
    }

    sp68 = 1.0f / pokemon->path->unk_0C * arg3;

    while (TRUE) {
        if (!(pokemon->pathParam >= 0.0f) || !(pokemon->pathParam <= 1.0f)) {
            while (TRUE) {
                ohWait(1);
            }
        }
        if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_20)) {
            GET_TRANSFORM(model)->pos.v.x -= sp80.x * 100.0f;
            GET_TRANSFORM(model)->pos.v.z -= sp80.z * 100.0f;
            if (!(arg5 & 0x10)) {
                if (arg5 & 1) {
                    GET_TRANSFORM(model)->pos.v.y -= sp80.y;
                } else {
                    GET_TRANSFORM(model)->pos.v.y -= sp80.y * 100.0f;
                }
            }
            
            if (arg5 & 0x82) {
                func_8001FCE8(&sp70, pokemon->path, pokemon->pathParam);
                f2 = atan2f(sp70.x, sp70.z);
                if (f2 < 0.0f) {
                    f2 += TAU;
                } else if (f2 > TAU) {
                    f2 -= (s32)(f2 / TAU) * TAU;
                }
                if (arg5 & 0x80) {
                    func_80360FC8_5013D8(model, f2, arg4);
                } else {
                    GET_TRANSFORM(model)->rot.f[2] = f2;
                }
            }

            func_80361FBC_5023CC(&sp80, pokemon->path, pokemon->pathParam);

            GET_TRANSFORM(model)->pos.v.x += sp80.x * 100.0f;
            GET_TRANSFORM(model)->pos.v.z += sp80.z * 100.0f;
            if (!(arg5 & 0x10)) {
                if (arg5 & 1) {
                    sp80.y = func_8035F21C_4FF62C(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z);
                    GET_TRANSFORM(model)->pos.v.y += sp80.y;
                    if (1) { } if (1) { } // TODO fake match
                } else {
                    GET_TRANSFORM(model)->pos.v.y += sp80.y * 100.0f;
                }
            }

            pokemon->pathParam += sp68;
            if (arg2 > 0.0f && arg2 <= pokemon->pathParam) {
                return;
            }

            if (pokemon->pathParam > 1.0f){
                pokemon->pathParam -= 1.0f;
            }
        }
        ohWait(1);
    }
}

f32 func_803623F4_502804(f32 arg0, f32 arg1) {
    return func_8035F21C_4FF62C(arg0, arg1);
}

void func_80362414_502824(Pokemon* arg0, eggStruct* arg1, f32 arg2) {
    arg0->eggGeo = arg1;
    func_800AB1F8(arg1);
    while (func_800AB138(arg1, arg2)) {
        ohWait(1);
    }
}

void func_80362480_502890(DObj* model, s32 arg1, f32 arg2) {
    GObj* obj = model->obj;
    Pokemon* pokemon = GET_POKEMON(obj);
    AnimationHeader* animHeader = pokemon->animHeader;

    switch (arg1) {
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
                s32 val = arg2;
                if (val != 0) {
                    if (animHeader->ids != NULL) {
                        func_8035F1D0_4FF5E0(obj, arg1, animHeader->ids[val - 1]);
                    }
                } else {
                    func_80366864_506C74(obj, arg1);
                }
            } else if (pokemon->tangible) {
                s32 val = arg2;
                if (val > 0 && D_80382D10_523120 != NULL && D_80382D14_523124 != NULL) {
                    UnkBrassLynx* unk = func_800A6C48(arg1, val - 1);
                    if (unk != NULL) {
                        unk->unk_48 = model;
                    }
                }
            }
            break;
    }
}

void func_803625B4_5029C4(GObjCmdData cmdData) {
    idFuncStruct* a2;
    f32 distance;
    s32 i;
    Pokemon* pokemon;    
    GObjFunc sp24;
    GObjFunc sp20;
        
    pokemon = GET_POKEMON(omCurrentObject);
    sp24 = NULL;
    sp20 = NULL;
    a2 = pokemon->transitionGraph;

    switch(cmdData.cmd) {
        case 14:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == cmdData.cmd) {
                    distance = func_8035F2A4_4FF6B4(omCurrentObject, cmdData.source);
                    if (distance < 600.0f) {
                        pokemon->apple = cmdData.source;
                        pokemon->interactionDist = distance;
                        pokemon->interactionTarget = cmdData.source;
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                    }
                    break;
                }
            }
            break;
        case 10:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == cmdData.cmd) {
                    distance = func_8035F2A4_4FF6B4(omCurrentObject, cmdData.source);
                    if (distance < 150.0) {
                        pokemon->apple = cmdData.source;
                        pokemon->interactionDist = distance;
                        pokemon->interactionTarget = cmdData.source;
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                    }
                    break;
                }
            }
            break;
        case 9:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 9) {
                    pokemon->interactionTarget = cmdData.source;
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
        case 13:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 13) {
                    pokemon->interactionTarget = cmdData.source;
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
        case 8:
        case 12:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == cmdData.cmd) {
                    pokemon->interactionTarget = cmdData.source;
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
        case 21:
            if (pokemon->apple == cmdData.source) {
                pokemon->apple = NULL;
                if (a2 == NULL) {
                    break;
                }
                for (i = 0; a2[i].id != 58; i++) {
                    if (a2[i].id == 21) {
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                        break;
                    }
                }
            }
            break;
        case 18:
            if (pokemon->playerDist < 400.0f) {
                if (a2 == NULL) {
                    break;
                }
                for (i = 0; a2[i].id != 58; i++) {
                    if (a2[i].id == 18) {
                        pokemon->interactionTarget = cmdData.source;
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                        break;
                    }
                }
            }
            break;
        case 24:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 24) {
                    pokemon->interactionTarget = cmdData.source;
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
        case 19:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 19) {
                    if (getCurrentWorldBlock() == pokemon->baseBlock) {
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                    }
                }
            }
            break;
        case 20:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 20) {
                    distance = func_8035F2A4_4FF6B4(omCurrentObject, cmdData.source);
                    if (distance < 600.0f) {
                        pokemon->interactionTarget = cmdData.source;
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                    }
                    break;
                }
            }
            break;
        case 22:
            if (pokemon->interactionTarget == cmdData.source) {
                pokemon->interactionTarget = NULL;
                if (a2 == NULL) {
                    break;
                }
                for (i = 0; a2[i].id != 58; i++) {
                    if (a2[i].id == 22) {
                        sp24 = a2[i].state;
                        sp20 = a2[i].aux;
                        break;
                    }
                }
            }
            break;
        case 26:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 26) {
                    pokemon->interactionTarget = cmdData.source;
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
        case 27:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == 27) {
                    pokemon->interactionTarget = cmdData.source;
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
            if (a2 == NULL) {
                break;
            }
            for (i = 0; a2[i].id != 58; i++) {
                if (a2[i].id == cmdData.cmd) {
                    if (cmdData.source != NULL) {
                        pokemon->interactionTarget = cmdData.source;
                    }
                    sp24 = a2[i].state;
                    sp20 = a2[i].aux;
                    break;
                }
            }
            break;
    }

    if (sp20 != NULL) {
        func_8035ED90_4FF1A0(omCurrentObject, sp20);
    }
    if (sp24 != NULL) {
        updatePokemonState(omCurrentObject, sp24);
    }
    if (!func_80353D68_4F4178()) {
        ohPauseObjectProcesses(omCurrentObject);
    }
}

void updatePokemonDefault(GObj* obj) {
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
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_1)) {
        if (pokemon->loopCount >= pokemon->pokemonLoopTarget) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_1;
        } else if (pokemon->lastAnimationFrame > 0.0f && pokemon->lastAnimationFrame < obj->animationTime) {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_1;
        }
    }
    cmdProcessCommands(func_803625B4_5029C4);
}

void func_80362D2C_50313C(GObj* obj, f32 prevBlockX, f32 prevBlockY, f32 prevBlockZ, f32 currBlockX, f32 currBlockY, f32 currBlockZ) {
    Pokemon* pokemon = GET_POKEMON(obj);
    WorldBlock* block;

    pokemonChangeBlockOnGround(obj, prevBlockX, prevBlockY, prevBlockZ, currBlockX, currBlockY, currBlockZ);
    if (getCurrentWorldBlock()->index > (block = pokemon->baseBlock)->index && pokemon->playerDist > 10000.0f) {
        runPokemonCleanup(obj);
    }
}

GObj* func_80362DC4_5031D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = spawnPokemon(objID, id, block, blockB, spawn, initData);
    omMoveGObjDL(pokemonObj, 4, 0x80000000);
    return pokemonObj;
}

GObj* func_80362E10_503220(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = spawnPokemonOnGround(objID, id, block, blockB, spawn, initData);
    omMoveGObjDL(pokemonObj, 4, 0x80000000);
    return pokemonObj;
}

GObj* spawnPokemon(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = spawnPokemonOnGround(objID, id, block, blockB, spawn, initData);
    GET_TRANSFORM(pokemonObj->data.dobj)->pos.v.y = spawn->translation.y * 100.0f + (block->descriptor->worldPos.y - blockB->descriptor->worldPos.y) * 100.0f;
    return pokemonObj;
}

GObj* spawnPokemonOnGround(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
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

    pokemonObj = omAddGObj(objID, updatePokemonDefault, 3, 0x80000000);

    if (initData->fnRender != NULL && initData->tree != NULL) {
        omLinkGObjDL(pokemonObj, initData->fnRender, 5, 0x80000000, -1);
        if (initData->flags & 0x10) {
            anim_func_80010230(pokemonObj, initData->tree, initData->textures, NULL, initData->matrix1, initData->matrix2, initData->matrix3);
        } else {
            anim_func_80010230(pokemonObj, initData->tree, initData->textures, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
        }
        model = pokemonObj->data.dobj;
    } else {
        model = omGObjAddDObj(pokemonObj, NULL);
        if (initData->flags & 0x10) {
            anim_func_8000FDA0(model, initData->matrix1, initData->matrix2, initData->matrix3);
        } else {
            anim_func_8000FDA0(model, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
        }
    }

    matrixStore = func_8035E944_4FED54();
    matrixStore->kinds[0] = 1;
    matrixStore->kinds[1] = 2;
    matrixStore->kinds[2] = 3;
    model->unk_4C = (struct DObjDynamicStore*)matrixStore;
    omDObjAddMtx(model, MTX_TYPE_63, 0, 0);

    GET_TRANSFORM(model)->pos.v.x = spawn->translation.x * 100.0f + (block->descriptor->worldPos.x - blockBX) * 100.0f;
    GET_TRANSFORM(model)->pos.v.z = spawn->translation.z * 100.0f + (block->descriptor->worldPos.z - blockBZ) * 100.0f;
    GET_TRANSFORM(model)->pos.v.y = func_8035F21C_4FF62C(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z);
    GET_TRANSFORM(model)->rot.f[1] = spawn->euler.x;
    GET_TRANSFORM(model)->rot.f[2] = spawn->euler.y;
    GET_TRANSFORM(model)->rot.f[3] = spawn->euler.z;
    GET_TRANSFORM(model)->scale.v.x = initData->scale.x * 0.1f;
    GET_TRANSFORM(model)->scale.v.y = initData->scale.y * 0.1f;
    GET_TRANSFORM(model)->scale.v.z = initData->scale.z * 0.1f;

    pokemonObj->userData = pokemon = func_8035EA80_4FEE90();
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
    pokemonObj->fnAnimCallback = func_80362480_502890;
    pokemon->animators = NULL;
    omCreateProcess(pokemonObj, animUpdateModelTreeAnimation, 1, 3);
    forcePokemonAnimation(pokemonObj, initData->animSetup->animations);
    omCreateProcess(pokemonObj, func_8035F390_4FF7A0, 1, 8);

    pokemon->interactionProc = omCreateProcess(pokemonObj, initData->animSetup->func, initData->animSetup->kind, 7);
    pokemon->unk_18 = -1;
    pokemon->processFlags = 0;
    pokemon->counter = 0;
    pokemon->pathProcess = NULL;
    pokemon->transitionGraph = NULL;
    pokemon->pokemonLoopTarget = 0;
    pokemon->lastAnimationFrame = 0.0f;
    pokemon->jumpVel = 0.0f;
    pokemon->hSpeed = 0.0f;
    pokemon->facingYaw = 0.0f;
    pokemon->transitionGraph = initData->animSetup->idfuncs;
    pokemon->unk_E4 = 255;
    pokemon->path = spawn->path;
    pokemon->pathParam = 0.0f;
    pokemon->behavior = spawn->behavior;
    pokemon->eggGeo = NULL;
    pokemon->unk_10C = 0;
    pokemon->field_0x10e = 0;
    pokemon->playerDist = FLOAT_MAX;
    func_8035E780_4FEB90(pokemonObj);
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
    SomeListEntry* entry;
    SomeListEntry* entry2;
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
                            cmdSendCommand(entry->obj, 26, entry2->obj);
                        }

                        if (!(pokemon2->processFlags & POKEMON_PROCESS_FLAG_80)) {
                            pokemon2->processFlags |= POKEMON_PROCESS_FLAG_80;
                            cmdSendCommand(entry2->obj, 26, entry->obj);
                        }
                        
                        // BUG same pokemon checked twice
                        if ((pokemon2->flags & POKEMON_FLAG_800) && (pokemon2->flags & POKEMON_FLAG_800)) {
                            func_8035F648_4FFA58(&sp84, &sp78, &sp6C, f20 / 2);
                            func_80360D18_501128(entry->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry->obj);

                            func_8035F648_4FFA58(&sp78, &sp84, &sp6C, f20 / 2);
                            func_80360D18_501128(entry2->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry2->obj);
                        } else if (pokemon2->flags & POKEMON_FLAG_800) {
                            func_8035F648_4FFA58(&sp78, &sp84, &sp6C, f20);
                            func_80360D18_501128(entry2->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry2->obj);
                        } else if (pokemon->flags & POKEMON_FLAG_800) {
                            func_8035F648_4FFA58(&sp84, &sp78, &sp6C, f20);
                            func_80360D18_501128(entry->obj, sp6C.x, sp6C.z, 1);
                            func_8036334C_50375C(entry->obj);
                        }
                    }
                }
            }
        }
        if (FALSE) { } // required to match
    }
}

extern SomeListEntry D_803B0A28_550E38[];

void func_80363738_503B48(void) {
    s32 i;

    D_803B0C08_551018 = NULL;
    D_803B0C0C_55101C = NULL;
    D_803B0C10_551020 = D_803B0A28_550E38;

    for (i = 0; i < 40; i++) {
        if (i == 0) {
            D_803B0A28_550E38[i].prev = NULL;
        } else {
            D_803B0A28_550E38[i].prev = &D_803B0A28_550E38[i - 1];
        }
        if (i == 39) {
            D_803B0A28_550E38[i].next = NULL;
        } else {
            D_803B0A28_550E38[i].next = &D_803B0A28_550E38[i + 1];
        }
        D_803B0A28_550E38[i].obj = NULL;
    }

    omCreateProcess(ohFindByLinkAndId(0, 0), func_8036345C_50386C, 1, 2);
    func_8035E8A4_4FECB4();
    func_8035E9E0_4FEDF0();
    func_8035EB1C_4FEF2C();
}
