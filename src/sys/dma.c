#include "common.h"

#include "sys/dma.h"
#include "sys/sched.h"

typedef struct HuffmanTreeNode {
    /* 0x00 */ struct HuffmanTreeNode* left;
    /* 0x04 */ struct HuffmanTreeNode* right;
    /* 0x08 */ s32 value;
} HuffmanTreeNode; // size = 0x0C

OSPiHandle* gRomPiHandle;
OSMesg sDmaOSMesg;
OSMesgQueue sDmaRetQueue;
s32 sVpkRamAddr;
s32 sVpkBufSize;
s32 sVpkRomAddr;

void dmaCreateMessageQueue(void) {
    osCreateMesgQueue(&sDmaRetQueue, &sDmaOSMesg, 1);
}

void dmaCopy(OSPiHandle* piHandle, u32 devAddr, u32 dramAddr, u32 numBytes, u8 direction) {
    OSIoMesg mb;

    if (direction == 1) {
        osWritebackDCache((void*) dramAddr, numBytes);
    } else {
        osInvalDCache((void*) dramAddr, numBytes);
    }
    mb.hdr.pri = 0;
    mb.hdr.retQueue = &sDmaRetQueue;
    mb.size = 0x10000;

    while (numBytes > 0x10000) {
        mb.dramAddr = (void*) dramAddr;
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
        mb.dramAddr = (void*) dramAddr;
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
        osInvalICache((void*) dmaData->textVramStart, dmaData->textVramEnd - dmaData->textVramStart);
        osInvalDCache((void*) dmaData->textVramStart, dmaData->textVramEnd - dmaData->textVramStart);
    }
    // If there are data/rodata sections, invalidate data cache
    if (dmaData->dataVramEnd - dmaData->dataVramStart != 0) {
        osInvalDCache((void*) dmaData->dataVramStart, dmaData->dataVramEnd - dmaData->dataVramStart);
    }
    // If there is any segment content, DMA it
    if (dmaData->romEnd - dmaData->romStart != 0) {
        dmaCopy(gRomPiHandle, dmaData->romStart, dmaData->vramStart, dmaData->romEnd - dmaData->romStart, OS_READ);
    }
    // Zero bss
    if (dmaData->bssVramEnd - dmaData->bssVramStart != 0) {
        bzero((void*) dmaData->bssVramStart, dmaData->bssVramEnd - dmaData->bssVramStart);
    }
}

void dmaReadRom(void* romSrc, void* ramDst, u32 nbytes) {
    dmaCopy(gRomPiHandle, (u32) romSrc, (u32) ramDst, nbytes, OS_READ);
}

void dmaWriteRom(void* ramSrc, u32 romDst, u32 nbytes) {
    dmaCopy(gRomPiHandle, romDst, (u32) ramSrc, nbytes, OS_WRITE);
}

