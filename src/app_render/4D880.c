#include "common_structs.h"
#include "app_render.h"

typedef struct UnkAsphaltLeopard {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} UnkAsphaltLeopard;

typedef struct UnkPinkLeopard {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8* unk_18[1];
} UnkPinkLeopard;

extern u16 D_800AEC68;
extern UnkRustRat* D_800BE1A0;
extern UnkRustRat* D_800BE1A8[16];
extern OMCamera* D_800BE1F0[4];
extern u8 D_800BE200[4];
extern s32 D_800BE228[];
extern UnkAsphaltLeopard** D_800BE268[];
extern UnkPinkLeopard** D_800BE288[];
extern u8 D_800AEC60;
extern u8 D_800AEC64;

void func_800A4798(GObj*);
void func_800A4858(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A1ED0.s")
/*
TODO later
extern u32 D_800BE228[8];
extern u32 D_800BE248[8];
extern u32* D_800BE268[8];
extern u32** D_800BE288[8];

void func_800A1ED0(s32 arg0, s32* arg1, s32* arg2) {
    s32 i, j;

    if (arg0 < 8) {
        D_800BE228[arg0] = *arg1;
        D_800BE248[arg0] = *arg2;
        D_800BE268[arg0] = ((u32)arg1) + 4;
        D_800BE288[arg0] = ((u32)arg2) + 4;

        for (i = 1; i < D_800BE228[arg0]; i++) {
            arg1[i] = (u32)(arg1) + arg1[i];
        }
        for (i = 1; i < D_800BE248[arg0]; i++) {
            arg2[i] = (u32)(arg2) + arg2[i];
        }

        for (i = 0; i < D_800BE248[arg0]; i++) {
            for (j = 0; j < D_800BE288[arg0][i][j]; j++) {
                D_800BE288[arg0][i][j]
            }
        }
    }
}
*/

#ifdef NON_MATCHING
// loop unroll
GObj* func_800A2094(s32 arg0, s32 arg1, OMCamera* arg2) {
    s32 i;
    s32 s0;
    UnkRustRat* temp;

    D_800BE1F0[0] = arg2;
    D_800BE200[0] = 1;
    for (i = 1; i < 4; i++) {
        D_800BE1F0[i] = 0;
    }

    D_800BE1A0 = NULL;
    for (i = 0; i < 16; i++) {
        D_800BE1A8[i] = NULL;
    }

    s0 = arg1 - 1;
    while (s0 >= 0) {
        temp = gtlMalloc(sizeof(UnkRustRat), 4);
        if (temp == NULL) {
            return NULL;
        }
        s0--;
        temp->next = D_800BE1A0;
        D_800BE1A0 = temp;
    }

    if (ohFindById(-6) != 0) {
        return NULL;
    } else {
        return ohCreateCamera(-6, func_800A4798, 0, 0x80000000, func_800A4858, arg0, 0, 0, FALSE, 1, NULL, 1, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2094.s")
GObj* func_800A2094(s32 arg0, s32 arg1, OMCamera* arg2);
#endif

void func_800A21C0(s32 arg0, OMCamera* arg1, s32 arg2) {
    D_800BE1F0[arg0] = arg1;
    D_800BE200[arg0] = arg2;
}

#ifdef NON_MATCHING
UnkRustRat* func_800A21E0(UnkRustRat** arg0, s32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7,
                    f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, s32 argF, UnkCoalEel* arg10) {
    UnkRustRat* ret = D_800BE1A0;

    if (ret == NULL) {
        return NULL;
    }

    if (arg10 != NULL) {
        ret->unk_04 = arg10->unk_04;
    } else {
        ret->unk_04 = ++D_800AEC68;
    }

    D_800BE1A0 = ret->next;

    if (arg0 == NULL) {
        ret->next = D_800BE1A8[arg1 >> 3];
        D_800BE1A8[arg1 >> 3] = ret;
    } else {
        ret->next = *arg0;
        *arg0 = ret;
    }

    ret->unk_08 = arg1;
    ret->unk_06 = arg2;
    ret->unk_0A = arg3;
    ret->unk_20 = arg6;
    ret->unk_24 = arg7;
    ret->unk_28 = arg8;
    ret->unk_2C = arg9;
    ret->unk_30 = argA;
    ret->unk_34 = argB;
    ret->unk_40 = argC;
    ret->unk_38 = argD;
    ret->unk_3C = argE;
    ret->unk_1E = arg5 + 1;
    ret->unk_14 = arg4;
    ret->unk_18 = 0;
    ret->unk_1A = 0;
    if (argF) {
        ret->unk_06 = arg2 | 0x10;
    }
    if (arg4 != 0) {
        ret->unk_0C = TRUE;
    } else {
        ret->unk_0C = FALSE;
    }
    ret->unk_48.r = ret->unk_48.g = ret->unk_48.b = ret->unk_48.a = 0xFF;
    ret->unk_50.r = ret->unk_50.g = ret->unk_50.b = ret->unk_50.a = 0;
    ret->unk_0B = 0;
    ret->unk_12 = 0;
    ret->unk_10 = 0;
    ret->unk_0E = 0;
    ret->unk_58 = arg10;

    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A21E0.s")
UnkRustRat* func_800A21E0(UnkRustRat** arg0, s32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7,
                    f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, s32 argF, UnkCoalEel* arg10);
#endif

UnkRustRat* func_800A2B3C(UnkRustRat*, UnkRustRat*, s32);

UnkRustRat* func_800A235C(UnkRustRat** arg0, s32 arg1, s32 arg2) {
    UnkAsphaltLeopard* temp_v0;
    s32 id = arg1 & 7;

    if (id >= 8) {
        return NULL;
    }
    if (arg2 >= D_800BE228[id]) {
        return NULL;
    }
    temp_v0 = D_800BE268[id][arg2];
    return func_800A21E0(arg0, arg1, temp_v0->unk_08, temp_v0->unk_02, (u32)temp_v0 + 0x30, temp_v0->unk_06,
                        0.0f, 0.0f, 0.0f, temp_v0->unk_14, temp_v0->unk_18, temp_v0->unk_1C, temp_v0->unk_2C, temp_v0->unk_0C,
                        temp_v0->unk_10, D_800BE288[id][temp_v0->unk_02]->unk_14, NULL);
}

UnkRustRat* func_800A244C(s32 arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, s32 argE, UnkCoalEel* argF) {
    UnkRustRat* ret;

    ret = func_800A21E0(NULL, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, argA, argB, argC, argD, argE, argF);
    if (ret != NULL) {
        func_800A2B3C(ret, 0, arg0 >> 3);
    }
    return ret;
}

UnkRustRat* func_800A2514(s32 arg0, s32 arg1) {
    UnkRustRat* ret;

    ret = func_800A235C(NULL, arg0, arg1);
    if (ret != NULL) {
        func_800A2B3C(ret, 0, arg0 >> 3);
    }
    return ret;
}

UnkRustRat* func_800A2564(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    UnkRustRat* ret;
    UnkAsphaltLeopard* temp_v0;
    s32 id = arg0 & 7;

    if (id >= 8) {
        return NULL;
    }
    if (arg1 >= D_800BE228[id]) {
        return NULL;
    }
    temp_v0 = D_800BE268[id][arg1];
    ret = func_800A21E0(NULL, arg0, temp_v0->unk_08, temp_v0->unk_02, (u32)temp_v0 + 0x30, temp_v0->unk_06,
                        arg2, arg3, arg4, arg5, arg6, arg7, temp_v0->unk_2C, temp_v0->unk_0C,
                        temp_v0->unk_10, D_800BE288[id][temp_v0->unk_02]->unk_14, NULL);
    if (ret != NULL) {
        func_800A2B3C(ret, 0, arg0 >> 3);
    }
    return ret;
}

void func_800A268C(UnkRustRat* arg0) {
    UnkRustRat* it;
    UnkRustRat* prev;
    s32 id = arg0->unk_08 >> 3;

    prev = NULL;
    for (it = D_800BE1A8[id]; it != NULL; it = it->next) {
        if (it == arg0) {
            if (prev == NULL) {
                D_800BE1A8[id] = it->next;
            } else {
                prev->next = it->next;
            }

            if (arg0->unk_58 != NULL && (arg0->unk_06 & 4) && arg0->unk_58->unk_08 == 2) {
                arg0->unk_58->unk_50--;
            }

            it->next = D_800BE1A0;
            D_800BE1A0 = it;
            return;
        }
        prev = it;
    }
}

void func_800A2740(void) {
    s32 i;
    UnkRustRat* it;
    UnkRustRat* next;

    for (i = 0; i < 16; i++) {
        for (it = D_800BE1A8[i]; it != NULL; it = next) {
            next = it->next;
            func_800A268C(it);
        }
    }
}

u8* func_800A27B0(u8* arg0, f32* arg1) {
    u8 sp4[4];

    sp4[0] = *arg0++;
    sp4[1] = *arg0++;
    sp4[2] = *arg0++;
    sp4[3] = *arg0++;
    *arg1 = *(f32*)sp4;
    return arg0;
}

u8* func_800A27E8(u8* arg0, u16* arg1) {
    u16 value;

    value = *arg0++;
    if (value & 0x80) {
        value = ((value & 0x7F) << 8) + *arg0++;
    }
    *arg1 = value + 1;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A29AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2B3C.s")

void func_800A4798(GObj* camObj) {
    u32 flags = camObj->flags;
    s32 i;
    UnkRustRat* prev;
    UnkRustRat* it;
    UnkRustRat* next;

    for (i = 0; i < 16; i++, flags >>= 1) {
        if (flags & 0x10000) {
            continue;
        }

        prev = NULL;
        it = D_800BE1A8[i];
        while (it != NULL) {
            next = func_800A2B3C(it, prev, i);
            if (it->next == next) {
                prev = it;
                it = next;
            } else {
                it = next;
            }
        }
    }
}

#if 0
void func_800A4858(GObj* camObj) {
    s32 sp2D4;
    s32 sp2D0;
    s32 sp2CC;
    s32 sp2C8;
    Mtx4f sp288;
    Mtx4f sp248;
    f32 temp_f0; // probably near sp220
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    s32 sp200;
    s32 sp1FC;
    s32 sp1F8;
    s32 sp1F4;
    s32 sp1C8;
    s32 sp1C4;

    s32 j;
    s32 var_s2;
    UnkRustRat* var_s7;
    s32 temp_fp;
    s32 temp_t4;
    s32 temp_s3;
    s32 temp_s5;
    s32 var_s6;
    s32 var_s1;
    s32 var_t2;
    s32 var_a1_2;
    s32 var_a0;

    f32 temp_f20;
    f32 temp_f2;

    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f28;

    f32 var_f24;
    f32 var_f16;
    f32 var_f26;
    f32 var_f18;

    f32 temp_f4;
    f32 temp_f8;

    f32 temp_f22;

    UnkPinkLeopard* v0;

    for (sp1F8 = 0; sp1F8 < 4; sp1F8++) {
        var_s2 = 0;

        if (D_800BE1F0[sp1F8] == NULL) {
            continue;
        }


        hal_look_at_roll_f(sp288, D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.xEye,
                                  D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.yEye,
                                  D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.zEye,
                                  D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.xAt,
                                  D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.yAt,
                                  D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.zAt,
                                  D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.roll,
                                  0.0f, 1.0f, 0.0f);
        hal_perspective_fast_f(sp248, NULL,
                               D_800BE1F0[sp1F8]->perspMtx.persp.fovy,
                               D_800BE1F0[sp1F8]->perspMtx.persp.aspect,
                               D_800BE1F0[sp1F8]->perspMtx.persp.near,
                               D_800BE1F0[sp1F8]->perspMtx.persp.far,
                               D_800BE1F0[sp1F8]->perspMtx.persp.scale);
        guMtxCatF(sp288, sp248, sp248);

        sp2C8 = -1;
        sp2CC = -1;
        sp2D0 = -1;
        sp2D4 = 0;

        sp218 = D_800BE1F0[sp1F8]->vp.vp.vscale[0];
        sp210 = -D_800BE1F0[sp1F8]->vp.vp.vscale[1];
        sp208 = D_800BE1F0[sp1F8]->vp.vp.vscale[2];
        sp214 = D_800BE1F0[sp1F8]->vp.vp.vtrans[0];
        sp20C = D_800BE1F0[sp1F8]->vp.vp.vtrans[1];
        sp204 = D_800BE1F0[sp1F8]->vp.vp.vtrans[2];

        sp220 = sqrtf(SQ(sp248[0][0]) + SQ(sp248[1][0]) + SQ(sp248[2][0]));
        temp_f0 = sqrtf(SQ(sp248[0][1]) + SQ(sp248[1][1]) + SQ(sp248[2][1]));

        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
        if (D_800BE200[sp1F8]) {
            gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
        } else {
            gDPSetRenderMode(gMainGfxPos[0]++, G_RM_XLU_SURF, G_RM_NOOP2);
        }
        gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_NONE);
        gDPSetDepthSource(gMainGfxPos[0]++, G_ZS_PRIM);
        gDPSetColorDither(gMainGfxPos[0]++, D_800AEC60);
        gDPSetAlphaDither(gMainGfxPos[0]++, D_800AEC64);

        for (j = 0; j < 16; j++) {
            for (var_s7 = D_800BE1A8[j]; var_s7 != NULL; var_s7 = var_s7->next) {
                if (var_s7->unk_40 == 0.0f) {
                    continue;
                }
                temp_f12 = (sp248[0][0] * var_s7->unk_20 + sp248[1][0] * var_s7->unk_24 + sp248[2][0] * var_s7->unk_28 + sp248[3][0]);
                temp_f20 = sp248[0][3] * var_s7->unk_20 + sp248[1][3] * var_s7->unk_24 + sp248[2][3] * var_s7->unk_28 + sp248[3][3];

                if (temp_f20 == 0.0f) {
                    continue;
                }

                temp_f2 = 1.0f / temp_f20;
                temp_f12 *= temp_f2;
                temp_f14 = (sp248[0][1] * var_s7->unk_20 + sp248[1][1] * var_s7->unk_24 + sp248[2][1] * var_s7->unk_28 + sp248[3][1]) * temp_f2;
                temp_f28 = (sp248[0][2] * var_s7->unk_20 + sp248[1][2] * var_s7->unk_24 + sp248[2][2] * var_s7->unk_28 + sp248[3][2]) * temp_f2;

                if (temp_f12 < -1.0f || temp_f12 > 1.0f || temp_f14 < -1.0f || temp_f14 > 1.0f || temp_f28 < -1.0f || temp_f28 > 1.0f) {
                    continue;
                }

                var_f16 = (temp_f2 * var_s7->unk_40 * sp220 + temp_f12) * sp218 + sp214;
                temp_f12 = temp_f12 * sp218 + sp214;
                if (var_f16 - temp_f12 > 0) {
                    var_f24 = temp_f12 - (var_f16 - temp_f12);
                } else {
                    var_f24 = var_f16;
                    var_f16 = temp_f12 - (var_f16 - temp_f12);
                }

                var_f18 = (temp_f2 * var_s7->unk_40 * temp_f0 + temp_f14) * sp210 + sp20C;
                temp_f14 = temp_f14 * sp210 + sp20C;
                if (var_f18 > temp_f14 * sp210 + sp20C) {
                    var_f26 = temp_f14 - (var_f18 - temp_f14);
                } else {
                    var_f26 = var_f18;
                    var_f18 = temp_f14 - (var_f18 - temp_f14);
                }

                v0 = D_800BE288[var_s7->unk_08 & 7][var_s7->unk_0A];
                temp_fp = v0->unk_04;
                temp_t4 = v0->unk_08;
                temp_s3 = v0->unk_0C;
                temp_s5 = v0->unk_10;
                sp1C8 = v0->unk_18[var_s7->unk_0B];
                if (temp_fp == 2) {
                    if (!(var_s7->unk_06 & 0x10)) {
                        sp1C4 = v0->unk_18[v0->unk_00 + var_s7->unk_0B];
                    } else {
                        sp1C4 = v0->unk_18[v0->unk_00];
                    }
                }

                sp200 = (temp_s3 * 4096.0f) / (var_f16 - var_f24);
                sp1FC = (temp_s5 * 4096.0f) / (var_f18 - var_f26);

                if (var_s7->unk_06 & 0x20) {
                    sp200 *= 2;
                    sp1F4 = 1;
                    switch (temp_s3) {
                        case 2:
                            var_s1 = 1;
                            break;
                        case 4:
                            var_s1 = 2;
                            break;
                        case 8:
                            var_s1 = 3;
                            break;
                        case 16:
                            var_s1 = 4;
                            break;
                        case 32:
                            var_s1 = 5;
                            break;
                        case 64:
                            var_s1 = 6;
                            break;
                        case 128:
                            var_s1 = 7;
                            break;
                        case 256:
                            var_s1 = 8;
                            break;
                        default:
                            var_s1 = 0;
                            break;
                    }
                } else {
                    sp1F4 = 2;
                    var_s1 = 0;
                }

                if (var_s7->unk_06 & 0x40) {
                    sp1FC *= 2;
                    var_s6 = 1;
                    switch (temp_s5) {
                        case 2:
                            var_t2 = 1;
                            break;
                        case 4:
                            var_t2 = 2;
                            break;
                        case 8:
                            var_t2 = 3;
                            break;
                        case 16:
                            var_t2 = 4;
                            break;
                        case 32:
                            var_t2 = 5;
                            break;
                        case 64:
                            var_t2 = 6;
                            break;
                        case 128:
                            var_t2 = 7;
                            break;
                        case 256:
                            var_t2 = 8;
                            break;
                        default:
                            var_t2 = 0;
                            break;
                    }
                } else {
                    var_s6 = 2;
                    var_t2 = 0;
                }

                if (temp_fp == 2) {
                    if (sp1C4 != sp2D4) {
                        gDPLoadTLUT_pal256(gMainGfxPos[0]++, sp1C4);
                        sp2D4 = sp1C4;
                    }
                    if (sp2C8 != 1) {
                        gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_RGBA16);
                        sp2C8 = 1;
                    }
                } else if (sp2C8 != 0) {
                    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
                    sp2C8 = 0;
                }

                if (sp1C8 != var_s2) {
                    switch (temp_t4) {
                        case 0:
                            gDPLoadTextureBlock_4b(gMainGfxPos[0]++, sp1C8, temp_fp, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x1000) {
                                sp2D4 = 0;
                            }
                            break;
                        case 1:
                            gDPLoadTextureBlock(gMainGfxPos[0]++, sp1C8, temp_fp, G_IM_SIZ_8b, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x800) {
                                sp2D4 = 0;
                            }
                            break;
                        case 2:
                            gDPLoadTextureBlock(gMainGfxPos[0]++, sp1C8, temp_fp, G_IM_SIZ_16b, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x400) {
                                sp2D4 = 0;
                            }
                            break;
                        case 3:
                            gDPLoadTextureBlock(gMainGfxPos[0]++, sp1C8, temp_fp, G_IM_SIZ_32b, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x200) {
                                sp2D4 = 0;
                            }
                            break;
                    }
                    var_s2 = sp1C8;
                }

                gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, var_s7->unk_48.r, var_s7->unk_48.g, var_s7->unk_48.b, var_s7->unk_48.a);
                if (var_s7->unk_06 & 0x80) {
                    gDPSetEnvColor(gMainGfxPos[0]++, var_s7->unk_50.r, var_s7->unk_50.g, var_s7->unk_50.b, var_s7->unk_50.a);
                    gDPSetCombineLERP(gMainGfxPos[0]++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                                                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                                                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                                                        PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT);
                } else if (var_s7->unk_06 & 0x100) {
                    gDPSetCombineLERP(gMainGfxPos[0]++, NOISE, 0, TEXEL0, 0,
                                                        TEXEL0, 0, PRIMITIVE, 0,
                                                        NOISE, 0, TEXEL0, 0,
                                                        TEXEL0, 0, PRIMITIVE, 0);
                } else {
                    gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                }

                if (var_s7->unk_06 & 0x400) {
                    var_a1_2 = 3;
                } else {
                    var_a1_2 = 1;
                    if (var_s7->unk_06 & 0x200) {
                        var_a0 = var_s7->unk_50.a;
                    } else {
                        var_a0 = 8;
                    }
                    if (sp2CC != var_a0) {
                        gDPSetBlendColor(gMainGfxPos[0]++, 0, 0, 0, var_a0);
                        sp2CC = var_a0;
                    }
                }

                if (sp2D0 != var_a1_2) {
                    gDPSetAlphaCompare(gMainGfxPos[0]++, var_a1_2);
                    sp2D0 = var_a1_2;
                }

                gDPSetPrimDepth(gMainGfxPos[0]++, (s32)((sp204 + temp_f28 * sp208) * 32.0f), 0);
                gSPScisTextureRectangle(gMainGfxPos[0]++, (s32)var_f24, (s32)var_f26, (s32)var_f16, (s32)var_f18, G_TX_RENDERTILE, 0, 0, sp200, sp1FC);
            }
        }
    }

    if (sp2C8 != 0) {
        gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A4858.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A63BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A7114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A7140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A716C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A71F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A72AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A7330.s")
