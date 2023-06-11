#include "___aInit.h"

//// 일괄 표면 생성 
void ___aInit(HDC hdc)
{
	////
	__geCreateBackBuffer(hdc, 3200, 600, 32, &g_sfBack);

	////
	__geSetImgSurface(&g_sfBG);
	g_sfBG.hBmp = __geBmpFile2BmpHandle("MAP.bmp");
	__geLoadSurface(hdc, &g_sfBG);


	__geSetSprSurface(&g_sfCharacterStand[0], RGB(225, 80, 80));
	g_sfCharacterStand[0].hBmp = __geBmpFile2BmpHandle("PoongMan_stand0.bmp");
	__geLoadSurface(hdc, &g_sfCharacterStand[0]);

	__geSetSprSurface(&g_sfCharacterStand[1], RGB(225, 80, 80));
	g_sfCharacterStand[1].hBmp = __geBmpFile2BmpHandle("PoongMan_stand1.bmp");
	__geLoadSurface(hdc, &g_sfCharacterStand[1]);

	__geSetSprSurface(&g_sfCharacterStand[2], RGB(225, 80, 80));
	g_sfCharacterStand[2].hBmp = __geBmpFile2BmpHandle("PoongMan_stand2.bmp");
	__geLoadSurface(hdc, &g_sfCharacterStand[2]);

	__geSetSprSurface(&g_sfCharacterStand[3], RGB(225, 80, 80));
	g_sfCharacterStand[3].hBmp = __geBmpFile2BmpHandle("PoongMan_stand3.bmp");
	__geLoadSurface(hdc, &g_sfCharacterStand[3]);


	__geSetSprSurface(&g_sfCharacterWalk[0], RGB(225, 80, 80));
	g_sfCharacterWalk[0].hBmp = __geBmpFile2BmpHandle("PoongMan_walk0.bmp");
	__geLoadSurface(hdc, &g_sfCharacterWalk[0]);

	__geSetSprSurface(&g_sfCharacterWalk[1], RGB(225, 80, 80));
	g_sfCharacterWalk[1].hBmp = __geBmpFile2BmpHandle("PoongMan_walk1.bmp");
	__geLoadSurface(hdc, &g_sfCharacterWalk[1]);

	__geSetSprSurface(&g_sfCharacterWalk[2], RGB(225, 80, 80));
	g_sfCharacterWalk[2].hBmp = __geBmpFile2BmpHandle("PoongMan_walk2.bmp");
	__geLoadSurface(hdc, &g_sfCharacterWalk[2]);

	__geSetSprSurface(&g_sfCharacterWalk[3], RGB(225, 80, 80));
	g_sfCharacterWalk[3].hBmp = __geBmpFile2BmpHandle("PoongMan_walk3.bmp");
	__geLoadSurface(hdc, &g_sfCharacterWalk[3]);


	__geSetSprSurface(&g_sfCharacterJump[0], RGB(225, 80, 80));
	g_sfCharacterJump[0].hBmp = __geBmpFile2BmpHandle("PoongMan_jump0.bmp");
	__geLoadSurface(hdc, &g_sfCharacterJump[0]);

	__geSetSprSurface(&g_sfCharacterJump[1], RGB(225, 80, 80));
	g_sfCharacterJump[1].hBmp = __geBmpFile2BmpHandle("PoongMan_jump1.bmp");
	__geLoadSurface(hdc, &g_sfCharacterJump[1]);


	__geSetSprSurface(&g_sfCharacterDown[0], RGB(225, 80, 80));
	g_sfCharacterDown[0].hBmp = __geBmpFile2BmpHandle("PoongMan_down0.bmp");
	__geLoadSurface(hdc, &g_sfCharacterDown[0]);

	__geSetSprSurface(&g_sfCharacterDown[1], RGB(225, 80, 80));
	g_sfCharacterDown[1].hBmp = __geBmpFile2BmpHandle("PoongMan_down1.bmp");
	__geLoadSurface(hdc, &g_sfCharacterDown[1]);


	__geSetSprSurface(&g_sfCloud[0], RGB(225, 80, 80));
	g_sfCloud[0].hBmp = __geBmpFile2BmpHandle("cloud_0.bmp");
	__geLoadSurface(hdc, &g_sfCloud[0]);

	__geSetSprSurface(&g_sfCloud[1], RGB(225, 80, 80));
	g_sfCloud[1].hBmp = __geBmpFile2BmpHandle("cloud_1.bmp");
	__geLoadSurface(hdc, &g_sfCloud[1]);

	__geSetSprSurface(&g_sfCloud[2], RGB(225, 80, 80));
	g_sfCloud[2].hBmp = __geBmpFile2BmpHandle("cloud_2.bmp");
	__geLoadSurface(hdc, &g_sfCloud[2]);

	__geSetSprSurface(&g_sfCloud[3], RGB(225, 80, 80));
	g_sfCloud[3].hBmp = __geBmpFile2BmpHandle("cloud_3.bmp");
	__geLoadSurface(hdc, &g_sfCloud[3]);

	__geSetSprSurface(&g_sfCloud[4], RGB(225, 80, 80));
	g_sfCloud[4].hBmp = __geBmpFile2BmpHandle("cloud_4.bmp");
	__geLoadSurface(hdc, &g_sfCloud[4]);

	__geSetSprSurface(&g_sfCloud[5], RGB(225, 80, 80));
	g_sfCloud[5].hBmp = __geBmpFile2BmpHandle("cloud_5.bmp");
	__geLoadSurface(hdc, &g_sfCloud[5]);
}