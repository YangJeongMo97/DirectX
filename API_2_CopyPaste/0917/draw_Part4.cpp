#include "draw_Part4.h"

void draw_Part4(HDC hdc, int nClientX, int nClientY) {
	COLORREF PixelColor;
	for (int y = nClientY / 2; y < nClientY; y++) {
		for (int x = 0; x < nClientX / 2; x++) {
			PixelColor = GetPixel(hdc, x, y);
			SetPixel(hdc, x + nClientX / 2, (nClientY - y) + (nClientY / 2), PixelColor);
		}
	}
}