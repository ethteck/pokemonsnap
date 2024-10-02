#include "common.h"
#include "world/world.h"
#include "app_level.h"

#define BASE_ITEM_OBJID 300

enum ItemFlags {
    ITEM_FLAG_BOUNCED = 1,
    ITEM_FLAG_TOUCHED_GROUND = 2,
    ITEM_FLAG_DELETED = 4
};

typedef struct ItemObjectListEntry {
    /* 0x00 */ struct ItemObjectListEntry* prev;
    /* 0x04 */ struct ItemObjectListEntry* next;
    /* 0x08 */ GObj* obj;
    /* 0x0C */ s32 index;
} ItemObjectListEntry; // size = 0x10

extern Texture** D_800E8EB8[];
extern UnkEC64Arg3 D_800E9138[];
extern AnimCmd** D_800E91C0[];

extern Texture** D_800EAC58[];
extern UnkEC64Arg3 D_800EAED0[];
extern AnimCmd** D_800EAF60[];

extern AnimCmd* D_800EAFB0[];
extern AnimCmd** D_800EB0C0[];
extern UnkEC64Arg3 D_800EB430[];
extern Texture** D_800EB510[];

extern AnimCmd* D_800ED5B0[];
extern AnimCmd** D_800ED6B0[];
extern UnkEC64Arg3 D_800EDAB0[];
extern Texture** D_800EDB90[];

extern DObj* gPlayerDObj;

s32 Items_ObjectCounter = 0;
GObjFunc Items_FnUpdate = NULL;
void (*Items_FnCollide)(GObj*, GroundResult*) = NULL;
s32 (*D_80382EBC_5232CC)(Vec3f*, Vec3f*, Vec3f*, Vec3f*) = NULL;
s32 Items_FluteSongsList[3] = { SONG_ID_1, SONG_ID_3, SONG_ID_2 };
s32 Items_FluteCommandIds[3] = { POKEMON_CMD_5, POKEMON_CMD_6, POKEMON_CMD_7 };
s32 Items_FluteSongIndex = 0;
s32 Items_IsPokeFlutePlaying = false;
OSTime Items_SongStartTime = 0;
// bss
extern ItemObjectListEntry Items_ListEntryArray[20];
extern ItemObjectListEntry* Items_AllocatedObjectListHead;
extern ItemObjectListEntry* Items_AllocatedObjectListTail;
extern ItemObjectListEntry* Items_FreeObjectListHead;
extern s32 D_803AF0B4_54F4C4;
extern s32 D_803AF0B8_54F4C8;
extern s32 Items_TotalItemCount;
extern s32 Items_PesterBallCount;
extern s32 Items_AppleCount;
extern u8 Items_FnUpdateKind;

void Pokemon_SendDieCommand(GObj*);
void Pokemon_FreeItem(void*);
void Items_RemovePesterBall(GObj*);
Item* Pokemon_GetItem(void);
f32 func_80363848_503C58(GObj* arg0, Vec3f* arg1);
void Items_UpdateNonMovingItem(GObj* arg0);

f32 Items_DotProduct(Vec3f* v1, Vec3f* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void Items_EndProcessByFunction(GObj* obj, GObjFunc func) {
    GObjProcess* proc;
    GObjProcess* next;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        next = proc->next;
        if (func == proc->function) {
            omEndProcess(proc);
        }
        proc = next;
    }
}

void Items_Init(void) {
    s32 i;

    Items_AllocatedObjectListHead = NULL;
    Items_AllocatedObjectListTail = 0;
    Items_FreeObjectListHead = Items_ListEntryArray;

    for (i = 0; i < ARRAY_COUNT(Items_ListEntryArray); i++) {
        if (i == 0) {
            Items_ListEntryArray[i].prev = NULL;
        } else {
            Items_ListEntryArray[i].prev = &Items_ListEntryArray[i - 1];
        }
        if (i == ARRAY_COUNT(Items_ListEntryArray) - 1) {
            Items_ListEntryArray[i].next = NULL;
        } else {
            Items_ListEntryArray[i].next = &Items_ListEntryArray[i + 1];
        }
        Items_ListEntryArray[i].obj = 0;
        Items_ListEntryArray[i].index = i;
    }
    Items_TotalItemCount = 0;
}

void Items_InitIterator(void) {
    D_803AF0B8_54F4C8 = 0;
    D_803AF0B4_54F4C4 = 0;
}

GObj* Items_NextValidItem(void) {
    while (D_803AF0B4_54F4C4 < 20) {
        GObj* obj = Items_ListEntryArray[D_803AF0B4_54F4C4++].obj;
        if (obj != NULL && GET_ITEM(obj)->state > ITEM_STATE_INVALID) {
            return obj;
        }
    }
    return NULL;
}

GObj* Items_func_80359900(void) {
    while (D_803AF0B4_54F4C4 < 20) {
        GObj* obj = Items_ListEntryArray[D_803AF0B4_54F4C4++].obj;
        if (obj != NULL && GET_ITEM(obj)->state == ITEM_STATE_STILL) {
            return obj;
        }
    }
    return NULL;
}

GObj* Items_CheckObjectExists(GObj* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(Items_ListEntryArray); i++) {
        if (Items_ListEntryArray[i].obj == arg0) {
            return arg0;
        }
    }
    return NULL;
}

void Items_LinkObject(GObj* obj) {
    ItemObjectListEntry* v1;

    v1 = Items_FreeObjectListHead;
    if (Items_FreeObjectListHead == NULL) {
        return;
    }
    Items_FreeObjectListHead = Items_FreeObjectListHead->next;

    v1->prev = Items_AllocatedObjectListTail;
    v1->next = NULL;

    if (v1->prev != NULL) {
        v1->prev->next = Items_AllocatedObjectListTail = v1;
        v1;
    } else {
        Items_AllocatedObjectListHead = Items_AllocatedObjectListTail = v1;
    }

    v1->obj = obj;
    GET_ITEM(obj)->entryIndex = v1->index;
}

