#include <iostream>
using namespace std;

int main() {
	int arr[5] = {1, 2, 3, 4, 5};

	// arr�� �ִ� element ����(c++11 syntax)
	for (int element : arr) { 
		cout << element << " ";
	}
	return 0;
}

