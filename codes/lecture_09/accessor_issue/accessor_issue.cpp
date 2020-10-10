#include <iostream>
#include <string>
using namespace std;

class Student {
public:
//private: // compile error (line 17)
	int id;
	string name;
public:
	int GetID() { 
		return id; 
	}
};

int main() {
	Student students[10];
	Student* student1;
	student1 = new Student{ 201911189, "hyhan" };

	cout << students[0].id << endl;
	cout << (*student1).id << endl;

	return 0;
}