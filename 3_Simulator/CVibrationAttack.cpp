#include "CVibrationAttack.h"

CVibrationAttack::CVibrationAttack() {

}

CVibrationAttack::~CVibrationAttack() {

}

int CVibrationAttack::AttackTypeVibration(CBasicSet* pTarget) {
	switch (pTarget->getType()) {
	case ENUM_HUMAN:
		return getAttack() * 50 / 100;
	case ENUM_ORC:
		return getAttack();
	case ENUM_ELF:
		return getAttack() * 130 / 100;
	default:
		return getAttack();
	}
}