#include <iostream>
using namespace std;

// function declaration
int Multiply(int, int = 1); // ������ �Լ��� ���� �Ķ������ �ڸ��� ������ �� 

int main() {
	cout << Multiply(10) << endl;
	cout << Multiply(10, 20) << endl;
	return 0;
}

// function definition
int Multiply(int num1, int num2) {
	return num1 * num2;
}
