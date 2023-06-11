#include <iostream>
#include "CharStats.h"

using namespace std;

CharStats::CharStats() {
	m_nStr = 5;
	m_nInt = 5;
	m_nLife = 100;
	m_nArmor = 1;
	m_nMagicDef = 1;
	m_nJobNum = 0;
	m_nLevel = 1;

	cout << "기본 캐릭터 생성 완료." << endl;
}

CharStats::CharStats(int nNum) {
	setJob(nNum);

	cout << "직업 캐릭터 생성 완료." << endl;
}

CharStats::~CharStats() {
}

void CharStats::setChar(int nStrLevel, int nIntLevel, int nLifeLevel, int nArmorLavel, int nMagicDefLevel) {
	m_nStr = nStrLevel;
	m_nInt = nIntLevel;
	m_nLife = nLifeLevel;
	m_nArmor = nArmorLavel;
	m_nMagicDef = nMagicDefLevel;
}

void CharStats::setJob(int nNum) {
	m_nJobNum = nNum;
	switch (m_nJobNum) {
	case 1:
		setChar(20, 5, 500, 30, 30);
		break;
	case 2:
		setChar(50, 5, 350, 15, 7);
		break;
	case 3:
		setChar(25, 20, 250, 9, 13);
		break;
		setChar(5, 40, 200, 5, 18);
		break;
	default:
		break;
	}
}

void  CharStats::setLevel() {
	m_nLevel++;
}
