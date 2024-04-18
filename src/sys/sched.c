#include "sys/sched.h"
#include "sys/main.h"
#include "macros.h"
#include "types.h"
#include "PR/rcp.h"

typedef struct {
    u8 unk_b80      : 1; // b0 0 80 => unknown game control (arg2 & 0x1) [aa & resamp enabled?]
    u8 serrate      : 1; // b1 0 40 => serrate enabled (bool)
    u8 pixelSize32  : 1; // b2   20 => type_32 enabled
    u8 gamma        : 1; // b3   10 => gamma on
    u8 blackout     : 1; // b4   08 => unknown game control (arg2 & 0x100) [blackout ?]
    u8 unk_b04      : 1; // b5   04 => unknown game control (arg2 & 0x400)
    u8 gammaDither  : 1; // b6   02 => gamma dither on
    u8 ditherFilter : 1; // b7   01 => dither filter
    u8 divot        : 1; // b8 1 80 => divot on
                         // b9 1 40
} ViSettings;

// TODO: use header
void contRumbleInit(s32);
void contRumbleStop(s32);

SCClient* scClientList;
// priority queue, all tasks added from scExecuteBlocking are put into this queue
SCTaskInfo* scMainQueueHead;
SCTaskInfo* scMainQueueTail;

SCTaskGfx* scCurrentGfxTask;
SCTaskAudio* scCurrentAudioTask;
// priority queue, paused gfx tasks are put into this queue
SCTaskGfx* scPausedQueueHead;
SCTaskGfx* scPausedQueueTail;
// fifo
SCTaskGfx* scQueue3Head;
SCTaskGfx* scQueue3Tail;
SCTaskGfx* scCurrentQueue3Task;

OSViMode scViModeCurrent;
OSViMode scViModeNext;
u32 scViSettingsUpdated;
u32 padding;
void* scFrameBuffers[3];
void* scNextFrameBuffer;
void* scUnkFrameBuffer;
u32 scUnknownInt;
void* scCurrentFrameBuffer;
s32 scTimestampSetFb;
s32 scTimestampAudioTaskStarted;
s32 scTimeSpentGfx;
s32 scTimeSpentAudio;
ViSettings scViSettings;
u64 scUnknownU64;
s32 scUnknownInt2;
void* scUnknownVoid;
s32 scUnknownInt3;
OSMesg scMessages[8];
OSMesgQueue scTaskQueue;
s32 scUseCustomSwapBufferFunc;
OSMesgQueue *scCustomSwapBufferQueue;
void (*scPreNMIProc)(void);
s32 scBeforeReset;
void (*scUnknownFunc)(void*);

void func_80000920(void) {
}

void func_80000928(void) {
    while (TRUE) {
        if (scCurrentGfxTask == NULL && scCurrentQueue3Task == NULL && scQueue3Head == NULL) {
            return;
        }
        func_80000920();
    }
}

void scExecuteBlocking(SCTaskInfo* task) {
    OSMesg msgs[1];
    OSMesgQueue mq;

    osCreateMesgQueue(&mq, msgs, ARRAY_COUNT(msgs));
    task->fnCheck  = NULL;
    task->retVal = 1;
    task->mq = &mq;
    osSendMesg(&scTaskQueue, (OSMesg)task, OS_MESG_NOBLOCK);
    // wait until task is done
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}

// add client which receives VRETRACE message
void scAddClient(SCClient* client, OSMesgQueue* mq, OSMesg* msg, u32 count) {
    SCTaskAddClient t;

    osCreateMesgQueue(mq, msg, count);
    client->mq = mq;
    t.info.type = SC_TASK_TYPE_ADD_CLIENT;
    t.info.priority = 100;
    t.client = client;
    scExecuteBlocking(&t.info);
}

// return TRUE if task can be executed now
s32 scCheckGfxTaskDefault(SCTaskGfx* t) {
    s32 idx;
    s32 i;
    void* nextFb;
    void* curFb;
    void* fb;

    if (scNextFrameBuffer != NULL) {
        return TRUE;
    }
    if (scUnkFrameBuffer != NULL) {
        return FALSE;
    }

    nextFb = osViGetNextFramebuffer();
    curFb  = osViGetCurrentFramebuffer();

    // set framebuffer for drawing
    idx = t->fbIdx;
    if (idx != -1) {
        fb = scFrameBuffers[idx];
        if (fb != NULL && curFb != fb && nextFb != fb) {
            scUnkFrameBuffer = scNextFrameBuffer = fb;
            scUnknownInt2 = 0;
            scTimestampSetFb = osGetCount();
            return TRUE;
        }
    }

    // set any available 
    for (i = 0; i < ARRAY_COUNT(scFrameBuffers); i++) {
        fb = scFrameBuffers[i];
        if (fb != NULL && curFb != fb && nextFb != fb) {
            scNextFrameBuffer = fb;
            scUnknownInt2 = 0;
            scTimestampSetFb = osGetCount();
            return TRUE;
        }
    }

    return FALSE;
}

