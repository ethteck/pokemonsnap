#include "world.h"

void func_800E354C_60CFC(UnkVioletMarlin*, s32);
void func_800E3464_60C14(WorldBlock*);

typedef struct UnkAquamarineCoyote {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} UnkAquamarineCoyote; // size=0x0C

// data
WorldBlock* D_800E6AD0_64280 = NULL;
u32 SkyBoxObjectId = 0;
s32 WorldBlockMinObjId = 0;
u32 WorldBlockMaxObjId = 0;
u32 WorldLink = 0;
u32 WorldDlLink = 0;
GObj* SkyBoxObject = NULL;
f32 SkyBoxAnimationPhase = 0.0f;
f32 SkyBoxAnimationSpeed = 1.0f;
s32 SkyBoxMaxAngle = 10000;
AnimCmd*** SkyBoxAnimation = NULL;
BlockFunc2 D_800E6AFC_642AC = NULL;
BlockFunc WorldBlockDeleteCb = NULL;
BlockFunc2 D_800E6B04_642B4 = NULL;

// bss
static char D_800F5A00_731B0[8]; // padding
static WorldBlock* worldBlocks[MAX_BLOCKS];
static WorldBlock worldBlockArray[MAX_BLOCKS];
static DObj* D_800F5BB0_73360[MAX_BLOCKS * 3];
static UnkAquamarineCoyote D_800F5C50_73400[14];
static char D_800F5CF8_734A8[0x48];

void setWorldBlocksVisibility(u32 visibilityMask) {
    s32 i;

    for (i = 0; i < 31 && i < MAX_BLOCKS; i++) {
        if (worldBlocks[i] == NULL) {
            break;
        }

        if (worldBlocks[i]->blockModel == NULL) {
            continue;
        }

        if (visibilityMask & 1) {
            worldBlocks[i]->blockModel->flags &= ~GOBJ_FLAG_HIDDEN;
        } else {
            worldBlocks[i]->blockModel->flags |= GOBJ_FLAG_HIDDEN;
        }
        visibilityMask >>= 1;
    }
}

void func_800E1924_5F0D4(void) {
    s32 i;

    for (i = 0; i < 14; i++) {
        D_800F5C50_73400[i].unk_00 = -1.0f;
        D_800F5C50_73400[i].unk_04 = 0.0f;
        D_800F5C50_73400[i].unk_08 = 0.0f;
    }
}

void func_800E19A4_5F154(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 >= 0 && arg1 < 14) {
        f32 animationTime = arg0->obj->animationTime;
        D_800F5C50_73400[arg1].unk_00 = animationTime;
        D_800F5C50_73400[arg1].unk_04 = arg2;
        setWorldBlocksVisibility(arg2);
    }   
}

void func_800E1A78_5F228(f32 arg0) {
    SkyBoxAnimationSpeed = arg0;
    if (SkyBoxAnimation != NULL) {
        animSetTextureAnimationSpeed(SkyBoxObject, arg0);
    }
}

f32 func_800E1AB4_5F264(f32 arg0, s32 arg1) {
    while (arg0 < 0.0f) {
        arg0 += arg1;
    }
    
    arg0 *= 10000.0;
    arg0 = ((s32)arg0 + 5) / 10;
    arg0 /= 1000.0;

    while (arg0 >= arg1) {
        arg0 -= arg1;
    }

    return arg0;
}

void updateSkyBoxRotation(GObj* arg0) {
    SkyBoxAnimationPhase += SkyBoxAnimationSpeed;
    SkyBoxAnimationPhase = func_800E1AB4_5F264(SkyBoxAnimationPhase, SkyBoxMaxAngle);
}

void func_800E1BB8_5F368(GObj* obj) {
    void (*userData)(GObj*) = obj->userData;
    if (userData != &renRenderModelTypeA) {
        return;
    }

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2)
    gSPClearGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gSPSetGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
}

void drawSkyBox1Cycle(GObj* obj) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2)
    gSPClearGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gSPSetGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
}

