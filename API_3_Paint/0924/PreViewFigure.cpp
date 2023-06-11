#include "PreViewFigure.h"

void PreViewFigure(HWND hWnd, int clientY, int nFigure, int nPenStyle, int nHatchBrush, int nTextStyle, int nWidth, COLORREF rgbPen, COLORREF rgbBrush) {
    HDC hdc = GetDC(hWnd);

    switch (nFigure) {
    case SELECT_FREELINE:
        DrawLine(hWnd, 455, clientY - 30, 525, clientY - 70, TRUE, PS_SOLID, nWidth, rgbPen);
        DrawLine(hWnd, 525, clientY - 70, 565, clientY - 110, TRUE, PS_SOLID, nWidth, rgbPen);
        DrawLine(hWnd, 565, clientY - 110, 605, clientY - 180, TRUE, PS_SOLID, nWidth, rgbPen);
        break;
    case SELECT_LINE:
        DrawLine(hWnd, 455, clientY - 30, 605, clientY - 180, TRUE, nPenStyle, nWidth, rgbPen);
        break;
    case SELECT_RECTANGLE:
        DrawRect(hWnd, 455, clientY - 30, 605, clientY - 180, TRUE, nPenStyle, nHatchBrush, nWidth, rgbPen, rgbBrush);
        break;
    case SELECT_ROUNDRECT:
        DrawRoundRect(hWnd, 455, clientY - 30, 605, clientY - 180, TRUE, nPenStyle, nHatchBrush, nWidth, rgbPen, rgbBrush);
        break;
    case SELECT_ELLIPSE:
        DrawEllipse(hWnd, 455, clientY - 30, 605, clientY - 180, TRUE, nPenStyle, nHatchBrush, nWidth, rgbPen, rgbBrush);
        break;
    case SELECT_TEXT:
        switch (nTextStyle) {
        case SELECT_NORMAL:
            SetTextColor(hdc, rgbPen);
            break;
        case SELECT_TRANSPARENT:
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, rgbPen);
            break;
        case SELECT_OPAQUE:
            SetBkMode(hdc, OPAQUE);
            SetBkColor(hdc, rgbBrush);
            SetTextColor(hdc, rgbPen);
            break;
        }
        TextOut(hdc, 465, clientY - 126, "화면에 출력되는", strlen("화면에 출력되는"));
        TextOut(hdc, 465, clientY - 100, "글자 모양입니다.", strlen("글자 모양입니다."));
        break;
    }
}