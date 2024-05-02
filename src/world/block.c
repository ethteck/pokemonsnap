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
// split
extern UnkVioletMarlin* D_800E6B10_642C0;
extern s32 D_800E6B14_642C4;

// bss
static char D_800F5A00_731B0[8]; // padding
static WorldBlock* worldBlocks[13];
static WorldBlock worldBlockArray[13];
static DObj* D_800F5BB0_73360[13 * 3];
static UnkAquamarineCoyote D_800F5C50_73400[14];
static char D_800F5CF8_734A8[0x48];

#ifdef NON_MATCHING
// setWorldBlocksVisibility
void func_800E18A0_5F050(u32 visibilityMask) {
    s32 i;

    for (i = 0; i <= 30 && i < 13; i++) {
        if (worldBlocks[i] == NULL) {
            break;
        }

        if (worldBlocks[i]->blockModel != NULL) {
            if (visibilityMask & 1) {
                worldBlocks[i]->blockModel->flags &= ~GOBJ_FLAG_HIDDEN;
            } else {
                worldBlocks[i]->blockModel->flags |= GOBJ_FLAG_HIDDEN;
            }
            visibilityMask >>= 1;
        }
    }
}
#else
void func_800E18A0_5F050(u32 arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/world/block/func_800E18A0_5F050.s")
#endif

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
        func_800E18A0_5F050(arg2);
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

void func_800E20B4_5F864(void) {
    if (SkyBoxObject != NULL && SkyBoxObject->data.dobj != NULL) {
        omCreateProcess(SkyBoxObject, &func_800E206C_5F81C, 1, 0);
    }
}

void func_800E20F8_5F8A8(f32 posX, f32 posY, f32 posZ, f32 yaw, f32 animationTime) {

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

f32 func_800E219C_5F94C(void) {
    return SkyBoxAnimationPhase;
}

f32 func_800E21A8_5F958(f32 arg0) {
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

#ifdef NON_MATCHING
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

    x1 = arg0->descriptor->unk_04.x;
    y1 = arg0->descriptor->unk_04.y;
    z1 = arg0->descriptor->unk_04.z;

    arg0->blockModel->data.dobj->position.v.x = (x1 - arg1->descriptor->unk_04.x) * 100.0f;
    arg0->blockModel->data.dobj->position.v.y = (y1 - arg1->descriptor->unk_04.y) * 100.0f;
    arg0->blockModel->data.dobj->position.v.z = (z1 - arg1->descriptor->unk_04.z) * 100.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/world/block/func_800E21E4_5F994.s")
void func_800E21E4_5F994(WorldBlock* arg0, WorldBlock* arg1);
#endif

void func_800E2280_5FA30(WorldBlock* arg0) {
    s32 i;

    for (i = 0; i < 13; i++) {
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
        if (next->index + i >= 13) {
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

    animSetModelTreeTextureAnimation(obj, block->descriptor->gfx->unk_08, func_800E21A8_5F958(SkyBoxAnimationPhase));
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
               &func_800A1530 == block->descriptor->gfx->renderFunc || 
               &renRenderModelTypeC == block->descriptor->gfx->renderFunc || 
               &func_800A1590 == block->descriptor->gfx->renderFunc)
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
               &func_800A15D8 == block->descriptor->gfx->renderFunc || 
               &renRenderModelTypeD == block->descriptor->gfx->renderFunc || 
               &func_800A1608 == block->descriptor->gfx->renderFunc)
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
    obj->fnAnimCallback = &func_800E19A4_5F154;
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

    for (i = 0; i < 13; i++) {
        worldBlocks[i] = NULL;
    }

    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return NULL;
    }
    ptr = arg0->unk_00;
    createSkyBox(arg0->skybox);
    
    for (i = 0; i < 13; i++) {
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

    for (i = num1; i < 13; i++) {
        if (ptr[i - num1] == 0) {
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

    if (i >= 13) {
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

s32 func_800E2F38_606E8(UnkTomatoEagle* arg0, s32 skyBoxObjId, s32 blockMinObjId, s32 blockMaxObjId, s32 link, s32 dllink, BlockFunc2 arg6, BlockFunc arg7, BlockFunc2 arg8) {
    func_800E1924_5F0D4();
    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return FALSE;
    }
    func_800E354C_60CFC(arg0->unk_04, arg0->unk_08);
    func_800E66BC_63E6C(arg0->unk_0C);
    func_800A18AC(arg0->unk_14, arg0->unk_16);
    func_800A181C(arg0->unk_18, arg0->unk_19, arg0->unk_1A);
    func_800A1780(arg0->unk_1B, arg0->unk_1C, arg0->unk_1D);
    createWorldBlocks(arg0->unk_00, skyBoxObjId, blockMinObjId, blockMaxObjId, link, dllink, arg6, arg7, arg8);
    func_800E1A78_5F228(arg0->unk_10);
    return TRUE;
}

void clearWorldBlocks(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        if (worldBlocks[i] != NULL) {
            clearWorldBlock(worldBlocks[i]);
        }
    }
}

void func_800E3064_60814(void) {
    func_800E1924_5F0D4();
    clearWorldBlocks();
    if (SkyBoxObject != NULL) {
        omDeleteGObj(SkyBoxObject);
        SkyBoxObject = NULL;
    }
    SkyBoxAnimation = NULL;
}

void func_800E30B0_60860(WorldBlock* block, UnkBeigeServal* arg1, PayloadStruct arg2) {
    if (block->blockModel->fnRender == &renRenderModelTypeA ||
        block->blockModel->fnRender == &func_800A1530 || 
        block->blockModel->fnRender == &renRenderModelTypeB || 
        block->blockModel->fnRender == &func_800A15D8)
    {
        DObj* child = omDObjAddChild(block->blockModel->data.dobj, arg2.d.gfx);
        s32 unused[2];

        if (arg1->unk_1C.x == 1.0f && arg1->unk_1C.y == 1.0f && arg1->unk_1C.z == 1.0f) {
            omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE, 1);
            child->scale.v.x = 1.0f;
            child->scale.v.y = 1.0f;
            child->scale.v.z = 1.0f;
        } else {
            omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 1);
            child->scale.v.x = arg1->unk_1C.x;
            child->scale.v.y = arg1->unk_1C.y;
            child->scale.v.z = arg1->unk_1C.z;
        }

        child->position.v.x = arg1->unk_04.x * 100.0f;
        child->position.v.y = arg1->unk_04.y * 100.0f;
        child->position.v.z = arg1->unk_04.z * 100.0f;

        child->rotation.f[1] = arg1->unk_10.x;
        child->rotation.f[2] = arg1->unk_10.y;
        child->rotation.f[3] = arg1->unk_10.z;

        if (block->blockModel->fnRender == &renRenderModelTypeA) {
            block->blockModel->fnRender = &renRenderModelTypeB;
        } else if (block->blockModel->fnRender == &func_800A1530) {
            block->blockModel->fnRender = &func_800A15D8;
        }
    }
}

void func_800E3258_60A08(WorldBlock* block, UnkBeigeServal* arg1, PayloadStruct arg2) {
    UnkEC64Arg3* treePtr = arg2.d.treeDef;

    if (block->blockModel->fnRender == &renRenderModelTypeA ||
        block->blockModel->fnRender == &renRenderModelTypeB)
    {
        s32 unused;
        s32 i;
        DObj* sp54[18];
        DObj* child;        

        for (i = 0; i < ARRAY_COUNT(sp54); i++) {
            sp54[i] = NULL;
        }

        while (treePtr->unk_00 != 18) {
            if (treePtr->unk_00 != 0) {
                child = sp54[treePtr->unk_00] = omDObjAddChild(sp54[treePtr->unk_00 - 1], treePtr->unk04);
            } else {
                child = sp54[0] = omDObjAddChild(block->blockModel->data.dobj, treePtr->unk04);
            }

            if (arg1->unk_1C.x == 1.0f && arg1->unk_1C.y == 1.0f && arg1->unk_1C.z == 1.0f) {
                omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE, 1);
                child->scale.v.z = 1.0f;
                child->scale.v.y = 1.0f;
                child->scale.v.x = 1.0f;
            } else {
                child->scale.v.x = arg1->unk_1C.x;
                child->scale.v.y = arg1->unk_1C.y;
                child->scale.v.z = arg1->unk_1C.z;
                omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 1);                
            }

            child->position.v.x = arg1->unk_04.x * 100.0f;
            child->position.v.y = arg1->unk_04.y * 100.0f;
            child->position.v.z = arg1->unk_04.z * 100.0f;

            child->rotation.f[1] = arg1->unk_10.x;
            child->rotation.f[2] = arg1->unk_10.y;
            child->rotation.f[3] = arg1->unk_10.z;

            treePtr++;
        }

        if (block->blockModel->fnRender == &renRenderModelTypeA) {
            block->blockModel->fnRender = &renRenderModelTypeB;
        }
    }
}

void func_800E3464_60C14(WorldBlock* arg0) {
    UnkBeigeServal* s2;
    s32 i;

    if (arg0 == NULL || arg0->descriptor == NULL || arg0->descriptor->unk_18 == NULL || arg0->index >= 13) {
        return;
    }

    s2 = arg0->descriptor->unk_18;
    while (s2->unk_00 != -1) {
        for (i = 0; i < 100; i++) {
            if (D_800E6B10_642C0[i].unk_00 == -1) {
                break;
            }
            if (D_800E6B10_642C0[i].unk_00 == s2->unk_00 && D_800E6B10_642C0[i].unk_04 != NULL && D_800E6B10_642C0[i].unk_08.d.gfx != NULL) {
                D_800E6B10_642C0[i].unk_04(arg0, s2, D_800E6B10_642C0[i].unk_08);
                break;
            }

        }
        s2++;
    }
}

void func_800E354C_60CFC(UnkVioletMarlin* arg0, s32 arg1) {
    D_800E6B10_642C0 = arg0;
    D_800E6B14_642C4 = arg1;
}
