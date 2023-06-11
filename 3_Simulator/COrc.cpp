#include "COrc.h"

int COrc::m_nDeathCount = 0;

COrc::COrc() {
	m_nType = ENUM_ORC;
	int nLength = ::strlen("ORC");
	m_pTribe = new char[nLength + 1];
	::strcpy(m_pTribe, "ORC");
	setHP(rand() % 25 + 60);
	setArmor_base(rand() % 7 + 3);
	setArmor_mod(getArmor_base() + 3);
	setAttack(rand() % 7 + 5);
}

COrc::~COrc() {
}

void COrc::Display() {
	if (getLive())
		printf("%s | %02d | ¢¾", m_pTribe, getHP());
	else
		printf("%s | %02d | ¢½", m_pTribe, getHP());
}

void COrc::balanceDamage(int eNum) {
	int nTemp = getAttack();
	switch (eNum) {
	case::ENUM_ELF:
		setAttack(nTemp - 1);
	case::ENUM_HUMAN:
		setAttack(nTemp + 1);
	}
}

void COrc::AttackTarget(CBasicSet* pTarget) {
	switch (pTarget->getType()) {
	case ENUM_ELF:
		balanceDamage(ENUM_ELF);
		if (getAttackType())
			pTarget->setHP(pTarget->remainHP(AttackTypeExplosive(pTarget), pTarget->getArmor_base()));
		else
			pTarget->setHP(pTarget->remainHP(AttackTypeNormal(pTarget), pTarget->getArmor_base()));
		break;
	case ENUM_HUMAN:
		balanceDamage(ENUM_HUMAN);
		if (getAttackType())
			pTarget->setHP(pTarget->remainHP(AttackTypeExplosive(pTarget), pTarget->getArmor_base()));
		else
			pTarget->setHP(pTarget->remainHP(AttackTypeNormal(pTarget), pTarget->getArmor_base()));
		break;
	}
}