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
			cout << "�ΰ� ��" << endl;
			cout << "�̹� ���忡�� � ���ָ� �����ðڽ��ϱ�? (1.���� 2.���) :";
			cin >> nMenu;
			switch (nMenu) {
			case 1:
			SELECT_TRIBE_1:
				cout << "��� ������ �����Ͻðڽ��ϱ�? (1.��ũ 2.����) :";
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
					cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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
				cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				getch();
				system("cls");
				goto SELECT_MENU_1;
				break;
			}
			nTurn++;
			break;
		case 2:
		SELECT_MENU_2:
			cout << "��ũ ��" << endl;
			cout << "�̹� ���忡�� � ���ָ� �����ðڽ��ϱ�? (1.���� 2.���) :";
			cin >> nMenu;

			switch (nMenu) {
			case 1:
			SELECT_TRIBE_2:
				cout << "��� ������ �����Ͻðڽ��ϱ�? (1.���� 2.�ΰ�) :";
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
					cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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
				cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
				getch();
				system("cls");
				goto SELECT_MENU_2;
			}
			nTurn++;
			break;
		case 3:
		SELECT_MENU_3:
			cout << "���� ��" << endl;
			cout << "�̹� ���忡�� � ���ָ� �����ðڽ��ϱ�? (1.���� 2.���) :";
			cin >> nMenu;

			switch (nMenu) {
			case 1:
			SELECT_TRIBE_3:
				cout << "��� ������ �����Ͻðڽ��ϱ�? (1.�ΰ� 2.��ũ) :";
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
					cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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
				cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
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