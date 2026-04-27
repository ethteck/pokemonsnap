#include "sys/om.h"
#include "sys/oh.h"
#include "sys/cmd.h"
#include "sys/gtl.h"
#include "sys/crash.h"
#include "sys/rdp_reset.h"
#include "sys/render.h"
#include "macros.h"

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
GObj* omGObjListHead[32]; // indexed by link
GObj* omGObjListTail[32];
GObj* omFreeGObjList;
GObj* omGObjListDlHead[33]; // indexed by dlLink
GObj* omGObjListDlTail[33];
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
GObj* omCurrentObject;
GObj* omCurrentCamera;
GObj* omRenderedObject;
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
struct Mtx4Float omD_80040EF8 = { NULL, 0.0, { 0.0, 0.0, 1.0 } };
struct Mtx4Float omD_80040F0C = { NULL, 0.0, { 0.0, 0.0, 0.0 } };
struct Mtx3Float omD_80040F20 = { NULL, { 1.0, 1.0, 1.0 } };

GObjThread* omGetThread(void) {
    GObjThread* ret;

    if (omFreeThreadList == NULL) {
        omFreeThreadList = gtlMalloc(sizeof(GObjThread), 8);
    }

    if (omFreeThreadList == NULL) {
        error_printf("om : couldn't get GObjThread\n");
        PANIC();
    }

    ret = omFreeThreadList;
    omFreeThreadList = omFreeThreadList->next;
    omActiveThreads++;

    return ret;
}

void omFreeThread(GObjThread* t) {
    t->next = omFreeThreadList;
    omFreeThreadList = t;
    omActiveThreads--;
}

