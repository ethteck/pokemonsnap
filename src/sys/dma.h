#ifndef SYSTEM_DMA_H
#define SYSTEM_DMA_H

#include <types.h>

#include <PR/os.h>
#include <PR/ultratypes.h>

typedef struct Overlay {
    u32 romStart;
    u32 romEnd;
    u32 vramStart;
    u32 textVramStart;
    u32 textVramEnd;
    u32 dataVramStart; // Probably rodata too
    u32 dataVramEnd;
    u32 bssVramStart;
    u32 bssVramEnd;
} Overlay; // size == 0x24

#define OVERLAY(name) \
    {(u32) name##_ROM_START, (u32) name##_ROM_END, (u32) name##_VRAM, (u32) name##_TEXT_START, (u32) name##_TEXT_END, (u32) name##_DATA_START, (u32) name##_RODATA_END, (u32) name##_BSS_START, (u32) name##_BSS_END}

extern OSPiHandle* gRomPiHandle;

void create_dma_mq(void);
void dma_copy(OSPiHandle* handle, u32 physAddr, uintptr_t vAddr, u32 size, u8 direction);
void load_overlay(Overlay* ovl);
void dma_rom_read(u32 romSrc, void* ramDst, u32 nbytes);
void dma_rom_write(void* ramSrc, u32 romDst, u32 nbytes);
OSPiHandle* sram_pi_init(void);
void dma_sram_read(u32 romSrc, void* ramDst, u32 nbytes);
void dma_sram_write(void* ramSrc, u32 romDst, u32 nbytes);
void dma_vpk_read(u32 devAddr, void* ramDst);

#endif /* SYSTEM_DMA_H */
