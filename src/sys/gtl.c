#include "ultra64.h"
#include "sys/crash.h"
#include "sys/sched.h"
#include "sys/main.h"
#include "sys/cont.h"
#include "sys/om.h"
#include "sys/oh.h"
#include "sys/ml.h"
#include "sys/gtl.h"
#include "sys/vi.h"
#include "sys/rdp_reset.h"
#include "types.h"
#include "macros.h"
#include "ucode.h"

// TODO include
void renSetCustomMatrixHandler(void*);

enum GtlStates {
    GTL_STATE_0 = 0,
    GTL_STATE_1 = 1,
    GTL_STATE_2 = 2
};

enum UcodeTypes {
    UCODE_F3DEX2_FIFO = 0,
    UCODE_F3DEX2_XBUS = 1,
    UCODE_F3DEX2_NON_FIFO = 2,
    UCODE_F3DEX2_NON_XBUS = 3,
    UCODE_F3DEX2_REJ_FIFO = 4,
    UCODE_F3DEX2_REJ_XBUS = 5,
    UCODE_F3DLX2_REJ_FIFO = 6,
    UCODE_F3DLX2_REJ_XBUS = 7,
    UCODE_L3DEX2_FIFO = 8,
    UCODE_L3DEX2_XBUS = 9,
    UCODE_S2DEX2_FIFO = 10,
    UCODE_S2DEX2_XBUS = 11
};

typedef struct {
    /* 0x00 */ long long* text;
    /* 0x04 */ long long* data;
} UcodeInfo; // size = 0x08

typedef struct FnBundle {
    /* 0x00 */ u16 unk00;
    /* 0x04 */ void (*fnPrivUpdate)(void);
    /* 0x08 */ void (*fnUpdate)(struct FnBundle*);
    /* 0x0C */ void (*fnPrivDraw)(void);
    /* 0x10 */ void (*fnDraw)(struct FnBundle*);
} FnBundle; // size == 0x14

// data
s32 gtlD_80040CF0 = 0;
u32 gtlFrameCounter = 0;
s32 gtlDrawnFrameCounter = 0;
UcodeInfo gtlD_80040CFC[] = { { NULL, NULL }, { NULL, NULL }, { gspF3DEX2_NoN_fifoTextStart, gspF3DEX2_NoN_fifoDataStart }, { NULL, NULL }, { NULL, NULL }, { NULL, NULL }, { NULL, NULL }, { NULL, NULL }, { gspL3DEX2_fifoTextStart, gspL3DEX2_fifoDataStart }, { NULL, NULL }, { NULL, NULL } };

// BSS
u8 gtlPadding[16];
OSMesg gtlGameTickQueueMsgs[4];
OSMesgQueue gtlGameTickQueue;
u16 gtlUpdateInterval;
u16 gtlDrawFrameInterval;
s32 gtlD_8004979C;
OSMesg gtlD_800497A0[1];
OSMesgQueue gtlD_800497A8;
SCClient gtlSCClient;
u32* gtlSegmentFBasePtr;
OSMesg gtlD_800497D0[3];
OSMesgQueue gtlD_800497E0;
OSMesg gtlResetQueueMsgs[1];
OSMesgQueue gtlResetQueue;
u64 gtlDramStack[SP_DRAM_STACK_SIZE64 + 1];
u64 gtlYieldData[OS_YIELD_DATA_SIZE / sizeof(u64) + 1];
SCTaskGfx* gtlGfxTasksBufferStart[2];
SCTaskGfx* gtlGfxTasksBufferPtr[2];
SCTaskGfx* gtlGfxTasksBufferEnd[2];
SCTaskGfxEnd* gtlGfxEndTasks[2];
SCTaskVi* gtlVideoSettingsTasks[2];
DLBuffer gtlDLBuffers[2][4];
Gfx* gMainGfxPos[4];
Gfx* gSavedGfxPos[4];
s32 gtlState;
s32 gtlD_8004A8B4;
DynamicBuffer gtlCurrentGfxHeap;
DynamicBuffer sGeneralHeap;
FnBundle gtlCallbackBundle;
s32 gtlTimestamp;
u32 gtlD_8004A8F0;
u32 gtlD_8004A8F4;
void* gtlRPDOutputBuffer;
u32 gtlRPDOutputBufferSize;
s32 gtlNoNearclipping;
u16 gtlD_8004A904;
u16 gtlD_8004A906;
u16 gtlD_8004A908;
Gfx* gtlrdpResetDlist;
s32 gtlContextId;
s32 gtlD_8004A918[2];
s32 gtlNumContexts;
DynamicBuffer gtlGfxHeaps[2];
void (*gtlUpdateInputFunc)(void);
s32 (*gtlD_8004A94C)(SCTaskGfx*);

void func_800053F0(void* arg0) {
    if (arg0 != NULL) {
        gtlD_8004A94C = arg0;
        return;
    } else {
        gtlD_8004A94C = scCheckGfxTaskDefault;
    }
}

