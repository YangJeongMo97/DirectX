#pragma once
#include <windows.h>

void DrawRect(HWND hWnd, int x1, int y1, int x2, int y2, BOOL bFill, int nPenStyle, int nHatchBrush, int nWidth, COLORREF rgbPen, COLORREF rgbBrush);