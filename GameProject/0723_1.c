#include <stdio.h>

int main() {
	int nDan, nResult, nInputNum, nCount = 2, nWhileNum = 1;
	while (nWhileNum) {
		puts("���ϴ� �޴��� �Է��ϼ���.");
		printf("1. ��ü ������ ���  2. ���ϴ� ������ ���  3. ���� : ");
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
			printf("���ϴ� �������� �Է��Ͽ� �ּ���. : ");
			scanf("%d", &nDan);
			if (nDan < 2 || nDan > 9) {
				printf("\n!!2 ~ 9 ������ ���� �Է����ּ���.!!\n");
				goto CASE_2;
			}
			printf("======\n%2d��\n======\n", nDan);
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
			printf("�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �޴��� �������ּ���.\n\n");
			break;
		}
	}

	printf("���α׷��� �����մϴ�.\n");

	return 0;
}