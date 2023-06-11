#include "userInterface.h"

void userInterface(CharStats* character) {
	int nNum;
	cout << "----------------------------------------------------------" << endl;
	displayCharStats(character);
	while (1) {
		if (!character->getJobNum()) {
			choiceJob(nNum);
			character->setJob(nNum);
		}
		system("cls");
		cout << "----------------------------------------------------------" << endl;
		displayCharStats(character);
		cout << "----------------------------------------------------------" << endl;
		cout << "직업 변경 : ENTER  |  레벨업 : SPACEBAR  |  종료 : 다른키" << endl;
		switch (getch()) {
		case ' ':
			character = userLevelUp(character);
			break;
		case '\r':
			system("cls");
			choiceJob(nNum);
			break;
		default:
			exit(1);
		}
	}
}