/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////

#include "ProblemB2.h"
#include <iostream>

// ======================================== [Problem B-2] =======================================
void problem_B2() {
	// The following source code is your starting point. You don't need to do anything with this function.
	// Just uncomment the line below to see if it works correctly with your implementation of Problem B2.
	// Then, proceed and solve Problem_B2_i, Problem_B2_ii, Problem_B2_iii, in order (i.e., one by one)
	// Note: You have to build up the source code in order, i.e.,
	// Problem_B2 -> copy/edit -> Problem_B2_i -> copy/edit -> Problem_B2_ii -> copy/edit -> Problem_B2_iii

	/*Op<int>* op = new Add<int>();*/
	//std::cout << op->run(10, 20) << std::endl;
	//std::cout << op->run(20, 30) << std::endl;

	//op = new Sub<int>();
	//std::cout << op->run(30, 10) << std::endl;

	//op = new Div<int>();
	//std::cout << op->run(10, 10) << std::endl;
	//std::cout << op->run(10, 0) << std::endl; // Use this code to issue division-by-zero!


}

void problem_B2_i() {
	// #############################################################################################################################################
	// PROBLEM: The source code of the previous function would have a memory leak.
	//
	// What you need to do is:
	// - Copy/paste the function body of it into here and edit them using a smartpointer, either unique_ptr or shared_ptr, to eliminate all memory leaks
	// - Do not use `delete' explicitly.
	// #############################################################################################################################################

	// Implement Here
	//std::unique_ptr<int>*op = new Add<int>();

	//std::cout << op->run(10, 20) << std::endl;
	//std::cout << op->run(20, 30) << std::endl;

	//std::unique_ptr<int> op(new Sub<int>());
	//std::cout << op->run(30, 10) << std::endl;

	//std::unique_ptr<int> op(new Div<int>());
	//std::cout << op->run(10, 10) << std::endl;
}


void problem_B2_ii() {
	// #############################################################################################################################################
	// PROBLEM: Modify the source code of the previous function to use the factory design pattern.
	//
	// What you need to do is:
	// 1. Complete the factory function, "create_op(std::string opstr)", in ProblemB2.h
	// 2. Copy/paste the function body above into here and modify it so that it uses the factory function
	// #############################################################################################################################################

	// Implement Here
}

void problem_B2_iii() {
	// #############################################################################################################################################
	// PROBLEM: The source code of the previous function would have a runtime error due to division-by-zero.
	//
	// Do following things to handle the issue
	// 1. Implement an execption class, "DivByZeroException" in ProblemB2.h
	//    - You must derive std::execption class
	//    - The "what()" member function should be implemented and return DIV_BY_ZERO defined in ProblemB2.h
	// 2. Implement a new class, SafeDiv, in ProblemB2.h by deriving the Operator class of ProblemB1.hpp 
	//    - This class should raise the DivByZeroExecption when v2 == 0
	// 3. Copy/paste the function body of the previous function into here, and edit it to run it with the following outputs by handling the exception:
	// ----------------------------- (You don't need to print "-------")
	// 30
	// 50
	// 20
	// Div by Zero Error
	// ----------------------------- (You don't need to print "-------")
	// #############################################################################################################################################

	// Implement Here
}
