#include "sys/om.h"
#include "sys/gtl.h"
#include "sys/crash.h"
#include "macros.h"

// TODO: header
void func_80007CBC(Vp*);
void func_8000C220(GObjCommon*);
void func_8000C1CC(GObjCommon*);
void omh_end_all_object_processes(GObjCommon*);
void func_8000B740(GObj_Sub3CList*);
void func_80015448(void);
void func_80018CD0(s32);
void func_8000B998(void);
void func_8000BCA8(s32);

#define ANIMATION_DISABLED (FLOAT_NEG_MAX)


typedef struct ThreadStackList {
    /* 0x00 */ struct ThreadStackList* next;
    /* 0x04 */ ThreadStackNode* stack;
    /* 0x08 */ u32 size;
} ThreadStackList; // size == 0x0C

GObjThread* omFreeThreadList;
s32 omActiveThreads;
s32 omActiveStacks;
u32 omDefaultStackSize;
s32 omD_8004A9A0;
ThreadStackList* omFreeStackList;
void (*omEndProcessHandler)(GObjProcess*);
GObjProcess* omFreeProcessList;
GObjProcess* omGProcessList[12]; // indexed by priority
s32 omActiveProcesses;
GObjCommon* omGObjListHead[32];  // indexed by link
GObjCommon* omGObjListTail[32];
GObjCommon* omFreeGObjList;
GObjCommon* omGObjListDlHead[33]; // indexed by dlLink
GObjCommon* omGObjListDlTail[33];
s32 omActiveObjects;
u16 omGObjSize;
s16 omMaxObjects;
OMMtx* omFreeMtxList;
s32 omActiveMatrices;
void (*omD_8004AC0C)(void*);
AObj* omFreeAObjList;
s32 omActiveAObj;
MObj* omFreeMObjList;
s32 omActiveMobj;
DObj* omFreeDObjList;
s32 omActiveDObj;
u16 omDObjSize;
SObj* omFreeSObjList;
s32 omActiveSObj;
u16 omSObjSize;
OMCamera* omFreeCameraList;
s32 omActiveCameras;
u16 omCameraSize;
GObjCommon* omCurrentObject;
GObjCommon* omCurrentCamera;
GObjCommon* omRenderedObject;
GObjProcess* omCurrentProcess;
s32 omD_8004AC54;
OSMesg omProcessWaitMsgs[1];
OSMesgQueue omProcessWaitQueue;
struct Unk80046A88 omD_8004AC78[32];

// data
s32 omThreadCounter = 10000000;
struct MtxCameraPersp omD_80040E84 = { NULL, 0, 30.0, 4.0 / 3.0, 100.0, 12800.0, 1.0 };
struct MtxCameraOrtho omD_80040EA0 = { NULL, -160.0, 160.0, -120.0, 120.0, 100.0, 12800.0, 1.0 };
struct MtxCameraLookAt omD_80040EC0 = { NULL, 1500.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };
struct Mtx3Float omD_80040EE8 = { NULL, { 0.0, 0.0, 0.0 } };
struct Mtx4Float omD_80040EF8 = { NULL, { 0.0, 0.0, 0.0, 1.0 } };
struct Mtx4Float omD_80040F0C = { NULL, { 0.0, 0.0, 0.0, 0.0 } };
struct Mtx3Float omD_80040F20 = { NULL, { 1.0, 1.0, 1.0 } };

GObjThread* om_get_obj_thread(void) {
    GObjThread* ret;

    if (omFreeThreadList == NULL) {
        omFreeThreadList = gtlMalloc(sizeof(GObjThread), 8);
    }

    if (omFreeThreadList == NULL) {
        fatal_printf("om : couldn't get GObjThread\n");
        while (TRUE) {}
    }

    ret = omFreeThreadList;
    omFreeThreadList = omFreeThreadList->next;
    omActiveThreads++;

    return ret;
}

void om_free_obj_thread(GObjThread* t) {
    t->next = omFreeThreadList;
    omFreeThreadList = t;
    omActiveThreads--;
}

