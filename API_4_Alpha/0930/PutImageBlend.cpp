#include "PutImageBlend.h"

BOOL PutImageBlend(HDC hdc, int x, int y, HDC memDc, int nAlpha) {
	extern HBITMAP MyBitmap;
	HBITMAP OldBitmap = NULL;
	int nBitX, nBitY;
	BITMAP bitmap;
	BLENDFUNCTION blendFunction;

	if (MyBitmap) {
		OldBitmap = (HBITMAP)SelectObject(memDc, MyBitmap);
		GetObject(MyBitmap, sizeof(BITMAP), &bitmap);

		nBitX = bitmap.bmWidth;
		nBitY = bitmap.bmHeight;

		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.AlphaFormat = 0;
		blendFunction.SourceConstantAlpha = nAlpha;

		AlphaBlend(hdc, x, y, nBitX, nBitY, memDc, 0, 0, nBitX, nBitY, blendFunction);

		SelectObject(memDc, OldBitmap);
		DeleteObject(MyBitmap);

		return TRUE;
	}
	else return FALSE;
}