s32 func_80000B84(UNUSED SCTaskInfo* t) {
    SCTaskInfo* cur;

    if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.type == SC_TASK_TYPE_GFX) {
        return 0;
    }

    cur = &scPausedQueueHead->info;
    while (cur != NULL) {
        if (cur->type == SC_TASK_TYPE_GFX) {
            return 0;
        }
        cur = cur->next;
    }

    cur = scMainQueueHead;
    while (cur != NULL) {
        if (cur->type == SC_TASK_TYPE_GFX) {
            return 0;
        }
        cur = cur->next;
    }

    if (scCurrentQueue3Task != NULL && scCurrentQueue3Task->info.type == SC_TASK_TYPE_GFX) {
        return 0;
    }

    cur = &scQueue3Head->info;
    while (cur != NULL) {
        if (cur->type == SC_TASK_TYPE_GFX) {
            return 0;
        }
        cur = cur->next;
    }

    return 1;
}

void scMainQueueAdd(SCTaskInfo* task) {
    SCTaskInfo* cur;

    // find task with priority higher than task
    cur = scMainQueueTail;
    while (cur != NULL && cur->priority < task->priority) {
        cur = cur->prev;
    }

    // insert new task into queue
    task->prev = cur;
    if (cur != NULL) {
        task->next = cur->next;
        cur->next     = task;
    } else {
        task->next = scMainQueueHead;
        scMainQueueHead = task;
    }

    cur = task->next;
    if (cur != NULL) {
        cur->prev = task;
    } else {
        scMainQueueTail = task;
    }
}

void scMainQueueRemove(SCTaskInfo* task) {
    if (task->prev != NULL) {
        task->prev->next = task->next;
    } else {
        scMainQueueHead = task->next;
    }

    if (task->next != NULL) {
        task->next->prev = task->prev;
    } else {
        scMainQueueTail = task->prev;
    }
}

void scPausedQueueAdd(SCTaskGfx* task) {
    SCTaskInfo* cur;

    cur = &scPausedQueueTail->info;
    while (cur != NULL && cur->priority < task->info.priority) {
        cur = cur->prev;
    }

    task->info.prev = cur;
    if (cur != NULL) {
        task->info.next = cur->next;
        cur->next   = &task->info;
    } else {
        task->info.next = &scPausedQueueHead->info;
        scPausedQueueHead       = task;
    }

    cur = task->info.next;
    if (cur != NULL) {
        cur->prev = &task->info;
    } else {
        scPausedQueueTail = task;
    }
}

void scPausedQueueRemove(SCTaskGfx* task) {
    if (task->info.prev != NULL) {
        task->info.prev->next = task->info.next;
    } else {
        scPausedQueueHead = (void *)task->info.next;
    }

    if (task->info.next != NULL) {
        task->info.next->prev = task->info.prev;
    } else {
        scPausedQueueTail = (void *)task->info.prev;
    }
}

void scQueue3Add(SCTaskGfx* task) {
    task->info.next = NULL;
    task->info.prev = &scQueue3Tail->info;
    if (scQueue3Tail != NULL) {
        scQueue3Tail->info.next = &task->info;
    } else {
        scQueue3Head = task;
    }
    scQueue3Tail = task;
}

void scQueue3Remove(SCTaskGfx* task) {
    if (task->info.prev != NULL) {
        task->info.prev->next = task->info.next;
    } else {
        scQueue3Head = (void *)task->info.next;
    }

    if (task->info.next != NULL) {
        task->info.next->prev = task->info.prev;
    } else {
        scQueue3Tail = (void *)task->info.prev;
    }
}

void scSetNewViMode(void) {
    scViModeCurrent = scViModeNext;
    osViSetMode(&scViModeCurrent);
    osViBlack(scViSettings.blackout);
    scViSettingsUpdated = 0;
}

