#include "common.h"
// sys/dma.c

#include "sys/dma.h"
#include "sys/sched.h"

OSPiHandle* gRomPiHandle;
OSMesg sDmaOSMesg;
OSMesgQueue sDmaRetQueue;
s32 sVpkRamAddr;
s32 sVpkBufSize;
s32 sVpkRomAddr;

void dmaCreateMessageQueue(void) {
    osCreateMesgQueue(&sDmaRetQueue, &sDmaOSMesg, 1);
}

void dmaCopy(OSPiHandle *piHandle, u32 devAddr, u32 dramAddr, u32 numBytes, u8 direction) {
    OSIoMesg mb;

    if (direction == 1) {
        osWritebackDCache((void*)dramAddr, numBytes);
    } else {
        osInvalDCache((void*)dramAddr, numBytes);
    }
    mb.hdr.pri = 0;
    mb.hdr.retQueue = &sDmaRetQueue;
    mb.size = 0x10000;

    while (numBytes > 0x10000) {
        mb.dramAddr = (void*)dramAddr;
        mb.devAddr = devAddr;
        if (!scBeforeReset) {
            osEPiStartDma(piHandle, &mb, direction);
        }
        osRecvMesg(&sDmaRetQueue, NULL, 1);
        devAddr += 0x10000;
        dramAddr += 0x10000;
        numBytes -= 0x10000;
    }

    if (numBytes != 0) {
        mb.dramAddr = (void*)dramAddr;
        mb.devAddr = devAddr;
        mb.size = numBytes;
        if (!scBeforeReset) {
            osEPiStartDma(piHandle, &mb, direction);
        }
        osRecvMesg(&sDmaRetQueue, NULL, 1);
    }
}

void dmaLoadOverlay(Overlay* dmaData) {
    // If there is a text section, invalidate instruction and data caches
    if (dmaData->textVramEnd - dmaData->textVramStart != 0) {
        osInvalICache((void*)dmaData->textVramStart, dmaData->textVramEnd - dmaData->textVramStart);
        osInvalDCache((void*)dmaData->textVramStart, dmaData->textVramEnd - dmaData->textVramStart);
    }
    // If there are data/rodata sections, invalidate data cache
    if (dmaData->dataVramEnd - dmaData->dataVramStart != 0) {
        osInvalDCache((void*)dmaData->dataVramStart, dmaData->dataVramEnd - dmaData->dataVramStart);
    }
    // If there is any segment content, DMA it
    if (dmaData->romEnd - dmaData->romStart != 0) {
        dmaCopy(gRomPiHandle, dmaData->romStart, dmaData->vramStart, dmaData->romEnd - dmaData->romStart, OS_READ);
    }
    // Zero bss
    if (dmaData->bssVramEnd - dmaData->bssVramStart != 0) {
        bzero((void*)dmaData->bssVramStart, dmaData->bssVramEnd - dmaData->bssVramStart);
    }
}

void dmaReadRom(u32 romSrc, void* ramDst, u32 nbytes) {
    dmaCopy(gRomPiHandle, romSrc, (u32) ramDst, nbytes, OS_READ);
}

void dmaWriteRom(void* ramSrc, u32 romDst, u32 nbytes) {
    dmaCopy(gRomPiHandle, romDst, (u32) ramSrc, nbytes, OS_WRITE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/sys/dma/dmaDecodeVPK.s")
void dmaDecodeVPK(u16* data, s32 size, void (*func)(void), u32 arg3);

void dmaInitVPKStream(s32 romAddr, s32 ramAddr, s32 bufSize) {
    sVpkRomAddr = romAddr;
    sVpkRamAddr = ramAddr;
    sVpkBufSize = bufSize;
}

void dmaUpdateVPKStream(void) {
    dmaReadRom(sVpkRomAddr, (void*) sVpkRamAddr, sVpkBufSize);
    sVpkRomAddr += sVpkBufSize;
}

void dmaReadVPKToBuffer(u32 rom, u32 ram, void* buf, u32 size) {
    dmaInitVPKStream(rom, (s32) buf, size);
    dmaDecodeVPK(buf, size, &dmaUpdateVPKStream, ram);
}

void dmaReadVPK(u32 rom, u32 ram) {
    char buf[0x400];

    dmaReadVPKToBuffer(rom, ram, &buf, sizeof(buf));
}

#pragma GLOBAL_ASM("asm/nonmatchings/sys/dma/func_80003530.s")
