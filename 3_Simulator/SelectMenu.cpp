#include "SelectMenu.h"

int SelectMenu(CBasicSet* pCObj[], int* pTempHumanArmor, int* pTempOrcArmor, int* pTempElfArmor) {
	int nTurn = 1, nMenu, nTribe, nSelectHistory = 0;
	for (int i = 0; i < ENUM_MAX / TRIBE_COUNT; i++) {
		pTempHumanArmor[i] = pCObj[i * TRIBE_COUNT + HUMAN_TURN]->getArmor_base();
		pTempOrcArmor[i] = pCObj[i * TRIBE_COUNT + ORC_TURN]->getArmor_base();
		pTempElfArmor[i] = pCObj[i * TRIBE_COUNT + ELF_TURN]->getArmor_base();
	}
	while (nTurn != 4) {
		switch (nTurn) {
		case 1:
		SELECT_MENU_1:
			cout << "인간 턴" << endl;
			cout << "이번 라운드에는 어떤 지휘를 내리시겠습니까? (1.공격 2.방어) :";
			cin >> nMenu;
			switch (nMenu) {
			case 1:
			SELECT_TRIBE_1:
				cout << "어느 종족을 공격하시겠습니까? (1.오크 2.엘프) :";
				cin >> nTribe;
				switch (nTribe) {
				case 1:
					nSelectHistory += 11;
					nSelectHistory *= 100;
					break;
				case 2:
					nSelectHistory += 12;
					nSelectHistory *= 100;
					break;
				default:
					cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
					getch();
					system("cls");
					goto SELECT_TRIBE_1;
					break;
				}
				break;
			case 2:
				for (int i = 0; i < ENUM_MAX; i++) {
					switch (i % TRIBE_COUNT) {
					case HUMAN_TURN:
						pCObj[i]->setArmor_base(pCObj[i]->getArmor_mod());
						break;
					default:
						break;
					}
				}
				nSelectHistory += 20;
				nSelectHistory *= 100;
				break;
			default:
				cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
				getch();
				system("cls");
				goto SELECT_MENU_1;
				break;
			}
			nTurn++;
			break;
		case 2:
		SELECT_MENU_2:
			cout << "오크 턴" << endl;
			cout << "이번 라운드에는 어떤 지휘를 내리시겠습니까? (1.공격 2.방어) :";
			cin >> nMenu;

			switch (nMenu) {
			case 1:
			SELECT_TRIBE_2:
				cout << "어느 종족을 공격하시겠습니까? (1.엘프 2.인간) :";
				cin >> nTribe;
				switch (nTribe) {
				case 1:
					nSelectHistory += 11;
					nSelectHistory *= 100;
					break;
				case 2:
					nSelectHistory += 12;
					nSelectHistory *= 100;
					break;
				default:
					cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
					getch();
					system("cls");
					goto SELECT_TRIBE_2;
				}
				break;
			case 2:
				for (int i = 0; i < ENUM_MAX; i++) {
					switch (i % TRIBE_COUNT) {
					case ORC_TURN:
						pCObj[i]->setArmor_base(pCObj[i]->getArmor_mod());
						break;
					default:
						break;
					}
				}
				nSelectHistory += 20;
				nSelectHistory *= 100;
				break;
			default:
				cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
				getch();
				system("cls");
				goto SELECT_MENU_2;
			}
			nTurn++;
			break;
		case 3:
		SELECT_MENU_3:
			cout << "엘프 턴" << endl;
			cout << "이번 라운드에는 어떤 지휘를 내리시겠습니까? (1.공격 2.방어) :";
			cin >> nMenu;

			switch (nMenu) {
			case 1:
			SELECT_TRIBE_3:
				cout << "어느 종족을 공격하시겠습니까? (1.인간 2.오크) :";
				cin >> nTribe;
				switch (nTribe) {
				case 1:
					nSelectHistory += 11;
					nSelectHistory *= 100;
					break;
				case 2:
					nSelectHistory += 12;
					nSelectHistory *= 100;
					break;
				default:
					cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
					getch();
					system("cls");
					goto SELECT_TRIBE_3;
				}
				break;
			case 2:
				for (int i = 0; i < ENUM_MAX; i++) {
					switch (i % TRIBE_COUNT) {
					case ELF_TURN:
						pCObj[i]->setArmor_base(pCObj[i]->getArmor_mod());
						break;
					default:
						break;
					}
				}
				nSelectHistory += 20;
				nSelectHistory *= 100;
				break;
			default:
				cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
				getch();
				system("cls");
				goto SELECT_MENU_3;
			}
			nTurn++;
			break;
		}
	}
	return nSelectHistory;
	}