void func_80000F40(u32, u32, s32, s16, s16, s16, s16);
#ifdef NON_MATCHING
void func_80000F40(u32 width, u32 height, s32 flags, s16 edgeOffsetLeft, s16 edgeOffsetRight, s16 edgeOffsetTop, s16 edgeOffsetBottom) {
    u32 phi_a0; // flag collector
    s32 phi_v1;
    s32 phi_t0;
    s32 phi_t2;
    u32 phi_t3;
    u32 sp00;
    s32 sp14;
    s32 sp1C;
    s32 sp20;

    if (width > SCREEN_WIDTH || height > SCREEN_HEIGHT) {
        phi_t2 = 0;
    } else {
        phi_t2 = 1;
    }

    // phi_t2 = arg0 >= SCREEN_WIDTH && arg1 >= SCREEN_HEIGHT ? 0 : 1;

    // L80000F5C
    if (flags & 0x00004) {
        scViSettings.serrate = TRUE;
        scViModeNext.comRegs.ctrl |= VI_CTRL_SERRATE_ON;
    }
    // L80000F8C
    if (flags & 0x00008) {
        scViSettings.serrate = FALSE;
        scViModeNext.comRegs.ctrl &= ~VI_CTRL_SERRATE_ON;
    }
    // L80000FC0
    if (flags & 0x00010) {
        scViSettings.pixelSize32 = FALSE;
        scViModeNext.comRegs.ctrl &= ~(VI_CTRL_TYPE_32 | VI_CTRL_TYPE_16);
        scViModeNext.comRegs.ctrl |= VI_CTRL_TYPE_16;
    }
    // L80000FF4
    if (flags & 0x00020) {
        scViSettings.pixelSize32 = TRUE;
        scViModeNext.comRegs.ctrl &= ~(VI_CTRL_TYPE_32 | VI_CTRL_TYPE_16);
        scViModeNext.comRegs.ctrl |= VI_CTRL_TYPE_32;
    }
    // L80001024
    if (flags & 0x00040) {
        scViSettings.gamma = TRUE;
        scViModeNext.comRegs.ctrl |= VI_CTRL_GAMMA_ON;
    }
    // L80001048
    if (flags & 0x00080) {
        scViSettings.gamma = FALSE;
        scViModeNext.comRegs.ctrl &= ~VI_CTRL_GAMMA_ON;
    }
    // L80001070
    if (flags & 0x01000) {
        scViSettings.gammaDither = TRUE;
        scViModeNext.comRegs.ctrl |= VI_CTRL_GAMMA_DITHER_ON;
    }
    // L80001094
    if (flags & 0x02000) {
        scViSettings.gammaDither = FALSE;
        scViModeNext.comRegs.ctrl &= ~VI_CTRL_GAMMA_DITHER_ON;
    }
    // L800010BC
    if (flags & 0x04000) {
        scViSettings.ditherFilter = TRUE;
        scViModeNext.comRegs.ctrl |= VI_CTRL_DITHER_FILTER_ON;
    }
    // L800010E4
    if (flags & 0x08000) {
        scViSettings.ditherFilter = FALSE;
        scViModeNext.comRegs.ctrl &= ~VI_CTRL_DITHER_FILTER_ON;
    }
    // L80001110
    if (flags & 0x10000) {
        scViSettings.divot = TRUE;
        scViModeNext.comRegs.ctrl |= VI_CTRL_DIVOT_ON;
    }
    // L80001134
    if (flags & 0x20000) {
        scViSettings.divot = FALSE;
        scViModeNext.comRegs.ctrl &= ~VI_CTRL_DIVOT_ON;
    }
    // L8000115C
    if (flags & 0x00100) { scViSettings.blackout = TRUE; }
    // L80001174
    if (flags & 0x00200) { scViSettings.blackout = FALSE; }
    // L80001188
    if (flags & 0x00400) { scViSettings.unk_b04 = TRUE; }
    // L800011A0
    if (flags & 0x00800) { scViSettings.unk_b04 = FALSE; }
    // L800011B4
    if (flags & 0x00001) { scViSettings.unk_b80 = TRUE; }
    // L800011D0
    if (flags & 0x00002) { scViSettings.unk_b80 = FALSE; }

    // L800011E8D_80044F88
    scViModeNext.comRegs.ctrl &= ~VI_CTRL_ANTIALIAS_MASK;

    if (scViSettings.unk_b80) {
        phi_a0 = scViSettings.ditherFilter ? 0x100 : 0;

        // if (viSettings.ditherFilter) {
        //     phi_a0 = 0x100; // aa & resamp (fetch extra lines if needed)
        // } else {
        //     phi_a0 = 0;
        // }

        // L80001220
        scViModeNext.comRegs.ctrl |= phi_a0;
    } else {
        // L80001238
        if (!scViSettings.unk_b04 && scViSettings.pixelSize32 == 1) {
            scViModeNext.comRegs.ctrl = 0x300; // neither (replicate pixels, no interpolate)
        } else {
            // L8000126C
            scViModeNext.comRegs.ctrl = 0x200; // resamp only (treat as all fully covered
        }
    }
    // L8000127C
    phi_t0 = scViSettings.pixelSize32; // tail expression?

    if (phi_t2) {
        if (scViSettings.serrate) {
            phi_v1 = 0;
        } else {
            phi_v1 = 1;
        }
    } else {
        // L800012A0
        if (scViSettings.unk_b04) {
            phi_v1 = 1;
        } else {
            phi_v1 = 0;
        }
    }
    // L800012B0
    // temp_a1 = arg5 & 0xFFFE;
    // temp_a2 = arg6 & 0xFFFE;
    edgeOffsetTop &= ~1; // a1?
    edgeOffsetBottom &= ~1; // a2?
    if (!phi_t2 && !phi_v1) {
        sp14 = 2;
    } else {
        sp14 = 1;
    }
    // L800012EC L800012F0 L800012F4
    if (phi_t2) {
        phi_a0 = 1;
    } else {
        phi_a0 = 2;
    }
    // L80001308
    // t7 = arg6 - arg5
    // t8 = t7 + 480
    // t4 = arg1 << 11
    // t9 = (u32) t4 / t8
    // t7 = sp14
    // t5 = arg0 (sp38)
    // t6 = t9 / phi_a0
    // t3 = t6 * t7
    // L80001348
    phi_t3 = (((height << 11) / ((edgeOffsetBottom - edgeOffsetTop) + 480)) / phi_a0) * (sp14);
    if (!phi_t2 && phi_v1) {
        phi_a0 = 2;
    } else {
        phi_a0 = 1;
    }
    // L80001368
    scViModeNext.comRegs.width = phi_a0 * width;
    // TODO: macros
    switch (osTvType) {
        case OS_TV_NTSC:
            scViModeNext.comRegs.burst     = 0x3E52239;
            scViModeNext.comRegs.vSync     = 0x20C;
            scViModeNext.comRegs.hSync     = 0xC15;
            scViModeNext.comRegs.leap      = 0xC150C15;
            scViModeNext.comRegs.hStart    = 0x6C02EC;
            scViModeNext.fldRegs[0].vStart = 0x2501FFU;
            scViModeNext.fldRegs[0].vBurst = 0xE0204;
            break;
        case OS_TV_MPAL:
            scViModeNext.comRegs.burst     = 0x4651E39;
            scViModeNext.comRegs.vSync     = 0x20C;
            scViModeNext.comRegs.hSync     = 0xC10;
            scViModeNext.comRegs.leap      = 0xC1C0C1C;
            scViModeNext.comRegs.hStart    = 0x6C02EC;
            scViModeNext.fldRegs[0].vStart = 0x2501FFU;
            scViModeNext.fldRegs[0].vBurst = 0xE0204;
            break;
    }
    // L80001424
    sp00                         = scViModeNext.comRegs.hStart;
    scViModeNext.fldRegs[1].vStart = scViModeNext.fldRegs[0].vStart;
    sp20                         = scViModeNext.comRegs.hStart >> 16;
    sp1C                         = scViModeNext.comRegs.hStart & 0xFFFF;

    if (sp20 + edgeOffsetRight < 0) {
        sp20 = 0;
    } else {
        sp20 = sp20 + edgeOffsetRight;
    }
    // L80001458
    if (sp1C + edgeOffsetTop < 0) {
        sp1C = 0;
    } else {
        sp1C = sp1C + edgeOffsetTop;
    }
    // L80001470
    scViModeNext.comRegs.hStart = (sp20 << 16) | sp1C;
    sp00                      = scViModeNext.fldRegs[0].vStart;
    sp20                      = sp00 >> 16;
    sp1C                      = sp00 & 0xFFFF;

    sp20 = sp20 + edgeOffsetTop;
    if (sp20 < 0) { sp20 = 0; }
    // L800014AC
    sp1C = sp1C + edgeOffsetBottom;
    if (sp1C < 0) { sp1C = 0; }
    // L800014C0
    scViModeNext.fldRegs[0].vStart = (sp20 << 16) | sp1C;
    sp00                         = scViModeNext.fldRegs[1].vStart;
    sp20                         = sp00 >> 16;
    sp1C                         = sp00 & 0xFFFF;

    sp20 = sp20 + edgeOffsetTop;
    if (sp20 < 0) { sp20 = 0; }
    // L800014FC
    sp1C = sp1C + edgeOffsetBottom;
    if (sp1C < 0) { sp1C = 0; }
    // L80001510
    scViModeNext.fldRegs[1].vStart = (sp20 << 16) | sp1C;
    scViModeNext.fldRegs[1].vBurst = scViModeNext.fldRegs[0].vBurst;

    if (phi_t2 && phi_v1) {
        scViModeNext.comRegs.vSync += 1;
        if (osTvType == OS_TV_MPAL) { scViModeNext.comRegs.hSync += 0x40001; }
        if (osTvType == OS_TV_MPAL) { scViModeNext.comRegs.leap += 0xFFFCFFFE; }
    } else {
        // L80001580
        scViModeNext.fldRegs[0].vStart += 0xFFFDFFFE;
        if (osTvType == OS_TV_MPAL) { scViModeNext.fldRegs[0].vBurst += 0xFFFCFFFE; }
        if (osTvType == OS_TV_PAL) { scViModeNext.fldRegs[1].vBurst += 0x2FFFE; }
    }
    // L800015C8
    scViModeNext.comRegs.vCurrent  = 0;
    scViModeNext.comRegs.xScale    = (u32)(width << 0xA) / (u32)((edgeOffsetRight - edgeOffsetLeft) + 0x280);
    phi_a0                       = phi_t0 ? 2 : 1;
    scViModeNext.fldRegs[0].origin = (phi_a0 * width * 2);

    sp14 = phi_t0 ? 2 : 1;
    // L8000163C
    phi_a0 = phi_t2 ? 2 : 1;
    // L8000164C
    scViModeNext.fldRegs[0].yScale = phi_t3;
    scViModeNext.fldRegs[1].yScale = phi_t3;
    scViModeNext.fldRegs[1].origin = (phi_a0 * width * 2 * sp14);
    if (scViSettings.unk_b04) {
        if ((height << 11) < 0xB4000U) {
            scViModeNext.fldRegs[0].yScale = phi_t3 + 0x3000000;
            scViModeNext.fldRegs[1].yScale = phi_t3 + 0x1000000;
        } else {
            // L8000169C
            scViModeNext.fldRegs[0].yScale += 0x2000000;
            scViModeNext.fldRegs[1].yScale += 0x2000000;
        }
        // L800016B8
    }
    // L800016BC
    scViModeNext.fldRegs[0].vIntr = 2;
    scViModeNext.fldRegs[1].vIntr = 2;
    scViSettingsUpdated               = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/sched/func_80000F40.s")
#endif

// called when frame is drawn into fb
void scSetNextFrameBuffer(void* fb) {
    if (scViSettingsUpdated) {
        if (!scBeforeReset) {
            scSetNewViMode();
        }
    }

    if (scUseCustomSwapBufferFunc) {
        // don't call osViSwapBuffer
        osSendMesg(scCustomSwapBufferQueue, (OSMesg)1, OS_MESG_NOBLOCK);
        if ((intptr_t)fb == -1) {
            scCurrentFrameBuffer = scNextFrameBuffer;
            scNextFrameBuffer = NULL;
        } else {
            scCurrentFrameBuffer = fb;
        }
    } else {
        if ((intptr_t)fb == -1) {
            osViSwapBuffer(scNextFrameBuffer);
            if (scUnkFrameBuffer == scNextFrameBuffer) { 
                scUnknownInt = 1; 
            }
            scCurrentFrameBuffer = scNextFrameBuffer;
            scNextFrameBuffer = NULL;
        } else {
            osViSwapBuffer((void *)fb);
            scCurrentFrameBuffer = fb;
        }
    }
    scTimeSpentGfx = (u32)((u32)(osGetCount() - scTimestampSetFb) / 2971);
}

void scExecuteGfxTask(SCTaskGfx* task) {
    if (scCurrentGfxTask != NULL) {
        osSpTaskYield();
        scCurrentGfxTask->info.state = SC_TASK_STATE_SUSPENDING;
        scPausedQueueAdd(scCurrentGfxTask);
        task->info.state = SC_TASK_STATE_PRIORITY_PENDING;
    } else {
        osSpTaskStart(&task->task);
        task->info.state = SC_TASK_STATE_RUNNUNG;
    }
    scCurrentGfxTask = task;
}

void scExecuteAudioTask(SCTaskAudio* task) {
    scTimestampAudioTaskStarted = osGetCount();

    if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.state == SC_TASK_STATE_RUNNUNG) {
        osSpTaskYield();
        scCurrentGfxTask->info.state = SC_TASK_STATE_SUSPENDING;
        task->info.state = SC_TASK_STATE_PRIORITY_PENDING;
    } else {
        osSpTaskStart(&task->task);
        task->info.state = SC_TASK_STATE_RUNNUNG;
    }
    scCurrentAudioTask = task;
}