void drawSkyBox2Cycle(GObj* obj) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gSPSetGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
}

void setSkyBoxRotation(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    dobj->rotation.f[2] = 6.283185482f * SkyBoxAnimationPhase /  SkyBoxMaxAngle;
}

void createSkyBox(SkyBox* skyBox) {
    GObj* obj;
    DObj* dobj;

    obj = omAddGObj(SkyBoxObjectId, &ohUpdateDefault, WorldLink, 0x80000000);
    SkyBoxObject  = obj;
    omCreateProcess(obj, &updateSkyBoxRotation, 1, 2);

    if (skyBox == NULL || skyBox->gfxData == NULL) {
        return;
    }

    if (skyBox->renderFunc == NULL || skyBox->renderFunc != &drawSkyBox1Cycle && skyBox->renderFunc != &drawSkyBox2Cycle) {
        return;
    }

    omLinkGObjDL(obj, skyBox->renderFunc, WorldDlLink, 0x80000001, -1);
    omGObjAddDObj(obj, skyBox->gfxData);
    if (skyBox->renderFunc == &drawSkyBox2Cycle) {
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_ROTATE_RPY_TRANSLATE, 0);
    } else {
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_TRANSLATE, 0);
    }

    if (skyBox->textures != NULL) {
        Texture** ptr = *skyBox->textures;
        Texture* curr = *ptr;
        while (curr != NULL) {
            omDObjAddMObj(obj->data.dobj, curr);
            ptr++;
            curr = *ptr; 
        }
    }

    if (skyBox->animation != NULL) {
        SkyBoxAnimation = skyBox->animation;
        omCreateProcess(obj, &animUpdateModelTreeAnimation, 1, 1);
        animSetModelTreeTextureAnimation(obj, skyBox->animation, 0);
        animSetTextureAnimationSpeed(obj, skyBox->animationSpeed);
    }

    if (skyBox->renderFunc == &drawSkyBox2Cycle) {
        omCreateProcess(obj, &setSkyBoxRotation, 1, 1);
    }

    dobj = obj->data.dobj;
    dobj->position.v.z = 0.0f;
    dobj->position.v.y = 0.0f;
    dobj->position.v.x = 0.0f;
}

void func_800E206C_5F81C(GObj* obj) {
    OMCamera* v0 = func_803586F8_4F8B08();

    obj->data.dobj->position.v.x = v0->viewMtx.lookAt.eye.x;
    obj->data.dobj->position.v.y = v0->viewMtx.lookAt.eye.y;
    obj->data.dobj->position.v.z = v0->viewMtx.lookAt.eye.z;
}

void setSkyBoxFollowPlayer(void) {
    if (SkyBoxObject != NULL && SkyBoxObject->data.dobj != NULL) {
        omCreateProcess(SkyBoxObject, &func_800E206C_5F81C, 1, 0);
    }
}

void setSkyBoxPos(f32 posX, f32 posY, f32 posZ, f32 yaw, f32 animationTime) {
    if (SkyBoxObject != NULL && SkyBoxObject->data.dobj != NULL) {
        SkyBoxObject->data.dobj->position.v.x = posX;
        SkyBoxObject->data.dobj->position.v.y = posY;
        SkyBoxObject->data.dobj->position.v.z = posZ;
    }

    SkyBoxObject->data.dobj->rotation.f[2] = yaw;

    if (SkyBoxAnimation != NULL) {
        animSetModelTreeTextureAnimation(SkyBoxObject, SkyBoxAnimation, animationTime);
    }
}

WorldBlock* getCurrentWorldBlock(void) {
    return D_800E6AD0_64280;
}

WorldBlock** getWorldBlocks(void) {
    return worldBlocks;
}

f32 world_func_800E219C(void) {
    return SkyBoxAnimationPhase;
}

f32 world_func_800E21A8(f32 arg0) {
    while (TRUE) {
        if (arg0 < 100.0f) {
            return arg0;
        }
        arg0 -= 100.0f;
    }
    return arg0;
}

