#include "common.h"
#include "ld_addrs.h"

#define UNK_STUFF_VRAM 0x80200000

#define UNK_STUFF_SP_IMEM_OK *(u8*) (UNK_STUFF_VRAM - 0x10)
#define UNK_STUFF_SP_DMEM_OK *(u8*) (UNK_STUFF_VRAM - 0x0C)
#define UNK_STUFF_MINUS_8 *(u8*) (UNK_STUFF_VRAM - 0x08)

void func_80364360_504770(void) {
    dmaReadVPK0((u32*) AAA610_ROM_START, UNK_STUFF_VRAM);
    UNK_STUFF_SP_IMEM_OK = gSPImemOkay;
    UNK_STUFF_SP_DMEM_OK = gSPDmemOkay;
    ((void (*)(void)) UNK_STUFF_VRAM)();
    if (UNK_STUFF_MINUS_8 != 0) {
        setPlayerFlag(PFID_ILLEGAL_COPY, true);
    }
}
