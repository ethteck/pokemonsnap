#include "common.h"
#include "string.h"

typedef struct Struct_800BEFD8 {
    /* 0x00 */ GObj* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
} Struct_800BEFD8; // size = 0x18

extern Struct_800BEFD8 D_800BEFD8[];

void func_800AAF20(void) {
    s32 i;

    auSetSoundGlobalReverb(0);
    auSetBGMExtraReverb(BGM_PLAYER_MAIN, 0);
    auSetBGMExtraReverb(BGM_PLAYER_AUX, 0);
    auStopBGM();
    auSetBGMVolume(BGM_PLAYER_MAIN, 0x7F00);
    auSetBGMVolume(BGM_PLAYER_AUX, 0x7F00);
    auSetSoundGlobalVolume(0x7F);
    for (i = 0; i < 16; i++)
        auSetBGMChannelVolume(BGM_PLAYER_MAIN, i, 0x7F);
}

s8 func_800AAFB0(s16 arg0, s16 arg1, f32 arg2) {
    return ((f32)arg1 - (f32)arg0) * arg2 + arg0;
}

s16 func_800AB000(s16 arg0, s16 arg1, f32 arg2) {
    return ((f32)arg1 - (f32)arg0) * arg2 + arg0;
}

void func_800AB050(f32 arg0, s32 arg1, Struct_800AB050* arg2, Struct_800AB050* arg3, Struct_800AB050* arg4) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg2[i].unk_00 = func_800AB000(arg3[i].unk_00, arg4[i].unk_00, arg0);
        arg2[i].unk_02 = func_800AB000(arg3[i].unk_02, arg4[i].unk_02, arg0);
        arg2[i].unk_04 = func_800AB000(arg3[i].unk_04, arg4[i].unk_04, arg0);
        arg2[i].unk_0C = func_800AAFB0(arg3[i].unk_0C, arg4[i].unk_0C, arg0);
        arg2[i].unk_0D = func_800AAFB0(arg3[i].unk_0D, arg4[i].unk_0D, arg0);
        arg2[i].unk_0E = func_800AAFB0(arg3[i].unk_0E, arg4[i].unk_0E, arg0);
    }
}

s32 func_800AB138(EggStruct* arg0, f32 arg1) {
    s32 n;
    Struct_800AB050* next;
    
    n = arg0->timer;
    next = arg0->tempBuffer[n + 1];
    func_800AB050(arg0->timer - n, arg0->vertexCount, arg0->data, arg0->tempBuffer[n], next);
    arg0->timer += arg1;
    if ((s32)arg0->timer >= arg0->end - 1) {
        arg0->timer = arg0->end - 2 + 0.9999f;
        return FALSE;
    } else {
        return TRUE;
    }
}

void func_800AB1F8(EggStruct* arg0) {
    memcpy(arg0->tempBuffer[0], arg0->data, arg0->vertexCount * sizeof(Struct_800AB050));
    arg0->timer = 0.0f;
}

#ifdef NON_MATCHING
void func_800AB240(GObj* obj) {
    while (TRUE) {
        Struct_800BEFD8* entry = &D_800BEFD8[(s32)obj->userData];
        f32 unk_08 = entry->unk_08;
        f32 unk_0C = entry->unk_0C;
        f32 unk_10 = entry->unk_10;
        f32 unk_14 = entry->unk_14;
        auSetSoundPan(entry->unk_04, unk_08 + (unk_0C - unk_08) * unk_10 / unk_14);
        if (entry->unk_10 >= entry->unk_14) {
            entry->unk_04 = 0;
            entry->unk_08 = 0;
            entry->unk_0C = 0;
            entry->unk_10 = 0;
            entry->unk_14 = 0;
            omDeleteGObj(obj);
            entry->unk_00 = NULL;
            ohWait(1);
        } else {
            entry->unk_10++;
        }
        ohWait(1);
    }
}
#else
void func_800AB240(GObj* obj);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB240.s")
#endif

#ifdef NON_MATCHING
s32 func_800AB41C(s32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_800BEFD8[i].unk_00 != NULL) {
            continue;
        }

        if (arg1 > 127) {
            arg1 = 127;
        }
        if (arg2 > 127) {
            arg2 = 127;
        }

        D_800BEFD8[i].unk_04 = arg0;
        D_800BEFD8[i].unk_08 = arg1;
        D_800BEFD8[i].unk_0C = arg2;
        D_800BEFD8[i].unk_10 = 0;
        D_800BEFD8[i].unk_14 = arg3;
        D_800BEFD8[i].unk_00 = omAddGObj(14, NULL, LINK_0, 0x80000000);
        D_800BEFD8[i].unk_00->userData = (void*)i;
        omCreateProcess(D_800BEFD8[i].unk_00, func_800AB240, 0, 1);
        return 0;
    }
    return -1;
}
#else
s32 func_800AB41C(s32 arg0, u32 arg1, u32 arg2, s32 arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB41C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/568D0/func_800AB9A4.s")
