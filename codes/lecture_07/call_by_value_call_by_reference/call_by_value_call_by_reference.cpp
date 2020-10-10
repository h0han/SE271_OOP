#include <iostream>
using std::cout;
using std::endl;

void swap1(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void swap2(int* num1, int* num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

void swap3(int& num1, int& num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

int main() {
	int num1 = 1;
	int num2 = 3;
	int num3 = 1;
	int num4 = 3;
	cout << num1 << " " << num2 << endl;
	swap1(num1, num2);
	cout << "swap1 " << num1 << num2 << endl;
	cout << num1 << " " << num2 << endl;
	swap2(&num1, &num2);
	cout << "swap2 " << num1 << num2 << endl;
	cout << num3 << " " << num4 << endl;
	swap3(num3, num4);
	cout << "swap3 " << num3 << num4 << endl;

	return 0;
}