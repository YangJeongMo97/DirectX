#include "draw_Part3.h"

void draw_Part3(HDC hdc, int nClientX, int nClientY) {
	COLORREF PixelColor;
	for (int y = 0; y < nClientY / 2; y++) {
		for (int x = nClientX / 2; x < nClientX; x++) {
			PixelColor = GetPixel(hdc, x, y);
			SetPixel(hdc, nClientX - x , y + nClientY / 2, PixelColor);
		}
	}
}