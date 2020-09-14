#include <iostream>
using namespace std;

// function declaration
int Multiply(int, int = 1); // 정의한 함수와 같은 파라미터의 자리를 가져야 함 

int main() {
	cout << Multiply(10) << endl;
	cout << Multiply(10, 20) << endl;
	return 0;
}

// function definition
int Multiply(int num1, int num2) {
	return num1 * num2;
}
