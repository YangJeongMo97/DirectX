#include "choiceJob.h"

void choiceJob(int &nNum) {
	while (1) {
		cout << "----------------------------------------------------------" << endl;
		cout << "1. ��Ŀ  2. ����  3. �ü�  4. ����" << endl;
		cout << "������ �������ּ��� :";
		cin >> nNum;
		cout << "----------------------------------------------------------" << endl;
		if (nNum < 1 || nNum > 4) {
			cout << "�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
			getch();
			system("cls");
			nNum = NULL;
			continue;
		}
		else break;
	}
}