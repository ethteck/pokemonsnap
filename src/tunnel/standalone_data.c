#include "tunnel.h"

/* BSP child/patch indices are fixed up by initMap, not addresses. */
HeightMapPatch D_802F0420_5ED4F0[4008] = {
#include "tunnel/D_802F0420_5ED4F0.hm.inc.c"
};

HeightMapTreeNode D_80303D40_600E10[4007] = {
#include "tunnel/D_80303D40_600E10.hm.inc.c"
};

u8 heightmapPadding_61C454[12] = { 0 };

HeightMapPatch D_8031F390_61C460[658] = {
#include "tunnel/D_8031F390_61C460.hm.inc.c"
};

HeightMapTreeNode D_803226F8_61F7C8[657] = {
#include "tunnel/D_803226F8_61F7C8.hm.inc.c"
};

u8 heightmapPadding_623FA4[12] = { 0 };

HeightMap D_80326EE0_623FB0 = { D_802F0420_5ED4F0, D_80303D40_600E10 };

HeightMap D_80326EE8_623FB8 = { D_8031F390_61C460, D_803226F8_61F7C8 };
