#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main() {
	int nSlot_1, nSlot_2, nSlot_3, nMoney = 100000, nBetAmount, nCount = 0, nRollingTime, nRollingDelay = 100, nCountDown = 5, nTemp, nSecond = 0;

	srand((unsigned)time(NULL));

	//배팅 할 금액과 돌아가는 바퀴수 입력. 배팅 금액을 0입력할 시 프로그램 종료.
	while (nMoney > 0) {
		printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
		printf("\n\n\n\n");
		printf("\t\t\t o               o\n");
		printf("\t\t\t |               |  。\n");
		printf("\t\t\t|-----------------|│\n");
		printf("\t\t\t|     |     |     |┘\n");
		printf("\t\t\t|-----------------|\n");
		printf("\t\t\t|  S  L  O  T  ○ |\n");
		printf("\t\t\t|  M A C H I N E  |\n");
		printf("\t\t\t|_________________|\n\n");
		printf("\t배팅할 금액을 입력해주세요 (0 또는 음수 입력시 종료) : ");
		scanf("%d", &nBetAmount);
		if (nBetAmount > nMoney) {
			printf("\t소유 자금보다 큰 금액을 배팅하셨습니다.\n\t다시 배팅하기 위해서 아무키나 눌러주세요.");
			getch();
			system("cls");
			continue;
		}
		else if (nBetAmount <= 0) goto END;						//0을 입력하면 최종 점수를 출력해주면서 게임 종료.
		nMoney -= nBetAmount;
		printf("\t몇바퀴를 돌리시겠습니까? : ");
		scanf("%d", &nRollingTime);
		if (nRollingTime <= 0) {
			printf("\t1보다 작은 수는 입력하실수는 없습니다.\n\t초기 화면으로 돌아갑니다.\n\t아무키나 눌러주세요.");
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
		printf("\t\t\t |               |  。\n");
		printf("\t\t\t|-----------------|│\n");
		printf("\t\t\t|     |     |     |┘\n");
		printf("\t\t\t|-----------------|\n");
		printf("\t\t\t|  S  L  O  T  ○ |\n");
		printf("\t\t\t|  M A C H I N E  |\n");
		printf("\t\t\t|_________________|\n");
		switch(nCountDown - nSecond){							//입력한 시간이 줄어들며 룰렛이 돌아가길 기다림
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
			printf("\t\t\t |               |  。\n");
			printf("\t\t\t|-----------------|│\n");
			printf("\t\t\t|     |     |     |┘\n");
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|  S  L  O  T  ○ |\n");
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
			printf("\t\t\t|     |     |     |┐\n");
			printf("\t\t\t|-----------------|│\n");
			printf("\t\t\t|  S  L  O  T  ○ |˚\n");
			printf("\t\t\t|  M A C H I N E  |\n");
			printf("\t\t\t|_________________|\n");
			Sleep(500);
			system("cls");
			printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
			printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
			printf("\n\n\n");
			printf("\t\t\t o               o\n");
			printf("\t\t\t |               |  。\n");
			printf("\t\t\t|-----------------|│\n");
			printf("\t\t\t|     |     |     |┘\n");
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|  S  L  O  T  ● |\n");
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
			while (nRollingTime > 0) {								//룰렛은 칸마다 순차적으로 20바퀴 돌아감
				nSlot_1 = rand() % 10;
				printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
				printf("$$$ BET AMOUNT = %5d\\ $$$\n", nBetAmount);
				printf("\n\n\n");
				printf("\t\t\t o               o\n");
				printf("\t\t\t |               |  。\n");
				printf("\t\t\t|-----------------|│\n");
				printf("\t\t\t| %2d  |     |     |┘\n", nSlot_1);
				printf("\t\t\t|-----------------|\n");
				printf("\t\t\t|  S  L  O  T  ● |\n");
				printf("\t\t\t|  M A C H I N E  |\n");
				printf("\t\t\t|_________________|\n");
				printf("\n\t\t\tSHOT!\n");
				nRollingTime--;
				Sleep(nRollingDelay);
				if (nRollingTime < 7) nRollingDelay *= 1.3;			//1번칸과 2번칸은 6바퀴가 남았을때부터 바퀴당 0.1 * 1.3^n초만큼 느려짐
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
				printf("\t\t\t |               |  。\n");
				printf("\t\t\t|-----------------|│\n");
				printf("\t\t\t| %2d  | %2d  |     |┘\n", nSlot_1, nSlot_2);
				printf("\t\t\t|-----------------|\n");
				printf("\t\t\t|  S  L  O  T  ● |\n");
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
				printf("\t\t\t |               |  。\n");
				printf("\t\t\t|-----------------|│\n");
				printf("\t\t\t| %2d  | %2d  | %2d  |┘\n", nSlot_1, nSlot_2, nSlot_3);
				printf("\t\t\t|-----------------|\n");
				printf("\t\t\t|  S  L  O  T  ● |\n");
				printf("\t\t\t|  M A C H I N E  |\n");
				printf("\t\t\t|_________________|\n");
				printf("\n\t\t\tSECOND NUM = %d!\n", nSlot_2);
				nRollingTime--;
				Sleep(nRollingDelay);
				if (nRollingTime < 8) nRollingDelay *= 1.6;							//마지막칸은 7바퀴가 남았을 때 한 바퀴당 0.1 * 1.6^n초만큼 느려짐
				system("cls");
			}
			nCount++;
			nRollingDelay = 100;
			goto SLOT_START;
		default:
			printf("$$$ MY MONEY = %5d\\ $$$\n", nMoney);
			printf("\n\n\n\n");
			printf("\t\t\t o               o\n");
			printf("\t\t\t |               |  。\n");
			printf("\t\t\t|-----------------|│\n");
			printf("\t\t\t| %2d  | %2d  | %2d  |┘\n", nSlot_1, nSlot_2, nSlot_3);
			printf("\t\t\t|-----------------|\n");
			printf("\t\t\t|  S  L  O  T  ○ |\n");
			printf("\t\t\t|  M A C H I N E  |\n");
			printf("\t\t\t|_________________|\n");
			if (nSlot_1 == 7 && nSlot_2 == 7 && nSlot_3 == 7) {							//잭팟이 터졌을 때 배팅금액 11.8배
				printf("\n\t\t\t777 J A C K  P O T 777\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 11.8));
				nMoney += (int)(nBetAmount * 11.8);
			}
			else if (nSlot_1 - 1 == nSlot_2 && nSlot_2 - 1 == nSlot_3) {				//숫자가 1씩 줄어들면 백스트레이트로 배팅금액 5.9배
				printf("\n\t\t\t<-- BACK STRAIGHT <--\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 5.9));
				nMoney += (int)(nBetAmount * 5.9);
			}
			else if (nSlot_1 + 1 == nSlot_2 && nSlot_2 + 1 == nSlot_3) {				//숫자가 1씩 늘어나면 스트레이트로 배팅금액 4.7배
				printf("\n\t\t\t--> STRAIGHT -->\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 4.7));
				nMoney += (int)(nBetAmount * 4.7);
			}
			else if (nSlot_1 == nSlot_2 && nSlot_2 == nSlot_3) {						//숫자 3개가 동일 할 시 트리플로 배팅금액 3.5배
				printf("\n\t\t\t$$$TRIPLE$$$\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 3.5));
				nMoney += (int)(nBetAmount * 3.5);
			}
			else if (nSlot_1 == nSlot_2 || nSlot_2 == nSlot_3 || nSlot_1 == nSlot_3) {	//숫자 2개가 동일하면 배팅금액 1.9배
				printf("\n\t\t\tNOT BAD :)\n");
				printf("\n\t\t\t+ %d\n\n", (int)(nBetAmount * 1.9));
				nMoney += (int)(nBetAmount * 1.9);
			}
			else {
				printf("\n\t\t\tTOO BAD ;(\n");											//위의 족보중 일치하는 것이 없으면 배팅 금액을 잃음(위에서 이미 소유금액과 배팅금액을 나눴으므로 따로 빼주지는 않는다.)
				printf("\n\t\t\t- %d\n\n", nBetAmount);
			}
			printf("\n결과를 확인하셨으면 아무키나 누르세요.");
			getch();
			nCount = 0;
			nCountDown = 5;
			nSecond = 0;
			system("cls");
			continue;
		}
	}
	system("cls");
	printf("\n\n\n\n");																			//남은 금액이 없을 때, 게임 종료.
	printf("\t\t\tNOT ENOUGH MONEY..\n");
	printf("\t\t\t더이상 게임을 진행 할 수 없어 프로그램을 종료합니다.\n\n\n\n");
	return 0;


END:
	system("cls");																		//플레이어의 금액이 남은채로 게임이 종료되면 출력
	printf("\n\n\n\n");
	printf("\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("\t\t\t$$$$$$$ TOTAL MONEY $$$$$$$\n");
	printf("\t\t\t$$$$$$$%10d\\  $$$$$$$\n", nMoney);
	printf("\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n\n");
	return 0;
}