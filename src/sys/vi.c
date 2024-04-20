#include "PR/ultratypes.h"
#include "PR/gbi.h"
#include "sys/sched.h"
#include "sys/vi.h"

u16* viZBuffer;
s32 viBitDepth;
s32 viScreenWidth;
s32 viScreenHeight;
s32 viFlags;
s32 viSettingsChanged;
void* sFrameBuffers[3];
s16 viEdgeOffsetLeft;
s16 viEdgeOffsetRight;
s16 viEdgeOffsetTop;
s16 viEdgeOffsetBottom;

/**
 * Convert an RBGA32 color value into a packed set of RBGA5551
 * that can be used with gDPSetFillColor
 *
 * Depends on the state of `viBitDepth`
 * @param color RRGGBBAA
 */
u32 func_80007910(u32 color) {
    // GPACK_RGBA5551, but it doesn't seem to match
    // if that macro is used
    u32 packed = ((color >> 16) & 0xF800) | ((color >> 13) & 0x07C0) | ((color >> 10) & 0x003E) | ((color >> 7) & 1);

    return viBitDepth == G_IM_SIZ_32b ? color : (packed << 16) | packed;
}

void viSetFramebuffers(void* fb1, void* fb2, void* fb3) {
    SCTaskFb task;

    task.info.type = SC_TASK_TYPE_FRAMEBUFFERS;
    task.info.priority = 100;
    sFrameBuffers[0] = task.unk24[0] = fb1;
    sFrameBuffers[1] = task.unk24[1] = fb2;
    sFrameBuffers[2] = task.unk24[2] = fb3;

    scExecuteBlocking(&task.info);
}

void viSetFlags(s32 flags) {
    viFlags |= flags;

    // TODO: flags
    if (flags & 0x20) {
        viBitDepth = G_IM_SIZ_32b;
    }
    if (flags & 0x10) {
        viBitDepth = G_IM_SIZ_16b;
    }
    viSettingsChanged = TRUE;
}

void viSetScreenWidth(s32 width) {
    viScreenWidth = width;
    viSettingsChanged = TRUE;
}

void viSetScreenHeight(s32 height) {
    viScreenHeight = height;
    viSettingsChanged = TRUE;
}

void viSetScreenOffsets(s16 left, s16 right, s16 top, s16 bottom) {
    viEdgeOffsetLeft = left;
    viEdgeOffsetRight = right;
    viEdgeOffsetTop = top;
    viEdgeOffsetBottom = bottom;
    viSettingsChanged = TRUE;
}

void viFillVideoTask(SCTaskVi* task) {
    task->width = viScreenWidth;
    task->height = viScreenHeight;
    task->flags = viFlags;
    task->edgeOffsetLeft = viEdgeOffsetLeft;
    task->edgeOffsetRight = viEdgeOffsetRight;
    task->edgeOffsetTop = viEdgeOffsetTop;
    task->edgeOffsetBottom = viEdgeOffsetBottom;
    viFlags = 0;
    viSettingsChanged = FALSE;
}

void viApplySettingsNonblocking(SCTaskVi* task) {
    if (viSettingsChanged) {
        task->info.type = SC_TASK_TYPE_VI;
        task->info.priority = 50;
        task->info.fnCheck = NULL;
        task->info.mq = NULL;
        viFillVideoTask(task);
        osSendMesg(&scTaskQueue, (OSMesg)task, OS_MESG_NOBLOCK);
    }
}

void viSetScreenParams(s32 width, s32 height, u32 flags) {
    SCTaskVi task;

    viFlags = 0;
    viBitDepth = G_IM_SIZ_16b;
    viSetFlags(flags);
    viSetScreenWidth(width);
    viSetScreenHeight(height);
    task.info.type = SC_TASK_TYPE_VI;
    task.info.priority = 100;
    viFillVideoTask(&task);
    scExecuteBlocking(&task.info);
}

void viApplyScreenSettings(ScreenSettings* settings) {
    viSetFramebuffers(settings->fb1, settings->fb2, settings->fb3);
    viZBuffer = settings->zBuffer;
    viSetScreenParams(settings->screenWidth, settings->screenHeight, settings->flags);
}