void gtlSetSegmentF(Gfx** gfxPtr) {
    gtlSegmentFBasePtr = (u32*) &(*gfxPtr)->dma.addr;
    gSPSegment((*gfxPtr)++, 0x0F, 0x00000000);
}

void gtlDisableNearClipping(s32 arg0) {
    gtlNoNearclipping = arg0;
}

void func_80005454(u16 arg0, u16 arg1) {
    gtlD_8004A904 = arg0;
    gtlD_8004A906 = arg1;
}

void gtlInitHeap(void* arg0, s32 size) {
    mlHeapInit(&sGeneralHeap, 0x10000, arg0, size);
}

void* gtlMalloc(s32 size, s32 alignment) {
    return mlHeapAlloc(&sGeneralHeap, size, alignment);
}

void gtlResetHeap(void) {
    gtlCurrentGfxHeap.id = gtlGfxHeaps[gtlContextId].id;
    gtlCurrentGfxHeap.start = gtlGfxHeaps[gtlContextId].start;
    gtlCurrentGfxHeap.end = gtlGfxHeaps[gtlContextId].end;
    gtlCurrentGfxHeap.ptr = gtlGfxHeaps[gtlContextId].ptr;
    mlHeapClear(&gtlCurrentGfxHeap);
}

void gtlSetDLBuffers(DLBuffer (*buffers)[4]) {
    s32 i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            gtlDLBuffers[i][j] = buffers[i][j];
        }
    }
}

void gtlInitDLists(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gMainGfxPos[i] = gSavedGfxPos[i] = gtlDLBuffers[gtlContextId][i].start;
    }

    for (i = 0; i < 4; i++) {
        if (gtlDLBuffers[gtlContextId][i].length != 0) {
            // load "reset rdp" display list in the beginning and use reference to it every time we reload ucode
            gtlrdpResetDlist = gMainGfxPos[i];
            rdpReset(&gMainGfxPos[i]);
            gSPEndDisplayList(gMainGfxPos[i]++);
            gSavedGfxPos[i] = gMainGfxPos[i];
            break;
        }
    }

    gtlD_8004A908 = false;
}

void gtlCheckBuffers(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (gtlDLBuffers[gtlContextId][i].length + (uintptr_t) gtlDLBuffers[gtlContextId][i].start <
            (uintptr_t) gMainGfxPos[i]) {
            error_printf("gtl : DLBuffer over flow !  kind = %d  vol = %d byte\n", i,
                         (uintptr_t) gMainGfxPos[i] - (uintptr_t) gtlDLBuffers[gtlContextId][i].start);
            PANIC();
        }
    }

    if ((uintptr_t) gtlCurrentGfxHeap.end < (uintptr_t) gtlCurrentGfxHeap.ptr) {
        error_printf("gtl : DynamicBuffer over flow !  %d byte\n",
                     (uintptr_t) gtlCurrentGfxHeap.ptr - (uintptr_t) gtlCurrentGfxHeap.start);
        PANIC();
    }
}

void gtlSetRDPOutput(void* buffer, s32 size) {
    SCTaskRDPBuffer task;

    task.info.type = SC_TASK_TYPE_RDP_BUFFER;
    task.info.priority = 50;
    task.buffer = buffer;
    task.size = size;
    scExecuteBlocking(&task.info);
    if ((s32) &scUnknownU64 & 7) {
        error_printf("bad addr sc_rdp_output_len = %x\n", &scUnknownU64);
        PANIC();
    }
}

void gtlSetRDPOutputSettings(s32 type, void* buffer, u32 size) {
    gtlD_80040CF0 = type;
    gtlRPDOutputBuffer = buffer;
    gtlRPDOutputBufferSize = size;

    if (type == 2 || type == 1) {
        if (size == 0) {
            error_printf("gtl : Buffer size for RDP is zero !!\n");
            PANIC();
        }
    }

    if (type == 1) {
        gtlSetRDPOutput(buffer, size);
    }
}

SCTaskGfx* gtlGetTaskGfx(void) {
    SCTaskGfx* task;

    if (gtlGfxTasksBufferStart[gtlContextId] == NULL) {
        error_printf("gtl : not defined SCTaskGfx\n");
        PANIC();
    }

    if (gtlGfxTasksBufferPtr[gtlContextId] == gtlGfxTasksBufferEnd[gtlContextId]) {
        error_printf("gtl : couldn\'t get SCTaskGfx\n");
        PANIC();
    }
    task = gtlGfxTasksBufferPtr[gtlContextId]++;
    return task;
}

void gtlInitTaskBuffers(SCTaskGfx* gfxTasks, s32 taskBufferSize, SCTaskGfxEnd* gfxEndTasks, SCTaskVi* viTasks) {
    s32 i;
    for (i = 0; i < gtlNumContexts; i++) {
        gtlGfxTasksBufferStart[i] = (SCTaskGfx*) ((uintptr_t) (gfxTasks) + taskBufferSize * sizeof(SCTaskGfx) * i);
        gtlGfxTasksBufferPtr[i] = (SCTaskGfx*) ((uintptr_t) (gfxTasks) + taskBufferSize * sizeof(SCTaskGfx) * i);
        gtlGfxTasksBufferEnd[i] = (SCTaskGfx*) ((uintptr_t) (gfxTasks) + taskBufferSize * sizeof(SCTaskGfx) * (i + 1));
        gtlGfxEndTasks[i] = &gfxEndTasks[i];
        gtlVideoSettingsTasks[i] = &viTasks[i];
    }
}

