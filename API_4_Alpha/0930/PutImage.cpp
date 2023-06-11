#include "PutImage.h"

BOOL PutImage(HDC hdc, int x, int y, HDC memDc) {
	extern HBITMAP MyBitmap;
	HBITMAP OldBitmap = NULL;
	int nBitX, nBitY;
	BITMAP bitmap;
	
	if (MyBitmap) {
		OldBitmap = (HBITMAP)SelectObject(memDc, MyBitmap);

		GetObject(MyBitmap, sizeof(BITMAP), &bitmap);

		nBitX = bitmap.bmWidth;
		nBitY = bitmap.bmHeight;

		BitBlt(hdc, x, y, nBitX, nBitY, memDc, x, y, SRCCOPY);

		SelectObject(hdc, OldBitmap);

		DeleteObject(MyBitmap);

		return TRUE;
	}
	else return FALSE;
}