static void nullsub() {
    
}

void func_800E21E4_5F994(WorldBlock* arg0, WorldBlock* arg1) {
    f32 x1, y1, z1;

    if (arg0 == NULL ||
        arg0->descriptor == NULL ||
        arg1 == NULL ||
        arg0->blockModel == NULL ||
        arg0->blockModel->data.dobj == NULL)
    {
        return;
    }

    x1 = arg1->descriptor->unk_04.x;
    y1 = arg1->descriptor->unk_04.y;
    z1 = arg1->descriptor->unk_04.z;

    arg0->blockModel->data.dobj->position.v.x = (arg0->descriptor->unk_04.x - x1) * 100.0f;
    arg0->blockModel->data.dobj->position.v.y = (arg0->descriptor->unk_04.y - y1) * 100.0f;
    arg0->blockModel->data.dobj->position.v.z = (arg0->descriptor->unk_04.z - z1) * 100.0f;
}

void func_800E2280_5FA30(WorldBlock* arg0) {
    s32 i;

    for (i = 0; i < MAX_BLOCKS; i++) {
        if (worldBlocks[i] == NULL) {
            break;
        }
        func_800E21E4_5F994(worldBlocks[i], arg0);
    }
}

void clearWorldBlock(WorldBlock* arg0) {
    if (arg0 != NULL) {
        if (WorldBlockDeleteCb != NULL) {
            WorldBlockDeleteCb(arg0);
        }
        if (arg0->blockModel != NULL) {
            omDeleteGObj(arg0->blockModel);
        }
        if (arg0->blockUV != NULL) {
            omDeleteGObj(arg0->blockUV);
        }
        arg0->blockModel = NULL;
        arg0->blockUV = NULL;
    }
}

void func_800E2354_5FB04(WorldBlock* arg0) {
    s32 i;

    if (arg0 != NULL) {
        for (i = 0; i < 1; i++) {
            arg0 = arg0->prev;
            if (arg0 == NULL) {
                return;
            }
        }
        if (WorldBlockDeleteCb != NULL) {
            WorldBlockDeleteCb(arg0);
        }
    }    
}

void func_800E23A8_5FB58(WorldBlock* arg0) {
    s32 i;

    if (arg0 != NULL) {
        WorldBlock* next = arg0;
        for (i = 0; i < 1; i++) {
            next = next->next;
            if (next == NULL) {
                return;
            }
        }
        if (D_800E6AFC_642AC != NULL) {
            D_800E6AFC_642AC(next, arg0);
        }
    }    
}

WorldBlock* func_800E2400_5FBB0(void) {
    WorldBlock* curr;
    WorldBlock* next;
    s32 i;

    curr = D_800E6AD0_64280;
    if (curr == NULL || curr->next == NULL) {
        return NULL;
    }
    next = curr->next;
    D_800E6AD0_64280 = next;
    func_8035024C_4F065C((curr->descriptor->unk_04.x - next->descriptor->unk_04.x) * 100.0f,
                         (curr->descriptor->unk_04.y - next->descriptor->unk_04.y) * 100.0f,
                         (curr->descriptor->unk_04.z - next->descriptor->unk_04.z) * 100.0f);
    func_800A71F8((curr->descriptor->unk_04.x - next->descriptor->unk_04.x) * 100.0f,
                         (curr->descriptor->unk_04.y - next->descriptor->unk_04.y) * 100.0f,
                         (curr->descriptor->unk_04.z - next->descriptor->unk_04.z) * 100.0f);

    func_800E2280_5FA30(next);
    func_800E2354_5FB04(curr);
    func_800E23A8_5FB58(next);

    for (i = 0; i <= curr->index; i++) {
        if (worldBlocks[i] == NULL) {
            break;
        }
        if (D_800E6B04_642B4 != NULL) {
            D_800E6B04_642B4(worldBlocks[i], next);
        }
    }

    for (i = 0; i < 1; i++) {
        if (next->index + i >= MAX_BLOCKS) {
            break;
        }
        if (worldBlocks[next->index + i] == NULL) {
            break;
        }
        if (D_800E6B04_642B4 != NULL) {
            D_800E6B04_642B4(worldBlocks[next->index + i], next);
        }
    }

    return D_800E6AD0_64280;
}

