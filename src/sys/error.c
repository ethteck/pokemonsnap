#include "common.h"
#include "ultralib/include/PR/os_internal_thread.h"
#include "string.h"
#include "ultralib/src/libc/xstdio.h"

// This file is almost the same as if not identical to
// https://github.com/VetriTheRetri/ssb-decomp-re/blob/main/src/sys/error.c

// The varargs functions in this file align the va_list
// This might be due to a change in the va_list macro from 5.3 to 7.1
// But, until that is known as a fact, only do the alignment when
// building for matching IDO code
#if defined(__sgi) && !defined(NON_MATCHING)
#define VA_LIST_ALIGN(ap, paramN) ((ap) = (va_list) ALIGN((uintptr_t) (ap), sizeof((paramN))))
#else
#define VA_LIST_ALIGN(ap, paramN)
#endif

#define HAL_CRASH_MSG_CPU_BREAK ((OSMesg) 1)
#define HAL_CRASH_MSG_FAULT ((OSMesg) 2)

#define THREAD8_MAIN_HANG_PRI 105

typedef struct Rect {
    /* 0x00 */ s32 ulx;
    /* 0x04 */ s32 uly;
    /* 0x08 */ s32 lrx;
    /* 0x0C */ s32 lry;
} Rect;

extern s32 gtlFrameCounter;

Rect D_80042420[8] = {
    { 0, 0, 3, 0 },
    { 0, 0, 0, 3 },
    { 3, 0, 3, 3 },
    { 0, 3, 3, 3 },
    { 0, 3, 0, 6 },
    { 3, 3, 3, 6 },
    { 0, 6, 3, 6 },
    { 5, 6, 5, 6 }
};

s32 D_800424A0[17][8] = {
    { 1, 1, 1, 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 1, 0, 1, 0, 1, 1, 0 },
    { 1, 1, 0, 1, 1, 1, 1, 0 },
    { 1, 0, 1, 0, 0, 1, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1, 0 },
    { 1, 1, 1, 1, 0, 1, 1, 0 },
    { 1, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 0, 1, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 0 },
    { 1, 1, 0, 1, 1, 0, 1, 0 },
    { 1, 1, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 }
};

f32 D_800426C0[] = {
    1.0f,
    10.0f,
    100.0f,
    1000.0f,
    10000.0f,
    100000.0f,
    1000000.0f,
    10000000.0f,
    100000000.0f,
    1000000000.0f
};

u8 error_isScreenActive = false;

u8 error_asciiToGlyphIDs[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x29, 0xff, 0xff, 0xff, 0x2b, 0xff, 0xff, 0x25, 0x26, 0xff, 0x2a, 0xff, 0x27, 0x2c, 0xff,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x24, 0xff, 0xff, 0xff, 0xff, 0x28,
    0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0xff, 0xff, 0xff, 0xff, 0xff
};

u32 error_glyphs[] = {
    0x70871C30, 0x8988A250, 0x88808290, 0x88831C90, 0x888402F8, 0x88882210, 0x71CF9C10, 0xF9CF9C70,
    0x8228A288, 0xF200A288, 0x0BC11C78, 0x0A222208, 0x8A222288, 0x71C21C70, 0x23C738F8, 0x5228A480,
    0x8A282280, 0x8BC822F0, 0xFA282280, 0x8A28A480, 0x8BC738F8, 0xF9C89C08, 0x82288808, 0x82088808,
    0xF2EF8808, 0x82288888, 0x82288888, 0x81C89C70, 0x8A08A270, 0x920DA288, 0xA20AB288, 0xC20AAA88,
    0xA208A688, 0x9208A288, 0x8BE8A270, 0xF1CF1CF8, 0x8A28A220, 0x8A28A020, 0xF22F1C20, 0x82AA0220,
    0x82492220, 0x81A89C20, 0x8A28A288, 0x8A28A288, 0x8A289488, 0x8A2A8850, 0x894A9420, 0x894AA220,
    0x70852220, 0xF8011000, 0x08020800, 0x10840400, 0x20040470, 0x40840400, 0x80020800, 0xF8011000,
    0x70800000, 0x88822200, 0x08820400, 0x108F8800, 0x20821000, 0x00022200, 0x20800020, 0x00000000
};

