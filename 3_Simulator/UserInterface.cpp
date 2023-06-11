#include "UserInterface.h"

void UserInterface(CBasicSet* User[], int* pTempHumanArmor, int* pTempOrcArmor, int* pTempElfArmor) {
	int nSelectHistory, nTemp, nTurn;

	while (1) {
		for (int i = 0; i < ENUM_MAX; i++) {
			switch (i % TRIBE_COUNT) {
			case HUMAN_TURN:
				User[i]->Display();
				printf("\t\t");
				break;
			case ORC_TURN:
				User[i]->Display();
				printf("\t\t");
				break;
			case ELF_TURN:
				User[i]->Display();
				printf("\n");
				break;
			}

		}

		cout << "--------------------------------DeathCount--------------------------------\n" << User[HUMAN_TURN]->getDeathCount() << "\t\t\t" << User[ORC_TURN]->getDeathCount() << "\t\t\t" << User[ELF_TURN]->getDeathCount() << endl;
		puts("");
		nSelectHistory = SelectMenu(User, pTempHumanArmor, pTempOrcArmor, pTempElfArmor);
		nTurn = ELF_TURN;
		while (nSelectHistory != 0) {
			switch (nTurn) {
			case HUMAN_TURN:
				nTemp = nSelectHistory % 100;
				switch (nTemp) {
				case 11:
					for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
						User[i * TRIBE_COUNT + HUMAN_TURN]->AttackTarget(User[i * TRIBE_COUNT + ORC_TURN]);
						if (User[i * TRIBE_COUNT + ORC_TURN]->getHP() < 0){
							User[i * TRIBE_COUNT + ORC_TURN]->cantSurvival();
							User[i * TRIBE_COUNT + ORC_TURN]->setDeathCount();
						}
					}
					break;
				case 12:
					for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
						User[i * TRIBE_COUNT + HUMAN_TURN]->AttackTarget(User[i * TRIBE_COUNT + ELF_TURN]);
						if (User[i * TRIBE_COUNT + ELF_TURN]->getHP() < 0){
							User[i * TRIBE_COUNT + ELF_TURN]->cantSurvival();
							User[i * TRIBE_COUNT + ELF_TURN]->setDeathCount();
						}
					}
					break;
				default:
					break;
				}
				nSelectHistory /= 100;
				nTurn = ELF_TURN;
				break;
			case ORC_TURN:
				nTemp = nSelectHistory % 100;
				switch (nTemp) {
				case 11:
					for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
						User[i * TRIBE_COUNT + ORC_TURN]->AttackTarget(User[i * TRIBE_COUNT + ELF_TURN]);
						if (User[i * TRIBE_COUNT + ELF_TURN]->getHP() < 0){
							User[i * TRIBE_COUNT + ELF_TURN]->cantSurvival();
							User[i * TRIBE_COUNT + ELF_TURN]->setDeathCount();
						}
					}
					break;
				case 12:
					for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
						User[i * TRIBE_COUNT + ORC_TURN]->AttackTarget(User[i * TRIBE_COUNT + HUMAN_TURN]);
						if (User[i * TRIBE_COUNT + HUMAN_TURN]->getHP() < 0){
							User[i * TRIBE_COUNT + HUMAN_TURN]->cantSurvival();
							User[i * TRIBE_COUNT + HUMAN_TURN]->setDeathCount();
						}
					}
					break;
				default:
					break;
				}
				nSelectHistory /= 100;
				nTurn = HUMAN_TURN;
				break;
			case ELF_TURN:
				nTemp = nSelectHistory % 100;
				switch (nTemp) {
				case 11:
					for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
						User[i * TRIBE_COUNT + ELF_TURN]->AttackTarget(User[i * TRIBE_COUNT + HUMAN_TURN]);
						if (User[i * TRIBE_COUNT + HUMAN_TURN]->getHP() < 0) {
							User[i * TRIBE_COUNT + HUMAN_TURN]->cantSurvival();
							User[i * TRIBE_COUNT + HUMAN_TURN]->setDeathCount();
						}
					}

					break;
				case 12:
					for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
						User[i * TRIBE_COUNT + ELF_TURN]->AttackTarget(User[i * TRIBE_COUNT + ORC_TURN]);
						if (User[i * TRIBE_COUNT + ORC_TURN]->getHP() < 0){
							User[i * TRIBE_COUNT + ORC_TURN]->cantSurvival();
							User[i * TRIBE_COUNT + ORC_TURN]->setDeathCount();
						}
					}
					break;
				default:
					break;
				}
				nSelectHistory /= 100;
				nTurn = ORC_TURN;
				break;
			}
		}

		for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
			User[i * TRIBE_COUNT + HUMAN_TURN]->setArmor_base(pTempHumanArmor[i]);
			User[i * TRIBE_COUNT + ORC_TURN]->setArmor_base(pTempOrcArmor[i]);
			User[i * TRIBE_COUNT + ELF_TURN]->setArmor_base(pTempElfArmor[i]);
		}

		getch();
		system("cls");
	}
}