#include "__Line.h"

void __Line(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen) {
	HPEN hSidePen, OldPen;
	int nRandPenStyle = rand() % 5, nThick = rand() % 2 + 1;
	hSidePen = CreatePen(nRandPenStyle, nThick, crPen);
	OldPen = (HPEN)SelectObject(hdc, hSidePen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	
	SelectObject(hdc, OldPen);
	DeleteObject(hSidePen);
}