const char* error_cpuExceptions[] = {
    "Interrupt",
    "TLB modification",
    "TLB exception on load",
    "TLB exception on store",
    "Address error on load",
    "Address error on store",
    "Bus error on inst.",
    "Bus error on data",
    "System call exception",
    "Breakpoint exception",
    "Reserved instruction",
    "Coprocessor unusable",
    "Arithmetic overflow",
    "Trap exception",
    "Virtual coherency on inst.",
    "Floating point exception",
    "Watchpoint exception",
    "Virtual coherency on data"
};

const char* error_fpuExceptions[] = {
    "Unimplemented operation",
    "Invalid operation",
    "Division by zero",
    "Overflow",
    "Underflow",
    "Inexact operation"
};

s32 error_mesgPosX = 30;
s32 error_mesgPosY = 25;

// bss
extern OSThread D_80046880;
extern Rect* D_80096980;
extern OSThread D_80096988;
extern OSMesgQueue D_80097338;
extern OSMesg D_80097350[1];
extern void (*D_80097358)(void);
extern SCClient D_80097360;
extern OSMesg D_80097368[1];
extern OSMesgQueue D_80097370;
extern OSThread D_80097388;
extern void* D_80097D38;

void func_800239E0(s32 arg0, s32 arg1, s32 arg2, bool arg3) {
    if (arg2 >= 0 && arg2 < ARRAY_COUNT(D_800424A0)) {
        Gfx* gfx = gMainGfxPos[0];
        Rect* boxsize = D_80042420;
        s32* line = D_800424A0[arg2];
        s32 i;

        for (i = 0; i < ARRAY_COUNT(D_80042420) - 1; i++, line++, boxsize++) {
            if (*line == 0) {

            } else {
                gDPFillRectangle(gfx++,
                                 ((arg0 + boxsize->ulx) * viScreenWidth) / SCREEN_WIDTH,
                                 ((arg1 + boxsize->uly) * viScreenHeight) / SCREEN_HEIGHT,
                                 ((arg0 + boxsize->lrx) * viScreenWidth) / SCREEN_WIDTH,
                                 ((arg1 + boxsize->lry) * viScreenHeight) / SCREEN_HEIGHT);
            }
        }

        D_80096980 = boxsize;
        if (arg3) {
            gDPFillRectangle(gfx++,
                             ((arg0 + boxsize->ulx) * viScreenWidth) / SCREEN_WIDTH,
                             ((arg1 + boxsize->uly) * viScreenHeight) / SCREEN_HEIGHT,
                             ((arg0 + boxsize->lrx) * viScreenWidth) / SCREEN_WIDTH,
                             ((arg1 + boxsize->lry) * viScreenHeight) / SCREEN_HEIGHT);
        }
        D_80096980 = boxsize;
        gMainGfxPos[0] = gfx;
    }
}

void func_80024054(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 s6 = 0;
    s32 i;

    if (arg3 > 0 && arg3 < (viScreenWidth - arg0) / 7) {
        arg0 += (arg3 * 7);
        arg0 -= 7;

        if (arg2 < 0) {
            arg2 = -arg2;
            s6 = 1;
        }
        if (arg4 <= 0) {
            arg4 = -1;
        }
        for (i = 0; s6 < arg3; i++, arg0 -= 7, arg3--) {
            func_800239E0(arg0, arg1, (arg2 % 10) % 16U, arg4-- == 0);

            arg2 /= 10;

            if (arg5 != 0 && arg2 == 0 && arg4 < 0) {
                arg0 -= 7;
                break;
            }
        }
        if (s6 != 0) {
            func_800239E0(arg0, arg1, 16, FALSE);
        }
    }
}

