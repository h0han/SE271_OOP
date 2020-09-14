#include <iostream>
using namespace std;

int main() {
	int menu{1};
	cout << "1. coffee\n2. juice\n3. quit\n";
	
	// syntax - do Statements while (condition);
	do {
		cout << "Select menu? ";
		cin >> menu;
		cout << "Your choice is " << menu << endl;
	} while (menu != 3);
	
	return 0;
}