void Items_UnlinkObject(GObj* obj) {
    ItemObjectListEntry* entry;

    if (GET_ITEM(obj)->itemID == ITEM_ID_APPLE) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_21, obj);
    }

    entry = &Items_ListEntryArray[GET_ITEM(obj)->entryIndex];
    if (entry->prev != NULL) {
        entry->prev->next = entry->next;
    } else {
        Items_AllocatedObjectListHead = entry->next;
    }
    if (entry->next != NULL) {
        entry->next->prev = entry->prev;
    } else {
        Items_AllocatedObjectListTail = entry->prev;
    }

    entry->next = Items_FreeObjectListHead;
    entry->obj = NULL;
    Items_FreeObjectListHead = entry;
}

#ifdef NON_MATCHING
// loop not unrolled
s32 Items_GetFreeObjectID(void) {
    s32 i;

    Items_ObjectCounter++;
    if (Items_ObjectCounter >= 20) {
        Items_ObjectCounter = 0;
    }

    for (i = Items_ObjectCounter; i < 20; i++) {
        if (Items_ListEntryArray[i].obj == NULL) {
            return BASE_ITEM_OBJID + i;
        }
    }
    for (i = 0; i < Items_ObjectCounter; i++) {
        if (Items_ListEntryArray[i].obj == NULL) {
            return BASE_ITEM_OBJID + i;
        }
    }
    return BASE_ITEM_OBJID;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/items/Items_GetFreeObjectID.s")
s32 Items_GetFreeObjectID(void);
#endif

void Items_ShowDelayed(GObj* obj) {
    ohWait(3);
    obj->flags &= ~GOBJ_FLAG_HIDDEN;
    omEndProcess(NULL);
}

void Items_InitItem(GObj* obj, Vec3f* pos, Vec3f* extraVelocity) {
    Vec3f velocity;
    DObj* model;
    Item* item;

    model = obj->data.dobj;

    model->position.v.x = pos->x;
    model->position.v.y = pos->y;
    model->position.v.z = pos->z;

    velocity.x = gCamTargetX - model->position.v.x;
    velocity.y = gCamTargetY - model->position.v.y + 100.0f;
    velocity.z = gCamTargetZ - model->position.v.z;
    Vec3fNormalize(&velocity);
    Vec3fScale(&velocity, 50.0f); // base speed
    Vec3fAdd(&velocity, extraVelocity);

    item = obj->userData;
    item->state = ITEM_STATE_FLYING;
    item->flags = 0;
    item->restTimer = 0.0f;
    item->velocity.x = velocity.x;
    item->velocity.y = velocity.y;
    item->velocity.z = velocity.z;
    Items_LinkObject(obj);
    obj->flags |= GOBJ_FLAG_HIDDEN;
    omCreateProcess(obj, Items_FnUpdate, Items_FnUpdateKind, 7);
    omCreateProcess(obj, Items_ShowDelayed, 0, 7);
}

void Items_ProcessCommand(GObjCmdData cmdData) {
    if (cmdData.cmd == ITEM_CMD_REMOVE) {
        Items_DeleteItem(omCurrentObject);
    }
}

void Items_UpdateObject(GObj* obj) {
    cmdProcessCommands(Items_ProcessCommand);
}

void Items_DeleteFume(GObj* obj) {
    omDeleteGObj(obj);
}

void Items_UpdateFume(GObj* obj) {
    f32 animTime = 0.0f;

    while (true) {
        if (60.0f - obj->animationTime < 0.9f) {
            break;
        }
        if (animTime < 0.0f) {
            break;
        }
        animTime = obj->animationTime;
        ohWait(1);
    }
    omCreateProcess(obj, Items_DeleteFume, 1, 7);
    omEndProcess(NULL);
}

void Items_CreateSplash(GObj* pesterBallObj, UnkEC64Arg3* treeDef, Texture*** textures, AnimCmd** modelAnim, AnimCmd*** texturesAnim) {
    DObj* ballModel = pesterBallObj->data.dobj;
    GObj* fumeObj;
    GroundResult groundResult;
    s32 i;

    animSetTextureAnimationSpeed(pesterBallObj, 0.0f);
    fumeObj = omAddGObj(Items_GetFreeObjectID(), ohUpdateDefault, LINK_ITEM, 0x80000000);
    omLinkGObjDL(fumeObj, renderModelTypeDFogged, DL_LINK_3, 0x80000000, -1);
    anim_func_80010230(fumeObj, treeDef, textures, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
    omCreateProcess(fumeObj, animUpdateModelTreeAnimation, 1, 3);
    animSetModelTreeAnimation(fumeObj, modelAnim, 0.0f);
    animSetModelTreeTextureAnimation(fumeObj, texturesAnim, 0.0f);
    animSetModelAndTextureAnimationSpeed(fumeObj, 0.9f);
    getGroundAt(ballModel->position.v.x, ballModel->position.v.z, &groundResult);
    fumeObj->data.dobj->position.v.x = ballModel->position.v.x;
    fumeObj->data.dobj->position.v.y = groundResult.height;
    fumeObj->data.dobj->position.v.z = ballModel->position.v.z;
    fumeObj->data.dobj->scale.v.x = 0.1f;
    fumeObj->data.dobj->scale.v.y = 0.1f;
    fumeObj->data.dobj->scale.v.z = 0.1f;
    fumeObj->userData = NULL;
    omCreateProcess(fumeObj, Items_UpdateFume, 0, 7);
    for (i = 59; i > 0; i--) {
        ballModel->position.v.y -= 2.0f;
        ohWait(1);
    }
    Items_DeleteItem(pesterBallObj);
    omEndProcess(NULL);
}

void Items_CreateWaterSplash(GObj* obj) {
    Items_CreateSplash(obj, D_800EB430, D_800EB510, D_800EAFB0, D_800EB0C0);
}

void Items_CreateLavaSplash(GObj* obj) {
    Items_CreateSplash(obj, D_800EDAB0, D_800EDB90, D_800ED5B0, D_800ED6B0);
}

void Items_DeleteItemImmediately(GObj* obj) {
    Items_DeleteItem(obj);
    omEndProcess(NULL);
}

void Items_PlaySound(DObj* model, s32 soundID) {
    f32 dist;
    Vec3f playerPos;
    Vec3f pos;
    Vec3f diff;

    pos.x = model->position.v.x;
    pos.y = model->position.v.y;
    pos.z = model->position.v.z;
    playerPos.x = GET_TRANSFORM(gPlayerDObj)->pos.v.x;
    playerPos.y = GET_TRANSFORM(gPlayerDObj)->pos.v.y;
    playerPos.z = GET_TRANSFORM(gPlayerDObj)->pos.v.z;
    dist = Vec3fDirection(&diff, &playerPos, &pos);
    if (dist < 3000.0f) {
        auPlaySoundWithVolume(soundID, 30720.0f - (dist / 3000.0f) * 30720.0f);
    }
}

void Items_CollideWithGround(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    Vec3f velocity;
    Vec3f normal;
    f32 newvar = 0.5f;
    f32 speed;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f) {
        item->state = ITEM_STATE_STILL;
        obj->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(obj, Items_DeleteItemImmediately, 1, 7);
        omEndProcess(NULL);
        return;
    }

    model->position.v.y = groundResult->height + 12.0f;
    normal.x = groundResult->normal.x;
    normal.y = groundResult->normal.y;
    normal.z = groundResult->normal.z;
    velocity.x = item->velocity.x;
    velocity.y = item->velocity.y;
    velocity.z = item->velocity.z;
    speed = Vec3fNormalize(&velocity);
    Vec3fReflect(&velocity, &normal);

    if (item->itemID == ITEM_ID_PESTER_BALL) {
        Items_PlaySound(model, SOUND_ID_10);
        if (groundResult->surfaceType == SURFACE_TYPE_4C1900 ||
            groundResult->surfaceType == SURFACE_TYPE_4C4C33 ||
            groundResult->surfaceType == SURFACE_TYPE_7F4C00 ||
            groundResult->surfaceType == SURFACE_TYPE_7F7F7F ||
            groundResult->surfaceType == SURFACE_TYPE_B2997F) {
            if (item->itemID == ITEM_ID_PESTER_BALL) {
                item->state = ITEM_STATE_STILL;
            }
        }
        obj->flags |= GOBJ_FLAG_HIDDEN;
        Items_EndProcessByFunction(obj, Items_ShowDelayed);
        omCreateProcess(obj, Items_RemovePesterBall, 1, 7);
        animSetTextureAnimationSpeed(obj, 0.0f);
        omEndProcess(NULL);
        return;
    }
    switch (groundResult->surfaceType) {
        case SURFACE_TYPE_4C7F00:
        case SURFACE_TYPE_996666:
        case SURFACE_TYPE_FF9919:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_24);
            }
            speed *= 0.2f;
            break;
        case SURFACE_TYPE_331919:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_25);
            }
            speed *= 0.3f;
            break;
        case SURFACE_TYPE_193333:
        case SURFACE_TYPE_4C1900:
        case SURFACE_TYPE_4C4C33:
        case SURFACE_TYPE_7F4C00:
        case SURFACE_TYPE_7F667F:
        case SURFACE_TYPE_7F7F7F:
        case SURFACE_TYPE_FF7FB2:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_25);
            }
            speed *= 0.3f;
            break;
        case SURFACE_TYPE_7F6633:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_25);
            }
            speed *= 0.3f;
            break;
        case SURFACE_TYPE_B2997F:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_27);
            }
            speed *= 0.2f;
            break;
        case SURFACE_TYPE_00FF00:
        case SURFACE_TYPE_FF4C19:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_29);
            }
            item->state = ITEM_STATE_STILL;
            omCreateProcess(obj, Items_CreateLavaSplash, 0, 7);
            animSetTextureAnimationSpeed(obj, 0.0f);
            omEndProcess(NULL);
            return;
        case SURFACE_TYPE_0019FF:
        case SURFACE_TYPE_007F66:
        case SURFACE_TYPE_337FB2:
        case SURFACE_TYPE_4CCCCC:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_26);
            }
            item->state = ITEM_STATE_STILL;
            omCreateProcess(obj, Items_CreateWaterSplash, 0, 7);
            animSetTextureAnimationSpeed(obj, 0.0f);
            omEndProcess(NULL);
            return;
        case SURFACE_TYPE_FF0000:
            item->state = ITEM_STATE_STILL;
            speed = 0.0f;
            omCreateProcess(obj, Items_DeleteItemImmediately, 1, 7);
            omEndProcess(NULL);
            break;
        default:
            speed = 0.0f;
            break;
    }

    if (speed < 13.0f && groundResult->normal.y < 0.866) { // slope angle > 30 degrees
        if (SQ(groundResult->normal.x) + SQ(groundResult->normal.z) < SQ(6.5f)) {
            speed = 13.0f;
        }
    }

    if (speed < 13.0f) {
        item->state = ITEM_STATE_STILL;
        omCreateProcess(obj, Items_UpdateNonMovingItem, 1, 7);
        animSetTextureAnimationSpeed(obj, 0.0f);
        omEndProcess(NULL);
        return;
    }

    item->velocity.x = velocity.x * speed;
    item->velocity.y = velocity.y * speed;
    item->velocity.z = velocity.z * speed;
    model->position.v.x += item->velocity.x * newvar;
    model->position.v.y += item->velocity.y * newvar;
    model->position.v.z += item->velocity.z * newvar;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f) {
        item->state = ITEM_STATE_STILL;
        obj->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(obj, Items_DeleteItemImmediately, 1, 7);
        omEndProcess(NULL);
    }
}

