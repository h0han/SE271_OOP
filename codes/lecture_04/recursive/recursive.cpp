#include <iostream> 
using namespace std;

// function declaration
long calFact(int = 0);

int main() {
	int iVal{0}; long dVal{0};
	cout << "Enter the number? ";
	cin >> iVal;
	
	dVal = calFact(iVal);
	cout << dVal << endl;
	
	return 0;
}

// function definition
long calFact(int num) {
	if (num == 0) return 1;
	else return num * calFact(num-1);
}