WorldBlock* func_800E25E4_5FD94(WorldBlock* arg0) {
    s32 i;
    WorldBlock* v1;

    if (arg0 == NULL) {
        return NULL;
    }

    D_800E6AD0_64280 = arg0;
    func_800E2280_5FA30(arg0);
    if (D_800E6AFC_642AC != NULL) {
        D_800E6AFC_642AC(arg0, arg0);
    }
    
    for (i = -1; i >= -1;i--) {
        if (arg0->prev == NULL) {
            break;
        }
        v1 = arg0->prev;
        if (D_800E6AFC_642AC != NULL) {
            D_800E6AFC_642AC(v1, arg0);
        }
    }

    for (i = 1; i <= 1;i++) {
        if (arg0->next == NULL) {
            break;
        }
        v1 = arg0->next;
        if (D_800E6AFC_642AC != NULL) {
            D_800E6AFC_642AC(v1, arg0);
        }
    }

    return arg0;
}

WorldBlock* func_800E26CC_5FE7C(s32 arg0) {
    if (worldBlocks[arg0] == NULL) {
        return NULL;
    }
    return func_800E25E4_5FD94(worldBlocks[arg0]);
}

void func_800E270C_5FEBC(GObj* obj) {
    WorldBlock* block;
    u32 index = obj->id;    

    index = (index - WorldBlockMinObjId) / 2;
    block = worldBlocks[index];

    if (block == NULL ||
        block->blockModel == NULL ||
        block->descriptor == NULL ||
        block->descriptor->gfx == NULL ||
        block->descriptor->gfx->unk_08 == NULL)
    {
        return;
    }

    animSetModelTreeTextureAnimation(obj, block->descriptor->gfx->unk_08, world_func_800E21A8(SkyBoxAnimationPhase));
    animSetTextureAnimationSpeed(obj, 0.0f);
    animUpdateModelTreeAnimation(obj);
}

GObj* createWorldBlockModel(WorldBlock* block) {
    s32 id;
    GObj* obj;
    DObj* dobj;
    Texture** ptr;
    Texture* curr;
    u32 priority = 0x80000000;

    if (block == NULL || block->descriptor == NULL || block->descriptor->gfx == NULL || block->descriptor->gfx->gfxData == NULL) {
        return NULL;
    }

    id = block->index * 2 + WorldBlockMinObjId;
    if (!inRange_DEBUG(id, WorldBlockMinObjId, WorldBlockMaxObjId, "blockModelCreate()")) {
        return NULL;
    }

    obj = omAddGObj(id, &ohUpdateDefault, WorldLink, priority);
    omLinkGObjDL(obj, block->descriptor->gfx->renderFunc, WorldDlLink, priority, -1);

    if (&drawSkyBox2Cycle == block->descriptor->gfx->renderFunc) {
        omGObjAddDObj(obj, block->descriptor->gfx->gfxData);
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_ROTATE_RPY_TRANSLATE, 0);
        if (block->descriptor->gfx->textures != NULL) {
            ptr = *block->descriptor->gfx->textures;
            curr = *ptr;
            while (curr != NULL) {
                omDObjAddMObj(obj->data.dobj, curr);
                ptr++;
                curr = *ptr; 
            }
        }
    } else if (&renRenderModelTypeA == block->descriptor->gfx->renderFunc ||
               &renderModelTypeAFogged == block->descriptor->gfx->renderFunc || 
               &renRenderModelTypeC == block->descriptor->gfx->renderFunc || 
               &renderModelTypeCFogged == block->descriptor->gfx->renderFunc)
    {
        omGObjAddDObj(obj, block->descriptor->gfx->gfxData);
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_TRANSLATE, 0);
        if (block->descriptor->gfx->textures != NULL) {
            ptr = *block->descriptor->gfx->textures;
            curr = *ptr;
            while (curr != NULL) {
                omDObjAddMObj(obj->data.dobj, curr);
                ptr++;
                curr = *ptr; 
            }
        }
    } else if (&renRenderModelTypeB == block->descriptor->gfx->renderFunc ||
               &renderModelTypeBFogged == block->descriptor->gfx->renderFunc || 
               &renRenderModelTypeD == block->descriptor->gfx->renderFunc || 
               &renderModelTypeDFogged == block->descriptor->gfx->renderFunc)
    {
        anim_func_80010230(obj, block->descriptor->gfx->gfxData, block->descriptor->gfx->textures, NULL, 0, 0, 0);
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_TRANSLATE, 0);
    } else {
        omDeleteGObj(obj);
        return NULL;
    }

    if (block != NULL && block->descriptor != NULL && block->descriptor->gfx != NULL && block->descriptor->gfx->unk_08 != NULL) {
        omCreateProcess(obj, &func_800E270C_5FEBC, 1, 1);
    }

    dobj = obj->data.dobj;
    dobj->rotation.f[2] = block->descriptor->yaw;
    dobj->rotation.f[1] = dobj->rotation.f[3] = 0.0f;
    dobj->scale.v.x = dobj->scale.v.y = dobj->scale.v.z = 1.0f;
    return obj;
}

