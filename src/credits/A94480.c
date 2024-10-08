#include "common.h"
#include "../window/window.h"
#include "credits.h"

void func_credits_801DD8C0(SObj* sobj) {
    switch (D_credits_801ECDA0) {
        case SCENE_CREDITS_17:
        case SCENE_CREDITS_18:
        case SCENE_CREDITS_20:
            sobj->sprite.x = 0x60;
            sobj->sprite.y = 0xF0;
            break;

        case SCENE_CREDITS_19:
            sobj->sprite.x = SCREEN_WIDTH;
            sobj->sprite.y = (SCREEN_HEIGHT / 2) - (sobj->sprite.height / 2);
            break;
    }
}

void func_credits_801DD930(SObj* sobj) {
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_credits_801DD93C(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_credits_801DCC00(gobj, &D_credits_801E8B50);
    D_credits_801ECCA0 = gobj;
    sobj = gobj->data.sobj;
    func_credits_801DD8C0(sobj);
    func_credits_801DD930(sobj);
}

void func_credits_801DD980(void) {
    SObj* sobj = D_credits_801ECCA0->data.sobj;
    s32 middle;

    switch (D_credits_801ECDA0) {
        case SCENE_CREDITS_17:
        case SCENE_CREDITS_18:
        case SCENE_CREDITS_20:
            while (true) {
                sobj->sprite.y--;
                if (sobj->sprite.y < 113) {
                    break;
                }
                ohWait(1);
            }
            sobj->sprite.y = 112;
            break;

        case SCENE_CREDITS_19:
            while (true) {
                sobj->sprite.x--;
                middle = (SCREEN_WIDTH / 2) - (sobj->sprite.width / 2);
                if (sobj->sprite.x < middle) {
                    break;
                }
                ohWait(1);
            }
            sobj->sprite.x = middle;
            break;
    }
}

void func_credits_801DDA60(void) {
    u8 color;
    SObj* sobj = D_credits_801ECCA0->data.sobj;

    color = 0xFF;
    while (true) {
        color -= 5;
        if (color >= 10) {
            sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = color;
        } else {
            sobj->sprite.attr |= SP_HIDDEN;
            ohWait(1);
            break;
        }

        ohWait(1);
        ohWait(1);
    }
}

void func_credits_801DDAE8(u8 arg0) {
    switch (D_credits_801ECDA0) {
        case SCENE_CREDITS_17:
        case SCENE_CREDITS_18:
        case SCENE_CREDITS_20:
            func_credits_801DCE10();
            D_credits_801ECDA4 = 0;
            break;

        case SCENE_CREDITS_19:
            D_credits_801ECDA4 = 0;
            func_credits_801DD428();
            func_credits_801DD848();
            break;
    }

    func_credits_801DD93C();
}

void func_credits_801DDB60(void) {
    Credit* var_s0;
    f32 var_f20;

    if (D_credits_801ECDA0 == SCENE_CREDITS_19) {
        var_f20 = 0.44f;
    } else {
        var_f20 = 0.5f;
    }

    var_s0 = D_credits_801ECCB0;
    while (var_s0->unk_C != 0) {
        var_s0->unk_4 -= var_f20;
        UIElement_SetPos(var_s0->unk_C, var_s0->unk_0, var_s0->unk_4);
        var_s0++;
    }
}

Credit* func_credits_801DDC0C(void) {
    Credit* var_v1 = D_credits_801ECCB0;

    while (var_v1->unk_C != 0) {
        if (var_v1->unk_4 < -18.0f) {
            break;
        }

        var_v1++;
    }

    if (var_v1->unk_C == 0) {
        return NULL;
    }

    return var_v1;
}

void func_credits_801DDC70(void) {
    Credit* var_s0;
    f32 var_f20;
    s16 i;
    UIElement* temp_v0;

    var_f20 = 0.0f;
    var_s0 = D_credits_801ECCB0;

    for (i = 0; i < 14; i++) {
        var_s0->unk_4 = var_f20;
        var_s0->unk_0 = SCREEN_WIDTH / 2;
        var_f20 += 18.0f;
        UIText_SetPrintDelay(0);
        temp_v0 = UIElement_Create(var_s0->unk_0, var_s0->unk_4, 252, 15, UI_FLAG_32BIT);
        var_s0->unk_C = temp_v0;
        UIElement_SetFont(temp_v0, FONT_12);
        UIElement_DrawBackground(var_s0->unk_C);
        UIElement_SetTextPos(var_s0->unk_C, 0, 0);
        UIElement_SetColor(var_s0->unk_C, UI_BACKGROUND, 0, 0, 0, 0);
        var_s0++;
    }
    var_s0->unk_C = 0;
    var_s0->unk_0 = 0;
    var_s0->unk_4 = 0.0f;
}