void func_80024200(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_80024054(arg0, arg1, arg2, arg3, 0, arg4);
}

void func_80024228(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_80024054(arg0, arg1, D_800426C0[arg4] * arg2, arg3, arg4, arg5);
}

void func_80024278(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg3 > 0 && arg3 < (viScreenWidth - arg0) / 7) {
        arg0 += (arg3 * 7), arg0 -= 7;

        while (arg3 > 0) {
            func_800239E0(arg0, arg1, arg2 % 16U /* & 0xF */, FALSE);

            arg2 >>= 4;

            if (arg4 != 0 && arg2 == 0) {
                break;
            }
            arg0 -= 7, arg3--;
        }
    }
}

void error_fillRect(Gfx* dl, u32 ulx, u32 uly, u32 lrx, u32 lry) {
    gDPFillRectangle(
        dl,
        (viScreenWidth * ulx) / SCREEN_WIDTH,
        (uly * viScreenHeight) / SCREEN_HEIGHT,
        (viScreenWidth * lrx) / SCREEN_WIDTH,
        (lry * viScreenHeight) / SCREEN_HEIGHT);
}

#define GPACK_RGBA8888(r, g, b, a) ((((r) << 24) & 0xff000000) | \
                                    (((g) << 16) & 0xff0000) |   \
                                    (((b) << 8) & 0xff00) | ((a) & 0xff))

void func_80024450(GObj* gobj) {
    UNUSED s32 pad;
    s32 offsetX = 60;
    s32 offsetY = 210;
    s32 i, j;

    ren_func_800177D8(gMainGfxPos, gobj->data.cam, 0);
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_FILL);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0xFF, 0xFF, 0xFF, 0xFF)));
    func_80024200(60, 179, gContInputStickX, 3, TRUE);
    func_80024200(92, 179, gContInputStickY, 3, TRUE);

    // 0.00390625 is 1 / 1256, but it doesn't want to autoconvert
    func_80024228(offsetX, 195, gtlD_8004A8F0 * 0.00390625f, 5, 2, TRUE);
    offsetX += 35;

    func_80024228(offsetX, 195, gtlD_8004A8F4 * 0.00390625f, 5, 2, TRUE);
    offsetX += 35;

    func_80024228(offsetX, 195, scTimeSpentGfx * 0.00390625f, 5, 2, TRUE);
    offsetX += 35;

    func_80024228(
        offsetX,
        195,
        (gtlD_8004A8F0 * 0.00390625f) + (gtlD_8004A8F4 * 0.00390625f) + (scTimeSpentGfx * 0.00390625f),
        5,
        2,
        TRUE);
    offsetX += 70;

    func_80024228(offsetX, 195, D_80096250 * 0.00390625f, 5, 2, TRUE);
    offsetX += 35;

    func_80024228(offsetX, 195, scTimeSpentAudio * 0.00390625f, 5, 2, TRUE);

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0xFF, 0x00, 0x00, 0xFF)));
    error_fillRect(gMainGfxPos[0]++, 30, offsetY, ((gtlD_8004A8F0 / 4 > 256) ? 256 : gtlD_8004A8F0 / 4) + 30, offsetY + 1);
    offsetY += 2;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0xFF, 0x00, 0xFF, 0xFF)));
    error_fillRect(gMainGfxPos[0]++, 30, offsetY, ((gtlD_8004A8F4 / 4 > 256) ? 256 : gtlD_8004A8F4 / 4) + 30, offsetY + 1);
    offsetY += 2;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0x00, 0xFF, 0x00, 0xFF)));
    error_fillRect(gMainGfxPos[0]++, 30, offsetY, ((scTimeSpentGfx / 4 > 256) ? 256 : scTimeSpentGfx / 4) + 30, offsetY + 1);
    offsetY += 2;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0xFF, 0xFF, 0x00, 0xFF)));
    error_fillRect(gMainGfxPos[0]++, 30, offsetY, ((D_80096250 / 4 > 256) ? 256 : D_80096250 / 4) + 30, offsetY + 1);
    offsetY += 2;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0x00, 0xFF, 0xFF, 0xFF)));
    error_fillRect(gMainGfxPos[0]++, 30, offsetY, ((scTimeSpentAudio / 4 > 256) ? 256 : scTimeSpentAudio / 4) + 30, offsetY + 1);

    // controller buttons
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0xFF, 0xFF, 0x00, 0xFF)));

    for (i = 0; i < 16; i++) {
        if (gContInputCurrentButtons & (1 << i)) {
            error_fillRect(gMainGfxPos[0]++, (i * 4) + 30, 206, (i * 4) + 33, 208);
        }
    }
    // controller stick
    error_fillRect(
        gMainGfxPos[0]++,
        gContInputStickX / 4 + 39,
        -gContInputStickY / 4 + 184,
        gContInputStickX / 4 + 41,
        -gContInputStickY / 4 + 186);
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetFillColor(gMainGfxPos[0]++, viPackRGBA(GPACK_RGBA8888(0x10, 0x10, 0x10, 0xFF)));

    for (j = 30, i = 350; j != i; j += 64) {
        error_fillRect(gMainGfxPos[0]++, j, 210, j, 220);
        // required to match
        if (D_80096250 && D_80096250) {
        }
    }
    error_fillRect(gMainGfxPos[0]++, 40, 165, 40, 205);
    error_fillRect(gMainGfxPos[0]++, 20, 185, 60, 185);

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
}

