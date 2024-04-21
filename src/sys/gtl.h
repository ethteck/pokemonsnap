#ifndef SYS_GTL_H
#define SYS_GTL_H

#include <PR/ultratypes.h>
#include <PR/mbi.h>
#include "sys/ml.h"

typedef struct {
    /* 0x00 */ Gfx* start;
    /* 0x04 */ s32 length;
} DLBuffer; // size = 0x08

struct OMCamera;

typedef struct Struct_8004B038 {
    /* 0x00 */ s32 (*unk_00)(Mtx*, void*, Gfx**);
    /* 0x04 */ s32 (*unk_04)(Mtx*, void*, Gfx**);
} Struct_8004B038; // size = 0x08

typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x04 */ void (*fnUpdate)(void);
    /* 0x08 */ void (*fnDraw)(void);
    /* 0x0C */ void* heapBase;
    /* 0x10 */ u32 heapSize;
    /* 0x14 */ u32 unk14; // count?
    /* 0x18 */ s32 numContexts;
    /* 0x1C */ u32 dlBufferSize0;
    /* 0x20 */ u32 dlBufferSize1;
    /* 0x24 */ u32 dlBufferSize2;
    /* 0x28 */ u32 dlBufferSize3;
    /* 0x2C */ u32 gfxHeapSize;
    /* 0x30 */ u16 unk30;
    /* 0x34 */ s32 rdpOutputBufferSize;
    /* 0x38 */ void (*fnPreRender)(Gfx**);
    /* 0x3C */ void (*fnUpdateInput)(void); // controller read callback?
} BufferSetup;                              // size == 0x40

typedef struct {
    /* 0x00 */ BufferSetup gtlSetup;
    /* 0x40 */ u32 numOMThreads;
    /* 0x44 */ u32 omThreadStackSize;
    /* 0x48 */ u32 numOMStacks;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ u32 numOMProcesses;
    /* 0x54 */ u32 numOMGobjs;
    /* 0x58 */ u32 objectSize;
    /* 0x5C */ u32 numOMMtx;
    /* 0x60 */ Struct_8004B038* unk60;
    /* 0x64 */ void* unk64; // fn pointer void(*)(struct DObjDynamicStore *)
    /* 0x68 */ u32 numOMAobjs;
    /* 0x6C */ u32 numOMMobjs;
    /* 0x70 */ u32 numOMDobjs;
    /* 0x74 */ u32 omDobjSize;
    /* 0x78 */ u32 numOMSobjs;
    /* 0x7C */ u32 omSobjSize;
    /* 0x80 */ u32 numOMCameras;
    /* 0x84 */ u32 omCameraSize;
    /* 0x88 */ void (*postInitFunc)(void);
} SceneSetup; // size >= 0x8C

void* gtlMalloc(s32 size, s32 alignment);
void gtlProcessAllDLists(void);
void gtlCombineAllDLists(void);
void gtlReset(void);
void gtlLoadUcode(Gfx** dlist, u32 ucodeIdx);
void omSetupScene(SceneSetup* arg);
void gtlSetSegmentF(Gfx**);
void gtlInit(void);

extern s32 gtlDrawnFrameCounter;
extern Gfx* gMainGfxPos[4];
extern Gfx* gSavedGfxPos[4];
extern s32 gtlContextId;
extern DLBuffer gtlDLBuffers[2][4];
extern DynamicBuffer gtlCurrentGfxHeap;
extern u16 gtlD_8004A906;
extern u16 gtlD_8004A908;

#endif /* SYS_GTL_H */
