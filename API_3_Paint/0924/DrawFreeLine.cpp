#include "DrawFreeLine.h"

void DrawFreeLine(HWND hWnd, int &x1, int &y1, int x2, int y2, int nWidth, COLORREF rgbPen) {
    HDC hdc = GetDC(hWnd);
    HPEN newPen, oldPen;
    
    newPen = CreatePen(PS_SOLID, nWidth, rgbPen);
    oldPen = (HPEN)SelectObject(hdc, newPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);

    SelectObject(hdc, oldPen);
    DeleteObject(newPen);

    x1 = x2;
    y1 = y2;
    ReleaseDC(hWnd, hdc);
}