void Items_CollideWithCeiling(GObj* obj, GroundResult* result) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    Vec3f velocity;
    Vec3f normal;
    Vec3f dirUp;
    f32 newvar = 0.5f;
    f32 speed;
    f32 unused;
    f32 normalSpeed;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f) {
        item->state = ITEM_STATE_STILL;
        obj->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(obj, Items_DeleteItemImmediately, 1, 7);
        omEndProcess(NULL);
        return;
    }

    normal.x = result->normal.x;
    normal.y = result->normal.y;
    normal.z = result->normal.z;
    dirUp.x = 0.0f;
    dirUp.y = model->position.v.y - result->height;
    dirUp.z = 0.0f;
    velocity.x = item->velocity.x;
    velocity.y = item->velocity.y;
    velocity.z = item->velocity.z;

    speed = Vec3fNormalize(&velocity);
    normalSpeed = normal.x * velocity.x + normal.y * velocity.y + normal.z * velocity.z;
    if (ABS(normalSpeed) > 0.001f) {
        Vec3fAddScaled(&model->position.v, &velocity, -(normal.x * dirUp.x + normal.y * dirUp.y + normal.z * dirUp.z) / normalSpeed);
    } else {
    }
    Vec3fAddScaled(&model->position.v, &normal, 12.0f);
    Vec3fReflect(&velocity, &normal);

    if (item->itemID == ITEM_ID_PESTER_BALL) {
        Items_PlaySound(model, SOUND_ID_10);
        if (result->surfaceType == SURFACE_TYPE_4C1900 ||
            result->surfaceType == SURFACE_TYPE_4C4C33 ||
            result->surfaceType == SURFACE_TYPE_7F4C00 ||
            result->surfaceType == SURFACE_TYPE_7F7F7F ||
            result->surfaceType == SURFACE_TYPE_B2997F) {
            if (item->itemID == ITEM_ID_PESTER_BALL) {
                item->state = ITEM_STATE_STILL;
            }
        }
        obj->flags |= GOBJ_FLAG_HIDDEN;
        Items_EndProcessByFunction(obj, Items_ShowDelayed);
        omCreateProcess(obj, Items_RemovePesterBall, 1, 7);
        animSetTextureAnimationSpeed(obj, 0.0f);
        omEndProcess(NULL);
        return;
    }
    switch (result->surfaceType) {
        case SURFACE_TYPE_193333:
        case SURFACE_TYPE_4C7F00:
        case SURFACE_TYPE_996666:
        case SURFACE_TYPE_FF9919:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_24);
            }
            speed *= 0.2f;
            break;
        case SURFACE_TYPE_331919:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_25);
            }
            speed *= 0.2f;
            break;
        case SURFACE_TYPE_4C1900:
        case SURFACE_TYPE_4C4C33:
        case SURFACE_TYPE_7F4C00:
        case SURFACE_TYPE_7F667F:
        case SURFACE_TYPE_7F7F7F:
        case SURFACE_TYPE_FF7FB2:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_25);
            }
            speed *= 0.3f;
            break;
        case SURFACE_TYPE_7F6633:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_25);
            }
            speed *= 0.3f;
            break;
        case SURFACE_TYPE_B2997F:
            if (speed > 13.0f) {
                Items_PlaySound(model, SOUND_ID_27);
            }
            speed *= 0.2f;
            break;
        default:
            speed = 0.0f;
            break;
    }

    item->velocity.x = velocity.x * speed;
    item->velocity.y = velocity.y * speed;
    item->velocity.z = velocity.z * speed;
    model->position.v.x += item->velocity.x * newvar;
    model->position.v.y += item->velocity.y * newvar;
    model->position.v.z += item->velocity.z * newvar;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f) {
        item->state = ITEM_STATE_STILL;
        obj->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(obj, Items_DeleteItemImmediately, 1, 7);
        omEndProcess(NULL);
    }
}

