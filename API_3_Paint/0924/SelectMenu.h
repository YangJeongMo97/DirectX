#pragma once
#include <windows.h>
#include "enumHeader.h"

void SelectMenu(HWND hWnd, int x, int y, int clientY, int &nSelectFigure, int &nSelectPenStyle, int &nSelectHatchBrush, int &nTextStyle, COLORREF &rgbPen, COLORREF &rgbBrush);