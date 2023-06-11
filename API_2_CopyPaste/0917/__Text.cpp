#include "__Text.h"

void __Text(HDC hdc, int x, int y) {
	LPCSTR pString = "Text Out Area";
	int nTextMode = rand() % 3;
	switch (nTextMode) {
	case 0:
		TextOut(hdc, x, y, pString, strlen(pString));
		break;
	case 1:
		SetBkMode(hdc, TRANSPARENT);
		TextOut(hdc, x, y, pString, strlen(pString));
		break;
	case 2:
		SetBkMode(hdc, OPAQUE);
		SetBkColor(hdc, RGB(rand() % 256, rand() % 256, 255));
		SetTextColor(hdc, RGB(rand() % 256, rand() % 256, rand() % 256));
		TextOut(hdc, x, y, pString, strlen(pString));
		break;
	}
}