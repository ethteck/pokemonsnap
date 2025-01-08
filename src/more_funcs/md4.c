#include "common.h"
#include "more_funcs.h"

extern MD4Ctx MD4_GlobalContext;

#define ROL32(value, shift) (((value) << (shift)) | ((value) >> (32 - (shift))))

#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & y) | (x & z) | (y & z))
#define H(x,y,z) (x ^ y ^ z)

#define STEP(a,b,c,d,k,s,constant,OP) \
temp = a + OP(b,c,d) + data[k] + constant, \
a = ROL32(temp, s)

#define ROUND1(a,b,c,d,k,s) STEP(a,b,c,d,k,s,0,F)
#define ROUND2(a,b,c,d,k,s) STEP(a,b,c,d,k,s,0x5A827999,G)
#define ROUND3(a,b,c,d,k,s) STEP(a,b,c,d,k,s,0x6ED9EBA1,H)

void MD4_Init(MD4Ctx* ctx) {
    s32 i;

    ctx->a = 0x67452301;
    ctx->b = 0xEFCDAB89;
    ctx->c = 0x98BADCFE;
    ctx->d = 0x10325476;

    // Same-line needed for matching
    for (i = 0; i < ARRAY_COUNT(ctx->buffer); i++) ctx->buffer[i] = 0;

    ctx->finalized = FALSE; // Digest is not yet finalized
}

void MD4_Transform(MD4Ctx* ctx, u32* data) {
    u32 A;
    u32 B;
    u32 C;
    u32 D;
    u32 temp;

    A = ctx->a;
    B = ctx->b;
    C = ctx->c;
    D = ctx->d;

    /* Round 1 */

    ROUND1(A,B,C,D,0,3);
    ROUND1(D,A,B,C,1,7);
    ROUND1(C,D,A,B,2,11);
    ROUND1(B,C,D,A,3,19);

    ROUND1(A,B,C,D,4,3);
    ROUND1(D,A,B,C,5,7);
    ROUND1(C,D,A,B,6,11);
    ROUND1(B,C,D,A,7,19);

    ROUND1(A,B,C,D,8,3);
    ROUND1(D,A,B,C,9,7);
    ROUND1(C,D,A,B,10,11);
    ROUND1(B,C,D,A,11,19);

    ROUND1(A,B,C,D,12,3);
    ROUND1(D,A,B,C,13,7);
    ROUND1(C,D,A,B,14,11);
    ROUND1(B,C,D,A,15,19);

    /* Round 2 */

    ROUND2(A,B,C,D,0,3);
    ROUND2(D,A,B,C,4,5);
    ROUND2(C,D,A,B,8,9);
    ROUND2(B,C,D,A,12,13);

    ROUND2(A,B,C,D,1,3);
    ROUND2(D,A,B,C,5,5);
    ROUND2(C,D,A,B,9,9);
    ROUND2(B,C,D,A,13,13);

    ROUND2(A,B,C,D,2,3);
    ROUND2(D,A,B,C,6,5);
    ROUND2(C,D,A,B,10,9);
    ROUND2(B,C,D,A,14,13);

    ROUND2(A,B,C,D,3,3);
    ROUND2(D,A,B,C,7,5);
    ROUND2(C,D,A,B,11,9);
    ROUND2(B,C,D,A,15,13);

    /* Round 3 */

    ROUND3(A,B,C,D,0,3);
    ROUND3(D,A,B,C,8,9);
    ROUND3(C,D,A,B,4,11);
    ROUND3(B,C,D,A,12,15);

    ROUND3(A,B,C,D,2,3);
    ROUND3(D,A,B,C,10,9);
    ROUND3(C,D,A,B,6,11);
    ROUND3(B,C,D,A,14,15);

    ROUND3(A,B,C,D,1,3);
    ROUND3(D,A,B,C,9,9);
    ROUND3(C,D,A,B,5,11);
    ROUND3(B,C,D,A,13,15);

    ROUND3(A,B,C,D,3,3);
    ROUND3(D,A,B,C,11,9);
    ROUND3(C,D,A,B,7,11);
    ROUND3(B,C,D,A,15,15);

    ctx->a += A;
    ctx->b += B;
    ctx->c += C;
    ctx->d += D;
}

void MD4_Update(MD4Ctx* ctx, u32* input, u32 byteCount) {
    s32 unused[2];
    u32 tempOffset;
    u8* currentBlock;
    u32 tempByteCount;
    u8 buffer[0x40];
    u32 i;

    // If no bits are provided or the hash is already finalized, return early
    if (byteCount == 0 && ctx->finalized != FALSE) {
        return;
    }

    if (ctx->finalized != FALSE) {
        return;
    }

    tempByteCount = byteCount;
    for (i = 0, currentBlock = ctx->buffer; tempByteCount != 0; i++, currentBlock++) {
        tempByteCount += *currentBlock;
        *currentBlock = tempByteCount;
        tempByteCount >>= 8;
    }

    // Process input if it's a complete block
    if (byteCount == MD4_BLOCK_LENGTH) {
        MD4_Transform(ctx, input);
        return;
    }

    // If input length is more than a full block, return early
    if (byteCount > MD4_BLOCK_LENGTH) {
        return;
    }

    // If input length is less than a full block
    tempOffset = byteCount >> 3;
    for (i = 0; i <= tempOffset; i++) {
        buffer[i] = ((u8*) input)[i];
    }

    // Since the input is less than a full block, we will prepare our own buffer
    for (i = tempOffset + 1; i < ARRAY_COUNT(buffer); i++) buffer[i] = 0;

    buffer[tempOffset] = (buffer[tempOffset] | (1 << (7 - (byteCount & 7)))) & ~((1 << (7 - (byteCount & 7))) - 1);

    if (tempOffset < 0x38) {
        for (i = 0; i < 8; i++) {
            buffer[0x38 + i] = ctx->buffer[i];
        }

        MD4_Transform(ctx, (u32*) buffer);
    } else {
        MD4_Transform(ctx, (u32*) buffer);

        for (i = 0; i < 0x38; i++) {
            buffer[i] = 0;
        }

        for (i = 0; i < 8; i++) {
            buffer[0x38 + i] = ctx->buffer[i];
        }
        MD4_Transform(ctx, (u32*) buffer);
    }
    ctx->finalized = TRUE;
}

MD4Ctx* MD4_Finalize(u32* input, s32 length) {
    s32 tempBytes;
    u32 remainingBytes;
    u32* currentBlock;

    MD4_Init(&MD4_GlobalContext);
    remainingBytes = 0;
    if (length >= 0x40) {
        currentBlock = input;
        tempBytes = 0x40;
        do {
            MD4_Update(&MD4_GlobalContext, currentBlock, 0x200);
            remainingBytes = tempBytes;
            tempBytes += 0x40;
            currentBlock += 0x10;
        } while (length >= tempBytes);
        // required to match
        if (!tempBytes && !tempBytes && !tempBytes) {
        }
    }
    MD4_Update(&MD4_GlobalContext, (u32*) ((u8*) input + remainingBytes), (length - remainingBytes) * 8);
    return &MD4_GlobalContext;
}

#undef ROL32
#undef F
#undef G
#undef H
#undef STEP
#undef ROUND1
#undef ROUND2
#undef ROUND3