ThreadStackNode* om_get_stack_of_size(u32 size) {
    ThreadStackList* curr;
    ThreadStackList* prev;
    ThreadStackNode* ret;

    curr = omFreeStackList;
    prev = NULL;
    while (curr != NULL) {
        if (curr->size == size) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // stack of size 'size' not found
    if (curr == NULL) {
        curr = gtlMalloc(sizeof(ThreadStackList), 4);
        curr->next = NULL;
        curr->stack = NULL;
        curr->size = size;

        // add it to the end of the list
        if (prev != NULL) {
            prev->next = curr;
        } else {
            omFreeStackList = curr;
        }
    }

    if (curr->stack != NULL) {
        ret = curr->stack;
        curr->stack = curr->stack->next;
    } else {
        ret = gtlMalloc(size + 8 /*offsetof(ThreadStackNode, stack)*/, 8);
        ret->stackSize = size;
    }

    ret->next = NULL;
    omActiveStacks++;
    return ret;
}

ThreadStackNode* om_get_default_stack(void) {
    return om_get_stack_of_size(omDefaultStackSize);
}

void om_free_stack(ThreadStackNode* node) {
    ThreadStackList* parent;

    parent = omFreeStackList;
    while (parent != NULL) {
        if (parent->size == node->stackSize) {
            break;
        }
        parent = parent->next;
    }

    if (parent == NULL) {
        fatal_printf("om : Illegal GObjThreadStack Link\n");
        while (TRUE) {}
    }

    node->next = parent->stack;
    parent->stack = node;
    omActiveStacks--;
}

GObjProcess* om_get_obj_process(void) {
    GObjProcess* ret;

    if (omFreeProcessList == NULL) {
        omFreeProcessList = gtlMalloc(sizeof(GObjProcess), 4);
    }

    if (omFreeProcessList == NULL) {
        fatal_printf("om : couldn't get GObjProcess\n");
        while (TRUE) {}
    }

    ret = omFreeProcessList;
    omFreeProcessList = omFreeProcessList->next;
    omActiveProcesses++;

    return ret;
}

void om_link_process(GObjProcess* proc) {
    GObjCommon* obj = proc->object;
    GObjCommon* curObj = proc->object;
    s32 curLink = curObj->link;
    curObj = curObj; // required to match

    // find place in priority list
    // here it is assumed that objects with lower link and priority have processes with lower priority
    while (TRUE) {
        while (curObj != NULL) {
            GObjProcess* curProc = curObj->processListTail;
            while (curProc != NULL) {
                if (curProc->priority == proc->priority) {
                    proc->nextInPriorityList = curProc->nextInPriorityList;
                    curProc->nextInPriorityList = proc;
                    proc->prevInPriorityList = curProc;
                    goto END;
                }
                curProc = curProc->prev;
            }
            curObj = curObj->prev;
        }
        if (curLink != 0) {
            curObj = omGObjListTail[--curLink];
        } else {
            // curLink == 0
            proc->nextInPriorityList = omGProcessList[proc->priority];
            omGProcessList[proc->priority] = proc;
            proc->prevInPriorityList = NULL;
            goto END;
        }
    }
END:
    if (proc->nextInPriorityList != NULL) {
        proc->nextInPriorityList->prevInPriorityList = proc;
    }

    // add to object process list
    if (obj->processListTail != NULL) {
        obj->processListTail->next = proc;
    } else {
        obj->processListHead = proc;
    }

    proc->prev = obj->processListTail;
    proc->next = NULL;
    obj->processListTail = proc;
}

void om_free_process(GObjProcess* proc) {
    proc->next = omFreeProcessList;
    omFreeProcessList = proc;
    omActiveProcesses--;
}

void om_unlink_process_from_priority_list(GObjProcess* proc) {
    if (proc->prevInPriorityList != NULL) {
        proc->prevInPriorityList->nextInPriorityList = proc->nextInPriorityList;
    } else {
        omGProcessList[proc->priority] = proc->nextInPriorityList;
    }

    if (proc->nextInPriorityList != NULL) {
        proc->nextInPriorityList->prevInPriorityList = proc->prevInPriorityList;
    }
}

void om_unlink_process(GObjProcess* proc) {
    GObjCommon* obj = proc->object;

    om_unlink_process_from_priority_list(proc);
    if (proc->prev != NULL) {
        proc->prev->next = proc->next;
    } else {
        obj->processListHead = proc->next;
    }

    if (proc->next != NULL) {
        proc->next->prev = proc->prev;
    } else {
        obj->processListTail = proc->prev;
    }
}

GObjProcess* om_get_default_process(void) {
    return omCurrentProcess;
}

u64* om_get_process_stack(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    if (proc != NULL && proc->kind == 0) {
        return proc->unk1C.thread->osStack;
    }

    return NULL;
}

s32 om_get_process_stack_size(GObjProcess* arg0) {
    if (arg0 == NULL) {
        arg0 = omCurrentProcess;
    }

    if (arg0 != NULL && arg0->kind == 0) {
        return arg0->unk1C.thread->stackSize;
    }

    return NULL;
}

void om_set_end_process_handler(void (*handler)(GObjProcess*)) {
    omEndProcessHandler = handler;
}

s32 om_get_total_gobj_number(void) {
    GObjCommon* curr = omFreeGObjList;
    s32 i = 0;

    while (curr != NULL) {
        i++;
        curr = curr->next;
    }

    return i + omActiveObjects;
}

GObjCommon* om_get_gobj(void) {
    GObjCommon* ret;

    if (omMaxObjects == -1 || omActiveObjects < omMaxObjects) {
        ret = omFreeGObjList;
        if (ret == NULL) {
            omFreeGObjList = gtlMalloc(omGObjSize, 8);
            ret = omFreeGObjList;
        }
    } else {
        fatal_printf("om : limit over get GObj\n");
        while (TRUE) {}
    }

    if (ret == NULL) {
        fatal_printf("om : couldn't get GObj\n");
        while (TRUE) {}
    }
    if (ret == NULL) {
        return NULL;
    }
    omFreeGObjList = ret->next;
    omActiveObjects++;

    return ret;
}

void om_free_gobj(GObjCommon* obj) {
    obj->next = omFreeGObjList;
    omFreeGObjList = obj;
    omActiveObjects--;
}

void om_link_gobj_after(GObjCommon* obj, GObjCommon* prevObj) {
    obj->prev = prevObj;
    if (prevObj != NULL) {
        obj->next = prevObj->next;
        prevObj->next = obj;
    } else {
        obj->next = omGObjListHead[obj->link];
        omGObjListHead[obj->link] = obj;
    }

    if (obj->next != NULL) {
        obj->next->prev = obj;
    } else {
        omGObjListTail[obj->link] = obj;
    }
}

void om_link_gobj_after_same_priority(GObjCommon* obj) {
    GObjCommon* curr;

    curr = omGObjListTail[obj->link];
    while (curr != NULL && curr->priority < obj->priority) {
        curr = curr->prev;
    }

    om_link_gobj_after(obj, curr);
}

void om_link_gobj_before_same_priority(GObjCommon* obj) {
    GObjCommon* curr;
    GObjCommon* beforeCurr;

    curr = omGObjListHead[obj->link];
    while (curr != NULL && obj->priority < curr->priority) {
        curr = curr->next;
    }

    if (curr != NULL) {
        beforeCurr = curr->prev;
    } else {
        beforeCurr = omGObjListTail[obj->link];
    }

    om_link_gobj_after(obj, beforeCurr);
}

void om_unlink_gobj(GObjCommon* obj) {
    if (obj->prev != NULL) {
        obj->prev->next = obj->next;
    } else {
        omGObjListHead[obj->link] = obj->next;
    }

    if (obj->next != NULL) {
        obj->next->prev = obj->prev;
    } else {
        omGObjListTail[obj->link] = obj->prev;
    }
}

void om_insert_gobj_dl(GObjCommon* obj, GObjCommon* prevObj) {
    obj->prevDl = prevObj;

    if (prevObj != NULL) {
        obj->nextDl = prevObj->nextDl;
        prevObj->nextDl = obj;
    } else {
        obj->nextDl = omGObjListDlHead[obj->dlLink];
        omGObjListDlHead[obj->dlLink] = obj;
    }

    if (obj->nextDl != NULL) {
        obj->nextDl->prevDl = obj;
    } else {
        omGObjListDlTail[obj->dlLink] = obj;
    }
}

void om_insert_gobj_dl_after_same_priority(GObjCommon* obj) {
    GObjCommon* csr;

    csr = omGObjListDlTail[obj->dlLink];
    while (csr != NULL && csr->dlPriority < obj->dlPriority) {
        csr = csr->prevDl;
    }
    om_insert_gobj_dl(obj, csr);
}

void om_insert_gobj_dl_before_same_priority(GObjCommon* obj) {
    GObjCommon* curr;
    GObjCommon* found;

    curr = omGObjListDlHead[obj->dlLink];
    while (curr != NULL && obj->dlPriority < curr->dlPriority) {
        curr = curr->nextDl;
    }

    if (curr != NULL) {
        found = curr->prevDl;
    } else {
        found = omGObjListDlTail[obj->dlLink];
    }

    om_insert_gobj_dl(obj, found);
}

void om_unlink_gobj_dl(GObjCommon* obj) {
    if (obj->prevDl != NULL) {
        obj->prevDl->nextDl = obj->nextDl;
    } else {
        omGObjListDlHead[obj->dlLink] = obj->nextDl;
    }

    if (obj->nextDl != NULL) {
        obj->nextDl->prevDl = obj->prevDl;
    } else {
        omGObjListDlTail[obj->dlLink] = obj->prevDl;
    }
}

OMMtx* om_get_mtx(void) {
    OMMtx* ret;

    if (omFreeMtxList == NULL) {
        omFreeMtxList = gtlMalloc(sizeof(OMMtx), 8);
    }

    if (omFreeMtxList == NULL) {
        fatal_printf("om : couldn't get OMMtx\n");
        while (TRUE) {}
    }

    ret = omFreeMtxList;
    omFreeMtxList = omFreeMtxList->next;
    omActiveMatrices++;
    return ret;
}

void om_free_mtx(OMMtx* mtx) {
    mtx->next = omFreeMtxList;
    omFreeMtxList = mtx;
    omActiveMatrices--;
}

AObj* om_get_aobj(void) {
    AObj* ret;

    if (omFreeAObjList == NULL) {
        omFreeAObjList = gtlMalloc(sizeof(AObj), 4);
    }

    if (omFreeAObjList == NULL) {
        fatal_printf("om : couldn't get AObj\n");
        while (TRUE) {}
    }

    ret = omFreeAObjList;
    omFreeAObjList = omFreeAObjList->next;
    omActiveAObj++;
    return ret;
}

void om_dobj_attach_aobj(DObj* dobj, AObj* aobj) {
    aobj->next = dobj->aobjList;
    dobj->aobjList = aobj;
}

void om_mobj_attach_aobj(MObj* mobj, AObj* aobj) {
    aobj->next = mobj->aobjList;
    mobj->aobjList = aobj;
}

void om_camera_attach_aobj(OMCamera* cam, AObj* aobj) {
    aobj->next = cam->aobjList;
    cam->aobjList = aobj;
}

void om_free_aobj(AObj* aobj) {
    aobj->next = omFreeAObjList;
    omFreeAObjList = aobj;
    omActiveAObj--;
}

MObj* om_get_mobj(void) {
    MObj* ret;

    if (omFreeMObjList == NULL) {
        omFreeMObjList = gtlMalloc(sizeof(MObj), 4);
    }

    if (omFreeMObjList == NULL) {
        fatal_printf("om : couldn't get MObj\n");
        while (TRUE) {}
    }

    ret = omFreeMObjList;
    omFreeMObjList = omFreeMObjList->next;
    omActiveMobj++;

    return ret;
}

void om_free_mobj(MObj* obj) {
    obj->next = omFreeMObjList;
    omFreeMObjList = obj;
    omActiveMobj--;
}

DObj* om_get_dobj(void) {
    DObj* ret;

    if (omFreeDObjList == NULL) {
        omFreeDObjList = gtlMalloc(omDObjSize, 8);
    }

    if (omFreeDObjList == NULL) {
        fatal_printf("om : couldn't get DObj\n");
        while (TRUE) {}
    }

    ret = omFreeDObjList;
    omFreeDObjList = omFreeDObjList->nextFree;
    omActiveDObj++;

    return ret;
}

void om_free_dobj(DObj* obj) {
    obj->nextFree = omFreeDObjList;
    omFreeDObjList = obj;
    omActiveDObj--;
}

SObj* om_get_sobj(void) {
    SObj* ret;

    if (omFreeSObjList == NULL) {
        omFreeSObjList = gtlMalloc(omSObjSize, 8);
    }

    if (omFreeSObjList == NULL) {
        fatal_printf("om : couldn't get SObj\n");
        while (TRUE) {}
    }

    ret = omFreeSObjList;
    omFreeSObjList = omFreeSObjList->nextFree;
    omActiveSObj++;

    return ret;
}

void om_free_sobj(SObj* obj) {
    obj->nextFree = omFreeSObjList;
    omFreeSObjList = obj;
    omActiveSObj--;
}

OMCamera* om_get_camera(void) {
    OMCamera* ret;

    if (omFreeCameraList == NULL) {
        omFreeCameraList = gtlMalloc(omCameraSize, 8);
    }

    if (omFreeCameraList == NULL) {
        fatal_printf("om : couldn't get Camera\n");
        while (TRUE) {}
    }

    ret = omFreeCameraList;
    omFreeCameraList = omFreeCameraList->nextFree;
    omActiveCameras++;

    return ret;
}

void om_free_camera(OMCamera* obj) {
    obj->nextFree = omFreeCameraList;
    omFreeCameraList = obj;
    omActiveCameras--;
}

GObjProcess* om_create_process(GObjCommon* com, void (*func)(struct GObjCommon*), u8 kind, u32 pri) {
    ThreadStackNode* stackNode;
    GObjThread* thread;
    GObjProcess* process;

    if (com == NULL) {
        com = omCurrentObject;
    }

    process = om_get_obj_process();
    if (pri > 11) {
        fatal_printf("om : GObjProcess's priority is bad value\n");
        while (TRUE) {}
    }
    process->priority = pri;
    process->kind = kind;
    process->paused = 0;
    process->object = com;
    process->function = func;

    switch (kind) {
        case 0:
            thread = om_get_obj_thread();
            process->unk1C.thread = thread;

            stackNode = om_get_default_stack();
            thread->osStack = stackNode->stack;
            thread->stackSize = omDefaultStackSize;
            osCreateThread(&thread->osThread, omThreadCounter++, (void (*)(void*))func, com, &thread->osStack[omDefaultStackSize / 8],
                           51);
            thread->osStack[7] = 0xFEDCBA98;

            if (omThreadCounter >= 20000000) {
                omThreadCounter = 10000000;
            }
            break;
        case 1:
            process->unk1C.cb = func;
            break;
        default:
            fatal_printf("om : GObjProcess's kind is bad value\n");
            while (TRUE) {}
    }

    om_link_process(process);
    return process;
}

GObjProcess* om_create_process_threaded(GObjCommon* obj, void (*entry)(GObjCommon*), u32 pri, s32 threadId, u32 stackSize) {
    GObjProcess* process;
    GObjThread* thread;
    ThreadStackNode* stackNode;
    OSId tid;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    process = om_get_obj_process();

    if (pri > 11) {
        fatal_printf("om : GObjProcess's priority is bad value\n");
        while (TRUE) {}
    }

    process->priority = pri;
    process->paused = 0;
    process->object = obj;
    process->function = entry;

    process->unk1C.thread = thread = om_get_obj_thread();
    process->kind = 0;

    stackNode = stackSize == 0 ? om_get_default_stack() : om_get_stack_of_size(stackSize);
    thread->osStack = stackNode->stack;
    thread->stackSize = stackSize == 0 ? omDefaultStackSize : stackSize;
    tid = threadId != -1 ? threadId : omThreadCounter++;

    osCreateThread(&thread->osThread, tid, (void (*)(void*))entry, obj, &thread->osStack[thread->stackSize / 8], 51);
    thread->osStack[7] = 0xFEDCBA98;
    if (omThreadCounter >= 20000000) {
        omThreadCounter = 10000000;
    }

    om_link_process(process);
    return process;
}

void om_end_process(GObjProcess* proc) {
    ThreadStackNode* tnode;

    if (proc == NULL || proc == omCurrentProcess) {
        omD_8004AC54 = 1;
        if (omCurrentProcess->kind == 0) {
            func_8000BCA8(1);
        }
        return;
    }

    if (omEndProcessHandler != NULL) {
        omEndProcessHandler(proc);
    }

    switch (proc->kind) {
        case 0:
            osDestroyThread(&proc->unk1C.thread->osThread);
            // cast from stack pointer back to stack node
            tnode = (void*)((uintptr_t)(proc->unk1C.thread->osStack) - 8); /*offsetof(struct ThreadStackNode, stack));*/
            om_free_stack(tnode);
            om_free_obj_thread(proc->unk1C.thread);
            break;
        case 1:
            break;
    }

    om_unlink_process(proc);
    om_free_process(proc);
}

OMMtx* om_dobj_add_mtx(DObj* dobj, u8 kind, u8 arg2, s32 index) {
    uintptr_t csr;
    struct Mtx3Float* t2;
    struct Mtx4Float* t1;
    struct Mtx3Float* t4;
    s32 i;
    OMMtx* mtx;
    s32 num = dobj->numMatrices;

    if (dobj->numMatrices == 5) {
        fatal_printf("om : couldn\'t add OMMtx for DObj\n");
        while (TRUE) {}
    }

    if (dobj->unk4C != NULL) {
        csr = (uintptr_t)dobj->unk4C->data;
        for (i = 0; i < 3; i++) {
            switch (dobj->unk4C->kinds[i]) {
                case 0:
                    break;
                case 1:
                    t2 = (void*)csr;
                    csr += sizeof(union Mtx3fi);
                    break;
                case 2:
                    t1 = (void*)csr;
                    csr += sizeof(struct Mtx4Float);
                    break;
                case 3:
                    t4 = (void*)csr;
                    csr += sizeof(struct Mtx3Float);
                    break;
            }
        }
    }

    for (; num > index; num--) {
        dobj->matrices[num] = dobj->matrices[num - 1];
    }
    dobj->numMatrices += 1;

    dobj->matrices[index] = mtx = om_get_mtx();
    mtx->kind = kind;

    switch (kind) {
        case MTX_TYPE_TRANSLATE:
        case MTX_TYPE_34:
        case MTX_TYPE_36:
        case MTX_TYPE_38:
        case MTX_TYPE_40:
        case MTX_TYPE_55:
            dobj->position = omD_80040EE8;
            dobj->position.mtx = mtx;
            break;
        case MTX_TYPE_ROTATE_DEG:
        case MTX_TYPE_ROTATE:
            dobj->rotation = omD_80040EF8;
            dobj->rotation.mtx = mtx;
            break;
        case MTX_TYPE_ROTATE_DEG_TRANSLATE:
        case MTX_TYPE_ROTATE_TRANSLATE:
            dobj->position = omD_80040EE8;
            dobj->rotation = omD_80040EF8;
            dobj->position.mtx = mtx;
            dobj->rotation.mtx = mtx;
            break;
        case MTX_TYPE_ROTATE_RPY_DEG:
        case MTX_TYPE_ROTATE_RPY:
        case MTX_TYPE_ROTATE_PYR:
            dobj->rotation = omD_80040F0C;
            dobj->rotation.mtx = mtx;
            break;
        case MTX_TYPE_ROTATE_RPY_TRANSLATE_DEG:
        case MTX_TYPE_ROTATE_RPY_TRANSLATE:
        case MTX_TYPE_ROTATE_PYR_TRANSLATE:
        case MTX_TYPE_51:
        case MTX_TYPE_52:
            dobj->position = omD_80040EE8;
            dobj->rotation = omD_80040F0C;
            dobj->position.mtx = mtx;
            dobj->rotation.mtx = mtx;
            break;
        case MTX_TYPE_ROTATE_TRANSLATE_SCALE:
            dobj->position = omD_80040EE8;
            dobj->rotation = omD_80040EF8;
            dobj->scale = omD_80040F20;
            dobj->position.mtx = mtx;
            dobj->rotation.mtx = mtx;
            dobj->scale.mtx = mtx;
            break;
        case MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE:
        case MTX_TYPE_ROTATE_PYR_TRANSLATE_SCALE:
        case MTX_TYPE_54:
            dobj->position = omD_80040EE8;
            dobj->rotation = omD_80040F0C;
            dobj->scale = omD_80040F20;
            dobj->position.mtx = mtx;
            dobj->rotation.mtx = mtx;
            dobj->scale.mtx = mtx;
            break;
        case MTX_TYPE_SCALE:
        case MTX_TYPE_43:
        case MTX_TYPE_44:
        case MTX_TYPE_47:
        case MTX_TYPE_48:
        case MTX_TYPE_49:
        case MTX_TYPE_50:
        case MTX_TYPE_53:
            dobj->scale = omD_80040F20;
            dobj->scale.mtx = mtx;
            break;
        case MTX_TYPE_45:
        case MTX_TYPE_46:
            dobj->rotation = omD_80040EF8;
            dobj->scale = omD_80040F20;
            dobj->rotation.mtx = mtx;
            dobj->scale.mtx = mtx;
            break;
        case MTX_TYPE_56:
            *t2 = omD_80040EE8;
            t2->mtx = mtx;
            break;
        case MTX_TYPE_57:
            *t1 = omD_80040EF8;
            t1->mtx = mtx;
            break;
        case MTX_TYPE_58:
            *t1 = omD_80040F0C;
            t1->mtx = mtx;
            break;
        case MTX_TYPE_59:
            *t4 = omD_80040F20;
            t4->mtx = mtx;
            break;
        case MTX_TYPE_60:
            *t2 = omD_80040EE8;
            *t1 = omD_80040EF8;
            t2->mtx = t1->mtx = mtx;
            break;
        case MTX_TYPE_61:
            *t2 = omD_80040EE8;
            *t1 = omD_80040EF8;
            *t4 = omD_80040F20;
            t2->mtx = t1->mtx = t4->mtx = mtx;
            break;
        case MTX_TYPE_62:
            *t2 = omD_80040EE8;
            *t1 = omD_80040F0C;
            t2->mtx = t1->mtx = mtx;
            break;
        case MTX_TYPE_63:
            *t2 = omD_80040EE8;
            *t1 = omD_80040F0C;
            *t4 = omD_80040F20;
            t2->mtx = t1->mtx = t4->mtx = mtx;
            break;
        case MTX_TYPE_1:
        case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z_MVIEW:
            // empty branch?
            // could be for any and all cases between 1 and 17
            break;
    }

    mtx->unk05 = arg2;
    return mtx;
}

OMMtx* om_dobj_append_mtx(DObj* dobj, u8 kind, u8 arg2) {
    return om_dobj_add_mtx(dobj, kind, arg2, dobj->numMatrices);
}

OMMtx* om_camera_add_mtx(OMCamera* arg0, u8 kind, u8 arg2) {
    OMMtx* mtx;

    if (arg0->numMatrices == 2) {
        fatal_printf("om : couldn't add OMMtx for Camera\n");
        while (TRUE) {}
    }

    mtx = om_get_mtx();

    arg0->matrices[arg0->numMatrices] = mtx;
    arg0->numMatrices++;
    mtx->kind = kind;

    switch (kind) {
        case MTX_TYPE_PERSP_FAST:
        case MTX_TYPE_PERSP:
            arg0->perspMtx.persp = omD_80040E84;
            arg0->perspMtx.persp.mtx = mtx;
            break;
        case MTX_TYPE_ORTHO:
            arg0->perspMtx.ortho = omD_80040EA0;
            arg0->perspMtx.ortho.mtx = mtx;
            break;
        case MTX_TYPE_LOOKAT:
        case MTX_TYPE_LOOKAT_MVIEW:
        case MTX_TYPE_LOOKAT_ROLL:
        case MTX_TYPE_LOOKAT_ROLL_MVIEW:
        case MTX_TYPE_LOOKAT_ROLL_Z:
        case MTX_TYPE_LOOKAT_ROLL_Z_MVIEW:
        case MTX_TYPE_LOOKAT_REFLECT:
        case MTX_TYPE_LOOKAT_REFLECT_MVIEW:
        case MTX_TYPE_LOOKAT_REFLECT_ROLL:
        case MTX_TYPE_LOOKAT_REFLECT_ROLL_MVIEW:
        case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z:
        case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z_MVIEW:
            arg0->viewMtx.lookAt = omD_80040EC0;
            arg0->viewMtx.lookAt.mtx = mtx;
            break;
        case MTX_TYPE_1:
        case MTX_TYPE_2:
            break;
    }

    mtx->unk05 = arg2;
    return mtx;
}

AObj* om_dobj_add_aobj(DObj* dobj, u8 index) {
    AObj* aobj = om_get_aobj();

    aobj->paramID = index;
    aobj->kind = ANIM_TYPE_NONE;
    aobj->unk20 = NULL;
    aobj->targetRate = 0.0;
    aobj->rate = 0.0;
    aobj->targetValue = 0.0;
    aobj->initialValue = 0.0;
    aobj->time = 0.0;
    aobj->invDuration = 1.0;

    om_dobj_attach_aobj(dobj, aobj);

    return aobj;
}

void om_dobj_reset_animation(DObj* dobj) {
    AObj* curr;
    AObj* origNext;

    curr = dobj->aobjList;
    while (curr != NULL) {
        origNext = curr->next;
        om_free_aobj(curr);
        curr = origNext;
    }
    dobj->aobjList = NULL;
    dobj->timeLeft = ANIMATION_DISABLED;
}

AObj* om_mobj_add_aobj(MObj* mobj, u8 index) {
    AObj* aobj = om_get_aobj();

    aobj->paramID = index;
    aobj->kind = ANIM_TYPE_NONE;
    aobj->unk20 = NULL;
    aobj->targetRate = 0.0;
    aobj->rate = 0.0;
    aobj->targetValue = 0.0;
    aobj->initialValue = 0.0;
    aobj->time = 0.0;
    aobj->invDuration = 1.0;

    om_mobj_attach_aobj(mobj, aobj);

    return aobj;
}

void om_mobj_reset_aobj_list(MObj* mobj) {
    AObj* curr;
    AObj* origNext;

    curr = mobj->aobjList;
    while (curr != NULL) {
        origNext = curr->next;
        om_free_aobj(curr);
        curr = origNext;
    }
    mobj->aobjList = NULL;
    mobj->timeLeft = ANIMATION_DISABLED;
}

AObj* om_camera_add_aobj(OMCamera* obj, u8 index) {
    AObj* aobj = om_get_aobj();

    aobj->paramID = index;
    aobj->kind = ANIM_TYPE_NONE;
    aobj->unk20 = NULL;
    aobj->targetRate = 0.0;
    aobj->rate = 0.0;
    aobj->targetValue = 0.0;
    aobj->initialValue = 0.0;
    aobj->time = 0.0;
    aobj->invDuration = 1.0;

    om_camera_attach_aobj(obj, aobj);

    return aobj;
}

void func_80009B1C(OMCamera* dobj) {
    AObj* curr;
    AObj* origNext;

    curr = dobj->aobjList;
    while (curr != NULL) {
        origNext = curr->next;
        om_free_aobj(curr);
        curr = origNext;
    }
    dobj->aobjList = NULL;
    dobj->timeLeft = ANIMATION_DISABLED;
}

MObj* om_dobj_add_mobj(DObj* dobj, Texture* arg1) {
    MObj* mobj;

    mobj = om_get_mobj();

    if (dobj->mobjList != NULL) {
        MObj* curr = dobj->mobjList->next;
        MObj* prior = dobj->mobjList;
        while (curr != NULL) {
            prior = curr;
            curr = curr->next;
        }
        prior->next = mobj;
    } else {
        dobj->mobjList = mobj;
    }

    mobj->next = NULL;
    mobj->lodLevel = arg1->unk54 / 255.0f;
    mobj->texture = *arg1;

    mobj->texture.unk24 = arg1->unk14;
    mobj->texture.unk28 = arg1->scaleS;
    mobj->imageIndex = 0;
    mobj->nextImageIndex = 0;
    mobj->paletteIndex = 0.f;
    mobj->aobjList = NULL;
    mobj->animList = NULL;
    mobj->timeLeft = ANIMATION_DISABLED;
    mobj->animSpeed = 1.0f;
    mobj->timePassed = 0.0f;

    return mobj;
}

void om_dobj_remove_all_mobj(DObj* dobj) {
    MObj* currM;
    MObj* nextM;
    AObj* currA;
    AObj* nextA;

    currM = dobj->mobjList;
    while (currM != NULL) {
        currA = currM->aobjList;
        while (currA != NULL) {
            nextA = currA->next;
            om_free_aobj(currA);
            currA = nextA;
        }
        nextM = currM->next;
        om_free_mobj(currM);
        currM = nextM;
    }
    dobj->mobjList = NULL;
}

void om_dobj_init(DObj* dobj) {
    s32 i;

    dobj->unk4C = 0;
    dobj->flags = 0;
    dobj->animCBReceiver = FALSE;
    dobj->numMatrices = 0;

    for (i = 0; i < 5; i++) {
        dobj->matrices[i] = NULL;
    }
    dobj->aobjList = NULL;
    dobj->animList = NULL;
    dobj->timeLeft = ANIMATION_DISABLED;
    dobj->animSpeed = 1.0;
    dobj->timePassed = 0.0;
    dobj->mobjList = NULL;
    dobj->unk84 = 0;
}

DObj* om_gobj_add_dobj(GObjCommon* obj, void* arg1) {
    DObj* newDobj;
    DObj* curr;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    newDobj = om_get_dobj();
    if (obj->children != NULL) {
        curr = obj->children;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newDobj;
        newDobj->prev = curr;
    } else {
        obj->type = 1;
        obj->children = newDobj;
        newDobj->prev = NULL;
    }

    newDobj->obj = obj;
    newDobj->parent = (void*)1;
    newDobj->next = NULL;
    newDobj->firstChild = NULL;
    newDobj->unk50 = arg1;

    om_dobj_init(newDobj);

    return newDobj;
}

DObj* om_dobj_add_sibling(DObj* dobj, void* arg1) {
    DObj* newObj;

    newObj = om_get_dobj();
    if (dobj->next != NULL) {
        dobj->next->prev = newObj;
    }
    newObj->prev = dobj;
    newObj->next = dobj->next;
    dobj->next = newObj;
    newObj->obj = dobj->obj;
    newObj->parent = dobj->parent;

    newObj->firstChild = NULL;
    newObj->unk50 = arg1;
    om_dobj_init(newObj);

    return newObj;
}

DObj* om_dobj_add_child(DObj* arg0, void* arg1) {
    DObj* newObj;
    DObj* curr;

    newObj = om_get_dobj();
    if (arg0->firstChild != NULL) {
        curr = arg0->firstChild;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newObj;
        newObj->prev = curr;
    } else {
        arg0->firstChild = newObj;
        newObj->prev = NULL;
    }

    newObj->obj = arg0->obj;
    newObj->parent = arg0;
    newObj->firstChild = NULL;
    newObj->next = NULL;
    newObj->unk50 = arg1;

    om_dobj_init(newObj);

    return newObj;
}

void om_dobj_remove(DObj* dobj) {
    s32 i;
    AObj* currA;
    AObj* nextA;
    MObj* currM;
    MObj* nextM;

    while (dobj->firstChild != NULL) {
        om_dobj_remove(dobj->firstChild);
    }

    if ((uintptr_t)dobj->parent == 1) {
        // toplevel
        if (dobj == dobj->obj->children) {
            dobj->obj->children = dobj->next;
            if (dobj->obj->children == NULL) {
                dobj->obj->type = 0;
            }
        }
    } else if (dobj == dobj->parent->firstChild) {
        dobj->parent->firstChild = dobj->next;
    }

    if (dobj->prev != NULL) {
        dobj->prev->next = dobj->next;
    }

    if (dobj->next != NULL) {
        dobj->next->prev = dobj->prev;
    }

    for (i = 0; i < ARRAY_COUNT(dobj->matrices); i++) {
        if (dobj->matrices[i] != NULL) {
            om_free_mtx(dobj->matrices[i]);
        }
    }

    if (dobj->unk4C != NULL && omD_8004AC0C != NULL) {
        omD_8004AC0C(dobj->unk4C);
    }

    currA = dobj->aobjList;
    while (currA != NULL) {
        nextA = currA->next;
        om_free_aobj(currA);
        currA = nextA;
    }

    currM = dobj->mobjList;
    while (currM != NULL) {
        currA = currM->aobjList;
        while (currA != NULL) {
            nextA = currA->next;
            om_free_aobj(currA);
            currA = nextA;
        }
        nextM = currM->next;
        om_free_mobj(currM);
        currM = nextM;
    }

    om_free_dobj(dobj);
}

SObj* om_gobj_add_sprite(GObjCommon* obj, Sprite* sprite) {
    SObj* sobj;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    sobj = om_get_sobj();

    if (obj->children != NULL) {
        SObj* curr = obj->children;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = sobj;
        sobj->prev = curr;
    } else {
        obj->type = 2;
        obj->children = sobj;
        sobj->prev = NULL;
    }

    sobj->obj = obj;
    sobj->next = NULL;

    if (sprite != NULL) {
        sobj->sprite = *sprite;
    }

    sobj->unk54 = 0;
    return sobj;
}

void om_gobj_remove_sprite(SObj* obj) {
    if (obj == obj->obj->children) {
        obj->obj->children = (void*)obj->next;
        if (obj->obj->children == NULL) {
            obj->obj->type = 0;
        }
    }

    if (obj->prev != NULL) {
        obj->prev->next = obj->next;
    }

    if (obj->next != NULL) {
        obj->next->prev = obj->prev;
    }

    om_free_sobj(obj);
}

OMCamera* om_gobj_set_camera(GObjCommon* obj) {
    s32 i;
    OMCamera* camera;

    if (obj == NULL) {
        obj = omCurrentObject;
    }
    obj->type = 3;

    camera = om_get_camera();
    obj->children = camera;
    camera->obj = obj;
    func_80007CBC(&camera->vp);
    if (FALSE) {} // required to match
    camera->numMatrices = 0;
    for (i = 0; i < ARRAY_COUNT(camera->matrices); i++) {
        camera->matrices[i] = NULL;
    }
    camera->flags = 0;
    camera->unk84 = 0;
    camera->fnPreRender = NULL;
    camera->unk8C = 0;
    camera->aobjList = NULL;
    camera->animList = 0;
    camera->timeLeft = ANIMATION_DISABLED;
    camera->animSpeed = 1.0;
    camera->timePassed = 0.0;

    return camera;
}

void om_gobj_remove_camera(OMCamera* cam) {
    GObjCommon* obj;
    s32 i;
    AObj* curr;
    AObj* next;

    obj = cam->obj;
    obj->type = 0;
    obj->children = NULL;

    for (i = 0; i < ARRAY_COUNT(cam->matrices); i++) {
        if (cam->matrices[i] != NULL) {
            om_free_mtx(cam->matrices[i]);
        }
    }

    curr = cam->aobjList;
    while (curr != NULL) {
        next = curr->next;
        om_free_aobj(curr);
        curr = next;
    }

    om_free_camera(cam);
}

GObjCommon* om_add_gobj_common(u32 id, void (*fnUpdate)(GObjCommon*), u8 link, u32 priority) {
    GObjCommon* obj;

    if (link >= 32) {
        fatal_printf("omGAddCommon() : link num over : link = %d : id = %d\n", link, id);
        while (TRUE) {}
    }

    obj = om_get_gobj();
    if (obj == NULL) {
        return NULL;
    }

    obj->id = id;
    obj->link = link;
    obj->priority = priority;
    obj->fnUpdate = fnUpdate;
    obj->processListHead = NULL;
    obj->processListTail = NULL;
    obj->sub3C.count = 0;
    obj->sub3C.head = NULL;
    obj->sub3C.tail = NULL;
    obj->animationTime = 0.0f;
    obj->flags = 0;
    obj->type = 0;
    obj->children = NULL;
    obj->dlLink = 33;

    if (FALSE) {} // required to match

    obj->fnAnimCallback = NULL;
    obj->unk_58 = 0;
    return obj;
}

GObjCommon* om_add_gobj(u32 id, void (*fnUpdate)(GObjCommon*), u8 link, u32 priority) {
    GObjCommon* com = om_add_gobj_common(id, fnUpdate, link, priority);

    if (com == NULL) {
        return NULL;
    }

    om_link_gobj_after_same_priority(com);

    return com;
}

GObjCommon* om_add_gobj_before_same_priority(u32 id, void (*fnUpdate)(GObjCommon*), u8 link, u32 priority) {
    GObjCommon* com = om_add_gobj_common(id, fnUpdate, link, priority);

    if (com == NULL) {
        return NULL;
    }

    om_link_gobj_before_same_priority(com);

    return com;
}

GObjCommon* om_add_gobj_after(u32 id, void (*fnUpdate)(GObjCommon*), GObjCommon* arg2) {
    GObjCommon* com = om_add_gobj_common(id, fnUpdate, arg2->link, arg2->priority);

    if (com == NULL) {
        return NULL;
    }

    om_link_gobj_after(com, arg2);

    return com;
}

GObjCommon* om_add_gobj_before(u32 id, void (*fnUpdate)(GObjCommon*), GObjCommon* arg2) {
    GObjCommon* com = om_add_gobj_common(id, fnUpdate, arg2->link, arg2->priority);

    if (com == NULL) {
        return NULL;
    }

    om_link_gobj_after(com, arg2->prev);

    return com;
}

void func_8000A52C(GObjCommon* obj) {
    if (obj == NULL || obj == omCurrentObject) {
        omD_8004AC54 = 2;
        return;
    }

    omh_end_all_object_processes(obj);
    func_8000B740(&obj->sub3C);
    switch (obj->type) {
        case 1:
            func_8000C1CC(obj);
            break;
        case 2:
            func_8000C220(obj);
            break;
        case 3:
            om_gobj_remove_camera(obj->children);
            break;
    }

    if (obj->dlLink != 33) {
        om_unlink_gobj_dl(obj);
    }
    om_unlink_gobj(obj);
    om_free_gobj(obj);
}

void om_move_gobj_common(s32 moveType, GObjCommon* obj, u8 link, u32 priority, GObjCommon* refObj) {
    GObjProcess* csr;
    GObjProcess* procList;
    GObjProcess* next;

    if (link >= 32) {
        fatal_printf("omGMoveCommon() : link num over : link = %d : id = %d\n", link, obj->id);

        while (TRUE) {}
    }

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    procList = obj->processListHead;
    obj->processListHead = NULL;
    obj->processListTail = NULL;

    csr = procList;
    while (csr != NULL) {
        om_unlink_process_from_priority_list(csr);
        csr = csr->next;
    }
    om_unlink_gobj(obj);
    obj->link = link;
    obj->priority = priority;

    switch (moveType) {
        case 0:
            om_link_gobj_after_same_priority(obj);
            break;
        case 1:
            om_link_gobj_before_same_priority(obj);
            break;
        case 2:
            om_link_gobj_after(obj, refObj);
            break;
        case 3:
            om_link_gobj_after(obj, refObj->prev);
            break;
    }

    csr = procList;
    while (csr != NULL) {
        next = csr->next;
        om_link_process(csr);
        csr = next;
    }
}

void om_move_gobj_after_same_priority(GObjCommon* obj, u8 link, u32 priority) {
    om_move_gobj_common(0, obj, link, priority, NULL);
}

void om_move_gobj_before_same_priority(GObjCommon* arg0, u8 link, u32 arg2) {
    om_move_gobj_common(1, arg0, link, arg2, NULL);
}

void om_move_gobj_after(GObjCommon* arg0, GObjCommon* arg1) {
    om_move_gobj_common(2, arg0, arg1->link, arg1->priority, arg1);
}

void om_move_gobj_before(GObjCommon* arg0, GObjCommon* arg1) {
    om_move_gobj_common(3, arg0, arg1->link, arg1->priority, arg1);
}

void om_link_gobj_dl_common(GObjCommon* obj, void (*renderFunc)(GObjCommon*), u8 dlLink, s32 dlPriority,
                            s32 cameraTag) {
    if (dlLink >= 32) {
        fatal_printf("omGLinkObjDLCommon() : dl_link num over : dl_link = %d : id = %d\n", dlLink, obj->id);
        while (TRUE) {}
    }

    obj->dlLink = dlLink;
    obj->dlPriority = dlPriority;
    obj->fnRender = renderFunc;
    obj->cameraTag = cameraTag;
    obj->lastDrawFrame = gtlDrawnFrameCounter - 1;
}

void om_link_gobj_dl(GObjCommon* obj, void (*arg1)(GObjCommon*), u8 dlLink, s32 dlPriority, s32 cameraTag) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    om_link_gobj_dl_common(obj, arg1, dlLink, dlPriority, cameraTag);
    om_insert_gobj_dl_after_same_priority(obj);
}

