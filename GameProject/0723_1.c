#include <stdio.h>

int main() {
	int nDan, nResult, nInputNum, nCount = 2, nWhileNum = 1;
	while (nWhileNum) {
		puts("원하는 메뉴를 입력하세요.");
		printf("1. 전체 구구단 출력  2. 원하는 구구단 출력  3. 종료 : ");
		scanf("%d", &nInputNum);
		switch (nInputNum){
		case 1:
			printf("\n");
			while (nCount) {
				for (int i = 1; i < 10; i++) {
					for (int j = nCount; j < nCount + 3; j++) {
						if (j > 9) break;
						printf("%2d X%2d =%3d\t", j, i, i * j);
					}
					printf("\n");
				}
				printf("\n");
				nCount += 3;
				if (nCount > 9) break;
			}
			break;
		case 2:
		CASE_2:
			printf("\n");
			printf("원하는 구구단을 입력하여 주세요. : ");
			scanf("%d", &nDan);
			if (nDan < 2 || nDan > 9) {
				printf("\n!!2 ~ 9 사이의 값을 입력해주세요.!!\n");
				goto CASE_2;
			}
			printf("======\n%2d단\n======\n", nDan);
			for (int i = 1; i < 10; i++) {
				nResult = nDan * i;
				printf("%2d X%2d =%3d\n", nDan, i, nResult);
				}
			puts("");
			break;
		case 3:
			nWhileNum = 0;
			break;
		default:
			printf("잘못된 값을 입력하셨습니다. 다시 메뉴를 선택해주세요.\n\n");
			break;
		}
	}

	printf("프로그램을 종료합니다.\n");

	return 0;
}