void dmaDecodeVPK0(u16* data, u32 size, void (*updateStream)(void), u8* outBuffer) {
#define VPK0_UPDATE_STREAM()        \
    if ((uintptr_t) csr >= bound) { \
        updateStream();             \
        csr = data;                 \
    }

#define VPK0_READ_USHORT() \
    tempValue <<= 0x10;    \
    tempValue |= *(csr++); \
    numBits += 0x10;

#define VPK0_GET_BITS(var, n) \
    if (numBits < n) {        \
        VPK0_UPDATE_STREAM(); \
        VPK0_READ_USHORT();   \
    }                         \
    numBits -= n;             \
    var = ((tempValue << ((32 - n) - numBits)) >> (32 - (u32) (n)));

#define INIT_NODE(node)        \
    node = lengthsNode;        \
    lengthsNode->left = NULL;  \
    lengthsNode->right = NULL; \
    lengthsNode->value = 0;    \
    lengthsNode++;

    uintptr_t bound = (uintptr_t) ((uintptr_t) data + size);
    HuffmanTreeNode* sample1Node;
    HuffmanTreeNode* lengthsNode;
    HuffmanTreeNode sp14C[64];
    u8* outPtr;
    HuffmanTreeNode* offsetsTree;
    HuffmanTreeNode* lengthsTree;
    u8* copySrc;
    void* outBufferEnd;
    u32 sampleMethod;
    HuffmanTreeNode* offStack[20];
    s32 offStackSize;
    s32 value;
    HuffmanTreeNode* offsetsNode;
    HuffmanTreeNode* offNode;
    HuffmanTreeNode* lenStack[20];
    s32 lenStackSize;
    s32 unused2[2];
    HuffmanTreeNode* lenNode;
    s32 unused3[3];
    s32 sp64;
    s32 unused;
    u32 tempValue;
    s32 numBits;
    u16* csr;

    numBits = 0;
    tempValue = 0;
    lengthsNode = sp14C;

    // read "vpk0" magic
    updateStream();
    csr = data;
    // clang-format off
    VPK0_READ_USHORT(); VPK0_UPDATE_STREAM(); VPK0_READ_USHORT(); numBits -= 32;
    // clang-format on

    outPtr = outBuffer;

    // read size of decompressed data
    // clang-format off
    VPK0_UPDATE_STREAM(); VPK0_READ_USHORT(); VPK0_UPDATE_STREAM(); VPK0_READ_USHORT(); numBits -= 32; outBufferEnd = ((tempValue << ((32 - 32) - numBits)) >> (32 - (u32) (32))) + outBuffer;
    // clang-format on

    // read sample method
    VPK0_GET_BITS(sampleMethod, 8);

    // read Huffman tree for offsets
    offStackSize = 0;
    offStack[0] = NULL;
    while (true) {
        // leaf or node
        VPK0_GET_BITS(value, 1);
        // node, but less than 2 nodes on stack -> end of tree
        if (value != 0 && offStackSize < 2) {
            break;
        }
        if (value != 0) {
            // node
            INIT_NODE(offNode);
            // combine two nodes from stack
            offNode->left = offStack[offStackSize - 2];
            offNode->right = offStack[offStackSize - 1];
            // write current node on stack
            offStack[offStackSize - 2] = offNode;
            offStackSize--;
        } else {
            // leaf
            INIT_NODE(offNode);
            // read leaf node value
            VPK0_GET_BITS(offNode->value, 8);
            offStack[offStackSize] = offNode;
            offStackSize++;
        }
    }
    offsetsTree = offStack[0];

    // read Huffman tree for lengths
    lenStackSize = 0;
    lenStack[0] = 0;
    while (true) {
        // leaf or node
        VPK0_GET_BITS(value, 1);
        // node, but less than 2 nodes on stack -> end of tree
        if (value != 0 && lenStackSize < 2) {
            break;
        }

        if (value != 0) {
            // node
            INIT_NODE(lenNode);
            // combine two nodes from stack
            lenNode->left = lenStack[lenStackSize - 2];
            lenNode->right = lenStack[lenStackSize - 1];
            // write current node on stack
            lenStack[lenStackSize - 2] = lenNode;
            lenStackSize--;
        } else {
            // leaf
            INIT_NODE(lenNode);
            // read leaf node value
            VPK0_GET_BITS(lenNode->value, 8);
            lenStack[lenStackSize] = lenNode;
            lenStackSize++;
        }
    }
    lengthsTree = lenStack[0];

    while ((uintptr_t) outPtr < (uintptr_t) outBufferEnd) {
        VPK0_GET_BITS(value, 1);
        if (!value) {
            // byte value
            VPK0_GET_BITS(*outPtr++, 8);
        } else {
            // encoded data
            lengthsNode = lengthsTree;

            if (sampleMethod != 0) {
                // two samples
                sp64 = 0;
                sample1Node = offsetsTree;

                while (sample1Node->left != NULL) {
                    VPK0_GET_BITS(value, 1);
                    sample1Node = !value ? sample1Node->left : sample1Node->right;
                }
                VPK0_GET_BITS(value, sample1Node->value);

                if (value <= 2) {
                    sp64 = value + 1;
                    offsetsNode = offsetsTree;

                    while (offsetsNode->left != NULL) {
                        VPK0_GET_BITS(value, 1);
                        offsetsNode = !value ? offsetsNode->left : offsetsNode->right;
                    }

                    VPK0_GET_BITS(value, offsetsNode->value);
                }
                copySrc = outPtr - value * 4 - sp64 + 8;
            } else {
                // one sample
                offsetsNode = offsetsTree;
                // get number of bytes to move back
                while (offsetsNode->left != NULL) {
                    VPK0_GET_BITS(value, 1);
                    offsetsNode = !value ? offsetsNode->left : offsetsNode->right;
                }
                VPK0_GET_BITS(value, offsetsNode->value);
                // move back
                copySrc = outPtr - value;
            }
            // get number of bytes to copy
            while (lengthsNode->left != NULL) {
                VPK0_GET_BITS(value, 1);
                lengthsNode = !value ? lengthsNode->left : lengthsNode->right;
            }
            VPK0_GET_BITS(value, lengthsNode->value);

            while (value-- > 0) {
                *(outPtr++) = *(copySrc++);
            }
        }
    }
}

