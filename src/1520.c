#include "common.h"

extern s32 D_80048888;
extern s32 D_80048890;

void func_80000920(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000928.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_800009A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000DE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80000F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_800016E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001D94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80001FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80002254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_800024E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/scMain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80002954.s")

void func_800029BC(s32 arg0) {
    D_80048888 = arg0;
}

void func_800029C8(s32 arg0) {
    D_80048890 = arg0;
}

void func_800029D4(void) {
    D_80048890 = 0;
}

// sys/dma.c

#include "sys/dma.h"

extern OSMesg sDmaOSMesg;
extern OSMesgQueue sDmaRetQueue;
extern s32 sVpkRamAddr;
extern s32 sVpkBufSize;
extern s32 sVpkRomAddr;

void create_dma_mq(void) {
    osCreateMesgQueue(&sDmaRetQueue, &sDmaOSMesg, 1);
}

extern s32 scBeforeReset;
extern OSPiHandle* gRomPiHandle;

void dma_copy(OSPiHandle *piHandle, u32 devAddr, u32 dramAddr, u32 numBytes, u8 direction) {
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

void load_overlay(Overlay* dmaData) {
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
        dma_copy(gRomPiHandle, dmaData->romStart, dmaData->vramStart, dmaData->romEnd - dmaData->romStart, OS_READ);
    }
    // Zero bss
    if (dmaData->bssVramEnd - dmaData->bssVramStart != 0) {
        bzero((void*)dmaData->bssVramStart, dmaData->bssVramEnd - dmaData->bssVramStart);
    }
}

void dma_rom_read(u32 romSrc, void* ramDst, u32 nbytes) {
    dma_copy(gRomPiHandle, romSrc, (u32) ramDst, nbytes, OS_READ);
}

void dma_rom_write(void* ramSrc, u32 romDst, u32 nbytes) {
    dma_copy(gRomPiHandle, romDst, (u32) ramSrc, nbytes, OS_WRITE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80002C94.s")
void func_80002C94(u16* data, s32 size, void (*func)(void), u32 arg3);

void initialize_vpk_dma_stream(s32 romAddr, s32 ramAddr, s32 bufSize) {
    sVpkRomAddr = romAddr;
    sVpkRamAddr = ramAddr;
    sVpkBufSize = bufSize;
}

void fill_vpk_dma_buffer(void) {
    dma_rom_read(sVpkRomAddr, (void*) sVpkRamAddr, sVpkBufSize);
    sVpkRomAddr += sVpkBufSize;
}

void func_800034C4(u32 rom, u32 ram, void* buf, u32 size) {
    initialize_vpk_dma_stream(rom, (s32) buf, size);
    func_80002C94(buf, size, &fill_vpk_dma_buffer, ram);
}

void loadCompressedData(u32 rom, u32 ram) {
    char buf[0x400];

    func_800034C4(rom, ram, &buf, sizeof(buf));
}

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80003530.s")
