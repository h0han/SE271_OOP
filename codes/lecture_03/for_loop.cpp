#include <iostream>
using namespace std;

int main() {
	int sum{0};
	for (int i = 0; i < 4; i++) {
		sum += i;
	}
	cout << sum << endl;
	return 0;
}