s32 scExecuteTask(SCTaskInfo* task) {
    s32 ret = 0;
    UNUSED s32 pad[4]; // required to match
    SCTaskInfo* sp34[2]; 

    switch (task->type) {
        case SC_TASK_TYPE_GFX:
            {
                SCTaskGfx* t = (void *)task;

                if (t->unk68 != NULL) {
                    *t->unk68 |= (uintptr_t)scNextFrameBuffer;
                    osWritebackDCache(t->unk68, sizeof(s32*));
                }
                if ((uintptr_t)t->task.t.output_buff == (uintptr_t)-1) {
                    t->task.t.output_buff = (u64 *)((uintptr_t)scUnknownVoid + scUnknownInt2);
                    osWritebackDCache(&t->task.t.output_buff, sizeof(u64 *));
                }
                if (t->unk74 == 1) {
                    osInvalDCache(&scUnknownU64, sizeof(scUnknownU64));
                }
                scExecuteGfxTask(t);
                ret = 1;
                break;
            }
        case SC_TASK_TYPE_AUDIO:
            {
                SCTaskAudio* t = (void *)task;

                osWritebackDCacheAll();
                scExecuteAudioTask(t);
                ret = 1;
                break;
            }
        case SC_TASK_TYPE_ADD_CLIENT:
            {
                SCTaskAddClient* t   = (void *)task;
                SCClient* temp;

                temp = t->client;
                temp->next = scClientList;
                scClientList = temp;

                if (t->info.mq != NULL) {
                    osSendMesg(t->info.mq, (OSMesg)t->info.retVal, OS_MESG_NOBLOCK);
                }
                break;
            }
        case SC_TASK_TYPE_VI:
            {
                SCTaskVi* t = (void *)task;

                func_80000F40(t->width, t->height, t->flags, t->edgeOffsetLeft, t->edgeOffsetRight, t->edgeOffsetTop, t->edgeOffsetBottom);

                if (t->info.mq != NULL) {
                    osSendMesg(t->info.mq, (OSMesg)t->info.retVal, OS_MESG_NOBLOCK);
                }
                break;
            }
        case SC_TASK_TYPE_FRAMEBUFFERS:
            {
                SCTaskFb* t = (void *)task;
                s32 i;

                for (i = 0; i < ARRAY_COUNT(scFrameBuffers); i++) {
                    scFrameBuffers[i] = t->unk24[i];
                }

                if (t->info.mq != NULL) {
                    osSendMesg(t->info.mq, (OSMesg)t->info.retVal, OS_MESG_NOBLOCK);
                }
                break;
            }
        case SC_TASK_TYPE_GFX_END:
            {
                SCTaskGfxEnd* t = (void *)task;
                SCTaskGfx* v1   = NULL;
                SCTaskInfo* v0;

                if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.type == SC_TASK_TYPE_GFX
                    && scCurrentGfxTask->taskId == t->taskId) {
                    v1 = scCurrentGfxTask;
                }

                v0 = &scPausedQueueHead->info;
                while (v0 != NULL) {
                    if (v0->type == SC_TASK_TYPE_GFX) {
                        if (((SCTaskGfx *)v0)->taskId == t->taskId) {
                            v1 = (void *)v0;
                        }
                    }
                    v0 = v0->next;
                }

                v0 = scMainQueueHead;
                while (v0 != NULL) {
                    if (v0->type == SC_TASK_TYPE_GFX) {
                        if (((SCTaskGfx *)v0)->taskId == t->taskId) {
                            v1 = (void *)v0;
                        }
                    }

                    v0 = v0->next;
                }

                v0 = &scCurrentQueue3Task->info;
                if (v0 != NULL) {
                    if (v0->type == SC_TASK_TYPE_GFX) {
                        if (scCurrentGfxTask->taskId == t->taskId) {
                            v1 = (void *)v0;
                        }
                    }
                }

                v0 = &scQueue3Head->info;
                while (v0 != NULL) {
                    if (v0->type == SC_TASK_TYPE_GFX) {
                        if (((SCTaskGfx *)v0)->taskId == t->taskId) {
                            v1 = (void *)v0;
                        }
                    }
                    v0 = v0->next;
                }

                if (v1 != NULL) {
                    v1->info.retVal = t->info.retVal;
                    v1->info.mq = t->info.mq;
                    v1->fb = t->fb;
                } else {
                    if (t->fb != NULL) {
                        scSetNextFrameBuffer(t->fb);
                    }

                    if (t->info.mq != NULL) {
                        osSendMesg(t->info.mq, (OSMesg)t->info.retVal, OS_MESG_NOBLOCK);
                    }
                }
                break;
            }
        case SC_TASK_TYPE_NOP:
            if (task->mq != NULL) {
                osSendMesg(task->mq, (OSMesg)task->retVal, OS_MESG_NOBLOCK);
            }
            break;
        case SC_TASK_TYPE_8:
            {
                SCTaskType8* t = (void *)task;

                scUnknownVoid = t->unk24;
                scUnknownInt3 = t->unk28;
                if (t->info.mq != NULL) {
                    osSendMesg(t->info.mq, (OSMesg)t->info.retVal, OS_MESG_NOBLOCK);
                }
                break;
            }
        case SC_TASK_TYPE_9:
            {
                SCTaskType9* t = (void *)task;

                scUseCustomSwapBufferFunc = 1;
                scCustomSwapBufferQueue = t->unk24;
                if (t->info.mq != NULL) {
                    osSendMesg(t->info.mq, (OSMesg)t->info.retVal, OS_MESG_NOBLOCK);
                }
                break;
            }
        case SC_TASK_TYPE_10:
            scUseCustomSwapBufferFunc = 0;
            if (task->mq != NULL) {
                osSendMesg(task->mq, (OSMesg)task->retVal, OS_MESG_NOBLOCK);
            }
            break;
        case SC_TASK_TYPE_11:
            {
                SCTaskInfo *a0 = scMainQueueHead;
                while (a0 != NULL) {
                    if (a0->type == SC_TASK_TYPE_GFX || a0->type == SC_TASK_TYPE_VI) {
                        sp34[0] = a0->next;
                        scMainQueueRemove(a0);
                        a0 = sp34[0];
                    } else {
                        a0 = a0->next;
                    }
                }

                scUnkFrameBuffer = NULL;
                if (task->mq != NULL) {
                    osSendMesg(task->mq, (OSMesg)task->retVal, OS_MESG_NOBLOCK);
                }
                break;
            }
    }
    return ret;
}