void gtlScheduleGfxEnd(SCTaskGfxEnd* task, void* fb, s32 arg2, OSMesgQueue* mq) {
    task->info.type = SC_TASK_TYPE_GFX_END;
    task->info.priority = 100;
    task->info.fnCheck = NULL;
    task->info.mq = mq;
    task->info.retVal = arg2;
    task->fb = fb;
    task->taskId = gtlContextId;

    osSendMesg(&scTaskQueue, (OSMesg) task, OS_MESG_NOBLOCK);
}

void gtlCancelCurrentGfxTask(void) {
    s32 retVal;
    SCTaskGfxEnd* task = gtlGfxEndTasks[gtlContextId];

    if (task == NULL) {
        error_printf("gtl : not defined SCTaskGfxEnd\n");
        PANIC();
    }

    retVal = gtlContextId;
    gtlScheduleGfxEnd(task, (void*) -1, retVal, &gtlD_800497E0);
    gtlGfxTasksBufferPtr[gtlContextId] = gtlGfxTasksBufferStart[gtlContextId];
}

void gtlReset(void) {
    OSMesg recv;
    s32 retVal;
    SCTaskGfxEnd* task = gtlGfxEndTasks[gtlContextId];

    if (task == NULL) {
        error_printf("gtl : not defined SCTaskGfxEnd\n");
        PANIC();
    }

    retVal = gtlContextId;
    gtlScheduleGfxEnd(task, NULL, retVal, &gtlResetQueue);
    osRecvMesg(&gtlResetQueue, &recv, OS_MESG_BLOCK);
    gtlGfxTasksBufferPtr[gtlContextId] = gtlGfxTasksBufferStart[gtlContextId];
    gtlResetHeap();
    gtlInitDLists();
}

void gtlScheduleGfx(SCTaskGfx* t, s32* fb, u32 ucodeIdx, s32 contextId, u64* dlist, u64* outputBuff,
                    u32 outputBuffSize) {
    UcodeInfo* ucode;

    t->info.type = SC_TASK_TYPE_GFX;
    t->info.priority = 50;
    if (gtlSegmentFBasePtr != NULL) {
        t->info.fnCheck = (SCTaskCallback) gtlD_8004A94C;
        t->unk68 = gtlSegmentFBasePtr;
        gtlSegmentFBasePtr = NULL;
    } else {
        t->info.fnCheck = NULL;
        t->unk68 = NULL;
    }
    t->fb = fb;
    t->fbIdx = gtlD_8004A8B4;
    if (fb != 0) {
        t->info.mq = &gtlD_800497E0;
        t->info.retVal = contextId;
    } else {
        t->info.mq = NULL;
    }
    t->info.unk_18 = 2;
    t->taskId = gtlContextId;
    t->unk7C = 0;

    t->task.t.type = M_GFXTASK;
    t->task.t.flags = OS_TASK_LOADABLE;
    t->task.t.ucode_boot = gRspBootCode;
    t->task.t.ucode_boot_size = sizeof(gRspBootCode);

    ucode = &gtlD_80040CFC[ucodeIdx];
    if (ucode->text == NULL) {
        error_printf("gtl : ucode isn\'t included  kind = %d\n", ucodeIdx);
        PANIC();
    }
    t->task.t.ucode = (u64*) ucode->text;
    t->task.t.ucode_data = (u64*) ucode->data;
    t->task.t.ucode_size = SP_UCODE_SIZE;
    t->task.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    t->task.t.dram_stack = OS_DCACHE_ROUNDUP_ADDR(&gtlDramStack);
    t->task.t.dram_stack_size = SP_DRAM_STACK_SIZE8;

    switch (ucodeIdx) {
        case UCODE_F3DEX2_FIFO:
        case UCODE_F3DEX2_NON_FIFO:
        case UCODE_F3DEX2_REJ_FIFO:
        case UCODE_F3DLX2_REJ_FIFO:
        case UCODE_L3DEX2_FIFO:
            // FIFO microcodes..?
            t->task.t.output_buff = outputBuff;
            t->task.t.output_buff_size = (u64*) ((uintptr_t) outputBuff + outputBuffSize);
            t->unk74 = 2;
            break;
        case UCODE_F3DEX2_XBUS:
        case UCODE_F3DEX2_NON_XBUS:
        case UCODE_F3DEX2_REJ_XBUS:
        case UCODE_F3DLX2_REJ_XBUS:
        case UCODE_L3DEX2_XBUS:
            t->task.t.output_buff = NULL;
            t->task.t.output_buff_size = NULL;
            t->unk74 = 0;
            break;
    }
    t->task.t.data_ptr = dlist;
    t->task.t.data_size = 0;
    t->task.t.yield_data_ptr = OS_DCACHE_ROUNDUP_ADDR(&gtlYieldData);
    t->task.t.yield_data_size = OS_YIELD_DATA_SIZE;
    osWritebackDCacheAll();
    osSendMesg(&scTaskQueue, (OSMesg) t, OS_MESG_NOBLOCK);
}

