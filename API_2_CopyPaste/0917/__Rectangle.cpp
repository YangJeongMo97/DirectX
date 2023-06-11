#include "__Rectangle.h"

void __Rectangle(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush) {
	HPEN hSidePen, OldPen;
	HBRUSH hRectBrush, OldBrush;
	int nRandPenStyle = rand() % 6, nRandHatchBrush = rand() % 6, nHatch_NotHatch = rand();

	switch (nHatch_NotHatch % 2) {
	case 0:
		hRectBrush = CreateSolidBrush(crBrush);
		OldBrush = (HBRUSH)SelectObject(hdc, hRectBrush);
		hSidePen = CreatePen(nRandPenStyle, 1, crPen);
		OldPen = (HPEN)SelectObject(hdc, hSidePen);
		Rectangle(hdc, x1, y1, x2, y2);
		SelectObject(hdc, OldPen);
		DeleteObject(hSidePen);
		SelectObject(hdc, OldBrush);
		DeleteObject(hRectBrush);
		break;
	default:
		hRectBrush = CreateHatchBrush(nRandHatchBrush, crBrush);
		OldBrush = (HBRUSH)SelectObject(hdc, hRectBrush);
		hSidePen = CreatePen(nRandPenStyle, 1, crPen);
		OldPen = (HPEN)SelectObject(hdc, hSidePen);
		Rectangle(hdc, x1, y1, x2, y2);
		SelectObject(hdc, OldPen);
		DeleteObject(hSidePen);
		SelectObject(hdc, OldBrush);
		DeleteObject(hRectBrush);
		break;
	}
}