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
	cout << "가로 길이 : " << pRectC->getWidth() << "\n세로 길이 : " << pRectC->getHeight() << endl;
	cout << "설정하신 좌표 내에서 만들 수 있는 가장 큰 원을 생성합니다." << endl;
	getch();
	system("cls");

	delete pRectDefault;
	pRectDefault = NULL;

	CCircle* pRectCircle = new CCircle(nLeft, nRight, nTop, nBottom);
	pRectDefault = new CCircle;

	cout << "up casting 기본 생성자 설정 좌표 : " << pRectDefault->getLeft() << ", " << pRectDefault->getRight() << ", " << pRectDefault->getTop() << ", " << pRectDefault->getBottom() << endl;

	cout << "직접 설정 한 좌표 : " << pRectCircle->getLeft() << ", " << pRectCircle->getRight() << ", " << pRectCircle->getTop() << ", " << pRectCircle->getBottom() << endl;

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

	cout << "설정하신 좌표 내에서 만들 수 있는 가장 큰 직사각형을 생성합니다." << endl;
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

	cout << "총 호출된 도형 생성자 = " << pRectangle->getCount() << endl;

	delete pRectangle;
	pRectangle = NULL;

	return 0;
}