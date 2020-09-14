#include <iostream>
using namespace std;

double g_count = 0;

void counter() {
	static int iCount{0};
	iCount++;
	g_count = iCount;
	cout << iCount << endl;
}

int main() {
	int iCount;
	counter();
	counter();
	counter();
	cout << g_count << endl;
	cout << iCount << endl; // error
	
	return 0;
}