void Items_NotifyItemPosition(GObj* obj) {
    Item* item = GET_ITEM(obj);

    if (item->itemID == ITEM_ID_PESTER_BALL) {
        UnkPinkRat* unk = func_800A6C48(3, 0);
        if (unk != NULL) {
            unk->unk_14.x = obj->data.dobj->position.v.x;
            unk->unk_14.y = obj->data.dobj->position.v.y;
            unk->unk_14.z = obj->data.dobj->position.v.z;
        }
    }

    if (item->itemID == ITEM_ID_PESTER_BALL) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_10, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_14, obj);
    }
}

void Items_BounceFromCeiling(GObj* obj, GroundResult* ceilingResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    f32 prevX, prevY, prevZ;
    f32 currX, currY, currZ;
    f32 midX, midY, midZ;
    f32 oldX, oldY, oldZ;
    f32 d;
    s32 i;

    prevX = item->prevPos.x;
    prevY = item->prevPos.y;
    prevZ = item->prevPos.z;

    currX = model->position.v.x;
    currY = model->position.v.y;
    currZ = model->position.v.z;

    // reuiqred for matching, affects only regalloc
    midX = 0.0f;
    midZ = 0.0f;

    d = sqrtf(SQ(currX - prevX) + SQ(currZ - prevZ));
    // find approximate intersection point
    for (i = 0; i < 100; i++) {
        midX = (prevX + currX) * 0.5f;
        midY = (prevY + currY) * 0.5f;
        midZ = (prevZ + currZ) * 0.5f;
        d *= 0.5f;
        if (d <= 1.0f) {
            break;
        }

        getCeilingAt(midX, midZ, ceilingResult);
        if (midY > ceilingResult->height) {
            currX = midX;
            currY = midY;
            currZ = midZ;
        } else {
            prevX = midX;
            prevY = midY;
            prevZ = midZ;
        }
    }

    oldX = model->position.v.x;
    oldY = model->position.v.y;
    oldZ = model->position.v.z;
    model->position.v.x = midX;
    model->position.v.y = midY;
    model->position.v.z = midZ;

    Items_CollideWithCeiling(obj, ceilingResult);
    if (Items_FnCollide != NULL) {
        Items_FnCollide(obj, ceilingResult);
    }

    model->position.v.x = item->prevPos.x + model->position.v.x - oldX;
    model->position.v.y = item->prevPos.y + model->position.v.y - oldY;
    model->position.v.z = item->prevPos.z + model->position.v.z - oldZ;
    Items_NotifyItemPosition(obj);
}