GObj* createWorldBlockUV(WorldBlock* block) {
    s32 id;
    GObj* obj;
    f32 skipFrames;
    
    if (block == NULL || block->descriptor == NULL || block->descriptor->gfx == NULL) {
        return NULL;
    }
    if (block->descriptor->gfx->unk_14 < 2) {
        return NULL;
    }

    id = block->index * 2 + 1 + WorldBlockMinObjId;
    if (!inRange_DEBUG(id, WorldBlockMinObjId, WorldBlockMaxObjId, "blockUVCreate()")) {
        return NULL;
    }

    obj = omAddGObj(id, &ohUpdateDefault, WorldLink, 0x80000000);
    omLinkGObjDL(obj, renRenderModelTypeB, WorldDlLink, 0x80000000, -1);
    anim_func_8000FBC4(obj, block->descriptor->gfx->uvScrollAnim, block->unk_18);
    animSetModelAnimationSpeed(obj, 0.0f);
    if (block->descriptor->unk_14 != 0) {
        skipFrames = block->descriptor->gfx->unk_1C;
    } else {
        skipFrames = 0.0f;
    }
    animSetModelTreeAnimation(obj, block->descriptor->gfx->unk_18, skipFrames);
    animUpdateModelTreeAnimation(obj);
    obj->fnAnimCallback = func_800E19A4_5F154;
    return obj;
}

