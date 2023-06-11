#include "DrawLine.h"

void DrawLine(HWND hWnd, int x1, int y1, int x2, int y2, BOOL bFill, int nPenStyle, int nWidth, COLORREF rgbPen) {
    HDC hdc = GetDC(hWnd);
    HPEN newPen = NULL, oldPen = NULL;
    if(!bFill)
      SetROP2(hdc, R2_NOT);
    else {
        switch (nPenStyle) {
        case PS_SOLID:
            newPen = CreatePen(PS_SOLID, nWidth, rgbPen);
            oldPen = (HPEN)SelectObject(hdc, newPen);
            break;
        case PS_DASH:
            newPen = CreatePen(PS_DASH, nWidth, rgbPen);
            oldPen = (HPEN)SelectObject(hdc, newPen);
            break;
        case PS_DOT:
            newPen = CreatePen(PS_DOT, nWidth, rgbPen);
            oldPen = (HPEN)SelectObject(hdc, newPen);
            break;
        case PS_DASHDOT:
            newPen = CreatePen(PS_DASHDOT, nWidth, rgbPen);
            oldPen = (HPEN)SelectObject(hdc, newPen);
            break;
        case PS_DASHDOTDOT:
            newPen = CreatePen(PS_DASHDOTDOT, nWidth, rgbPen);
            oldPen = (HPEN)SelectObject(hdc, newPen);
            break;
        default:
            break;
        }
    }
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    if (oldPen) {
        SelectObject(hdc, oldPen);
        DeleteObject(newPen);
    }
    ReleaseDC(hWnd, hdc);
}