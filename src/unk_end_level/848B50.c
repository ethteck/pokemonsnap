#include "common.h"

extern UNK_TYPE D_803A66D0_879E80;
extern UNK_TYPE D_803A6718_879EC8;

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/848B50/func_803753A0_848B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/848B50/func_803753B8_848B68.s")

UNK_TYPE* func_803753D0_848B80(s32 arg0) {
    switch (arg0) {
        case 0:
            return &D_803A66D0_879E80;
        case 1:
            return &D_803A6718_879EC8;
    }
}
