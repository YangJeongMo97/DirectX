#include "RandRect.h"

void RandRect(HDC hdc, int nClientWidth, int nClientHeight) {
	RECT   rc;
	int nRandFigure = rand();

	rc = RandPoint(nClientWidth / 2, nClientHeight / 2);

	switch (nRandFigure % 4) {
	case 0:
		__Line(hdc, rc.left, rc.top, rc.right, rc.bottom, RGB(rand() % 256, rand() % 256, rand() % 256));
		break;
	case 1:
		__Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom, RGB(rand() % 256, rand() % 256, rand() % 256), RGB(rand() % 256, rand() % 256, rand() % 256));
		break;
	case 2:
		__Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom, RGB(rand() % 256, rand() % 256, rand() % 256), RGB(rand() % 256, rand() % 256, rand() % 256));
		break;
	case 3:
		__Text(hdc, rc.left + ((rc.right - rc.left) / 2), rc.top - ((rc.bottom - rc.top)/2));
		break;
	}

	draw_Part2(hdc, nClientWidth, nClientHeight);
	draw_Part3(hdc, nClientWidth, nClientHeight);
	draw_Part4(hdc, nClientWidth, nClientHeight);
}