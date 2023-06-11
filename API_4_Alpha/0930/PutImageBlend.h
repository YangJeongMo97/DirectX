#pragma once
#include <windows.h>
#include "resource.h"

extern HINSTANCE g_hInst;

BOOL PutImageBlend(HDC hdc, int x, int y, HDC memDc, int nAlpha);