#include "world.h"

HeightMap* sHeightMap = NULL;
HeightMap* sCeilingMap = NULL;

s32 setHeightMap(HeightMap* map) {
    HeightMapPatch* patches;
    HeightMapTreeNode* tree;

    if (map == NULL) {
        return false;
    }
    if (map->tree == NULL || map->patches == NULL) {
        return false;
    }
    sHeightMap = map;
    tree = sHeightMap->tree;
    patches = sHeightMap->patches;
    createHeightMapTree(tree, patches);
    return true;
}

s32 setCeilingMap(HeightMap* map) {
    HeightMapPatch* patches;
    HeightMapTreeNode* tree;

    if (map == NULL) {
        return false;
    }
    if (map->tree == NULL || map->patches == NULL) {
        return false;
    }
    sCeilingMap = map;
    tree = sCeilingMap->tree;
    patches = sCeilingMap->patches;
    createHeightMapTree(tree, patches);
    return true;
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
        return false;
    }

    patch = findHeightMapPatch(sHeightMap->tree, x, z);
    result->height = getPatchHeightAt(patch, x, z);
    normal = getPatchNormal(patch);
    result->normal.x = normal->x;
    result->normal.y = normal->z; // z is UP
    result->normal.z = normal->y;
    result->surfaceType = getPatchSurfaceType(patch);
    return true;
}

s32 getGroundAt(f32 x, f32 z, GroundResult* result) {
    WorldBlock* block = getCurrentWorldBlock();

    if (block == NULL || block->descriptor == NULL || sHeightMap == NULL) {
        setDefaultGroundResult(result);
        return false;
    }

    x /= 100.0f;
    z /= 100.0f;
    x = x + block->descriptor->worldPos.x;
    z = z + block->descriptor->worldPos.z;
    if (!getGroundAtGlobal(x, z, result)) {
        setDefaultGroundResult(result);
        return false;
    }

    result->height -= block->descriptor->worldPos.y;
    result->height *= 100.0f;
    return true;
}

s32 getCeilingAtGlobal(f32 x, f32 z, GroundResult* result) {
    HeightMapPatch* patch;
    Vec3f* normal;

    if (sCeilingMap == NULL) {
        setDefaultGroundResult(result);
        return false;
    }

    patch = findHeightMapPatch(sCeilingMap->tree, x, z);
    result->height = getPatchHeightAt(patch, x, z);
    normal = getPatchNormal(patch);
    result->normal.x = normal->x;
    result->normal.y = normal->z;
    result->normal.z = normal->y;
    result->surfaceType = getPatchSurfaceType(patch);
    return true;
}

s32 getCeilingAt(f32 x, f32 z, GroundResult* arg2) {
    WorldBlock* block;

    if (sCeilingMap == NULL) {
        return false;
    }

    block = getCurrentWorldBlock();
    if (block == NULL || block->descriptor == NULL || sCeilingMap == NULL) {
        setDefaultGroundResult(arg2);
        return false;
    }

    x /= 100.0f;
    z /= 100.0f;
    x = x + block->descriptor->worldPos.x;
    z = z + block->descriptor->worldPos.z;
    if (!getCeilingAtGlobal(x, z, arg2)) {
        setDefaultGroundResult(arg2);
        return false;
    }

    arg2->height -= block->descriptor->worldPos.y;
    arg2->height *= 100.0f;
    return true;
}
