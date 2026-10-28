#include <common.h>
#include <PR/sp.h>

#include "build/assets/menu_new_game/new_game_bg.png.inc.h"

static u8 aligner_0[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

#include "build/assets/menu_new_game/new_game_card.png.inc.h"

#include "build/assets/menu_new_game/new_game_cursor.png.inc.h"

// .bss
Gfx new_game_bg_dl[0xFC0 / sizeof(Gfx)];
Gfx new_game_card_dl[0xDE0 / sizeof(Gfx)];
Gfx new_game_cursor_dl[0x120 / sizeof(Gfx)];
