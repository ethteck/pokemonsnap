#include "world.h"

#ifdef NON_MATCHING
void func_800E4460_61C10(HeightMapTreeNode* nodeArray, HeightMapTreeNode* tree, HeightMapPatch* patchArray) {
    while (true) {
        if (tree->leftPatch != (void*) -1 && ((uintptr_t) tree->leftPatch & 0xFF000000) == 0) {
            if (!patchArray) {
            } // for regalloc
            tree->leftPatch = &patchArray[(uintptr_t) tree->leftPatch];
        }
        if (tree->rightPatch != (void*) -1 && ((uintptr_t) tree->rightPatch & 0xFF000000) == 0) {
            if (!patchArray) {
            } // for regalloc
            tree->rightPatch = &patchArray[(uintptr_t) tree->rightPatch];
        }
        if (tree->leftChild != (void*) -1 && ((uintptr_t) tree->leftChild & 0xFF000000) == 0) {
            if (!nodeArray) {
            } // for regalloc
            tree->leftChild = &nodeArray[(uintptr_t) tree->leftChild];
        }
        if (tree->rightChild != (void*) -1 && ((uintptr_t) tree->rightChild & 0xFF000000) == 0) {
            if (!nodeArray) {
            } // for regalloc
            tree->rightChild = &nodeArray[(uintptr_t) tree->rightChild];
        }

        if (tree->leftChild != (void*) -1) {
            func_800E4460_61C10(nodeArray, tree->leftChild, patchArray);
        }
        if (tree->rightChild != (void*) -1) {
            tree = tree->rightChild;
        } else {
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/world/ground_int/func_800E4460_61C10.s")
void func_800E4460_61C10(HeightMapTreeNode* arg0, HeightMapTreeNode* arg1, HeightMapPatch* arg2);
#endif

#ifdef NON_MATCHING
void func_800E4584_61D34(HeightMapTreeNode* nodeArray, HeightMapTreeNode* tree, HeightMapPatch* patchArray) {
    while (true) {
        if (tree->leftPatch == (void*) -1) {
            tree->leftPatch = NULL;
        }
        if (tree->rightPatch == (void*) -1) {
            tree->rightPatch = NULL;
        }
        if (tree->leftChild == (void*) -1) {
            tree->leftChild = NULL;
        }
        if (tree->rightChild == (void*) -1) {
            tree->rightChild = NULL;
        }

        if (tree->leftChild != NULL) {
            func_800E4584_61D34(nodeArray, tree->leftChild, patchArray);
        }
        if (tree->rightChild != NULL) {
            tree = tree->rightChild;
        } else {
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/world/ground_int/func_800E4584_61D34.s")
void func_800E4584_61D34(HeightMapTreeNode* nodeArray, HeightMapTreeNode* tree, HeightMapPatch* patchArray);
#endif

void createHeightMapTree(HeightMapTreeNode* tree, HeightMapPatch* patches) {
    func_800E4460_61C10(tree, tree, patches);
    func_800E4584_61D34(tree, tree, patches);
}

HeightMapPatch* findHeightMapPatch(HeightMapTreeNode* node, f32 x, f32 z) {
    while (true) {
        if (node->lineA * x + node->lineB * z + node->lineC <= 0.0f) {
            if (node->rightPatch != NULL) {
                return node->rightPatch;
            }
            if (node->rightChild != NULL) {
                node = node->rightChild;
            } else {
                break;
            }
        } else {
            if (node->leftPatch != NULL) {
                return node->leftPatch;
            }
            if (node->leftChild != NULL) {
                node = node->leftChild;
            } else {
                break;
            }
        }
    }

    return NULL;
}

HeightMapPatch* func_800E470C_61EBC(HeightMapTreeNode* arg0, f32* arg1) {
    return findHeightMapPatch(arg0, arg1[0], arg1[1]);
}

f32 getPatchHeightAt(HeightMapPatch* patch, f32 x, f32 z) {
    if (patch == NULL) {
        return 0.0f;
    }
    if (patch->planeC == 0.0f) {
        return 0.0f;
    }
    // find point on the surface
    // solve equation A * x + B * y + C * z + D = 0
    return -(patch->planeA * x + patch->planeB * z + patch->planeD) / patch->planeC;
}

f32 func_800E479C_61F4C(HeightMapPatch* arg0, f32* arg1) {
    return getPatchHeightAt(arg0, arg1[0], arg1[1]);
}

Vec3f* getPatchNormal(HeightMapPatch* patch) {
    static f32 padding1;
    static Vec3f surfaceNormal;
    if (patch == NULL) {
        return NULL;
    }

    surfaceNormal.x = patch->planeA;
    surfaceNormal.y = patch->planeB;
    surfaceNormal.z = patch->planeC;
    Vec3fNormalize(&surfaceNormal);
    return &surfaceNormal;
}

s32 getPatchSurfaceType(HeightMapPatch* patch) {
    if (patch == NULL) {
        return 0;
    }
    return (patch->surfaceType >> 8) & 0xFFFFFF;
}

static char padding[0x38];
