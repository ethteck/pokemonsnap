#include "common.h"
#include "window.h"
#include "string.h"
#include "ultralib/src/libc/xstdio.h"

extern s32 D_803A66A0_879E50[];
extern s32 D_803A66BC_879E6C;
extern s32 D_803A66C0_879E70; // song id
extern s32 D_803A66C4_879E74;
extern GObj* D_803A66C8_879E78;
extern char D_803A7010_87A7C0[];

s32 func_80374F30_8486E0(UIElement* arg0, bool arg1) {
    s32 button;
    UnkStruct800BEDF8* var_v0;

    button = 0;
    UIElement_SetTextPos(arg0, 180, 32);
    UIElement_PrintText(arg0, "\\l");
    func_8036EB80_842330(0);
    ohWait(1);
    var_v0 = func_800AA38C(0);
    while (!(var_v0->pressedButtons & (A_BUTTON | B_BUTTON))) {
        ohWait(1);
        var_v0 = func_800AA38C(0);
    }
    if (var_v0->currentButtons & A_BUTTON) {
        button = A_BUTTON;
    }
    if (var_v0->currentButtons & B_BUTTON) {
        button = B_BUTTON;
    }
    if (var_v0->currentButtons & START_BUTTON) {
        button = START_BUTTON;
    }
    if (arg1) {
        auPlaySound(0x4D);
    }
    ohWait(1);
    UIElement_Draw(arg0);
    func_8036EB80_842330(1);
    return button;
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/8486E0/func_8037501C_8487CC.s")

// string comparator used for pokemon names
s32 func_803750CC_84887C(char* arg0, char* arg1) {
    s32 diff;

    if (arg0 == NULL || arg1 == NULL) {
        return 0;
    }

    while (true) {
        diff = *arg0 - *arg1;
        if (diff != 0) {
            return diff;
        }

        // If strings haven't ended (null terminator), increment to next char and loop
        if (*arg0 != 0 && *arg1 != 0) {
            arg0++;
            arg1++;
        } else {
            return 0;
        }
    }
}

char* func_80375128_8488D8(char* dest, const char* src, size_t len) {
    return (char*) memcpy(dest, src, len) + len;
}

s32 func_8037514C_8488FC(char* str, const char* fmt, va_list args) {
    s32 len;

    len = _Printf(func_80375128_8488D8, str, fmt, args);
    if (len >= 0) {
        str[len] = 0;
    }
    return len;
}

s32 func_8037519C_84894C(UIElement* arg0, const char* fmt, ...) {
    s32 temp_v0;
    va_list ap;

    va_start(ap, fmt);
    VA_LIST_ALIGN(ap, fmt);

    temp_v0 = func_8037514C_8488FC(D_803A7010_87A7C0, fmt, ap);
    UIElement_PrintText(arg0, D_803A7010_87A7C0);
    return temp_v0;
}

s32 func_803751F8_8489A8(s32 levelID) {
    if (levelID < 0 || levelID >= 7U) {
        return 0;
    }
    return D_803A66A0_879E50[levelID];
}

void func_80375224_8489D4(GObj* arg0) {
    if (D_803A66BC_879E6C != 0) {
        D_803A66BC_879E6C--;
        if (D_803A66BC_879E6C == 0 && D_803A66C0_879E70 >= 0) {
            auPlaySong(0, D_803A66C0_879E70);
            auSetBGMVolume(0, 0x7F00);
        }
    }
}

// TODO terrible mess required to match
void func_80375284_848A34(s32 arg0) {
    s32* new_var; // TODO required to match
    s32 new_var2; // TODO required to match

    new_var = &D_803A66C4_879E74;
    if (D_803A66C8_879E78 == NULL) {
        D_803A66C8_879E78 = func_800A86A4(func_80375224_8489D4, 6, 0, NULL);
        D_803A66BC_879E6C = 0;
        D_803A66C0_879E70 = 0;
    }
    new_var2 = *new_var;
    if (new_var2 != arg0) {
        if (*new_var != (0, 3)) { // TODO required to match
            auSetBGMVolumeSmooth(0, 0, 30);
            D_803A66BC_879E6C = 30;
        } else if (arg0 != 3) {
            D_803A66BC_879E6C = 1;
        }
        D_803A66C4_879E74 = arg0;
        switch (arg0) {
            case 0:
                D_803A66C0_879E70 = 8;
                break;

            case 1:
                D_803A66C0_879E70 = 26;
                break;

            case 2:
                D_803A66C0_879E70 = 9;
                break;

            case 3:
                D_803A66C0_879E70 = -1;
                break;
        }
    }
}
