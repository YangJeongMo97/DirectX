#include "CRectangle.h"
#include "CCircle.h"
#include "CreateRect.h"
#include <conio.h>
#include <Windows.h>

int main() {
	int nLeft, nRight, nTop, nBottom;
	CRect* pRectDefault = CreateRect(nLeft, nRight, nTop, nBottom);
	CRectangle* pRectC = static_cast<CRectangle*>(pRectDefault);

	cout << "down casting result:" << endl;
	cout << "���� ���� : " << pRectC->getWidth() << "\n���� ���� : " << pRectC->getHeight() << endl;
	cout << "�����Ͻ� ��ǥ ������ ���� �� �ִ� ���� ū ���� �����մϴ�." << endl;
	getch();
	system("cls");

	delete pRectDefault;
	pRectDefault = NULL;

	CCircle* pRectCircle = new CCircle(nLeft, nRight, nTop, nBottom);
	pRectDefault = new CCircle;

	cout << "up casting �⺻ ������ ���� ��ǥ : " << pRectDefault->getLeft() << ", " << pRectDefault->getRight() << ", " << pRectDefault->getTop() << ", " << pRectDefault->getBottom() << endl;

	cout << "���� ���� �� ��ǥ : " << pRectCircle->getLeft() << ", " << pRectCircle->getRight() << ", " << pRectCircle->getTop() << ", " << pRectCircle->getBottom() << endl;

	delete pRectDefault;
	pRectDefault = NULL;

	cout << pRectCircle->getShapeName() << endl;

	pRectCircle->display();

	cout << "Radius = " << pRectCircle->CircleRadius() << endl;
	cout << "Area = " << pRectCircle->CircleArea() << endl;
	cout << "Periphery = " << pRectCircle->CirclePeriphery() << endl;
	
	delete pRectCircle;
	pRectCircle = NULL;

	getch();
	system("cls");

	cout << "�����Ͻ� ��ǥ ������ ���� �� �ִ� ���� ū ���簢���� �����մϴ�." << endl;
	getch();
	system("cls");

	CRectangle* pRectangle;

	pRectangle = new CRectangle(nLeft, nRight, nTop, nBottom);

	cout << pRectangle->getShapeName() << endl;

	pRectangle->display();

	cout << "Area = " << pRectangle->RectangleArea() << endl;
	cout << "Periphery = " << pRectangle->RectanglePeriphery() << endl;

	getch();
	system("cls");

	cout << "�� ȣ��� ���� ������ = " << pRectangle->getCount() << endl;

	delete pRectangle;
	pRectangle = NULL;

	return 0;
}