WorldBlock** createWorldBlocks(UnkBoneFox* arg0, s32 skyBoxObjId, s32 blockMinObjId, s32 blockMaxObjId, s32 link, s32 dlLink, BlockFunc2 arg6, BlockFunc deleteCb, BlockFunc2 arg8) {
    s32 i;
    s32 num1;
    WorldBlock* s0;
    WorldBlockDescriptor** ptr;

    SkyBoxObjectId = skyBoxObjId;
    WorldBlockMinObjId = blockMinObjId;
    WorldBlockMaxObjId = blockMaxObjId;
    WorldLink = link;
    WorldDlLink = dlLink;
    D_800E6AFC_642AC = arg6;
    WorldBlockDeleteCb = deleteCb;
    D_800E6B04_642B4 = arg8;

    for (i = 0; i < MAX_BLOCKS; i++) {
        worldBlocks[i] = NULL;
    }

    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return NULL;
    }
    ptr = arg0->unk_00;
    createSkyBox(arg0->skybox);
    
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (ptr[i] == NULL) {
            break;
        }

        if (i > 0 && ptr[i] == ptr[0]) {
            worldBlocks[0]->prev = worldBlocks[i - 1];
            if (1) {

            }
            worldBlocks[i - 1]->next = worldBlocks[0];
            break;
        }

        s0 = &worldBlockArray[i];
        s0->index = i;
        s0->descriptor = ptr[i];
        if (i > 0) {
            if (s0) { } // TODO fake match
            s0->prev = worldBlocks[i - 1];
        } else {
            s0->prev = NULL;
        }
        s0->next = NULL;
        if (s0->descriptor->gfx->unk_14 <= 0 || s0->descriptor->gfx->unk_14 >= 4) {
            s0->unk_18 = NULL;
        } else {
            s0->unk_18 = &D_800F5BB0_73360[3 * i];
        }

        s0->blockModel = createWorldBlockModel(s0);
        s0->blockUV = createWorldBlockUV(s0);
        worldBlocks[i] = s0;
        func_800E3464_60C14(s0);
        if (s0->prev != NULL) {
            s0->prev->next = s0;
        }
    }

    num1 = i;

    if (arg0->unk_04 == NULL) {
        return worldBlocks;
    }
    ptr = arg0->unk_04;

    for (i = num1; i < MAX_BLOCKS; i++) {
        if (ptr[i - num1] == NULL) {
            break;
        }

        s0 = &worldBlockArray[i];
        s0->index = i;
        s0->descriptor = ptr[i - num1];
        s0->prev = NULL;
        s0->next = NULL;
        if (1) { } if (1) { } // TODO fake match
        s0->blockModel = createWorldBlockModel(s0);
        s0->blockUV = NULL;
        s0->unk_18 = NULL;
        worldBlocks[i] = s0;
        func_800E3464_60C14(s0);
    }

    if (i >= MAX_BLOCKS) {
        return NULL;
    }

    s0 = worldBlocks[0];
    if (s0 != NULL &&
        s0->blockUV != NULL &&
        s0->descriptor != NULL &&
        s0->descriptor->gfx != NULL &&
        s0->descriptor->gfx->unk_18 != NULL
        )
    {
        animSetModelTreeAnimation(s0->blockUV, s0->descriptor->gfx->unk_18, 0);
        animUpdateModelTreeAnimation(s0->blockUV);
    }

    return worldBlocks;
}

s32 createWorld(WorldSetup* arg0, s32 skyBoxObjId, s32 blockMinObjId, s32 blockMaxObjId, s32 link, s32 dllink, BlockFunc2 arg6, BlockFunc arg7, BlockFunc2 arg8) {
    func_800E1924_5F0D4();
    if (arg0 == NULL || arg0->blocksSetup == NULL) {
        return FALSE;
    }
    func_800E354C_60CFC(arg0->unk_04, arg0->unk_08);
    func_800E66BC_63E6C(arg0->unk_0C);
    setFogDistance(arg0->fogDistanceMin, arg0->fogDistanceMax);
    setFogColor(arg0->fogR, arg0->fogG, arg0->fogB);
    setBackgroundColor(arg0->backgroundR, arg0->backgroundG, arg0->backgroundB);
    createWorldBlocks(arg0->blocksSetup, skyBoxObjId, blockMinObjId, blockMaxObjId, link, dllink, arg6, arg7, arg8);
    func_800E1A78_5F228(arg0->unk_10);
    return TRUE;
}

void clearWorldBlocks(void) {
    s32 i;

    for (i = 0; i < MAX_BLOCKS; i++) {
        if (worldBlocks[i] != NULL) {
            clearWorldBlock(worldBlocks[i]);
        }
    }
}

void destroyWorld(void) {
    func_800E1924_5F0D4();
    clearWorldBlocks();
    if (SkyBoxObject != NULL) {
        omDeleteGObj(SkyBoxObject);
        SkyBoxObject = NULL;
    }
    SkyBoxAnimation = NULL;
}
