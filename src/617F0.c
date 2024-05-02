#include "common.h"
#include "level_low.h"

typedef struct UnkMagentaCrocodile {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} UnkMagentaCrocodile; // size >= 0x08

typedef struct UnkBurgundyOcelot {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
} UnkBurgundyOcelot; // size >= 0x14

extern UnkMagentaCrocodile* D_800E6B30_642E0;
extern UnkMagentaCrocodile* D_800E6B34_642E4;
void func_800E4634_61DE4(s32, s32);
s32 func_800E4670_61E20(s32, f32, f32);
f32 func_800E4734_61EE4(s32, f32, f32);
Vec3f* func_800E47C4_61F74(s32 arg0);
s32 func_800E4820_61FD0(s32);

s32 func_800E4040_617F0(UnkMagentaCrocodile* arg0) {
    s32 unk_00;
    s32 unk_04;

    if (arg0 == NULL) {
        return FALSE;
    }
    if (arg0->unk_04 == 0 || arg0->unk_00 == 0) {
        return FALSE;
    }
    D_800E6B30_642E0 = arg0;
    unk_04 = D_800E6B30_642E0->unk_04;
    unk_00 = D_800E6B30_642E0->unk_00;    
    func_800E4634_61DE4(unk_04, unk_00);
    return TRUE;
}

s32 func_800E40A4_61854(UnkMagentaCrocodile* arg0) {
    s32 unk_00;
    s32 unk_04;

    if (arg0 == NULL) {
        return FALSE;
    }
    if (arg0->unk_04 == 0 || arg0->unk_00 == 0) {
        return FALSE;
    }
    D_800E6B34_642E4 = arg0;
    unk_04 = D_800E6B34_642E4->unk_04;
    unk_00 = D_800E6B34_642E4->unk_00;    
    func_800E4634_61DE4(unk_04, unk_00);
    return TRUE;
}

void func_800E4108_618B8(UnkBurgundyOcelot* arg0) {
    arg0->unk_00 = -9000.0f;
    arg0->unk_04 = 0.0f;
    arg0->unk_08 = 1.0f;
    arg0->unk_0C = 0.0f;
    arg0->unk_10 = -1;
}

s32 func_800E4138_618E8(f32 arg0, f32 arg1, UnkBurgundyOcelot* arg2) {
    s32 sp24;
    Vec3f* v0;

    if (D_800E6B30_642E0 == NULL) {
        func_800E4108_618B8(arg2);
        return FALSE;
    }

    sp24 = func_800E4670_61E20(D_800E6B30_642E0->unk_04, arg0, arg1);
    arg2->unk_00 = func_800E4734_61EE4(sp24, arg0, arg1);
    v0 = func_800E47C4_61F74(sp24);
    arg2->unk_04 = v0->x;
    arg2->unk_08 = v0->z;
    arg2->unk_0C = v0->y; // BUG maybe ?
    arg2->unk_10 = func_800E4820_61FD0(sp24);
    return TRUE;
}

s32 func_800E41D8_61988(f32 arg0, f32 arg1, UnkBurgundyOcelot* arg2) {
    WorldBlock* block = getCurrentWorldBlock();

    if (block == NULL || block->descriptor == NULL || D_800E6B30_642E0 == NULL) {
        func_800E4108_618B8(arg2);
        return FALSE;
    }

    arg0 /= 100.0f;
    arg1 /= 100.0f;
    arg0 = arg0 + block->descriptor->unk_04.x;
    arg1 = arg1 + block->descriptor->unk_04.z;
    if (!func_800E4138_618E8(arg0, arg1, arg2)) {
        func_800E4108_618B8(arg2);
        return FALSE;
    }

    arg2->unk_00 -= block->descriptor->unk_04.y;
    arg2->unk_00 *= 100.0f;
    return TRUE;
}

s32 func_800E42BC_61A6C(f32 arg0, f32 arg1, UnkBurgundyOcelot* arg2) {
    s32 sp24;
    Vec3f* v0;

    if (D_800E6B34_642E4 == NULL) {
        func_800E4108_618B8(arg2);
        return FALSE;
    }

    sp24 = func_800E4670_61E20(D_800E6B34_642E4->unk_04, arg0, arg1);
    arg2->unk_00 = func_800E4734_61EE4(sp24, arg0, arg1);
    v0 = func_800E47C4_61F74(sp24);
    arg2->unk_04 = v0->x;
    arg2->unk_08 = v0->z;
    arg2->unk_0C = v0->y; // BUG maybe ?
    arg2->unk_10 = func_800E4820_61FD0(sp24);
    return TRUE;
}

s32 func_800E435C_61B0C(f32 arg0, f32 arg1, UnkBurgundyOcelot* arg2) {
    WorldBlock* block;

    if (D_800E6B34_642E4 == NULL) {
        return FALSE;
    }

    block = getCurrentWorldBlock();
    if (block == NULL || block->descriptor == NULL || D_800E6B34_642E4 == NULL) {
        func_800E4108_618B8(arg2);
        return FALSE;
    }

    arg0 /= 100.0f;
    arg1 /= 100.0f;
    arg0 = arg0 + block->descriptor->unk_04.x;
    arg1 = arg1 + block->descriptor->unk_04.z;
    if (!func_800E42BC_61A6C(arg0, arg1, arg2)) {
        func_800E4108_618B8(arg2);
        return FALSE;
    }

    arg2->unk_00 -= block->descriptor->unk_04.y;
    arg2->unk_00 *= 100.0f;
    return TRUE;
}
