#include <windows.h>
//#define IDR_MENU1 101                                      //IpszMenuName ����� �� �޴� �̸�

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);         //�ݹ� �Լ�, ���������� ȣ��Ǵ� �Լ� X. �����쿡 �� �Լ��� ��ġ�� �˷��ְ� �����찡 �ʿ��� ��, ������ ��.

//// ���� �Լ� : ������ ���α׷��� ���� ������ ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,		                //HINSTANCE = INSTANCE HANDLE �������� �ü������ ����Ǵ� ���α׷����� �����ϱ� ���� ID��
    HINSTANCE hPrevInstance,
    PSTR szCmdLine,				                //pointer string�� ���Ӹ� ����, char* ����
    int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWin");
    HWND         hwnd;		                                //���α׷� ���۷��� �ڵ� ����
    MSG          msg;			                                //�޼��� ����ü
    WNDCLASS     wndclass;	                                //class�ƴϰ� ����ü

    wndclass.style = CS_HREDRAW | CS_VREDRAW;             //Ŭ���̾�Ʈ ����(�۾�||����� ����)�� ���� ���̰� ����Ǿ����� ���� �ٽ� �׸����� �����ִ� style ����.

    wndclass.lpfnWndProc = WndProc;					        //�ݹ� �Լ� �����쿡 �Ѱ���
    wndclass.cbClsExtra = 0;                               //int��, Ŭ������ ���� ������ �޸� ũ��
    wndclass.cbWndExtra = 0;                               //�����츦 ���� ������ �޸� ũ��
    wndclass.hInstance = hInstance;                       //WinMain�� �Ű����� �� ù��° �Ű������� ���� ���α׷� �ν��Ͻ��� ���� �Ѱ���
    wndclass.hIcon = LoadIcon(NULL,
        IDI_APPLICATION);	                                //�⺻ ������ ����
    wndclass.hCursor = LoadCursor(NULL,
        IDC_ARROW);		                                     //�⺻ Ŀ�� ����
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //��� ���� ����

    wndclass.lpszMenuName = NULL;                //MAKEINTRESOURCE(IDR_MENU1);       //NULL = �޴� ����. MAKEINTRESOURCE() = �Ű�����(������)�� ���ڷ� �ٲپ��ֱ����� ��ũ��
    wndclass.lpszClassName = szAppName;                       //Ŭ���� �̸�.

    //// ������ Ŭ���� ���        -> ������ ���� �� ������ Ŭ���� ����
    // CreateWindow()�� �����츦 �����ϱ� ���� �ݵ�� ��ϵǾ� �־�� �Ѵ�
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"),         //Ŭ���� ��� ���н� ��� �Ǵ� �޼��� â.
            szAppName, MB_ICONINFORMATION);
        return 0;
    }

    //// ������ ����
    hwnd = CreateWindow(szAppName,                            //Ŭ���� �̸�
        TEXT("The Hello Program"),		    //�����쿡 ��µ� Ÿ��Ʋ �̸�
        WS_OVERLAPPEDWINDOW,                  //������ ��Ÿ��
        CW_USEDEFAULT,                                //������ ��ġ x��ǥ
        CW_USEDEFAULT,                                //������ ��ġ y��ǥ
        CW_USEDEFAULT,                        //������ ����ũ��
        CW_USEDEFAULT,                        //������ ����ũ�� ���� default ������ �ʱ�ȭ ��
        NULL,                                 //�θ��� ������ �ڵ��� ���� ��ġ. �����Ƿ� NULL
        NULL,                                 //�޴� �ڵ�. �޴��� ������ ��, resource���Ϸ� �����ϸ� NULL�� �س��� ��.
        hInstance,                            //���� ���α׷� �ν��Ͻ�. WinMain�� ù��° �Ű������� ����.
        NULL);                               //���� ������ ����(Parameter)

//// ������ �����츦 ȭ�鿡 ǥ��
    ShowWindow(hwnd, iCmdShow);

    UpdateWindow(hwnd);					                    //������ ���ν����� WM_PAINT �޼����� ���� �۾� ������ ������ �׸��� �ϴ� �Լ�.
                                                               //�޼��� ť�� ������ �ʾ� ��� �۵��Ѵ� ��.
    //// �޽��� ����
    while (GetMessage(&msg,
        NULL, 0, 0))
    {
        TranslateMessage(&msg);			      //�޼����� ����Ǿ����� ���� ���ִ� �Լ�. �ڼ��� ������ soen.kr -> API -> ���۷���
        DispatchMessage(&msg);			      //������ ���ν����� ������ ���� �����ϴ� �Լ�. (CALLBACK �Լ��� ȣ��Ǹ� ���� �ϴµ�?)
    }
    return msg.wParam;                          //WinMain�� ���� �� msg.wParam �����ϴ°��� �����ΰ� ����. C���� return 0;������
}

//// LRESULT == long
//// Window Procedure�� ���α׷����� ȣ���ϴ� ���� �ƴ϶� Windows�� ���� ȣ��ȴ� ( CALLBACK )

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;		                //��¿� ���� ����ü
    PAINTSTRUCT ps;		                //����ü �ȿ� HDC ����
    RECT        rect;                     //�簢�� ��ǥ �����ϴ� ����ü

    switch (message)
    {
        // �����찡 ǥ�õǱ� ��, �����찡 ���� �ɶ� 
    case WM_CREATE:
        MessageBox(hwnd,
            TEXT("WM_CREATE "),
            TEXT("�����츦 �����մϴ�."),
            0);
        return 0;

        // ȭ���� ��ȿȭ ( ���� )
    case WM_PAINT:                                 //�̺�Ʈ�� �߻����� ��, ȭ�� ó���� �̰����� �ϴ°�?
        hdc = BeginPaint(hwnd, &ps);

        GetClientRect(hwnd, &rect);                 //������ ��ǥ��ŭ�� ������ ����

        DrawText(hdc,
            TEXT("Hello, Windows!"),
            -1,
            &rect,
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);    

        EndPaint(hwnd, &ps);                  //WM_PAINT���� �׸��⸦ �����ϱ� ���� �Լ�.
        return 0;

        // ������ ���� �õ� ( �����ư�� )
    case WM_DESTROY:
        PostQuitMessage(0);					//WM_QUIT�� wParam���� ���޵�. �Ϲ������� 0���� ����				
        return 0;

    /*
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case 40001:
            MessageBox(hwnd, TEXT("ù��° �޴� ����"), TEXT("MENU PRACTICE"), MB_OK); // 40001 = �޴� �ڵ鰪�ε�? MB_OK = 0�̹Ƿ� �޼����ڽ� ����ϴ°��ε�
        }
    */
    }

    return DefWindowProc(hwnd, message, wParam, lParam);     //�޾Ҵ� �Ű������� �����ϸ� �޼����� ó���� ����� ����
}