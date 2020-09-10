#include <iostream>
using namespace std;

int main(){
	char grade{'F'};
	cin >> grade;
	switch (grade) {
		case 'A':
		case 'a':
			cout << "85~100" << endl;
			break;	
		case 'B':
		case 'b':
			cout << "70~84" << endl;
			break;
		case 'C':
		case 'c':
			cout << "50~69" << endl;
			break;
		default:
			cout << "less than 50" << endl;	
	}
	return 0;
}
