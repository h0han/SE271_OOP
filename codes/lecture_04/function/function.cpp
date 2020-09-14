#include <iostream>
using namespace std;

string order(int menu) {
	if (menu == 3) return static_cast<string>("Good bye");
	else return static_cast<string>("Successfully ordered");
}

int main() {
	int iMenu{1};
	cout << "1.Coffee\n2.Juice\n3.Quit\n";
	do {
		cout << "Select Menu?";
		cin >> iMenu;
		cout << order(iMenu) << endl;
	} while (iMenu != 3);
	
	return 0;
}
