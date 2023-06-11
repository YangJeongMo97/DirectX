#include "CExplosiveAttack.h"

CExplosiveAttack::CExplosiveAttack() {

}

CExplosiveAttack::~CExplosiveAttack() {

}

int CExplosiveAttack::AttackTypeExplosive(CBasicSet* pTarget) {
	switch (pTarget->getType()) {
	case ENUM_HUMAN:
		return getAttack() * 150 / 100;
	case ENUM_ORC:
		return getAttack() * 90 / 100;
	case ENUM_ELF:
		return getAttack() * 50 / 100;
	default:
		return getAttack();
	}
}