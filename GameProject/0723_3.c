#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main() {
	int nSlot_1, nSlot_2, nSlot_3, nMoney = 100000, nBetAmount, nCount = 0, nRollingTime, nRollingDelay = 100, nCountDown = 5, nTemp, nSecond = 0;

	srand((unsigned)time(NULL));

	//���� �� �ݾװ� ���ư��� ������ �Է�. ���� �ݾ��� 0�Է��� �� ���α׷� ����.
	while (nMoney > 0) {
		printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
		printf("\n\n\n\n");
		printf("\t\t\t o               o\n");
		printf("\t\t\t |               |  ��\n");
		printf("\t\t\t|-----------------|��\n");
		printf("\t\t\t|     |     |     |��\n");
		printf("\t\t\t|-----------------|\n");
		printf("\t\t\t|  S  L  O  T  �� |\n");
		printf("\t\t\t|  M A C H I N E  |\n");
		printf("\t\t\t|_________________|\n\n");
		printf("\t������ �ݾ��� �Է����ּ��� (0 �Ǵ� ���� �Է½� ����) : ");
		scanf("%d", &nBetAmount);
		if (nBetAmount > nMoney) {
			printf("\t���� �ڱݺ��� ū �ݾ��� �����ϼ̽��ϴ�.\n\t�ٽ� �����ϱ� ���ؼ� �ƹ�Ű�� �����ּ���.");
			getch();
			system("cls");
			continue;
		}
		else if (nBetAmount <= 0) goto END;						//0�� �Է��ϸ� ���� ������ ������ָ鼭 ���� ����.
		nMoney -= nBetAmount;
		printf("\t������� �����ðڽ��ϱ�? : ");
		scanf("%d", &nRollingTime);
		if (nRollingTime <= 0) {
			printf("\t1���� ���� ���� �Է��ϽǼ��� �����ϴ�.\n\t�ʱ� ȭ������ ���ư��ϴ�.\n\t�ƹ�Ű�� �����ּ���.");
			getch();
			system("cls");
			continue;
		}
		nTemp = nRollingTime;		
	WAIT_POINT:
		system("cls");
		printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
		printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
		printf("\n\n\n");
		printf("\t\t\t o               o\n");
		printf("\t\t\t |               |  ��\n");
		printf("\t\t\t|-----------------|��\n");
		printf("\t\t\t|     |     |     |��\n");
		printf("\t\t\t|-----------------|\n");
		printf("\t\t\t|  S  L  O  T  �� |\n");
		printf("\t\t\t|  M A C H I N E  |\n");
		printf("\t\t\t|_________________|\n");
		switch(nCountDown - nSecond){							//�Է��� �ð��� �پ��� �귿�� ���ư��� ��ٸ�
		case 5:
			printf("\n\t\t\tREADY    %d\n", nCountDown - nSecond);
			nSecond++;
			break;
		case 4:
			printf("\n\t\t\tREADY.   %d\n", nCountDown - nSecond);
			nSecond++;
			break;
		case 3:
			printf("\n\t\t\tREADY..  %d\n", nCountDown - nSecond);
			nSecond++;
			break;
		case 2:
			printf("\n\t\t\tREADY... %d\n", nCountDown - nSecond);
			nSecond++;
			break;
		case 1:
			printf("\n\t\t\tREADY....%d\n", nCountDown - nSecond);
			nSecond++;
			break;
		default:
			system("cls");
			printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
			printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
			printf("\n\n\n");
			printf("\t\t\t o               o\n");
			printf("\t\t\t |               |  ��\n");
			printf("\t\t\t|-----------------|��\n");
			printf("\t\t\t|     |     |     |��\n");
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|  S  L  O  T  �� |\n");
			printf("\t\t\t|  M A C H I N E  |\n");
			printf("\t\t\t|_________________|\n");
			Sleep(500);
			system("cls");
			printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
			printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
			printf("\n\n\n");
			printf("\t\t\t o               o\n");
			printf("\t\t\t |               |\n");
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|     |     |     |��\n");
			printf("\t\t\t|-----------------|��\n");
			printf("\t\t\t|  S  L  O  T  �� |��\n");
			printf("\t\t\t|  M A C H I N E  |\n");
			printf("\t\t\t|_________________|\n");
			Sleep(500);
			system("cls");
			printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
			printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
			printf("\n\n\n");
			printf("\t\t\t o               o\n");
			printf("\t\t\t |               |  ��\n");
			printf("\t\t\t|-----------------|��\n");
			printf("\t\t\t|     |     |     |��\n");
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|  S  L  O  T  �� |\n");
			printf("\t\t\t|  M A C H I N E  |\n");
			printf("\t\t\t|_________________|\n");
			Sleep(500);
			system("cls");
			goto SLOT_START;
		}
		Sleep(1000);
		goto WAIT_POINT;
		system("cls");
	SLOT_START:
		switch (nCount) {
		case 0:
			while (nRollingTime > 0) {								//�귿�� ĭ���� ���������� 20���� ���ư�
				nSlot_1 = rand() % 10;
				printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
				printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
				printf("\n\n\n");
				printf("\t\t\t o               o\n");
				printf("\t\t\t |               |  ��\n");
				printf("\t\t\t|-----------------|��\n");
				printf("\t\t\t| %2d  |     |     |��\n", nSlot_1);
				printf("\t\t\t|-----------------|\n");
				printf("\t\t\t|  S  L  O  T  �� |\n");
				printf("\t\t\t|  M A C H I N E  |\n");
				printf("\t\t\t|_________________|\n");
				printf("\n\t\t\tSHOT!\n");
				nRollingTime--;
				Sleep(nRollingDelay);
				if (nRollingTime < 7) nRollingDelay *= 1.3;			//1��ĭ�� 2��ĭ�� 6������ ������������ ������ 0.1 * 1.3^n�ʸ�ŭ ������
				system("cls");
			}
			nRollingTime = nTemp;
			nCount++;
			nRollingDelay = 100;
			goto SLOT_START;
		case 1:
			while (nRollingTime > 0) {
				nSlot_2 = rand() % 10;
				printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
				printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
				printf("\n\n\n");
				printf("\t\t\t o               o\n");
				printf("\t\t\t |               |  ��\n");
				printf("\t\t\t|-----------------|��\n");
				printf("\t\t\t| %2d  | %2d  |     |��\n", nSlot_1, nSlot_2);
				printf("\t\t\t|-----------------|\n");
				printf("\t\t\t|  S  L  O  T  �� |\n");
				printf("\t\t\t|  M A C H I N E  |\n");
				printf("\t\t\t|_________________|\n");
				printf("\n\t\t\tFIRST NUM = %d!\n", nSlot_1);
				nRollingTime--;
				Sleep(nRollingDelay);
				if (nRollingTime < 7) nRollingDelay *= 1.3;
				system("cls");
			}
			nRollingTime = nTemp;
			nCount++;
			nRollingDelay = 100;
			goto SLOT_START;
		case 2:
			while (nRollingTime > 0) {
				nSlot_3 = rand() % 10;
				printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
				printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
				printf("\n\n\n");
				printf("\t\t\t o               o\n");
				printf("\t\t\t |               |  ��\n");
				printf("\t\t\t|-----------------|��\n");
				printf("\t\t\t| %2d  | %2d  | %2d  |��\n", nSlot_1, nSlot_2, nSlot_3);
				printf("\t\t\t|-----------------|\n");
				printf("\t\t\t|  S  L  O  T  �� |\n");
				printf("\t\t\t|  M A C H I N E  |\n");
				printf("\t\t\t|_________________|\n");
				printf("\n\t\t\tSECOND NUM = %d!\n", nSlot_2);
				nRollingTime--;
				Sleep(nRollingDelay);
				if (nRollingTime < 8) nRollingDelay *= 1.6;							//������ĭ�� 7������ ������ �� �� ������ 0.1 * 1.6^n�ʸ�ŭ ������
				system("cls");
			}
			nCount++;
			nRollingDelay = 100;
			goto SLOT_START;
		default:
			printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
			printf("\n\n\n\n");
			printf("\t\t\t o               o\n");
			printf("\t\t\t |               |  ��\n");
			printf("\t\t\t|-----------------|��\n");
			printf("\t\t\t| %2d  | %2d  | %2d  |��\n", nSlot_1, nSlot_2, nSlot_3);
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|  S  L  O  T  �� |\n");
			printf("\t\t\t|  M A C H I N E  |\n");
			printf("\t\t\t|_________________|\n");
			if (nSlot_1 == 7 && nSlot_2 == 7 && nSlot_3 == 7) {							//������ ������ �� ���ñݾ� 11.8��
				printf("\n\t\t\t777 J A C K  P O T 777\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 11.8));
				nMoney += (int)(nBetAmount * 11.8);
			}
			else if (nSlot_1 - 1 == nSlot_2 && nSlot_2 - 1 == nSlot_3) {				//���ڰ� 1�� �پ��� �齺Ʈ����Ʈ�� ���ñݾ� 5.9��
				printf("\n\t\t\t<-- BACK STRAIGHT <--\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 5.9));
				nMoney += (int)(nBetAmount * 5.9);
			}
			else if (nSlot_1 + 1 == nSlot_2 && nSlot_2 + 1 == nSlot_3) {				//���ڰ� 1�� �þ�� ��Ʈ����Ʈ�� ���ñݾ� 4.7��
				printf("\n\t\t\t--> STRAIGHT -->\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 4.7));
				nMoney += (int)(nBetAmount * 4.7);
			}
			else if (nSlot_1 == nSlot_2 && nSlot_2 == nSlot_3) {						//���� 3���� ���� �� �� Ʈ���÷� ���ñݾ� 3.5��
				printf("\n\t\t\t$$$TRIPLE$$$\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 3.5));
				nMoney += (int)(nBetAmount * 3.5);
			}
			else if (nSlot_1 == nSlot_2 || nSlot_2 == nSlot_3 || nSlot_1 == nSlot_3) {	//���� 2���� �����ϸ� ���ñݾ� 1.9��
				printf("\n\t\t\tNOT BAD :)\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 1.9));
				nMoney += (int)(nBetAmount * 1.9);
			}
			else {
				printf("\n\t\t\tTOO BAD ;(\n");											//���� ������ ��ġ�ϴ� ���� ������ ���� �ݾ��� ����(������ �̹� �����ݾװ� ���ñݾ��� �������Ƿ� ���� �������� �ʴ´�.)
				printf("\n\t\t\t- %d\n\n", nBetAmount);
			}
			printf("\n����� Ȯ���ϼ����� �ƹ�Ű�� ��������.");
			getch();
			nCount = 0;
			nCountDown = 5;
			nSecond = 0;
			system("cls");
			continue;
		}
	}
	system("cls");
	printf("\n\n\n\n");																			//���� �ݾ��� ���� ��, ���� ����.
	printf("\t\t\tNOT ENOUGH MONEY..\n");
	printf("\t\t\t���̻� ������ ���� �� �� ���� ���α׷��� �����մϴ�.\n\n\n\n");
	return 0;


END:
	system("cls");																		//�÷��̾��� �ݾ��� ����ä�� ������ ����Ǹ� ���
	printf("\n\n\n\n");
	printf("\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t$$$$$$$ TOTAL MONEY $$$$$$$\n");
	printf("\t\t\t$$$$$$$%10d\\  $$$$$$$\n", nMoney);
	printf("\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n\n");
	return 0;
}