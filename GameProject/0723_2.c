#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int nRandomNum, nScore = 0, nInputNum, nLife = 3, nRound = 1;

	srand((unsigned)time(NULL));

	nRandomNum = rand() % 10 + 1;

	while(nLife != 0){
		printf("-> %d Round LIFE : %d\n- Score : %d\n\t�����Ǵ� ���ڸ� �Է��ϼ���. : ", nRound, nLife, nScore);
		scanf("%d", &nInputNum);
		if (nRandomNum > nInputNum) {
			printf("������ ������ %d���� Ů�ϴ�.\n\n", nInputNum);
			nLife--;
			continue;
		}
		else if (nRandomNum < nInputNum) {
			printf("������ ������ %d���� �۽��ϴ�.\n\n", nInputNum);
			nLife--;
			continue;
		}
		else {
			printf("�����մϴ�! ������ ���߼̽��ϴ�. ������ ����� �մϴ�.\n\n");
			nScore += 10;
			nRandomNum = rand() % 10 + 1;
			nLife = 3;
			nRound++;
		}
	}

	printf("������ ������ %d�����ϴ�.\n�� ȹ���� ������ %d�� �Դϴ�.\n", nRandomNum, nScore);
	return 0;
}