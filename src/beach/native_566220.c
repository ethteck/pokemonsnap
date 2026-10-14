#include "native_566220.h"

/* Writable native height map in original physical ROM order.
 * The ground system mutates encoded BSP indices during initialization. */
HeightMapPatch beach_566220_height_patches[6386] = {
#include "native_566220_patches.inc.c"
};

HeightMapTreeNode beach_566220_height_tree[6385] = {
#include "native_566220_tree.inc.c"
};

/* Original zero-filled alignment between BSP nodes and HeightMap root. */
char beach_566220_tree_alignment[12] = "";

HeightMap beach_566220_height_map = { beach_566220_height_patches, beach_566220_height_tree };

/* Original zero-filled trailing bank alignment. */
char beach_566220_tail_alignment[8] = "";
