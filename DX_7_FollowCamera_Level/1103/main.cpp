#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <iostream>
#include <Windows.h>
#include <d3dx9.h>
#include <d3dtypes.h>

void __KeyProc(HWND hWnd);

struct CUSTOMVERTEX {
    float fA, fB, fC, fU, fV;
    DWORD color;
};

struct MYINDEX {
    WORD _0, _1, _2;
};

LPDIRECT3D9             g_pD3D = NULL;
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVB;
LPDIRECT3DINDEXBUFFER9 g_pIB;

LPDIRECT3DTEXTURE9 g_pTexture1, g_pTexture2;

//ȸ�� ��Ʈ������ KeyProc()�� Render()������ ���Ǿ� �������� ����.
D3DXMATRIX matRotation;
//ȸ���� ��ŭ �̵��ϴ� ���� �����ϱ� ���� ����.
D3DXVECTOR3 g_vForward;

//ȸ���� �̵��� ���� ��
float g_fX, g_fY, g_fZ, g_fPitch, g_fYaw, g_fRoll;

HRESULT InitD3D(HWND hWnd)
{
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    d3dpp.Flags = D3DPRESENTFLAG_VIDEO;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &g_pd3dDevice)))
    {
        return E_FAIL;
    }
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
    g_pd3dDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);
    g_pd3dDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);

    D3DXCreateTextureFromFile(g_pd3dDevice, "Text.bmp", &g_pTexture1);
    D3DXCreateTextureFromFile(g_pd3dDevice, "World.bmp", &g_pTexture2);

    return S_OK;
}

HRESULT InitVertex() {
    CUSTOMVERTEX vertices[] = { {-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0xffffffff},   //0
                                {0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0xffffffff},   //1
                                {0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0xffffffff},   //2
                                {-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0xffffffff},   //3
                                {-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0xffffffff},   //4
                                {0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0xffffffff},   //5
                                {0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0xffffffff},   //6
                                {-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0xffffffff},   //7
                                //���� �Ʒ�, ���� �鿡 �ؽ��ĸ� ������ ���� ���� ����.
                                {-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0xffffffff},   //4'(8)
                                {0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0xffffffff},   //5'(9)
                                {0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0xffffffff},   //6'(10)
                                {-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0xffffffff},   //7'(11)
                                {-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0xffffffff},   //0'(12)
                                {-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0xffffffff}    //3'(13)
    };

    g_pd3dDevice->CreateVertexBuffer(14 * sizeof(CUSTOMVERTEX), 0, D3DFVF_XYZ, D3DPOOL_DEFAULT, &g_pVB, NULL);

    void* pVertices;

    g_pVB->Lock(0, sizeof(CUSTOMVERTEX), (void**)&pVertices, 0);
    memcpy(pVertices, vertices, sizeof(vertices));
    g_pVB->Unlock();

    return S_OK;
}

HRESULT InitIB() {
    MYINDEX indices[] = {
        { 0, 1, 2 }, { 0, 2, 3 },      // ��
        { 4, 6, 5 }, { 4, 7, 6 },      // ��
        { 11, 8, 12 }, { 11, 12, 13 }, // ��
        { 1, 5, 6 }, { 1, 6, 2 },      // ��
        { 8, 1, 0 }, { 8, 9, 1 },      // ��
        { 2, 11, 3 }, { 2, 10, 11 },    // ��
    };

    g_pd3dDevice->CreateIndexBuffer(14 * sizeof(MYINDEX), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &g_pIB, NULL);

    void* pIndices;

    g_pIB->Lock(0, sizeof(indices), (void**)&pIndices, 0);

    memcpy(pIndices, indices, sizeof(indices));

    g_pIB->Unlock();

    return S_OK;
}

VOID Cleanup()
{
    if (g_pTexture2 != NULL)
        g_pTexture2->Release();
    if (g_pTexture1 != NULL)
        g_pTexture1->Release();
    if (g_pIB != NULL)
        g_pIB->Release();
    if (g_pVB != NULL)
        g_pVB->Release();
    if (g_pd3dDevice != NULL)
        g_pd3dDevice->Release();
    if (g_pD3D != NULL)
        g_pD3D->Release();

}

