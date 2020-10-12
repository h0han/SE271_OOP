#include <iostream>
using namespace std;

class Complex {
	int* m_r = nullptr; // real part
	int* m_i = nullptr; // imaginary part
public:
	// Constructors
	Complex();
	Complex(int, int);
	Complex(int);
	~Complex();
	Complex(const Complex& rhs);

	void print() const;

public:
	Complex operator+(const Complex& c2);
	Complex operator+(int r);
	Complex operator+(double r);
};

Complex Complex::operator+(const Complex& c2) {
	Complex result;
	*(result.m_r) = *(m_r)+*(c2.m_r);
	*(result.m_i) = *(m_i)+*(c2.m_i);
	return result;
}

Complex Complex::operator+(int r) {
	Complex result;
	*(result.m_r) = *(m_r)+r;
	*(result.m_i) = *(m_i);
	return result;
}

Complex Complex::operator+(double r) {
	return Complex((static_cast<int> (r)) + *(m_r), *(m_i));
}

int main() {
	if (1) {
		Complex a(1, 2);
		Complex b(3, 4);
		
		Complex c = a + b;
		Complex d = a + b + b;

		a.print();
		b.print();
		c.print();
		d.print();
	}
}