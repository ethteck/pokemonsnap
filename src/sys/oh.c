#include "macros.h"
#include "sys/om.h"
#include "sys/cmd.h"
#include "sys/crash.h"
#include "sys/anim.h"
#include "sys/render.h"

// Object Helpers

void ohApplyByLink(s32 link, void (*func)(GObj*, void*), void* param) {
    GObj* curr;
    GObj* next;

    curr = omGObjListHead[link];
    while (curr != NULL) {
        next = curr->next;
        func(curr, param);
        curr = next;
    }
}

void ohApplyToAll(void (*cb)(GObj*, void*), void* param) {
    GObj* curr;
    GObj* next;
    s32 link;

    for (link = 0; link < 32; link++) {
        curr = omGObjListHead[link];
        while (curr != NULL) {
            next = curr->next;
            cb(curr, param);
            curr = next;
        }
    }
}

GObj* ohApplyByLinkEx(s32 link, GObj* (*cb)(GObj*, void*), void* param, s32 onlyOne) {
    GObj* curr;
    GObj* next;
    GObj* ret = NULL;

    curr = omGObjListHead[link];
    while (curr != NULL) {
        GObj* retVal;

        next = curr->next;
        retVal = cb(curr, param);

        if (retVal != NULL) {
            ret = retVal;
            if (onlyOne == TRUE) {
                return ret;
            }
        }
        curr = next;
    }

    return ret;
}

GObj* ohApplyToAllEx(GObj* (*cb)(GObj*, void*), void* param, s32 onlyOne) {
    GObj* curr;
    GObj* next;
    s32 link;
    GObj* ret = NULL;

    for (link = 0; link < 32; link++) {
        curr = omGObjListHead[link];
        while (curr != NULL) {
            GObj* retVal;

            next = curr->next;
            retVal = cb(curr, param);

            if (retVal != NULL) {
                ret = retVal;
                if (onlyOne == TRUE) {
                    return ret;
                }
            }
            curr = next;
        }
    }

    return ret;
}

GObj* ohCheckId(GObj* obj, void* id) {
    return obj->id == (u32)id ? obj : NULL;
}

GObj* ohFindByLinkAndId(s32 link, u32 id) {
    return ohApplyByLinkEx(link, ohCheckId, (void*)id, TRUE);
}

GObj* ohFindById(u32 id) {
    return ohApplyToAllEx(ohCheckId, (void*)id, TRUE);
}

void ohUpdateDefault(UNUSED GObj* arg0) {
    cmdProcessCommands(NULL);
}

void ohWait(s32 numFrames) {
    if (omCurrentProcess->unk_1C.thread->osStack[7] != 0xFEDCBA98) {
        fatal_printf("gobjthread stack over  gobjid = %d\n", omCurrentProcess->object->id);
    }

    while (numFrames) {
        osSendMesg(&omProcessWaitQueue, (OSMesg)1, OS_MESG_NOBLOCK);
        osStopThread(NULL);
        numFrames--;
    }
}

void ohPauseObjectProcesses(GObj* obj) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        proc->paused = TRUE;
        proc = proc->next;
    }
}

void ohResumeObjectProcesses(GObj* obj) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        proc->paused = FALSE;
        proc = proc->next;
    }
}

void ohPauseProcess(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    proc->paused = TRUE;
}

void ohResumeProcess(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    proc->paused = 0;
}

void ohPauseProcessByFunction(GObj* obj, GObjFunc function) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        if (proc->function == function) {
            proc->paused = TRUE;
        }
        proc = proc->next;
    }
}

void ohResumeProcessByFunction(GObj* obj, GObjFunc function) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        if (proc->function == function) {
            proc->paused = FALSE;
        }
        proc = proc->next;
    }
}

void ohEndAllObjectProcesses(GObj* obj) {
    GObjProcess *curr, *next;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    curr = obj->processListHead;
    while (curr != NULL) {
        next = curr->next;
        omEndProcess(curr);
        curr = next;
    }
}

void ohCreateDefaultMatricesDeg(DObj* dobj) {
    omDObjAppendMtx(dobj, MTX_TYPE_TRANSLATE, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_ROTATE_RPY_DEG, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_SCALE, 0);
}

void ohCreateDefaultMatricesRad(DObj* dobj) {
    omDObjAppendMtx(dobj, MTX_TYPE_TRANSLATE, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_ROTATE_RPY, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_SCALE, 0);
}

void ohCreateDefaultCameraMatrices(OMCamera* camera) {
    omCameraAddMtx(camera, MTX_TYPE_PERSP_FAST, 0);
    omCameraAddMtx(camera, MTX_TYPE_LOOKAT, 0);
}

void ohDobjTreeRemoveAllMObjs(GObj* obj) {
    DObj* curr;

    curr = obj->data.dobj;
    while (curr != NULL) {
        omDObjRemoveAllMObj(curr);
        curr = animModelTreeNextNode(curr);
    }
}