u32 gtlGetLineUcode(void) {
    u32 o = gtlD_8004A908 ? gtlD_8004A906 : gtlD_8004A904;

    switch (o) {
        case UCODE_F3DEX2_XBUS:
        case UCODE_F3DEX2_NON_XBUS:
        case UCODE_F3DEX2_REJ_XBUS:
        case UCODE_F3DLX2_REJ_XBUS:
        case UCODE_L3DEX2_XBUS:
            o = UCODE_L3DEX2_XBUS;
            break;
        default:
            o = UCODE_L3DEX2_FIFO;
            break;
    }

    return o;
}

void func_80005D60(s32 arg0, u64* dlist) {
    s32 uidx;

    if (!arg0) {
        uidx = gtlD_8004A904;
        if (gtlNoNearclipping == true) {
            switch (uidx) {
                case UCODE_F3DEX2_FIFO:
                    uidx = UCODE_F3DEX2_NON_FIFO;
                    break;
                case UCODE_F3DEX2_XBUS:
                    uidx = UCODE_F3DEX2_NON_XBUS;
                    break;
            }
        }
    } else {
        uidx = gtlGetLineUcode();
    }

    switch (uidx) {
        case UCODE_F3DEX2_XBUS:
        case UCODE_F3DEX2_NON_XBUS:
        case UCODE_F3DEX2_REJ_XBUS:
        case UCODE_F3DLX2_REJ_XBUS:
        case UCODE_L3DEX2_XBUS:
            gtlScheduleGfx(gtlGetTaskGfx(), 0, uidx, gtlContextId, dlist, NULL, 0);
            break;
        case UCODE_F3DEX2_FIFO:
        case UCODE_F3DEX2_NON_FIFO:
        case UCODE_F3DEX2_REJ_FIFO:
        case UCODE_F3DLX2_REJ_FIFO:
        case UCODE_L3DEX2_FIFO:
            gtlScheduleGfx(gtlGetTaskGfx(), 0, uidx, gtlContextId, dlist, gtlRPDOutputBuffer,
                           gtlRPDOutputBufferSize);
            break;
    }
}

void gtlLoadUcode(Gfx** dlist, u32 ucodeIdx) {
    switch (ucodeIdx) {
        case 0:
        case 1:
        case 2:
            gSPLoadUcodeL((*dlist)++, gspF3DEX2_NoN_fifo);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            gSPLoadUcodeL((*dlist)++, gspL3DEX2_fifo);
            break;
        case 9:
            break;
    }
    gSPDisplayList((*dlist)++, gtlrdpResetDlist);
}

void gtlProcessAllDLists(void) {
    s32 needLineUcode;
    s32 diffs;
    s32 i;
    s32 firstDlIdx;
    Gfx* cmdPtr;

    // calculate bitset of differences
    // bit 1 -> 0
    // 2 -> 1
    // 4 -> 2
    // 8 -> 3
    diffs = 0;
    for (i = 0; i < 4; i++) {
        diffs >>= 1;
        if (gMainGfxPos[i] != gSavedGfxPos[i]) {
            diffs |= 8;
        }
    }

    // combine 4 display lists into one
    // order: 0 -> 2 -> 1 -> 3
    // load line ucode before 2 and 3
    if (diffs != 0) {
        if (diffs & 1) {
            if (diffs & 4) {
                // 0 -> 2
                gtlLoadUcode(&gMainGfxPos[0], gtlGetLineUcode());
                gSPBranchList(gMainGfxPos[0]++, gSavedGfxPos[2]);
            } else if (diffs & 2) {
                // 0 -> 1
                if (gtlD_8004A908) {
                    gtlLoadUcode(&gMainGfxPos[0], gtlD_8004A904);
                }
                gSPBranchList(gMainGfxPos[0]++, gSavedGfxPos[1]);
            } else if (diffs & 8) {
                // 0 -> 3
                gtlLoadUcode(&gMainGfxPos[0], gtlGetLineUcode());
                gSPBranchList(gMainGfxPos[0]++, gSavedGfxPos[3]);
            } else {
                // 0
                gDPFullSync(gMainGfxPos[0]++);
                gSPEndDisplayList(gMainGfxPos[0]++);
            }
        }
        if (diffs & 4) {
            if (diffs & 2) {
                // 2 -> 1
                gtlLoadUcode(&gMainGfxPos[2], gtlD_8004A904);
                gSPBranchList(gMainGfxPos[2]++, gSavedGfxPos[1]);
            } else if (diffs & 8) {
                // 2 -> 3
                gSPBranchList(gMainGfxPos[2]++, gSavedGfxPos[3]);
            } else {
                // 2
                gDPFullSync(gMainGfxPos[2]++);
                gSPEndDisplayList(gMainGfxPos[2]++);
            }
        }
        if (diffs & 2) {
            if (diffs & 8) {
                // 1 -> 3
                gtlLoadUcode(&gMainGfxPos[0], gtlGetLineUcode());
                gSPBranchList(gMainGfxPos[1]++, gSavedGfxPos[3]);
            } else {
                // 1
                gDPFullSync(gMainGfxPos[1]++);
                gSPEndDisplayList(gMainGfxPos[1]++);
            }
        }
        if (diffs & 8) {
            // 3
            gDPFullSync(gMainGfxPos[3]++);
            gSPEndDisplayList(gMainGfxPos[3]++);
        }

        if (diffs & 1) {
            firstDlIdx = 0;
            needLineUcode = false;
        } else if (diffs & 4) {
            firstDlIdx = 2;
            needLineUcode = true;
        } else if (diffs & 2) {
            firstDlIdx = 1;
            needLineUcode = false;
        } else {
            firstDlIdx = 3;
            needLineUcode = true;
        }

        cmdPtr = gMainGfxPos[firstDlIdx];
        // after end ??
        gSPDisplayList(gMainGfxPos[firstDlIdx]++, gtlrdpResetDlist);
        gSPBranchList(gMainGfxPos[firstDlIdx]++, gSavedGfxPos[firstDlIdx]);
        func_80005D60(needLineUcode, (u64*) cmdPtr);

        gSavedGfxPos[0] = gMainGfxPos[0];
        gSavedGfxPos[2] = gMainGfxPos[2];
        gSavedGfxPos[1] = gMainGfxPos[1];
        gSavedGfxPos[3] = gMainGfxPos[3];
    }

    gtlCheckBuffers();
}

