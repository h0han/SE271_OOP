#pragma once
/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
// Goal of Problem D: Implement three member functions of Calculator
/////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

// Well done! It's the final problem for all.
// I now provide the solution code for Problem A, B, and C, in here and ProblemD_Provided.cpp.
// Your job is to implement a new Class, Calculator decribed below.

// Skim through the provided code below, and proceed to the Problem D by scrolling down! 
// Note: In the provided source code, the class/function names are slightly different from Problem B and C
// e.g.,
// 1. Op => Operator, Add => Addition, and so on
// 2. create_op => factory_op
// 3. parse => parse_eq

// ========================= [Provided Source Code ] ==========================================
// Warning: DON'T TOUCH THE SOURCE CODE!!!!
// 1. Operators (Solution of Problem B1)
// In the problem D, you should use the provided classes, NOT your implementation in B1.
template<typename T>
class Operator {
public:
	virtual T run(T v1, T v2) = 0;
};
template<typename T>
class Addition : public Operator<T> { T run(T v1, T v2) { return v1 + v2; }; };
template<typename T>
class Subtraction : public Operator<T> { T run(T v1, T v2) { return v1 - v2; }; };
template<typename T>
class Multiplication : public Operator<T> { T run(T v1, T v2) { return v1 * v2; }; }; 
template<typename T>
class Division : public Operator<T> { T run(T v1, T v2) { return v1 / v2; }; };

// 2. Operator Factory (Solution of Problem B2)
template<typename T>
Operator<T>* create_op(std::string op) {
	// Assume that the variable op is one of "+", "-", "*", "/"
	// e.g., create_op<T>("*") returns Mul<T>()
	if (op == "+") {
		return new Addition<T>();
	}
	else if (op == "-") {
		return new Subtraction<T>();
	}
	else if (op == "*") {
		return new Multiplication<T>();
	}
	else if (op == "/") {
		return new Division<T>();
	}
	return nullptr;
}

// 3. Parse equation (Solution of Problem C)
std::vector<std::string> parse_eq(std::string str);

// 4. BinNum Class
// This class implements a binary value with its arithmetic operators.
// You don't need to understand the details of the code implemented below.
// But, we are using them in the testcode function for your testing purpose.
// You can initialize it like bin2uint function, and perform +, -, *, and / on it.
// So, you should run the testcode above with binary values!
class BinNum {
public:
	BinNum() { value = 0;  };
	BinNum(std::vector<char> str);  // This includes the solution of Problem A
	BinNum operator+(const BinNum& rhs) { return BinNum(this->value + rhs.value); } 
	BinNum operator-(const BinNum& rhs) { return BinNum(this->value - rhs.value); }
	BinNum operator*(const BinNum& rhs) { return BinNum(this->value * rhs.value); }
	BinNum operator/(const BinNum& rhs) { return BinNum(this->value / rhs.value); }
	bool operator==(unsigned int rhs) { return value == rhs; }
private:
	unsigned int value;
	BinNum(unsigned int val) { value = val; };
	friend std::ostream& operator<<(std::ostream& o, BinNum c);
};
std::ostream& operator<<(std::ostream& o, BinNum c);

// 5. Something useful to your calculate() implementation. Skip for now. I will explain later
template<typename T> T strToNum(const std::string& str);
template<> BinNum strToNum<BinNum>(const std::string& str);
// ============================= End of Provided Code ========================================







// ############################################################################################
// #################### The GREATEST FINAL PROBLEM OF OOP - SE271 #############################
// ############################################################################################

// ======================================== [Problem D] =======================================

// The Calculator has three main functions, other than the constructor and destructor.
// 1. void insertInput(const std::string&)
// - Using this function, you should be able to store each token of an equation (recall Problem C) 
// - So, this class needs to have an STL container (e.g., list/vector/deque/set/...) to manage the token list. 
//   (IMPORTANT: consider the performance of the STL containers when choosing a proper STL container.
//    Write the reason why you choose the STL container in the body of "insertInput()" function in comments.)
// 2. std::string getEquation();
// - This function returns the complete form of the equation. e.g., {"10", "-", "20", "+", "30"} are inserted in order,
//   it should return "10-20+30"
// 3. T calculate();
// - It should calculate the tokens just in order, and produce the results.
// - You MUST use the provided Operator-derived classes, Addition, Subtraction, Multiplication, Division, and/or factory.
// - Important! We ignore the precedence of operators for simplicity, i.e.,
//  Regard "1 + 2 * 3" as ((1 + 2) * 3) = 9 (!= 7)

// Okay, let's get started!
// My recommendation is, before starting your implementation,
// to take a look at the test code implemented in ProblemD.cpp to see what you are expected!

template<typename T>
class Calculator {
public:
	Calculator() {
		// Implement here if any
	}

	~Calculator() {
		// Implement here if any
	}

	void insertInput(const std::string& input) {
		// This function gets and inserts an input token one by one.
		// Important: Short question. Why you choose such STL container?
		// Your answer (a couple of sentences at max):  deque : first in first out의 형태를 가진 container가 필요하기 때문이다.

		// Implement here 
		deque<std::string> dq;
		dq.push_back(input)
	}

	std::string getEquation() {
		// This function returns the complete form of the equation.
		// e.g., {"10", "-", "20", "+", "30"} are inserted in order, it should return "10-20+30"

		// Implement here
		str = std::string;
		for (auto iter = dq.begin(); iter != dq.end(); ++iter) {
			str += *iter;
		}
		return str;
	}

	T calculate() {
		// - This function calculates the inserted tokens just in order, and produce the results.
		// - You MUST use the provided Operator-derived classes, Addition, Subtraction, Multiplication, Division, and/or factory.
		// - Important! We ignore the precedence of operators for simplicity, i.e., 1 + 2 * 3 = 9 (!= 7)
		// - Assume it always gets the correct sequence of tokens, including without division-by-zero.

		// Hint. You can use the following function to convert a string token to a number (integer/float/BinNum)
		// template<typename T> T strToNum(const std::string & str);
		// e.g., strToNum<T>("20") returns the integer value 20 when T is integer
		// e.g., strToNum<T>("1010") returns the BinNum class with "1010" (== 10) when T is BinNum

		// Implement here

		return T();
	}

private:
	// Put any private variable here like your container that keeps the tokens of the equations
	std::vector<std::string> vec;
};


// Test code for your testing purpose
void problem_D_testcode();
