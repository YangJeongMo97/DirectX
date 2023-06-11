#pragma once
#include <Windows.h>
#include "enumHeader.h"

void DrawTextTyping(HWND hWnd, int x, int y, int nLength, char* string, int nTextStyle, BOOL bCanDraw, COLORREF rgbPen, COLORREF rgbBrush);