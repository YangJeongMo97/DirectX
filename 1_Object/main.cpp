#include "CObject.h"
#include <Windows.h>
#include <conio.h>

#pragma warning ( disable : 4996 )

#define MAX 20

int main() {
	cout << "������Ʈ ����" << endl;

	CObject Object("Hero", 100);
	CObject* ObjectList[20];
	CObject defaultObj;
	
	for (int i = 0; i < MAX; i++) {
		ObjectList[i] = new CObject(Object);
	}

	CObject Object12;
	Object12 = Object;

	getch();
	system("cls");

	cout << "������Ʈ ���" << endl;

	Object.displayObject();

	for (int i = 0; i < MAX; i++) {
		ObjectList[i]->displayObject();
	}

	Object12.displayObject();

	getch();
	system("cls");

	cout << "������Ʈ �Ҹ�" << endl;

	for (int i = 0; i < MAX; i++) {
		delete ObjectList[i];
		ObjectList[i] = NULL;
	}

	return 0;
}