GObj* func_80024C88(s32 arg0, s32 arg1, s32 arg2) {
    if (ohFindById(-2U) != NULL) {
        return NULL;
    }
    return ohCreateCamera(-2, ohUpdateDefault, arg0, arg1, func_80024450, arg2, 0, 0, 0, 0, NULL, 0, 0);
}

void error_framebufDrawBlackRect(s32 ulx, s32 uly, s32 width, s32 height) {
    u16* fb = (u16*) osViGetCurrentFramebuffer() + (viScreenWidth * uly) + ulx;
    s32 i;
    s32 j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++, fb++) {
            *fb = GPACK_RGBA5551(0, 0, 0, 1);
        }
        fb += viScreenWidth - width;
    }
}

void error_framebufWriteGlyph(s32 ulx, s32 uly, s32 char_index) {
    s32 i;
    s32 j;
    u32 initMask;
    u32 currentMask;
    u32* charOffset;
    u16* fb;
    u32 el;

    charOffset = &error_glyphs[char_index / 5 * 7];
    initMask = 0x80000000 >> ((char_index % 5) * 6);
    fb = (u16*) osViGetCurrentFramebuffer() + (viScreenWidth * uly) + ulx;

    for (i = 0; i < 7; i++, fb += (viScreenWidth - 6)) {
        for (j = 0, el = *charOffset++, currentMask = initMask; j < 6; j++, fb++, currentMask >>= 1) {
            if (currentMask & el) {
                *fb = GPACK_RGBA5551(0xFF, 0xFF, 0xFF, 0x01);
            } else
                *fb = GPACK_RGBA5551(0x00, 0x00, 0x00, 0x01);
        }
    }
}

char* error_memcpyAdvance(char* dst, const char* src, size_t count) {
    return (char*) memcpy(dst, src, count) + count;
}

void error_framebufPrintf(s32 ulx, s32 ulr, char* fmt, ...) {
    u8* csr;
    u32 glyph;
    s32 ans;
    char buf[0x100];
    va_list ap;

    va_start(ap, fmt);
    VA_LIST_ALIGN(ap, fmt);
    ans = _Printf(error_memcpyAdvance, buf, fmt, ap);
    va_end(ap);

    if (ans > 0) {
        csr = (u8*) buf;

        while (ans > 0) {
            glyph = error_asciiToGlyphIDs[*csr & 0x7F];

            if (glyph != 0xFF) {
                error_framebufWriteGlyph(ulx, ulr, glyph);
            }
            ans--;
            csr++;
            ulx += 6;
        }
    }
}

