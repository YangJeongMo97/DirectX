#include "__template.h"
#include <iostream>

using namespace std;

int main() {
	//�� ���ڰ� ���� ���� �ڷ��� ��ȯ �Լ�
	cout << isBig(20, 30) << endl;
	cout << isBig(3.141592, 38.4151) << endl;
	cout << isBig(-2154183, 21473647) << endl;
	cout << isBig('A', 'c') << endl;

	puts("");

	//�� ���ڰ� ���� �ٸ� �ڷ��� ��� �Լ�
	isBig(50, 33.3);
	isBig('A', 99.934);
	isBig(50, 'c');
	isBig(27123485, 1818.552);
	isBig(100, 'A');


	return 0;
}