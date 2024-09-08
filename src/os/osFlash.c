#include "ultra64.h"
#include "PR/os_flash.h"

/// Some functions here seem to be modified from libultra's osFlash.c.
/// The ones that did match are included directly from ultralib.

// BSS
extern u32 __osFlashID[4];
extern OSIoMesg __osFlashMsg;
extern OSMesgQueue __osFlashMessageQ;
extern OSPiHandle __osFlashHandler;
extern OSMesg __osFlashMsgBuf[1];
extern s32 __osFlashVersion;

#include "ultralib/src/flash/flashreinit.c"

OSPiHandle* osFlashInit(void) {
    u32 flash_type;
    u32 flash_maker;

    osCreateMesgQueue(&__osFlashMessageQ, __osFlashMsgBuf, 1);

    if (__osFlashHandler.baseAddress == PHYS_TO_K1(FLASH_START_ADDR)) {
        return &__osFlashHandler;
    }

    __osFlashHandler.type = DEVICE_TYPE_FLASH;
    __osFlashHandler.baseAddress = PHYS_TO_K1(FLASH_START_ADDR);
    __osFlashHandler.latency = FLASH_LATENCY;
    __osFlashHandler.pulse = FLASH_PULSE;
    __osFlashHandler.pageSize = FLASH_PAGE_SIZE;
    __osFlashHandler.relDuration = FLASH_REL_DURATION;
    __osFlashHandler.domain = PI_DOMAIN2;
    __osFlashHandler.speed = 0;

    bzero(&__osFlashHandler.transferInfo, sizeof(__OSTranxInfo));

    osEPiLinkHandle(&__osFlashHandler);
    osFlashReadId(&flash_type, &flash_maker);

    if (flash_maker == FLASH_VERSION_MX_C ||
        flash_maker == FLASH_VERSION_MX_A ||
        flash_maker == FLASH_VERSION_MX_PROTO_A) {
        __osFlashVersion = 0x40;
    } else {
        __osFlashVersion = 0x80;
    }

    return &__osFlashHandler;
}

#include "ultralib/src/flash/flashreadstatus.c"

void osFlashReadId(u32* flash_type, u32* flash_maker) {
    u8 tmp;

    // why read status ?
    osFlashReadStatus(&tmp);

    // select silicon id read mode
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_ID);

    // read silicon id using DMA
    __osFlashMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    __osFlashMsg.hdr.retQueue = &__osFlashMessageQ;
    __osFlashMsg.dramAddr = __osFlashID;
    __osFlashMsg.devAddr = 0;
    __osFlashMsg.size = 2 * sizeof(u32);

    osWritebackDCache(&__osFlashID[0], sizeof(__osFlashID)); // this is osInvalDCache in libultra
    osEPiStartDma(&__osFlashHandler, &__osFlashMsg, OS_READ);
    osRecvMesg(&__osFlashMessageQ, NULL, OS_MESG_BLOCK);

    *flash_type = __osFlashID[0];
    *flash_maker = __osFlashID[1];
    return;
}

#include "ultralib/src/flash/flashclearstatus.c"

s32 osFlashAllErase(void) {
    u32 status;

    // start chip erase operation
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_CHIP_ERASE);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_EXECUTE_ERASE);

    // wait for completion by polling erase-busy flag
    do {
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & FLASH_STATUS_ERASE_BUSY) == FLASH_STATUS_ERASE_BUSY);

    // check erase operation status, clear status
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    // check for success
    if (((status & 0xFF) == 8) || ((status & 0xFF) == 0x48) || ((status & 8) == 8)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
}

s32 osFlashSectorErase(u32 page_num) {
    u32 status;

    // start sector erase operation
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_SECTOR_ERASE | page_num);
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_EXECUTE_ERASE);

    // wait for completion by polling erase-busy flag
    do {
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & FLASH_STATUS_ERASE_BUSY) == FLASH_STATUS_ERASE_BUSY);

    // check erase operation status, clear status
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if (((status & 0xFF) == 8) || ((status & 0xFF) == 0x48) || ((status & 8) == 8)) {
        return FLASH_STATUS_ERASE_OK;
    } else {
        return FLASH_STATUS_ERASE_ERROR;
    }
}

#include "ultralib/src/flash/flashwritebuffer.c"

s32 osFlashWriteArray(u32 page_num) {
    u32 status;

    // start program page operation
    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_PROGRAM_PAGE | page_num);

    // wait for completion by polling write-busy flag
    do {
        osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    } while ((status & FLASH_STATUS_WRITE_BUSY) == FLASH_STATUS_WRITE_BUSY);

    // check program operation status, clear status
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &status);
    osFlashClearStatus();

    if (((status & 0xFF) == 4) || ((status & 0xFF) == 0x44) || ((status & 4) == 4)) {
        return FLASH_STATUS_WRITE_OK;
    } else {
        return FLASH_STATUS_WRITE_ERROR;
    }
}

s32 osFlashReadArray(OSIoMesg* mb, s32 priority, s32 page_num, void* dramAddr, u32 n_pages, OSMesgQueue* mq) {
    s32 ret;
    u32 tmp;

    osEPiWriteIo(&__osFlashHandler, __osFlashHandler.baseAddress | FLASH_CMD_REG, FLASH_CMD_READ_ARRAY);
    osEPiReadIo(&__osFlashHandler, __osFlashHandler.baseAddress, &tmp);
    mb->hdr.pri = priority;
    mb->hdr.retQueue = mq;
    mb->dramAddr = dramAddr;
    mb->devAddr = page_num * __osFlashVersion;
    mb->size = n_pages * FLASH_BLOCK_SIZE;
    ret = osEPiStartDma(&__osFlashHandler, mb, OS_READ);
    return ret;
}
