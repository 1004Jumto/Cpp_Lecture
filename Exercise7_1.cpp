#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Complex
{
public:
	Complex(int a, int b);
    friend ostream& operator<<(ostream& os, Complex& com);
    friend Complex operator+(const Complex& a, const Complex& b);

private:
    int n1, n2;
};

Complex::Complex(int a, int b) :n1(a), n2(b) { ; }

ostream& operator<<(ostream& os, Complex& com)
{
    if (com.n1 != 0) {
        os << com.n1;
    }
    if (com.n2 < 0) {
        os << " - " << -com.n2 << "i";
    }
    if (com.n2 > 0) {
        os << " + " << com.n2 << "i";
    }

    return os;
}

Complex operator+(const Complex& a, const Complex& b)
{
    int x = a.n1 + b.n1;
    int y = a.n2 + b.n2;
    Complex com2(x, y);

    return com2;
}

int main(void) {
    Complex com(4, -3);
    Complex com1(5, -3);
    Complex res = com + com1;
    cout << res;

    return 0;
}