void dmaInitVPK0Stream(u32 romAddr, s32 ramAddr, s32 bufSize) {
    sVpkRomAddr = romAddr;
    sVpkRamAddr = ramAddr;
    sVpkBufSize = bufSize;
}

void dmaUpdateVPK0Stream(void) {
    dmaReadRom((void*) sVpkRomAddr, (void*) sVpkRamAddr, sVpkBufSize);
    sVpkRomAddr += sVpkBufSize;
}

void dmaReadVPK0ToBuffer(u32 rom, u32 ram, void* buf, u32 size) {
    dmaInitVPK0Stream(rom, (s32) buf, size);
    dmaDecodeVPK0(buf, size, &dmaUpdateVPK0Stream, (u8*) ram);
}

void dmaReadVPK0(u32* rom, u32 ram) {
    char buf[0x400];

    dmaReadVPK0ToBuffer((u32) rom, ram, &buf, sizeof(buf));
}

void func_80003530(u16* data, u8* outBuffer) {
#define VPK0_MEM_READ_USHORT(csr) \
    tempValue <<= 0x10;            \
    tempValue |= *(csr++);         \
    numBits += 0x10;

#define VPK0_MEM_READ_USHORT2(csr) \
    tempValue <<= 0x10;             \
    tempValue |= *(csr++);          \
    numBits -= 0x10;

#define VPK0_MEM_GET_BITS(var, n, csr)                                               \
    if (numBits < (n)) {                                                             \
        VPK0_MEM_READ_USHORT(csr);                                                   \
    }                                                                                \
    numBits -= (n);                                                                  \
    (var) = ((tempValue << (32 - ((n) + numBits))) >> (32 - (u32) (n)));

#define VPK0_RAM_INIT_NODE(node) \
    node = lengthsNode;           \
    lengthsNode->left = NULL;     \
    lengthsNode->right = NULL;    \
    lengthsNode->value = 0;       \
    lengthsNode++;

    uintptr_t bound;
    HuffmanTreeNode* sampleNode;
    HuffmanTreeNode* lengthsNode;
    HuffmanTreeNode nodePool[64];
    u8* outPtr;
    HuffmanTreeNode* offsetsTree;
    HuffmanTreeNode* lengthsTree;
    u8* copySrc;
    void* unusedEnd;
    s32 sampleMethod;
    HuffmanTreeNode* offStack[20];
    s32 offStackSize;
    s32 value;
    HuffmanTreeNode* offsetsNode;
    HuffmanTreeNode* offNode;
    HuffmanTreeNode* lenStack[20];
    s32 unusedValue;
    s32 lenStackSize;
    HuffmanTreeNode* unusedNode;
    s32 otherValue;
    HuffmanTreeNode* lengthsCursor;
    s32 unused3[3];
    s32 sampleAdjust;
    u32 tempValue;
    s32 numBits;
    u16* csr = data;
    s32 copyCount;

    lengthsNode = nodePool;
    numBits = 0;
    tempValue = 0;

    VPK0_MEM_READ_USHORT(csr);
    VPK0_MEM_READ_USHORT2(csr);
    VPK0_MEM_READ_USHORT(csr);
    VPK0_MEM_READ_USHORT2(csr);
    bound = tempValue + outBuffer;
    outPtr = outBuffer;

    VPK0_MEM_GET_BITS(sampleMethod, 8, csr);

    offStackSize = 0;
    offStack[0] = NULL;

    data = csr;
    while (true) {
        VPK0_MEM_GET_BITS(sampleAdjust, 1, data);

        if (sampleAdjust == 0 || offStackSize >= 2) {
            if (sampleAdjust != 0) {
                VPK0_RAM_INIT_NODE(offNode);
                offNode->left = offStack[offStackSize - 2];
                offNode->right = offStack[offStackSize - 1];
                offStack[offStackSize - 2] = offNode;
                offStackSize--;
            } else {
                VPK0_RAM_INIT_NODE(offNode);
                VPK0_MEM_GET_BITS(offNode->value, 8, data);
                offStack[offStackSize] = offNode;
                offStackSize++;
            }
        } else {
            break;
        }
    }

    offsetsTree = offStack[0];
    if (!unusedValue) {
        ;
    }
    lenStackSize = 0;
    lenStack[0] = NULL;

    while (true) {
        VPK0_MEM_GET_BITS(value, 1, data);

        if (value == 0 || lenStackSize >= 2) {
            if (value != 0) {
                VPK0_RAM_INIT_NODE(offNode);
                offNode->left = lenStack[lenStackSize - 2];
                offNode->right = lenStack[lenStackSize - 1];
                lenStack[lenStackSize - 2] = offNode;
                lenStackSize--;
            } else {
                VPK0_RAM_INIT_NODE(offNode);
                VPK0_MEM_GET_BITS(offNode->value, 8, data);
                lenStack[lenStackSize] = offNode;
                lenStackSize++;
            }
        } else {
            break;
        }
    }

    lengthsTree = lenStack[0];
    while ((uintptr_t) outPtr < bound) {
        if (numBits <= 0) {
            VPK0_MEM_READ_USHORT(data);
        }
        numBits--;

        if (!((tempValue << (0x1F - numBits)) >> 0x1F)) {
            VPK0_MEM_GET_BITS(*(outPtr++), 8, data);
        } else {
            if (sampleMethod != 0) {
                sampleAdjust = 0;

                sampleNode = offsetsTree;
                while (sampleNode->left != NULL) {
                    VPK0_MEM_GET_BITS(unusedValue, 1, data);
                    sampleNode = !unusedValue ? sampleNode->left : sampleNode->right;
                }

                VPK0_MEM_GET_BITS(value, sampleNode->value, data);
                value = (tempValue << (0x20 - (sampleNode->value + numBits))) >> (0x20 - sampleNode->value);

                if (value <= 2) {
                    sampleAdjust = value + 1;
                    offsetsNode = offsetsTree;
                    while (offsetsNode->left != NULL) {
                        VPK0_MEM_GET_BITS(value, 1, data);
                        offsetsNode = !value ? offsetsNode->left : offsetsNode->right;
                    }

                    VPK0_MEM_GET_BITS(value, offsetsNode->value, data);
                    value = (tempValue << (0x20 - (offsetsNode->value + numBits))) >> (0x20 - offsetsNode->value);
                }
                copySrc = outPtr - (value * 4) - sampleAdjust + 8;
            } else {
                unusedNode = offsetsTree;

                while (unusedNode->left != NULL) {
                    VPK0_MEM_GET_BITS(value, 1, data);
                    unusedNode = !value ? unusedNode->left : unusedNode->right;
                }

                VPK0_MEM_GET_BITS(value, unusedNode->value, data);
                value = (tempValue << (0x20 - (unusedNode->value + numBits))) >> (0x20 - unusedNode->value);
                copySrc = outPtr - value;
            }

            lengthsCursor = lengthsTree;

            while (lengthsCursor->left != NULL) {
                VPK0_MEM_GET_BITS(unusedNode, 1, data);
                lengthsCursor = !unusedNode ? lengthsCursor->left : lengthsCursor->right;
            }

            VPK0_MEM_GET_BITS(copyCount, lengthsCursor->value, data);
            copyCount = (tempValue << (0x20 - (lengthsCursor->value + numBits))) >> (0x20 - lengthsCursor->value);

            while (copyCount-- > 0) {
                *(outPtr++) = *(copySrc++);
            }
        }
    }

#undef VPK0_RAM_INIT_NODE
#undef VPK0_MEM_GET_BITS
#undef VPK0_MEM_READ_USHORT2
#undef VPK0_MEM_READ_USHORT
}
