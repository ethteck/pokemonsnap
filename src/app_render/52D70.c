#include "common.h"

void* func_800A73C0(u32 romSrcStart, u32 romSrcEnd) {
    void* ramDst;

    if (romSrcEnd < romSrcStart) {
        return NULL;
    }
    ramDst = gtlMalloc(romSrcEnd - romSrcStart, 8);
    dmaReadRom((void*)romSrcStart, ramDst, romSrcEnd - romSrcStart);
    return ramDst;
}
