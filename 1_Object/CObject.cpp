#include "CObject.h"

int CObject::m_nNum = 0;

CObject::CObject() {
	m_nLife = 0;
	m_pName = NULL;
	cout << "CObject()" << endl;
}

CObject::CObject(const char* pName, int nLife) {
	m_pName = new char[strlen(pName) + 2];
	m_nLife = nLife;
	m_nNum++;
	::strcpy(m_pName, pName);
	m_pName[strlen(pName)] = m_nNum + 48;
	m_pName[strlen(pName) + 1] = '\0';

	cout << "#" << m_pName <<" CObject(const char*)  |  m_nNum = " << m_nNum << endl;
}

CObject::CObject(const CObject& pUser) {
	int nTemp, nNum;
	m_nLife = pUser.getLife();
	m_nNum++;
	nTemp = m_nNum;
	m_pName = new char[strlen(pUser.m_pName) + getNumSize(m_nNum) + 1];
	::strcpy(m_pName, pUser.m_pName);
	for (int i = getNumSize(m_nNum) - 1; i >= 0; i--) {
		nNum = nTemp % 10;
		nTemp /= 10;
		m_pName[strlen(pUser.m_pName) + i - 1] = nNum + 48;
	}
	m_pName[strlen(pUser.m_pName) + getNumSize(m_nNum) - 1] = '\0';
	cout << "#" << m_pName << " CObject(const CObject&) | m_nNum = " << m_nNum << endl;
}

CObject::~CObject() {
	if (m_pName) {
		cout << "#" << m_pName << " ~CObject()  |  m_nNum = " << m_nNum << "\n" << endl;
		delete m_pName;
		m_pName = NULL;
		m_nNum--;
	}
	else
		cout << "default ~CObject()" << endl;
}


void CObject::operator=(const CObject& object) {
	if (&object == this) { return; }

	if (m_pName) {
		delete m_pName;
		m_pName = NULL;
	}

	m_nLife = object.m_nLife;
	m_nNum++;
	m_pName = new char[strlen(object.m_pName) + 1];
	::strcpy(m_pName, object.m_pName);

	cout << "#" << m_pName << " operator=(const CObject&)" << endl;
}


int CObject::getNumSize(const int nNum) {
	int nTemp = nNum, nCount = 0;

	while (nTemp != 0) {
		nTemp /= 10;
		nCount++;
	}

	return nCount;
}

void CObject::displayObject() {
	cout << " £ß£ß£ß£ß£ß£ß£ß£ß£ß£ß£ß£ß£ß£ß£ß£ß" << endl;
	cout << "¦¢ ID : " << this->getName() << "\t¦¢ LIFE : " << this->getLife() << "\t¦¢" << endl;
	cout << " £þ£þ£þ£þ£þ£þ£þ£þ£þ£þ£þ£þ£þ£þ£þ£þ" << endl;
}