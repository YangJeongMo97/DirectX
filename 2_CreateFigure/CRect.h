#pragma once
#include <iostream>

using namespace std;

class CRect
{
public:
	CRect();
	CRect(int nLeft, int nRight, int nTop, int nBottom);
	~CRect();

	void setLeft(int nLeft) { m_nLeft = nLeft; }
	int getLeft() const { return m_nLeft; }

	void setRight(int nRight) { m_nRight = nRight; }
	int getRight() const { return m_nRight; }

	void setTop(int nTop) { m_nTop = nTop; }
	int getTop() const { return m_nTop; }

	void setBottom(int nBottom) { m_nBottom = nBottom; }
	int getBottom() const { return m_nBottom; }
	
	void setCount() { m_nCount++; }
	int getCount() const { return m_nCount; }

	int getHeight() const;
	int getWidth() const;

	void display();

private:
	int m_nLeft, m_nRight, m_nTop, m_nBottom;
	const int m_nMaxLength;
	static int m_nCount;
};

