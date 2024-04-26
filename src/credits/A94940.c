#include "common.h"

typedef struct UnkTealGrouper UnkTealGrouper;
struct UnkTealGrouper {
    u8 pad_00[0x8];
    UnkTealGrouper* var_8;
    u8 pad_C[0xC];
    f32 var_18;
    f32 var_1C;
};

extern s32 D_credits_801ECDA0;
extern u8 D_credits_801ECDA3;
extern s32 D_credits_801ECDA8;
extern s32 D_credits_801ECDB0[];

void func_80374714(void*, s32);
void func_credits_801DDF48(GObj*);
void func_credits_801DDE24(GObj*);
void func_credits_801DDAE8(u8);
void func_credits_801DDC70(void);
void func_credits_801DDD80(void);
void func_credits_801DE734(s32);
void func_credits_801DE7B4(s32);
void func_credits_801DCF94(void);
void func_credits_801DE060(void);
void func_credits_801DE35C(void);

void func_credits_801DDD80(void) {
    s32* var_v0;
    u32 var_s0;

    D_credits_801ECDA8 = 0;
    var_v0 = D_credits_801ECDB0;
    for (var_s0 = 0; var_s0 < 0x98; var_s0++) {
        *var_v0++ = 0x3E7;
    }

    for (var_s0 = 0; var_s0 < 0x98; var_s0++) {
        if (func_800BF710_5C5B0(var_s0) != NULL) {
            D_credits_801ECDB0[D_credits_801ECDA8] = var_s0;
            D_credits_801ECDA8 += 1;
        }
    }
}

#if 0
// TODO: This should match when rodata is moved
void func_credits_801DEA30(SObj*, f32); /* extern */
void func_credits_801DEB74(SObj*, f32); /* extern */
extern f32 D_credits_801E9A84; // 0.1000000015
void func_credits_801DDE24(GObj* arg0) {
    SObj* temp_s0;
    f32 scale;
    f32 temp_f22;

    temp_s0 = arg0->data.sobj;
    auPlaySoundWithParams(0x47U, 0x7FFF, 0x40, 1.0, 0xF);
    temp_f22 = 0.1000000015;

    scale = 4.0f;
    while (temp_s0->sprite.scalex > 1.0f) {
        scale -= temp_f22;
        ohWait(1);
        func_credits_801DEB74(temp_s0, scale);
        func_credits_801DEA30(temp_s0, scale);
    }
    func_credits_801DEA30(temp_s0, 1.0);
    func_credits_801DEB74(temp_s0, 1.0);
    ohWait(1);
    omEndProcess(NULL);

    while (1) {
        ohWait(1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/credits/A94940/func_credits_801DDE24.s")
#endif

void func_credits_801DDF1C(GObj* arg0) {
    omCreateProcess(arg0, func_credits_801DDE24, 0U, 1U);
}

void func_credits_801DDF48(GObj* arg0) {
    SObj* temp_s1;
    SObj* var_v0;
    s16 var_s0;

    temp_s1 = arg0->data.sobj;
    auPlaySoundWithParams(0x50U, 0x7FFF, 0x40, 1.0f, 0xF);

    var_s0 = 0xA;
    while (temp_s1->sprite.y < 0x12C) {
        for (var_v0 = temp_s1; var_v0 != NULL; var_v0 = var_v0->next) {
            var_v0->sprite.y += var_s0;
        }

        var_s0++;
        ohWait(1);
    }

    for (var_v0 = temp_s1; var_v0 != NULL; var_v0 = var_v0->next) {
        var_v0->sprite.attr |= 4;
    }
    omEndProcess(NULL);

    while (1) {
        ohWait(1);
    }
}

void func_credits_801DE034(GObj* arg0) {
    omCreateProcess(arg0, func_credits_801DDF48, 0U, 1U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A94940/func_credits_801DE060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A94940/func_credits_801DE35C.s")

void func_credits_801DE734(s32 arg0) {
    switch (D_credits_801ECDA0) {
        case 18:
            func_credits_801DE060();
            return;
        case 17:
        case 20:
            func_credits_801DCF94();
            func_credits_801DE060();
            return;
        case 19:
            func_credits_801DE35C();
            return;
    }
}

void func_credits_801DE7B4(s32 arg0) {
    auSetBGMVolume(0, 0x7F00);
    switch (arg0) {
        case 18:
            auPlaySong(0, 0xB);
            return;
        case 19:
            auPlaySong(0, 0x24);
            return;
        case 17:
        case 20:
            auPlaySong(0, 0xB);
            return;
    }
}

void func_credits_801DE844(s32 arg0) {
    func_credits_801DE7B4(D_credits_801ECDA0);
    func_credits_801DDD80();
    func_credits_801DDAE8(D_credits_801ECDA3);
    func_credits_801DDC70();
    func_credits_801DE734(arg0);
    func_800067DC();
    ohWait(1);
}

void func_credits_801DE8A0(s32 arg0, s32 arg1) {
    void* temp_v0;

    temp_v0 = func_800BF710_5C5B0(arg1);
    if (temp_v0 != NULL) {
        func_80374714(temp_v0, arg0 + 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A94940/func_credits_801DE8D8.s")

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/credits/A94940/func_credits_801DEA30.s")
#else
void func_credits_801DEA30(SObj* arg0, f32 arg1) {
    SObj* temp_v1;
    f32 temp_f0;
    s16 temp_f10;
    s16 temp_f6;
    f32 i;

    temp_f0 = 70.0f * arg1;
    arg0->sprite.x = (s16) (s32) (160.0f - temp_f0);
    arg0->sprite.y = (s16) (s32) (120.0f - (52.0f * arg1));
    temp_f10 = (255.0f - ((arg1 - 1.0f) * 53.0f));
    temp_f6 = (3.0f * arg1);
    arg0->sprite.blue = temp_f10;
    arg0->sprite.green = temp_f10;
    arg0->sprite.red = temp_f10;

    temp_v1 = arg0->next;
    temp_v1->sprite.x = arg0->sprite.x - temp_f6;
    temp_v1->sprite.y = arg0->sprite.y - temp_f6;

    temp_v1 = temp_v1->next;
    temp_v1->sprite.x = arg0->sprite.x + (s32) (140.0f * arg1);
    temp_v1->sprite.y = arg0->sprite.y - temp_f6;

    temp_v1 = temp_v1->next;
    i = 0xA0 - temp_f0;
    temp_v1->sprite.x = i;
    temp_v1->sprite.y = arg0->sprite.y - temp_f6;

    temp_v1 = temp_v1->next;
    temp_v1->sprite.x = i;
    temp_v1->sprite.y = arg0->sprite.y + (s32) (105.0f * arg1);
}
#endif

void func_credits_801DEB74(SObj* arg0, f32 arg1) {
    while (arg0 != NULL) {
        arg0->sprite.scalex = arg1;
        arg0->sprite.scaley = arg1;
        arg0 = arg0->next;
    }
}
