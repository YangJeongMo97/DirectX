#include "___aMainLoop.h"

void ___aMainLoop(HWND hWnd)
{
	HDC   hdc;
	static int nCloudX[6];
	static int nCharacterBreath, nWalkAnimation, nJumpPower = 20;
	float fGravity = 1.6f;
	int nCloudSpeed[6] = { 3, 2, 4, 6, 5, 7 };

	hdc = GetDC(hWnd);

	//// 연산부
	for (int i = 0; i < 6; i++) {
		nCloudX[i] -= nCloudSpeed[i];
		if (nCloudX[i] < -1000) nCloudX[i] = 0;
	}

	if (!bWalk)
		nCharacterBreath++;
	else
		nWalkAnimation++;

	if (nBgX < -3200) nBgX = 0;

	//// 출력부	
	// 배경	
	__gePutSprite(g_sfBack.dcSurface, nBgX, 0, &g_sfBG);
	__gePutSprite(g_sfBack.dcSurface, nBgX + 3200, 0, &g_sfBG);

	__gePutSprite(g_sfBack.dcSurface, nCloudX[0], 10, &g_sfCloud[0]);
	__gePutSprite(g_sfBack.dcSurface, nCloudX[0] + 1000, 10, &g_sfCloud[0]);

	__gePutSprite(g_sfBack.dcSurface, nCloudX[1], 30, &g_sfCloud[1]);
	__gePutSprite(g_sfBack.dcSurface, nCloudX[1] + 1000, 30, &g_sfCloud[1]);

	__gePutSprite(g_sfBack.dcSurface, nCloudX[2], 60, &g_sfCloud[2]);
	__gePutSprite(g_sfBack.dcSurface, nCloudX[2] + 1000, 60, &g_sfCloud[2]);

	__gePutSprite(g_sfBack.dcSurface, nCloudX[3], 20, &g_sfCloud[3]);
	__gePutSprite(g_sfBack.dcSurface, nCloudX[3] + 1000, 20, &g_sfCloud[3]);

	__gePutSprite(g_sfBack.dcSurface, nCloudX[4], 45, &g_sfCloud[4]);
	__gePutSprite(g_sfBack.dcSurface, nCloudX[4] + 1000, 45, &g_sfCloud[4]);

	__gePutSprite(g_sfBack.dcSurface, nCloudX[5], 75, &g_sfCloud[5]);
	__gePutSprite(g_sfBack.dcSurface, nCloudX[5] + 1000, 75, &g_sfCloud[5]);

	switch (bLeft) {
	case FALSE:
		switch (bJump) {
		case FALSE:
			switch (bGetDown) {
			case FALSE:
				switch (bWalk) {
				case FALSE:
					switch (nCharacterBreath / 16) {
					case 0:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[0]);
						break;
					case 1:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[1]);
						break;
					default:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[0]);
						nCharacterBreath = 0;
						break;
					}
					break;
				case TRUE:
					switch (nWalkAnimation / 4) {
					case 0:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterWalk[0]);
						break;
					case 1:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[0]);
						break;
					case 2:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterWalk[1]);
						break;
					case 3:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[0]);
						nWalkAnimation = 0;
						break;
					}
				}
				break;
			case TRUE:
				__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterDown[0]);
				break;
			}
			break;
		case TRUE:
			fGravity += fGravity;
			nJumpPower -= fGravity * 1.1;
			nCharacterY -= nJumpPower;
			if (nCharacterY > GROUND) {
				nCharacterY = GROUND;
				bJump = FALSE;
				fGravity = 1.2;
				nJumpPower = 20;
			}
			__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterJump[0]);
			break;
		}
		break;
	case TRUE:
		switch (bJump) {
		case FALSE:
			switch (bGetDown) {
			case FALSE:
				switch (bWalk) {
				case FALSE:
					switch (nCharacterBreath / 16) {
					case 0:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[2]);
						break;
					case 1:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[3]);
						break;
					default:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[2]);
						nCharacterBreath = 0;
						break;
					}
					break;
				case TRUE:
					switch (nWalkAnimation / 4) {
					case 0:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterWalk[2]);
						break;
					case 1:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[2]);
						break;
					case 2:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterWalk[3]);
						break;
					case 3:
						__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterStand[2]);
						nWalkAnimation = 0;
						break;
					}
				}
				break;
			case TRUE:
				__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterDown[1]);
				break;
			}
			break;
		case TRUE:
			fGravity += fGravity;
			nJumpPower -= fGravity * 1.1;
			nCharacterY -= nJumpPower;
			if (nCharacterY > GROUND) {
				nCharacterY = GROUND;
				bJump = FALSE;
				fGravity = 1.2;
				nJumpPower = 20;
			}
			__gePutSprite(g_sfBack.dcSurface, nCharacterX, nCharacterY, &g_sfCharacterJump[1]);
			break;
		}
		break;
	}
	////				


	//// 출력 완료 (후면표면DC --전송--> 전면표면DC/화면DC)
	
	__geCompleteBlt(hdc, &g_sfBack);
	ReleaseDC(hWnd, hdc);

	Sleep(1000 / 60);
}