void gtlCombineAllDLists(void) {
    s32 i;
    s32 diffs;

    gtlCheckBuffers();
    diffs = 0;
    for (i = 0; i < 4; i++) {
        diffs >>= 1;
        if (gMainGfxPos[i] != gSavedGfxPos[i]) {
            diffs |= 8;
        }
    }

    if (diffs != 0) {
        if (diffs & 1) {
            if (diffs & 4) {
                gtlLoadUcode(&gMainGfxPos[0], gtlGetLineUcode());
                gSPBranchList(gMainGfxPos[0]++, gSavedGfxPos[2]);
            } else if (diffs & 2) {
                if (gtlD_8004A908) {
                    gtlLoadUcode(&gMainGfxPos[0], gtlD_8004A904);
                }
                gSPBranchList(gMainGfxPos[0]++, gSavedGfxPos[1]);
            } else if (diffs & 8) {
                gtlLoadUcode(&gMainGfxPos[0], gtlGetLineUcode());
                gSPBranchList(gMainGfxPos[0]++, gSavedGfxPos[3]);
            }
        }

        if (diffs & 4) {
            if (diffs & 2) {
                gtlLoadUcode(&gMainGfxPos[2], gtlD_8004A904);
                gSPBranchList(gMainGfxPos[2]++, gSavedGfxPos[1]);
            } else if (diffs & 8) {
                gSPBranchList(gMainGfxPos[2]++, gSavedGfxPos[3]);
            } else {
                gtlLoadUcode(&gMainGfxPos[2], gtlD_8004A904);
                gSPBranchList(gMainGfxPos[2]++, gMainGfxPos[0]);
            }
            gSavedGfxPos[2] = gMainGfxPos[2];
        }

        if (diffs & 2) {
            if (diffs & 8) {
                gtlLoadUcode(&gMainGfxPos[0], gtlGetLineUcode());
                gSPBranchList(gMainGfxPos[1]++, gSavedGfxPos[3]);
            } else {
                if (gtlD_8004A908) {
                    gtlLoadUcode(&gMainGfxPos[1], gtlD_8004A904);
                }
                gSPBranchList(gMainGfxPos[1]++, gMainGfxPos[0]);
            }
            gSavedGfxPos[1] = gMainGfxPos[1];
        }

        if (diffs & 8) {
            gtlLoadUcode(&gMainGfxPos[3], gtlD_8004A904);
            gSPBranchList(gMainGfxPos[3]++, gMainGfxPos[0]);
            gSavedGfxPos[3] = gMainGfxPos[3];
        }
    }

    gtlD_8004A908 = false;
    gtlCheckBuffers();
}

u32 gtlSwitchContext(s32 arg0) {
    s32 msg;
    s32 i;

    while (osRecvMesg(&gtlD_800497E0, (OSMesg*) &msg, OS_MESG_NOBLOCK) != -1) {
        gtlD_8004A918[msg] = 0;
    }

    do {
        for (i = 0; i < gtlNumContexts; i++) {
            if (gtlD_8004A918[i] == 0) {
                gtlContextId = i;
                gtlD_8004A918[i] = 1;
                return 1;
            }
        }
        if (!arg0) {
            osRecvMesg(&gtlD_800497E0, (OSMesg*) &msg, OS_MESG_BLOCK);
            gtlD_8004A918[msg] = 0;
        }
    } while (!arg0);

    return 0;
}

