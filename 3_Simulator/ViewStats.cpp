#include "ViewStats.h"

void ViewStats(CBasicSet* pCObj) {
	cout << " ATK : " << pCObj->getAttack() << "\t| DEF : " << pCObj->getArmor_base() << "\t| HP : " << pCObj->getHP();
	switch (pCObj->getType()) {
	case ENUM_HUMAN:
			if (pCObj->getAttackType())
				cout << "  ������" << endl;
			else
				cout << "  ������" << endl;
			break;
	case ENUM_ORC:
		if (pCObj->getAttackType())
			cout << "  ������" << endl;
		else
			cout << "  �Ϲ���" << endl;
		break;
	case ENUM_ELF:
		if (pCObj->getAttackType())
			cout << "  ������" << endl;
		else
			cout << "  �Ϲ���" << endl;
		break;
	}
}