void om_link_gobj_dl_before_same_priority(GObjCommon* obj, void (*renderFunc)(GObjCommon*), u8 dlLink, s32 dlPriority,
                                          s32 arg4) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    om_link_gobj_dl_common(obj, renderFunc, dlLink, dlPriority, arg4);
    om_insert_gobj_dl_before_same_priority(obj);
}

void om_link_gobj_dl_after(GObjCommon* obj, void (*renderFunc)(GObjCommon*), s32 arg2, GObjCommon* other) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    om_link_gobj_dl_common(obj, renderFunc, other->dlLink, other->dlPriority, arg2);
    om_insert_gobj_dl(obj, other);
}

void om_link_gobj_dl_before(GObjCommon* obj, void (*renderFunc)(struct GObjCommon*), s32 arg2, GObjCommon* other) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    om_link_gobj_dl_common(obj, renderFunc, other->dlLink, other->dlPriority, arg2);
    om_insert_gobj_dl(obj, other->prev);
}

void om_link_gobj_dl_camera_common(GObjCommon* obj, void (*renderFunc)(GObjCommon*), u32 dlPriority, s32 dlLinkBitMask,
                                   s32 cameraTag) {
    obj->dlLink = 32;
    obj->dlPriority = dlPriority;
    obj->fnRender = renderFunc;
    obj->dlLinkBitMask = dlLinkBitMask;
    obj->cameraTag = cameraTag;
    obj->unk38 = 0;
    obj->lastDrawFrame = gtlDrawnFrameCounter - 1;
}

