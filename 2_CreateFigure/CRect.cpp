#include "CRect.h"

int CRect::m_nCount = 0;

CRect::CRect() : m_nMaxLength(30) {
	m_nLeft = 0;
	m_nRight = 10;
	m_nTop = 0;
	m_nBottom = 10;
}

CRect::CRect(int nLeft = 0, int nRight = 5, int nTop = 0, int nBottom = 10) : m_nMaxLength(30) {
	m_nLeft = nLeft;
	m_nRight = nRight;
	m_nTop = nTop;
	m_nBottom = nBottom;
}

CRect::~CRect() {
}

void display() {}

int CRect::getHeight() const {
	int nHeight;
	nHeight = m_nBottom - m_nTop;
	if (nHeight < 0) nHeight *= -1;
	if (nHeight > m_nMaxLength) return 0;
	return nHeight;
}

int CRect::getWidth() const {
	int nWidth;
	nWidth = m_nRight - m_nLeft;
	if (nWidth < 0) nWidth *= -1;
	if (nWidth > m_nMaxLength) return 0;
	return nWidth;
}