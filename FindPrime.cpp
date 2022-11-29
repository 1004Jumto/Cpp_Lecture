#include<iostream>
using namespace std;

class Utility : public P
{
public:
	Utility();
	~Utility();
	static bool isDiv(int a, int b);
	static bool isPrime(int a);

private:
};

Utility::Utility()
{
}

Utility::~Utility()
{
}

bool Utility::isDiv(int a, int b)
{
	return (a % b == 0);
}

bool Utility::isPrime(int a)
{
	int i;
	for (i = 2; i < a; i++) {
		if (isDiv(a, i))
			break;
	}

	if (i == a) {
		return true;
	}
	else
		return false;
}

class P8 : public Utility
{
public:
	P8(int n);
	~P8();
	int solution();

private:
	int n;
};

P8::P8(int n)
{
	this->n = n;
}

P8::~P8()
{
}

int P8::solution()
{
	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (Utility::isPrime(i)) {		// Utility를 상속받으면 isPrime을 그냥 쓸 수 있다
			count++;
		}
	}

	return count;
}

class P10 : public P8
{
public:
	P10(int n);
	~P10();
	int solution();	
private:
	int n;
};

P10::P10(int n) : P8(n)
{
}

P10::~P10()
{
}
int P10::solution()
{
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (isDiv(n, i)) {
			sum += i;
		}
	}
	return sum;
}
class P {
protected:
	int n;
public:
	P(int n);
	virtual int solution() = 0;
};

P::P(int n) {
	this->n = n;
}

class P9 : public P {
protected:
	int m;
public:
	P9(int n, int m);
	virtual int solution();
};

P9::P9(int n, int m) : P(n)
{
	this->m = m;
}

int P9::solution() {
	int gcd = 1;
	for (int i = 2; i <= n; i++) {
		if (isDiv(n, i) && isDiv(m, i)) {
			gcd = i;
		}
	}
	return gcd;
}

class P92 :public P9 {
public:
	P92(int n, int m);
	virtual int solution();
};

P92::P92(int n, int m) : P9(n,m)
{
}

int P92::solution() {
	int gcd = P9::solution();	//오버라이드 하는 중에 부모의 이름 똑같은 함수를 호출하고 싶으면 부모이름::함수이름 써서 호출
}	return (m*n)/gcd;

int main(void) {

	cout << "12,4 : " << Utility::isDiv(12, 4) << endl;
	cout << "13 : " << Utility::isPrime(13) << endl;
	
	P8 p8(10);
	cout << "p8,10 : " << p8.solution() << endl;
	cout << "p8,13 : " << p8.solution() << endl;
	
	P10 p101(12);
	P10 p102(5);
	cout << "p10,12 : " << p101.solution() << endl;
	cout << "p10,5 : " << p102.solution() << endl;
	
	P* first;
	P* second;
	first = new P9(12, 8);
	second = new P9(13, 7);
	cout << "p9,12,8 : " << first->solution() << endl;
	delete first;
}

/*
부모클래스를 짤 때 어떤 프로퍼티를 가질지 시간은 걸리지만, 유사한 기능을 확장해 나갈때 훨씬 효과적이다
virtual을 사용해서 이전버전은 이전버전대로 살아있고, 새로운 버전을 새롭게 또 만들수 있다. 
체계적인 관리가 가능하다
부모꺼를 상속받아 사용하자
한군데만 업데이트하면 모든 클래스가 자동으로 업데이트 되는 것과 같다

최초의 설계는 느릴지 몰라도 기능의 확장성에는 매우 높아진다
*/