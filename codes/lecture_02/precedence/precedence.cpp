#include <iostream>

void precedence() {
	int a, b, c;
	a = 1;
	b = 2;
	c = 3;
	
	// a < b => true == 1
	// a < c => true == 1
	// a, b, c의 자료형이 int 
	std::cout << (a < b < c) << std::endl;
}

int main() {
	precedence();
}

