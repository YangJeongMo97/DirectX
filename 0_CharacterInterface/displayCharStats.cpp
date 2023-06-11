#include "displayCharStats.h"

void displayCharStats(CharStats *user) {
	cout << "Lv. " << user->getLevel() << endl;
	cout << "STR : " << user->getStr() << endl;
	cout << "INT : " << user->getInt() << endl;
	cout << "LIFE : " << user->getLife() << endl;
	cout << "ARMOR : " << user->getArmor() << endl;
	cout << "MAGIC DEF : " << user->getMagicDef() << endl;
}