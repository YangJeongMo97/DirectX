#include "DisplayStats.h"

void DisplayStats(CBasicSet* pCObj[]) {
	for (int i = 0; i < ENUM_MAX; i++) {
		switch (i % TRIBE_COUNT) {
		case HUMAN_TURN:
			cout << pCObj[i]->getTribe();
			printf("#%02d : ", i + 1);
			ViewStats(pCObj[i]);
			break;
		default:
			break;
		}
	}
	getch();
	system("cls");

	for (int i = 0; i < ENUM_MAX; i++) {
		switch (i % TRIBE_COUNT) {
		case ORC_TURN:
			cout << pCObj[i]->getTribe();
			printf("#%02d : ", i + 1);
			ViewStats(pCObj[i]);
			break;
		default:
			break;
		}
	}
	getch();
	system("cls");

	for (int i = 0; i < ENUM_MAX; i++) {
		switch (i % TRIBE_COUNT) {
		case ELF_TURN:
			cout << pCObj[i]->getTribe();
			printf("#%02d : ", i + 1);
			ViewStats(pCObj[i]);
			break;
		default:
			break;
		}
	}
	getch();
	system("cls");
}