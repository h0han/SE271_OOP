//#include <iostream>
//#include <string>
//
//struct Student {
//	int id;
//	char name[20];
//};
//
//struct StudentCpp {
//	int id;
//	std::string name;
//};
//
//void struct_example() {
//	struct Student student1;
//	student1.id = 201911189;
//	strcpy_s(student1.name, 20, "hy");
//
//	printf("id: %d, name: %s\n", student1.id, student1.name);
//}
//
//void struct_cpp_example() {
//	using std::cout;
//	using std::endl;
//
//	StudentCpp students[10];
//	StudentCpp* student1 = new StudentCpp{ 201911189, "hy" };
//
//	cout << students[0].id << endl; // ÃÊ±âÈ­ X
//	cout << (*student1).id << endl;
//	cout << student1->id << endl;
//
//	delete student1;
//}
//
////int main() {
////	struct_cpp_example();
////
////	return 0;
////}