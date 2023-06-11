#include "SelectMenuByKey.h"

void SelectMenuByKey(WPARAM wParam, int& nSelectFigure, int& nSelectPenStyle, int& nSelectHatchBrush, COLORREF& rgbPen, COLORREF& rgbBrush) {
    switch (wParam) {
    case 'Q':
    case 'q':
        nSelectFigure = SELECT_FREELINE;
        break;
    case 'W':
    case 'w':
        nSelectFigure = SELECT_LINE;
        break;
    case 'E':
    case 'e':
        nSelectFigure = SELECT_RECTANGLE;
        break;
    case 'R':
    case 'r':
        nSelectFigure = SELECT_ROUNDRECT;
        break;
    case 'T':
    case 't':
        nSelectFigure = SELECT_ELLIPSE;
        break;
    case 'A':
    case 'a':
        nSelectPenStyle = PS_SOLID;
        break;
    case 'S':
    case 's':
        nSelectPenStyle = PS_DASH;
        break;
    case 'D':
    case 'd':
        nSelectPenStyle = PS_DOT;
        break;
    case 'F':
    case 'f':
        nSelectPenStyle = PS_DASHDOT;
        break;
    case 'G':
    case 'g':
        nSelectPenStyle = PS_DASHDOTDOT;
        break;
    case 'Z':
    case 'z':
        nSelectHatchBrush = HS_VERTICAL;
        break;
    case 'X':
    case 'x':
        nSelectHatchBrush = HS_HORIZONTAL;
        break;
    case 'C':
    case 'c':
        nSelectHatchBrush = HS_CROSS;
        break;
    case 'V':
    case 'v':
        nSelectHatchBrush = HS_BDIAGONAL;
        break;
    case 'B':
    case 'b':
        nSelectHatchBrush = HS_FDIAGONAL;
        break;
    case 'N':
    case 'n':
        nSelectHatchBrush = HS_DIAGCROSS;
        break;
    case '~':
        rgbBrush = RGB(0, 0, 0);
        break;
    case '`':
        rgbPen = RGB(0, 0, 0);
        break;
    case '!':
        rgbBrush = RGB(255, 0, 0);
        break;
    case '1':
        rgbPen = RGB(255, 0, 0);
        break;
    case '@':
        rgbBrush = RGB(0, 255, 0);
        break;
    case '2':
        rgbPen = RGB(0, 255, 0);
        break;
    case '#':
        rgbBrush = RGB(0, 0, 255);
        break;
    case '3':
        rgbPen = RGB(0, 0, 255);
        break;
    case '$':
        rgbBrush = RGB(255, 255, 255);
        break;
    case '4':
        rgbPen = RGB(255, 255, 255);
        break;
    }
}