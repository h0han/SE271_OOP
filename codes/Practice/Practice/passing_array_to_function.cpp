#include <iostream>
#include <typeinfo>
using namespace std;

void func1(int* ary) { // 첫 번째 방법 : array의 주소를 넘긴다. ary의 size에 대한 정보 전달 불가 --> func1(int* ary, int size)의 형태로 인자 전달.
	cout << "func1" << endl;
	cout << ary << endl;
	cout << sizeof(ary) << endl; // 4 (input array의 size 전달 안됨)
	cout << typeid(ary).name() << endl;
}

void func2(int ary[]) {
	cout << "func2" << endl;
	cout << ary << endl;
	cout << sizeof(ary) << endl; // 4 (input array의 size 전달 안됨)
	cout << typeid(ary).name() << endl;
}

void func3(int ary[13]) { // 컴파일러 내부에서 void func3(int* ary)의 형태로 인식. size를 명시해줘도 integer pointer의 size를 반환
	cout << "func3" << endl;
	cout << ary << endl;
	cout << sizeof(ary) << endl; // 4 (input array의 size 전달 안됨)
	cout << typeid(ary).name() << endl; // 4 (integer ptr의 size 반환)
}

void func4(int(*ary)[13]) { // ary의 pointer로 잡아서 넘기는 것이 best
	cout << "func4" << endl;
	cout << "ary is" << ary << endl;
	cout << "*ary is" << *ary << endl; // ary == *ary
	cout << "**ary is " << **ary << endl;
	cout << "sizeof(ary) is " << sizeof(ary) << endl; // 4(integer ptr)
	cout << "sizeof(*ary) is " << sizeof(*ary) << endl; // 52
	cout << "typeid(ary) is " << typeid(ary).name() << endl;
	cout << "typeid(*ary) is " << typeid(*ary).name() << endl;
}

int main(int argc, char** argv) {
	int hello[13] = { 'H', 'E', 'L', 'L', 'O' };
	int(*whatisit)[13] = &hello;

	cout << "sizeof(int) == " << sizeof(int) << endl;
	cout << "===================" << endl;
	cout << "main" << endl;
	cout << hello << endl; // hello의 주소 출력
	cout << sizeof(hello) << endl; // 4*13
	cout << *whatisit << endl; // whatisit의 주소 출력
	cout << **whatisit << endl; // whatisit의 값 출력, 이 경우 hello가 array type이기 때문에 array[0] 출력

	cout << "===================" << endl;
	func1(hello);

	cout << "===================" << endl;
	func2(hello);

	cout << "===================" << endl;
	func3(hello);

	cout << "===================" << endl;
	func4(&hello); // 인자 전달할 때 array의 주소를 입력

	return 0;
}