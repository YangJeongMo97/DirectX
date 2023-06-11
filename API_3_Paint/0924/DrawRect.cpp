#include "DrawRect.h"

void DrawRect(HWND hWnd, int x1, int y1, int x2, int y2, BOOL bFill, int nPenStyle, int nHatchBrush, int nWidth, COLORREF rgbPen, COLORREF rgbBrush)
{
    HBRUSH newBrush = NULL, oldBrush = NULL;
    HPEN newPen = NULL, oldPen = NULL;

    HDC hdc = GetDC(hWnd);
    if (bFill) {
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

        switch (nHatchBrush) {
        case HS_VERTICAL:
            newBrush = CreateHatchBrush(HS_VERTICAL, rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        case HS_HORIZONTAL:
            newBrush = CreateHatchBrush(HS_HORIZONTAL, rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        case HS_CROSS:
            newBrush = CreateHatchBrush(HS_CROSS, rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        case HS_BDIAGONAL:
            newBrush = CreateHatchBrush(HS_BDIAGONAL, rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        case HS_FDIAGONAL:
            newBrush = CreateHatchBrush(HS_FDIAGONAL, rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        case HS_DIAGCROSS:
            newBrush = CreateHatchBrush(HS_DIAGCROSS, rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        default:
            newBrush = CreateSolidBrush(rgbBrush);
            oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
            break;
        }
    }
    else
        SetROP2(hdc, R2_NOT);
    Rectangle(hdc, x1, y1, x2, y2);
    SelectObject(hdc, oldBrush);
    DeleteObject(newBrush);
    if (oldPen) {
        SelectObject(hdc, oldPen);
        DeleteObject(newPen);
    }
    ReleaseDC(hWnd, hdc);
}