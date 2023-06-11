#pragma once
#include <windows.h>
#include "enumHeader.h"

void SelectMenuByKey(WPARAM wParam, int& nSelectFigure, int& nSelectPenStyle, int& nSelectHatchBrush, COLORREF& rgbPen, COLORREF& rgbBrush);