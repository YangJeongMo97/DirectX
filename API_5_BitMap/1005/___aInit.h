#pragma once
#include <windows.h>
#include "GraphicEngine.h"

extern SURFACEINFO g_sfBack;
extern SURFACEINFO g_sfBG;
extern SURFACEINFO g_sfCharacterStand[4];
extern SURFACEINFO g_sfCharacterWalk[4];
extern SURFACEINFO g_sfCharacterJump[2];
extern SURFACEINFO g_sfCharacterDown[2];
extern SURFACEINFO g_sfCloud[6];

void ___aInit(HDC hdc);