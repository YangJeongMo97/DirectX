#include "Draw.h"

void Draw(HWND hWnd, int &x1, int &y1, int x2, int y2, int nLength, char* string, BOOL bFill, int nFigure, int nPenStyle, int nHatchBrush, int nTextType, int nWidth, COLORREF rgbPen, COLORREF rgbBrush) {
    switch (nFigure) {
    case SELECT_FREELINE:
        DrawFreeLine(hWnd, x1, y1, x2, y2, nWidth, rgbPen);
        break;
    case SELECT_LINE:
        DrawLine(hWnd, x1, y1, x2, y2, TRUE, nPenStyle, nWidth, rgbPen);
        break;
    case SELECT_RECTANGLE:
        DrawRect(hWnd, x1, y1, x2, y2, TRUE, nPenStyle, nHatchBrush, nWidth, rgbPen, rgbBrush);
        break;
    case SELECT_ROUNDRECT:
        DrawRoundRect(hWnd, x1, y1, x2, y2, TRUE, nPenStyle, nHatchBrush, nWidth, rgbPen, rgbBrush);
        break;
    case SELECT_ELLIPSE:
        DrawEllipse(hWnd, x1, y1, x2, y2, TRUE, nPenStyle, nHatchBrush, nWidth, rgbPen, rgbBrush);
        break;
    case SELECT_ERASER:
        DrawFreeLine(hWnd, x1, y1, x2, y2, nWidth, RGB(255, 255, 255));
        break;
    }
}