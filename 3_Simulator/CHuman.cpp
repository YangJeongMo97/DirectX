#include "CHuman.h"

int CHuman::m_nDeathCount = 0;

CHuman::CHuman() {
	m_nType = ENUM_HUMAN;
	int nLength = ::strlen("HUMAN");
	m_pTribe = new char[nLength + 1];
	::strcpy(m_pTribe, "HUMAN");
	setHP(rand() % 30 + 50);
	setArmor_base(rand() % 5 + 5);
	setArmor_mod(getArmor_base() + 3);
	setAttack(rand() % 4 + 7);
}

CHuman::~CHuman() {
}

void CHuman::Display() {
	if (getLive())
		printf("%s | %02d | ¢¾", m_pTribe, getHP());
	else
		printf("%s | %02d | ¢½", m_pTribe, getHP());
}

void CHuman::balanceDamage(int eNum) {
	int nTemp = getAttack();
	switch (eNum) {
	case::ENUM_ORC:
		setAttack(nTemp - 1);
	case::ENUM_ELF:
		setAttack(nTemp + 1);
	}
}

void CHuman::AttackTarget(CBasicSet* pTarget) {
	switch (pTarget->getType()) {
	case ENUM_ELF:
		balanceDamage(ENUM_ELF);
		if (getAttackType()) 
			pTarget->setHP(pTarget->remainHP(AttackTypeExplosive(pTarget), pTarget->getArmor_base()));
		else
			pTarget->setHP(pTarget->remainHP(AttackTypeVibration(pTarget), pTarget->getArmor_base()));
		break;
	case ENUM_ORC:
		balanceDamage(ENUM_ORC);
		if (getAttackType())
			pTarget->setHP(pTarget->remainHP(AttackTypeExplosive(pTarget), pTarget->getArmor_base()));
		else
			pTarget->setHP(pTarget->remainHP(AttackTypeVibration(pTarget), pTarget->getArmor_base()));
		break;
	}
}