#include <iostream>
using namespace std;

void printname(char * const name) {
	cout << "name : " << name << endl;
	name[0] = '\0';
	//name = "name";
}

int main() {
	char myname[10] = "John";
	printname(myname);
	cout << "name : " << myname << endl;
	return 0;
}
