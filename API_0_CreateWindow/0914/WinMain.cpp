#include <windows.h>
//#define IDR_MENU1 101                                      //IpszMenuName 멤버에 들어갈 메뉴 이름

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);         //콜백 함수, 직접적으로 호출되는 함수 X. 윈도우에 이 함수의 위치를 알려주고 윈도우가 필요할 때, 가져다 씀.

//// 메인 함수 : 윈도우 프로그램의 최초 진입점 ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,		                //HINSTANCE = INSTANCE HANDLE 윈도우즈 운영체제에서 실행되는 프로그램들을 구별하귀 위한 ID값
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,				                //pointer string의 줄임말 같음, char* 형식
    int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWin");
    HWND         hwnd;		                                //프로그램 레퍼런스 핸들 생성
    MSG          msg;			                                //메세지 구조체
    WNDCLASS     wndclass;	                                //class아니고 구조체

    wndclass.style = CS_HREDRAW | CS_VREDRAW;             //클라이언트 영역(작업||사용자 영역)의 폭과 높이가 변경되었을때 전부 다시 그리도록 도와주는 style 형식.

    wndclass.lpfnWndProc = WndProc;					        //콜백 함수 윈도우에 넘겨줌
    wndclass.cbClsExtra = 0;                               //int형, 클래스를 위한 여분의 메모리 크기
    wndclass.cbWndExtra = 0;                               //윈도우를 위한 여분의 메모리 크기
    wndclass.hInstance = hInstance;                       //WinMain의 매개변수 중 첫번째 매개변수를 응용 프로그램 인스턴스의 값을 넘겨줌
    wndclass.hIcon = LoadIcon(NULL,
        IDI_APPLICATION);	                                //기본 아이콘 지정
    wndclass.hCursor = LoadCursor(NULL,
        IDC_ARROW);		                                     //기본 커서 지정
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //배경 색상 지정

    wndclass.lpszMenuName = NULL;                //MAKEINTRESOURCE(IDR_MENU1);       //NULL = 메뉴 없음. MAKEINTRESOURCE() = 매개변수(정수형)을 문자로 바꾸어주기위한 매크로
    wndclass.lpszClassName = szAppName;                       //클래스 이름.

    //// 윈도우 클래스 등록        -> 위에서 생성 한 윈도우 클래스 전달
    // CreateWindow()로 윈도우를 생성하기 전에 반드시 등록되어 있어야 한다
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"),         //클래스 등록 실패시 출력 되는 메세지 창.
            szAppName, MB_ICONINFORMATION);
        return 0;
    }

    //// 윈도우 생성
    hwnd = CreateWindow(szAppName,                            //클래스 이름
        TEXT("The Hello Program"),		    //윈도우에 출력될 타이틀 이름
        WS_OVERLAPPEDWINDOW,                  //윈도우 스타일
        CW_USEDEFAULT,                                //윈도우 위치 x좌표
        CW_USEDEFAULT,                                //윈도우 위치 y좌표
        CW_USEDEFAULT,                        //윈도우 가로크기
        CW_USEDEFAULT,                        //윈도우 세로크기 전부 default 값으로 초기화 함
        NULL,                                 //부모의 윈도우 핸들이 들어가는 위치. 없으므로 NULL
        NULL,                                 //메뉴 핸들. 메뉴를 생성할 때, resource파일로 생성하면 NULL로 해놔도 됨.
        hInstance,                            //응용 프로그램 인스턴스. WinMain의 첫번째 매개변수를 받음.
        NULL);                               //생성 윈도우 정보(Parameter)

//// 생성된 윈도우를 화면에 표시
    ShowWindow(hwnd, iCmdShow);

    UpdateWindow(hwnd);					                    //윈도우 프로시저로 WM_PAINT 메세지를 보내 작업 영역을 강제로 그리게 하는 함수.
                                                               //메세지 큐를 통하지 않아 즉시 작동한다 함.
    //// 메시지 루프
    while (GetMessage(&msg,
        NULL, 0, 0))
    {
        TranslateMessage(&msg);			      //메세지가 변경되었는지 리턴 해주는 함수. 자세한 설명은 soen.kr -> API -> 레퍼런스
        DispatchMessage(&msg);			      //윈도우 프로시저가 리턴한 값을 리턴하는 함수. (CALLBACK 함수가 호출되면 리턴 하는듯?)
    }
    return msg.wParam;                          //WinMain은 종료 시 msg.wParam 리턴하는것이 관례인거 같다. C에서 return 0;같은거
}

//// LRESULT == long
//// Window Procedure는 프로그램에서 호출하는 것이 아니라 Windows로 부터 호출된다 ( CALLBACK )

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;		                //출력에 관한 구조체
    PAINTSTRUCT ps;		                //구조체 안에 HDC 포함
    RECT        rect;                     //사각형 좌표 저장하는 구조체

    switch (message)
    {
        // 윈도우가 표시되기 전, 윈도우가 생성 될때 
    case WM_CREATE:
        MessageBox(hwnd,
            TEXT("WM_CREATE "),
            TEXT("윈도우를 생성합니다."),
            0);
        return 0;

        // 화면이 무효화 ( 갱신 )
    case WM_PAINT:                                 //이벤트가 발생했을 때, 화면 처리는 이곳에서 하는가?
        hdc = BeginPaint(hwnd, &ps);

        GetClientRect(hwnd, &rect);                 //설정된 좌표만큼의 윈도우 생성

        DrawText(hdc,
            TEXT("Hello, Windows!"),
            -1,
            &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);    

        EndPaint(hwnd, &ps);                  //WM_PAINT에서 그리기를 종료하기 위한 함수.
        return 0;

        // 윈도우 종료 시도 ( 종료버튼등 )
    case WM_DESTROY:
        PostQuitMessage(0);					//WM_QUIT의 wParam으로 전달됨. 일반적으로 0으로 전달				
        return 0;

    /*
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 40001:
            MessageBox(hwnd, TEXT("첫번째 메뉴 선택"), TEXT("MENU PRACTICE"), MB_OK); // 40001 = 메뉴 핸들값인듯? MB_OK = 0이므로 메세지박스 출력하는거인듯
        }
    */
    }

    return DefWindowProc(hwnd, message, wParam, lParam);     //받았던 매개변수를 전달하며 메세지를 처리한 결과를 리턴
}