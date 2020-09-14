#include <iostream>
using namespace std;

double calArea(int radius) {
	double dVal;
	dVal = radius * radius * 3.14;
	return dVal;
}

int main() {
	int iVal{0}; double dVal{0};
	cout << "Enter the radius?";
	cin >> iVal;
	dVal = iVal * 2 * 3.14;
	cout << dVal << endl;
	dVal = calArea(iVal);
	cout << dVal << endl;
	
	return 0;
}
