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

	//// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	//// ���� ����
	hWnd = CreateWindow(szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		2000, 100, 990, 540,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	//// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//// �޽��� ����
	// idle time�� Ȱ���ϱ� ���� �޽��� ����
	// GetMessage()  : �޽����� �������� ������ ������� �ѱ��� �ʴ´�
	// PeekMessage() : ������� �׻� �ѱ��
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0,
			PM_REMOVE)) // �޽��� ť���� �޽��� ����
		{
			if (msg.message == WM_QUIT) break;
			DispatchMessage(&msg);
		}
		else // �޽����� ������
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