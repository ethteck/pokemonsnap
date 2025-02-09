#include "world.h"

UnkVioletMarlin* D_800E6B10_642C0 = NULL;
s32 D_800E6B14_642C4 = 0;

void func_800E30B0_60860(WorldBlock* block, StaticObject* arg1, PayloadStruct arg2) {
    if (block->blockModel->fnRender == &renRenderModelTypeA ||
        block->blockModel->fnRender == &renderModelTypeAFogged ||
        block->blockModel->fnRender == &renRenderModelTypeB ||
        block->blockModel->fnRender == &renderModelTypeBFogged)
    {
        DObj* child = omDObjAddChild(block->blockModel->data.dobj, arg2.d.gfx);
        s32 unused[2];

        if (arg1->scale.x == 1.0f && arg1->scale.y == 1.0f && arg1->scale.z == 1.0f) {
            omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE, 1);
            child->scale.v.x = 1.0f;
            child->scale.v.y = 1.0f;
            child->scale.v.z = 1.0f;
        } else {
            omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 1);
            child->scale.v.x = arg1->scale.x;
            child->scale.v.y = arg1->scale.y;
            child->scale.v.z = arg1->scale.z;
        }

        child->position.v.x = arg1->position.x * 100.0f;
        child->position.v.y = arg1->position.y * 100.0f;
        child->position.v.z = arg1->position.z * 100.0f;

        child->rotation.v.x = arg1->rotation.x;
        child->rotation.v.y = arg1->rotation.y;
        child->rotation.v.z = arg1->rotation.z;

        if (block->blockModel->fnRender == &renRenderModelTypeA) {
            block->blockModel->fnRender = &renRenderModelTypeB;
        } else if (block->blockModel->fnRender == &renderModelTypeAFogged) {
            block->blockModel->fnRender = &renderModelTypeBFogged;
        }
    }
}

void func_800E3258_60A08(WorldBlock* block, StaticObject* arg1, PayloadStruct arg2) {
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

            if (arg1->scale.x == 1.0f && arg1->scale.y == 1.0f && arg1->scale.z == 1.0f) {
                omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE, 1);
                child->scale.v.z = 1.0f;
                child->scale.v.y = 1.0f;
                child->scale.v.x = 1.0f;
            } else {
                child->scale.v.x = arg1->scale.x;
                child->scale.v.y = arg1->scale.y;
                child->scale.v.z = arg1->scale.z;
                omDObjAppendMtx(child, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 1);
            }

            child->position.v.x = arg1->position.x * 100.0f;
            child->position.v.y = arg1->position.y * 100.0f;
            child->position.v.z = arg1->position.z * 100.0f;

            child->rotation.v.x = arg1->rotation.x;
            child->rotation.v.y = arg1->rotation.y;
            child->rotation.v.z = arg1->rotation.z;

            treePtr++;
        }

        if (block->blockModel->fnRender == &renRenderModelTypeA) {
            block->blockModel->fnRender = &renRenderModelTypeB;
        }
    }
}

void func_800E3464_60C14(WorldBlock* arg0) {
    StaticObject* s2;
    s32 i;

    if (arg0 == NULL || arg0->descriptor == NULL || arg0->descriptor->unk_18 == NULL || arg0->index >= MAX_BLOCKS) {
        return;
    }

    s2 = arg0->descriptor->unk_18;
    while (s2->id != -1) {
        for (i = 0; i < 100; i++) {
            if (D_800E6B10_642C0[i].id == -1) {
                break;
            }
            if (D_800E6B10_642C0[i].id == s2->id && D_800E6B10_642C0[i].unk_04 != NULL && D_800E6B10_642C0[i].unk_08.d.gfx != NULL) {
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
