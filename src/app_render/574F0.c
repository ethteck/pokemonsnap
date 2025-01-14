#include "common.h"

u8 D_800BF050;
s8 D_800BF051;

void func_800ABB40(void) {
    D_800BF050 = 0;
}

void func_800ABB4C(u8 flags) {
    D_800BF050 |= flags;
}

u8 func_800ABB68(void) {
    return D_800BF050;
}

void func_800ABB74(u8 flags) {
    D_800BF050 &= ~flags;
}

void func_800ABB94(void) {
    if (sControllerIndices[0] == 0) {
        D_800BF051 = 0;
    } else {
        D_800BF051 = -1;
    }
}