ThreadStackNode* omGetStackOfSize(u32 size) {
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

ThreadStackNode* omGetDefaultStack(void) {
    return omGetStackOfSize(omDefaultStackSize);
}

void omFreeStack(ThreadStackNode* node) {
    ThreadStackList* parent;

    parent = omFreeStackList;
    while (parent != NULL) {
        if (parent->size == node->stackSize) {
            break;
        }
        parent = parent->next;
    }

    if (parent == NULL) {
        error_printf("om : Illegal GObjThreadStack Link\n");
        PANIC();
    }

    node->next = parent->stack;
    parent->stack = node;
    omActiveStacks--;
}

GObjProcess* omGetProcess(void) {
    GObjProcess* ret;

    if (omFreeProcessList == NULL) {
        omFreeProcessList = gtlMalloc(sizeof(GObjProcess), 4);
    }

    if (omFreeProcessList == NULL) {
        error_printf("om : couldn't get GObjProcess\n");
        PANIC();
    }

    ret = omFreeProcessList;
    omFreeProcessList = omFreeProcessList->next;
    omActiveProcesses++;

    return ret;
}

void omLinkProcess(GObjProcess* proc) {
    GObj* obj = proc->object;
    GObj* curObj = proc->object;
    s32 curLink = curObj->link;
    curObj = curObj; // required to match

    // find place in priority list
    // here it is assumed that objects with lower link and priority have processes with lower priority
    while (true) {
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

void omFreeProcess(GObjProcess* proc) {
    proc->next = omFreeProcessList;
    omFreeProcessList = proc;
    omActiveProcesses--;
}

void omUnlinkProcessFromPriorityList(GObjProcess* proc) {
    if (proc->prevInPriorityList != NULL) {
        proc->prevInPriorityList->nextInPriorityList = proc->nextInPriorityList;
    } else {
        omGProcessList[proc->priority] = proc->nextInPriorityList;
    }

    if (proc->nextInPriorityList != NULL) {
        proc->nextInPriorityList->prevInPriorityList = proc->prevInPriorityList;
    }
}

void omUnlinkProcess(GObjProcess* proc) {
    GObj* obj = proc->object;

    omUnlinkProcessFromPriorityList(proc);
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

GObjProcess* omGetCurrentProcess(void) {
    return omCurrentProcess;
}

u64* omGetProcessStack(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    if (proc != NULL && proc->kind == 0) {
        return proc->unk_1C.thread->osStack;
    }

    return NULL;
}

s32 omGetProcessStackSize(GObjProcess* proc) {
    if (proc == NULL) {
        proc = omCurrentProcess;
    }

    if (proc != NULL && proc->kind == 0) {
        return proc->unk_1C.thread->stackSize;
    }

    return NULL;
}

void omSetEndProcessHandler(void (*handler)(GObjProcess*)) {
    omEndProcessHandler = handler;
}

s32 omGetTotalGObjNumber(void) {
    GObj* curr = omFreeGObjList;
    s32 i = 0;

    while (curr != NULL) {
        i++;
        curr = curr->next;
    }

    return i + omActiveObjects;
}

GObj* omGetGObj(void) {
    GObj* ret;

    if (omMaxObjects == -1 || omActiveObjects < omMaxObjects) {
        ret = omFreeGObjList;
        if (ret == NULL) {
            omFreeGObjList = gtlMalloc(omGObjSize, 8);
            ret = omFreeGObjList;
        }
    } else {
        error_printf("om : limit over get GObj\n");
        PANIC();
    }

    if (ret == NULL) {
        error_printf("om : couldn't get GObj\n");
        PANIC();
    }
    if (ret == NULL) {
        return NULL;
    }
    omFreeGObjList = ret->next;
    omActiveObjects++;

    return ret;
}

void omFreeGObj(GObj* obj) {
    obj->next = omFreeGObjList;
    omFreeGObjList = obj;
    omActiveObjects--;
}

void omLinkGObjAfter(GObj* obj, GObj* prevObj) {
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

void omLinkGObjAfterSamePriority(GObj* obj) {
    GObj* curr;

    curr = omGObjListTail[obj->link];
    while (curr != NULL && curr->priority < obj->priority) {
        curr = curr->prev;
    }

    omLinkGObjAfter(obj, curr);
}

void omLinkGObjBeforeSamePriority(GObj* obj) {
    GObj* curr;
    GObj* beforeCurr;

    curr = omGObjListHead[obj->link];
    while (curr != NULL && obj->priority < curr->priority) {
        curr = curr->next;
    }

    if (curr != NULL) {
        beforeCurr = curr->prev;
    } else {
        beforeCurr = omGObjListTail[obj->link];
    }

    omLinkGObjAfter(obj, beforeCurr);
}

void omUnlinkGObj(GObj* obj) {
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

void omInsertGObjDL(GObj* obj, GObj* prevObj) {
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

void omInsertGObjDLAfterSamePriority(GObj* obj) {
    GObj* csr;

    csr = omGObjListDlTail[obj->dlLink];
    while (csr != NULL && csr->dlPriority < obj->dlPriority) {
        csr = csr->prevDl;
    }
    omInsertGObjDL(obj, csr);
}

void omInsertGObjDLBeforeSamePriority(GObj* obj) {
    GObj* curr;
    GObj* found;

    curr = omGObjListDlHead[obj->dlLink];
    while (curr != NULL && obj->dlPriority < curr->dlPriority) {
        curr = curr->nextDl;
    }

    if (curr != NULL) {
        found = curr->prevDl;
    } else {
        found = omGObjListDlTail[obj->dlLink];
    }

    omInsertGObjDL(obj, found);
}

void omUnlinkGObjDL(GObj* obj) {
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

OMMtx* omGetMtx(void) {
    OMMtx* ret;

    if (omFreeMtxList == NULL) {
        omFreeMtxList = gtlMalloc(sizeof(OMMtx), 8);
    }

    if (omFreeMtxList == NULL) {
        error_printf("om : couldn't get OMMtx\n");
        PANIC();
    }

    ret = omFreeMtxList;
    omFreeMtxList = omFreeMtxList->next;
    omActiveMatrices++;
    return ret;
}

void omFreeMtx(OMMtx* mtx) {
    mtx->next = omFreeMtxList;
    omFreeMtxList = mtx;
    omActiveMatrices--;
}

AObj* omGetAObj(void) {
    AObj* ret;

    if (omFreeAObjList == NULL) {
        omFreeAObjList = gtlMalloc(sizeof(AObj), 4);
    }

    if (omFreeAObjList == NULL) {
        error_printf("om : couldn't get AObj\n");
        PANIC();
    }

    ret = omFreeAObjList;
    omFreeAObjList = omFreeAObjList->next;
    omActiveAObj++;
    return ret;
}

void omDObjAttachAObj(DObj* dobj, AObj* aobj) {
    aobj->next = dobj->aobjList;
    dobj->aobjList = aobj;
}

void omMObjAttachAObj(MObj* mobj, AObj* aobj) {
    aobj->next = mobj->aobjList;
    mobj->aobjList = aobj;
}

void omCameraAttachAObj(OMCamera* cam, AObj* aobj) {
    aobj->next = cam->aobjList;
    cam->aobjList = aobj;
}

void omFreeAObj(AObj* aobj) {
    aobj->next = omFreeAObjList;
    omFreeAObjList = aobj;
    omActiveAObj--;
}

MObj* omGetMObj(void) {
    MObj* ret;

    if (omFreeMObjList == NULL) {
        omFreeMObjList = gtlMalloc(sizeof(MObj), 4);
    }

    if (omFreeMObjList == NULL) {
        error_printf("om : couldn't get MObj\n");
        PANIC();
    }

    ret = omFreeMObjList;
    omFreeMObjList = omFreeMObjList->next;
    omActiveMobj++;

    return ret;
}

void omFreeMObj(MObj* obj) {
    obj->next = omFreeMObjList;
    omFreeMObjList = obj;
    omActiveMobj--;
}

DObj* omGetDObj(void) {
    DObj* ret;

    if (omFreeDObjList == NULL) {
        omFreeDObjList = gtlMalloc(omDObjSize, 8);
    }

    if (omFreeDObjList == NULL) {
        error_printf("om : couldn't get DObj\n");
        PANIC();
    }

    ret = omFreeDObjList;
    omFreeDObjList = omFreeDObjList->nextFree;
    omActiveDObj++;

    return ret;
}

void omFreeDObj(DObj* obj) {
    obj->nextFree = omFreeDObjList;
    omFreeDObjList = obj;
    omActiveDObj--;
}

SObj* omGetSObj(void) {
    SObj* ret;

    if (omFreeSObjList == NULL) {
        omFreeSObjList = gtlMalloc(omSObjSize, 8);
    }

    if (omFreeSObjList == NULL) {
        error_printf("om : couldn't get SObj\n");
        PANIC();
    }

    ret = omFreeSObjList;
    omFreeSObjList = omFreeSObjList->nextFree;
    omActiveSObj++;

    return ret;
}

void omFreeSObj(SObj* obj) {
    obj->nextFree = omFreeSObjList;
    omFreeSObjList = obj;
    omActiveSObj--;
}

OMCamera* omGetCamera(void) {
    OMCamera* ret;

    if (omFreeCameraList == NULL) {
        omFreeCameraList = gtlMalloc(omCameraSize, 8);
    }

    if (omFreeCameraList == NULL) {
        error_printf("om : couldn't get Camera\n");
        PANIC();
    }

    ret = omFreeCameraList;
    omFreeCameraList = omFreeCameraList->nextFree;
    omActiveCameras++;

    return ret;
}

void omFreeCamera(OMCamera* obj) {
    obj->nextFree = omFreeCameraList;
    omFreeCameraList = obj;
    omActiveCameras--;
}

GObjProcess* omCreateProcess(GObj* obj, void (*func)(struct GObj*), u8 kind, u32 pri) {
    ThreadStackNode* stackNode;
    GObjThread* thread;
    GObjProcess* process;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    process = omGetProcess();
    if (pri > 11) {
        error_printf("om : GObjProcess's priority is bad value\n");
        PANIC();
    }
    process->priority = pri;
    process->kind = kind;
    process->paused = 0;
    process->object = obj;
    process->function = func;

    switch (kind) {
        case 0:
            thread = omGetThread();
            process->unk_1C.thread = thread;

            stackNode = omGetDefaultStack();
            thread->osStack = stackNode->stack;
            thread->stackSize = omDefaultStackSize;
            osCreateThread(&thread->osThread, omThreadCounter++, (void (*)(void*)) func, obj, &thread->osStack[omDefaultStackSize / 8],
                           51);
            thread->osStack[7] = 0xFEDCBA98;

            if (omThreadCounter >= 20000000) {
                omThreadCounter = 10000000;
            }
            break;
        case 1:
            process->unk_1C.cb = func;
            break;
        default:
            error_printf("om : GObjProcess's kind is bad value\n");
            PANIC();
    }

    omLinkProcess(process);
    return process;
}

GObjProcess* omCreateProcessThreaded(GObj* obj, void (*entry)(GObj*), u32 pri, s32 threadId, u32 stackSize) {
    GObjProcess* process;
    GObjThread* thread;
    ThreadStackNode* stackNode;
    OSId tid;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    process = omGetProcess();

    if (pri > 11) {
        error_printf("om : GObjProcess's priority is bad value\n");
        PANIC();
    }

    process->priority = pri;
    process->paused = 0;
    process->object = obj;
    process->function = entry;

    process->unk_1C.thread = thread = omGetThread();
    process->kind = 0;

    stackNode = stackSize == 0 ? omGetDefaultStack() : omGetStackOfSize(stackSize);
    thread->osStack = stackNode->stack;
    thread->stackSize = stackSize == 0 ? omDefaultStackSize : stackSize;
    tid = threadId != -1 ? threadId : omThreadCounter++;

    osCreateThread(&thread->osThread, tid, (void (*)(void*)) entry, obj, &thread->osStack[thread->stackSize / 8], 51);
    thread->osStack[7] = 0xFEDCBA98;
    if (omThreadCounter >= 20000000) {
        omThreadCounter = 10000000;
    }

    omLinkProcess(process);
    return process;
}

void omEndProcess(GObjProcess* proc) {
    ThreadStackNode* tnode;

    if (proc == NULL || proc == omCurrentProcess) {
        omD_8004AC54 = 1;
        if (omCurrentProcess->kind == 0) {
            ohWait(1);
        }
        return;
    }

    if (omEndProcessHandler != NULL) {
        omEndProcessHandler(proc);
    }

    switch (proc->kind) {
        case 0:
            osDestroyThread(&proc->unk_1C.thread->osThread);
            // cast from stack pointer back to stack node
            tnode = (void*) ((uintptr_t) (proc->unk_1C.thread->osStack) - 8); /*offsetof(struct ThreadStackNode, stack));*/
            omFreeStack(tnode);
            omFreeThread(proc->unk_1C.thread);
            break;
        case 1:
            break;
    }

    omUnlinkProcess(proc);
    omFreeProcess(proc);
}

OMMtx* omDObjAddMtx(DObj* dobj, u8 kind, u8 arg2, s32 index) {
    uintptr_t csr;
    struct Mtx3Float* t2;
    struct Mtx4Float* t1;
    struct Mtx3Float* t4;
    s32 i;
    OMMtx* mtx;
    s32 num = dobj->numMatrices;

    if (dobj->numMatrices == 5) {
        error_printf("om : couldn\'t add OMMtx for DObj\n");
        PANIC();
    }

    if (dobj->unk_4C != NULL) {
        csr = (uintptr_t) dobj->unk_4C->data;
        for (i = 0; i < 3; i++) {
            switch (dobj->unk_4C->kinds[i]) {
                case 0:
                    break;
                case 1:
                    t2 = (void*) csr;
                    csr += sizeof(union Mtx3fi);
                    break;
                case 2:
                    t1 = (void*) csr;
                    csr += sizeof(struct Mtx4Float);
                    break;
                case 3:
                    t4 = (void*) csr;
                    csr += sizeof(struct Mtx3Float);
                    break;
            }
        }
    }

    for (; num > index; num--) {
        dobj->matrices[num] = dobj->matrices[num - 1];
    }
    dobj->numMatrices += 1;

    dobj->matrices[index] = mtx = omGetMtx();
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

    mtx->unk_05 = arg2;
    return mtx;
}

OMMtx* omDObjAppendMtx(DObj* dobj, u8 kind, u8 arg2) {
    return omDObjAddMtx(dobj, kind, arg2, dobj->numMatrices);
}

OMMtx* omCameraAddMtx(OMCamera* arg0, u8 kind, u8 arg2) {
    OMMtx* mtx;

    if (arg0->numMatrices == 2) {
        error_printf("om : couldn't add OMMtx for Camera\n");
        PANIC();
    }

    mtx = omGetMtx();

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

    mtx->unk_05 = arg2;
    return mtx;
}

AObj* omDObjAddAObj(DObj* dobj, u8 paramID) {
    AObj* aobj = omGetAObj();

    aobj->paramID = paramID;
    aobj->kind = ANIM_TYPE_NONE;
    aobj->unk_20 = NULL;
    aobj->targetRate = 0.0;
    aobj->rate = 0.0;
    aobj->targetValue = 0.0;
    aobj->initialValue = 0.0;
    aobj->time = 0.0;
    aobj->invDuration = 1.0;

    omDObjAttachAObj(dobj, aobj);

    return aobj;
}

void omDObjResetAnimation(DObj* dobj) {
    AObj* curr;
    AObj* origNext;

    curr = dobj->aobjList;
    while (curr != NULL) {
        origNext = curr->next;
        omFreeAObj(curr);
        curr = origNext;
    }
    dobj->aobjList = NULL;
    dobj->timeLeft = ANIMATION_DISABLED;
}

AObj* omMObjAddAObj(MObj* mobj, u8 index) {
    AObj* aobj = omGetAObj();

    aobj->paramID = index;
    aobj->kind = ANIM_TYPE_NONE;
    aobj->unk_20 = NULL;
    aobj->targetRate = 0.0;
    aobj->rate = 0.0;
    aobj->targetValue = 0.0;
    aobj->initialValue = 0.0;
    aobj->time = 0.0;
    aobj->invDuration = 1.0;

    omMObjAttachAObj(mobj, aobj);

    return aobj;
}

void omMObjResetAObjList(MObj* mobj) {
    AObj* curr;
    AObj* origNext;

    curr = mobj->aobjList;
    while (curr != NULL) {
        origNext = curr->next;
        omFreeAObj(curr);
        curr = origNext;
    }
    mobj->aobjList = NULL;
    mobj->timeLeft = ANIMATION_DISABLED;
}

AObj* omCameraAddAObj(OMCamera* obj, u8 index) {
    AObj* aobj = omGetAObj();

    aobj->paramID = index;
    aobj->kind = ANIM_TYPE_NONE;
    aobj->unk_20 = NULL;
    aobj->targetRate = 0.0;
    aobj->rate = 0.0;
    aobj->targetValue = 0.0;
    aobj->initialValue = 0.0;
    aobj->time = 0.0;
    aobj->invDuration = 1.0;

    omCameraAttachAObj(obj, aobj);

    return aobj;
}

void omCameraResetAnimation(OMCamera* cam) {
    AObj* curr;
    AObj* origNext;

    curr = cam->aobjList;
    while (curr != NULL) {
        origNext = curr->next;
        omFreeAObj(curr);
        curr = origNext;
    }
    cam->aobjList = NULL;
    cam->timeLeft = ANIMATION_DISABLED;
}

MObj* omDObjAddMObj(DObj* dobj, Texture* arg1) {
    MObj* mobj;

    mobj = omGetMObj();

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
    mobj->lodLevel = arg1->unk_54 / 255.0f;
    mobj->texture = *arg1;

    mobj->texture.unk_24 = arg1->unk_14;
    mobj->texture.unk_28 = arg1->scaleS;
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

void omDObjRemoveAllMObj(DObj* dobj) {
    MObj* currM;
    MObj* nextM;
    AObj* currA;
    AObj* nextA;

    currM = dobj->mobjList;
    while (currM != NULL) {
        currA = currM->aobjList;
        while (currA != NULL) {
            nextA = currA->next;
            omFreeAObj(currA);
            currA = nextA;
        }
        nextM = currM->next;
        omFreeMObj(currM);
        currM = nextM;
    }
    dobj->mobjList = NULL;
}

void omDObjInit(DObj* dobj) {
    s32 i;

    dobj->unk_4C = NULL;
    dobj->flags = 0;
    dobj->animCBReceiver = false;
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

DObj* omGObjAddDObj(GObj* obj, void* arg1) {
    DObj* newDobj;
    DObj* curr;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    newDobj = omGetDObj();
    if (obj->data.dobj != NULL) {
        curr = obj->data.dobj;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newDobj;
        newDobj->prev = curr;
    } else {
        obj->type = 1;
        obj->data.dobj = newDobj;
        newDobj->prev = NULL;
    }

    newDobj->obj = obj;
    newDobj->parent = (void*) 1;
    newDobj->next = NULL;
    newDobj->firstChild = NULL;
    newDobj->payload.any = arg1;

    omDObjInit(newDobj);

    return newDobj;
}

DObj* omDObjAddSibling(DObj* dobj, void* arg1) {
    DObj* newObj;

    newObj = omGetDObj();
    if (dobj->next != NULL) {
        dobj->next->prev = newObj;
    }
    newObj->prev = dobj;
    newObj->next = dobj->next;
    dobj->next = newObj;
    newObj->obj = dobj->obj;
    newObj->parent = dobj->parent;

    newObj->firstChild = NULL;
    newObj->payload.any = arg1;
    omDObjInit(newObj);

    return newObj;
}

DObj* omDObjAddChild(DObj* arg0, void* arg1) {
    DObj* newObj;
    DObj* curr;

    newObj = omGetDObj();
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
    newObj->payload.any = arg1;

    omDObjInit(newObj);

    return newObj;
}

void omDObjRemove(DObj* dobj) {
    s32 i;
    AObj* currA;
    AObj* nextA;
    MObj* currM;
    MObj* nextM;

    while (dobj->firstChild != NULL) {
        omDObjRemove(dobj->firstChild);
    }

    if ((uintptr_t) dobj->parent == 1) {
        // toplevel
        if (dobj == dobj->obj->data.dobj) {
            dobj->obj->data.dobj = dobj->next;
            if (dobj->obj->data.dobj == NULL) {
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
            omFreeMtx(dobj->matrices[i]);
        }
    }

    if (dobj->unk_4C != NULL && omD_8004AC0C != NULL) {
        omD_8004AC0C(dobj->unk_4C);
    }

    currA = dobj->aobjList;
    while (currA != NULL) {
        nextA = currA->next;
        omFreeAObj(currA);
        currA = nextA;
    }

    currM = dobj->mobjList;
    while (currM != NULL) {
        currA = currM->aobjList;
        while (currA != NULL) {
            nextA = currA->next;
            omFreeAObj(currA);
            currA = nextA;
        }
        nextM = currM->next;
        omFreeMObj(currM);
        currM = nextM;
    }

    omFreeDObj(dobj);
}

SObj* omGObjAddSprite(GObj* obj, Sprite* sprite) {
    SObj* sobj;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    sobj = omGetSObj();

    if (obj->data.sobj != NULL) {
        SObj* curr = obj->data.sobj;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = sobj;
        sobj->prev = curr;
    } else {
        obj->type = 2;
        obj->data.sobj = sobj;
        sobj->prev = NULL;
    }

    sobj->obj = obj;
    sobj->next = NULL;

    if (sprite != NULL) {
        sobj->sprite = *sprite;
    }

    sobj->unk_54 = 0;
    return sobj;
}

void omGObjRemoveSprite(SObj* obj) {
    if (obj == obj->obj->data.sobj) {
        obj->obj->data.sobj = (void*) obj->next;
        if (obj->obj->data.sobj == NULL) {
            obj->obj->type = 0;
        }
    }

    if (obj->prev != NULL) {
        obj->prev->next = obj->next;
    }

    if (obj->next != NULL) {
        obj->next->prev = obj->prev;
    }

    omFreeSObj(obj);
}

OMCamera* omGObjSetCamera(GObj* obj) {
    s32 i;
    OMCamera* camera;

    if (obj == NULL) {
        obj = omCurrentObject;
    }
    obj->type = 3;

    camera = omGetCamera();
    obj->data.cam = camera;
    camera->obj = obj;
    func_80007CBC(&camera->vp);
    if (false) {
    } // required to match
    camera->numMatrices = 0;
    for (i = 0; i < ARRAY_COUNT(camera->matrices); i++) {
        camera->matrices[i] = NULL;
    }
    camera->flags = 0;
    camera->bgColor = 0;
    camera->fnPreRender = NULL;
    camera->unk_8C = 0;
    camera->aobjList = NULL;
    camera->animList = 0;
    camera->timeLeft = ANIMATION_DISABLED;
    camera->animSpeed = 1.0;
    camera->timePassed = 0.0;

    return camera;
}

void omGObjRemoveCamera(OMCamera* cam) {
    GObj* obj;
    s32 i;
    AObj* curr;
    AObj* next;

    obj = cam->obj;
    obj->type = 0;
    obj->data.cam = NULL;

    for (i = 0; i < ARRAY_COUNT(cam->matrices); i++) {
        if (cam->matrices[i] != NULL) {
            omFreeMtx(cam->matrices[i]);
        }
    }

    curr = cam->aobjList;
    while (curr != NULL) {
        next = curr->next;
        omFreeAObj(curr);
        curr = next;
    }

    omFreeCamera(cam);
}

GObj* omAddGObjCommon(u32 id, void (*fnUpdate)(GObj*), u8 link, u32 priority) {
    GObj* obj;

    if (link >= 32) {
        error_printf("omGAddCommon() : link num over : link = %d : id = %d\n", link, id);
        PANIC();
    }

    obj = omGetGObj();
    if (obj == NULL) {
        return NULL;
    }

    obj->id = id;
    obj->link = link;
    obj->priority = priority;
    obj->fnUpdate = fnUpdate;
    obj->processListHead = NULL;
    obj->processListTail = NULL;
    obj->cmdList.count = 0;
    obj->cmdList.head = NULL;
    obj->cmdList.tail = NULL;
    obj->animationTime = 0.0f;
    obj->flags = 0;
    obj->type = 0;
    obj->data.any = NULL;
    obj->dlLink = 33;

    if (false) {
    } // required to match

    obj->fnAnimCallback = NULL;
    obj->userData = NULL;
    return obj;
}

GObj* omAddGObj(u32 id, void (*fnUpdate)(GObj*), u8 link, u32 priority) {
    GObj* com = omAddGObjCommon(id, fnUpdate, link, priority);

    if (com == NULL) {
        return NULL;
    }

    omLinkGObjAfterSamePriority(com);

    return com;
}

GObj* omAddGObjBeforeSamePriority(u32 id, void (*fnUpdate)(GObj*), u8 link, u32 priority) {
    GObj* com = omAddGObjCommon(id, fnUpdate, link, priority);

    if (com == NULL) {
        return NULL;
    }

    omLinkGObjBeforeSamePriority(com);

    return com;
}

GObj* omAddGObjAfter(u32 id, void (*fnUpdate)(GObj*), GObj* arg2) {
    GObj* com = omAddGObjCommon(id, fnUpdate, arg2->link, arg2->priority);

    if (com == NULL) {
        return NULL;
    }

    omLinkGObjAfter(com, arg2);

    return com;
}

GObj* omAddGObjBefore(u32 id, void (*fnUpdate)(GObj*), GObj* arg2) {
    GObj* com = omAddGObjCommon(id, fnUpdate, arg2->link, arg2->priority);

    if (com == NULL) {
        return NULL;
    }

    omLinkGObjAfter(com, arg2->prev);

    return com;
}

void omDeleteGObj(GObj* obj) {
    if (obj == NULL || obj == omCurrentObject) {
        omD_8004AC54 = 2;
        return;
    }

    ohEndAllObjectProcesses(obj);
    cmdFreeObjCmd(&obj->cmdList);
    switch (obj->type) {
        case 1:
            ohRemoveDObj(obj);
            break;
        case 2:
            ohRemoveSprite(obj);
            break;
        case 3:
            omGObjRemoveCamera(obj->data.cam);
            break;
    }

    if (obj->dlLink != 33) {
        omUnlinkGObjDL(obj);
    }
    omUnlinkGObj(obj);
    omFreeGObj(obj);
}

void omMoveGObjCommon(s32 moveType, GObj* obj, u8 link, u32 priority, GObj* refObj) {
    GObjProcess* csr;
    GObjProcess* procList;
    GObjProcess* next;

    if (link >= 32) {
        error_printf("omGMoveCommon() : link num over : link = %d : id = %d\n", link, obj->id);
        PANIC();
    }

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    procList = obj->processListHead;
    obj->processListHead = NULL;
    obj->processListTail = NULL;

    csr = procList;
    while (csr != NULL) {
        omUnlinkProcessFromPriorityList(csr);
        csr = csr->next;
    }
    omUnlinkGObj(obj);
    obj->link = link;
    obj->priority = priority;

    switch (moveType) {
        case 0:
            omLinkGObjAfterSamePriority(obj);
            break;
        case 1:
            omLinkGObjBeforeSamePriority(obj);
            break;
        case 2:
            omLinkGObjAfter(obj, refObj);
            break;
        case 3:
            omLinkGObjAfter(obj, refObj->prev);
            break;
    }

    csr = procList;
    while (csr != NULL) {
        next = csr->next;
        omLinkProcess(csr);
        csr = next;
    }
}

void omMoveGObjAfterSamePriority(GObj* obj, u8 link, u32 priority) {
    omMoveGObjCommon(0, obj, link, priority, NULL);
}

void omMoveGObjBeforeSamePriority(GObj* arg0, u8 link, u32 arg2) {
    omMoveGObjCommon(1, arg0, link, arg2, NULL);
}

void omMoveGObjAfter(GObj* arg0, GObj* arg1) {
    omMoveGObjCommon(2, arg0, arg1->link, arg1->priority, arg1);
}

void omMoveGObjBefore(GObj* arg0, GObj* arg1) {
    omMoveGObjCommon(3, arg0, arg1->link, arg1->priority, arg1);
}

void omLinkGObjDLCommon(GObj* obj, void (*renderFunc)(GObj*), u8 dlLink, s32 dlPriority,
                        s32 cameraTag) {
    if (dlLink >= 32) {
        error_printf("omGLinkObjDLCommon() : dl_link num over : dl_link = %d : id = %d\n", dlLink, obj->id);
        PANIC();
    }

    obj->dlLink = dlLink;
    obj->dlPriority = dlPriority;
    obj->fnRender = renderFunc;
    obj->cameraTag = cameraTag;
    obj->lastDrawFrame = gtlDrawnFrameCounter - 1;
}

void omLinkGObjDL(GObj* obj, void (*arg1)(GObj*), u8 dlLink, u32 dlPriority, s32 cameraTag) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    omLinkGObjDLCommon(obj, arg1, dlLink, dlPriority, cameraTag);
    omInsertGObjDLAfterSamePriority(obj);
}

void omLinkGObjDLBeforeSamePriority(GObj* obj, void (*renderFunc)(GObj*), u8 dlLink, s32 dlPriority,
                                    s32 arg4) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    omLinkGObjDLCommon(obj, renderFunc, dlLink, dlPriority, arg4);
    omInsertGObjDLBeforeSamePriority(obj);
}

void omLinkGObjDLAfter(GObj* obj, void (*renderFunc)(GObj*), s32 arg2, GObj* other) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    omLinkGObjDLCommon(obj, renderFunc, other->dlLink, other->dlPriority, arg2);
    omInsertGObjDL(obj, other);
}

void omLinkGObjDLBefore(GObj* obj, void (*renderFunc)(struct GObj*), s32 arg2, GObj* other) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    omLinkGObjDLCommon(obj, renderFunc, other->dlLink, other->dlPriority, arg2);
    omInsertGObjDL(obj, other->prev);
}

void omLinkGObjDLCameraCommon(GObj* obj, void (*renderFunc)(GObj*), u32 dlPriority, s32 dlLinkBitMask,
                              s32 cameraTag) {
    obj->dlLink = 32;
    obj->dlPriority = dlPriority;
    obj->fnRender = renderFunc;
    obj->dlLinkBitMask = dlLinkBitMask;
    obj->cameraTag = cameraTag;
    obj->unk_38 = 0;
    obj->lastDrawFrame = gtlDrawnFrameCounter - 1;
}

void omLinkGObjDLCamera(GObj* obj, void (*renderFunc)(GObj*), u32 dlPriority, s32 dlLinkBitMask,
                        s32 cameraTag) {
    if (obj == NULL) {
        obj = omCurrentObject;
    }
    omLinkGObjDLCameraCommon(obj, renderFunc, dlPriority, dlLinkBitMask, cameraTag);
    omInsertGObjDLAfterSamePriority(obj);
}

void omLinkGObjDLCameraBeforeSamePriority(GObj* arg0, void (*arg1)(GObj*), u32 arg2, s32 arg3,
                                          s32 arg4) {
    if (arg0 == NULL) {
        arg0 = omCurrentObject;
    }
    omLinkGObjDLCameraCommon(arg0, arg1, arg2, arg3, arg4);
    omInsertGObjDLBeforeSamePriority(arg0);
}

void omLinkGObjDLCameraAfter(GObj* arg0, void (*arg1)(GObj*), s32 arg2, s32 arg3, GObj* arg4) {
    if (arg0 == NULL) {
        arg0 = omCurrentObject;
    }
    omLinkGObjDLCameraCommon(arg0, arg1, arg4->dlPriority, arg2, arg3);
    omInsertGObjDL(arg0, arg4);
}

void omLinkGObjDLCameraBefore(GObj* arg0, void (*arg1)(GObj*), s32 arg2, s32 arg3, GObj* arg4) {
    if (arg0 == NULL) {
        arg0 = omCurrentObject;
    }
    omLinkGObjDLCameraCommon(arg0, arg1, arg4->dlPriority, arg2, arg3);
    omInsertGObjDL(arg0, arg4->prev);
}

void omMoveGObjDL(GObj* arg0, u8 dlLink, u32 dlPriority) {
    if (dlLink >= 32) {
        error_printf("omGMoveObjDL() : dl_link num over : dl_link = %d : id = %d\n", dlLink, arg0->id);
        PANIC();
    }

    omUnlinkGObjDL(arg0);
    arg0->dlLink = dlLink;
    arg0->dlPriority = dlPriority;
    omInsertGObjDLAfterSamePriority(arg0);
}

void omMoveGObjDLHead(GObj* arg0, u8 dlLink, u32 dlPriority) {
    if (dlLink >= 32) {
        error_printf("omGMoveObjDLHead() : dl_link num over : dl_link = %d : id = %d\n", dlLink, arg0->id);
        PANIC();
    }
    omUnlinkGObjDL(arg0);
    arg0->dlLink = dlLink;
    arg0->dlPriority = dlPriority;
    omInsertGObjDLBeforeSamePriority(arg0);
}

void func_8000AC28(GObj* arg0, GObj* arg1) {
    omUnlinkGObjDL(arg0);
    arg0->dlLink = arg1->dlLink;
    arg0->dlPriority = arg1->dlPriority;
    omInsertGObjDL(arg0, arg1);
}

void func_8000AC68(GObj* arg0, GObj* arg1) {
    omUnlinkGObjDL(arg0);
    arg0->dlLink = arg1->dlLink;
    arg0->dlPriority = arg1->dlPriority;
    omInsertGObjDL(arg0, arg1->prevDl);
}

void func_8000ACAC(GObj* arg0, u32 dlPriority) {
    omUnlinkGObjDL(arg0);
    arg0->dlPriority = dlPriority;
    omInsertGObjDLAfterSamePriority(arg0);
}

void func_8000ACE0(GObj* arg0, u32 dlPriority) {
    omUnlinkGObjDL(arg0);
    arg0->dlPriority = dlPriority;
    omInsertGObjDLBeforeSamePriority(arg0);
}

void func_8000AD14(GObj* obj, GObj* other) {
    omUnlinkGObjDL(obj);
    obj->dlPriority = other->dlPriority;
    omInsertGObjDL(obj, other);
}

void func_8000AD4C(GObj* arg0, GObj* arg1) {
    omUnlinkGObjDL(arg0);
    arg0->dlPriority = arg1->dlPriority;
    omInsertGObjDL(arg0, arg1->prev);
}

void omSetMaxObjects(s32 n) {
    omMaxObjects = n;
}

s16 omGetMaxObjects(void) {
    return omMaxObjects;
}

void omDrawAll(void) {
    s32 i;
    GObj* curr;

    omCurrentCamera = NULL;
    omRenderedObject = NULL;

    for (i = 0; i < ARRAY_COUNT(omD_8004AC78); i++) {
        omD_8004AC78[i].unk00 = gtlDrawnFrameCounter - 1;
    }

    curr = omGObjListDlHead[32];
    while (curr != NULL) {
        if (!(curr->flags & GOBJ_FLAG_HIDDEN)) {
            omCurrentCamera = curr;
            curr->fnRender(curr);
        }
        curr = curr->nextDl;
    }
}

GObj* omUpdateGObj(GObj* arg0) {
    GObj* ret;

    omCurrentObject = arg0;
    arg0->fnUpdate(arg0);
    ret = arg0->next;
    omCurrentObject = NULL;

    switch (omD_8004AC54) {
        case 0:
            break;
        case 2:
            omD_8004AC54 = 0;
            omDeleteGObj(arg0);
            break;
        default:
            omD_8004AC54 = 0;
            break;
    }

    return ret;
}

GObjProcess* omRunProcess(GObjProcess* proc) {
    GObjProcess* ret;

    omCurrentObject = proc->object;
    omCurrentProcess = proc;

    switch (proc->kind) {
        case 0: {
            osStartThread(&proc->unk_1C.thread->osThread);
            osRecvMesg(&omProcessWaitQueue, NULL, OS_MESG_BLOCK);
            break;
        }
        case 1: {
            proc->unk_1C.cb(proc->object);
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

            omDeleteGObj(proc->object);
            break;
        case 1:
            omD_8004AC54 = 0;
            omEndProcess(proc);
            break;
        case 0:
            break;
        default:
            omD_8004AC54 = 0;
            break;
    }

    return ret;
}

void omUpdateAll(void) {
    s32 i;
    GObj* obj;
    GObjProcess* proc;

    omD_8004AC54 = 0;
    omCurrentObject = NULL;
    omCurrentProcess = NULL;

    for (i = 0; i < 32; i++) {
        obj = omGObjListHead[i];
        while (obj != NULL) {
            if (!(obj->flags & GOBJ_FLAG_40) && obj->fnUpdate != NULL) {
                obj = omUpdateGObj(obj);
            } else {
                obj = obj->next;
            }
        }
    }

    for (i = ARRAY_COUNT(omGProcessList) - 1; i >= 0; i--) {
        proc = omGProcessList[i];
        while (proc != NULL) {
            if (!proc->paused) {
                proc = omRunProcess(proc);
            } else {
                proc = proc->nextInPriorityList;
            }
        }
    }
}

void omCreateObjects(OMSetup* setup) {
    s32 i;

    omDefaultStackSize = setup->threadStackSize;
    omD_8004A9A0 = setup->unk_14;

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

        for (i = 0; (u32) i < setup->numStacks - 1; i++) {
            csr->next = (void*) ((uintptr_t) csr + omDefaultStackSize + 8); // offsetof(struct ThreadStackNode, stack));
            csr->stackSize = omDefaultStackSize;
            csr = (void*) ((uintptr_t) csr + omDefaultStackSize + 8); // offsetof(struct ThreadStackNode, stack));
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
        GObj* csr;
        omFreeGObjList = csr = setup->commons;

        for (i = 0; i < setup->numObjects - 1; i++) {
            csr->next = (void*) ((uintptr_t) csr + setup->objectSize);
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
            csr->nextFree = (void*) ((uintptr_t) csr + setup->dobjSize);
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
            csr->nextFree = (void*) ((uintptr_t) csr + setup->sobjSize);
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
            csr->nextFree = (void*) ((uintptr_t) csr + setup->cameraSize);
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

    ren_func_80015448();
    osCreateMesgQueue(&omProcessWaitQueue, omProcessWaitMsgs, ARRAY_COUNT(omProcessWaitMsgs));

    omActiveStacks = omActiveThreads = omActiveProcesses = omActiveObjects = omActiveMatrices = omActiveAObj =
        omActiveDObj = omActiveSObj = omActiveCameras = 0;

    omEndProcessHandler = NULL;
    ren_func_80018CD0(0);
    cmdReset();
}
