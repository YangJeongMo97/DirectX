#pragma once
#include <windows.h>
#include "resource.h"

extern HINSTANCE g_hInst;

BOOL PutImage(HDC hdc, int x, int y, HDC memDc);