#include <iostream>
using namespace std;

class Student {
private:
	int* m_pid;
	std::string m_name;
public:
	void getid() {
		cout << "id is " << *(this->m_pid) << endl;
		cout << "name is " << this->m_name << endl;
	}
	Student();
	Student(int, string);
	~Student();
};

Student::Student(int id, string name) {
	m_pid = new int{ id };
	m_name = name;
}
Student::~Student() {
	if (!m_pid) {
		delete m_pid;
		m_pid = nullptr;
	}
}

int main() {
	Student s1(201911189, "hyhan");
	s1.getid();

	return 0;
}