void error_wait(s32 ms) {
    OSTime cycles = OS_USEC_TO_CYCLES(ms * 1000ULL);

    osSetTime(0);

    while (osGetTime() < cycles) {
        continue;
    }
}

void error_framebufPrintFloatReg(s32 x, s32 y, s32 reg_id, f32* fp_reg) {
    u32 byterep = *(u32*) fp_reg;
    s32 small = ((byterep & 0x7F800000) >> 23) - 127;

    if ((small >= -126 && small < 128) || byterep == 0) {
        error_framebufPrintf(x, y, "F%02d:%.3e", reg_id, (f64) *fp_reg);
    } else {
        error_framebufPrintf(x, y, "F%02d:%08XH", reg_id, byterep);
    }
}

void error_framebufPrintFCSR(u32 fcsr) {
    s32 i;
    u32 mask = 0x20000;

    error_framebufPrintf(30, 155, "FPCSR:%08XH", fcsr);

    for (i = 0; i < ARRAY_COUNT(error_fpuExceptions); i++) {
        if (fcsr & mask) {
            error_framebufPrintf(132, 155, "(%s)", error_fpuExceptions[i]);
            break;
        } else
            mask >>= 1;
    }
}

s32 error_waitFramebufOrCont(u32 buttons, void* framebuf) {
    while (TRUE) {
        error_wait(16);
        contUpdate();

        if ((framebuf != NULL) && (osViGetCurrentFramebuffer() != framebuf)) {
            return TRUE;
        }
        if (buttons == gContInputCurrentButtons) {
            return FALSE;
        }
    }
}

