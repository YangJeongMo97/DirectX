#pragma once
#include <windows.h>
#include "resource.h"

extern HINSTANCE g_hInst;

BOOL PutSprite(HDC hdc, int x, int y, HDC memDc, COLORREF colorkey);