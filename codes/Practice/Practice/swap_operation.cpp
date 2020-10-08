#include <iostream>
using namespace std;

void intSwap1(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void intSwap2(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void intSwap3(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int* f1() {
	int inums[3] = { 1, 2, 3 };
	return inums;
}

//int main() {
//	int inum1 = 1;
//	int inum2 = 3;
//	
//	cout << inum1 << " " << inum2 << endl;
//	intSwap1(inum1, inum2);
//	cout << inum1 << " " << inum2 << endl;
//	//intSwap2(inum1, inum2);
//	//cout << inum1 << " " << inum2 << endl;
//	intSwap3(inum1, inum2);
//	cout << inum1 << " " << inum2 << endl;
//
//	int* pnums = f1();
//	cout << *pnums << endl;
//
//	return 0;
//}