#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class CObject
{
public:
	CObject();
	CObject(const char* pName, int nLife);
	CObject(const CObject& pUser);
	~CObject();

	void operator=(const CObject& object);

	char* getName() const { return m_pName; };

	static int getNum() { return m_nNum; };

	int getLife() const { return m_nLife; };

	int getNumSize(const int nNum);

	void displayObject();

private:
	static int m_nNum;
	int m_nLife;
	char* m_pName;
};