#include "userInterface.h"

int main() {
	cout << "캐릭터를 생성하시려면 아무키나 눌러주세요." << endl;
	getch();

	CharStats character;
	userInterface(&character);

	return 0;
}