void error_framebufPrintThreadStatus(OSThread* t, bool showSummary) {
    s16 adjustedCause;
    __OSThreadContext* ctx;
    s32 stackOffset;
    s32 y;
    u8* stackCsr;

    adjustedCause = (t->context.cause >> 2) & 31;
    // WATCH_POINT
    if (adjustedCause == 23) {
        adjustedCause = 16;
    }
    // Virt. Coherency on data read
    if (adjustedCause == 31) {
        adjustedCause = 17;
    }
    osWritebackDCacheAll();

    if (showSummary) {
        ctx = &t->context;
        error_framebufDrawBlackRect(25, 20, 270, 25);
        error_framebufPrintf(30, 25, "THREAD:%d  (%s)", t->id, error_cpuExceptions[adjustedCause]);
        error_framebufPrintf(30, 35, "PC:%08XH   SR:%08XH   VA:%08XH", ctx->pc, ctx->sr, ctx->badvaddr);
        osWritebackDCacheAll();
        error_waitFramebufOrCont(0, NULL);
        error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
    }

    // register dump
    ctx = &t->context;
    error_framebufDrawBlackRect(25, 20, 270, 210);
    error_framebufPrintf(30, 25, "THREAD:%d  (%s)", t->id, error_cpuExceptions[adjustedCause]);
    error_framebufPrintf(30, 35, "PC:%08XH   SR:%08XH   VA:%08XH", ctx->pc, ctx->sr, ctx->badvaddr);
    error_framebufPrintf(30, 50, "AT:%08XH   V0:%08XH   V1:%08XH", (u32) ctx->at, (u32) ctx->v0, (u32) ctx->v1);
    error_framebufPrintf(30, 60, "A0:%08XH   A1:%08XH   A2:%08XH", (u32) ctx->a0, (u32) ctx->a1, (u32) ctx->a2);
    error_framebufPrintf(30, 70, "A3:%08XH   T0:%08XH   T1:%08XH", (u32) ctx->a3, (u32) ctx->t0, (u32) ctx->t1);
    error_framebufPrintf(30, 80, "T2:%08XH   T3:%08XH   T4:%08XH", (u32) ctx->t2, (u32) ctx->t3, (u32) ctx->t4);
    error_framebufPrintf(30, 90, "T5:%08XH   T6:%08XH   T7:%08XH", (u32) ctx->t5, (u32) ctx->t6, (u32) ctx->t7);
    error_framebufPrintf(30, 100, "S0:%08XH   S1:%08XH   S2:%08XH", (u32) ctx->s0, (u32) ctx->s1, (u32) ctx->s2);
    error_framebufPrintf(30, 110, "S3:%08XH   S4:%08XH   S5:%08XH", (u32) ctx->s3, (u32) ctx->s4, (u32) ctx->s5);
    error_framebufPrintf(30, 120, "S6:%08XH   S7:%08XH   T8:%08XH", (u32) ctx->s6, (u32) ctx->s7, (u32) ctx->t8);
    error_framebufPrintf(30, 130, "T9:%08XH   GP:%08XH   SP:%08XH", (u32) ctx->t9, (u32) ctx->gp, (u32) ctx->sp);
    error_framebufPrintf(30, 140, "S8:%08XH   RA:%08XH", (u32) ctx->s8, (u32) ctx->ra);
    error_framebufPrintFCSR(ctx->fpcsr);
    error_framebufPrintFloatReg(30, 170, 0, &ctx->fp0.f.f_even);
    error_framebufPrintFloatReg(120, 170, 2, &ctx->fp2.f.f_even);
    error_framebufPrintFloatReg(210, 170, 4, &ctx->fp4.f.f_even);
    error_framebufPrintFloatReg(30, 180, 6, &ctx->fp6.f.f_even);
    error_framebufPrintFloatReg(120, 180, 8, &ctx->fp8.f.f_even);
    error_framebufPrintFloatReg(210, 180, 10, &ctx->fp10.f.f_even);
    error_framebufPrintFloatReg(30, 190, 12, &ctx->fp12.f.f_even);
    error_framebufPrintFloatReg(120, 190, 14, &ctx->fp14.f.f_even);
    error_framebufPrintFloatReg(210, 190, 16, &ctx->fp16.f.f_even);
    error_framebufPrintFloatReg(30, 200, 18, &ctx->fp18.f.f_even);
    error_framebufPrintFloatReg(120, 200, 20, &ctx->fp20.f.f_even);
    error_framebufPrintFloatReg(210, 200, 22, &ctx->fp22.f.f_even);
    error_framebufPrintFloatReg(30, 210, 24, &ctx->fp24.f.f_even);
    error_framebufPrintFloatReg(120, 210, 26, &ctx->fp26.f.f_even);
    error_framebufPrintFloatReg(210, 210, 28, &ctx->fp28.f.f_even);
    error_framebufPrintFloatReg(30, 220, 30, &ctx->fp30.f.f_even);
    osWritebackDCacheAll();
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);

    // stack dump
    error_framebufDrawBlackRect(25, 20, 270, 210);

    stackCsr = (u8*) (uintptr_t) ctx->sp;

    error_framebufPrintf(26, 20, "SP Base %08x", (u32) stackCsr);

    y = 30;

    for (stackOffset = 0; stackOffset < 0x98; stackOffset += 8) {
        u32 word = *(u32*) stackCsr;
        s32 small = ((word & 0x7F800000) >> 23) - 127;

        if ((small >= -126 && small < 128) || word == 0) {
            error_framebufPrintf(
                26,
                y,
                "%03d:%02x%02x%02x%02x %.3e",
                stackOffset,
                stackCsr[0],
                stackCsr[1],
                stackCsr[2],
                stackCsr[3],
                (f64) * (f32*) stackCsr);
        } else {
            error_framebufPrintf(
                26,
                y,
                "%03d:%02x%02x%02x%02x %08x",
                stackOffset,
                stackCsr[0],
                stackCsr[1],
                stackCsr[2],
                stackCsr[3],
                word);
        }

        stackCsr += 4;
        word = *(u32*) stackCsr;
        small = ((word & 0x7F800000) >> 23) - 127;

        if ((small >= -126 && small < 128) || word == 0) {
            error_framebufPrintf(
                172,
                y,
                ":%02x%02x%02x%02x %.3e",
                stackCsr[0],
                stackCsr[1],
                stackCsr[2],
                stackCsr[3],
                (f64) * (f32*) stackCsr);
        } else {
            error_framebufPrintf(
                172,
                y,
                ":%02x%02x%02x%02x %08x",
                stackCsr[0],
                stackCsr[1],
                stackCsr[2],
                stackCsr[3],
                word);
        }
        y += 10;
        stackCsr += 4;
    }
    osWritebackDCacheAll();
}

