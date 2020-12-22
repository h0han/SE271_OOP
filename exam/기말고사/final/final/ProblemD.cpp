/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////

#include "ProblemD.h"

// ======================================== [Problem D] =======================================
// Well done! It's the final problem for all.
// I now provide the solution code for Problem A, B, and C, in ProblemD.h and ProblemD_Provided.cpp.
// Your job is to implement a new Class Calculator in "ProblemD.h" (NOT HERE).

// You can play with this problem D test code.
void problem_D_testcode() {
	Calculator<int> calc;
	calc.insertInput("10"); 
	calc.insertInput("+");
	calc.insertInput("20");
	calc.insertInput("*");
	calc.insertInput("30");
	std::cout << calc.getEquation() << " = "; // Should print "10+20*30 = "
	std::cout << calc.calculate() << std::endl; // Should print "900"

	Calculator<BinNum> bincalc;
	for (auto s : parse_eq("1110+0001*0010*0010")) {
		bincalc.insertInput(s);
    }
	std::cout << bincalc.getEquation() << " = "; // Should print "1110+0001*0010*0010 = "
	std::cout << bincalc.calculate() << std::endl; // Should print "111100"
	// A note: You don't need to worry about how it is converted to the string vice verca in the std::cout. 
	// It's already nicely implemented in the provided code :)
}


///////////////////////////////////////////////////////////////////////////////////
// Provided Source code. Don't touch them
#include <sstream>
template<typename T>
T strToNum(const std::string& str) {
	T ret;
	std::stringstream ss(str);
	ss >> ret;
	return ret;
}
template<>
BinNum strToNum<BinNum>(const std::string& str) {
	return BinNum(std::vector<char>(str.begin(), str.end()));
}