void scExecuteTasks(void) {
    s32 selectedTaskPriority;
    s32 priority;
    s32 taskQueueType;
    SCTaskInfo* task;
    SCTaskInfo* nextTask;
    s32 stop = FALSE;
    s32 pausedTaskPriority;
    s32 currentTaskPriority;

    currentTaskPriority = scCurrentGfxTask != NULL ? scCurrentGfxTask->info.priority : -1;

    if (scCurrentAudioTask != NULL) {
        currentTaskPriority = scCurrentAudioTask->info.priority;
    }

    pausedTaskPriority = scPausedQueueHead != NULL ? scPausedQueueHead->info.priority : -1;

    task = scMainQueueHead;
    while (!stop) {
        priority = task != NULL ? task->priority : -1;

        if (pausedTaskPriority >= priority) {
            taskQueueType = 0;
            selectedTaskPriority = pausedTaskPriority;
        } else {
            taskQueueType = 1;
            selectedTaskPriority = priority;
        }

        if (currentTaskPriority >= selectedTaskPriority) {
            stop = TRUE;
        } else {
            switch (taskQueueType) {
                case 0:
                    // execute paused gfx task
                    osSpTaskStart(&scPausedQueueHead->task);
                    stop = TRUE;
                    scPausedQueueHead->info.state = SC_TASK_STATE_RUNNUNG;
                    scCurrentGfxTask = scPausedQueueHead;
                    scPausedQueueRemove(scPausedQueueHead);
                    break;
                case 1:
                    // execute general task
                    if (task->fnCheck == NULL || task->fnCheck(task)) {
                        stop = scExecuteTask(task);
                        nextTask = task->next;
                        scMainQueueRemove(task);
                        task = nextTask;
                    } else {
                        task = task->next;
                    }
                    break;
            }
        }
    }
}

