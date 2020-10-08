#include <iostream>
#include <typeinfo>
using namespace std;

void func1(int* ary) { // ù ��° ��� : array�� �ּҸ� �ѱ��. ary�� size�� ���� ���� ���� �Ұ� --> func1(int* ary, int size)�� ���·� ���� ����.
	cout << "func1" << endl;
	cout << ary << endl;
	cout << sizeof(ary) << endl; // 4 (input array�� size ���� �ȵ�)
	cout << typeid(ary).name() << endl;
}

void func2(int ary[]) {
	cout << "func2" << endl;
	cout << ary << endl;
	cout << sizeof(ary) << endl; // 4 (input array�� size ���� �ȵ�)
	cout << typeid(ary).name() << endl;
}

void func3(int ary[13]) { // �����Ϸ� ���ο��� void func3(int* ary)�� ���·� �ν�. size�� ������൵ integer pointer�� size�� ��ȯ
	cout << "func3" << endl;
	cout << ary << endl;
	cout << sizeof(ary) << endl; // 4 (input array�� size ���� �ȵ�)
	cout << typeid(ary).name() << endl; // 4 (integer ptr�� size ��ȯ)
}

void func4(int(*ary)[13]) { // ary�� pointer�� ��Ƽ� �ѱ�� ���� best
	cout << "func4" << endl;
	cout << "ary is" << ary << endl;
	cout << "*ary is" << *ary << endl; // ary == *ary
	cout << "**ary is " << **ary << endl;
	cout << "sizeof(ary) is " << sizeof(ary) << endl; // 4(integer ptr)
	cout << "sizeof(*ary) is " << sizeof(*ary) << endl; // 52
	cout << "typeid(ary) is " << typeid(ary).name() << endl;
	cout << "typeid(*ary) is " << typeid(*ary).name() << endl;
}

int main(int argc, char** argv) {
	int hello[13] = { 'H', 'E', 'L', 'L', 'O' };
	int(*whatisit)[13] = &hello;

	cout << "sizeof(int) == " << sizeof(int) << endl;
	cout << "===================" << endl;
	cout << "main" << endl;
	cout << hello << endl; // hello�� �ּ� ���
	cout << sizeof(hello) << endl; // 4*13
	cout << *whatisit << endl; // whatisit�� �ּ� ���
	cout << **whatisit << endl; // whatisit�� �� ���, �� ��� hello�� array type�̱� ������ array[0] ���

	cout << "===================" << endl;
	func1(hello);

	cout << "===================" << endl;
	func2(hello);

	cout << "===================" << endl;
	func3(hello);

	cout << "===================" << endl;
	func4(&hello); // ���� ������ �� array�� �ּҸ� �Է�

	return 0;
}