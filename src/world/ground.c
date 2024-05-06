#include "world.h"

HeightMap* sHeightMap = NULL;
HeightMap* D_800E6B34_642E4 = NULL;

s32 setHeightMap(HeightMap* arg0) {
    HeightMapPatch* unk_00;
    HeightMapTreeNode* tree;

    if (arg0 == NULL) {
        return FALSE;
    }
    if (arg0->tree == NULL || arg0->patches == NULL) {
        return FALSE;
    }
    sHeightMap = arg0;
    tree = sHeightMap->tree;
    unk_00 = sHeightMap->patches;    
    createHeightMapTree(tree, unk_00);
    return TRUE;
}

s32 world_func_800E40A4(HeightMap* arg0) {
    HeightMapPatch* unk_00;
    HeightMapTreeNode* unk_04;

    if (arg0 == NULL) {
        return FALSE;
    }
    if (arg0->tree == NULL || arg0->patches == NULL) {
        return FALSE;
    }
    D_800E6B34_642E4 = arg0;
    unk_04 = D_800E6B34_642E4->tree;
    unk_00 = D_800E6B34_642E4->patches;    
    createHeightMapTree(unk_04, unk_00);
    return TRUE;
}

void setDefaultGroundResult(GroundResult* result) {
    result->height = -9000.0f;
    result->normal.x = 0.0f;
    result->normal.y = 1.0f;
    result->normal.z = 0.0f;
    result->type = -1;
}

s32 getGroundAtGlobal(f32 x, f32 z, GroundResult* result) {
    HeightMapPatch* patch;
    Vec3f* normal;

    if (sHeightMap == NULL) {
        setDefaultGroundResult(result);
        return FALSE;
    }

    patch = findHeightMapPatch(sHeightMap->tree, x, z);
    result->height = getPatchHeightAt(patch, x, z);
    normal = getPatchNormal(patch);
    result->normal.x = normal->x;
    result->normal.y = normal->z; // z is UP
    result->normal.z = normal->y;
    result->type = getPatchSurfaceType(patch);
    return TRUE;
}

s32 getGroundAt(f32 x, f32 z, GroundResult* result) {
    WorldBlock* block = getCurrentWorldBlock();

    if (block == NULL || block->descriptor == NULL || sHeightMap == NULL) {
        setDefaultGroundResult(result);
        return FALSE;
    }

    x /= 100.0f;
    z /= 100.0f;
    x = x + block->descriptor->unk_04.x;
    z = z + block->descriptor->unk_04.z;
    if (!getGroundAtGlobal(x, z, result)) {
        setDefaultGroundResult(result);
        return FALSE;
    }

    result->height -= block->descriptor->unk_04.y;
    result->height *= 100.0f;
    return TRUE;
}

s32 func_800E42BC_61A6C(f32 arg0, f32 arg1, GroundResult* result) {
    HeightMapPatch* sp24;
    Vec3f* v0;

    if (D_800E6B34_642E4 == NULL) {
        setDefaultGroundResult(result);
        return FALSE;
    }

    sp24 = findHeightMapPatch(D_800E6B34_642E4->tree, arg0, arg1);
    result->height = getPatchHeightAt(sp24, arg0, arg1);
    v0 = getPatchNormal(sp24);
    result->normal.x = v0->x;
    result->normal.y = v0->z;
    result->normal.z = v0->y;
    result->type = getPatchSurfaceType(sp24);
    return TRUE;
}

s32 func_800E435C_61B0C(f32 arg0, f32 arg1, GroundResult* arg2) {
    WorldBlock* block;

    if (D_800E6B34_642E4 == NULL) {
        return FALSE;
    }

    block = getCurrentWorldBlock();
    if (block == NULL || block->descriptor == NULL || D_800E6B34_642E4 == NULL) {
        setDefaultGroundResult(arg2);
        return FALSE;
    }

    arg0 /= 100.0f;
    arg1 /= 100.0f;
    arg0 = arg0 + block->descriptor->unk_04.x;
    arg1 = arg1 + block->descriptor->unk_04.z;
    if (!func_800E42BC_61A6C(arg0, arg1, arg2)) {
        setDefaultGroundResult(arg2);
        return FALSE;
    }

    arg2->height -= block->descriptor->unk_04.y;
    arg2->height *= 100.0f;
    return TRUE;
}