void func_80001F24(void) {
    if (scCurrentQueue3Task == NULL && scQueue3Head != NULL) {
        scCurrentQueue3Task = scQueue3Head;
        scQueue3Remove(scQueue3Head);
        scCurrentQueue3Task->info.state = SC_TASK_STATE_RUNNUNG;
        osDpSetNextBuffer(scCurrentQueue3Task->task.t.output_buff, scCurrentQueue3Task->rdpBufSize);
    }
}

void scHandleVRetrace(void) {
    SCClient* client;
    // temp usages are needed to match
    SCClient* temp;

    client = scClientList;
    while (client != NULL) {
        temp = client;
        osSendMesg(temp->mq, (OSMesg)1, OS_MESG_NOBLOCK);
        client = client->next;

        if (temp->mq) { }
    }

    scExecuteTasks();
}

void scHandleSPTaskDone(void) {
    if (scCurrentAudioTask != NULL && scCurrentAudioTask->info.state == SC_TASK_STATE_RUNNUNG) {
        osSendMesg(scCurrentAudioTask->info.mq, (OSMesg)0, OS_MESG_NOBLOCK);
        scCurrentAudioTask = NULL;
        scExecuteTasks();
        scTimeSpentAudio = (osGetCount() - scTimestampAudioTaskStarted) / 2971;
        return;
    }

    if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.state == SC_TASK_STATE_SUSPENDING) {
        if (osSpTaskYielded(&scCurrentGfxTask->task) == OS_TASK_YIELDED) {
            scCurrentGfxTask->info.state = SC_TASK_STATE_SUSPENDED;
            scPausedQueueAdd(scCurrentGfxTask);
            scCurrentGfxTask = NULL;
        } else {
            scCurrentGfxTask->info.state = SC_TASK_STATE_STOPPED;
        }
        osSpTaskStart(&scCurrentAudioTask->task);
        scCurrentAudioTask->info.state = SC_TASK_STATE_RUNNUNG;
    }

    if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.unk18 == 1 && scCurrentGfxTask->info.state != SC_TASK_STATE_SUSPENDED) {
        if (scCurrentGfxTask->info.type == SC_TASK_TYPE_GFX && scCurrentGfxTask->unk74 == 1) {
            osInvalDCache(&scUnknownU64, sizeof(scUnknownU64));
            scCurrentGfxTask->rdpBufSize = scUnknownU64;
            scUnknownInt2 += (s32)scUnknownU64;
            scUnknownInt2 = OS_DCACHE_ROUNDUP_ADDR(scUnknownInt2);
            if (scUnknownInt2 < scUnknownU64) {
                fatal_printf("rdp_output_buff over !! size = %d\n byte", scUnknownInt2);
                while (TRUE) { }
            }
            
            scCurrentGfxTask->info.state = SC_TASK_STATE_QUEUED;
            scQueue3Add(scCurrentGfxTask);
            func_80001F24();
        }
        scCurrentGfxTask = NULL;
        scExecuteTasks();
        return;
    }
    
    if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.unk18 == 2 && scCurrentGfxTask->info.type == SC_TASK_TYPE_GFX) {
        scCurrentGfxTask->info.state = SC_TASK_STATE_STOPPED;
        if (!(scCurrentGfxTask->unk7C & 2)) {
            scCurrentGfxTask->unk7C |= 1;
        }
    }
}

