#pragma once
#include <windows.h>
#include "enumHeader.h"
#include "DrawFreeLine.h"
#include "DrawLine.h"
#include "DrawRect.h"
#include "DrawRoundRect.h"
#include "DrawEllipse.h"
#include "DrawTextTyping.h"

void Sketch(HWND hWnd, int &x1, int &y1, int x2, int y2, BOOL bFill, int nFigure, int nPenStyle, int nHatchBrush, int nWidth, COLORREF rgbPen, COLORREF rgbBrush);