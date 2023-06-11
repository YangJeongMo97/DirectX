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

    hwnd = CreateWindow(szAppName,                  // 윈도우 클래스 이름
        "Win32-예제",               // 윈도우 켑션
        WS_OVERLAPPEDWINDOW,        // 윈도우 모양
        CW_USEDEFAULT,              // X 출력위치
        CW_USEDEFAULT,              // Y 출력위치
        300,						  // 윈도우 넓이
        300,						  // 윈도우 높이
        NULL,                       // 부모 윈도우 핸들
        NULL,                       // 윈도우 메뉴 핸들
        hInstance,                  // 인스턴트 핸들
        NULL);                     // 사용되지 않음

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
    HDC	hdc;	// DC에 대한 핸들
    PAINTSTRUCT ps;
    char* szText = (char*)"윈도우 문자열 출력1";
    static int cyChar = 0, cxChar = 0, nVscrollPos = 0, nHscrollPos = 0, cyClient = 0, cxClient = 0;
    static char	strBuff[255] = "";
    int	y, i;
    TEXTMETRIC tm;
    

    switch (message)
    {
    case WM_CREATE:

        //// 폰트 크기
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        cyChar = tm.tmHeight;
        cxChar = tm.tmAveCharWidth;
        ReleaseDC(hwnd, hdc);     

        return 0;

    case WM_SIZE:
        //// lParam의 상위 2바이트 : 클라이언트 영역의 높이 
        cyClient = HIWORD(lParam);
        // lParam의 하위 2바이트 : 클라이언트 영역의 너비
        cxClient = LOWORD(lParam);
        return 0;

    case WM_VSCROLL:
        //// wParam의 하위 2바이트 : 눌린버튼
        ////          상위 2바이트 : thumb의 위치
        //// lParam : 윈도우 핸들
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
            SB_VERT,		//	수직 
            0,			//	최소
            NUMLINES - (cyClient / cyChar),	//	최대
            FALSE);		//	redraw 여부
        SetScrollPos(hwnd,
            SB_VERT,
            nVscrollPos,	// thumb 위치
            FALSE);		// redraw 여부
        
        SetScrollRange(hwnd,
            SB_HORZ,		//	수평
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
