#include "Overloading.h"

void Overloading() {
	CBasicSet* Temp, * Temp2;

	Temp = new CHuman;
	Temp2 = new COrc;

	CBasicSet* Temp3 = (*Temp + *Temp2);

	cout << "Temp : " << Temp->getAttack() << " " << Temp->getHP() << " " << Temp->getTribe() << " " << Temp->getAttackType() << endl;
	cout << "Temp2 : " << Temp2->getAttack() << " " << Temp2->getHP() << " " << Temp2->getTribe() << " " << Temp2->getAttackType() << endl;
	cout << "= Temp + Temp2 : " << Temp3->getAttack() << " " << Temp3->getHP() << " " << Temp3->getTribe() << " " << Temp3->getAttackType() << endl;

	*Temp3 += *Temp2;

	cout << "+= Temp2 : " << Temp3->getAttack() << " " << Temp3->getHP() << " " << Temp3->getTribe() << " " << Temp3->getAttackType() << endl;

	Temp3 = (100 + *Temp);

	cout << "= (int + Temp) : " << Temp3->getAttack() << " " << Temp3->getHP() << " " << Temp3->getTribe() << " " << Temp3->getAttackType() << endl;

	int nResult;

	nResult = ("ORC" == *Temp);
	cout << nResult << endl;

	nResult = ("HUMAN" == *Temp);
	cout << nResult << endl;
}