#ifdef NON_EQUIVALENT
void Items_BounceFromGround(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    s32 i;
    f32 deltaY;

    x1 = item->prevPos.x;
    y1 = item->prevPos.y;
    z1 = item->prevPos.z;

    x2 = model->position.v.x;
    y2 = model->position.v.y;
    z2 = model->position.v.z;

    item->prevPos.x = model->position.v.x;
    item->prevPos.y = model->position.v.y;
    item->prevPos.z = model->position.v.z;

    for (i = 15; i >= 0; i--) {
        model->position.v.x = (x1 + model->position.v.x) * 0.5;
        model->position.v.y = (y1 + model->position.v.y) * 0.5;
        model->position.v.z = (z1 + model->position.v.z) * 0.5;
        getGroundAt(model->position.v.x, model->position.v.z, groundResult);
        deltaY = ABS(model->position.v.y - groundResult->height);
        if (ABS(deltaY) <= 0.375f) {
            model->position.v.y = groundResult->height;
            break;
        }

        if (model->position.v.y < groundResult->height) {
            x2 = model->position.v.x;
            y2 = model->position.v.y;
            z2 = model->position.v.z;
        } else {
            x1 = model->position.v.x;
            y1 = model->position.v.y;
            z1 = model->position.v.z;
        }
    }

    if (i < 0) {
        model->position.v.y = groundResult->height;
    }
    item->flags |= ITEM_FLAG_BOUNCED | ITEM_FLAG_TOUCHED_GROUND;
    Items_CollideWithGround(obj, groundResult);
    if (Items_FnCollide != NULL) {
        Items_FnCollide(obj, groundResult);
    }
    Items_NotifyItemPosition(obj);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/items/Items_BounceFromGround.s")
void Items_BounceFromGround(GObj* arg0, GroundResult* arg1);
#endif

void Items_BounceFromCeilingAndGround(GObj* obj, GroundResult* result) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    Vec3f vel;
    f32 speed;

    vel.x = item->velocity.x;
    vel.y = item->velocity.y;
    vel.z = item->velocity.z;
    speed = Vec3fNormalize(&vel);
    getCeilingAt(item->prevPos.x, item->prevPos.z, result);
    if (item->itemID == ITEM_ID_PESTER_BALL) {
        Items_PlaySound(model, SOUND_ID_10);
        speed = 0.0f;
        if (result->surfaceType == SURFACE_TYPE_4C1900 ||
            result->surfaceType == SURFACE_TYPE_4C4C33 ||
            result->surfaceType == SURFACE_TYPE_7F4C00 ||
            result->surfaceType == SURFACE_TYPE_7F7F7F ||
            result->surfaceType == SURFACE_TYPE_B2997F) {
            if (item->itemID == ITEM_ID_PESTER_BALL) {
                item->state = ITEM_STATE_STILL;
            }
        }
        obj->flags |= GOBJ_FLAG_HIDDEN;
        Items_EndProcessByFunction(obj, Items_ShowDelayed);
        omCreateProcess(obj, Items_RemovePesterBall, 1, 7);
        animSetTextureAnimationSpeed(obj, 0.0f);
        omEndProcess(NULL);
    } else {
        switch (result->surfaceType) {
            case SURFACE_TYPE_193333:
            case SURFACE_TYPE_4C7F00:
            case SURFACE_TYPE_996666:
            case SURFACE_TYPE_FF9919:
                if (speed > 13.0f) {
                    Items_PlaySound(model, SOUND_ID_24);
                }
                speed *= 0.2f;
                break;
            case SURFACE_TYPE_331919:
                if (speed > 13.0f) {
                    Items_PlaySound(model, SOUND_ID_25);
                }
                speed *= 0.2f;
                break;
            case SURFACE_TYPE_4C1900:
            case SURFACE_TYPE_4C4C33:
            case SURFACE_TYPE_7F4C00:
            case SURFACE_TYPE_7F667F:
            case SURFACE_TYPE_7F7F7F:
            case SURFACE_TYPE_FF7FB2:
                if (speed > 13.0f) {
                    Items_PlaySound(model, SOUND_ID_25);
                }
                speed *= 0.3f;
                break;
            case SURFACE_TYPE_7F6633:
                if (speed > 13.0f) {
                    Items_PlaySound(model, SOUND_ID_25);
                }
                speed *= 0.3f;
                break;
            case SURFACE_TYPE_B2997F:
                if (speed > 13.0f) {
                    Items_PlaySound(model, SOUND_ID_27);
                }
                speed *= 0.2f;
                break;
            default:
                speed = 0.0f;
                break;
        }
    }

    Vec3fReflect(&vel, &result->normal);
    item->velocity.x = vel.x * speed;
    item->velocity.y = vel.y * speed;
    item->velocity.z = vel.z * speed;
    model->position.v.x = item->prevPos.x + item->velocity.x;
    model->position.v.y = item->prevPos.y + item->velocity.y;
    model->position.v.z = item->prevPos.z + item->velocity.z;
    Items_NotifyItemPosition(obj);
}