void om_link_gobj_dl_camera(GObjCommon* obj, void (*renderFunc)(GObjCommon*), u32 dlPriority, s32 dlLinkBitMask,
                            s32 cameraTag) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    om_link_gobj_dl_camera_common(obj, renderFunc, dlPriority, dlLinkBitMask, cameraTag);
    om_insert_gobj_dl_after_same_priority(obj);
}

void om_link_gobj_dl_camera_before_same_priority(GObjCommon* arg0, void (*arg1)(GObjCommon*), u32 arg2, s32 arg3,
                                                 s32 arg4) {
    if (arg0 == NULL) {
        arg0 = omCurrentObject;
    }
    om_link_gobj_dl_camera_common(arg0, arg1, arg2, arg3, arg4);
    om_insert_gobj_dl_before_same_priority(arg0);
}

void om_link_gobj_dl_camera_after(GObjCommon* arg0, void (*arg1)(GObjCommon*), s32 arg2, s32 arg3, GObjCommon* arg4) {
    if (arg0 == NULL) {
        arg0 = omCurrentObject;
    }
    om_link_gobj_dl_camera_common(arg0, arg1, arg4->dlPriority, arg2, arg3);
    om_insert_gobj_dl(arg0, arg4);
}

void om_link_gobj_dl_camera_before(GObjCommon* arg0, void (*arg1)(GObjCommon*), s32 arg2, s32 arg3, GObjCommon* arg4) {
    if (arg0 == NULL) {
        arg0 = omCurrentObject;
    }
    om_link_gobj_dl_camera_common(arg0, arg1, arg4->dlPriority, arg2, arg3);
    om_insert_gobj_dl(arg0, arg4->prev);
}

