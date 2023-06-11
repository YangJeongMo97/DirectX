#pragma once
#include <windows.h>
#include "GraphicEngine.h"

#define GROUND 470

extern SURFACEINFO g_sfBack;
extern SURFACEINFO g_sfBG;
extern SURFACEINFO g_sfCharacterStand[4];
extern SURFACEINFO g_sfCharacterWalk[4];
extern SURFACEINFO g_sfCharacterJump[2];
extern SURFACEINFO g_sfCharacterDown[2];
extern SURFACEINFO g_sfCloud[6];

extern int nCharacterX, nCharacterY, nBgX;
extern BOOL bLimitLeft, bLimitRight, bWalk, bJump, bGetDown, bLeft;

void ___aMainLoop(HWND hWnd);