void scHandleDPFullSync(void) {
    if (scCurrentGfxTask != NULL && scCurrentGfxTask->info.unk18 == 2) {
        if (scCurrentGfxTask->info.type == SC_TASK_TYPE_GFX) {
            if (scCurrentGfxTask->fb != NULL) { 
                if (scUnknownFunc != NULL) {
                    if ((intptr_t)scCurrentGfxTask->fb == -1) {
                        scUnknownFunc(scNextFrameBuffer);
                    } else {
                        scUnknownFunc(scCurrentGfxTask->fb);
                    }
                }
                scSetNextFrameBuffer(scCurrentGfxTask->fb);
            }

            if (scCurrentGfxTask->info.mq != NULL) {
                osSendMesg(scCurrentGfxTask->info.mq, (OSMesg)scCurrentGfxTask->info.retVal, OS_MESG_NOBLOCK);
            }

            if (scCurrentGfxTask->info.state == SC_TASK_STATE_SUSPENDING) {
                osSpTaskStart(&scCurrentAudioTask->task);
                scCurrentAudioTask->info.state = SC_TASK_STATE_RUNNUNG;
            }
        }

        scCurrentGfxTask = NULL;
        scExecuteTasks();
    } else if (scCurrentQueue3Task != NULL) {
        if (scCurrentQueue3Task->fb != NULL) { 
            if (scUnknownFunc != NULL) {
                if ((intptr_t)scCurrentQueue3Task->fb == -1) {
                    scUnknownFunc(scNextFrameBuffer);
                } else {
                    scUnknownFunc(scCurrentQueue3Task->fb);
                }
            }
            scSetNextFrameBuffer(scCurrentQueue3Task->fb);
        }

        if (scCurrentQueue3Task->info.mq != NULL) {
            osSendMesg(scCurrentQueue3Task->info.mq, (OSMesg)scCurrentQueue3Task->info.retVal, OS_MESG_NOBLOCK);
        }

        scCurrentQueue3Task = NULL;
        func_80001F24();
    } else if (scPausedQueueHead != NULL && scPausedQueueHead->info.unk18 == 2) {
        if (scPausedQueueHead->info.type == SC_TASK_TYPE_GFX) {
            if (scPausedQueueHead->fb != NULL) { 
                if (scUnknownFunc != NULL) {
                    if ((intptr_t)scPausedQueueHead->fb == -1) {
                        scUnknownFunc(scNextFrameBuffer);
                    } else {
                        scUnknownFunc(scPausedQueueHead->fb);
                    }
                }
                scSetNextFrameBuffer(scPausedQueueHead->fb);
            }

            if (scPausedQueueHead->info.mq != NULL) {
                osSendMesg(scPausedQueueHead->info.mq, (OSMesg)scPausedQueueHead->info.retVal, OS_MESG_NOBLOCK);
            }

            scPausedQueueRemove(scPausedQueueHead);
        }
        scExecuteTasks();
    }
}