void om_move_gobj_dl(GObjCommon* arg0, u8 dlLink, u32 dlPriority) {
    if (dlLink >= 32) {
        fatal_printf("omGMoveObjDL() : dl_link num over : dl_link = %d : id = %d\n", dlLink, arg0->id);
        while (TRUE) {}
    }

    om_unlink_gobj_dl(arg0);
    arg0->dlLink = dlLink;
    arg0->dlPriority = dlPriority;
    om_insert_gobj_dl_after_same_priority(arg0);
}

void func_8000ABAC(GObjCommon* arg0, u8 dlLink, u32 arg2) {
    if (dlLink >= 32) {
        fatal_printf("omGMoveObjDLHead() : dl_link num over : dl_link = %d : id = %d\n", dlLink, arg0->id);
        while (TRUE) {}
    }
    om_unlink_gobj_dl(arg0);
    arg0->dlLink = dlLink;
    arg0->dlPriority = arg2;
    om_insert_gobj_dl_before_same_priority(arg0);
}

void func_8000AC28(GObjCommon* arg0, GObjCommon* arg1) {
    om_unlink_gobj_dl(arg0);
    arg0->dlLink = arg1->dlLink;
    arg0->dlPriority = arg1->dlPriority;
    om_insert_gobj_dl(arg0, arg1);
}