DObj* ohAddDObj(GObj* obj, void* arg1) {
    DObj* ret = omGObjAddDObj(obj, arg1);
    ohCreateDefaultMatricesDeg(ret);
    return ret;
}

DObj* ohAddDObjSibling(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddSibling(dobj, arg1);
    ohCreateDefaultMatricesDeg(ret);
    return ret;
}

DObj* ohAddDObjChild(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddChild(dobj, arg1);
    ohCreateDefaultMatricesDeg(ret);
    return ret;
}

DObj* ohAddDObjRad(GObj* obj, void* arg1) {
    DObj* ret = omGObjAddDObj(obj, arg1);
    ohCreateDefaultMatricesRad(ret);
    return ret;
}

DObj* ohAddDObjSiblingRad(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddSibling(dobj, arg1);
    ohCreateDefaultMatricesRad(ret);
    return ret;
}

DObj* ohAddDObjChildRad(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddChild(dobj, arg1);
    ohCreateDefaultMatricesRad(ret);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/sys/oh/func_8000C0D8.s")

void ohRemoveDObj(GObj* obj) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    while (obj->data.dobj != NULL) {
        omDObjRemove(obj->data.dobj);
    }
}

void ohRemoveSprite(GObj* obj) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    while (obj->data.sobj != NULL) {
        omGObjRemoveSprite(obj->data.sobj);
    }
}

void ohDeleteAllObjects(void) {
    GObj* curr;
    GObj* next;
    s32 i;

    for (i = 0; i < 32; i++) {
        curr = omGObjListHead[i];
        while (curr != NULL) {
            next = curr->next;
            omDeleteGObj(curr);
            curr = next;
        }
    }
}

GObj* ohCreateModel(s32 objId, void (*objFnUpdate)(GObj*), s32 objLink, s32 objPriority,
                  void (*fnRender)(GObj*), u8 dlLink, s32 dlPriority, s32 cameraTag, void* dobjBP, s32 setMatrices,
                  u8 procKind, void (*procFunc)(GObj*), s32 procPriority) {
    GObj* obj;
    DObj* dobj;

    obj = omAddGObj(objId, objFnUpdate, objLink, objPriority);
    if (obj == NULL) {
        return NULL;
    }

    omLinkGObjDL(obj, fnRender, dlLink, dlPriority, cameraTag);

    dobj = omGObjAddDObj(obj, dobjBP);
    if (setMatrices) {
        ohCreateDefaultMatricesDeg(dobj);
    }
    if (procFunc != NULL) {
        omCreateProcess(obj, procFunc, procKind, procPriority);
    }
    return obj;
}

GObj* ohCreateSprite(s32 objId, void (*objFnUpdate)(GObj*), s32 objLink, s32 objPriority,
                          void (*fnRender)(GObj*), u8 dlLink, s32 dlPriority, s32 cameraTag, Sprite* sprite,
                          u8 procKind, void (*procFunc)(GObj*), s32 procPriority) {
    GObj* obj;

    obj = omAddGObj(objId, objFnUpdate, objLink, objPriority);
    if (obj == NULL) {
        return NULL;
    }

    omLinkGObjDL(obj, fnRender, dlLink, dlPriority, cameraTag);
    omGObjAddSprite(obj, sprite);
    if (procFunc != NULL) {
        omCreateProcess(obj, procFunc, procKind, procPriority);
    }
    return obj;
}

GObj* ohCreateCamera(s32 objId, void (*objFnUpdate)(GObj*), s32 objLink, s32 objPriority,
                  void (*fnRender)(GObj*), s32 dlPriority, s32 dlLinkBitMask, s32 cameraTag, s32 defaultMatrices,
                  u8 procKind, void (*procFunc)(GObj*), s32 procPriority, s32 defaultFlags) {
    GObj* obj;
    OMCamera* cam;

    obj = omAddGObj(objId, objFnUpdate, objLink, objPriority);
    if (obj == NULL) {
        return NULL;
    }
    omLinkGObjDLCamera(obj, fnRender, dlPriority, dlLinkBitMask, cameraTag);
    cam = omGObjSetCamera(obj);
    if (defaultMatrices) {
        ohCreateDefaultCameraMatrices(cam);
    }
    if (procFunc != NULL) {
        omCreateProcess(obj, procFunc, procKind, procPriority);
    }
    if (defaultFlags) {
        cam->flags = 7;
        cam->bgColor = 0xFF;
    }
    return obj;
}

GObj* ohCreateCameraWrapper(s32 link, s32 priority, s32 dlPriority, s32 flags, s32 bgColor) {
    GObj* obj;
    OMCamera* cam;

    obj = ohCreateCamera(-1, ohUpdateDefault, link, priority, ren_func_800191D8, dlPriority, 0, 0, FALSE, 0, NULL, 0, FALSE);
    if (obj == NULL) {
        return NULL;
    }
    cam = obj->data.cam;
    cam->flags = flags;
    cam->bgColor = bgColor;
    return obj;
}
