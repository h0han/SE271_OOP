//#include <iostream>
//using namespace std;
//
//class Student {
//	int* m_id{ nullptr };
//public:
//	Student(int id) {
//		m_id = new int(id);
//	}
//	~Student() {
//		delete m_id;
//	}
//	int GetStudent() {
//		return *m_id;
//	}
//};
//
//int main() {
//	Student s1(201911189);
//	Student s2{ s1 };
//	cout << s1.GetStudent() << endl;
//	cout << s2.GetStudent() << endl;
//
//	return 0;
//}