#include "___aMainLoop.h"
#include "___aDestroyAll.h"
#include "__KeyProc.h"

#define GROUND 470

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;
HWND hWndMain;
LPSTR lpszClass = "API_06_HOMEWORK";

SURFACEINFO g_sfBack;			
SURFACEINFO g_sfBG;				
SURFACEINFO g_sfCharacterStand[4];
SURFACEINFO g_sfCharacterWalk[4];
SURFACEINFO g_sfCharacterJump[2];
SURFACEINFO g_sfCharacterDown[2];
SURFACEINFO g_sfCloud[6];

int nCharacterX = 200, nCharacterY = GROUND, nBgX = 0;
BOOL bLimitLeft = FALSE, bLimitRight = FALSE, bWalk = FALSE, bJump = FALSE, bGetDown = FALSE, bLeft = FALSE;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_SYSMENU | WS_CAPTION, //WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1000, 620,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	hWndMain = hWnd;

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!GetMessage(&msg, NULL, 0, 0)) return (int)msg.wParam;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			bWalk = FALSE;
			bGetDown = FALSE;
		}
		else {
			__KeyProc(hWnd);
			___aMainLoop(hWnd);
		}
	}
	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;

	switch (iMessage)
	{
	case WM_CREATE:
		//// 표면 생성 및 기타
		hdc = GetDC(hWnd);
		___aInit(hdc);
		ReleaseDC(hWnd, hdc);
		return 0;

	case WM_DESTROY:
		___aDestroyAll();
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}