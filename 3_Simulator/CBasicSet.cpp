#include "CBasicSet.h"
#include "CHuman.h"
#include "COrc.h"
#include "CElf.h"

CBasicSet::CBasicSet() : m_nArmor_base (0), m_nArmor_mod(1), m_nAttack(1), m_nHP(50), m_bLive(true), m_nType(ENUM_CITIZEN)
{
	m_nAttackType = rand() % 2; // Human = 진동형 0, 폭발형 1 | Orc = 노말형 0, 폭발형 1 | Elf = 노말형 0, 진동형 1
	m_pTribe = NULL;
}

CBasicSet::~CBasicSet() {
	delete[] m_pTribe;
}

const CBasicSet& CBasicSet::operator=(const CBasicSet& pTemp) {
	return *this;
}

CBasicSet* CBasicSet::operator+(CBasicSet& pTribe) {
	CBasicSet* pTemp;

	switch(this->getType()){
	case ENUM_HUMAN:
		pTemp = new CHuman;
		pTemp->m_bLive = true;
		pTemp->m_nArmor_base = (this->m_nArmor_base + pTribe.m_nArmor_base) / 2;
		pTemp->m_nAttack = (this->m_nAttack + pTribe.m_nAttack) / 2;
		pTemp->m_nHP = (this->m_nHP + pTribe.m_nHP) / 2;
		pTemp->m_nAttackType = this->m_nAttackType;
		break;
	case ENUM_ORC:
		pTemp = new COrc;
		pTemp->m_bLive = true;
		pTemp->m_nArmor_base = (this->m_nArmor_base + pTribe.m_nArmor_base) / 2;
		pTemp->m_nAttack = (this->m_nAttack + pTribe.m_nAttack) / 2;
		pTemp->m_nHP = (this->m_nHP + pTribe.m_nHP) / 2;
		pTemp->m_nAttackType = this->m_nAttackType;
		break;
	case ENUM_ELF:
		pTemp = new CElf;
		pTemp->m_bLive = true;
		pTemp->m_nArmor_base = (this->m_nArmor_base + pTribe.m_nArmor_base) / 2;
		pTemp->m_nAttack = (this->m_nAttack + pTribe.m_nAttack) / 2;
		pTemp->m_nHP = (this->m_nHP + pTribe.m_nHP) / 2;
		pTemp->m_nAttackType = this->m_nAttackType;
		break;
	default:
		pTemp = new CHuman;
		break;
	}

	return pTemp;
}

CBasicSet& CBasicSet::operator+=(const CBasicSet& pTemp) {
	this->m_nArmor_base += pTemp.m_nArmor_base;
	this->m_nAttack += pTemp.m_nAttack;
	this->m_nHP += pTemp.m_nHP;
	this->m_nArmor_base /= 2;
	this->m_nAttack /= 2;
	this->m_nHP /= 2;

	return *this;
}

CBasicSet* operator+(int nTemp, CBasicSet& pTribe) {
	CBasicSet* pTemp;

	switch (pTribe.getType()) {
	case ENUM_HUMAN:
		pTemp = new CHuman;
		pTemp->m_bLive = true;
		pTemp->m_nArmor_base = (pTribe.m_nArmor_base + nTemp) / 2;
		pTemp->m_nAttack = (pTribe.m_nAttack + nTemp) / 2;
		pTemp->m_nHP = (pTribe.m_nHP + nTemp) / 2;
		pTemp->m_nAttackType = pTribe.m_nAttackType;
		break;
	case ENUM_ORC:
		pTemp = new COrc;
		pTemp->m_bLive = true;
		pTemp->m_nArmor_base = (pTribe.m_nArmor_base + nTemp) / 2;
		pTemp->m_nAttack = (pTribe.m_nAttack + nTemp) / 2;
		pTemp->m_nHP = (pTribe.m_nHP + nTemp) / 2;
		pTemp->m_nAttackType = pTribe.m_nAttackType;
		break;
	case ENUM_ELF:
		pTemp = new CElf;
		pTemp->m_bLive = true;
		pTemp->m_nArmor_base = (pTribe.m_nArmor_base + nTemp) / 2;
		pTemp->m_nAttack = (pTribe.m_nAttack + nTemp) / 2;
		pTemp->m_nHP = (pTribe.m_nHP + nTemp) / 2;
		pTemp->m_nAttackType = pTribe.m_nAttackType;
		break;
	default:
		pTemp = new CHuman;
		break;
	}

	return pTemp;
}

int operator==(const char* pTribe, const CBasicSet& pTemp) {
	if (::strcmp(pTribe, pTemp.getTribe()) == 0) return 1;
	else return 0;
}

int CBasicSet::remainHP(int nAttack, int nArmor) {
	int nTemp = m_nHP;
	if (nAttack <= nArmor && m_bLive) { nTemp -= 1; }
	else nTemp -= nAttack - nArmor;
	return nTemp;
}

void CBasicSet::cantSurvival() {
	m_bLive = false;
	m_nHP = 0;
	m_nAttack = 0;
	m_nArmor_base = 0;
	m_nArmor_mod = 0;
}