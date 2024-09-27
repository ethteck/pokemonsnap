#include "common.h"
#include "window.h"

extern s32 D_80381920_8550D0;

void UIFrame_ExpandFromCenter(UIFrame* f, s32 style, s32 show) {
    s32 i;
    s32 v0;
    s32 x1, y1;
    s32 x2, y2;
    s32 opacity;

    UIFrame_SetStyle(f, style);
    UIFrame_ShowBackground(f, true);

    for (i = 0; i <= D_80381920_8550D0; i++) {
        v0 = show ? i : D_80381920_8550D0 - i;

        x1 = -92 * v0 / D_80381920_8550D0 + 188;
        x2 = 92 * v0 / D_80381920_8550D0 + 212;
        y1 = -36 * v0 / D_80381920_8550D0 + 201;        
        y2 = 225;
        opacity = v0 * 255 / D_80381920_8550D0;
        
        UIFrame_SetPos(f, x1, y1);
        UIFrame_SetSize(f, x2 - x1, y2 - y1);
        UIFrame_SetOpacity(f, opacity);
        ohWait(1);
    }

    if (show) {
        UIFrame_SetPos(f, 96, 165);
        UIFrame_SetSize(f, 208, 60);
    }
}

void UIFrame_ExpandFromRight(UIFrame* f, s32 style, s32 show) {
    s32 i;
    s32 v0;
    s32 x1, y1;
    s32 x2, y2;
    s32 opacity;

    UIFrame_SetStyle(f, style);
    UIFrame_ShowBackground(f, true);

    for (i = 0; i <= D_80381920_8550D0; i++) {
        v0 = show ? i : D_80381920_8550D0 - i;

        x1 = -184 * v0 / D_80381920_8550D0 + 280;
        x2 = 304;
        y1 = -36 * v0 / D_80381920_8550D0 + 201;        
        y2 = 225;
        opacity = v0 * 255 / D_80381920_8550D0;
        
        UIFrame_SetPos(f, x1, y1);
        UIFrame_SetSize(f, x2 - x1, y2 - y1);
        UIFrame_SetOpacity(f, opacity);
        ohWait(1);
    }

    if (show) {
        UIFrame_SetPos(f, 96, 165);
        UIFrame_SetSize(f, 208, 60);
    }
}

void UIFrame_ExpandFromLeft(UIFrame* f, s32 style, s32 show) {
    s32 i;
    s32 v0;
    s32 width, height;
    s32 opacity;

    UIFrame_SetStyle(f, style);
    UIFrame_ShowBackground(f, true);
    UIFrame_SetPos(f, 96, 165);

    for (i = 0; i <= D_80381920_8550D0; i++) {
        v0 = show ? i : D_80381920_8550D0 - i;

        width = 184 * v0 / D_80381920_8550D0;
        height = 36 * v0 / D_80381920_8550D0;
        opacity = v0 * 255 / D_80381920_8550D0;
        
        UIFrame_SetSize(f, width + 24, height + 24);
        UIFrame_SetOpacity(f, opacity);
        ohWait(1);
    }

    if (show) {
        UIFrame_SetSize(f, 208, 60);
    }
}

void UIFrame_FadeIn(UIFrame* f, s32 style) {
    UIFrame_Show(f, true);

    switch (style) {
        case FRAME_STYLE_0:
            UIFrame_ExpandFromCenter(f, style, true);
            break;
        case FRAME_STYLE_1:
            UIFrame_ExpandFromCenter(f, style, true);
            break;
        case FRAME_STYLE_2:
            UIFrame_ExpandFromRight(f, style, true);
            break;
        case FRAME_STYLE_3:
            UIFrame_ExpandFromLeft(f, style, true);
            break;
    }

    UIFrame_SetOpacity(f, 255);
    UIFrame_ShowBackground(f, false);
}

void UIFrame_FadeOut(UIFrame* f) {
    UIFrame_ShowBackground(f, true);

    switch (f->style) {
        case FRAME_STYLE_0:
            UIFrame_ExpandFromCenter(f, f->style, false);
            break;
        case FRAME_STYLE_1:
            UIFrame_ExpandFromCenter(f, f->style, false);
            break;
        case FRAME_STYLE_2:
            UIFrame_ExpandFromRight(f, f->style, false);
            break;
        case FRAME_STYLE_3:
            UIFrame_ExpandFromLeft(f, f->style, false);
            break;
    }
    UIFrame_Show(f, false);
}
