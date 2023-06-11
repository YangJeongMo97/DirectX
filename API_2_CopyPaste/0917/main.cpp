#include "RandRect.h"
#include <time.h>

void DrawFigure(HWND hWnd);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR	  lpCmdLine,
	int		  nCmdShow)
{
	srand((unsigned)time(NULL));

	char	  szAppName[] = "Random Figure";
	HWND	  hWnd;
	MSG      msg;
	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	//// 윈도 클래스 등록
	RegisterClass(&wndclass);

	//// 윈도 생성
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		2000, 100, 990, 540,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	//// 생성된 윈도를 화면에 표시
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//// 메시지 루프
	// idle time을 활용하기 위한 메시지 루프
	// GetMessage()  : 메시지를 가져오기 전에는 제어권을 넘기지 않는다
	// PeekMessage() : 제어권을 항상 넘긴다
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0,
			PM_REMOVE)) // 메시지 큐에서 메시지 제거
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else // 메시지가 없으면
		{
			DrawFigure(hWnd);
			InvalidateRect(hWnd, NULL, TRUE);
		}
	}
	return (int)msg.wParam;
}

int g_nWidth, g_nHeight;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
		g_nWidth = LOWORD(lParam);
		g_nHeight = HIWORD(lParam);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void DrawFigure(HWND hWnd)
{
	HDC    hdc;

	hdc = GetDC(hWnd);

	RandRect(hdc, g_nWidth, g_nHeight);

	ValidateRect(hWnd, NULL);

	Sleep(1000);
}