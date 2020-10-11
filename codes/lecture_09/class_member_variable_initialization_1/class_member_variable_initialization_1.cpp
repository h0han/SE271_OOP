#include <iostream>
using namespace std;

class Student {
private:
	int* m_pid;
	std::string m_name;
public:
	void Getinfo();
	void SetVariables(int, string);
};

void Student::Getinfo() {
	cout << "id is " << *(this->m_pid) << endl;
	cout << "name is " << this->m_name << endl;
}

void Student::SetVariables(int id, string name) {
	this->m_pid = new int(id); // m_pid는 id의 주소를 가리킴, 따라서 Getinfo() 에서 *(this->m_pid)로 가져와야 id의 값을 참조할 수 있음.
	m_name = name;
}

int main() {
	Student s1;
	s1.SetVariables(201911189, "hyhan");
	Student s2;
	s2.SetVariables(202011189, "hshan");

	s1.Getinfo();
	s2.Getinfo();
	return 0;
}