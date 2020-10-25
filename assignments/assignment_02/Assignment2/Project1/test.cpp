#include <iostream>
#include <typeinfo>
using namespace std;

enum class DataType { Integer, Float, Str, NotAvailable };

int main() {
	auto a = 1;
	cout << typeid(a).name() << endl;
	return 0;
}