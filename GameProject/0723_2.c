#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int nRandomNum, nScore = 0, nInputNum, nLife = 3, nRound = 1;

	srand((unsigned)time(NULL));

	nRandomNum = rand() % 10 + 1;

	while(nLife != 0){
		printf("-> %d Round LIFE : %d\n- Score : %d\n\t예측되는 숫자를 입력하세요. : ", nRound, nLife, nScore);
		scanf("%d", &nInputNum);
		if (nRandomNum > nInputNum) {
			printf("생성된 난수는 %d보다 큽니다.\n\n", nInputNum);
			nLife--;
			continue;
		}
		else if (nRandomNum < nInputNum) {
			printf("생성된 난수는 %d보다 작습니다.\n\n", nInputNum);
			nLife--;
			continue;
		}
		else {
			printf("축하합니다! 정답을 맞추셨습니다. 난수를 재생성 합니다.\n\n");
			nScore += 10;
			nRandomNum = rand() % 10 + 1;
			nLife = 3;
			nRound++;
		}
	}

	printf("생성된 난수는 %d였습니다.\n총 획득한 점수는 %d점 입니다.\n", nRandomNum, nScore);
	return 0;
}