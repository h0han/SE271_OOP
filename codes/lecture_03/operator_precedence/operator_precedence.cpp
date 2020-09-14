#include <iostream>
using namespace std;

int main() {
	int x = 1, y = 2;
	cout << (++x > 2 && ++y > 2) << endl;
	cout << "x = " << x << ", y = " << y << endl;
	
	cout << (++x > 2 || ++y > 2) << endl;
	cout << "x = " << x << ", y = " << y << endl;
	
	return 0;
}

