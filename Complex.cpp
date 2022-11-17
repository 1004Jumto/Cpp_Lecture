#include<iostream>
#include<string>

using namespace std;

class Complex
{
public:
	Complex(int a, int b);
	~Complex();
	string get() const;
	friend Complex operator+(const Complex& x, const Complex& y);
	friend ostream& operator<<(ostream& os, const Complex& num);
private:
	int real;
	int img;
};

Complex::Complex(int a, int b) : real(a), img(b)
{
}

Complex::~Complex()
{
}

string Complex::get() const
{
	string s;

	if (img > 0) {
		s = to_string(real) + "+" + to_string(img) + "i";
	}
	else if (img < 0) {
		s = to_string(real) + to_string(img) + "i";
	}
	else {
		s = to_string(real);
	}

	return s;
}

Complex operator+(const Complex& x, const Complex& y)
{
	Complex answer(x.real + y.real, x.img + y.img);
	return answer;
}

ostream& operator<<(ostream& os, const Complex& num)
{
	if (num.real != 0) {
		os << num.real;
	}

	if (num.img < 0) {
		os << " - " << -num.img << "i";
	}
	else if (num.img > 0) {
		os << " + " << num.img << "i";
	}

	return os;
}

int main(void) {
	Complex com(4, -3);
	Complex com1(5, -3);
	
	cout << (com + com1);

	return 0;
}