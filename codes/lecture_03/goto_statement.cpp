#include <iostream>
using namespace std;

// syntax - goto LABEL; LABEL:
int main() {
	int i{0}, sum{0};
	Sum:
		sum += i;
		i++;
	if (i < 11) {
		goto Sum;
	}
	
	else {
		cout << sum << endl;
	}
	
	return 0;
}
