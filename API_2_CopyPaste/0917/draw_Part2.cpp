#include "draw_Part2.h"

void draw_Part2(HDC hdc, int nClientX, int nClientY) {
	COLORREF PixelColor;
	for (int y = 0; y < nClientY / 2; y++) {
		for (int x = 0; x < nClientX / 2; x++) {
			PixelColor = GetPixel(hdc, x, y);
			SetPixel(hdc, x + nClientX / 2, y, PixelColor);
		}
	}
}