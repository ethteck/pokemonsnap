#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FC80/func_802DEA80_72FC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FC80/func_802DEAFC_72FCFC.s")

extern idFuncStruct D_802E3474_734674;

void func_802DEBB0_72FDB0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802E3474_734674;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FC80/func_802DEBF0_72FDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FC80/func_802DEC78_72FE78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FC80/func_802DED34_72FF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FC80/func_802DED6C_72FF6C.s")
