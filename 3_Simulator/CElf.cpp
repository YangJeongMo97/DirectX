#include "CElf.h"

int CElf::m_nDeathCount = 0;

CElf::CElf() {
	m_nType = ENUM_ELF;
	int nLength = ::strlen("ELF");
	m_pTribe = new char[nLength + 1];
	::strcpy(m_pTribe, "ELF");
	setHP(rand() % 35 + 40);
	setArmor_base(rand() % 5 + 4);
	setArmor_mod(getArmor_base() + 3);
	setAttack(rand() % 2 + 8);
}

CElf::~CElf() {
}

void CElf::Display() {
	if (getLive())
		printf("%s | %02d | ¢¾", m_pTribe, getHP());
	else
		printf("%s | %02d | ¢½", m_pTribe, getHP());
}

void CElf::balanceDamage(int eNum) {
	int nTemp = getAttack();
	switch (eNum) {
	case::ENUM_HUMAN:
		setAttack(nTemp - 1);
	case::ENUM_ORC:
		setAttack(nTemp + 1);
	}
}

void CElf::AttackTarget(CBasicSet* pTarget) {
	switch (pTarget->getType()) {
	case ENUM_HUMAN:
		balanceDamage(ENUM_HUMAN);
		if (getAttackType())
			pTarget->setHP(pTarget->remainHP(AttackTypeVibration(pTarget), pTarget->getArmor_base()));
		else
			pTarget->setHP(pTarget->remainHP(AttackTypeNormal(pTarget), pTarget->getArmor_base()));
		break;
	case ENUM_ORC:
		balanceDamage(ENUM_ORC);
		if (getAttackType())
			pTarget->setHP(pTarget->remainHP(AttackTypeVibration(pTarget), pTarget->getArmor_base()));
		else
			pTarget->setHP(pTarget->remainHP(AttackTypeNormal(pTarget), pTarget->getArmor_base()));
		break;
	}
}