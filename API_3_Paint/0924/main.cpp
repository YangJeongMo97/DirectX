#include "totalHeader.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;

//// WinMain 함수 : 윈도즈 프로그램의 최초 진입점 ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR	  lpCmdLine,
    int		  nCmdShow)
{
    char	  szAppName[] = "내가 만든 기린 그림판";
    HWND	  hWnd;
    MSG      msg;
    WNDCLASS wndclass;

    g_hInst = hInstance;

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
        100, 100, 1172, 648,
        NULL, NULL, hInstance, NULL);

    if (!hWnd) return FALSE;

    //// 생성된 윈도를 화면에 표시
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    //// 메시지 루프
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

int clientX = 1156, clientY = 609;
int nSelectFigure, nSelectPenStyle = PS_SOLID, nSelectHatchBrush = HS_API_MAX, nPenWidth = 1,
    nRed_Pen = 0, nGreen_Pen = 0, nBlue_Pen = 0, nRed_Brush = 0, nGreen_Brush = 0, nBlue_Brush = 0;
int nTextStyle = SELECT_NORMAL;
RECT menuField;
COLORREF rgbPen = RGB(0, 0, 0), rgbBrush = RGB(0, 0, 0);
HWND hRed_Pen, hGreen_Pen, hBlue_Pen, hRed_Brush, hGreen_Brush, hBlue_Brush, hWidth, hTemp;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam)
{
    static BOOL bDrawing = FALSE;
    static BOOL bTyping = FALSE;
    static int  x1, y1, x2, y2;
    static char string[256];
    static int nLength = 0;
    int TempPos;
    menuField.left = 0;
    menuField.right = 1152;
    menuField.top =  448;
    menuField.bottom = 628;

    PAINTSTRUCT ps;

    switch (message)
    {
    case WM_CREATE:
        //펜 색상 지정 스크롤바 만들기
        hRed_Pen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 630,
            clientY - 160, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        hGreen_Pen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 630,
            clientY - 130, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        hBlue_Pen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 630,
            clientY - 100, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        SetScrollRange(hRed_Pen, SB_CTL, 0, 255, TRUE);
        SetScrollPos(hRed_Pen, SB_CTL, 0, TRUE);
        SetScrollRange(hGreen_Pen, SB_CTL, 0, 255, TRUE);
        SetScrollPos(hGreen_Pen, SB_CTL, 0, TRUE);
        SetScrollRange(hBlue_Pen, SB_CTL, 0, 255, TRUE);
        SetScrollPos(hBlue_Pen, SB_CTL, 0, TRUE);

        //펜 두께 지정 스크롤바 만들기
        hWidth = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 630,
            clientY - 50, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        SetScrollRange(hWidth, SB_CTL, 1, 20, TRUE);
        SetScrollPos(hWidth, SB_CTL, 1, TRUE);

        //브러쉬 색상 지정 스크롤바 만들기
        hRed_Brush = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 840,
            clientY - 160, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        hGreen_Brush = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 840,
            clientY - 130, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        hBlue_Brush = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 840,
            clientY - 100, 200, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
        SetScrollRange(hRed_Brush, SB_CTL, 0, 255, TRUE);
        SetScrollPos(hRed_Brush, SB_CTL, 0, TRUE);
        SetScrollRange(hGreen_Brush, SB_CTL, 0, 255, TRUE);
        SetScrollPos(hGreen_Brush, SB_CTL, 0, TRUE);
        SetScrollRange(hBlue_Brush, SB_CTL, 0, 255, TRUE);
        SetScrollPos(hBlue_Brush, SB_CTL, 0, TRUE);
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    
    case WM_HSCROLL:
        if ((HWND)lParam == hRed_Pen) TempPos = nRed_Pen;
        if ((HWND)lParam == hGreen_Pen) TempPos = nGreen_Pen;
        if ((HWND)lParam == hBlue_Pen) TempPos = nBlue_Pen;
        if ((HWND)lParam == hRed_Brush) TempPos = nRed_Brush;
        if ((HWND)lParam == hGreen_Brush) TempPos = nGreen_Brush;
        if ((HWND)lParam == hBlue_Brush) TempPos = nBlue_Brush;

        if ((HWND)lParam == hWidth) {
            TempPos = nPenWidth;
            switch (LOWORD(wParam)) {
            case SB_LINELEFT:
                TempPos = max(1, TempPos - 1);
                break;
            case SB_LINERIGHT:
                TempPos = min(20, TempPos + 1);
                break;
            case SB_PAGELEFT:
                TempPos = max(1, TempPos - 5);
                break;
            case SB_PAGERIGHT:
                TempPos = min(20, TempPos + 5);
                break;
            case SB_THUMBTRACK:
                TempPos = HIWORD(wParam);
                break;
            }
        }
        else {
            switch (LOWORD(wParam)) {
            case SB_LINELEFT:
                TempPos = max(0, TempPos - 1);
                break;
            case SB_LINERIGHT:
                TempPos = min(255, TempPos + 1);
                break;
            case SB_PAGELEFT:
                TempPos = max(0, TempPos - 10);
                break;
            case SB_PAGERIGHT:
                TempPos = min(255, TempPos + 10);
                break;
            case SB_THUMBTRACK:
                TempPos = HIWORD(wParam);
                break;
            }
        }
        if ((HWND)lParam == hRed_Pen) nRed_Pen = TempPos;
        if ((HWND)lParam == hGreen_Pen) nGreen_Pen = TempPos;
        if ((HWND)lParam == hBlue_Pen) nBlue_Pen = TempPos;
        if ((HWND)lParam == hWidth) nPenWidth = TempPos;
        if ((HWND)lParam == hRed_Brush) nRed_Brush = TempPos;
        if ((HWND)lParam == hGreen_Brush) nGreen_Brush = TempPos;
        if ((HWND)lParam == hBlue_Brush) nBlue_Brush = TempPos;
        SetScrollPos((HWND)lParam, SB_CTL, TempPos, TRUE);
        InvalidateRect(hWnd, NULL, FALSE);
        break;
        
    case WM_LBUTTONDOWN:
        x1 = x2 = LOWORD(lParam);
        y1 = y2 = HIWORD(lParam);
        //// 커서가 영역밖을 벗어나도 지속적 마우스 메시지를 받을 수 있다
        SetCapture(hWnd);
        bDrawing = TRUE;
        bTyping = FALSE;
        if (y1 > clientY - 200) {
            bDrawing = FALSE;
            bTyping = FALSE;
            SelectMenu(hWnd, x1, y1, clientY, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, nTextStyle, rgbPen, rgbBrush);
            ReleaseCapture();
            InvalidateRect(hWnd, &menuField, TRUE);
        }
        else {
            SetCursor(LoadCursor(NULL, IDC_CROSS));
            bTyping = TRUE;
            string[0] = '\0';
            nLength = 0;
        }
        break;

    case WM_MOUSEMOVE:
        if (bDrawing)
        {
            SetCursor(LoadCursor(NULL, IDC_CROSS));
            Sketch(hWnd, x1, y1, x2, y2, FALSE, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, nPenWidth, rgbPen, rgbBrush);
            x2 = LOWORD(lParam);
            y2 = HIWORD(lParam);
            if (x2 >= 0xf000)
                x2 = 0x0000;
            if (y2 >= 0xf000)
                y2 = 0x0000;
            else if (y2 > clientY - 200)
                y2 = clientY - 200;
            Sketch(hWnd, x1, y1, x2, y2, FALSE, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, nPenWidth, rgbPen, rgbBrush);
        }
        break;

    case WM_LBUTTONUP:
        if (bDrawing)
        {
            Sketch(hWnd, x1, y1, x2, y2, FALSE, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, nPenWidth, rgbPen, rgbBrush);
            //// 마우스 캡처를 푼다
            ReleaseCapture();
            bDrawing = FALSE;
            UpdateWindow(hWnd);
            Draw(hWnd, x1, y1, x2, y2, nLength, string, FALSE, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, nTextStyle, nPenWidth, rgbPen, rgbBrush);
        }
        break;

    case WM_CHAR:
        if (bTyping) {
            if(nSelectFigure == SELECT_TEXT)
                string[nLength++] = (char)wParam;
            if (wParam == 13) {
                string[0] = '\0';
                nLength = 0;
                bTyping = FALSE;
            }
            InvalidateRect(hWnd, NULL, FALSE);
        }
        else {
            SelectMenuByKey(wParam, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, rgbPen, rgbBrush);
            InvalidateRect(hWnd, &menuField, TRUE);
        }
        break;

    case WM_SIZE:
        clientX = LOWORD(lParam);
        clientY = HIWORD(lParam);
        Menu(hWnd, clientX, clientY, g_hInst);
        menuField.left = 0;
        menuField.right = clientX;
        menuField.top = clientY - 200;
        menuField.bottom = clientY;
        break;

    case WM_PAINT:
        HDC hdc;
        hdc = BeginPaint(hWnd, &ps);
        rgbPen = RGB(nRed_Pen, nGreen_Pen, nBlue_Pen);
        rgbBrush = RGB(nRed_Brush, nGreen_Brush, nBlue_Brush);
        if (bTyping)
            DrawTextTyping(hWnd, x1, y1 - 16, nLength, string, nTextStyle, bTyping, rgbPen, rgbBrush);
        else {
            Menu(hWnd, clientX, clientY, g_hInst);
            PreViewFigure(hWnd, clientY, nSelectFigure, nSelectPenStyle, nSelectHatchBrush, nTextStyle, nPenWidth, rgbPen, rgbBrush);
        }
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}