#include "PutSprite.h"

BOOL PutSprite(HDC hdc, int x, int y, HDC memDc, COLORREF colorkey) {
	extern HBITMAP MyBitmap;
	HBITMAP OldBitmap = NULL;
	int nBitX, nBitY;
	BITMAP bitmap;

	if (MyBitmap) {
		OldBitmap = (HBITMAP)SelectObject(memDc, MyBitmap);

		GetObject(MyBitmap, sizeof(BITMAP), &bitmap);

		nBitX = bitmap.bmWidth;
		nBitY = bitmap.bmHeight;

		TransparentBlt(hdc, x, y, nBitX, nBitY, memDc, 0, 0, nBitX, nBitY, colorkey);

		SelectObject(hdc, OldBitmap);

		DeleteObject(MyBitmap);

		return TRUE;
	}
	else return FALSE;
}