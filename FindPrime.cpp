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
		if (Utility::isPrime(i)) {		// Utility�� ��ӹ����� isPrime�� �׳� �� �� �ִ�
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
	int gcd = P9::solution();	//�������̵� �ϴ� �߿� �θ��� �̸� �Ȱ��� �Լ��� ȣ���ϰ� ������ �θ��̸�::�Լ��̸� �Ἥ ȣ��
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
�θ�Ŭ������ © �� � ������Ƽ�� ������ �ð��� �ɸ�����, ������ ����� Ȯ���� ������ �ξ� ȿ�����̴�
virtual�� ����ؼ� ���������� ����������� ����ְ�, ���ο� ������ ���Ӱ� �� ����� �ִ�. 
ü������ ������ �����ϴ�
�θ𲨸� ��ӹ޾� �������
�ѱ����� ������Ʈ�ϸ� ��� Ŭ������ �ڵ����� ������Ʈ �Ǵ� �Ͱ� ����

������ ����� ������ ���� ����� Ȯ�强���� �ſ� ��������
*/