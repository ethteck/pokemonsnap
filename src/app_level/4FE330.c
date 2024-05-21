#include "common.h"
#include "world/world.h"

extern AnimationHeader D_80388310_528720;
extern PokemonInitData D_80388348_528758;

void func_8035E034_4FE444(GObj*);
void func_8035DFB0_4FE3C0(GObj*);

void func_8035DF20_4FE330(GObj* arg0) {
    s32 unused[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    if (pokemon->behavior == 1) {
        updatePokemonState(arg0, func_8035E034_4FE444);
    }
    setPokemonAnimation(arg0, &D_80388310_528720);
    runPathProcess(arg0, func_8035DFB0_4FE3C0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(arg0, 1);
    runPokemonCleanup(arg0);
    updatePokemonState(arg0, NULL);
}

void func_8035DFB0_4FE3C0(GObj* arg0) {
    s32 unused[2];
    DObj* model = arg0->data.dobj;
    Pokemon* pokemon = GET_POKEMON(arg0);
    s32 i;

    for (i = 59; i > 0; i--) {
        model->position.v.y -= 0.2f;
        ohWait(1);
    }

    pokemon->processFlags |= 2;
    pokemon->pathProcess = NULL;
    omEndProcess(NULL);
}

void func_8035E034_4FE444(GObj* arg0) {
    s32 unused[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    pokemon->tangible = FALSE;
    arg0->flags |= 3;
    pokemon->miscVars[0].field1 = 0;
    do {
        ohWait(1);
    } while (pokemon->miscVars[0].field1 == 0);
    pokemon->tangible = TRUE;
    arg0->flags = 0;
    forcePokemonAnimation(arg0, &D_80388310_528720);
    runPathProcess(arg0, &func_8035DFB0_4FE3C0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(arg0, 1);
    updatePokemonState(arg0, func_8035E034_4FE444);
}

void func_8035E0D4_4FE4E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* arg3, ObjectSpawn* arg4) {
    func_80362E10_503220(objID, id, block, arg3, arg4, &D_80388348_528758);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E10C_4FE51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E174_4FE584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E1D4_4FE5E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E238_4FE648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E264_4FE674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E298_4FE6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E370_4FE780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E37C_4FE78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E4D0_4FE8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E508_4FE918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E52C_4FE93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E754_4FEB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E764_4FEB74.s")
