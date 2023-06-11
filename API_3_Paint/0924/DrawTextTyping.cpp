#include "DrawTextTyping.h"

void DrawTextTyping(HWND hWnd, int x, int y, int nLength, char* string, int nTextStyle, BOOL bCanDraw, COLORREF rgbPen, COLORREF rgbBrush) {
	HDC hdc = GetDC(hWnd);
	
	if (bCanDraw) {
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

		TextOut(hdc, x, y, string, nLength);
	}
}