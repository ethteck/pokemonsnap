#include "common.h"
#include "string.h"
#include "level_low.h"

UnkChestnutCougar* D_800E6B40_642F0 = NULL;
Mtx4f D_800E6B44_642F4 = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };

f32 func_800E4860_62010(Vec3f* v1, Vec3f* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void func_800E4890_62040(Mtx4f arg0, Vec3f* arg1) {
    s32 i;
    f32 temp[3];    

    for (i = 0; i < 3; i++) {
        temp[i] = arg1->x * arg0[0][i] + arg1->y * arg0[1][i] + arg1->z * arg0[2][i] + arg0[3][i];
    }

    arg1->x = temp[0];
    arg1->y = temp[1];
    arg1->z = temp[2];
}

void func_800E4904_620B4(Mtx4f arg0, Vec3f* arg1) {
    s32 i;
    f32 temp[3];    

    for (i = 0; i < 3; i++) {
        temp[i] = arg1->x * arg0[0][i] + arg1->y * arg0[1][i] + arg1->z * arg0[2][i];
    }

    arg1->x = temp[0];
    arg1->y = temp[1];
    arg1->z = temp[2];
}

void func_800E4970_62120(Mtx4f dst, Mtx4f src) {
    dst[0][0] = src[0][0];
    dst[0][1] = src[0][1];
    dst[0][2] = src[0][2];
    dst[0][3] = src[0][3];
    dst[1][0] = src[1][0];
    dst[1][1] = src[1][1];
    dst[1][2] = src[1][2];
    dst[1][3] = src[1][3];
    dst[2][0] = src[2][0];
    dst[2][1] = src[2][1];
    dst[2][2] = src[2][2];
    dst[2][3] = src[2][3];
    dst[3][0] = src[3][0];
    dst[3][1] = src[3][1];
    dst[3][2] = src[3][2];
    dst[3][3] = src[3][3];
}

void func_800E49F4_621A4(Mtx4f arg0, Mtx4f arg1, Mtx4f arg2) {
    s32 i, j, k;
    Mtx4f temp;    

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = 0.0f;
            for (k = 0; k < 4; k++) {
                temp[i][j] += arg1[i][k] * arg2[k][j];
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg0[i][j] = temp[i][j];
        }
    }
}

void func_800E4B60_62310(Mtx4f dst, Mtx4f src) {
    s32 i, j;
    Mtx4f temp;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = src[j][i];
        }
    }

    memcpy(dst, temp, sizeof(Mtx4f));
}

// added to match extra "jr ra; nop"
static void nullsub() {

}

// needs data probably ?
#ifdef NON_MATCHING
void func_800E4BCC_6237C(Mtx4f dst) {
    dst[0][0] = D_800E6B44_642F4[0][0];
    dst[0][1] = D_800E6B44_642F4[0][1];
    dst[0][2] = D_800E6B44_642F4[0][2];
    dst[0][3] = D_800E6B44_642F4[0][3];
    dst[1][0] = D_800E6B44_642F4[1][0];
    dst[1][1] = D_800E6B44_642F4[1][1];
    dst[1][2] = D_800E6B44_642F4[1][2];
    dst[1][3] = D_800E6B44_642F4[1][3];
    dst[2][0] = D_800E6B44_642F4[2][0];
    dst[2][1] = D_800E6B44_642F4[2][1];
    dst[2][2] = D_800E6B44_642F4[2][2];
    dst[2][3] = D_800E6B44_642F4[2][3];
    dst[3][0] = D_800E6B44_642F4[3][0];
    dst[3][1] = D_800E6B44_642F4[3][1];
    dst[3][2] = D_800E6B44_642F4[3][2];
    dst[3][3] = D_800E6B44_642F4[3][3];
}
#else 
#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4BCC_6237C.s")
void func_800E4BCC_6237C(Mtx4f dst);
#endif

