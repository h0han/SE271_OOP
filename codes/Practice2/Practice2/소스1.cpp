#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Complex {
	int* mr = nullptr;
	int* mi = nullptr;
public:
	Complex();
	Complex(int, int);
	Complex(int);
	~Complex();
	Complex(const Complex& rhs);
};
Complex::Complex(int r, int i) {
	mr = new int(r);
	mi = new int(i)
}
int main() {
	Complex::Complex(int r, int i) {
		mr = new int(r);
		mi = new int(i);
}

int Add(int num1, int num2) {
	return num1 + num2;
}
int Sub(int num1, int num2) {
	return num1 - num2;
}