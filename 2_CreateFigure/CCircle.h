#pragma once
#include "CRect.h"

class CCircle : public CRect
{
public:
	CCircle();
	CCircle(int nLeft, int nRight, int nTop, int nBottom);
	~CCircle();

	float CircleRadius()const;

	float CircleArea()const;

	float CirclePeriphery()const;

	void display();

	void setShapeName(const char* pName) { m_pShapeName = pName; }
	const char* getShapeName() { return m_pShapeName; }

	const float PI = 3.141592653f;

private:
	const char* m_pShapeName;
};