OSThread* error_getFaultThread(void) {
    OSThread* th = __osGetActiveQueue();

    while (th->priority != -1) {
        if (th->priority > OS_PRIORITY_IDLE && th->priority < OS_PRIORITY_APPMAX && (th->flags & (OS_FLAG_CPU_BREAK | OS_FLAG_FAULT))) {
            return th;
        }
        th = th->tlnext;
    }
    return NULL;
}

void error_setPrintFunc(void (*printFunc)(void)) {
    D_80097358 = printFunc;
}

void error_setMesgPos(s32 x, s32 y) {
    error_mesgPosX = x;
    error_mesgPosY = y;
}

void error_framebufVPrintfNewLine(const char* fmt, va_list args) {
    u32 glyph;
    s32 ans;
    char buf[0x100];
    u8* csr;

    ans = _Printf(error_memcpyAdvance, buf, fmt, args);

    if (ans > 0) {
        csr = (u8*) buf;

        while (ans > 0) {
            glyph = error_asciiToGlyphIDs[*csr & 0x7F];

            if (*csr == '\n') {
                error_mesgPosX = 30;
                error_mesgPosY += 10;
            } else {
                if (glyph != 0xFF) {
                    error_framebufWriteGlyph(error_mesgPosX, error_mesgPosY, glyph);
                }
                error_mesgPosX += 6;

                if (viScreenWidth - 30 < error_mesgPosX) {
                    error_mesgPosX = 30;
                    error_mesgPosY += 10;
                }
            }
            ans--;
            csr++;
        }
    }
    osWritebackDCacheAll();
}

void error_debugPrintf(const char* fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    VA_LIST_ALIGN(ap, fmt);

    error_framebufVPrintfNewLine(fmt, ap);

    va_end(ap);
}

