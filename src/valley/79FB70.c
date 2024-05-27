#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79FB70/func_802C65E0_79FB70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79FB70/func_802C6610_79FBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79FB70/func_802C6630_79FBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79FB70/func_802C66A4_79FC34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79FB70/func_802C673C_79FCCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79FB70/func_802C67F4_79FD84.s")

void func_802C65E0_79FB70(GObj*);
void func_802C67F4_79FD84(GObj*);
extern GObj* D_802D2A84_7AC014;

void func_802C6AD4_7A0064(void) {
    GObj* obj;

    obj = func_80365E80_506290();
    D_802D2A84_7AC014 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_802C67F4_79FD84, 0, 1);
        func_802C65E0_79FB70(obj);
    }
}
