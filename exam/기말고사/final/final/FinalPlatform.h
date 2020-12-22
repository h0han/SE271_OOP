#pragma once
/////////////////////////////////////////////////////////////
// Object Oriented Programming - SE271 | Fall 2020 | Final //
/////////////////////////////////////////////////////////////

// DON'T READ THIS FILE. It's a waste of time for your exam :)

// Note: You don't need to read this file during the exam
// This file creates the problems and checks potential cheating issues.

#include <iostream>

class FinalPlatform {
private:
	FinalPlatform();
	std::string studentID;

public:
	bool check();
	static FinalPlatform& instance() {
        static FinalPlatform* instance = new FinalPlatform();
        return *instance;
    }
};