void scAddTask(SCTaskInfo* task) {
    task->state = SC_TASK_STATE_QUEUED;
    scMainQueueAdd(task);
    scExecuteTasks();
}

#define INTR_VRETRACE     1
#define INTR_SP_TASK_DONE 2
#define INTR_DP_FULL_SYNC 3
#define INTR_SOFT_RESET   99

void scPreNMIDefault(void);

void scMain(UNUSED void* arg) {
    OSMesg intrMsg;
    UNUSED u32 pad;
    OSViMode mode;

    scClientList = NULL;
    scMainQueueHead = scMainQueueTail = scCurrentGfxTask = scCurrentAudioTask = scPausedQueueHead = scPausedQueueTail = NULL;
    scCurrentQueue3Task = scQueue3Head = scQueue3Tail = NULL;
    scViSettingsUpdated = 0;
    scCurrentFrameBuffer = scNextFrameBuffer = scUnkFrameBuffer = NULL;
    scUseCustomSwapBufferFunc = 0;
    scPreNMIProc = scPreNMIDefault;
    scBeforeReset = FALSE;

    switch (osTvType) {
        case OS_TV_NTSC:
            mode = osViModeNtscLan1;
            scViModeCurrent = mode;
            scViModeNext = mode;
            break;
        case OS_TV_PAL:
            while (TRUE) { }
            break;
        case OS_TV_MPAL:
            mode = osViModeMpalLan1;
            scViModeCurrent = mode;
            scViModeNext = mode;
            break;
    }

    scViModeCurrent.comRegs.ctrl = VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_DIVOT_ON | VI_CTRL_DITHER_FILTER_ON;
    scViModeNext.comRegs.ctrl = VI_CTRL_TYPE_16 | VI_CTRL_GAMMA_DITHER_ON | VI_CTRL_DIVOT_ON | VI_CTRL_DITHER_FILTER_ON;
    osViSetMode(&scViModeCurrent);
    osViBlack(TRUE);

    scViSettings.unk_b80      = TRUE;
    scViSettings.serrate      = FALSE;
    scViSettings.pixelSize32  = FALSE;
    scViSettings.gamma        = FALSE;
    scViSettings.blackout     = TRUE;
    scViSettings.unk_b04      = FALSE;
    scViSettings.gammaDither  = TRUE;
    scViSettings.ditherFilter = TRUE;
    scViSettings.divot        = TRUE;

    osCreateMesgQueue(&scTaskQueue, scMessages, ARRAY_COUNT(scMessages));
    osViSetEvent(&scTaskQueue, (OSMesg)INTR_VRETRACE, 1);
    osSetEventMesg(OS_EVENT_SP, &scTaskQueue, (OSMesg)INTR_SP_TASK_DONE);
    osSetEventMesg(OS_EVENT_DP, &scTaskQueue, (OSMesg)INTR_DP_FULL_SYNC);
    osSetEventMesg(OS_EVENT_PRENMI, &scTaskQueue, (OSMesg)INTR_SOFT_RESET);

    osSendMesg(&gThreadingQueue, (OSMesg)1, OS_MESG_NOBLOCK);

    while (TRUE) {
        osRecvMesg(&scTaskQueue, &intrMsg, OS_MESG_BLOCK);

        switch ((uintptr_t)intrMsg) {
            case INTR_VRETRACE:
                scHandleVRetrace();
                break;
            case INTR_SP_TASK_DONE:
                scHandleSPTaskDone();
                break;
            case INTR_DP_FULL_SYNC:
                scHandleDPFullSync();
                break;
            case INTR_SOFT_RESET:
                if (scPreNMIProc != NULL) { 
                    scPreNMIProc();
                }
                break;
            default:
                // task added by client
                if (scBeforeReset == FALSE) {
                    scAddTask((SCTaskInfo *)intrMsg);
                }
                break;
        }
    }
}

void scPreNMIDefault(void) {
    s32 i;

    scBeforeReset = TRUE;
    osViSetYScale(1.0);
    osViBlack(TRUE);

    for (i = 0; i < 4; i++) {
        contRumbleInit(i);
        contRumbleStop(i);
    }

}

void scSetPreNMIProc(void (*fn)(void)) {
    scPreNMIProc = fn;
}

void func_800029C8(void (*fn)(void*)) {
    scUnknownFunc = fn;
}

void func_800029D4(void) {
    scUnknownFunc = NULL;
}