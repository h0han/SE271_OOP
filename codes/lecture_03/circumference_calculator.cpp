#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
	const double pi = 3.14;
	int value{2};
	double circum{0};
	for (;;) {
		cout << "Enter the radius : ";
		cin >> value;
		if (value == 0) {
			break;
		}
		circum = value * 2 * pi;
		cout << "circumference with a radius of " << value << " : ";
		cout << circum << "(" << typeid(circum).name() << ")" << endl;
	}
	
	return 0;
}
