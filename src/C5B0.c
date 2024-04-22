#include "macros.h"
#include "sys/om.h"
#include "sys/crash.h"

// TODO header
s32 func_8000B880(void (*handler)(GObj*, s32));
void func_800191D8(GObj*);
DObj* func_8000C550(DObj*);

void func_8000B9B0(s32 link, void (*cb)(GObj*, void*), void* param) {
    GObj* curr;
    GObj* next;

    curr = omGObjListHead[link];
    while (curr != NULL) {
        next = curr->next;
        cb(curr, param);
        curr = next;
    }
}

void func_8000BA18(void (*cb)(GObj*, void*), void* param) {
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

GObj* func_8000BAA4(s32 link, GObj* (*cb)(GObj*, void*), void* param, s32 getFirst) {
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
            if (getFirst == TRUE) {
                return ret;
            }
        }
        curr = next;
    }

    return ret;
}

GObj* func_8000BB4C(GObj* (*cb)(GObj*, void*), void* param, s32 getFirst) {
    GObj* curr;
    GObj* next;
    s32 link;
    GObj* ret = 0;

    for (link = 0; link < 32; link++) {
        curr = omGObjListHead[link];
        while (curr != NULL) {
            GObj* retVal;

            next = curr->next;
            retVal = cb(curr, param);

            if (retVal != NULL) {
                ret = retVal;
                if (getFirst == TRUE) {
                    return ret;
                }
            }
            curr = next;
        }
    }

    return ret;
}

GObj* func_8000BC0C(GObj* obj, void* id) {
    return obj->id == (u32)id ? obj : NULL;
}

GObj* func_8000BC2C(s32 link, u32 id) {
    return func_8000BAA4(link, func_8000BC0C, (void*)id, TRUE);
}

GObj* func_8000BC58(u32 id) {
    return func_8000BB4C(func_8000BC0C, (void*)id, TRUE);
}

void func_8000BC84(UNUSED GObj* arg0) {
    func_8000B880(NULL);
}

void func_8000BCA8(s32 numFrames) {
    // todo: main.h STACK_PROBE_MAGIC
    if (omCurrentProcess->unk1C.thread->osStack[7] != 0xFEDCBA98) {
        fatal_printf("gobjthread stack over  gobjid = %d\n", omCurrentProcess->object->id);
    }

    while (numFrames) {
        osSendMesg(&omProcessWaitQueue, (OSMesg)1, OS_MESG_NOBLOCK);
        osStopThread(NULL);
        numFrames--;
    }
}

void func_8000BD44(GObj* obj) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        proc->paused = 1;
        proc = proc->next;
    }
}

void func_8000BD78(GObj* obj) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        proc->paused = 0;
        proc = proc->next;
    }
}

void func_8000BDAC(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    proc->paused = TRUE;
}

void func_8000BDC4(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    proc->paused = 0;
}

void func_8000BDDC(GObj* obj, void (*function)(GObj*)) {
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

void func_8000BE1C(GObj* obj, void (*function)(GObj*)) {
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

void omh_end_all_object_processes(GObj* obj) {
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

void func_8000BEAC(DObj* dobj) {
    omDObjAppendMtx(dobj, MTX_TYPE_TRANSLATE, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_ROTATE_RPY_DEG, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_SCALE, 0);
}

void func_8000BEF4(DObj* dobj) {
    omDObjAppendMtx(dobj, MTX_TYPE_TRANSLATE, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_ROTATE_RPY, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_SCALE, 0);
}

void func_8000BF3C(OMCamera* camera) {
    omCameraAddMtx(camera, MTX_TYPE_PERSP_FAST, 0);
    omCameraAddMtx(camera, MTX_TYPE_LOOKAT, 0);
}

void func_8000BF74(GObj* obj) {
    DObj* curr;

    curr = obj->data.dobj;
    while (curr != NULL) {
        omDObjRemoveAllMObj(curr);
        curr = func_8000C550(curr);
    }
}

DObj* func_8000BFB8(GObj* obj, void* arg1) {
    DObj* ret = omGObjAddDObj(obj, arg1);
    func_8000BEAC(ret);
    return ret;
}

DObj* func_8000BFE8(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddSibling(dobj, arg1);
    func_8000BEAC(ret);
    return ret;
}

DObj* func_8000C018(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddChild(dobj, arg1);
    func_8000BEAC(ret);
    return ret;
}

DObj* func_8000C048(GObj* obj, void* arg1) {
    DObj* ret = omGObjAddDObj(obj, arg1);
    func_8000BEF4(ret);
    return ret;
}

DObj* func_8000C078(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddSibling(dobj, arg1);
    func_8000BEF4(ret);
    return ret;
}

DObj* func_8000C0A8(DObj* dobj, void* arg1) {
    DObj* ret = omDObjAddChild(dobj, arg1);
    func_8000BEF4(ret);
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/C5B0/func_8000C0D8.s")

void func_8000C1CC(GObj* obj) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    while (obj->data.dobj != NULL) {
        omDObjRemove(obj->data.dobj);
    }
}

void func_8000C220(GObj* obj) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    while (obj->data.sobj != NULL) {
        omGObjRemoveSprite(obj->data.sobj);
    }
}

void func_8000C274(void) {
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

GObj* func_8000C2E4(s32 objId, void (*objFnUpdate)(GObj*), s32 objLink, s32 objPriority,
                  void (*fnRender)(GObj*), u8 dlLink, s32 dlPriority, s32 dlArg, void* dobjBP, s32 arg9,
                  u8 procKind, void (*procFunc)(GObj*), s32 procPriority) {
    GObj* obj;
    DObj* dobj;

    obj = omAddGObj(objId, objFnUpdate, objLink, objPriority);
    if (obj == NULL) {
        return NULL;
    }

    omLinkGObjDL(obj, fnRender, dlLink, dlPriority, dlArg);

    dobj = omGObjAddDObj(obj, dobjBP);
    if (arg9) {
        func_8000BEAC(dobj);
    }
    if (procFunc != NULL) {
        omCreateProcess(obj, procFunc, procKind, procPriority);
    }
    return obj;
}

GObj* create_sprite(s32 objId, void (*objFnUpdate)(GObj*), s32 objLink, s32 objPriority,
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

GObj* create_camera(s32 objId, void (*objFnUpdate)(GObj*), s32 objLink, s32 objPriority,
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
        func_8000BF3C(cam);
    }
    if (procFunc != NULL) {
        omCreateProcess(obj, procFunc, procKind, procPriority);
    }
    if (defaultFlags) {
        cam->flags = 7;
        cam->unk84 = 0xFF;
    }
    return obj;
}

GObj* func_8000C4B0(s32 link, s32 priority, s32 dlPriority, s32 flags, s32 bgColor) {
    GObj* obj;
    OMCamera* cam;

    obj = create_camera(-1, func_8000BC84, link, priority, func_800191D8, dlPriority, 0, 0, FALSE, 0, NULL, 0, FALSE);
    if (obj == NULL) {
        return NULL;
    }
    cam = obj->data.cam;
    cam->flags = flags;
    cam->unk84 = bgColor;
    return obj;
}
