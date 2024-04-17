#include "sys/crash.h"
#include "sys/dma.h"

#include "macros.h"

#include <PR/R4300.h>
#include <PR/os.h>
#include <PR/rcp.h>
#include <PR/ultratypes.h>
#include "os_internal_reg.h"

#include "ld_addrs.h"

// TODO: includes
void scMain(void *arg);
void thread4_audio(void *arg);
void contMain(void *arg);
void gtl_init(void);

void start_scene_manager(s32);
void start_thread8_rmon(void);

#define STACK_PROBE_MAGIC 0xFEDCBA98
// size of stack in double words (u64, 8 bytes)
#define THREAD0_STACK_SIZE 64
#define THREAD1_STACK_SIZE 32
#define THREAD3_STACK_SIZE 128
#define THREAD4_STACK_SIZE 192
#define THREAD5_STACK_SIZE 512
#define THREAD6_STACK_SIZE 256

// Thread Scheduler Priorities
#define THREAD3_PRI 120
#define THREAD4_PRI 110
#define THREAD5_PRI 50
#define THREAD6_PRI 115

// data
static struct Overlay OverlayManager = OVERLAY(app_render);
u32 sNoThread5 = 0;

// bss
u64 gThread0Stack[THREAD0_STACK_SIZE];
OSThread sThread1;
u64 sThread1Stack[THREAD1_STACK_SIZE];
OSThread sThread3;
u64 sThread3Stack[THREAD3_STACK_SIZE];
OSThread sThread4;
u64 sThread4Stack[THREAD4_STACK_SIZE];
OSThread gThread5;
u64 sThread5Stack[THREAD5_STACK_SIZE];
OSThread sThread6;
u64 sThread6Stack[THREAD6_STACK_SIZE];
u64 gRspBootCode[0x20];
s8 gSPImemOkay;
s8 gSPDmemOkay;
OSMesg sBlockMsg[1];
OSMesgQueue gThreadingQueue;
OSMesg sPIcmdBuf[100];
OSMesgQueue sPIcmdQ;
u8 sThreadArgBuf[128];

u64* get_thread4_stack_start(void) {
    return sThread4Stack + THREAD4_STACK_SIZE;
}

u64* func_8000046C(void) {
    return sThread5Stack;
}

s32 func_80000478(void) {
    return 0x1000;
}

void check_sp_imem(void) {
    if (IO_READ(SP_IMEM_START) == 6103) {
        gSPImemOkay = TRUE;
    } else {
        gSPImemOkay = FALSE;
    }
}

void check_sp_dmem(void) {
    if (IO_READ(SP_DMEM_START) == (u32)-1) {
        gSPDmemOkay = TRUE;
    } else {
        gSPDmemOkay = FALSE;
    }
}

void fatal_stack_overflow_thread(s32 tid) {
    fatal_printf("thread stack overflow  id = %d\n", tid);

    while (TRUE) { }
}

void check_stack_probes(void) {
    if (gThread0Stack[7] != STACK_PROBE_MAGIC) { fatal_stack_overflow_thread(0); }
    if (sThread1Stack[7] != STACK_PROBE_MAGIC) { fatal_stack_overflow_thread(1); }
    if (sThread3Stack[7] != STACK_PROBE_MAGIC) { fatal_stack_overflow_thread(3); }
    if (sThread5Stack[7] != STACK_PROBE_MAGIC) { fatal_stack_overflow_thread(5); }
}

void thread5_main(UNUSED void *arg) {
    osCreateViManager(OS_PRIORITY_VIMGR);
    gRomPiHandle = osCartRomInit();
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPIcmdQ, sPIcmdBuf, ARRAY_COUNT(sPIcmdBuf));
    create_dma_mq();

    dma_rom_read(PHYSICAL_TO_ROM(0xB70), gRspBootCode, sizeof(gRspBootCode));
    check_sp_imem();
    check_sp_dmem();
    osCreateMesgQueue(&gThreadingQueue, sBlockMsg, ARRAY_COUNT(sBlockMsg));

    osCreateThread(&sThread3, 3, &scMain, NULL, sThread3Stack + THREAD3_STACK_SIZE, THREAD3_PRI);
    sThread3Stack[7] = STACK_PROBE_MAGIC; osStartThread(&sThread3);
    osRecvMesg(&gThreadingQueue, NULL, OS_MESG_BLOCK);

    osCreateThread(&sThread4, 4, thread4_audio, NULL, sThread4Stack + THREAD4_STACK_SIZE, THREAD4_PRI);
    sThread4Stack[7] = STACK_PROBE_MAGIC; osStartThread(&sThread4);
    osRecvMesg(&gThreadingQueue, NULL, OS_MESG_BLOCK);

    osCreateThread(&sThread6, 6, contMain, NULL, sThread6Stack + THREAD6_STACK_SIZE, THREAD6_PRI);
    sThread6Stack[7] = STACK_PROBE_MAGIC; osStartThread(&sThread6);
    osRecvMesg(&gThreadingQueue, NULL, OS_MESG_BLOCK);

    gtl_init();
    load_overlay(&OverlayManager);
    start_scene_manager(0);
}

void thread1_idle(void *arg) {
    start_thread8_rmon();
    osCreateThread(&gThread5, 5, thread5_main, arg, sThread5Stack + THREAD5_STACK_SIZE, THREAD5_PRI);
    sThread5Stack[7] = STACK_PROBE_MAGIC;
    if (!sNoThread5) { osStartThread(&gThread5); }
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (TRUE) { }
}

void game_main(void) {
    gThread0Stack[7] = STACK_PROBE_MAGIC;
    __osSetWatchLo(0x04900000 & WATCHLO_ADDRMASK);
    osInitialize();
    osCreateThread(&sThread1, 1, thread1_idle, &sThreadArgBuf, sThread1Stack + THREAD1_STACK_SIZE, OS_PRIORITY_APPMAX);
    sThread1Stack[7] = STACK_PROBE_MAGIC; osStartThread(&sThread1);
}