#include "Menu.h"

void Menu(HWND hWnd, int clientX, int clientY, HINSTANCE g_hInst) {
	HDC hdc = GetDC(hWnd);
	HPEN oldPen, newPen;
	HBRUSH oldBrush, newBrush;

	//�޴� ���
	SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
	//Rectangle(hdc, 0, clientY - 200, clientX, clientY);
	MoveToEx(hdc, 0, clientY - 200, NULL);
	LineTo(hdc, clientX, clientY - 200);
	MoveToEx(hdc, 435, clientY - 200, NULL);
	LineTo(hdc, 435, clientY);
	MoveToEx(hdc, 625, clientY - 200, NULL);
	LineTo(hdc, 625, clientY);
	MoveToEx(hdc, 835, clientY - 200, NULL);
	LineTo(hdc, 835, clientY);
	MoveToEx(hdc, 625, clientY - 75, NULL);
	LineTo(hdc, clientX, clientY - 75);

	//1�� 1�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 10, clientY - 190, 60, clientY - 140);
	MoveToEx(hdc, 20, clientY - 180, NULL);
	LineTo(hdc, 40, clientY - 155);
	LineTo(hdc, 45, clientY - 160);
	LineTo(hdc, 50, clientY - 150);

	//1�� 2�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 70, clientY - 190, 120, clientY - 140);
	MoveToEx(hdc, 80, clientY - 180, NULL);
	LineTo(hdc, 110, clientY - 150);

	//1�� 3�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 130, clientY - 190, 180, clientY - 140);
	Rectangle(hdc, 140, clientY - 180, 170, clientY - 150);

	//1�� 4�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 190, clientY - 190, 240, clientY - 140);
	RoundRect(hdc, 200, clientY - 180, 230, clientY - 150, 10, 10);

	//1�� 5�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 250, clientY - 190, 300, clientY - 140);
	Ellipse(hdc, 260, clientY - 180, 290, clientY - 150);

	//2�� 1�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 10, clientY - 130, 60, clientY - 80);
	newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, newPen);
	MoveToEx(hdc, 20, clientY - 120, NULL);
	LineTo(hdc, 50, clientY - 90);
	SelectObject(hdc, oldPen);

	//2�� 2�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 70, clientY - 130, 120, clientY - 80);
	newPen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, newPen);
	MoveToEx(hdc, 80, clientY - 120, NULL);
	LineTo(hdc, 110, clientY - 90);
	SelectObject(hdc, oldPen);

	//2�� 3�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 130, clientY - 130, 180, clientY - 80);
	newPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, newPen);
	MoveToEx(hdc, 140, clientY - 120, NULL);
	LineTo(hdc, 170, clientY - 90);
	SelectObject(hdc, oldPen);

	//2�� 4�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 190, clientY - 130, 240, clientY - 80);
	newPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, newPen);
	MoveToEx(hdc, 200, clientY - 120, NULL);
	LineTo(hdc, 230, clientY - 90);
	SelectObject(hdc, oldPen);

	//2�� 5�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 250, clientY - 130, 300, clientY - 80);
	newPen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
	oldPen = (HPEN)SelectObject(hdc, newPen);
	MoveToEx(hdc, 260, clientY - 120, NULL);
	LineTo(hdc, 290, clientY - 90);
	SelectObject(hdc, oldPen);

	//3�� 1�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 10, clientY - 70, 60, clientY - 20);
	SelectObject(hdc, GetStockObject(BLACK_BRUSH));
	Ellipse(hdc, 20, clientY - 60, 50, clientY - 30);

	//3�� 2�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 70, clientY - 70, 120, clientY - 20);
	newBrush = CreateHatchBrush(HS_VERTICAL, RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
	Ellipse(hdc, 80, clientY - 60, 110, clientY - 30);
	SelectObject(hdc, oldBrush);

	//3�� 3�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 130, clientY - 70, 180, clientY - 20);
	newBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
	Ellipse(hdc, 140, clientY - 60, 170, clientY - 30);
	SelectObject(hdc, oldBrush);

	//3�� 4�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 190, clientY - 70, 240, clientY - 20);
	newBrush = CreateHatchBrush(HS_CROSS, RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
	Ellipse(hdc, 200, clientY - 60, 230, clientY - 30);
	SelectObject(hdc, oldBrush);

	//3�� 5�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 250, clientY - 70, 300, clientY - 20);
	newBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
	Ellipse(hdc, 260, clientY - 60, 290, clientY - 30);
	SelectObject(hdc, oldBrush);

	//3�� 6�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 310, clientY - 70, 360, clientY - 20);
	newBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
	Ellipse(hdc, 320, clientY - 60, 350, clientY - 30);
	SelectObject(hdc, oldBrush);

	//3�� 7�� �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 370, clientY - 70, 420, clientY - 20);
	newBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 0));
	oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
	Ellipse(hdc, 380, clientY - 60, 410, clientY - 30);
	SelectObject(hdc, oldBrush);

	//�ؽ�Ʈ �޴�
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 310, clientY - 190, 420, clientY - 160);
	TextOut(hdc, 320, clientY - 180, "�⺻ �ؽ�Ʈ", strlen("�⺻ �ؽ�Ʈ"));

	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 310, clientY - 150, 420, clientY - 120);
	TextOut(hdc, 320, clientY - 140, "���� �ؽ�Ʈ", strlen("���� �ؽ�Ʈ"));

	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 310, clientY - 110, 420, clientY - 80);
	TextOut(hdc, 320, clientY - 100, "��� �ؽ�Ʈ", strlen("��� �ؽ�Ʈ"));

	//�̸����� ��
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, 445, clientY - 190, 615, clientY - 20);

	//�� ���� ����
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, 690, clientY - 190, "�� RGB ����", strlen("�� RGB ����"));

	//�귯�� ���� ����
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, 870, clientY - 190, "�귯�� RGB ����", strlen("�귯�� RGB ����"));

	//�� �β� ����
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, 690, clientY - 70, "�� �β� ����", strlen("�� �β� ����"));

	//���찳
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, clientX - 110, clientY - 190, clientX - 10, clientY - 140);
	TextOut(hdc, clientX - 85, clientY - 173, "���찳", strlen("���찳"));

	//��ü �����
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));
	Rectangle(hdc, clientX - 110, clientY - 130, clientX - 10, clientY - 80);
	TextOut(hdc, clientX - 102, clientY - 113, "��ü �����", strlen("��ü �����"));

	ReleaseDC(hWnd, hdc);
}