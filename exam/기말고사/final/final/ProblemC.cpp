
/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////

#include "ProblemC.h"

#include <iostream>
#include <algorithm>

// ======================================== [Problem C] =======================================
// In this problem, you need to IMPLEMENT the parse() function,
// which takes an input string of an simple math equation and returns each `token' one by one.
// - For example, "10-20+30*100-40" is given, the function returns a vector of strings,
// containing {"10", "-", "20", "+", "30", "*", "100", "-", "40"}.
// - Assume that there are only four operators, '+', '-', '*', '/', and int/float numbers in the equation.

// Important!: You have to use "std::find_if".
// - I know, we don't cover it during the class, so most of you don't know. Don't panic!
// - It's very similar to std::find; but you can specify a comparator as its last parameter.
// For example, you can now digest the code below based on your understading of how the STL algorithm & iterator work.
/*
#include <algorithm>  // std::find_if
#include <iostream>   // std::cout
#include <vector>     // std::vector

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {
  std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it =
    std::find_if(myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd number is " << *it << '\n'; // Print 25

  return 0;
}
*/

// Something useful:
// Hint 1. std::string also has its iterator, std::string::iterator,
//         since it is a special container for characters. So, you can use std::find_if.
// Hint 2. Using two string iterators, you can make a substring, e.g.,
//         std::string str = std::string("ABCD");
//         std::cout << std::string(str.begin()+1, str.end()) << std::endl; // ==> "BCD"
//         std::cout << std::string(str.begin()+1, str.end()-1) << std::endl; // ==> "BC"
// Hint 3. You can use the following function for a parameter of find_if.

/*

static bool isOp(const char& c) {
    // You don't need to edit it.
    char ops[] = { '+', '-', '*', '/' };
    for (auto o : ops) {
        if (o == c)
            return true;
    }
    return false;
}


std::vector<std::string> parse(std::string str) {
    // Implement here using std::find_if
    std::vector<std::string> ret;
    std::vector<std::string> ch;
    for (auto iter = str.begin(); iter != str.end(); ++iter) {
        auto it = std::find_if(str.begin(), str.end(), isOp);
        ch.push_back(it);
        ret.push_back(ch);
    }

    
    return ret;
}

void problem_C_testcode() {
	// Edit this function for testing if you want
    for (auto s : parse("10-20+30*100-40")) {
        std::cout << s << std::endl;
    }
}


*/