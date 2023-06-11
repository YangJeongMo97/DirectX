#include "__KeyProc.h"

void __KeyProc(HWND hWnd)
{
	if (GetKeyState(VK_LEFT) & 0x80)
	{
		bLeft = TRUE;
		if (!bGetDown)
			nCharacterX -= 10;
		if (!bJump && !bGetDown)
			bWalk = TRUE;
		if (nBgX < 0 && nCharacterX < 150) {
			nCharacterX = 150;
			bLimitLeft = TRUE;
			bLimitRight = FALSE;
		}
		else if (nCharacterX < 0)
			nCharacterX = 0;
		else bLimitLeft = FALSE;
		if (bLimitLeft) {
			if (nBgX != 0) nBgX += 10;
			else nBgX = 0;
		}
	}
	if (GetKeyState(VK_RIGHT) & 0x80)
	{
		bLeft = FALSE;
		if (!bGetDown)
			nCharacterX += 10;

		if (!bJump && !bGetDown)
			bWalk = TRUE;
		if (nCharacterX > 300) {
			nCharacterX = 300;
			bLimitRight = TRUE;
			bLimitLeft = FALSE;
		}
		else bLimitRight = FALSE;
		if (bLimitRight) nBgX -= 10;
	}
	if (GetKeyState(VK_UP) & 0x80)
	{
		bWalk = FALSE;
		bJump = TRUE;
	}
	if (GetKeyState(VK_DOWN) & 0x80)
	{
		bWalk = FALSE;
		bGetDown = TRUE;
	}
}