void func_800E4C64_62414(Mtx4f mtx, Mtx4f invMtx, Vec3f scale, Vec3f rotation, Vec3f translation) {
    f32 sinAngleX = sinf(rotation.x);
    f32 cosAngleX = cosf(rotation.x);
    f32 sinAngleY = sinf(rotation.y);
    f32 cosAngleY = cosf(rotation.y);
    f32 sinAngleZ = sinf(rotation.z);
    f32 cosAngleZ = cosf(rotation.z);
    Mtx4f temp;
    s32 unused;

    func_800E4BCC_6237C(mtx);
    func_800E4BCC_6237C(invMtx);
    
    mtx[0][0] = scale.x;
    mtx[1][1] = scale.y;
    mtx[2][2] = scale.z;
    mtx[3][3] = 1.0f;

    invMtx[0][0] = 1.0f / scale.x;
    invMtx[1][1] = 1.0f / scale.y;
    invMtx[2][2] = 1.0f / scale.z;
    invMtx[3][3] = 1.0f;

    func_800E4BCC_6237C(temp);
    temp[2][1] = -sinAngleX;
    temp[1][2] = sinAngleX;
    temp[1][1] = cosAngleX;
    temp[2][2] = cosAngleX;
    func_800E49F4_621A4(mtx, mtx, temp);
    func_800E4B60_62310(temp, temp);
    func_800E49F4_621A4(invMtx, temp, invMtx);

    func_800E4BCC_6237C(temp);
    temp[0][2] = -sinAngleY;
    temp[2][0] = sinAngleY;
    temp[0][0] = cosAngleY;
    temp[2][2] = cosAngleY;
    func_800E49F4_621A4(mtx, mtx, temp);
    func_800E4B60_62310(temp, temp);
    func_800E49F4_621A4(invMtx, temp, invMtx);

    func_800E4BCC_6237C(temp);
    temp[1][0] = -sinAngleZ;
    temp[0][1] = sinAngleZ;
    temp[0][0] = cosAngleZ;
    temp[1][1] = cosAngleZ;
    func_800E49F4_621A4(mtx, mtx, temp);
    func_800E4B60_62310(temp, temp);
    func_800E49F4_621A4(invMtx, temp, invMtx);

    func_800E4BCC_6237C(temp);
    temp[3][0] = translation.x;
    temp[3][1] = translation.y;
    temp[3][2] = translation.z;
    func_800E49F4_621A4(mtx, mtx, temp);

    func_800E4BCC_6237C(temp);
    temp[3][0] = -translation.x;
    temp[3][1] = -translation.y;
    temp[3][2] = -translation.z;
    func_800E49F4_621A4(invMtx, temp, invMtx);
}

void func_800E4E98_62648(UnkCaramelBoa* arg0, s32* arg1) {
    f32 unused[8];
    Mtx4f mtx;
    Mtx4f invMtx;    

    if (arg0 != NULL) {
        func_800E4C64_62414(mtx, invMtx, arg0->scale, arg0->rotation, arg0->position);
        if (arg0->unk_04 != NULL) {
            UnkIndigoDingo* temp = arg0->unk_04;
            func_800E4970_62120(temp->unk_04, mtx);
            func_800E4970_62120(temp->unk_44, invMtx);
        }
    }
}

void func_800E4F40_626F0(Vec3f* arg0, Vec3f* arg1, f32 arg2, s32 arg3, Vec3f* arg4, Vec3f* arg5) {
    Vec3f sp24;

    arg4->x = arg1->x * arg2 + arg0->x;
    arg4->y = arg1->y * arg2 + arg0->y;
    arg4->z = arg1->z * arg2 + arg0->z;

    switch (arg3) {
        case 1:
            sp24.x = -1;
            sp24.y = 0;
            sp24.z = 0;
            break;
        case 2:
            sp24.x = 1;
            sp24.y = 0;
            sp24.z = 0;
            break;
        case 3:
            sp24.x = 0;
            sp24.y = -1;
            sp24.z = 0;
            break;
        case 4:
            sp24.x = 0;
            sp24.y = 1;
            sp24.z = 0;
            break;
        case 5:
            sp24.x = 0;
            sp24.y = 0;
            sp24.z = -1;
            break;
        case 6:
            sp24.x = 0;
            sp24.y = 0;
            sp24.z = 1;
            break;
    }

    arg5->x = arg1->x;
    arg5->y = arg1->y;
    arg5->z = arg1->z;
    Vec3f_func_8001AC98(arg5, &sp24);
}