void Items_UpdateItemMovement(GObj* obj) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    Vec3f vel2;
    UnkPinkRat* v03;
    f32 sp11C;
    GObj* closestPokemon;
    Pokemon* pokemon;
    Vec3f sp108;
    GroundResult groundResult;
    GObj* pokemonObjPtr;
    f32 f2;
    Vec3f outPos;
    Vec3f outVel;
    f32 g = 1.2f;
    f32 distToGround;
    GroundResult ceilingResult;
    s32 somethingID;
    Vec3f pos;
    Vec3f sp9C;
    Vec3f sp90;
    Vec3f sp84;
    Vec3f vel;
    Vec3f sp6C;
    Vec3f sp60;
    s32 hasCeiling;
    f32 f22;
    f32 sp54;
    f32 sp50;
    f32 speed;
    f32 unused1[3];

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f) {
        item->state = ITEM_STATE_STILL;
        obj->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(obj, Items_DeleteItemImmediately, 1, 7);
        omEndProcess(NULL);
        return;
    }

    getGroundAt(model->position.v.x, model->position.v.z, &groundResult);
    hasCeiling = getCeilingAt(model->position.v.x, model->position.v.z, &ceilingResult);
    if (hasCeiling && model->position.v.y <= groundResult.height && model->position.v.y > ceilingResult.height) {
        // under the ground but above the ceiling? hmm..
        Items_BounceFromCeilingAndGround(obj, &ceilingResult);
        return;
    }
    if (hasCeiling && model->position.v.y > ceilingResult.height) {
        Items_BounceFromCeiling(obj, &ceilingResult);
        return;
    }
    distToGround = ABS(model->position.v.y - groundResult.height);
    if (distToGround > 0.375f && model->position.v.y < groundResult.height) {
        Items_BounceFromGround(obj, &groundResult);
        return;
    }
    if (distToGround <= 0.375f) {
        // exactly on ground
        item->prevPos.x = model->position.v.x;
        item->prevPos.y = model->position.v.y;
        item->prevPos.z = model->position.v.z;
        item->flags |= ITEM_FLAG_BOUNCED | ITEM_FLAG_TOUCHED_GROUND;
        Items_CollideWithGround(obj, &groundResult);
        if (Items_FnCollide != NULL) {
            Items_FnCollide(obj, &groundResult);
        }
        Items_NotifyItemPosition(obj);
        return;
    }
    // normal fly
    item->prevPos.x = model->position.v.x;
    item->prevPos.y = model->position.v.y;
    item->prevPos.z = model->position.v.z;
    vel2.x = item->velocity.x * 0.5f;
    vel2.y = item->velocity.y * 0.5f;
    vel2.z = item->velocity.z * 0.5f;

    // bounce from something
    somethingID = StaticObject_Collide(&model->position.v, &vel2, &outPos, &outVel);
    if (somethingID >= 0) {
        item->flags |= ITEM_FLAG_BOUNCED;
        if (item->itemID == ITEM_ID_PESTER_BALL) {
            Items_PlaySound(model, SOUND_ID_10);
            v03 = func_800A6C48(3, 0);
            if (v03 != NULL) {
                v03->unk_14.x = obj->data.dobj->position.v.x;
                v03->unk_14.y = obj->data.dobj->position.v.y;
                v03->unk_14.z = obj->data.dobj->position.v.z;
            }
            obj->flags |= GOBJ_FLAG_HIDDEN;
            Items_EndProcessByFunction(obj, Items_ShowDelayed);
            omCreateProcess(obj, Items_RemovePesterBall, 1, 7);
            animSetTextureAnimationSpeed(obj, 0.0f);
            cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_10, obj);
            omEndProcess(NULL);
        } else if (somethingID == PokemonID_1004 || somethingID == PokemonID_1007 || somethingID == PokemonID_1010 || somethingID == PokemonID_1022) {
            Items_PlaySound(model, SOUND_ID_25);
        } else {
            Items_PlaySound(model, SOUND_ID_31);
        }
        item->collisionVelocity.x = item->velocity.x;
        item->collisionVelocity.y = item->velocity.y;
        item->collisionVelocity.z = item->velocity.z;
        item->velocity.x = outVel.x;
        item->velocity.y = outVel.y;
        item->velocity.z = outVel.z;
        model->position.v.x = outPos.x;
        model->position.v.y = outPos.y;
        model->position.v.z = outPos.z;
        return;
    }

    if (D_80382EBC_5232CC != NULL && D_80382EBC_5232CC(&model->position.v, &vel2, &outPos, &outVel) >= 0) {
        item->flags |= ITEM_FLAG_BOUNCED;
        if (item->itemID == ITEM_ID_PESTER_BALL) {
            Items_PlaySound(model, SOUND_ID_10);
            v03 = func_800A6C48(3, 0);
            if (v03 != NULL) {
                v03->unk_14.x = obj->data.dobj->position.v.x;
                v03->unk_14.y = obj->data.dobj->position.v.y;
                v03->unk_14.z = obj->data.dobj->position.v.z;
            }
            obj->flags |= GOBJ_FLAG_HIDDEN;
            Items_EndProcessByFunction(obj, Items_ShowDelayed);
            omCreateProcess(obj, Items_RemovePesterBall, 1, 7);
            animSetTextureAnimationSpeed(obj, 0.0f);
            cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_10, obj);
            omEndProcess(NULL);
        } else {
            Items_PlaySound(model, SOUND_ID_31);
        }
        item->collisionVelocity.x = item->velocity.x;
        item->collisionVelocity.y = item->velocity.y;
        item->collisionVelocity.z = item->velocity.z;
        item->velocity.x = outVel.x;
        item->velocity.y = outVel.y;
        item->velocity.z = outVel.z;
        model->position.v.x = outPos.x;
        model->position.v.y = outPos.y;
        model->position.v.z = outPos.z;
        return;
    }

    // no collision
    pos.x = model->position.v.x;
    pos.y = model->position.v.y;
    pos.z = model->position.v.z;

    vel.x = item->velocity.x * 0.5f;
    vel.y = item->velocity.y * 0.5f;
    vel.z = item->velocity.z * 0.5f;
    speed = Vec3fNormalize(&vel);

    sp11C = speed;
    closestPokemon = NULL;

    for (pokemonObjPtr = omGObjListHead[LINK_POKEMON]; pokemonObjPtr != NULL; pokemonObjPtr = pokemonObjPtr->next) {
        pokemon = GET_POKEMON(pokemonObjPtr);
        if (pokemon->tangible && pokemon->collisionRadius > 0.0f) {
            sp54 = func_80363848_503C58(pokemonObjPtr, &sp9C);
            sp50 = Vec3fDirection(&sp84, &sp9C, &pos);
            f2 = Items_DotProduct(&sp84, &vel) * sp50;
            if (f2 > 0.0f) {
                if (SQ(sp54) < SQ(sp50) - SQ(f2)) {
                    continue;
                }
                if (pokemon->flags & POKEMON_FLAG_2) {
                    if (item->itemID == ITEM_ID_PESTER_BALL) {
                        cmdSendCommand(pokemonObjPtr, POKEMON_CMD_8, NULL);
                    } else {
                        cmdSendCommand(pokemonObjPtr, POKEMON_CMD_12, NULL);
                    }
                }

                f22 = f2 - sqrtf(SQ(sp54) - (SQ(sp50) - SQ(f2)));
                if (f22 < sp11C) {
                    sp11C = f22;
                    closestPokemon = pokemonObjPtr;
                    sp108.x = sp9C.x;
                    sp108.y = sp9C.y;
                    sp108.z = sp9C.z;
                }
            }
        }
    }

    if (closestPokemon != NULL) {
        sp90.x = pos.x + sp11C * vel.x;
        sp90.y = pos.y + sp11C * vel.y;
        sp90.z = pos.z + sp11C * vel.z;
        Vec3fDirection(&sp6C, &sp90, &sp108);
        Vec3fReflect(&vel, &sp6C);
        sp60.x = vel.x = vel.x * speed * 0.5f;
        sp60.y = vel.y = vel.y * speed * 0.5f - g * 0.5f;
        sp60.z = vel.z = vel.z * speed * 0.5f;
        if (Vec3fNormalize(&sp60) < 10.0f) {
            vel.x = sp6C.x * 10.0f;
            vel.y = sp6C.y * 10.0f;
            vel.z = sp6C.z * 10.0f;
        }
        if (item->itemID == ITEM_ID_PESTER_BALL) {
            v03 = func_800A6C48(3, 0);
            if (v03 != NULL) {
                v03->unk_14.x = obj->data.dobj->position.v.x;
                v03->unk_14.y = obj->data.dobj->position.v.y;
                v03->unk_14.z = obj->data.dobj->position.v.z;
            }
            Items_PlaySound(model, SOUND_ID_10);
            cmdSendCommand(closestPokemon, POKEMON_CMD_9, NULL);
            obj->flags |= GOBJ_FLAG_HIDDEN;
            Items_EndProcessByFunction(obj, Items_ShowDelayed);
            omCreateProcess(obj, Items_RemovePesterBall, 1, 7);
            animSetTextureAnimationSpeed(obj, 0.0f);
            omEndProcess(NULL);
        } else {
            Items_PlaySound(model, SOUND_ID_12);
            cmdSendCommand(closestPokemon, POKEMON_CMD_13, NULL);
        }
        item->collisionVelocity.x = item->velocity.x;
        item->collisionVelocity.y = item->velocity.y;
        item->collisionVelocity.z = item->velocity.z;
        item->velocity.x = vel.x;
        item->velocity.y = vel.y;
        item->velocity.z = vel.z;
        model->position.v.x = sp90.x + item->velocity.x * 0.5f;
        model->position.v.y = sp90.y + item->velocity.y * 0.5f;
        model->position.v.z = sp90.z + item->velocity.z * 0.5f;
        return;
    } else {
        // apply gravity
        item->velocity.y -= g * 0.5f;
        model->position.v.x += item->velocity.x * 0.5f;
        model->position.v.y += item->velocity.y * 0.5f;
        model->position.v.z += item->velocity.z * 0.5f;
    }
}