void error_reportCPUBreakFault(UNUSED void* arg0) {
    OSMesg mesg[1];
    OSThread* thread;

    osSetEventMesg(OS_EVENT_CPU_BREAK, &D_80097338, HAL_CRASH_MSG_CPU_BREAK);
    osSetEventMesg(OS_EVENT_FAULT, &D_80097338, HAL_CRASH_MSG_FAULT);

    do {
        osRecvMesg(&D_80097338, mesg, OS_MESG_BLOCK);
        thread = error_getFaultThread();
    } while (thread == NULL);

    error_isScreenActive = true;
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(U_JPAD | U_CBUTTONS, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(A_BUTTON | L_JPAD, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(B_BUTTON | R_JPAD, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(D_JPAD | D_CBUTTONS, NULL);

    error_framebufPrintThreadStatus(thread, 1);

    if (D_80097358 != NULL) {
        while (true) {
            error_waitFramebufOrCont(0, NULL);
            error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
            error_framebufDrawBlackRect(25, 20, 270, 210);
            error_setMesgPos(30, 25);
            D_80097358();
            error_waitFramebufOrCont(0, NULL);
            error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
            error_framebufPrintThreadStatus(thread, 0);
        }
    }
    while (true) {
    }
}

void start_thread8_rmon(void) {
    osCreateMesgQueue(&D_80097338, D_80097350, ARRAY_COUNT(D_80097350));
    osCreateThread(&D_80096988, 8, error_reportCPUBreakFault, NULL, &D_80097338, OS_PRIORITY_RMON);
    osStartThread(&D_80096988);
}

void error_fileLoaderThread8(void* arg0) {
    OSMesg mesg;
    s32 sp50;
    s32 pri;
    s32 count;

    count = 0;
    scAddClient(&D_80097360, &D_80097370, D_80097368, ARRAY_COUNT(D_80097368));

    while (true) {
        osRecvMesg(&D_80097370, &mesg, OS_MESG_BLOCK);
        if (!error_isScreenActive) {
            if (sp50 == gtlFrameCounter) {
                count++;
            } else {
                count = 0;
            }
            sp50 = gtlFrameCounter;
            if (count >= 300) {
                error_isScreenActive = true;
                pri = osGetThreadPri(NULL);
                osSetThreadPri(NULL, OS_PRIORITY_RMON);
                error_waitFramebufOrCont(0, NULL);
                error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
                error_waitFramebufOrCont(0, NULL);
                error_waitFramebufOrCont(U_JPAD | U_CBUTTONS, NULL);
                error_waitFramebufOrCont(0, NULL);
                error_waitFramebufOrCont(A_BUTTON | L_JPAD, NULL);
                error_waitFramebufOrCont(0, NULL);
                error_waitFramebufOrCont(B_BUTTON | R_JPAD, NULL);
                error_waitFramebufOrCont(0, NULL);
                error_waitFramebufOrCont(D_JPAD | D_CBUTTONS, NULL);
                error_framebufPrintThreadStatus(&D_80046880, TRUE);
                if (D_80097358 != NULL) {
                    error_waitFramebufOrCont(0, NULL);
                    error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
                    error_framebufDrawBlackRect(25, 20, 270, 210);
                    error_setMesgPos(30, 25);
                    D_80097358();
                }
                error_waitFramebufOrCont(0, NULL);
                error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
                osSetThreadPri(NULL, pri);
                error_isScreenActive = false;
                count = 0;
            }
        }
    }
}

void func_80025ED0(void) {
    osCreateThread(&D_80097388, 8, error_fileLoaderThread8, NULL, &D_80097D38, THREAD8_MAIN_HANG_PRI);
    osStartThread(&D_80097388);
}

void error_printf(const char* fmt, ...) {
    void* framebuf;
    s32 pri;
    va_list ap;
    s32 tmp;

    va_start(ap, fmt);
    VA_LIST_ALIGN(ap, fmt);

    error_isScreenActive = true;
    pri = osGetThreadPri(NULL);
    osSetThreadPri(NULL, OS_PRIORITY_RMON);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(U_JPAD | U_CBUTTONS, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(A_BUTTON | L_JPAD, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(B_BUTTON | R_JPAD, NULL);
    error_waitFramebufOrCont(0, NULL);
    error_waitFramebufOrCont(D_JPAD | D_CBUTTONS, NULL);

    do {
        framebuf = osViGetCurrentFramebuffer();
        error_framebufDrawBlackRect(25, 20, 270, 25);
        error_setMesgPos(30, 25);
        error_framebufVPrintfNewLine(fmt, ap);
    } while (error_waitFramebufOrCont(0, framebuf) || error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, framebuf));

    osSetThreadPri(NULL, pri);
    error_isScreenActive = false;
}

void error_runPrintFunc(void (*printFunc)(void)) {
    s32 pri;
    void* framebuf;

    error_isScreenActive = true;
    pri = osGetThreadPri(NULL);
    osSetThreadPri(NULL, OS_PRIORITY_RMON);

    do {
        framebuf = osViGetCurrentFramebuffer();
        error_framebufDrawBlackRect(25, 20, 270, 210);
        error_setMesgPos(30, 25);
        printFunc();
    } while (error_waitFramebufOrCont(0, framebuf) || error_waitFramebufOrCont(Z_TRIG | L_TRIG | R_TRIG, framebuf));

    osSetThreadPri(NULL, pri);
    error_isScreenActive = false;
}
