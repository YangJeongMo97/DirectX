#include "userLevelUp.h"

CharStats* userLevelUp(CharStats *user) {
	int nStr = 5, nInt = 5, nLife = 100, nArm = 5, nMaDf = 5;
	switch (user->getJobNum()) {
	case 1:
		nStr = (int)(user->getStr() + user->getLevel() * 0.75);
		nInt = (int)(user->getInt() + user->getLevel() * 0.1);
		nLife = (int)(user->getLife() + user->getLevel() * 15);
		nArm = (int)(user->getArmor() + user->getLevel() * 5.2);
		nMaDf = (int)(user->getMagicDef() + user->getLevel() * 3.3);
		break;
	case 2:
		nStr = (int)(user->getStr() + user->getLevel() * 5);
		nInt = (int)(user->getInt());
		nLife = (int)(user->getLife() + user->getLevel() * 7.5);
		nArm = (int)(user->getArmor() + user->getLevel() * 3.5);
		nMaDf = (int)(user->getMagicDef() + user->getLevel() * 2.1);
		break;
	case 3:
		nStr = (int)(user->getStr() + user->getLevel() * 2);
		nInt = (int)(user->getInt() + user->getLevel() * 1);
		nLife = (int)(user->getLife() + user->getLevel() * 5.5);
		nArm = (int)(user->getArmor() + user->getLevel() * 2.1);
		nMaDf = (int)(user->getMagicDef() + user->getLevel() * 0.75);
		break;
	case 4:
		nStr = (int)(user->getStr());
		nInt = (int)(user->getInt() + user->getLevel() * 3);
		nLife = (int)(user->getLife() + user->getLevel() * 4.75);
		nArm = (int)(user->getArmor() + user->getLevel() * 0.75);
		nMaDf = (int)(user->getMagicDef() + user->getLevel() * 3);
		break;
	}
	user->setChar(nStr, nInt, nLife, nArm, nMaDf);
	user->setLevel();

	return user;
}