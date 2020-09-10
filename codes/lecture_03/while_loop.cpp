#include <iostream>
using namespace std;

int main() {
	int menu{1};
	cout << "1. coffee\n2. juice\n3. quit\n";
	cout << "Select menu? ";
	cin >> menu;
	cout << "Your choice is " << menu << endl;
	
	// syntax - while (condition) {statement}
	while (menu != 3) {
		cout << "Select menu? ";
		cin >> menu;
		cout << "Your choice is " << menu << endl;
	}
	return 0;
}
