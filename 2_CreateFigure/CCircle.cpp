#include "CCircle.h"

CCircle::CCircle() {
	setShapeName("CIRCLE");
}

CCircle::CCircle(int nLeft, int nRight, int nTop, int nBottom) : m_pShapeName("CIRCLE") {
	setLeft(nLeft);
	setRight(nRight);
	setTop(nTop);
	setBottom(nBottom);
	m_pShapeName = new char[10];
	setShapeName("CIRCLE");
	setCount();
}

CCircle::~CCircle() {

}

float CCircle::CircleRadius()const {
	float fRadius, fWidth, fHeight;

	fHeight = (float)(getBottom() - getTop());
	if (fHeight < 0) fHeight *= -1;

	fWidth = (float)(getRight() - getLeft());
	if (fWidth < 0) fWidth *= -1;

	if (fHeight > fWidth) fRadius = fWidth / 2;
	else fRadius = fHeight / 2;

	return fRadius;
}

float CCircle::CircleArea() const{
	float fRadius;

	fRadius = CircleRadius();

	return fRadius * fRadius * PI;
}

float CCircle::CirclePeriphery() const{
	float fRadius;

	fRadius = CircleRadius();

	return 2 * fRadius * PI;
}

void CCircle::display() {
	int nRadius;

	if (getHeight() > getWidth()) nRadius = getWidth() / 2;
	else nRadius = getHeight() / 2;

	for (int nX = -nRadius; nX <= nRadius; nX++) {
		for (int nY = -nRadius; nY <= nRadius; nY++) {
			if ((nX * nX + nY * nY) <= nRadius * nRadius + nRadius)
				printf("бс");
			else printf(" ");
		}
		printf("\n");
	}
}