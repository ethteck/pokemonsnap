#include "common.h"

char D_803A66D0_879E80[] = "どの  しゃしんを  アルバムに\nのこしますか\n〜あと  %sまい  のこせます〜";
char D_803A6718_879EC8[] = "どの  しゃしんを  アルバムに\nのこしますか\n〜これいじょう  のこせません〜";

char* func_803753D0_848B80(s32 arg0) {
    switch (arg0) {
        case 0:
            return D_803A66D0_879E80;
        case 1:
            return D_803A6718_879EC8;
    }
}
