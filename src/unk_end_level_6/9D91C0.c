#include "common.h"

#include "unk_end_level/unk_end_level.h"
#include "unk_end_level_6.h"

typedef struct Unk8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x4];
} Unk8;

extern s32 D_80202EC0_9F9830;
extern UNK_TYPE D_80202EC8_9F9838;
extern UNK_TYPE D_80202EF8_9F9868;
extern UNK_TYPE D_80202F20_9F9890;
extern UNK_TYPE D_80202F48_9F98B8;
extern UNK_TYPE D_80202F68_9F98D8;
extern UNK_TYPE D_80202FA8_9F9918;
extern UNK_TYPE D_80202FC0_9F9930;
extern s32 D_80203008_9F9978;
extern s32 D_8020300C_9F997C;
extern UNK_PTR D_80230E10_A27780;
extern UnkCanaryScallop* D_80230E14_A27784;

UNK_PTR func_801E2850_9D91C0(void) {
    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        return &D_80202EC8_9F9838;
    } else {
        return &D_80202EF8_9F9868;
    }
}

UNK_PTR func_801E28A0_9D9210(s32 arg0) {
    if (!arg0) {
        return &D_80202F20_9F9890;
    } else {
        return &D_80202F48_9F98B8;
    }
}

s32 func_801E28D8_9D9248(UnkStruct800BEDF8* arg0, s32* arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E28D8_9D9248.s")

void func_801E2AC0_9D9430(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E2AC0_9D9430.s")

void func_801E2CF8_9D9668(UnkStruct800BEDF8* arg0, s32* arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E2CF8_9D9668.s")

s32 func_801E2EB0_9D9820(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E2EB0_9D9820.s")

s32 func_801E3000_9D9970(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E3000_9D9970.s")

s32 func_801E3604_9D9F74(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E3604_9D9F74.s")

s32 func_801E38DC_9DA24C(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_6/9D91C0/func_801E38DC_9DA24C.s")

void func_801E3B18_9DA488(void) {
    UNUSED s32 pad;
    u32 sp18;

    sp18 = 0;
    D_80230E10_A27780 = func_801E2850_9D91C0();
    D_80230E14_A27784 = func_80370600_843DB0();
    func_80370134_8438E4();
    D_80202EC0_9F9830 = 0;
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);

    while (true) {
        switch (sp18) {
            case 0:
                sp18 = func_801E2EB0_9D9820();
                break;
            case 1:
                sp18 = func_801E3000_9D9970();
                break;
            case 2:
                sp18 = func_801E3604_9D9F74();
                break;
            case 3:
                sp18 = func_801E38DC_9DA24C();
                break;
            case 5:
                return;
        }
    }
}