void func_8000AC68(GObjCommon* arg0, GObjCommon* arg1) {
    om_unlink_gobj_dl(arg0);
    arg0->dlLink = arg1->dlLink;
    arg0->dlPriority = arg1->dlPriority;
    om_insert_gobj_dl(arg0, arg1->prevDl);
}

void func_8000ACAC(GObjCommon* arg0, u32 dlPriority) {
    om_unlink_gobj_dl(arg0);
    arg0->dlPriority = dlPriority;
    om_insert_gobj_dl_after_same_priority(arg0);
}

void func_8000ACE0(GObjCommon* arg0, u32 dlPriority) {
    om_unlink_gobj_dl(arg0);
    arg0->dlPriority = dlPriority;
    om_insert_gobj_dl_before_same_priority(arg0);
}

void func_8000AD14(GObjCommon* obj, GObjCommon* other) {
    om_unlink_gobj_dl(obj);
    obj->dlPriority = other->dlPriority;
    om_insert_gobj_dl(obj, other);
}

void func_8000AD4C(GObjCommon* arg0, GObjCommon* arg1) {
    om_unlink_gobj_dl(arg0);
    arg0->dlPriority = arg1->dlPriority;
    om_insert_gobj_dl(arg0, arg1->prev);
}

void om_set_max_objects(s32 n) {
    omMaxObjects = n;
}

