#include "SelectMenu.h"

void SelectMenu(HWND hWnd, int x, int y, int clientY, int &nSelectFigure, int &nSelectPenStyle, int &nSelectHatchBrush, int& nTextStyle, COLORREF &rgbPen, COLORREF &rgbBrush) {
    if (y > clientY - 190 && y < clientY - 140 && x > 10 && x < 300) {
        if (x > 10 && x < 60)
            nSelectFigure = SELECT_FREELINE;
        else if (x > 70 && x < 120)
            nSelectFigure = SELECT_LINE;
        else if (x > 130 && x < 180)
            nSelectFigure = SELECT_RECTANGLE;
        else if (x > 190 && x < 240)
            nSelectFigure = SELECT_ROUNDRECT;
        else if (x > 250 && x < 300)
            nSelectFigure = SELECT_ELLIPSE;
    }
    else if (y > clientY - 130 && y < clientY - 80 && x > 10 && x < 300) {
        if (x > 10 && x < 60)
            nSelectPenStyle = PS_SOLID;
        else if (x > 70 && x < 120)
            nSelectPenStyle = PS_DASH;
        else if (x > 130 && x < 180)
            nSelectPenStyle = PS_DOT;
        else if (x > 190 && x < 240)
            nSelectPenStyle = PS_DASHDOT;
        else if (x > 250 && x < 300)
            nSelectPenStyle = PS_DASHDOTDOT;
    }
    else if (y > clientY - 70 && y < clientY - 20 && x > 10 && x < 420) {
        if (x > 10 && x < 60)
            nSelectHatchBrush = HS_API_MAX;
        else if (x > 70 && x < 120)
            nSelectHatchBrush = HS_VERTICAL;
        else if (x > 130 && x < 180)
            nSelectHatchBrush = HS_HORIZONTAL;
        else if (x > 190 && x < 240)
            nSelectHatchBrush = HS_CROSS;
        else if (x > 250 && x < 300)
            nSelectHatchBrush = HS_BDIAGONAL;
        else if (x > 310 && x < 360)
            nSelectHatchBrush = HS_FDIAGONAL;
        else if (x > 370 && x < 420)
            nSelectHatchBrush = HS_DIAGCROSS;
    }
    else if (x > 310 && x < 420) {
        if (y > clientY - 190 && y < clientY - 160) {
            nSelectFigure = SELECT_TEXT;
            nTextStyle = SELECT_NORMAL;
        }
        else if (y > clientY - 150 && y < clientY - 120) {
            nSelectFigure = SELECT_TEXT;
            nTextStyle = SELECT_TRANSPARENT;
        }
        else if (y > clientY - 110 && y < clientY - 80) {
            nSelectFigure = SELECT_TEXT;
            nTextStyle = SELECT_OPAQUE;
        }
    }
    else if (x > 1030 && x < 1130) {
        if(y > clientY - 190 && y < clientY - 140)
            nSelectFigure = SELECT_ERASER;
        else if(y > clientY - 130 && y < clientY - 80)
            InvalidateRect(hWnd, NULL, TRUE);
    }
}