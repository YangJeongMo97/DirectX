#include "choiceJob.h"

void choiceJob(int &nNum) {
	while (1) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1. 탱커  2. 전사  3. 궁수  4. 힐러" << endl;
		cout << "직업을 선택해주세요 :";
		cin >> nNum;
		cout << "----------------------------------------------------------" << endl;
		if (nNum < 1 || nNum > 4) {
			cout << "잘못된 값을 입력하셨습니다. 다시 입력해주세요." << endl;
			getch();
			system("cls");
			nNum = NULL;
			continue;
		}
		else break;
	}
}