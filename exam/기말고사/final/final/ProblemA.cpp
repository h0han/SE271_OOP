/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////
#include "ProblemA.h"

#include <iostream>

// ======================================== [Problem A] =======================================
// In this problem, you need to IMPLEMENT a function which converts a character vector, which includes a binary number, into an unsigned integer.
// For example, 
// a) If vec = {'1', '0', '0', '1'},
// it should return 9 = (2^3*1 + 2^2*0 + 2^1*0 + 2^0*1)
// b) If vec = {'1', '0', '0', '0', '0'},
// it should return 16 = (2^4*1 + 2^3*0 + 2^2*0 + 2^1*0 + 2^0*0)

// Important Note:
// - Do not use any external library/functions other than the member functions of std::vector
// - Implement everything in a single function
// - The return value is always positive or zero (as it's an unsigned integer.)
// - Assume that the input vec is given to meet the safe range of the unsigned integer, i.e., smaller than 2^32 - 1 (4294967295)
// - Assume that the input vec has always correct elements, i.e., they are only either '0' or '1'.

unsigned int bin2uint(std::vector<char> vec) {
	// Implement here !
	int ans = 0;
	int size = vec.size();
	for (char& a : vec) {
		if (a == '1') {
			int one = 1;
			for (int i = 0; i = size - 1; ++i) {
				one *= 2;
				ans += one;
			}
		}
		else if (a == '0') {
			continue;
		}
		--size;
	}
	return ans;
}

//void problem_A_testcode() {
//	// Edit this function if you want
//	std::cout << bin2uint({'1', '0', '0', '1'}) << std::endl;
//	std::cout << bin2uint({'1', '0', '0', '0', '0'}) << std::endl;
//}