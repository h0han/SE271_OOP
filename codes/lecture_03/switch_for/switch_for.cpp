#include <iostream>
using namespace std;

int main() {
	char grade{'F'};
	cout << "Enter your letter grade : ";
	cin >> grade;
	if (grade == 'A' || grade == 'a') {
		cout << "85~100" << endl;
	}
	
	else if (grade == 'B' || grade == 'b') {
		cout << "70~84" << endl;
	}
	
	else if (grade == 'C' || grade == 'c') {
		cout << "50~69" << endl;
	}
	
	else {
		cout << "less than 50" << endl;
	}
	
	return 0;
}
