#include <iostream>
using std::cout;
using std::endl;

int sum(int n1, int n2) {
	return n1 + n2;
}

double sum(int n1, double n2) {
	return n1 + n2;
}

double sum(double n1, double n2) {
	return n1 + n2;
}

int sum(int n1, int n2, int n3) {
	return n1 + n2 + n3;
}

char* sum(char c1, char c2) {
	char* ret = new char[3]{ c1, c2, '\0' };
	return ret;
}

int main() {
	cout << "sum(1, 1) " << sum(1, 1) << endl;
	cout << "sum(1, 1.5) " << sum(1, 1.5) << endl;
	cout << "sum(1.5, 1.5) " << sum(1.5, 1.5) << endl;
	cout << "sum(1, 2, 3) " << sum(1, 2, 3) << endl;
	cout << "sum('a', 'b') " << sum('a', 'b') << endl;

	return 0;
}