VOID Render()
{
    static int count = 0;
    if (NULL == g_pd3dDevice)
        return;

    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        //���� ��ġ���� �ٶ󺸴� �������� ���� ����Ͽ� �̵�
        //���� ����� KeyProc()�� ����.
        g_fX += g_vForward.x;
        g_fY += g_vForward.y;
        g_fZ += g_vForward.z;

        D3DXMATRIX matTranslation, matWorld, tempView, tempTM;
        D3DXVECTOR3 vEyePt(0.0f, 1.0f, -5.0f);                  //ī�޶��� ��ġ
        D3DXVECTOR3 vLookatPt(g_fX, g_fY, g_fZ);                //ī�޶� �ٶ󺸴� ���� (���� �ڽ��� �߾�)
        D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
        if(g_fY > 0) D3DXMatrixLookAtLH(&tempView, &vEyePt, &vLookatPt, &vUpVec);   // y��ǥ ���� 0���� ũ�� ī�޶� ����
        else {                                                                      // 0���� �Ʒ��� ī�޶�� �¿�θ� ����
            vLookatPt.y = 0;
            D3DXMatrixLookAtLH(&tempView, &vEyePt, &vLookatPt, &vUpVec);
        }
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempView);

        D3DXMatrixIdentity(&tempTM);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM);

        D3DXMATRIX tempProjection;
        D3DXMatrixPerspectiveFovLH(&tempProjection, D3DX_PI * 0.5f, 1, 0.1f, 500.0f);     //zn���� 0.0f�̸� ���̰� ����� �ȵ�!
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);
        g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
        g_pd3dDevice->SetFVF(D3DFVF_XYZ | D3DFVF_TEX1);
        g_pd3dDevice->SetIndices(g_pIB);

        g_pd3dDevice->SetTexture(0, g_pTexture2);

        D3DXMatrixTranslation(&tempProjection, -5.1f, 1.5f, 0.3f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, 4.4f, 2.8f, 0.91f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, 11.7f, 0.3f, 0.70f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, 0.6f, 1.5f, -0.11f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, 15.1f, 16.5f, 0.153f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, -14.4f, -12.8f, 0.721f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, 2.7f, -7.3f, 1.0f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixTranslation(&tempProjection, 9.6f, 7.5f, -0.01f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempProjection);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        D3DXMatrixRotationYawPitchRoll(&matRotation, g_fYaw, g_fPitch, g_fRoll);        //ȸ��
        D3DXMatrixTranslation(&matTranslation, g_fX, g_fY, g_fZ);                       //Render() ���� �κп��� �ʱ�ȭ�� ���Ͱ���ŭ �̵�

        D3DXMatrixMultiply(&matWorld, &matRotation, &matTranslation);                   //ȸ�� �� �̵��� ����� ��.

        g_pd3dDevice->SetTexture(0, g_pTexture1);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 14, 0, 12);

        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        Cleanup();
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        Render();
        ValidateRect(hWnd, NULL);
        return 0;
    case WM_CHAR:
        switch (wParam) {
        case 'W':
        case 'w':
            g_fPitch += D3DX_PI * 0.015f;
            break;
        case 'A':
        case 'a':
            g_fYaw += D3DX_PI * 0.015f;
            break;
        case 'S':
        case 's':
            g_fPitch -= D3DX_PI * 0.015f;
            break;
        case 'D':
        case 'd':
            g_fYaw -= D3DX_PI * 0.015f;
            break;
        case 'Q':
        case 'q':
            g_fRoll += D3DX_PI * 0.015f;
            break;
        case 'E':
        case 'e':
            g_fRoll -= D3DX_PI * 0.015f;
            break;
        }
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      "D3D Tutorial", NULL };
    RegisterClassEx(&wc);
    HWND hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice",
        WS_OVERLAPPEDWINDOW, 100, 100, 600, 600,
        GetDesktopWindow(), NULL, wc.hInstance, NULL);

    if (SUCCEEDED(InitD3D(hWnd)))
    {
        if (SUCCEEDED(InitVertex())) {
            if (SUCCEEDED(InitIB())) {
                ShowWindow(hWnd, SW_SHOWDEFAULT);
                UpdateWindow(hWnd);
                MSG msg;
                ZeroMemory(&msg, sizeof(msg));
                while (msg.message != WM_QUIT) {
                    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                    {

                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                    }
                    __KeyProc(hWnd);
                    Render();
                }
            }
        }
    }
    UnregisterClass("D3D Tutorial", wc.hInstance);
    return 0;
}

void __KeyProc(HWND hWnd) {
    float fX = 0.0f, fY = 0.0f, fZ = 0.0f;
    if (GetKeyState(VK_LEFT) & 0x80)
    {
        fX -= 0.015f;
    }
    if (GetKeyState(VK_RIGHT) & 0x80)
    {
        fX += 0.015f;
    }
    if (GetKeyState(VK_UP) & 0x80)
    {
        fZ += 0.015f;
    }
    if (GetKeyState(VK_DOWN) & 0x80)
    {
        fZ -= 0.015f;
    }

    //���������� �̵����� ���Ϳ� ������ ȸ�� ��Ʈ������ ���� ���Ͱ��� ����.
    g_vForward.x = fX;
    g_vForward.y = fY;
    g_vForward.z = fZ;
    D3DXVec3TransformCoord(&g_vForward, &g_vForward, &matRotation);
}