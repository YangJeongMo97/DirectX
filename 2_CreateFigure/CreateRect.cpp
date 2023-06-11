#include "CreateRect.h"

CRect* CreateRect(int &nLeft, int &nRight, int &nTop, int &nBottom) {
	cout << "좌측 기준점을 입력해주세요 : ";
	cin >> nLeft;
	cout << "우측 기준점을 입력해주세요 : ";
	cin >> nRight;
	cout << "상단 기준점을 입력해주세요 : ";
	cin >> nTop;
	cout << "하단 기준점을 입력해주세요 : ";
	cin >> nBottom;

	CRect* pRectDefault = new CRect(nLeft, nRight, nTop, nBottom);
	
	return pRectDefault;
}