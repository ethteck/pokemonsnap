#include "common.h"

extern s32 D_800E17E0_7E680[];
extern OSIoMesg D_800E17F0_7E690;
extern OSMesgQueue D_800E1808_7E6A8;
extern OSPiHandle D_800E1820_7E6C0;
extern void* D_800E1894_7E734;
extern s32 D_800E1898_7E738;

void func_800C1A38_5E8D8(s32*, s32*);

OSPiHandle* func_800C1790_5E630(u8 latency, u8 pulse, u8 pageSize, u8 relDuration, s32 arg4) {
    D_800E1820_7E6C0.baseAddress = arg4 | 0xA0000000;
    D_800E1820_7E6C0.type++; // ???
    D_800E1820_7E6C0.latency = latency;
    D_800E1820_7E6C0.pulse = pulse;
    D_800E1820_7E6C0.pageSize = pageSize;
    D_800E1820_7E6C0.relDuration = relDuration;
    D_800E1820_7E6C0.domain = PI_DOMAIN2;
    return &D_800E1820_7E6C0;
}

OSPiHandle* func_800C1818_5E6B8(void) {
    s32 sp1C;
    s32 sp18;

    osCreateMesgQueue(&D_800E1808_7E6A8, &D_800E1894_7E734, 1);
    if (D_800E1820_7E6C0.baseAddress == 0xA8000000) {
        return &D_800E1820_7E6C0;
    }
    D_800E1820_7E6C0.type = 8;
    D_800E1820_7E6C0.baseAddress = 0xA8000000;
    D_800E1820_7E6C0.latency = 5;
    D_800E1820_7E6C0.pulse = 0xC;
    D_800E1820_7E6C0.pageSize = 0xF;
    D_800E1820_7E6C0.relDuration = 2;
    D_800E1820_7E6C0.domain = 1;
    D_800E1820_7E6C0.speed = 0;
    bzero(&D_800E1820_7E6C0.transferInfo, sizeof(D_800E1820_7E6C0.transferInfo));
    osEPiLinkHandle(&D_800E1820_7E6C0);
    func_800C1A38_5E8D8(&sp1C, &sp18);

    if (sp18 == 0xC2001E || sp18 == 0xC20001 || sp18 == 0xC20000) {
        D_800E1898_7E738 = 0x40;
    } else {
        D_800E1898_7E738 = 0x80;
    }

    return &D_800E1820_7E6C0;
}

void func_800C196C_5E80C(u8* arg0) {
    u32 sp1C;

    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0xD2000000);
    osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0xD2000000);
    osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    *arg0 = sp1C & 0xFF;
    return;
}

void func_800C1A38_5E8D8(s32* arg0, s32* arg1) {
    u8 sp1F;

    func_800C196C_5E80C(&sp1F);
    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0xE1000000);
    D_800E17F0_7E690.hdr.pri = 0;
    D_800E17F0_7E690.hdr.retQueue = &D_800E1808_7E6A8;
    D_800E17F0_7E690.dramAddr = &D_800E17E0_7E680;
    D_800E17F0_7E690.devAddr = 0;
    D_800E17F0_7E690.size = 8;
    osWritebackDCache(&D_800E17E0_7E680, 0x10);
    osEPiStartDma(&D_800E1820_7E6C0, &D_800E17F0_7E690, 0);
    osRecvMesg(&D_800E1808_7E6A8, NULL, 1);
    *arg0 = D_800E17E0_7E680[0];
    *arg1 = D_800E17E0_7E680[1];
    return;
}

void func_800C1B50_5E9F0(void) {
    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0xD2000000U);
    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, 0);
    return;
}

s32 func_800C1BBC_5EA5C(void) {
    u32 sp1C;

    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0x3C000000);
    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0x78000000);

    do {
        osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    } while ((sp1C & 2) == 2);

    osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    func_800C1B50_5E9F0();

    if (((sp1C & 0xFF) == 8) || (sp1C & 0xFF) == 0x48 || ((sp1C & 8) == 8)) {
        return 0;
    } else {
        return -1;
    }
}

s32 func_800C1CD8_5EB78(s32 arg0) {
    u32 sp1C;

    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, arg0 | 0x4B000000);
    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0x78000000);

    do {
        osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    } while ((sp1C & 2) == 2);

    osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    func_800C1B50_5E9F0();

    if ((sp1C & 0xFF) == 8 || (sp1C & 0xFF) == 0x48 || (sp1C & 8) == 8) {
        return 0;
    } else {
        return -1;
    }
}

s32 func_800C1E04_5ECA4(OSIoMesg* arg0, s32 arg1, void* arg2, OSMesgQueue* arg3) {
    s32 sp1C;
    s32 temp_v0;

    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0xB4000000);
    arg0->hdr.pri = arg1;
    arg0->hdr.retQueue = arg3;
    arg0->dramAddr = arg2;
    arg0->devAddr = 0;
    arg0->size = 0x80;
    sp1C = osEPiStartDma(&D_800E1820_7E6C0, arg0, 1);
    return sp1C;
}

s32 func_800C1ED0_5ED70(s32 arg0) {
    u32 sp1C;

    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, arg0 | 0xA5000000);

    do {
        osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    } while ((sp1C & 1) == 1);

    osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp1C);
    func_800C1B50_5E9F0();

    if ((sp1C & 0xFF) == 4 || (sp1C & 0xFF) == 0x44 || (sp1C & 4) == 4) {
        return 0;
    } else {
        return -1;
    }
}

s32 func_800C1FD4_5EE74(OSIoMesg* arg0, s32 arg1, s32 arg2, void* arg3, s32 arg4, OSMesgQueue* arg5) {
    s32 sp1C;
    u32 sp18;

    osEPiWriteIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress | 0x10000, 0xF0000000);
    osEPiReadIo(&D_800E1820_7E6C0, D_800E1820_7E6C0.baseAddress, &sp18);
    arg0->hdr.pri = (u8) arg1;
    arg0->hdr.retQueue = arg5;
    arg0->dramAddr = arg3;
    arg0->devAddr = arg2 * D_800E1898_7E738;
    arg0->size = arg4 << 7;
    sp1C = osEPiStartDma(&D_800E1820_7E6C0, arg0, 0);
    return sp1C;
}
