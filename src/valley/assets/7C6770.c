#include "valley/valley.h"

/* initMap fixes signed BSP indices into pointers at runtime. */
HeightMapPatch D_802ED1E0_7C6770[4309] = {
#include "valley/assets/7C6770_7C6770.inc.c"
};

HeightMapTreeNode D_80302284_7DB814[4308] = {
#include "valley/assets/7C6770_7DB814.inc.c"
};

char D_8031F9B4_7F8F44_padding[12] = "";
HeightMap D_8031F9C0_7F8F50 = { D_802ED1E0_7C6770, D_80302284_7DB814 };
char D_8031F9C8_7F8F58_padding[8] = "";