void gtlWaitAllGfxTasksDone(void) {
    struct SCTaskInfo task;
    OSMesg msgs[1];
    OSMesgQueue mq;

    task.type = SC_TASK_TYPE_NOP;
    task.priority = 50;
    osCreateMesgQueue(&mq, msgs, ARRAY_COUNT(msgs));
    task.fnCheck = func_80000B84;
    task.retVal = 1;
    task.mq = &mq;

    osSendMesg(&scTaskQueue, (OSMesg) &task, OS_MESG_NOBLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}

void func_800067DC(void) {
    gtlState = GTL_STATE_1;
}

void func_800067EC(s32 arg0) {
    gtlState = GTL_STATE_2;
    gtlD_8004A8B4 = arg0;
}

s32 gtlCheckExitMainLoop(void) {
    SCTaskInfo task;

    switch (gtlState) {
        case GTL_STATE_1:
            return 1;
        case GTL_STATE_2:
            if (scUnknownInt != 0) {
                task.type = SC_TASK_TYPE_11;
                task.priority = 100;
                scExecuteBlocking(&task);
                return 1;
            } else {
                return 0;
            }
        default:
            return 0;
    }
}

void func_80006878(void) {
    if (gtlD_8004979C == 1) {
        gtlD_8004979C = 2;
        while (osRecvMesg(&gtlD_800497A8, NULL, OS_MESG_NOBLOCK) != -1) {
        }

        osRecvMesg(&gtlD_800497A8, NULL, OS_MESG_BLOCK);
        gtlD_8004979C = 0;
    }
}

void gtlMain(FnBundle* arg0) {
    s32 i;

    gtlD_8004979C = 0;

    while (osRecvMesg(&gtlD_800497E0, NULL, OS_MESG_NOBLOCK) != -1) {
    }
    while (osRecvMesg(&gtlResetQueue, NULL, OS_MESG_NOBLOCK) != -1) {
    }
    while (osRecvMesg(&gtlGameTickQueue, NULL, OS_MESG_NOBLOCK) != -1) {
    }

    gtlState = GTL_STATE_0;
    gtlD_8004A8B4 = -1;
    gtlContextId = 1;
    scUnknownInt = 0;

    for (i = 0; i < ARRAY_COUNT(gtlD_8004A918); i++) {
        gtlD_8004A918[i] = 0;
    }

    if (arg0->unk00 & 1) {
        while (true) {
            func_80006878();
            check_stack_probes();
            for (i = 0; i < gtlUpdateInterval; i++) {
                osRecvMesg(&gtlGameTickQueue, NULL, OS_MESG_BLOCK);
            }
            while (osRecvMesg(&gtlGameTickQueue, NULL, OS_MESG_NOBLOCK) != -1) {
            }

            gtlTimestamp = osGetCount();
            arg0->fnUpdate(arg0);
            gtlFrameCounter += 1;
            gtlD_8004A8F0 = (osGetCount() - gtlTimestamp) / 2971;
            if (gtlCheckExitMainLoop()) {
                break;
            }

            if (gtlFrameCounter % gtlDrawFrameInterval == 0) {
                gtlSwitchContext(0);
                gtlTimestamp = osGetCount();
                arg0->fnDraw(arg0);
                gtlDrawnFrameCounter += 1;
                gtlD_8004A8F4 = (osGetCount() - gtlTimestamp) / 2971;

                if (gtlCheckExitMainLoop()) {
                    break;
                }
            }
        }
    } else {
        while (true) {
            func_80006878();
            check_stack_probes();
            for (i = 0; i < gtlUpdateInterval; i++) {
                osRecvMesg(&gtlGameTickQueue, NULL, OS_MESG_BLOCK);
            }
            while (osRecvMesg(&gtlGameTickQueue, NULL, OS_MESG_NOBLOCK) != -1) {
            }

            gtlTimestamp = osGetCount();
            arg0->fnUpdate(arg0);
            gtlFrameCounter += 1;
            gtlD_8004A8F0 = (osGetCount() - gtlTimestamp) / 2971;
            if (gtlCheckExitMainLoop()) {
                break;
            }

            if (gtlFrameCounter % gtlDrawFrameInterval == 0 && gtlSwitchContext(1)) {
                gtlTimestamp = osGetCount();
                arg0->fnDraw(arg0);
                gtlDrawnFrameCounter += 1;
                gtlD_8004A8F4 = (osGetCount() - gtlTimestamp) / 2971;
                if (gtlCheckExitMainLoop()) {
                    break;
                }
            }
        }
    }

    gtlWaitAllGfxTasksDone();
    while (osRecvMesg(&gtlD_800497E0, NULL, OS_MESG_NOBLOCK) != -1) {
    }
    while (osRecvMesg(&gtlResetQueue, NULL, OS_MESG_NOBLOCK) != -1) {
    }
    while (osRecvMesg(&gtlGameTickQueue, NULL, OS_MESG_NOBLOCK) != -1) {
    }
    rdpSetPreRenderFunc(NULL);
    scRemovePostProcessFunc();
    gtlD_8004979C = 2;
}

void func_80006E24(FnBundle* arg0) {
    gtlUpdateInputFunc();
    arg0->fnPrivUpdate();
}

void func_80006E5C(FnBundle* self) {
    gtlResetHeap();
    gtlInitDLists();
    self->fnPrivDraw();
    gtlProcessAllDLists();
    viApplySettingsNonblocking(gtlVideoSettingsTasks[gtlContextId]);
    gtlCancelCurrentGfxTask();
}

void gtlUpdate(FnBundle* self) {
    gtlUpdateInputFunc();
    self->fnPrivUpdate();
    if (gtlCheckExitMainLoop()) {
        ohDeleteAllObjects();
    }
}

void gtlDraw(FnBundle* self) {
    gtlResetHeap();
    gtlInitDLists();
    self->fnPrivDraw();
    gtlProcessAllDLists();
    viApplySettingsNonblocking(gtlVideoSettingsTasks[gtlContextId]);
    gtlCancelCurrentGfxTask();
    if (gtlCheckExitMainLoop()) {
        ohDeleteAllObjects();
    }
}

void func_80006F8C(GObj* arg0) {
    s32 idx;
    s32 tmp;
    SCTaskGfxEnd* task;

    gtlSwitchContext(0);
    gtlResetHeap();
    gtlInitDLists();
    arg0->fnRender(arg0);
    gtlProcessAllDLists();
    task = gtlGfxEndTasks[gtlContextId];
    if (task == NULL) {
        error_printf("gtl : not defined SCTaskGfxEnd\n");
        PANIC();
    }
    tmp = gtlContextId;
    gtlScheduleGfxEnd(task, NULL, tmp, &gtlD_800497E0);
    gtlGfxTasksBufferPtr[gtlContextId] = gtlGfxTasksBufferStart[gtlContextId];
    do {
        osRecvMesg(&gtlD_800497E0, (OSMesg*) &idx, OS_MESG_BLOCK);
        gtlD_8004A918[idx] = 0;
    } while (gtlD_8004A918[gtlContextId] != 0);

    gtlDrawnFrameCounter += 1;
}

void gtlStart(BufferSetup* setup, void (*postInitFunc)(void)) {
    s32 i;
    DLBuffer dlBuffers[2][4];
    s32 tmp;

    gtlNumContexts = setup->numContexts;
    gtlCallbackBundle.unk00 = setup->unk00;
    gtlCallbackBundle.fnPrivUpdate = setup->fnUpdate;
    gtlCallbackBundle.fnPrivDraw = setup->fnDraw;

    gtlInitTaskBuffers(gtlMalloc(setup->unk_14 * sizeof(SCTaskGfx) * gtlNumContexts, 8), setup->unk_14,
                       gtlMalloc(sizeof(SCTaskGfxEnd) * gtlNumContexts, 8),
                       gtlMalloc(sizeof(SCTaskVi) * gtlNumContexts, 8));

    for (i = 0; i < gtlNumContexts; i++) {
        dlBuffers[i][0].start = gtlMalloc(setup->dlBufferSize0, 8);
        dlBuffers[i][0].length = setup->dlBufferSize0;
        dlBuffers[i][1].start = gtlMalloc(setup->dlBufferSize1, 8);
        dlBuffers[i][1].length = setup->dlBufferSize1;
        dlBuffers[i][2].start = gtlMalloc(setup->dlBufferSize2, 8);
        dlBuffers[i][2].length = setup->dlBufferSize2;
        dlBuffers[i][3].start = gtlMalloc(setup->dlBufferSize3, 8);
        dlBuffers[i][3].length = setup->dlBufferSize3;
    }
    gtlSetDLBuffers(dlBuffers);

    for (i = 0; i < gtlNumContexts; i++) {
        mlHeapInit(&gtlCurrentGfxHeap, 0x10002, gtlMalloc(setup->gfxHeapSize, 8), setup->gfxHeapSize);
        gtlGfxHeaps[i].id = gtlCurrentGfxHeap.id;
        gtlGfxHeaps[i].start = gtlCurrentGfxHeap.start;
        gtlGfxHeaps[i].end = gtlCurrentGfxHeap.end;
        gtlGfxHeaps[i].ptr = gtlCurrentGfxHeap.ptr;
    }

    setup->unk30 = 2;
    if (setup->rdpOutputBufferSize == 0) {
        setup->rdpOutputBufferSize = 0x1000;
    }

    tmp = setup->rdpOutputBufferSize;
    gtlSetRDPOutputSettings(setup->unk30, gtlMalloc(tmp, 16), setup->rdpOutputBufferSize);
    rdpSetPreRenderFunc(setup->fnPreRender);
    gtlUpdateInputFunc = setup->fnUpdateInput;
    contSetUpdateEveryTick((uintptr_t) contReadAndUpdate != (uintptr_t) gtlUpdateInputFunc ? true : false);

    gtlFrameCounter = gtlDrawnFrameCounter = 0;
    if (postInitFunc != NULL) {
        postInitFunc();
    }

    gtlMain(&gtlCallbackBundle);
}

void func_80007354(BufferSetup* arg) {
    gtlInitHeap(arg->heapBase, arg->heapSize);
    gtlCallbackBundle.fnUpdate = func_80006E24;
    gtlCallbackBundle.fnDraw = func_80006E5C;
    gtlStart(arg, NULL);
}

void omSetupScene(SceneSetup* arg) {
    OMSetup omSetup;

    gtlInitHeap(arg->gtlSetup.heapBase, arg->gtlSetup.heapSize);

    omSetup.threads = gtlMalloc(sizeof(GObjThread) * arg->numOMThreads, 8);
    omSetup.numThreads = arg->numOMThreads;
    omSetup.threadStackSize = arg->omThreadStackSize;
    if (arg->omThreadStackSize != 0) {
        omSetup.stacks =
            gtlMalloc((arg->omThreadStackSize + 0x8 /*offsetof(ThreadStackNode, stack)*/) * arg->numOMStacks, 8);
    } else {
        omSetup.stacks = NULL;
    }

    omSetup.numStacks = arg->numOMStacks;
    omSetup.unk_14 = arg->unk4C;

    omSetup.processes = gtlMalloc(sizeof(GObjProcess) * arg->numOMProcesses, 4);
    omSetup.numProcesses = arg->numOMProcesses;

    omSetup.commons = gtlMalloc(arg->objectSize * arg->numOMGobjs, 8);
    omSetup.numObjects = arg->numOMGobjs;
    omSetup.objectSize = arg->objectSize;

    omSetup.matrices = gtlMalloc(sizeof(OMMtx) * arg->numOMMtx, 8);
    omSetup.numMatrices = arg->numOMMtx;

    renSetCustomMatrixHandler(arg->unk60);
    omSetup.cleanupFn = arg->unk64;

    omSetup.aobjs = gtlMalloc(sizeof(AObj) * arg->numOMAobjs, 4);
    omSetup.numAObjs = arg->numOMAobjs;

    omSetup.mobjs = gtlMalloc(sizeof(MObj) * arg->numOMMobjs, 4);
    omSetup.numMObjs = arg->numOMMobjs;

    omSetup.dobjs = gtlMalloc(arg->omDobjSize * arg->numOMDobjs, 8);
    omSetup.numDObjs = arg->numOMDobjs;
    omSetup.dobjSize = arg->omDobjSize;

    omSetup.sobjs = gtlMalloc(arg->omSobjSize * arg->numOMSobjs, 8);
    omSetup.numSObjs = arg->numOMSobjs;
    omSetup.sobjSize = arg->omSobjSize;

    omSetup.cameras = gtlMalloc(arg->omCameraSize * arg->numOMCameras, 8);
    omSetup.numCameras = arg->numOMCameras;
    omSetup.cameraSize = arg->omCameraSize;

    omCreateObjects(&omSetup);
    gtlCallbackBundle.fnUpdate = gtlUpdate;
    gtlCallbackBundle.fnDraw = gtlDraw;
    gtlStart(&arg->gtlSetup, arg->postInitFunc);
}

void gtlSetIntervals(u16 updateInterval, u16 drawInterval) {
    gtlUpdateInterval = updateInterval;
    gtlDrawFrameInterval = drawInterval;
}

void func_80007618(void) {
    if (gtlD_8004979C != 2) {
        gtlD_8004979C = 1;
    }
}

s32 func_80007640(void) {
    if (gtlD_8004979C == 2) {
        return 1;
    } else {
        return 0;
    }
}

void func_80007668(void) {
    osSendMesg(&gtlD_800497A8, NULL, OS_MESG_NOBLOCK);
}

void func_80007694(s32 arg0) {
    if (arg0 == 1 || arg0 == 2) {
        gtlContextId = arg0;
    }
}

s32 func_800076B4(s32 arg0) {
    if (arg0 == 1 || arg0 == 2) {
        if (gtlD_8004A918[arg0 - 1] == 0) {
            return 1;
        }
    }

    return 0;
}

void gtlInit(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        gtlGfxTasksBufferEnd[i] = NULL;
        gtlGfxTasksBufferPtr[i] = NULL;
        gtlGfxTasksBufferStart[i] = NULL;
        gtlGfxEndTasks[i] = NULL;
    }

    gtlNoNearclipping = 0;
    gtlD_8004A904 = gtlD_8004A906 = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            gtlDLBuffers[i][j].start = NULL;
            gtlDLBuffers[i][j].length = 0;
        }
    }

    gtlSegmentFBasePtr = NULL;
    func_800053F0(NULL);

    scAddClient(&gtlSCClient, &gtlGameTickQueue, gtlGameTickQueueMsgs, ARRAY_COUNT(gtlGameTickQueueMsgs));
    osCreateMesgQueue(&gtlD_800497E0, gtlD_800497D0, ARRAY_COUNT(gtlD_800497D0));
    osCreateMesgQueue(&gtlResetQueue, gtlResetQueueMsgs, ARRAY_COUNT(gtlResetQueueMsgs));
    gtlUpdateInterval = gtlDrawFrameInterval = 1;
    osCreateMesgQueue(&gtlD_800497A8, gtlD_800497A0, ARRAY_COUNT(gtlD_800497A0));
    gtlD_8004979C = 2;
}