void Items_RemovePesterBall(GObj* arg0) {
    Item* item = GET_ITEM(arg0);

    if (item->restTimer > 60.0f) {
        Items_DeleteItem(arg0);
        omEndProcess(NULL);
        return;
    }
    if (item->state == 0) {
        omEndProcess(NULL);
        return;
    }
    item->restTimer += 0.5;
}

void Items_UpdateNonMovingItem(GObj* obj) {
    Item* item = GET_ITEM(obj);
    DObj* model = obj->data.dobj;

    if (item->restTimer > 170.0f) {
        Items_DeleteItem(obj);
        omEndProcess(NULL);
        return;
    }
    if (item->state == ITEM_STATE_INVALID) {
        omEndProcess(NULL);
        return;
    }
    if (item->restTimer > 140.0f) {
        model->scale.v.x *= 0.9f;
        model->scale.v.y *= 0.9f;
        model->scale.v.z *= 0.9f;
        model->position.v.y -= model->scale.v.y * 12.0f;
    }
    item->restTimer += 0.5;
}

void Items_SpawnPesterBall(Vec3f* pos, Vec3f* extraVelocity) {
    GObj* ballObj;
    Item* ball;

    if (Items_PesterBallCount >= 5 && Items_AllocatedObjectListHead != NULL) {
        Items_DeleteItem(Items_AllocatedObjectListHead->obj);
    }
    Items_TotalItemCount++;
    Items_PesterBallCount++;
    ballObj = omAddGObj(Items_GetFreeObjectID(), Items_UpdateObject, LINK_ITEM, 0x80000000);
    omLinkGObjDL(ballObj, renderModelTypeBFogged, DL_LINK_3, 0x80000000, -1);
    anim_func_80010230(ballObj, D_800E9138, D_800E8EB8, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
    omCreateProcess(ballObj, animUpdateModelTreeAnimation, 1, 3);
    animSetModelTreeTextureAnimation(ballObj, D_800E91C0, 0);
    animSetTextureAnimationSpeed(ballObj, 0.4f);
    ballObj->data.dobj->scale.v.x = 0.1f;
    ballObj->data.dobj->scale.v.y = 0.1f;
    ballObj->data.dobj->scale.v.z = 0.1f;
    ball = Pokemon_GetItem();
    ballObj->userData = ball;
    ball->itemID = ITEM_ID_PESTER_BALL;
    ballObj->flags |= GOBJ_FLAG_HIDDEN;
    Items_EndProcessByFunction(ballObj, Items_ShowDelayed);
    auPlaySound(SOUND_ID_8);
    Items_InitItem(ballObj, pos, extraVelocity);
}

void Items_SpawnApple(Vec3f* pos, Vec3f* extraVelocity) {
    GObj* appleObj;
    Item* apple;

    if (Items_AppleCount >= 5 && Items_AllocatedObjectListHead != NULL) {
        Items_DeleteItem(Items_AllocatedObjectListHead->obj);
    }
    Items_TotalItemCount++;
    Items_AppleCount++;
    appleObj = omAddGObj(Items_GetFreeObjectID(), Items_UpdateObject, LINK_ITEM, 0x80000000);
    omLinkGObjDL(appleObj, renderModelTypeBFogged, DL_LINK_3, 0x80000000, -1);
    anim_func_80010230(appleObj, D_800EAED0, D_800EAC58, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
    omCreateProcess(appleObj, animUpdateModelTreeAnimation, 1, 3);
    animSetModelTreeTextureAnimation(appleObj, D_800EAF60, 0);
    animSetTextureAnimationSpeed(appleObj, 0.4f);
    appleObj->data.dobj->scale.v.x = 0.1f;
    appleObj->data.dobj->scale.v.y = 0.1f;
    appleObj->data.dobj->scale.v.z = 0.1f;
    apple = Pokemon_GetItem();
    appleObj->userData = apple;
    apple->itemID = ITEM_ID_APPLE;
    appleObj->flags |= GOBJ_FLAG_HIDDEN;
    Items_EndProcessByFunction(appleObj, Items_ShowDelayed);
    auPlaySound(SOUND_ID_9);
    Items_InitItem(appleObj, pos, extraVelocity);
}

void Items_PlayPokeFlute(void) {
    s32 temp_t8;

    if (Items_IsPokeFlutePlaying) {
        Items_FluteSongIndex++;
        if (Items_FluteSongIndex >= 3) {
            Items_FluteSongIndex -= 3;
        }
    }
    auStopSong(BGM_PLAYER_MAIN);
    auPlaySong(BGM_PLAYER_MAIN, Items_FluteSongsList[Items_FluteSongIndex]);
    Items_IsPokeFlutePlaying = true;
    Items_SongStartTime = D_80096968;
}

void Items_StopPokeFlute(void) {
    s32 temp_t8;

    if (Items_IsPokeFlutePlaying) {
        auStopSong(BGM_PLAYER_MAIN);
    }
    Items_IsPokeFlutePlaying = false;
    Items_SongStartTime = D_80096968;
}

s32 Items_GetPokeFluteCmd(void) {
    if (Items_IsPokeFlutePlaying) {
        return Items_FluteCommandIds[Items_FluteSongIndex];
    } else {
        return 0;
    }
}

s32 Items_GetPokeFluteState(void) {
    if (Items_SongStartTime != D_80096968) {
        return auIsBGMPlaying(BGM_PLAYER_MAIN);
    } else {
        return -1;
    }
}

void Items_DoRemoveItem(GObj* obj) {
    Pokemon_SendDieCommand(obj);
    Pokemon_FreeItem(obj->userData);
    omDeleteGObj(obj);
}

void Items_DeleteItem(GObj* obj) {
    Item* item;

    if (obj == NULL) {
        return;
    }
    item = GET_ITEM(obj);
    if (item->state == ITEM_STATE_INVALID || (item->flags & ITEM_FLAG_DELETED)) {
        return;
    }

    item->flags |= ITEM_FLAG_DELETED;
    Items_UnlinkObject(obj);
    obj->flags |= GOBJ_FLAG_HIDDEN;
    Items_EndProcessByFunction(obj, Items_ShowDelayed);
    omCreateProcess(obj, Items_DoRemoveItem, 1, 4);
    Items_TotalItemCount--;
    if (item->itemID == ITEM_ID_PESTER_BALL) {
        Items_PesterBallCount--;
    } else {
        Items_AppleCount--;
    }
    item->state = ITEM_STATE_INVALID;
}

void Items_SetCustomFunctions(GObjFunc fnUpdate, u8 kind, void (*fnCollide)(GObj*, GroundResult*)) {
    if (fnUpdate != NULL) {
        Items_FnUpdate = fnUpdate;
        Items_FnUpdateKind = kind;
        return;
    }
    Items_FnUpdate = Items_UpdateItemMovement;
    Items_FnUpdateKind = 1;
    if (fnCollide != NULL) {
        Items_FnCollide = fnCollide;
    }
}

void Items_func_8035CA1C(s32 (*arg0)(Vec3f*, Vec3f*, Vec3f*, Vec3f*)) {
    D_80382EBC_5232CC = arg0;
}

void Items_Pause(void) {
    GObj* ptr;

    ptr = omGObjListHead[LINK_ITEM];
    while (ptr != NULL) {
        ohPauseObjectProcesses(ptr);
        ptr = ptr->next;
    }
}

void Items_UnPause(void) {
    GObj* ptr;

    ptr = omGObjListHead[LINK_ITEM];
    while (ptr != NULL) {
        ohResumeObjectProcesses(ptr);
        ptr = ptr->next;
    }
}

void Items_RemoveFlyingItems(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(Items_ListEntryArray); i++) {
        if (Items_ListEntryArray[i].obj != NULL && !(GET_ITEM(Items_ListEntryArray[i].obj)->flags & ITEM_FLAG_TOUCHED_GROUND)) {
            Items_DeleteItem(Items_ListEntryArray[i].obj);
        }
    }
}

void Items_DisplaceAllItems(f32 deltaX, f32 deltaY, f32 deltaZ) {
    GObj* ptr;
    Item* item;

    ptr = omGObjListHead[LINK_ITEM];
    while (ptr != NULL) {
        DObj* model = ptr->data.dobj;

        model->position.v.x += deltaX;
        model->position.v.y += deltaY;
        model->position.v.z += deltaZ;
        item = GET_ITEM(ptr);
        if (item != NULL) {
            item->prevPos.x += deltaX;
            item->prevPos.y += deltaY;
            item->prevPos.z += deltaZ;
        }
        ptr = ptr->next;
    }
}
