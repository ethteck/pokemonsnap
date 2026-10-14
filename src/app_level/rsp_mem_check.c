#include "common.h"

// This compressed entrypoint is loaded at 0x80200000; its state precedes it.
#define RSP_CHECK_IMEM_OK (*(u8*) 0x801FFFF0)
#define RSP_CHECK_DMEM_OK (*(u8*) 0x801FFFF4)
#define RSP_CHECK_ILLEGAL_COPY (*(u8*) 0x801FFFF8)

void rspCheckMemory(void) {
    if (RSP_CHECK_IMEM_OK == 0) {
        RSP_CHECK_ILLEGAL_COPY = 0xFF;
        return;
    }
    if (RSP_CHECK_DMEM_OK == 0) {
        RSP_CHECK_ILLEGAL_COPY = 0xFF;
        return;
    }
    RSP_CHECK_ILLEGAL_COPY = 0;
}