s16 om_get_max_objects(void) {
    return omMaxObjects;
}

void om_draw_all(void) {
    s32 i;
    GObjCommon* curr;

    omCurrentCamera = NULL;
    omRenderedObject = NULL;

    for (i = 0; i < ARRAY_COUNT(omD_8004AC78); i++) {
        omD_8004AC78[i].unk00 = gtlDrawnFrameCounter - 1;
    }

    curr = omGObjListDlHead[32];
    while (curr != NULL) {
        if (!(curr->flags & GOBJ_FLAG_1)) {
            omCurrentCamera = curr;
            curr->fnRender(curr);
        }
        curr = curr->nextDl;
    }
}

GObjCommon* om_update_gobj(GObjCommon* arg0) {
    GObjCommon* ret;

    omCurrentObject = arg0;
    arg0->fnUpdate(arg0);
    ret = arg0->next;
    omCurrentObject = NULL;

    switch (omD_8004AC54) {
        case 0:
            break;
        case 2:
            omD_8004AC54 = 0;
            func_8000A52C(arg0);
            break;
        default:
            omD_8004AC54 = 0;
            break;
    }

    return ret;
}

GObjProcess* om_run_process(GObjProcess* proc) {
    GObjProcess* ret;

    omCurrentObject = proc->object;
    omCurrentProcess = proc;

    switch (proc->kind) {
        case 0: {
            osStartThread(&proc->unk1C.thread->osThread);
            osRecvMesg(&omProcessWaitQueue, NULL, OS_MESG_BLOCK);
            break;
        }
        case 1: {
            proc->unk1C.cb(proc->object);
            break;
        }
    }

    ret = proc->nextInPriorityList;

    omCurrentObject = NULL;
    omCurrentProcess = NULL;

    switch (omD_8004AC54) {
        case 2:
            omD_8004AC54 = 0;
            while (ret != NULL && ret->object == proc->object) {
                ret = ret->nextInPriorityList;
            }

            func_8000A52C(proc->object);
            break;
        case 1:
            omD_8004AC54 = 0;
            om_end_process(proc);
            break;
        case 0:
            break;
        default:
            omD_8004AC54 = 0;
            break;
    }

    return ret;
}

