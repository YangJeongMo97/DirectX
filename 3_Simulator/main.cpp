#include "UserInterface.h"
#include "Overloading.h"
#include <time.h>

int main() {
	int* pTempHumanArmor, *pTempOrcArmor, *pTempElfArmor;
	srand((unsigned)time(NULL));
	CBasicSet* User[ENUM_MAX];

	for (int i = 0; i < ENUM_MAX; i++) {
		switch (i % 3) {
		case 0:
			User[i] = new CHuman;
			break;
		case 1:
			User[i] = new COrc;
			break;
		case 2:
			User[i] = new CElf;
			break;
		}
	}

	pTempHumanArmor = new int[ENUM_MAX / TRIBE_COUNT];
	pTempOrcArmor = new int[ENUM_MAX / TRIBE_COUNT];
	pTempElfArmor = new int[ENUM_MAX / TRIBE_COUNT];

	DisplayStats(User);

	UserInterface(User, pTempHumanArmor, pTempOrcArmor, pTempElfArmor);

	Overloading();

	return 0;
}