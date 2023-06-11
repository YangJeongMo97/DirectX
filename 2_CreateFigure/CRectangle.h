#pragma once
#include "CRect.h"

class CRectangle : public CRect
{
public:
	CRectangle();
	CRectangle(int nLeft, int nRight, int nTop, int nBottom);
	~CRectangle();

	int RectangleArea()const;

	int RectanglePeriphery()const;

	void display();

	void setShapeName(const char* pName) { m_pShapeName = pName; }
	const char* getShapeName() { return m_pShapeName; }

private:
	const char* m_pShapeName;
};

