//#include <iostream>
//using namespace std;
//
//class Student {
//private:
//	int* m_pid;
//	std::string m_name;
//public:
//	void Getinfo();
//	//void SetVariables(int, string);
//	Student();
//	~Student();
//};
//
//void Student::Getinfo() {
//	if ((this->m_pid) != 0) {
//		cout << "id is " << *(this->m_pid) << endl;
//		cout << "name is " << this->m_name << endl;
//	}
//}
//
////Student::Student() {
////	this->m_pid = nullptr; // = new int{0};
////	m_name = "";
////}
//int a = 201911189;
//Student::Student() : m_pid{&a}, m_name{ "" } {
//}
//
//Student::~Student() {
//	if (!m_pid) {
//		delete m_pid;
//		m_pid = nullptr;
//	}
//}
//
////int main() {
////	Student s1;
////	//s1.SetVariables(201911189, "hyhan");
////	//int a = 2020;
////	//Student s2(&a, "hyhan");
////	//s2.SetVariables(202011189, "hshan");
////	Student s3;
////
////	s1.Getinfo();
////	//s2.Getinfo();
////	s3.Getinfo();
////
////	return 0;
////}