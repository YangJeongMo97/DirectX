#include "CreateRect.h"

CRect* CreateRect(int &nLeft, int &nRight, int &nTop, int &nBottom) {
	cout << "���� �������� �Է����ּ��� : ";
	cin >> nLeft;
	cout << "���� �������� �Է����ּ��� : ";
	cin >> nRight;
	cout << "��� �������� �Է����ּ��� : ";
	cin >> nTop;
	cout << "�ϴ� �������� �Է����ּ��� : ";
	cin >> nBottom;

	CRect* pRectDefault = new CRect(nLeft, nRight, nTop, nBottom);
	
	return pRectDefault;
}