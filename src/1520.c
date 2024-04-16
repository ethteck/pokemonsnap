#include "common.h"

#include "sys/dma.h"

extern s32 D_80048888;
extern s32 D_80048890;
extern OSMesg D_800488A4;
extern OSMesgQueue D_800488A8;
extern s32 D_800488C0;
extern s32 D_800488C4;
extern s32 D_800488C8;

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

void create_dma_mq(void) {
    osCreateMesgQueue(&D_800488A8, &D_800488A4, 1);
}

extern s32 D_8004888C;
extern OSMesgQueue D_800488A8;
extern OSPiHandle* D_800488A0;

void func_80002A10(OSPiHandle *piHandle, u32 devAddr, u32 dramAddr, u32 numBytes, u8 direction) {
    OSIoMesg mb;

    if (direction == 1) {
        osWritebackDCache((void*)dramAddr, numBytes);
    } else {
        osInvalDCache((void*)dramAddr, numBytes);
    }
    mb.hdr.pri = 0;
    mb.hdr.retQueue = &D_800488A8;
    mb.size = 0x10000;

    while (numBytes > 0x10000) {
            mb.dramAddr = (void*)dramAddr;
            mb.devAddr = devAddr;
            if (D_8004888C == 0) {
                osEPiStartDma(piHandle, &mb, direction);
            }
            osRecvMesg(&D_800488A8, NULL, 1);
            devAddr += 0x10000;
            dramAddr += 0x10000;
            numBytes -= 0x10000;
    }

    if (numBytes != 0) {
        mb.dramAddr = (void*)dramAddr;
        mb.devAddr = devAddr;
        mb.size = numBytes;
        if (D_8004888C == 0) {
            osEPiStartDma(piHandle, &mb, direction);
        }
        osRecvMesg(&D_800488A8, NULL, 1);
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
        func_80002A10(D_800488A0, dmaData->romStart, dmaData->vramStart, dmaData->romEnd - dmaData->romStart, 0);
    }
    // Zero bss
    if (dmaData->bssVramEnd - dmaData->bssVramStart != 0) {
        bzero((void*)dmaData->bssVramStart, dmaData->bssVramEnd - dmaData->bssVramStart);
    }
}

void dma_rom_read(u32 romSrc, void* ramDst, u32 nbytes) {
    func_80002A10(D_800488A0, romSrc, ramDst, nbytes, OS_READ);
}

void func_80002C5C(u32 dramAddr, u32 devAddr, u32 numBytes) {
    func_80002A10(D_800488A0, devAddr, dramAddr, numBytes, OS_WRITE);
}

void func_80002C94(void*, u32, void (*)(void), u32);
#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80002C94.s")

void func_8000345C(s32 devAddr, s32 dramAddr, s32 numBytes) {
    D_800488C8 = devAddr;
    D_800488C0 = dramAddr;
    D_800488C4 = numBytes;
}

void func_80003478(void) {
    dma_rom_read(D_800488C8, D_800488C0, D_800488C4);
    D_800488C8 += D_800488C4;
}

void func_800034C4(u32 rom, u32 ram, void* buf, u32 size) {
    func_8000345C(rom, (s32) buf, size);
    func_80002C94(buf, size, &func_80003478, ram);
}

void loadCompressedData(u32 rom, u32 ram) {
    char buf[0x400];

    func_800034C4(rom, ram, &buf, sizeof(buf));
}

#pragma GLOBAL_ASM("asm/nonmatchings/1520/func_80003530.s")
