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
	this->m_pid = new int(id); // m_pid�� id�� �ּҸ� ����Ŵ, ���� Getinfo() ���� *(this->m_pid)�� �����;� id�� ���� ������ �� ����.
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