#include <windows.h>

#define NUMLINES	30

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static CHAR szAppName[] = "GP";
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    RegisterClass(&wndclass);

    hwnd = CreateWindow(szAppName,                  // ������ Ŭ���� �̸�
        "Win32-����",               // ������ �μ�
        WS_OVERLAPPEDWINDOW,        // ������ ���
        CW_USEDEFAULT,              // X �����ġ
        CW_USEDEFAULT,              // Y �����ġ
        300,						  // ������ ����
        300,						  // ������ ����
        NULL,                       // �θ� ������ �ڵ�
        NULL,                       // ������ �޴� �ڵ�
        hInstance,                  // �ν���Ʈ �ڵ�
        NULL);                     // ������ ����

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC	hdc;	// DC�� ���� �ڵ�
    PAINTSTRUCT ps;
    char* szText = (char*)"������ ���ڿ� ���1";
    static int cyChar = 0, cxChar = 0, nVscrollPos = 0, nHscrollPos = 0, cyClient = 0, cxClient = 0;
    static char	strBuff[255] = "";
    int	y, i;
    TEXTMETRIC tm;
    

    switch (message)
    {
    case WM_CREATE:

        //// ��Ʈ ũ��
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        cyChar = tm.tmHeight;
        cxChar = tm.tmAveCharWidth;
        ReleaseDC(hwnd, hdc);     

        return 0;

    case WM_SIZE:
        //// lParam�� ���� 2����Ʈ : Ŭ���̾�Ʈ ������ ���� 
        cyClient = HIWORD(lParam);
        // lParam�� ���� 2����Ʈ : Ŭ���̾�Ʈ ������ �ʺ�
        cxClient = LOWORD(lParam);
        return 0;

    case WM_VSCROLL:
        //// wParam�� ���� 2����Ʈ : ������ư
        ////          ���� 2����Ʈ : thumb�� ��ġ
        //// lParam : ������ �ڵ�
        switch (LOWORD(wParam))
        //switch ((WORD)wParam)
        {
        case SB_LINEUP:
            nVscrollPos -= 1;
            break;

        case SB_LINEDOWN:
            if (nVscrollPos < NUMLINES - (cyClient / cyChar))
                nVscrollPos += 1;
            break;

        case SB_PAGEUP:
            nVscrollPos -= cyClient / cyChar;
            break;

        case SB_PAGEDOWN:
            nVscrollPos += cyClient / cyChar;
            break;

        case SB_THUMBPOSITION:
            nVscrollPos = HIWORD(wParam);
            break;

        default:
            break;
        }
        nVscrollPos = max(0, min(nVscrollPos, NUMLINES - cyClient / cyChar));
        if (nVscrollPos != GetScrollPos(hwnd, SB_VERT))
        {
            SetScrollPos(hwnd, SB_VERT, nVscrollPos, TRUE);
            InvalidateRect(hwnd, NULL, TRUE);
        }
        return 0;

    case WM_HSCROLL:
        switch (LOWORD(wParam)) {
        case SB_LINELEFT:
            if(nHscrollPos > 0)
                nHscrollPos -= 1;
            break;

        case SB_LINERIGHT:
            if (nHscrollPos < strlen(strBuff) - cxClient / cxChar)
                nHscrollPos += 1;
            break;

        case SB_PAGELEFT:
            nHscrollPos -= cxChar;
            break;

        case SB_PAGERIGHT:
            nHscrollPos += cxChar;
            break;

        case SB_THUMBPOSITION:
            nHscrollPos = LOWORD(wParam);
            break;

        default:
            break;
        }
        nHscrollPos = max(0, min(nHscrollPos, strlen(strBuff) - cxClient / cxChar));

        if (nHscrollPos != GetScrollPos(hwnd, SB_HORZ))
        {
            SetScrollPos(hwnd, SB_HORZ, nHscrollPos, TRUE);
            InvalidateRect(hwnd, NULL, TRUE);
        }
        return 0;

    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        //hdc = GetDC(hwnd);
        
        {
            for (i = 0; i < NUMLINES; i++)
            {
                y = cyChar * (i - nVscrollPos);

                wsprintf(strBuff, "Scrollbar %2d, VSPos %2d, y %3d", i, nVscrollPos, y);
                TextOut(hdc, 10, y, strBuff + nHscrollPos, strlen(strBuff) - nHscrollPos);
                //ValidateRect(hwnd, NULL);
            }
            if (cyClient >= y + cyChar * 2) {
                if(nVscrollPos > 0)
                    nVscrollPos--;
            }
            if (cxClient / cxChar >= strlen(strBuff) - nHscrollPos) {
                if (nHscrollPos > 0)
                    nHscrollPos--;
            }
        }

        SetScrollRange(hwnd,
            SB_VERT,		//	���� 
            0,			//	�ּ�
            NUMLINES - (cyClient / cyChar),	//	�ִ�
            FALSE);		//	redraw ����
        SetScrollPos(hwnd,
            SB_VERT,
            nVscrollPos,	// thumb ��ġ
            FALSE);		// redraw ����
        
        SetScrollRange(hwnd,
            SB_HORZ,		//	����
            0,
            strlen(strBuff) - (cxClient / cxChar),
            FALSE);
        SetScrollPos(hwnd,
            SB_HORZ,
            nHscrollPos,
            FALSE);

        
        //ReleaseDC(hwnd, hdc);

        EndPaint(hwnd, &ps);

        return 0;

    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        return 0;
    }
    

    return DefWindowProc(hwnd, message, wParam, lParam);
}
