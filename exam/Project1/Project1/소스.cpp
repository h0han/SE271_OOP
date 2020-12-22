#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() {
		cout << "Base" << endl;
	}
};

class D : public Base {
public:
	virtual void f() {
		cout << "D" << endl;
	}
};

int main() {
	Base b;
	b.f();
	D d;
	d.f();

	return 0;
}

virtual int getint(int a) = 0;
virtual int getint(int a) {
	body;
	return coin;
}

template<typename T>
void swap(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 10, b = 5;
	swap<int>(a, b);

}

template<typename T1, typename T2>
class Stu {
	T1 id;
	T2 name;
public:
	Stu(T1 id, T2 name) : id(id), name(name) {}
	void print() {
		cout << "id" << id << "name" << name;
	}
};

int main() {
	Stu<int, const char*> st1{ 201911189, "a" };

}

for (int& a : v1) {
	cout << a << endl;
}