void om_update_all(void) {
    s32 i;
    GObjCommon* obj;
    GObjProcess* proc;

    omD_8004AC54 = 0;
    omCurrentObject = NULL;
    omCurrentProcess = NULL;

    for (i = 0; i < 32; i++) {
        obj = omGObjListHead[i];
        while (obj != NULL) {
            if (!(obj->flags & GOBJ_FLAG_40) && obj->fnUpdate != NULL) {
                obj = om_update_gobj(obj);
            } else {
                obj = obj->next;
            }
        }
    }

    for (i = ARRAY_COUNT(omGProcessList) - 1; i >= 0; i--) {
        proc = omGProcessList[i];
        while (proc != NULL) {
            if (!proc->paused) {
                proc = om_run_process(proc);
            } else {
                proc = proc->nextInPriorityList;
            }
        }
    }
}

void om_create_objects(OMSetup* setup) {
    s32 i;

    omDefaultStackSize = setup->threadStackSize;
    omD_8004A9A0 = setup->unk14;

    if (setup->numThreads != 0) {
        GObjThread* csr;
        omFreeThreadList = csr = setup->threads;

        for (i = 0; i < setup->numThreads - 1; i++) {
            GObjThread* next = csr + 1;

            csr->next = next;
            csr = next;
        }
        csr->next = NULL;
    } else {
        omFreeThreadList = NULL;
    }

    if (setup->numStacks != 0 && setup->threadStackSize != NULL) {
        ThreadStackNode* csr;

        omFreeStackList = gtlMalloc(sizeof(ThreadStackList), 4);
        omFreeStackList->next = NULL;
        omFreeStackList->size = omDefaultStackSize;
        omFreeStackList->stack = csr = setup->stacks;

        for (i = 0; (u32)i < setup->numStacks - 1; i++) {
            csr->next = (void*)((uintptr_t)csr + omDefaultStackSize + 8); // offsetof(struct ThreadStackNode, stack));
            csr->stackSize = omDefaultStackSize;
            csr = (void*)((uintptr_t)csr + omDefaultStackSize + 8);       // offsetof(struct ThreadStackNode, stack));
        }

        csr->stackSize = omDefaultStackSize;
        csr->next = NULL;
    } else {
        omFreeStackList = NULL;
    }

    if (setup->numProcesses != 0) {
        GObjProcess* csr;
        omFreeProcessList = csr = setup->processes;

        for (i = 0; i < setup->numProcesses - 1; i++) {
            GObjProcess* next = csr + 1;

            csr->next = next;
            csr = next;
        }

        csr->next = NULL;
    } else {
        omFreeProcessList = NULL;
    }

    for (i = 0; i < ARRAY_COUNT(omGProcessList); i++) {
        omGProcessList[i] = NULL;
    }

    if (setup->numObjects != 0) {
        GObjCommon* csr;
        omFreeGObjList = csr = setup->commons;

        // todo: is this the purest form?
        for (i = 0; i < setup->numObjects - 1; i++) {
            csr->next = (void*)((uintptr_t)csr + setup->objectSize);
            csr = csr->next;
        }
        csr->next = NULL;

    } else {
        omFreeGObjList = NULL;
    }

    omGObjSize = setup->objectSize;
    omMaxObjects = -1;
    omD_8004AC0C = setup->cleanupFn;

    if (setup->numMatrices != 0) {
        OMMtx* csr;

        omFreeMtxList = csr = setup->matrices;

        for (i = 0; i < setup->numMatrices - 1; i++) {
            OMMtx* next = csr + 1;

            csr->next = next;
            csr = next;
        }
        csr->next = NULL;
    } else {
        omFreeMtxList = NULL;
    }

    if (setup->numAObjs != 0) {
        AObj* csr;

        omFreeAObjList = csr = setup->aobjs;

        for (i = 0; i < setup->numAObjs - 1; i++) {
            AObj* next = csr + 1;

            csr->next = next;
            csr = next;
        }
        csr->next = NULL;
    } else {
        omFreeAObjList = NULL;
    }

    if (setup->numMObjs != 0) {
        MObj* csr;

        omFreeMObjList = csr = setup->mobjs;

        for (i = 0; i < setup->numMObjs - 1; i++) {
            MObj* next = csr + 1;

            csr->next = next;
            csr = next;
        }
        csr->next = NULL;

    } else {
        omFreeMObjList = NULL;
    }

    if (setup->numDObjs != 0) {
        DObj* csr;
        omFreeDObjList = csr = setup->dobjs;

        for (i = 0; i < setup->numDObjs - 1; i++) {
            csr->nextFree = (void*)((uintptr_t)csr + setup->dobjSize);
            csr = csr->nextFree;
        }

        csr->nextFree = NULL;
    } else {
        omFreeDObjList = NULL;
    }
    omDObjSize = setup->dobjSize;

    if (setup->numSObjs != 0) {
        SObj* csr;
        omFreeSObjList = csr = setup->sobjs;

        for (i = 0; i < setup->numSObjs - 1; i++) {
            csr->nextFree = (void*)((uintptr_t)csr + setup->sobjSize);
            csr = csr->nextFree;
        }

        csr->nextFree = NULL;
    } else {
        omFreeSObjList = NULL;
    }
    omSObjSize = setup->sobjSize;

    if (setup->numCameras != 0) {
        OMCamera* csr;
        omFreeCameraList = csr = setup->cameras;

        for (i = 0; i < setup->numCameras - 1; i++) {
            csr->nextFree = (void*)((uintptr_t)csr + setup->cameraSize);
            csr = csr->nextFree;
        }

        csr->nextFree = NULL;
    } else {
        omFreeCameraList = NULL;
    }
    omCameraSize = setup->cameraSize;

    for (i = 0; i < 32; i++) {
        omGObjListTail[i] = NULL;
        omGObjListHead[i] = NULL;
    }

    for (i = 0; i < 33; i++) {
        omGObjListDlTail[i] = NULL;
        omGObjListDlHead[i] = NULL;
    }

    func_80015448();
    osCreateMesgQueue(&omProcessWaitQueue, omProcessWaitMsgs, ARRAY_COUNT(omProcessWaitMsgs));

    omActiveStacks = omActiveThreads = omActiveProcesses = omActiveObjects = omActiveMatrices = omActiveAObj =
        omActiveDObj = omActiveSObj = omActiveCameras = 0;

    omEndProcessHandler = NULL;
    func_80018CD0(0);
    func_8000B998();
}
