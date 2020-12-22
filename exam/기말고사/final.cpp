/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>

#include "FinalPlatform.h"

#include "ProblemA.h"
#include "ProblemB2.h"
#include "ProblemC.h"
#include "ProblemD.h"

int main() {
	// DO NOT TOUCH THESE PLATFORM LINES //////////////////////////
	if (!FinalPlatform::instance().check()) {
		return 0;
	}
	///////////////////////////////////////////////////////////////

	// Uncomment each below to test the problem you're implementing 
	//problem_A_testcode();

	//problem_B2_i();
	//problem_B2_ii();
	//problem_B2_iii();

	//problem_C_testcode();

	//problem_D_testcode();

	return 0;
}