s32 func_800E5094_62844(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, Vec3f* arg8, Vec3f* arg9) {
    Vec3f sp3C;
    f32 sp38;
    f32 sp34 = 0.0f;
    f32 sp30 = FLOAT_MAX;
    f32 f2;
    s32 sp28 = 0;

    arg9->x = arg1->x;
    arg9->y = arg1->y;
    arg9->z = arg1->z;

    sp3C.x = arg9->x;
    sp3C.y = arg9->y;
    sp3C.z = arg9->z;

    sp38 = Vec3fNormalize(&sp3C);

    if (sp3C.x < -0.0001f) {
        f2 = (arg2 - arg0->x) / sp3C.x;
        if (f2 < sp34) {
            return FALSE;
        }

        if (f2 <= sp30) {
            sp30 = f2;
        }

        f2 = (arg3 - arg0->x) / sp3C.x;
        if (f2 >= sp34) {
            sp28 = 2;
            if (f2 > sp30) {
                return FALSE;
            }
            sp34 = f2;
        }
    } else if (sp3C.x > 0.0001f) {
        f2 = (arg3 - arg0->x) / sp3C.x;
        if (f2 < sp34) {
            return FALSE;
        }

        if (f2 <= sp30) {
            sp30 = f2;
        }

        f2 = (arg2 - arg0->x) / sp3C.x;
        if (f2 >= sp34) {
            sp28 = 1;
            if (f2 > sp30) {
                return FALSE;
            }
            sp34 = f2;
        }
    } else if (arg0->x < arg2 || arg0->x > arg3){
        return FALSE;
    }

    if (sp3C.y < -0.0001f) {
        f2 = (arg4 - arg0->y) / sp3C.y;
        if (f2 < sp34) {
            return FALSE;
        }

        if (f2 <= sp30) {
            sp30 = f2;
        }

        f2 = (arg5 - arg0->y) / sp3C.y;
        if (f2 >= sp34) {
            sp28 = 4;
            if (f2 > sp30) {
                return FALSE;
            }
            sp34 = f2;
        }
    } else if (sp3C.y > 0.0001f) {
        f2 = (arg5 - arg0->y) / sp3C.y;
        if (f2 < sp34) {
            return FALSE;
        }

        if (f2 <= sp30) {
            sp30 = f2;
        }

        f2 = (arg4 - arg0->y) / sp3C.y;
        if (f2 >= sp34) {
            sp28 = 3;
            if (f2 > sp30) {
                return FALSE;
            }
            sp34 = f2;
        }
    } else if (arg0->y < arg4 || arg0->y > arg5){
        return FALSE;
    }

    if (sp3C.z < -0.0001f) {
        f2 = (arg6 - arg0->z) / sp3C.z;
        if (f2 < sp34) {
            return FALSE;
        }

        if (f2 <= sp30) {
            sp30 = f2;
        }

        f2 = (arg7 - arg0->z) / sp3C.z;
        if (f2 >= sp34) {
            sp28 = 6;
            if (f2 > sp30) {
                return FALSE;
            }
            sp34 = f2;
        }
    } else if (sp3C.z > 0.0001f) {
        f2 = (arg7 - arg0->z) / sp3C.z;
        if (f2 < sp34) {
            return FALSE;
        }

        if (f2 <= sp30) {
            sp30 = f2;
        }

        f2 = (arg6 - arg0->z) / sp3C.z;
        if (f2 >= sp34) {
            sp28 = 5;
            if (f2 > sp30) {
                return FALSE;
            }
            sp34 = f2;
        }
    } else if (arg0->z < arg6 || arg0->z > arg7){
        return FALSE;
    }

    if (sp34 < 0.0001f) {
        return FALSE;
    }

    if (sp28 > 0 && sp34 < sp38) {
        func_800E4F40_626F0(arg0, &sp3C, sp34, sp28, arg8, arg9);
        sp38 *= 0.7f;
        Vec3fScale(arg9, sp38);
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 func_800E55C0_62D70(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, Vec3f* arg4, Vec3f* arg5) {
    f32 unused;
    f32 sp60;
    f32 f20;
    f32 sp58;
    f32 f12;
    f32 sp50;
    f32 unused2;    
    Vec3f sp40;
    Vec3f sp34;

    arg5->x = arg1->x;
    arg5->y = arg1->y;
    arg5->z = arg1->z;
    f20 = Vec3fNormalize(arg5);
    Vec3fDiff(&sp40, arg2, arg0);
    sp60 = func_800E4860_62010(&sp40, &sp40);
    sp58 = func_800E4860_62010(&sp40, arg5);

    if (sp60 >= SQ(arg3) || sp58 < 0.0001f) {
        return FALSE;
    }

    f12 = sqrtf(sp58) + (SQ(arg3) - sp60);
    if (f12 > 0.0001f) {
        sp50 = sp58 - sqrtf(f12);
        if (sp50 < f20) {
            sp50 -= 12.0f;
            if (sp50 < 0.0f) {
                sp50 = 0.0f;
            }

            arg4->x = arg0->x + sp50 * arg5->x;
            arg4->y = arg0->y + sp50 * arg5->y;
            arg4->z = arg0->z + sp50 * arg5->z;
            sp50 = f20 - sp50;
            Vec3fDirection(&sp34, arg4, arg2);
            f20 *= 0.7f;
            Vec3f_func_8001AC98(arg5, &sp34);
            arg4->x += sp50 * arg5->x;
            arg4->y += sp50 * arg5->y;
            arg4->z += sp50 * arg5->z;
            Vec3fScale(arg5, f20);
            return TRUE;
        }
    }
    return FALSE;
}

void func_800E57CC_62F7C(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3, Vec3f* arg4) {
    Vec3f sp1C;

    arg3->x = arg0->x + arg2 * arg1->x;
    arg3->y = arg0->y + arg2 * arg1->y;
    arg3->z = arg0->z + arg2 * arg1->z;

    sp1C.x = arg3->x;
    sp1C.y = 0.0f;
    sp1C.z = arg3->z;
    Vec3fNormalize(&sp1C);
    Vec3f_func_8001AC98(arg4, &sp1C);
}

s32 func_800E5854_63004(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, f32 arg4, Vec3f* arg5, Vec3f* arg6) {
    Vec3f sp74;
    Vec3f sp68;
    f32 f20;
    f32 unkf;
    f32 unused1;
    f32 sp58;
    f32 sp54;
    f32 f12;
    f32 sp4C;
    f32 f2_2;
    f32 sp44;
    f32 f12_2;
    f32 unused2;

    Vec3fDiff(&sp68, arg0, arg2);
    arg6->x = arg1->x;
    arg6->y = arg1->y;
    arg6->z = arg1->z;

    f20 = Vec3fNormalize(arg6);
    sp74.x = arg6->x;
    sp74.y = arg6->y;
    sp74.z = arg6->z;

    sp58 = SQ(sp74.x) + SQ(sp74.z);
    if (sp58 > 0.0001f) {
        sp54 = sp68.x * sp74.x + sp68.z * sp74.z;
        unkf = SQ(sp54);
        unused1 = SQ(sp68.x) + SQ(sp68.z) - SQ(arg3);
        f12 = sp58 * unused1;
        sp4C = unkf - f12;
        if (f12 <= unkf) {
            f2_2 = (-sp54 - sqrtf(sp4C)) / sp58;
            if (f2_2 > 0.0001f && sp44 < FLOAT_MAX) { // UB: sp44 uninitialized 
                f12_2 = ABS(f2_2 * sp74.y + sp68.y);
                if (f12_2 <= arg4 && f2_2 < f20) {
                    func_800E57CC_62F7C(&sp68, &sp74, f2_2, arg5, arg6);
                    f20 *= 0.7f;
                    Vec3fScale(arg6, f20);
                    Vec3fAdd(arg5, arg2);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void func_800E5A4C_631FC(Vec3f* arg0, Vec3f* arg1, f32 arg2, Vec3f* arg3, Vec3f* arg4) {
    Vec3f sp1C;

    arg3->x = arg0->x + arg2 * arg1->x;
    arg3->y = arg0->y + arg2 * arg1->y;
    arg3->z = arg0->z + arg2 * arg1->z;

    sp1C.x = arg3->x;
    sp1C.y = 0.0f;
    sp1C.z = arg3->z;
    Vec3fNormalize(&sp1C);
    Vec3f_func_8001AC98(arg4, &sp1C);
}

s32 func_800E5AD4_63284(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, f32 arg4, Vec3f* arg5, Vec3f* arg6) {
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f unused;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 f0;
    f32 sp50;
    f32 sp4C;
    f32 f2;    
    f32 unused2;

    Vec3fDiff(&sp70, arg0, arg2);
    arg6->x = arg1->x;
    arg6->y = arg1->y;
    arg6->z = arg1->z;
    sp50 = Vec3fNormalize(arg6);
    sp7C.x = arg6->x;
    sp7C.y = arg6->y;
    sp7C.z = arg6->z;

    sp60 = SQ(sp7C.x) + SQ(sp7C.z) - SQ(sp7C.y);
    sp5C = sp7C.x * sp70.x + sp7C.z * sp70.z - sp7C.y * sp70.y;
    sp58 = SQ(sp70.x) + SQ(sp70.z) - SQ(sp70.y);

    if (!(ABS(sp60) < 0.0001f) && sp60 * sp58 <= SQ(sp5C)) {
        f2 = (-sp5C - sqrtf(SQ(sp5C) - sp60 * sp58)) / sp60;
        if (f2 > 0.0001f && sp4C < FLOAT_MAX) { // UB: sp4C uninitialized 
            f0 = f2 * sp7C.y + sp70.y;
            if (f0 >= 0.0f && f0 <= arg4 && f2 < sp50) {
                func_800E5A4C_631FC(&sp70, &sp7C, f2, arg5, arg6);
                sp50 *= 0.7f;
                Vec3fScale(arg6, sp50);
                Vec3fAdd(arg5, arg2);
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_800E5D30_634E0(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, UnkCaramelBoa* arg3, Vec3f* arg4, Vec3f* arg5) {
    f32 unused[4];
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;

    sp70.x = 0.0f;
    sp70.y = 0.0f;
    sp70.z = 0.0f;

    sp7C.x = arg0->x;
    sp7C.y = arg0->y;
    sp7C.z = arg0->z;

    sp64.x = arg1->x;
    sp64.y = arg1->y;
    sp64.z = arg1->z;

    func_800E4890_62040(arg3->unk_04->unk_44, &sp7C);
    func_800E4904_620B4(arg3->unk_04->unk_44, &sp64);

    sp54 = sqrtf(SQ(arg1->x) + SQ(arg1->y) + SQ(arg1->z));
    sp4C = sp54 / sqrtf(SQ(sp64.x) + SQ(sp64.y) + SQ(sp64.z));

    switch(arg3->unk_04->unk_00) {
        case 1:
            if (func_800E55C0_62D70(&sp7C, &sp64, &sp70, arg3->unk_04->unk_84, arg4, arg5)) {
                sp50 = sqrtf(SQ(arg5->x) + SQ(arg5->y) + SQ(arg5->z));
                func_800E4890_62040(arg3->unk_04->unk_04, arg4);
                func_800E4904_620B4(arg3->unk_04->unk_04, arg5);
                Vec3fNormalize(arg5);
                Vec3fScale(arg5, sp50 * sp4C);
                return TRUE;
            }
            break;
        case 3:
            if (func_800E5854_63004(&sp7C, &sp64, &sp70, arg3->unk_04->unk_84, arg3->unk_04->unk_88 * 0.5f, arg4, arg5)) {
                sp50 = sqrtf(SQ(arg5->x) + SQ(arg5->y) + SQ(arg5->z));
                func_800E4890_62040(arg3->unk_04->unk_04, arg4);
                func_800E4904_620B4(arg3->unk_04->unk_04, arg5);
                Vec3fNormalize(arg5);
                Vec3fScale(arg5, sp50 * sp4C);
                return TRUE;
            }
            break;
        case 2:
            if (func_800E5AD4_63284(&sp7C, &sp64, &sp70, arg3->unk_04->unk_84, arg3->unk_04->unk_88 * 0.5f, arg4, arg5)) {
                sp50 = sqrtf(SQ(arg5->x) + SQ(arg5->y) + SQ(arg5->z));
                func_800E4890_62040(arg3->unk_04->unk_04, arg4);
                func_800E4904_620B4(arg3->unk_04->unk_04, arg5);
                Vec3fNormalize(arg5);
                Vec3fScale(arg5, sp50 * sp4C);
                return TRUE;
            }
            break;
        case 4:
            if (1) { } if (1) { } if (1) { } // TODO fake match
            sp58.x = arg3->unk_04->unk_84;
            sp58.y = arg3->unk_04->unk_88;
            sp58.z = arg3->unk_04->unk_8C;
            if (func_800E5094_62844(&sp7C, &sp64, -sp58.x, sp58.x, -sp58.y, sp58.y, -sp58.z, sp58.z, arg4, arg5)) {
                sp50 = sqrtf(SQ(arg5->x) + SQ(arg5->y) + SQ(arg5->z));
                func_800E4890_62040(arg3->unk_04->unk_04, arg4);
                func_800E4904_620B4(arg3->unk_04->unk_04, arg5);
                Vec3fNormalize(arg5);
                Vec3fScale(arg5, sp50 * sp4C);
                return TRUE;
            }
            break;
        default:
            return FALSE;
    }
    return FALSE;
}

UnkCaramelBoa* func_800E6168_63918(UnkCaramelBoa* arg0) {
    s32 v0 = 100;
    UnkCaramelBoa* cur = arg0;
    UnkCaramelBoa* ret = NULL;

    while (cur->unk_00 != 18) {
        if (cur->unk_04 != NULL && cur->unk_00 < v0 && cur->unk_04->unk_00 == 1) {
            ret = cur;
            v0 = cur->unk_00;
        }
        cur++;
    }

    return ret;
}

s32 func_800E61CC_6397C(UnkCaramelBoa* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3) {
    f32 temp = arg0->unk_04->unk_84 * arg0->scale.x * arg3;

    if (SQ(arg1->x - arg2->x) + SQ(arg1->z - arg2->z) < SQ(temp)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

s32 func_800E6238_639E8(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {    
    UnkCeruleanComodo* sp18C;
    UnkCeruleanComodo* sp188;
    UnkCeruleanComodo* sp17C[3];
    f32 unused[4];
    UnkCaramelBoa* s0;
    UnkCaramelBoa* v0;
    Vec3f sp158;
    Vec3f sp14C;
    s32 i;
    s32 j;
    Vec3f sp138;
    Vec3f sp12C;
    Mtx4f spEC;
    Mtx4f spAC;
    UnkBeigeServal* s6;
    f32 f20;
    f32 f12;

    if (D_800E6B40_642F0 == NULL) {
        return -1;
    }

    sp18C = func_800E2184_5F934();
    if (sp18C == NULL || sp18C->unk4 == NULL) {
        return -1;
    }

    sp17C[0] = sp18C->unk8;
    sp17C[1] = sp18C;
    sp17C[2] = sp18C->unkC;

    for (j = 0; j < ARRAY_COUNT(sp17C); j++) {
        sp188 = sp17C[j];
        if (sp188 == NULL || sp188->unk4 == NULL || sp188->unk4->unk20 == NULL) {
            continue;
        }

        s6 = sp188->unk4->unk20;
        while (s6->unk_00 != -1) {
            for (i = 0; i < 100; i++) {
                if (D_800E6B40_642F0[i].unk_00 == -1) {
                    break;
                }
                if (D_800E6B40_642F0[i].unk_04 != NULL && D_800E6B40_642F0[i].unk_00 == s6->unk_00) {
                    sp158.x = s6->unk_04.x + (sp188->unk4->unk4.x - sp18C->unk4->unk4.x);
                    sp158.y = s6->unk_04.y + (sp188->unk4->unk4.y - sp18C->unk4->unk4.y);
                    sp158.z = s6->unk_04.z + (sp188->unk4->unk4.z - sp18C->unk4->unk4.z);

                    sp138.x = arg0->x / 100.0f;
                    sp138.y = arg0->y / 100.0f;
                    sp138.z = arg0->z / 100.0f;

                    sp12C.x = arg1->x / 100.0f;
                    sp12C.y = arg1->y / 100.0f;
                    sp12C.z = arg1->z / 100.0f;

                    f12 = Vec3fNormalize(&sp12C);
                    if (ABS(f12) < 0.1f) {
                        f12 = 0.1f;
                    }
                    Vec3fScale(&sp12C, f12);

                    if (D_800E6B40_642F0[i].unk_08 > 0.0f) {
                        sp14C.x = sp14C.y = f20 = sp14C.z = D_800E6B40_642F0[i].unk_08;
                    } else {
                        sp14C.x = f20 = s6->unk_1C.x;
                        sp14C.y = s6->unk_1C.y;
                        sp14C.z = s6->unk_1C.z;
                    }

                    v0 = func_800E6168_63918(D_800E6B40_642F0[i].unk_04);
                    if (v0 != NULL && func_800E61CC_6397C(v0, &sp138, &sp158, f20)) {
                        func_800E4C64_62414(spEC, spAC, sp14C, s6->unk_10, sp158);
                        func_800E4890_62040(spAC, &sp138);
                        func_800E4904_620B4(spAC, &sp12C);

                        s0 = D_800E6B40_642F0[i].unk_04;
                        while (s0->unk_00 != 18) {
                            if (s0 != v0 && s0->unk_04 != NULL && func_800E5D30_634E0(&sp138, &sp12C, &sp158, s0, arg2, arg3)) {
                                func_800E4890_62040(spEC, arg2);
                                func_800E4904_620B4(spEC, arg3);

                                arg2->x *= 100.0f;
                                arg2->y *= 100.0f;
                                arg2->z *= 100.0f;

                                arg3->x *= 100.0f;
                                arg3->y *= 100.0f;
                                arg3->z *= 100.0f;

                                return s6->unk_00;
                            }        
                            s0++;
                        }
                    }
                }
            }
            s6++;
        }
    }

    return -1;
}

void func_800E66BC_63E6C(UnkChestnutCougar* arg0) {
    s32 i;
    UnkCaramelBoa* s0;
    s32 sp44;
    s32 unused[2];

    D_800E6B40_642F0 = arg0;
    if (D_800E6B40_642F0 == NULL) {
        return;
    }

    for (i = 0; i < 100; i++) {
        if (D_800E6B40_642F0[i].unk_00 == -1) {
            break;
        }

        s0 = D_800E6B40_642F0[i].unk_04;
        if (s0 != NULL) {
            sp44 = -1;
            while (s0->unk_00 != 18) {
                func_800E4E98_62648(s0, &sp44);
                s0++;
            }
        }            
    }
}

void func_800E6778_63F28(UnkChestnutCougar* arg0) {
    UnkCaramelBoa* s0;
    s32 unused;
    s32 sp44;
    s32 unused2[3];

    s0 = arg0->unk_04;
    if (s0 != NULL) {
        sp44 = -1;
        while (s0->unk_00 != 18) {
            func_800E4E98_62648(s0, &sp44);
            s0++;
        }
    }    
}

s32 func_800E67E4_63F94(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, UnkChestnutCougar* arg4, Vec3f arg5, Vec3f arg8) {
    UnkCaramelBoa* v0;
    UnkCaramelBoa* s0;
    Vec3f sp114;
    Vec3f sp108;
    f32 f12;
    Vec3f spF8;
    Vec3f spEC;
    Mtx4f spAC;
    Mtx4f sp6C;
    f32 sp68;
    

    sp114.x = arg5.x / 100.0f;
    sp114.y = arg5.y / 100.0f;
    sp114.z = arg5.z / 100.0f;

    spF8.x = arg0->x / 100.0f;
    spF8.y = arg0->y / 100.0f;
    spF8.z = arg0->z / 100.0f;

    spEC.x = arg1->x / 100.0f;
    spEC.y = arg1->y / 100.0f;
    spEC.z = arg1->z / 100.0f;

    f12 = Vec3fNormalize(&spEC);
    if (ABS(f12) < 0.1f) {
        f12 = 0.1f;
    }
    Vec3fScale(&spEC, f12);
    sp68 = sp108.x = sp108.y = sp108.z = arg4->unk_08;
    
    v0 = func_800E6168_63918(arg4->unk_04);
    if (v0 == NULL) {
        return FALSE;
    }
    if (!func_800E61CC_6397C(v0, &spF8, &sp114, sp68)) {
        return FALSE;
    }

    func_800E4C64_62414(spAC, sp6C, sp108, arg8, sp114);
    func_800E4890_62040(sp6C, &spF8);
    func_800E4904_620B4(sp6C, &spEC);

    s0 = arg4->unk_04;
    while (s0->unk_00 != 18) {
        if (s0 != v0 && s0->unk_04 != NULL && func_800E5D30_634E0(&spF8, &spEC, &sp114, s0, arg2, arg3)) {
            func_800E4890_62040(spAC, arg2);
            func_800E4904_620B4(spAC, arg3);

            arg2->x *= 100.0f;
            arg2->y *= 100.0f;
            arg2->z *= 100.0f;

            arg3->x *= 100.0f;
            arg3->y *= 100.0f;
            arg3->z *= 100.0f;

            return TRUE;
        }        
        s0++;
    }
    return FALSE;
}
