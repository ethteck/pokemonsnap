#include "world.h"

HeightMap* sHeightMap = NULL;
HeightMap* sCeilingMap = NULL;

s32 setHeightMap(HeightMap* map) {
    HeightMapPatch* patches;
    HeightMapTreeNode* tree;

    if (map == NULL) {
        return FALSE;
    }
    if (map->tree == NULL || map->patches == NULL) {
        return FALSE;
    }
    sHeightMap = map;
    tree = sHeightMap->tree;
    patches = sHeightMap->patches;
    createHeightMapTree(tree, patches);
    return TRUE;
}

s32 setCeilingMap(HeightMap* map) {
    HeightMapPatch* patches;
    HeightMapTreeNode* tree;

    if (map == NULL) {
        return FALSE;
    }
    if (map->tree == NULL || map->patches == NULL) {
        return FALSE;
    }
    sCeilingMap = map;
    tree = sCeilingMap->tree;
    patches = sCeilingMap->patches;
    createHeightMapTree(tree, patches);
    return TRUE;
}

void setDefaultGroundResult(GroundResult* result) {
    result->height = -9000.0f;
    result->normal.x = 0.0f;
    result->normal.y = 1.0f;
    result->normal.z = 0.0f;
    result->surfaceType = -1;
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
    result->surfaceType = getPatchSurfaceType(patch);
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
    x = x + block->descriptor->worldPos.x;
    z = z + block->descriptor->worldPos.z;
    if (!getGroundAtGlobal(x, z, result)) {
        setDefaultGroundResult(result);
        return FALSE;
    }

    result->height -= block->descriptor->worldPos.y;
    result->height *= 100.0f;
    return TRUE;
}

s32 getCeilingAtGlobal(f32 x, f32 z, GroundResult* result) {
    HeightMapPatch* patch;
    Vec3f* normal;

    if (sCeilingMap == NULL) {
        setDefaultGroundResult(result);
        return FALSE;
    }

    patch = findHeightMapPatch(sCeilingMap->tree, x, z);
    result->height = getPatchHeightAt(patch, x, z);
    normal = getPatchNormal(patch);
    result->normal.x = normal->x;
    result->normal.y = normal->z;
    result->normal.z = normal->y;
    result->surfaceType = getPatchSurfaceType(patch);
    return TRUE;
}

s32 getCeilingAt(f32 x, f32 z, GroundResult* arg2) {
    WorldBlock* block;

    if (sCeilingMap == NULL) {
        return FALSE;
    }

    block = getCurrentWorldBlock();
    if (block == NULL || block->descriptor == NULL || sCeilingMap == NULL) {
        setDefaultGroundResult(arg2);
        return FALSE;
    }

    x /= 100.0f;
    z /= 100.0f;
    x = x + block->descriptor->worldPos.x;
    z = z + block->descriptor->worldPos.z;
    if (!getCeilingAtGlobal(x, z, arg2)) {
        setDefaultGroundResult(arg2);
        return FALSE;
    }

    arg2->height -= block->descriptor->worldPos.y;
    arg2->height *= 100.0f;
    return TRUE;
}
