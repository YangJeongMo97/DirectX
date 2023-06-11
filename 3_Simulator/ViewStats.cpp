#include "ViewStats.h"

void ViewStats(CBasicSet* pCObj) {
	cout << " ATK : " << pCObj->getAttack() << "\t| DEF : " << pCObj->getArmor_base() << "\t| HP : " << pCObj->getHP();
	switch (pCObj->getType()) {
	case ENUM_HUMAN:
			if (pCObj->getAttackType())
				cout << "  폭발형" << endl;
			else
				cout << "  진동형" << endl;
			break;
	case ENUM_ORC:
		if (pCObj->getAttackType())
			cout << "  폭발형" << endl;
		else
			cout << "  일반형" << endl;
		break;
	case ENUM_ELF:
		if (pCObj->getAttackType())
			cout << "  진동형" << endl;
		else
			cout << "  일반형" << endl;
		break;
	}
}