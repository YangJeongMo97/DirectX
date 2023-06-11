#include "CRectangle.h"

CRectangle::CRectangle() {
	setShapeName("RECTANGLE");
}

CRectangle::CRectangle (int nLeft, int nRight, int nTop, int nBottom) {
	setLeft(nLeft);
	setRight(nRight);
	setTop(nTop);
	setBottom(nBottom);
	m_pShapeName = new char[10];
	setShapeName("RECTANGLE");
	setCount();
}

CRectangle::~CRectangle() {

}

int CRectangle::RectangleArea() const {
	return getWidth() * getHeight();
}

int CRectangle::RectanglePeriphery() const {
	return getHeight() * 2 + getWidth() * 2;
}

void CRectangle::display() {
	for (int nX = 0; nX < getHeight(); nX++) {
		for (int nY = 0; nY < getWidth(); nY++)
			printf("бс");
		printf("\n");
	}
}