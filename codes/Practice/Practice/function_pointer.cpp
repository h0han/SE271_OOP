#include <iostream>
using namespace std;

int Add(int num1, int num2) {
	return num1 + num2;
}

int Sub(int num1, int num2) {
	return num1 - num2;
}

//int main() {
//	int imenu = 0;
//	int num1, num2;
//	int (*func_ptr) (int, int); // function pointer, ���ڿ� return Ÿ���� �¾ƾ� ��.
//	cout << "Select Menu (1=add, 2=sub)? ";
//	cin >> imenu;
//	cout << "Left operand: ";
//	cin >> num1;
//	cout << "Right operand: ";
//	cin >> num2;
//
//	func_ptr = (imenu == 1) ? Add : Sub;
//	cout << "Result : " << func_ptr(num1, num2);
//
//	return 0;
//}